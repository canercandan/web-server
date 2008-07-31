<?php
function	db_boisson_inventory()
{
	$query = "SELECT * FROM boisson";
	$result = mysql_query($query);
	if (!$result)
		return false;
	else
		{
		$i = 0;	
		while ($row = mysql_fetch_array($result))
		{
			$boisson[$i]['name'] = $row['name']; 
			$boisson[$i]['price'] = $row['price']; 
			$boisson[$i]['quantity'] = $row['quantity']; 
			$i++;
		}
	return ($fun);
	}
}
?>