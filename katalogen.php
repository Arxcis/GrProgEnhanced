

<?php
	$folders = array(
		'1_eksempel',
		'2_extra',
		'3_extramen',
		'4_uke_oppg',
		'5_uke_losn' 
		);
?>

<html>
	<head>
	    <meta charset="utf-8"/>
	    <title> Katalogen </title>
	    <link href="https://fonts.googleapis.com/css?family=Open+Sans" rel="stylesheet">
    	<link rel="stylesheet" type="text/css" href="css/style.css"/>

    	<script type="text/javascript">
		
			function collapseFiles(ele) {
				var next = ele.nextSibling;
				
				var files = next.getElementsByClassName('file');

				for (i=0; i< files.length; i++){

					if (files[i].style.display == 'flex')
						files[i].style.display = 'none';
					else 
						files[i].style.display = 'flex';

				}

			}
		</script>

	</head>

	<body>
	<div class="fileview" >   					<!-- Begin file view -->
		
		<?php

		foreach ($folders as $folder) {

			echo '<div style="cursor: hand; "onclick="collapseFiles(this)"><h2 class="fileheader">' . $folder . '</h2></div>';
			$files = scandir('katalogen/' . $folder);

			echo '<div class="lefiles">';	
												// Fill container with file-squares
			foreach($files as $file) {
				if($file == '.' || $file == '..' || $file == '.DS_Store'){
					continue;
				}

				$fullpath = 'katalogen' . DIRECTORY_SEPARATOR . $folder . DIRECTORY_SEPARATOR . $file;
				echo '<a href="' . $fullpath . '"><div class="file">' . $file . '</div></a>'; 
			}

			echo '</div>';
		}	
		?>

	</div>									      <!-- end file view -->
	</body>


</html>