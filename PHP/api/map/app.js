/*
    PMT MAP Javascipt
*/
var map;
var mapLat = 34.724600;
var mapLng = -86.639590;
var mapDefaultZoom = 15;
var url = "https://pmtlogger.000webhostapp.com/api/getJSON.php";
var data = null;

var darkOSM = "http://{a-c}.basemaps.cartocdn.com/dark_all/{z}/{x}/{y}.png";
var tonerOSM = "http://{a-c}.tile.stamen.com/toner/{z}/{x}/{y}.png";
var openlOSM = "https://a.tile.openstreetmap.org/{z}/{x}/{y}.png";

var defaultLayer,tonerLayer,darkLayer;

var vectorSource;

function styleFunction(props) {
    return [
            new ol.style.Style({
            image: new ol.style.Icon({
                anchor: [0.5, 0.5],
                anchorXUnits: "fraction",
                anchorYUnits: "fraction",
                src: "https://upload.wikimedia.org/wikipedia/commons/e/ec/RedDot.svg"
            }),
            text: new ol.style.Text({
                text: props.id+"",
                font: 'Normal 12px Arial',
                fill: new ol.style.Fill({
                color: '#33BAFF'
            }),
            stroke: new ol.style.Stroke({
                color: '#000000',
                width: 3
            }),
            offsetX: -15,
            offsetY: 0,
            rotation: 0
            })
        })
    ];
}

function zoomTo(lat, long)
{
    map.getView().setCenter(ol.proj.transform([long, lat], 'EPSG:4326', 'EPSG:3857'));
    map.getView().setZoom(18);
}
function buildKml(){
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function() 
    {
        if (this.readyState == 4 && this.status == 200) {
            
            data = JSON.parse(this.responseText);
            var xml = "";
            var id = 1;
            data.forEach(point => {
            xml += "<Placemark><name>" + id++ + "</name>";
            xml += "<gx:TimeStamp><when>" +point.Date+ "T" + point.Time + "Z" + "</when></gx:TimeStamp>";
            xml += "<styleUrl>#m_ylw-pushpin</styleUrl>";
            xml += "<Point><coordinates>" + point.Longitude + "," + point.Latitude + ",0</coordinates></Point>";
            xml += "</Placemark>";
            });
            // path
            xml += "<Placemark><name>Path</name><styleUrl>#m_ylw-pushpin</styleUrl><LineString><tessellate>1</tessellate>"
            var path = "";
            data.forEach(point => { path+=point.Longitude + "," + point.Latitude + ",0" });
            xml = xml + "<coordinates>" + path + "</coordinates></LineString></Placemark>";
            var outer_xml = '<?xml version="1.0" encoding="UTF-8"?> <kml xmlns="http://www.opengis.net/kml/2.2" xmlns:gx="http://www.google.com/kml/ext/2.2" xmlns:kml="http://www.opengis.net/kml/2.2" xmlns:atom="http://www.w3.org/2005/Atom"> <Document> <name>GPSData</name> <Style id="s_ylw-pushpin"> <IconStyle> <scale>1.1</scale> <Icon> <href>http://maps.google.com/mapfiles/kml/pushpin/ylw-pushpin.png</href> </Icon> <hotSpot x="20" y="2" xunits="pixels" yunits="pixels"/> </IconStyle> </Style> <StyleMap id="m_ylw-pushpin"> <Pair> <key>normal</key> <styleUrl>#s_ylw-pushpin</styleUrl> </Pair> <Pair> <key>highlight</key> <styleUrl>#s_ylw-pushpin_hl</styleUrl> </Pair> </StyleMap> <Style id="s_ylw-pushpin_hl"> <IconStyle> <scale>1.3</scale> <Icon> <href>http://maps.google.com/mapfiles/kml/pushpin/ylw-pushpin.png</href> </Icon> <hotSpot x="20" y="2" xunits="pixels" yunits="pixels"/> </IconStyle> </Style>' + xml + '</Document> </kml>';
            
            // export kml to file
            var pom = document.createElement('a');
            var today = new Date();
            var date = today.getMonth()+'_'+today.getDate()+'_'+today.getFullYear();
            var filename = "PMT_Data_"+date+".kml";
            var pom = document.createElement('a');
            var bb = new Blob([outer_xml], {type: 'text/plain'});

            pom.setAttribute('href', window.URL.createObjectURL(bb));
            pom.setAttribute('download', filename);

            pom.dataset.downloadurl = ['text/plain', pom.download, pom.href].join(':');
            pom.draggable = true; 
            pom.classList.add('dragout');

            pom.click();

        }   
    };
    xhttp.open("GET", url, true);
    xhttp.send();
}

function add_data_points() {
    
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            data = JSON.parse(this.responseText);
            //console.log(data);
            var id = 1;
            data.forEach(d => {
                $('#table-data').append("<tr onclick='zoomTo("+d.Latitude+","+d.Longitude+");'><td>"+id+"</td><td>"+
                    d.Latitude+"</td><td>"+
                    d.Longitude+"</td><td>"+
                    d.Date+" "+
                    d.Time+"</td></tr>");
                d.id = id++;
                add_map_point(d.Latitude,d.Longitude,d);
                
            });
            // vectorSource defined globally
            var vectorLayer=new ol.layer.Vector({
                source: vectorSource
            })
            map.addLayer(vectorLayer); 
        }
    };
    xhttp.open("GET", url, true);
    xhttp.send();
}

function initialize_map() {

    defaultLayer = new ol.layer.Tile({
        source: new ol.source.OSM({
            url: openlOSM
        })
    });
    
    tonerLayer =  new ol.layer.Tile({
        source: new ol.source.OSM({
            url: tonerOSM
        }),
        visible: false
    });
    
    darkLayer  = new ol.layer.Tile({
        source: new ol.source.OSM({
            url: darkOSM
        }),
        visible: false
    });

    // data points layer
    vectorSource = new ol.source.Vector({});

    map = new ol.Map({
        target: "map",
        layers: [ defaultLayer, tonerLayer,darkLayer],
        view: new ol.View({
            center: ol.proj.fromLonLat([mapLng, mapLat]),
            zoom: mapDefaultZoom
        })
    });
    
    /**
     * Elements that make up the popup.
     */
    var container = document.getElementById('popup');

    var closer = document.getElementById('popup-closer');


    /**
     * Create an overlay to anchor the popup to the map.
     */
    var overlay = new ol.Overlay({
        element: container,
        autoPan: true,
        autoPanAnimation: {
            duration: 250
        }
    });
    // add overlya to map
    map.addOverlay(overlay);
        
        /**
     * Add a click handler to hide the popup.
     * @return {boolean} Don't follow the href.
     */
    closer.onclick = function() {
        overlay.setPosition(undefined);
        closer.blur();
        return false;
    };
    /**
     * Add a click handler to the map to render the popup.
     */

    map.on('singleclick', function(evt) {
        var coordinate = evt.coordinate;

        var features = [];
        map.forEachFeatureAtPixel(evt.pixel, function(feature, layer) {
            features.push(feature);
        });
        var container = document.getElementById('information');
        if (features.length > 0) {
            var content = document.getElementById('popup-content');
            var fields =['id','Longitude','Latitude','Date','Time'];
            var labels =['id','Longitude','Latitude','UTC-Date','UTC-Time'];
            var html="";
            for (let x = 0; x< fields.length; x++)
            {
                html+='<p>'+'<span style=" font-weight: bold;">'+labels[x]+'</span>: '+features[0].get(fields[x])+'</p>';
            }
            content.innerHTML = html;
            content.style = "color: black;font-size: 17px;";
            overlay.setPosition(coordinate);
        }
    });

    initComponents();
}

function add_map_point(lat, lng,props) {
    var feat = new ol.Feature({
        geometry: new ol.geom.Point(ol.proj.transform([parseFloat(lng), parseFloat(lat)], 'EPSG:4326', 'EPSG:3857')),
    });
    feat.setProperties(props);
    feat.setStyle(styleFunction(props));
    vectorSource.addFeature(feat);
    // data points added as features to one layer
}
var timer = null;
function onSwitchChanged(){

    if($('#live-switch-check').val() == "on"){
        //loadlink(); // This will run on page load
        
        var timer = setInterval(function(){
            if($('#live-switch-check').val() == "off")
                clearInterval(this);
            add_data_points() // this will run after every 5 seconds
        }, 5000);
        $('#live-switch-check').val('off');
    }
    else
        $('#live-switch-check').val('on');
    
}

function initComponents(){
    // map theme dropdown
    $('#maptrigger').dropdown();
    // mobile nav bar
    $(document).ready(function(){
        $('.sidenav').sidenav();
    });
}

function changeMapSource(val){
    var selection = "";
    switch(val){
        case 'dark': {
            darkLayer.setVisible(true);
            defaultLayer.setVisible(false);
            tonerLayer.setVisible(false);
        }; break;
        case 'toner': {
            darkLayer.setVisible(false);
            defaultLayer.setVisible(false);
            tonerLayer.setVisible(true);
        }; break;
        case 'default':{
            darkLayer.setVisible(false);
            defaultLayer.setVisible(true);
            tonerLayer.setVisible(false);
        }; break;
    }
}