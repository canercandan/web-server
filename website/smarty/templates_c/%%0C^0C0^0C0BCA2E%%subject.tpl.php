<?php /* Smarty version 2.6.17, created on 2008-05-08 14:01:19
         compiled from subject.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'date_format', 'subject.tpl', 5, false),)), $this); ?>
<div id="primarycontent">
	<div class="post">
		<div class="header">
			<h3>ZAPPY Bibicy:</h3>
			<div id="date"><?php echo ((is_array($_tmp=time())) ? $this->_run_mod_handler('date_format', true, $_tmp, "%A %B %e, %Y") : smarty_modifier_date_format($_tmp, "%A %B %e, %Y")); ?>
</div>
		</div>
		<div class="content">
			<center><h4><strong>Jeu en réseau en temps réel avec un serveur et de multiples clients.</strong></h4></center>
			<br />
			<img src="images/zappy.png" class="picA floatleft" alt="" /><br />
			<h4><strong><u>But du projet :</u></strong></h4> 
			Développer en C un serveur de jeu zappy et un client graphique en C ou Perl.
		</div>
		<br /><br />
		<div class="content">
			<h4><u><strong>Principe :</strong></u></h4>
			Le jeu consiste à gérer un univers et ses habitants. Ce monde, nommé Trantor, est géographiquement constitué de plaines et ne comprend aucun autre relief.
			<br /><br />
			Le plateau de jeu représente la totalité de la surface de ce monde, comme un planisphère. Des ressources alimentaires et minières sont générées aléatoirement sur le terrain.
			<br /><br />
			Le Trantorien est pacifique. Il n'est ni violent, ni agressif. Il déambule gaiement en quête de pierres et s'alimente au passage. Il croise sans difficulté ses semblables sur une même unité de terrain et voit aussi loin que ses capacités visuelles le lui permettent.
			<br /><br />
			C'est un être immatériel, flou, qui occupe toute la case dans laquelle il se trouve. Il est impossible de distinguer son orientation lorsqu'on le croise. La nourriture qu'il ramasse lui permet de vivre pendant un certain laps de temps.
			<br /><br />
			L'objectif des joueurs est de s'élever dans la hiérarchie trantorienne. Cette "augmentation", qui permet d'accroître ses capacités physiques et mentales, doit être effectuée selon un rite particulier. Il faut en effet réunir sur la même unité de terrain:
			<br /><br />
			* Une combinaison de pierres,<br />
			* Un certain nombre de joueurs de même niveau.
			<br /><br />
			Un joueur débute l'incantation et lance ainsi le processus d'élévation. Il n'est pas nécessaire que les participants soient de la même équipe. Seul leur niveau importe. Tous les joueurs du groupe réalisant l'incantation atteignent le niveau supérieur.
			<br /><br />
			Pour compliquer la tâche de l'IA, le champ de vision des joueurs est limité. A chaque élévation, la vision augmente d'une unité de mesure en avant et d'une de chaque côté de la nouvelle rangée.
			<br /><br />
			Un Trantorien a également moyen de détecter la présence de ses congénères en émettant une onde-radar lui indiquant la direction à prendre pour les rejoindre.
			<br /><br />
			Le jeu se joue par équipe. L'équipe gagnante est celle dont six joueurs auront atteint l'élévation maximale.
		</div>			
	</div>
</div>