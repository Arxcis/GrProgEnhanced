<DOCTYPE html5>
<html>
<head>
    <meta charset="utf-8"/>
    <title>GrProg image</title>
    <link href="https://fonts.googleapis.com/css?family=Open+Sans" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="css/style.css"/>

</head>
<body>

    <header>
        <h1>IMT1031 - GrProg enhanced</h1>
    </header>

    <div class="mainblock">
        <nav>  
            <br/> 
            <div id="nav1" class="navitem activeNav" onclick="switchView(this)">Forelesninger</div>
            <div id="nav2" class="navitem" onclick="switchView(this)">Oppgaver</div>
            <div id="nav3" class="navitem" onclick="switchView(this)">Obliger</div>
            <div id="nav4" class="navitem" onclick="switchView(this)">Pensum</div>
            <div id="nav5" class="navitem" onclick="switchView(this)">Fagasser</div>
            <div id="nav6" class="navitem" onclick="switchView(this)">Beskjeder</div>
            <div id="nav7" class="navitem" onclick="switchView(this)">Ressurser</div>
            <div id="nav8" class="navitem" onclick="switchView(this)">Mer info..</div>
            <br/>
            <div id="nav9" class="navitem" onclick="switchView(this)">Katalogen</div>
            <br/>
            <div id="nav10" class="navitem" onclick="switchView(this)">Godkjent</div>
            <div id="nav11" class="navitem" onclick="switchView(this)">Feil i læreboka</div>
        </nav>

        <main>
            <iframe id="leframe" src="http://folk.ntnu.no/frh/grprog/plan.html" 
                height="99%" width="99%"></iframe>
        </main>

    </div>
</body>
</html>

<script type="text/javascript">

    var hrefs = {

        'nav1' : 'http://folk.ntnu.no/frh/grprog/plan.html' ,
        'nav2' : 'http://folk.ntnu.no/frh/grprog/uke_oppg.html',
        'nav3' : 'http://folk.ntnu.no/frh/grprog/obliger/',
        'nav4' : 'http://folk.ntnu.no/frh/grprog/pensum.html',
        'nav5' : 'http://folk.ntnu.no/frh/grprog/fagass.html',
        'nav6' : 'http://folk.ntnu.no/frh/grprog/info.html',
        'nav7' : 'http://folk.ntnu.no/frh/grprog/ressurs.html',
        'nav8' : 'http://folk.ntnu.no/frh/grprog/stoff.html',
        'nav9' : 'katalogen.php',
        'nav10': 'http://folk.ntnu.no/frh/grprog/obliger/godkjent.html',
        'nav11': 'http://folk.ntnu.no/frh/grprog/bok_feil.html',
    }

    var activeNav = document.getElementById('nav1');


    function switchView(nav) {


        var id = nav.getAttribute('id');

        var frame  = document.getElementById('leframe');
        frame.setAttribute('src', hrefs[id]);


        if(activeNav)
            activeNav.className = "navitem";
        nav.className = "navitem activeNav";
        activeNav = nav;
    }


</script>