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
//header('Content-Type: application/octet-stream');

require 'config/config.php';

//$data = array(); // Initialize default data array

// get id of product to be edited
$rawBody = file_get_contents("php://input");

// read the file if present
$handle = @fopen($filepath, 'r+');

// create the file if needed
if ($handle === false)
{
    $handle = fopen($filepath, 'w+');
}
    
if ($handle)
{
    // seek to the end
    fseek($handle, 0, SEEK_END);

    // are we at the end of is the file empty
    if (ftell($handle) > 0)
    {
        // move back a byte
        fseek($handle, -1, SEEK_END);

        // add the trailing comma
        //fwrite($handle, ',', 1);

        // add the new json string
        fwrite($handle, $rawBody);
    }
    else
    {
        // write the first event inside an array
        fwrite($handle,$rawBody);
    }

    // close the handle on the file
    fclose($handle);
    
    http_response_code(200);
    echo '<h1>OK!</h1>';
    
}
else
    http_response_code(404);


?>