

<?php
	$folders = array(
		'1_eksempel',
		'2_extra',
		'3_extramen',
		'4_uke_oppg',
		'5_uke_losn' 
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

			echo '<h2>' . $folder . '</h2>';
			$files = scandir('katalogen/' . $folder);

			foreach($files as $file) {
				if($file == '.' || $file == '..' || $file == '.DS_Store'){
					continue;
				}
				echo '<p>' . $file . '</p>'; 
			}
		}


		?>

	</div>
	</body>
</html>