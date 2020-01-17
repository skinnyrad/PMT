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

$key ='1234567890abcdef';
$iv = $key;

//$data = array(); // Initialize default data array

// get size of the binary file
$filesize = filesize($filepath);
// open file for reading in binary mode
$fp = fopen($filepath, 'rb');
// read the entire file into a binary string
$binary = fread($fp, $filesize);
echo 'FROM FILE: ',$binary;

//$key = $_GET["key"];
//$iv = $_GET["iv"];
//echo $key.'|'.$iv;

// Read from file then DECRYPT using PHP
//list($crypted_token, $iv) = explode("::", $crypted_token);;
$cipher_method = 'aes-128-cbc';
$enc_key = openssl_digest($key, 'SHA256', TRUE);
$plaintext = openssl_decrypt($binary, $cipher_method, $enc_key, 0);
echo '\nDECRYPTED: '.$plaintext;
//unset($binary, $cipher_method, $enc_key, $iv);

$token = "1,-86.6412163420141,34.722586539952,2019-10-14,14:30:00,2,-86.6411210245048,34.7232260242348,2019-10-15,14:30:10,3,-86.6420061571728,34.7235031028468,2019-10-16,14:30:20,4,-86.6421187854007,34.7242470342329,2019-10-17,14:30:30,5,-86.641940000026,34.7245409600879,2019-10-18,14:30:40,6,-86.6421847643798,34.7248047166302,2019-10-19,14:30:50,7,-86.6425906007074,34.7246067235775,2019-10-20,14:31:00,8,-86.6427949012338,34.724206185779,2019-10-21,14:31:10,9,-86.6431778066368,34.7240024430458,2019-10-22,14:31:20,10,-86.6436242447878,34.7239260217465,2019-10-23,14:31:30,11,-86.6439779020318,34.7241005807449,2019-10-24,14:31:40,12,-86.6439714392672,34.7245197489505,2019-10-25,14:31:50,13,-86.6439375447486,34.7249956102817,2019-10-26,14:32:00,14,-86.6439286316693,34.7253607985706,2019-10-27,14:32:10,15,-86.6438679842583,34.7257620487998,2019-10-28,14:32:20,16,-86.6435760632231,34.7260039358756,2019-10-29,14:32:30,17,-86.6425538064605,34.7263005486733,2019-10-30,14:32:40,18,-86.641839485347,34.7267437665668,2019-10-31,14:32:50,19,-86.6409493466223,34.7273238940422,2019-11-01,14:33:00,20,-86.6400003351475,34.7276064727814,2019-11-02,14:33:10,21,-86.6385770412927,34.7276646692817,2019-11-03,14:33:20,22,-86.6380048458353,34.7269783973773,2019-11-04,14:33:30,23,-86.6382245303282,34.7264934421783,2019-11-05,14:33:40,24,-86.6389299520553,34.7261097279809,2019-11-06,14:33:50";
// PHP Implementation
// ENCRYPT
$cipher_method = 'aes-128-cbc';
$enc_key = openssl_digest($key, 'SHA256', TRUE);
//$enc_iv = openssl_random_pseudo_bytes(openssl_cipher_iv_length($cipher_method));
$crypted_token = openssl_encrypt($token, $cipher_method, $enc_key, 0, $iv) . "::" . bin2hex($iv);
echo 'PHP CRYPTED: '.$crypted_token;
unset($token, $cipher_method, $enc_key, $iv);
/*
// DECRYPT
list($crypted_token, $iv) = explode("::", $crypted_token);;
$cipher_method = 'aes-128-cbc';
$enc_key = openssl_digest($key, 'SHA256', TRUE);
//$plaintext = openssl_decrypt($crypted_token, $cipher_method, $enc_key, 0, hex2bin($iv));
echo '\nDECRYPTED: '.$plaintext;
unset($crypted_token, $cipher_method, $enc_key, $enc_iv);
*/


?>