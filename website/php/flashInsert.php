<?php
function _get_browser()
{
  $browser = array ("OPERA", "MSIE", "NETSCAPE", "FIREFOX", "SAFARI", "KONQUEROR", "MOZILLA");
  $info[browser] = "OTHER";
  
  foreach ($browser as $parent) 
  {
	if ( ($s = strpos(strtoupper($_SERVER['HTTP_USER_AGENT']), $parent)) !== FALSE )
   {           
     $f = $s + strlen($parent);
     $version = substr($_SERVER['HTTP_USER_AGENT'], $f, 5);
     $version = preg_replace('/[^0-9,.]/','',$version);
              
     $info[browser] = $parent;
     $info[version] = $version;
     break; // first match wins
   }
  }
  return $info;
}

function smarty_function_flash($params, &$smarty)
{  
    $file = 'aa';
    $f_params = '';
    $debug = false;
    $basedir = isset($server_vars['DOCUMENT_ROOT']) ? $server_vars['DOCUMENT_ROOT'] : '';
    
    foreach($params as $_key => $_val) {
        switch($_key) {
            case 'file': $file = $_val; break;
            case 'width': $height = $_val; break;
            case 'height': $width = $_val; break;
            case 'extra': $f_params = $_val; break;
            case 'debug': $debug = $_val; break;
        }
    }

    if (empty($file)) {
        $smarty->trigger_error("flash: missing 'file' parameter", E_USER_NOTICE);
        return;        
    }

    if(!$sizes = @getimagesize($file)) {
        if(!file_exists($file)) {
            if ( $debug ) { $smarty->trigger_error("flash: unable to find '$file'", E_USER_NOTICE);	}
                return;
            } else if(!is_readable($file)) {
                if ( $debug ) { $smarty->trigger_error("flash: unable to read '$file'", E_USER_NOTICE); }
                return;
            } else {
                if ( $debug ) { $smarty->trigger_error("flash: '$file' is not a valid image file", E_USER_NOTICE); }
                return;
            }
        }

    if ( !isset($width) ) {
    	$width = $sizes[0];
    }
    if ( !isset($height) ) {
    	$height = $sizes[1];
    }
    if ( !isset($GLOBALS['smarty_flash_id']) ) {
    	$GLOBALS['smarty_flash_id'] = 0;
    }
    else {
    	$GLOBALS['smarty_flash_id']++;
    }

	/*
						<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
					codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,0,0"
					width="728" height="90" id="epitech-matrix" align="">
					<param name=movie value="flash/bandeau-epitech.swf"><param name=quality value=high>
					<embed src="flash/bandeau-epitech.swf" quality=high  width="728" height="90" name="bandeau-epitech" align=""
					type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer">
					</embed></object>
					*/

    $browser = _get_browser();
    if ( $browser['browser'] == 'MSIE' ) {
    	$flash_code='
		<object type="application/x-shockwave-flash" width="'.$width.'" height="'.$height.'" id="smarty_flash'.$GLOBALS['smarty_flash_id'].'">
		<param name="movie" value="'.$file.'" />
		<param name="quality" value="high" />
  '.$f_params.'
</object>
<script language="javascript" type="text/javascript">
    show_flash(\'smarty_flash'.$GLOBALS['smarty_flash_id'].'\');
</script>
        ';
    }
    else {
    	$flash_code='
<object type="application/x-shockwave-flash" data="'.$file.'" width="'.$width.'" height="'.$height.'">
  <param name="quality" value="high" />
  '.$f_params.'
</object>
        ';    	
    }

    return $flash_code;
}
?>
