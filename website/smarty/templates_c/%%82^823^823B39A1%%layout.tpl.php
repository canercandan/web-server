<?php /* Smarty version 2.6.17, created on 2008-07-28 22:12:21
         compiled from layout.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'date_format', 'layout.tpl', 29, false),array('insert', 'getBannerEpitech', 'layout.tpl', 41, false),)), $this); ?>
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
					<h2><?php echo '{'; ?>
Epitech. 42<?php echo '}'; ?>
</h2>
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
					<div id="date"><?php echo ((is_array($_tmp=time())) ? $this->_run_mod_handler('date_format', true, $_tmp, "%A %B %e, %Y") : smarty_modifier_date_format($_tmp, "%A %B %e, %Y")); ?>
</div>
				</div>
				<?php $_from = $this->_tpl_vars['ok']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['ok']):
?>
					<p style="color:green"><?php echo $this->_tpl_vars['ok']; ?>
</p>
				<?php endforeach; endif; unset($_from); ?>
				<?php if ($this->_tpl_vars['errors'] == ""): ?>
					<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => ($this->_tpl_vars['content']).".tpl", 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
				<?php endif; ?>
				<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "news.tpl", 'smarty_include_vars' => array()));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
			</div>
			<div id="footer">
				&copy; Website CopyLeft [Caner Candan - Florent Hochwelker - Majdi Toumi - Morgan Armand]	
				<?php require_once(SMARTY_CORE_DIR . 'core.run_insert_handler.php');
echo smarty_core_run_insert_handler(array('args' => array('name' => 'getBannerEpitech')), $this); ?>
 
			</div>
		</div>
	</body>
</html>