import json
import requests
from requests.exceptions import HTTPError 
from typing import Any, Dict, List

def auth_gapi(json_keyfile: str, scope: List[str]):
    credentials = ServiceAccountCredentials.from_json_keyfile_name(json_keyfile, scope)
    gc = gspread.authorize(credentials)
    return gc

def constructPins(gpsData: Dict[str, Any]) -> str:
    xml = "<Placemark><name>" + str(gpsData['id']) + "</name>"
    xml = xml + "<gx:TimeStamp><when>" + gpsData['Date'] + "T" + gpsData['Time'] + "Z" + "</when></gx:TimeStamp>"
    xml = xml + "<styleUrl>#m_ylw-pushpin</styleUrl>"
    xml = xml + "<Point><coordinates>" + str(gpsData['Longitude']) + "," + str(gpsData['Latitude']) + ",0</coordinates></Point>"
    xml = xml + "</Placemark>"
    return xml

def constructPath(gpsData: List[Dict[str, Any]]) -> str:
    xml = "<Placemark><name>Path</name><styleUrl>#m_ylw-pushpin</styleUrl><LineString><tessellate>1</tessellate>"
    path = "".join(str(point['Longitude']) + "," + str(point['Latitude']) + ",0" for point in gpsData)
    xml = xml + "<coordinates>" + path + "</coordinates></LineString></Placemark>"    
    return xml

def constructXml(inner_xml: str) -> str:
    outer_xml = """<?xml version="1.0" encoding="UTF-8"?>
<kml xmlns="http://www.opengis.net/kml/2.2" xmlns:gx="http://www.google.com/kml/ext/2.2" xmlns:kml="http://www.opengis.net/kml/2.2" xmlns:atom="http://www.w3.org/2005/Atom">
<Document>
    <name>GPSData</name>
    <Style id="s_ylw-pushpin">
        <IconStyle>
            <scale>1.1</scale>
            <Icon>
                <href>http://maps.google.com/mapfiles/kml/pushpin/ylw-pushpin.png</href>
            </Icon>
            <hotSpot x="20" y="2" xunits="pixels" yunits="pixels"/>
        </IconStyle>
    </Style>
    <StyleMap id="m_ylw-pushpin">
        <Pair>
            <key>normal</key>
            <styleUrl>#s_ylw-pushpin</styleUrl>
        </Pair>
        <Pair>
            <key>highlight</key>
            <styleUrl>#s_ylw-pushpin_hl</styleUrl>
        </Pair>
    </StyleMap>
    <Style id="s_ylw-pushpin_hl">
        <IconStyle>
            <scale>1.3</scale>
            <Icon>
                <href>http://maps.google.com/mapfiles/kml/pushpin/ylw-pushpin.png</href>
            </Icon>
            <hotSpot x="20" y="2" xunits="pixels" yunits="pixels"/>
        </IconStyle>
    </Style>""" + inner_xml + """
</Document>
</kml>"""

    return outer_xml

def main():
    try:
        data = requests.get('https://pmtlogger.000webhostapp.com/api/getKML.php')

        data.raise_for_status()
    except HTTPError as e:
        print(f'HTTP error occurred: {http_err}')
    else:
        print(data.text)
        gpsData = json.loads(data.text)
        print(gpsData)
        inner_xml = "".join(constructPins(point) for point in gpsData) + constructPath(gpsData)
        xml = constructXml(inner_xml)

        with open("GPSData.kml", "w") as outfile:
            outfile.write(xml)

if __name__ == "__main__":
    main()
