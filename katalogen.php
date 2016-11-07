
<DOCTYPE html5>
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
    	<link rel="stylesheet" type="text/css" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css"/>

    	<script type="text/javascript">
		
			function collapseFiles(ele) {
				var next = ele.nextSibling;

				var childs = next.childNodes;

				for(i=0; i<childs.length; i++) {

					console.log(childs[i].style.display);
					if (childs[i].style.display != 'none') {
						childs[i].style.display = 'none';
					}
					else
						childs[i].style.display = 'flex';
				}
				
			}
		</script>

	</head>

	<body>
	<div class="fileview" >   					<!-- Begin file view -->
		
		<?php

		foreach ($folders as $folder) {


			$formFolder = preg_replace('/\d_/is', '', $folder);
			$formFolder = ucfirst($formFolder);

			echo '<div class="fileheader" onclick="collapseFiles(this)"> 
			<h2>' . $formFolder . '<i class="fa fa-chevron-down" aria-hidden="true"></i> 
			</h2> 
			</div>';
			$files = scandir('katalogen/' . $folder);
			
			echo '<div class="filewrapper">';
			echo '<div class="lefiles">';	
												// Fill container with file-squares
			foreach($files as $file) {
				if($file == '.' || $file == '..' || $file == '.DS_Store'){
					continue;
				}

				$fullpath = 'katalogen' . DIRECTORY_SEPARATOR . $folder . DIRECTORY_SEPARATOR . $file;
				echo '<div class="file" onclick="location.href=\''.$fullpath.'\'">' . $file . '</div>'; 
			}

			echo '</div>';
			echo '</div>';
		}	
		?>

	</div>									      <!-- end file view -->
	</body>


</html>