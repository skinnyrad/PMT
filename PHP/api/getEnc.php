<?php
require 'config/config.php';
header("Access-Control-Allow-Origin: *");

 // Process download
if(file_exists($filepath_encrypted)) {
    // header('Content-Description: File Transfer');
    //header('Content-Type: application/octet-stream');
    // header('Content-Disposition: attachment; filename="'.basename($filepath).'"');
    // header('Expires: 0');
    // header('Cache-Control: must-revalidate');
    // header('Pragma: public');
    // header('Content-Length: ' . filesize($filepath));
    // flush(); // Flush system output buffer
    // readfile($filepath);
    $file = file_get_contents($filepath_encrypted, FILE_USE_INCLUDE_PATH);
    echo $file;
} else {
    http_response_code(404);
}
?>