<?php
require 'config/config.php';

if(file_exists($filepath_encrypted)) {
    unlink($filepath_encrypted);
    echo '<h2>File Cleared!</h2>';
}
else
    http_response_code(200);
?>