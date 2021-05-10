<?php

$arquivo = $_FILES["arquivo"];
move_uploaded_file($arquivo["tmp_name"], $_SERVER["DOCUMENT_ROOT"].'/arquivos/'.$arquivo["name"]);
include_once("index.php");

?>
