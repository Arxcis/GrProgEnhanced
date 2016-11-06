//  Fil:  FAG_KURS \ H97 \ 1EA \ EXAMEN \ EX_S98.CPP

//  L›sningsforslag til kontinuasjonseksamen i C++ (1EA), 17.august 1998.
//  Laget av Frode Haug, HIG, august 1998.


//  Programmet gj›r at brukeren kan:
//     - Legge inn data om en ny serie av frimerker
//     - Skrive ut alle data om et spesifikt merke
//     - Skrive ut data om en spesifikk serie
//     - Skrive ut data om alle serier utkommet et gitt †r.


			//  INCLUDE:
#include <iostream>          //  cout, cin
#include <cctype>            //  toupper

using namespace std;

			//  CONST:
const int ANT_SERIER =  50;      //   500   //  Max. antall ulike serier.
const int ANT_MERKER = 200;      //  2000   //  Max. antall ulike merker.
const int STRLEN     =  80;                 //  Max. tekstlengde.


			//  STRUCT:
struct Serie  {
  char tittel[STRLEN];       //  Frimerkeseriens tittel.
  char kunstner[STRLEN];     //  Kunstneren(e) som har tegnet/laget serien.
  char dag_maaned[STRLEN];   //  Utgivelsesdag og -m†ned, f.eks: "6.april".
  int  aar;                  //  Utgivelsese†r, f.eks: 1960.
  bool FDC;                  //  Har (ikke) f›rstedagsbrev (=FDC) av serien.
};


struct Merke  {
  int   tilhoerer_serie;     //  Merkets serienummer i arrayen "serier".
  char  motiv[STRLEN];       //  Beskrivelse av frimerkets motiv.
  float paalydende;          //  Verdien p†trykket merket.
  int   ant_ustemplet,       //  Antallet man har av ustemplet utgave av merket.
	ant_stemplet;        //  Antallet man har av stemplet utgave av merket.
  long  opplagsantall;       //  Antallet utgitt av dette merket, f.eks: 5000000.
};


			//  DEKLARASJON AV PROSEDYRER:
void skriv_meny();
void ny_serie();
void skriv_merke();
void skriv_serie();
void skriv_aar();


			//  GLOBALE VARIABLE:
Serie serier[ANT_SERIER+1];     //  Array med data om de ulike seriene.
Merke merker[ANT_MERKER+1];     //  Array med data om de ulike merkene.
int siste_serie = 0,            //  Siste indeks brukt i serie-arrayen.
    siste_merke = 0;            //  Siste indeks brukt i merke-arrayen.


                        //  HOVEDPROGRAM:
int main()  {
  char kommando;

  skriv_meny();                             //  Skriver kommando-meny.
  cout << "\n\nGi kommando:  ";             //  Leser brukerens valg:
  cin >> kommando;   kommando = toupper(kommando);

  while (kommando != 'Q')  {                //  Looper til Quit/Avslutt:
    switch (kommando)  {
      case 'N':  ny_serie();       break;   //  H†ndterer de ulike valgene: 
      case 'M':  skriv_merke();    break;
      case 'S':  skriv_serie();    break;
      case 'A':  skriv_aar();      break;
      default :  skriv_meny();     break;   //  Skriver kommando-meny.
    }
    cout << "\n\nGi kommando:  ";             //  Leser brukerens valg:
    cin >> kommando;   kommando = toupper(kommando);
  }
 return 0;
}


void skriv_meny() {
  cout << "\n\n\nFLGENDE KOMMANDOER ER TILGJENGELIGE:";
  cout << "\n\tN - Ny serie (merker)";
  cout << "\n\tM - Skriv alle data om et Merke";
  cout << "\n\tS - Skriv data om en Serie";
  cout << "\n\tA - Skriv data om alle serier et gitt r";
  cout << "\n\tQ - Quit/avslutt";
}


void ny_serie()  {          //  Registrere en ny serie og alle dets merker:
  int ant_merker, har;      //  Antall merker i serien.
  cout << "\n\n\nREGISTRERING AV NY SERIE (MERKER):";
  cout << "\n\n\tAntall merker i serien:  ";
  cin >> ant_merker;  cin.ignore();

  siste_serie++;            //  Teller opp indeksen for den nye serien.
  cout << "\tSeriens tittel:           ";              //  Leser tittel:
  cin.getline(serier[siste_serie].tittel, STRLEN);
  cout << "\tSeriens kunstner(e):      ";              //  Leser kunstner(e):
  cin.getline(serier[siste_serie].kunstner, STRLEN);
  cout << "\tUtgivelsesdag/-m†ned:     ";              //  Leser utgivelses-
  cin.getline(serier[siste_serie].dag_maaned, STRLEN); //    dag og m†ned.
  cout << "\tUtgivelses†r:             ";              //  Leser utgivelses†r:
  cin >> serier[siste_serie].aar;
  cout << "\tHar(=1) / ikke(=0) FDC:   ";              //  Leser om har f›rste-
  cin >> har;   cin.ignore();                          //    dagsbrev eller ei.  
  serier[siste_serie].FDC = (har) ? true : false;      //  Setter korrekt FDC.

  for (int i = 1;  i <= ant_merker;  i++)  {      //  For hvert merke i serien:
      siste_merke++;        //  Teller opp indeksen for det nye merket.
      merker[siste_merke].tilhoerer_serie = siste_serie;  //  Legger inn merkets
							  //   serietilh›righet.
      cout << "\n\tData om merke nr." << siste_merke << ':';
      cout << "\n\t\tMotiv:              ";               //  Leser motiv-
      cin.getline(merker[siste_merke].motiv, STRLEN);     //    beskrivelse.
      cout << "\t\tP†lydende:          ";                 //  Leser p†trykt
      cin >> merker[siste_merke].paalydende;              //    verdi.
      cout << "\t\tAntall stemplet:    ";                 //  Leser antall
      cin >> merker[siste_merke].ant_stemplet;            //   stemplet.
      cout << "\t\tAntall ustemplet:   ";                 //  Leser antall
      cin >> merker[siste_merke].ant_ustemplet;           //    ustemplet.
      cout << "\t\tOpplag:             ";                 //  Leser opplags-
      cin >> merker[siste_merke].opplagsantall;  cin.ignore();  //  antall.
  }
}


void skriv_merke()  { //  Skriver (om mulig) alle data om et spesifikt merke:
  int nr;             //  Nummeret til merket brukeren vil se alle data om.
  int snr;            //  Nummeret i serie-arrayen dette merket tilh›rer.
  cout << "\n\nHvilket merkenummer vil du se data om:  ";
  cin >> nr;                               //  Leser aktuelt merkes nummer.
  if (nr >= 1  && nr <= siste_merke)  {    //  Merket finnes:
     cout << "\nData om dette merket:";
     snr = merker[nr].tilhoerer_serie;     //  Henter merkets serienummer.
     cout << "\n\tTilh›rer serien:  " << serier[snr].tittel;     //  Skriver ut
     cout << "\n\tMotiv:            " << merker[nr].motiv;       //    alle
     cout << "\n\tP†lydende:        " << merker[nr].paalydende;  //    relevante
     cout << "\n\tAntall ustemplet: " << merker[nr].ant_ustemplet; //  data:
     cout << "\n\tAntall stemplet:  " << merker[nr].ant_stemplet;
     cout << "\n\tOpplagsantall:    " << merker[nr].opplagsantall;
  } else                                   //  Merket finnes IKKE:
    cout << "\n\tUgyldig merkenummer!";
}


void skriv_serie()  { //  Skriver (om mulig) data om en spesifikk serie:
  int nr;             //  Nummeret til et eller annet merke i serien.
  int snr;            //  Nummeret i serie-arrayen dette merket tilh›rer.
  int fnr;            //  Nummeret til det f›rste merket i denne serien.
  int enr;            //  Nummeret til det siste (ende) merket i denne serien.
  cout << "\n\nAngi et merkenummer i den aktuelle serien: ";
  cin >> nr;                               //  Leser aktuelt merkes nummer.
  if (nr >= 1  && nr <= siste_merke)  {    //  Merket finnes:
     snr = merker[nr].tilhoerer_serie;     //  Henter merkets serienummer.
     fnr = enr = nr;                       //  Initierer variable for s›king.
		// Leter bakover til det f›rste merket i den aktuelle serien:
     while (fnr-1 > 0  &&  merker[fnr-1].tilhoerer_serie == snr)  fnr--;   
		// Leter forover til det siste merket i den aktuelle serien:
     while (enr < siste_merke  &&  merker[enr+1].tilhoerer_serie == snr)  enr++;

     cout << "\nData om denne serien:";
     cout << "\n\tTittel:       " << serier[snr].tittel;          //  Skriver ut
     cout << "\n\tKunstner(e):  " << serier[snr].kunstner;        //   alle
     cout << "\n\tUtgivelse:    " << serier[snr].dag_maaned << '-' //  relevante
				  << serier[snr].aar;              //  data:
    cout << "\n\tHar " << (serier[snr].FDC ? "" : "IKKE ") << "f›rstedagsbrev.";
     cout << "\n\tI denne serien finnes merkene:";
     for (int i = fnr;  i <= enr;  i++)
	 cout << "\n\t\t" << i << ":\t" 
	      << merker[i].paalydende << ",  " << merker[i].motiv; 
  } else
    cout << "\n\tUgyldig merkenummer!";
}


void skriv_aar()  {   //  Skriver (om mulig) data om alle serier et gitt †r:
  int aar;            //  Aktuelt †rstall brukeren vil se alle seriene for.
  int snr;
  cout << "\n\nHvilket †rtall vil du se alle seriene for: ";
  cin >> aar;                            //  Leser aktuelt †rstall.
  snr = 1;                               //  Initierer indeksen for "serier".
	 //  Leter (om mulig) fram til der alle seriene dette †rstallet starter:
  while (snr <= siste_serie  &&  serier[snr].aar != aar)  snr++;
				       //  Serie med aktuelt †rstall er funnet:
  if (snr <= siste_serie  &&  serier[snr].aar == aar)  {
     cout << "\nData om serier utgitt i " << aar << ':';
				       // G†r gjennom alle aktuelle serier:
     while (snr <= siste_serie  &&  serier[snr].aar == aar)  { 
       cout << "\n\tTittel:       " << serier[snr].tittel       // Skriver rele-
	    << ",\t"                << serier[snr].dag_maaned;  //   vante data:
       snr++;
     }
  } else
    cout << "\n\tIngen serier utgitt dette †rstallet!";
}
