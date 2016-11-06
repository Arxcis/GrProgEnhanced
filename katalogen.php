

<?php
	$folders = array(
		'eksempel',
		'extra',
		'extramen',
		'uke_oppg',
		'uke_losn' 
		);

	echo 'This is PHP script';
?>

<html>
	<head>
	    <meta charset="utf-8"/>
	    <title> Katalogen </title>
	    <link href="https://fonts.googleapis.com/css?family=Open+Sans" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="css/style.css"/>
	</head>

	<body>
	<div class="filcontainer">
		
		<?php

		foreach ($folders as $folder) {

			echo '<h2>' . $folder . '</h2><br/>';
		}
 		// $files = scandir('katalogen/' + $folder); 

		?>

	</div>
	</body>
</html>