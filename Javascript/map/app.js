/*
    PMT MAP Javascipt
*/
var map;
var mapLat = 34.724600;
var mapLng = -86.639590;
var mapDefaultZoom = 5;
var latLonDecimals = 7;

var GPS_INTERVAL = 10;

// var url = "https://pmtlogger.000webhostapp.com/api/getJSON.php";
var host_conf = "None";
var host_json_path = "/api/getJSON.php";
var url_encryption = "https://pmtlogger.000webhostapp.com/api/getEnc.php";
var data = null;

var darkOSM = "http://{a-c}.basemaps.cartocdn.com/dark_all/{z}/{x}/{y}.png";
var tonerOSM = "http://{a-c}.tile.stamen.com/toner/{z}/{x}/{y}.png";
var openlOSM = "https://a.tile.openstreetmap.org/{z}/{x}/{y}.png";

var defaultLayer,tonerLayer,darkLayer,USGSmap;
var vectorSource;

function styleFunction(props, fill) {
    return [
            new ol.style.Style({
            // image: new ol.style.Icon({
            //     anchor: [0.5, 0.5],
            //     anchorXUnits: "fraction",
            //     anchorYUnits: "fraction",
            //     src: "res/RedDot.svg"
            // }),
            image: new ol.style.RegularShape({
                fill: new ol.style.Fill({color: fill}),
                stroke: new ol.style.Stroke({color: 'black', width: 2}),
                points: 5,
                radius: 10,
                radius2: 4,
                angle: 0
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

// Zooms MAP to specified Lat/Long
function zoomTo(lat, long)
{
    map.getView().setCenter(ol.proj.transform([long, lat], 'EPSG:4326', 'EPSG:3857'));
    map.getView().setZoom(18);
}
// Constructs KML
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
            var today = new Date(Date.now()).toLocaleString().split(',')[0].split('/');
            var date = today[0]+'_'+today[1]+'_'+today[2];
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
    xhttp.open("GET", host_conf, true);
    xhttp.send();
}

function ab2str(buf) {
    return String.fromCharCode.apply(null, new Uint8Array(buf));
}
// Converts string to ByteArray
function strToByteArray(str){
    var bytes = []; // char codes
    var bytesv2 = []; // char codes

    for (var i = 0; i < str.length; ++i) 
    {
        var code = str.charCodeAt(i);
        
        bytes = bytes.concat([code]);
        
        bytesv2 = bytesv2.concat([code & 0xff, code / 256 >>> 0]);
    }

    // 72, 101, 108, 108, 111, 31452
    console.log('bytes', bytes.join(', '));

    // 72, 0, 101, 0, 108, 0, 108, 0, 111, 0, 220, 122
    console.log('bytesv2', bytesv2.join(', '));
}

function str2ab(str) {
    var buf = new ArrayBuffer(str.length); // 32 bytes
    var bufView = new Uint8Array(str.length);
    for (var i=0, strLen=str.length; i < strLen; i++) {
        bufView[i] = str.charCodeAt(i);
    }
    return bufView;
}

function pad_mod_16(_string){
    while (!(_string.length % 16 == 0))
        _string = _string + '_'
    return _string;
}

function csvJSON(csv){
    var csvArray=csv.split(",");
    var json=[];
    var i=0;
    // subtract null position at the end
    while(i < csvArray.length-1)
    {
        var ptn = Math.ceil(i/4);
        
        json.push({
            Time: csvArray[i],
            Latitude:parseFloat(csvArray[i+1]), 
            Longitude:parseFloat(csvArray[i+2]),
            Date: csvArray[i+3]
        });
        i+=4;
    }

    return json;
}

// DECRYPTION
function decrypt(key) {
        // key = '1234567890abcdef'
        var iv = "PharmacyPMT01546";
        

        var delimiter = "TINTINNABULATION";
        key = pad_mod_16(key);
        //var key_sha256 = sha256(key);
        $.ajax(
        {
            url: url_encryption,
            //context: document.body
            success: function(result) {
                //console.log(result+"\n\n");
                var ciphertext_b64 = result;
                
                // Find chunks and decrypt them
                // using regular expression
                // var regex = new RegExp(delimiter, "gi");
                // var result, indices = [];
                // while ( (result = regex.exec(ciphertext)) ) {
                //     if(result.index % 16 ==0)
                //         indices.push(result.index);
                // }
                // console.log(indices);
                var inCSV = "";
                var chunks = ciphertext_b64.split(delimiter);
                // decrypt every chunk
                chunks.forEach(ascii_ck => {
                    // decode a string from base64 format
                    var ciphertext = atob(ascii_ck);
                    // convert string to bytes
                    var ciphertext_bytes = Uint8Array.from(ciphertext, c => c.charCodeAt(0));
                    // CBC decryption (keys to bytearrays)
                    var aesCbc = new aesjs.ModeOfOperation.cbc(str2ab(pad_mod_16(key)), str2ab(iv));
                    // decryption
                    var decryptedBytes = aesCbc.decrypt(ciphertext_bytes);

                    // Convert our bytes back into text
                    var decryptedText = aesjs.utils.utf8.fromBytes(decryptedBytes);
                    // remove padding and append data
                    inCSV+=decryptedText.replace(/_/g, "");
                    
                });
                add_data_points(csvJSON(inCSV),'red');
            },
            error: function (err) {
                console.alert(err);
            }
        });
}
// ################

function add_data_points(data,color) {
    
    var id = 1;
    data.forEach(d => {
        $('#table-data').append("<tr onclick='zoomTo("+d.Latitude+","+d.Longitude+");'><td>"+id+"</td><td>"+
            // d.Latitude.toFixed(latLonDecimals)+"</td><td>"+
            // d.Longitude.toFixed(latLonDecimals)+"</td><td>"+
            d.Latitude+"</td><td>"+
            d.Longitude+"</td><td>"+
            d.Date+" "+
            d.Time+"</td></tr>");
        d.id = id++;
        add_map_point(d,color);
        
    });
    // FOR LATER: String time to OBJ
    let dateString = data[0].Date+" "+data[0].Time
        , reggie = /(\d{4})-(\d{2})-(\d{2}) (\d{2}):(\d{2}):(\d{2})/
        , [, year, month, day, hours, minutes, seconds] = reggie.exec(dateString)
        , dateObject = new Date(Date.UTC(year, month-1, day, hours, minutes, seconds));

    console.log(dateObject);
    console.log(dateObject.toString());
    // vectorSource defined globally
    var vectorLayer=new ol.layer.Vector({
        source: vectorSource
    })
    map.addLayer(vectorLayer); 
}

// Inits MAP and get points
function initialize_map() {

    defaultLayer = new ol.layer.Tile({
        source: new ol.source.OSM({
            url: openlOSM
        }),
        visible: true
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

    USGSmap = new ol.layer.Group({
        layerId: "topoimagery",
        visible: false,
        layers: [
            new ol.layer.Tile({
        source: new ol.source.XYZ({ url: 'https://basemap.nationalmap.gov/arcgis/rest/services/USGSImageryTopo/MapServer/tile/{z}/{y}/{x}' }),
        //minResolution: 3,
        //maxResolution: 15,
        }),
        new ol.layer.Tile({
            source: new ol.source.TileArcGISRest({ url: 'https://raster.nationalmap.gov/arcgis/rest/services/Orthoimagery/USGS_EROS_Ortho_1Foot/ImageServer' }),
            maxResolution: 3
        }),
        new ol.layer.Tile({
            source: new ol.source.TileArcGISRest({ url: 'https://services.nationalmap.gov/arcgis/rest/services/USGSImageryTopoLarge/MapServer' }),
            maxResolution: 3
        })]
    });


    // data points layer
    vectorSource = new ol.source.Vector({});

    map = new ol.Map({
        target: "map",
        layers: [ defaultLayer, tonerLayer,darkLayer,USGSmap],
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

    //var host = prompt("Please enter your HOST","https://pmtlogger.000webhostapp.com");
    // read configs

    var url = localStorage.getItem('host')+"/api/getJSON.php";
    host_conf = url;

    // GET data points
    M.toast({html: 'Loading...', classes: 'rounded red'});
    $.ajax(
        {
            url: url,
            //context: document.body
            success: function(result) {
                let inCSV = JSON.parse(result);
                add_data_points(inCSV,'red');
            },
            error: function (err) {
                M.toast({html: 'Error! Check Configs', classes: 'rounded red'});
            }
        });
    
}

function saveConfigs(){
    // HOST
    let c_host= $('#host-config')[0].value;
    localStorage.setItem("host", c_host);
    M.toast({html: 'Saved!', classes: 'rounded green'});
    $('#configs-modal').modal('close');
    // reload page to set configs
    if(localStorage.getItem('reload')=='true')
        location.reload();
}

function loadConfigs (){
    $('#host-config')[0].value = localStorage.getItem('host');
    localStorage.setItem("reload", true);
}
function generateConfFile(){
    let hst = $('#host-config')[0].value;
    if(hst!==null && hst!=="")
    {
        let pmt_conf = {"host":hst,"gps_interval":GPS_INTERVAL};
        let text_json = JSON.stringify(pmt_conf, null, "\t"); // stringify with tabs inserted at each level

        // export kml to file
        var pom = document.createElement('a');
        var filename = "pmt.conf";
        var pom = document.createElement('a');
        var bb = new Blob([text_json], {type: 'text/plain'});

        pom.setAttribute('href', window.URL.createObjectURL(bb));
        pom.setAttribute('download', filename);

        pom.dataset.downloadurl = ['text/plain', pom.download, pom.href].join(':');
        pom.draggable = true; 
        pom.classList.add('dragout');
        pom.click();

        
        M.toast({html: 'pmt.conf Generated!', classes: 'rounded green'});
    }
    else
        M.toast({html: 'HOST not set!', classes: 'rounded red'});
}

function add_map_point(props, color) {
    var feat = new ol.Feature({
        geometry: new ol.geom.Point(ol.proj.transform([parseFloat(props.Longitude),
            parseFloat(props.Latitude)], 'EPSG:4326', 'EPSG:3857')),
    });
    feat.setProperties(props);
    feat.setStyle(styleFunction(props,color));
    vectorSource.addFeature(feat);
    // data points added as features to one layer
}
// var timer = null;
// function onSwitchChanged(){

//     if($('#live-switch-check').val() == "on"){
//         //loadlink(); // This will run on page load
        
//         var timer = setInterval(function(){
//             if($('#live-switch-check').val() == "off")
//                 clearInterval(this);
//             add_data_points() // this will run after every 5 seconds
//         }, 5000);
//         $('#live-switch-check').val('off');
//     }
//     else
//         $('#live-switch-check').val('on');
    
// }


// Inits Javascript Components
function initComponents(){
    // map theme dropdown
    $('#maptrigger').dropdown();
    // mobile nav bar
    $(document).ready(function(){
        $('.sidenav').sidenav();
    });
    $(document).ready(function(){
        $('.modal').modal();
        
        // setup stuf
        localStorage.setItem("reload", false);
        // prompt user modal (feel in data)
        if(localStorage.getItem('host')== "")
            $('#configs-modal').modal('open');
    });
}

// Sets MAP Layers according to selection
function changeMapSource(val)
{
    var selection = "";
    switch(val)
    {
        case 'dark': {
            darkLayer.setVisible(true);
            defaultLayer.setVisible(false);
            tonerLayer.setVisible(false);
            
            USGSmap.setVisible(false);
        }; break;
        case 'toner': {
            darkLayer.setVisible(false);
            defaultLayer.setVisible(false);
            tonerLayer.setVisible(true);
            
            USGSmap.setVisible(false);
        }; break;
        case 'default':{
            darkLayer.setVisible(false);
            defaultLayer.setVisible(true);
            tonerLayer.setVisible(false);
            
            USGSmap.setVisible(false);
        }; break;
        case 'usgs':{
            darkLayer.setVisible(false);
            defaultLayer.setVisible(false);
            tonerLayer.setVisible(false);
            USGSmap.setVisible(true);
        }; break;
    }
}

// Prompt FileBrowser Window to select file to upload
function handleFileUpload()
{               
    if (!window.File || !window.FileReader || !window.FileList || !window.Blob) {
        alert('The File APIs are not fully supported in this browser.');
        return;
    }   

    var input = document.getElementById('upload-file');
    if (!input) {
        alert("Um, couldn't find the fileinput element.");
    }
    else if (!input.files) {
        alert("This browser doesn't seem to support the `files` property of file inputs.");
    }
    else if (!input.files[0]) {
        alert("Please select a file before clicking 'Load'");               
    }
    else {
        var file = input.files[0];
        var fr = new FileReader();
        fr.onload = function(e) { 
            var contents = e.target.result;
            add_data_points(csvJSON(contents),'blue');
        }
        fr.readAsText(file);
    }
}
