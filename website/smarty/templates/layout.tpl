<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>
	<head>
		<meta http-equiv="content-type" content="text/html; charset=iso-8859-1" />
		<title>Zappy bibicy</title>
		<meta name="keywords" content="" />
		<meta name="description" content="" />
		<link rel="stylesheet" type="text/css" href="default.css" />
	</head>
	<body>
		<div id="outer">
			<div id="upbg"></div>
			<div id="inner">
				<div id="header">
					<h1>Zia <span>Protocol</span></h1>
					<h2>{literal}{{/literal}Epitech. 42{literal}}{/literal}</h2>
				</div>
				<div id="splash">
				</div>
				<div id="menu">
					<ul>
						<li class="first"><a href="./index.php?page=index">Home</a></li>
						<li class="first"><a href="./index.php?page=presentation">Presentation</a></li>
						<li class="first"><a href="./index.php?page=documentation">Documentation</a></li>
						<li class="first"><a href="./index.php?page=doxygen">Doxygen</a></li>
						<li class="first"><a href="./index.php?page=download">Download</a></li>
						<li class="first"><a href="./index.php?page=about">About</a></li>
						</ul>
					<div id="date">{$smarty.now|date_format:"%A %B %e, %Y"}</div>
				</div>
				{foreach from=$ok item=ok}
					<p style="color:green">{$ok}</p>
				{/foreach}
				{if $errors eq ""}
					{include file="$content.tpl"}
				{/if}
				{include file="news.tpl"}
			</div>
			<div id="footer">
				&copy; Website CopyLeft [Caner Candan - Florent Hochwelker - Majdi Toumi - Morgan Armand]	
				{insert name="getBannerEpitech"} 
			</div>
		</div>
	</body>
</html>
