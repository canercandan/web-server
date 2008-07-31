<?php
require('./smarty/libs/Smarty.class.php');
require('./php/db_libsql.php');

$smarty = new Smarty();
$smarty->template_dir = './smarty/templates';
$smarty->compile_dir = './smarty/templates_c';
$smarty->cache_dir = './smarty/cache';
$smarty->config_dir = './smarty/configs';
?>