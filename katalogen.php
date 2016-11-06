

<?php 
	$folders = array(
		'eksempel',
		'extra',
		'extramen',
		'uke_oppg',
		'uke_losn',
	);
	echo 'This is PHP script2';
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

			echo '<h2> ' + $folder + '</h2>';

/*			$files = scandir('katalogen/' + $folder);

			foreach ($files as $file) {

			}
*/
		}

		?>

	</div>
	</body>
</html>