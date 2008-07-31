<?php /* Smarty version 2.6.17, created on 2008-05-13 16:51:09
         compiled from observator_3d.tpl */ ?>
<div id="primarycontent">
	<div class="post">
		<div class="header">
			<h3>Observer_3D's explication</h3>
			<div class="date">May 7, 2008</div>
		</div>
		<div class="content">
			<p>soon...</p>
		</div>			
	</div>
		
	<div class="post">
		<div class="header">
			<h3>Observator's function:</h3>
		</div>
		<div class="content">
			<table class="table">
				<thead>
					<tr>
						<th>Id</th>
						<th>Name</th>
						<th>Prototype</th>
						<th>Description</th>
					</tr>
				</thead>
				<tbody>
					<?php $_from = $this->_tpl_vars['function']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['data']):
?>
					<tr>
						<td><?php echo $this->_tpl_vars['data']['id_fun']; ?>
</td>
						<td><?php echo $this->_tpl_vars['data']['name']; ?>
</td>
						<td><?php echo $this->_tpl_vars['data']['prototype']; ?>
</td>
						<td><?php echo $this->_tpl_vars['data']['description']; ?>
</td>
					</tr>
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
		<a href="./index.php?page=server">Server's functions</a><br />
		<a href="./index.php?page=observator_2D">Observator_2D's functions</a><br />
		<a href="./index.php?page=others">Other's functions</a><br />
		</div>
</div>