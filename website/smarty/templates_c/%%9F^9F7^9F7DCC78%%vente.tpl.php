<?php /* Smarty version 2.6.17, created on 2008-06-30 21:57:45
         compiled from vente.tpl */ ?>
<div id="primarycontent">
	<div class="post">
		<div class="header">
			<h3>Vente(s):</h3>
			<div class="date">May 7, 2008</div>
		</div>
		<div class="content">
			<p>Cette partie permet de vendre ... (boisson, barre chocolate, ...)</p>
		</div>			
	</div>
		
	<div class="post">
		<div class="header">
			<h3>Boissons:</h3>
		</div>
		<div class="content">
			<table class="table">
				<thead>
					<tr>
						<th>Nom</th>
						<th>Prix</th>
						<th>Quantite</th>
					</tr>
				</thead>
				<tbody>
					<?php $_from = $this->_tpl_vars['boisson']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['data']):
?>
					<tr>
						<td><?php echo $this->_tpl_vars['data']['name']; ?>
</td>
						<td><?php echo $this->_tpl_vars['data']['price']; ?>
</td>
						<td><?php echo $this->_tpl_vars['data']['quantity']; ?>
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
		<a href="./index.php?page=client">Client's functions</a><br />
		<a href="./index.php?page=server">Server's functions</a><br />
		<a href="./index.php?page=observator_2d">Observator_2D's functions</a><br />
		<a href="./index.php?page=observator_3d">Observator_3D's functions</a><br />
		<a href="./index.php?page=others">Other's functions</a><br />
		</div>
</div>