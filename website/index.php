<?php
session_start();
require_once('init.php');

$page = 'index';
if (!empty($_GET['page']))
{	
	$tpl = getcwd() . '/smarty/templates/' . $_GET['page'] . '.tpl';
	$php = getcwd() . '/' . $_GET['page'] . '.php';
	if (file_exists($tpl) && file_exists($php))
		$page = $_GET['page'];
}
require_once($page. '.php');

if (!empty($errors))
	$smarty->assign('errors', $errors);
else if (!empty($warnings))
	$smarty->assign('warnings', $warnings);
else if (!empty($ok))
	$smarty->assign('ok', $ok);

function	insert_getBannerEpitech()
{
	$banner = '<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"';
	$banner .= ' codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,0,0"';
	$banner .= ' width="2" height="2" id="epitech-matrix" align="">';
	$banner .= ' <param name=movie value="flash/bandeau-epitech.swf"><param name=quality value=high>';
	$banner .= ' <embed src="http://www.epitech.eu/v4/flash/bandeau-epitech.swf" quality=high  width="468" height="60" name="bandeau-epitech" align=""';
	$banner .= ' type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer"></embed></object>';
	return ($banner);
}
	
$smarty->assign('content', $page);
$smarty->display('layout.tpl');
?>