
<?php 
	
	if(empty($_GET['navn'])) 
		{die("FUCK YOU");}

	$path = 'http://folk.ntnu.no/frh/grprog/obliger/godkjent.html';
	$local = 'dump.html';


	$ch = curl_init("$path");
	$fp = fopen($local, 'w');

	curl_setopt($ch, CURLOPT_FILE, $fp);
	curl_setopt($ch, CURLOPT_HEADER, 0);

	curl_exec($ch);
	curl_close($ch);
	fclose($fp);


	function parseFile($local){
		$file = file_get_contents($local);

		$file = str_replace('&aring;',  'å', $file);
		$file = str_replace('&Aring;',  'Å', $file);
		$file = str_replace('&aelig;',  'æ', $file);
		$file = str_replace('&aelig;',  'Æ', $file);
		$file = str_replace('&oslash;', 'ø', $file);
		$file = str_replace('&Oslash;', 'Ø', $file);
		$file = str_replace('&nbsp;',   ' ', $file);
		$file = str_replace('</td>

   <tr>', '</td></tr>

   <tr>', $file);

		file_put_contents($local . '2', $file);
	}

	parseFile($local);

	$navn = $_GET['navn'];

	$html = new DOMDocument;
	@$html->loadHTML(file_get_contents($local));

	$tds = $html->getElementsByTagName('td');

	foreach ($tds as $td) {

		if ($td->nodeValue == $_GET['navn']) {

			echo $td->nodeValue;
			$sibling = $td->parentNode;

			$child = $sibling->childNodes[1];


		}
	}	
?>