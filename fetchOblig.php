
<?php

// -- TASK 1 -- 

function handleGET() {
	// ----- Easy get request handling ----
	$name = $_GET['navn'];
	if(empty($name)) 
			{ die('Byebye'); }

	return $name;
}
// ------------------------------------

function DOMhtml(){


}

// -- TASK 2 -- 
function htmlToXML($url, $local_path){

	$html  = new DOMDocument();
	$ohtml = new DOMDocument('1.0', 'utf-8');
	@$html->loadHTML(file_get_contents($url));

	$tds = $html->getElementsByTagName('tr');		
							// PHP_EOL and DIRECTORY_SEPARATOR is awsm

	$data = $ohtml->createElement('data');
	foreach($tds as $td) {
		$td = $ohtml->importNode($td, true);
		$data->appendChild($td);
	}

	$ohtml->appendChild($data);
	$fstring = $ohtml->saveXML();

	$fstring = str_replace('<br>', '<br/>', $fstring);
	file_put_contents($local_path, $fstring);
}

// -- TASK 3 -- 
function loadXML($filepath){

	$xml = new DOMDocument();
	$xml->load($filepath);

	return $xml;
}

function constructReturn($xdoc, $name){

	$xpath  = new DOMXpath($xdoc);
	$resDoc = new DOMDocument();

	$query = '//tr[./td/text() = "' .$name. '"]/td/p/text()';
	$rows = $xpath->query($query);

	createElementWithText($resDoc, 'p', $name);
	foreach ($rows as $row) {
		createElementWithText($resDoc, 'p', $row->nodeValue);

	}

	return $resDoc->saveHTML();
}


$url = 'http://folk.ntnu.no/frh/grprog/obliger/godkjent.html';  
$local_path = 'dump.html';


$name = handleGET();			    	// Step 1
htmlToXML($url, $local_path);	     	// Step 2
$xml = loadXML($local_path);		    // Step 3
echo constructReturn($xml, $name);	    // Step 4






        // Creates an element with a child-TextNode and appends it to a parent
function createElementWithText($parent, $tag, $text) {

    $textNode  = $parent ->createTextNode( $text );
    $element   = $parent ->createElement ( $tag  );
    $element             ->appendChild   ( $textNode );
    $parent              ->appendChild   ( $element  ); 

}
?>