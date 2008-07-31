<?php
function	db_connect()
{
	global	$host_db;
	global	$user_db;
	global	$pass_db;
	
	$link = mysql_connect('localhost', 'root'); //$host_db, $user_db); /*, base64_decode($pass_db)); */
	mysql_select_db('zappy');
	return ($link);
	}
?>