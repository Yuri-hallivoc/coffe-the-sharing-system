<?php

$arquivo = $_FILES["arquivo"];
for($i = 0; $i < count($arquivo["tmp_name"]); $i++){
	move_uploaded_file($arquivo["tmp_name"][$i], $_SERVER["DOCUMENT_ROOT"].'/arquivos/'.$arquivo["name"][$i]);
}
include_once("index.php");

?>
