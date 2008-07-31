<?php /* Smarty version 2.6.17, created on 2008-05-14 20:24:43
         compiled from epitech.tpl */ ?>
<div id="primarycontent">
	<div class="post">
		<div class="header">
			<h3>Bonus</h3>
			<div class="date">May 7, 2008</div>
		</div>
		<div class="content">
			<p>soon...</p>
		</div>			
	</div>
		
	<div class="post">
		<div class="header">
			<h3>Epitceh's page:</h3>
		</div>
		<div class="content">
			<?php $_from = $this->_tpl_vars['url']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['data']):
?>
			<a href="<?php echo $this->_tpl_vars['data']; ?>
">link</a>
			<?php endforeach; endif; unset($_from); ?>
				</tbody>
			</table>
		</div>
	</div>
</div>

<div id="secondarycontent">
	<h3>Main parts:</h3>
	<div class="content">
		<a href="./index.php?page=api">Api's search</a><br />
		<a href="./index.php?page=client">Client's functions</a><br />
		<a href="./index.php?page=observator_2d">Observator_2D's functions</a><br />
		<a href="./index.php?page=observator_3d">Observator_3D's functions</a><br />
		<a href="./index.php?page=others">Other's functions</a><br />
		</div>
</div>