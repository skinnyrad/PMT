<?php
//  ---------------CSV structure---------------
//  "id","Longitude","Latitude","Date","Time"

// php function to convert csv to json format
function csvToJson($csvString) {
    //read csv headers
    $csvArray = str_getcsv($csvString);
    $json = array();
    $i=0;
    while($i < count($csvArray))
    {
        $pnt = $i/5;
        $json[$pnt]['id'] = $csvArray[$i];
        $json[$pnt]['Longitude'] = $csvArray[$i+1];
        $json[$pnt]['Latitude'] = $csvArray[$i+2];
        $json[$pnt]['Date'] = $csvArray[$i+3];
        $json[$pnt]['Time'] = $csvArray[$i+4];
        
        $i = $i+  5;
    }
    return json_encode($json);
}

// required headers
header("Access-Control-Allow-Origin: *");
//header("Access-Control-Allow-Headers: access");
header("Access-Control-Allow-Methods: POST");
//header("Access-Control-Allow-Credentials: true");
//header('Content-Type: application/json');
header('Content-Type: application/octet-stream');

require 'config/config.php';

//$data = array(); // Initialize default data array

// get size of the binary file
$filesize = filesize($filepath);
// open file for reading in binary mode
$fp = fopen($filepath, 'rb');
// read the entire file into a binary string
$binary = fread($fp, $filesize);

$key = $_GET["key"];
$iv = $_GET["iv"];
echo $key.'|'.$iv;
if(!empty($key) && !empty($iv))
{
    $output = openssl_decrypt(base64_decode($binary), 'AES-256-CBC', $key, 0, $iv);
    
    echo $output;
    //http_response_code(200);
    
    
}
else
    http_response_code(404);


?>