//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H15_2.CPP

//  Løsningsforslag til eksamen i C++, 1.desember 2015, oppgave 2.
//  Laget av Frode Haug, HiG, november 2015.

//  Programmet holder orden på ulike båter (i en båthavn/-forening)
//  og deres merke/produsent.


					//  INCLUDE:
#include <fstream>				//  ifstream, ofstream
#include <iostream>				//  cin, cout
#include <cstring>				//  strcpy, strcmp, strlen
#include <cctype>				//  toupper
using namespace std;

					//  CONST:
const int STRLEN    =  60;		//  Max. tekstlengde.
const int MAXMERKER =  20;		//  Max. antall båtmerker/-produsenter.
const int MAXBAATER = 400;		//  Max. båter i registeret.
const int STARTAAR = 1960;		//  Første år for båtmodellene.
const int SLUTTAAR = 2016;		//  Siste år for båtmodellene.
const int LAVHK    =    1;		//  Laveste hestekraft (Hk).
const int HOYHK    = 1200;		//  Høyeste hestekraft (Hk).
const int TLFSTART = 10000000;  //  Første telefonnummer.
const int TLFSLUTT = 99999999;	//  Siste telefonnummer.


class Merke  {		//  KLASSER:
  private:
    char navn[STRLEN / 2];		//  Båtmerkets/-produsentens navn.
	char adr[STRLEN * 2];		//  Adresse (postboks/gate og postnr/-sted).
	char www[STRLEN];           //  Hjemmeside (det etter "www.").
	int  tlf;					//  Kontaktelefon.

  public:					//  Deklarasjon av medlemsfunksjoner:
    Merke();					//  Ferdiglaget nedenfor.
	void skriv(int n);							//  Oppgave 2B
	void lesData();								//  Oppgave 2D
	void skrivTilFil(ofstream & ut);			//  Oppgave 2F
	void lesFraFil(ifstream & inn);				//  Oppgave 2G
};


class Baat  {
  private:
    char nr[STRLEN / 6];		//  Båtens registreringsnummer.
	char modell[STRLEN];		//  Modell/type.
	int  merke;					//  Merke/produsent - indeks i "merker"-array.
	int  aar;					//  Årsmodell.
	int  hk;					//  Motorstørrelse (i hestekrefter - hk).
	char eier[STRLEN];			//  Båteierens navn.
	int  tlf;					//  Båteierens telefon.

  public:					//  Deklarasjon av medlemsfunksjoner:
	Baat();						//  Ferdiglaget nedenfor.
	void skriv();							//  Oppgave 2A
	void lesData(char n[], int m);			//  Oppgave 2D
	void skrivTilFil(ofstream & ut);		//  Oppgave 2F
	void lesFraFil(ifstream & inn);			//  Oppgave 2G
	int  hentAar()  { return aar; }			//  Oppgave 2E
	int  hentHk()   { return hk; }			//  Oppgave 2E
	bool likNr(char t[])  { return (!strcmp(nr, t)); }
	bool likMerke(int n)  {  return (merke == n);      }

};

			//  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les();
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
int  finnNr(char t[]);
void skrivBaat();					//  Oppgave 2A
void skrivMerke();					//  Oppgave 2B
void slettBaat();					//  Oppgave 2C
void nyBaat();						//  Oppgave 2D
void finnBaat();					//  Oppgave 2E
void skrivTilFil();					//  Oppgave 2F
void lesFraFil();					//  Oppgave 2G

			//  GLOBALE VARIABLE:
Merke merker[MAXMERKER+1];			//  Array med Merke-objekter.
int sisteMerke;						//  Indeks for siste merke hittil brukt.
Baat baater[MAXBAATER+1];			//  Array med Baat-objekter.
int sisteBaat;                      //  Indeks for siste båt hittil brukt.


int main()  {			//  HOVEDPROGRAM:
   char kommando;

   lesFraFil();                                     //  Oppgave 2G
   skrivMeny();
   cout << "\nØnske:  ";  kommando = les();
   while (kommando != 'Q')  {
	   switch (kommando)  {
  	     case 'B':  skrivBaat();           break;   //  Oppgave 2A
         case 'M':  skrivMerke();          break;   //  Oppgave 2B
		 case 'S':  slettBaat();           break;   //  Oppgave 2C
		 case 'N':  nyBaat();	           break;   //  Oppgave 2D
		 case 'F':  finnBaat();	           break;   //  Oppgave 2E
         default:   skrivMeny();           break;
     }
     cout << "\nØnske:  ";  kommando = les();
   }
  skrivTilFil();                                    //  Oppgave 2F
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

Merke::Merke()  {				//  Constructor initierer alle datamedlemmer:
  strcpy(navn, "");   strcpy(adr, "");   strcpy(www, "");   tlf = 0;
}


void Merke::skriv(int n)  {		//  Oppgave 2B - Skriver ALLE egne data, og
	cout << "\n\t" << navn << ", " << adr << "\n\t\t"
		<< tlf << ", http://www." << www << '\n';
	for (int i = 1; i <= sisteBaat; i++)	//  ALLE merkets båter:
		if (baater[i].likMerke(n)) baater[i].skriv();
}


void Merke::lesData()  {		//  Oppgave 2D - Leser ALLE egne data:
	les("Navn ", navn, STRLEN / 2);
	les("Adr  ", adr, STRLEN * 2);
	les("www. ", www, STRLEN);
	tlf = les("Tlf  ", TLFSTART, TLFSLUTT);
}

								
void Merke::skrivTilFil(ofstream & ut)  { //  Oppgave 2F - Skriver ALT til fil:
	ut << navn << '\n' << tlf << "  " << www << "  " << adr << '\n';
}


void Merke::lesFraFil(ifstream & inn)  {	//  Oppgave 2G - Leser ALT fra fil:
	inn.getline(navn, STRLEN / 2);
	inn >> tlf >> www;  inn.ignore(2);
	inn.getline(adr, STRLEN * 2);
}



Baat::Baat()  {					//  Constructor initierer alle datamedlemmer:
	strcpy(nr, "");   strcpy(modell, "");   strcpy(eier, "");
	merke = aar = hk = tlf = 0;
}


void Baat::skriv()  {			//  Oppgave 2A - Skriver ALLE egne data:
	cout << "\n\t" << nr << ", År: " << aar << ",  Hk: " << hk
		 << ", " << modell << "\n\t" << eier << ", " << tlf << '\n';
}


void Baat::lesData(char n[], int m)  {   //  Oppgave 2D - Leser ALLE egne data:
  strcpy(nr, n);    merke = m;  cout << '\n'; // Lagrer unna input/parametre.
  les("Modell", modell, STRLEN);
  aar = les("År", STARTAAR, SLUTTAAR);
  hk  = les("Hk", LAVHK, HOYHK);
  les("Eier", eier, STRLEN);
  tlf = les("Tlf", TLFSTART, TLFSLUTT);
}


void Baat::skrivTilFil(ofstream & ut)  {  //  Oppgave 2F - Skriver ALT til fil:
	ut << merke << ' ' << nr << ' ' << aar << ' ' << hk << ' ' 
	   << tlf << ' ' << eier << '\n' << modell << '\n';
}


void Baat::lesFraFil(ifstream & inn)  {		//  Oppgave 2G - Leser ALT fra fil:
  inn >> merke >> nr >> aar >> hk >> tlf;  inn.ignore();
  inn.getline(eier, STRLEN);
  inn.getline(modell, STRLEN);
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
	cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
	cout << "\tB = skriv alt om en Båt\n";
	cout << "\tM = skriv alt om ett Merke\n";
	cout << "\tN = Ny båt (+ evt. nytt Merke)\n";
	cout << "\tF = Finn båter fra års- og hk-intervall\n";
	cout << "\tS = Slett/fjern en båt\n";
	cout << "\tQ = Quit/avslutt\n";
}


char les()  {			//  Henter ett ikke-blankt upcaset tegn:
	char ch;
	cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
	return (toupper(ch));         //  Upcaser og returnerer.
}

						//  Leser et tall i et visst intervall:
int les(const char t[], const int min, const int max)  {
	int n;
	do  {                                 // Skriver ledetekst:
		cout << '\t' << t << " (" << min << '-' << max << "): ";
		cin >> n;   cin.ignore();         // Leser inn ett tall.
	} while (n < min || n > max);         // Sjekker at i lovlig intervall.
	return n;                             // Returnerer innlest tall.
}

						//  Leser en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {
	do  {
		cout << '\t' << t << ": ";	cin.getline(s, LEN); //  Ledetekst og leser.
	} while (strlen(s) == 0);             //  Sjekker at tekstlengden er ulik 0.
}

							//  Finner (om mulig) indeksen for
int finnNr(char t[])  {		//	 en båt med et gitt regnr:
  for (int i = 1; i <= sisteBaat; i++)	//  Går gjennom båtene:
	if (baater[i].likNr(t))  return i;	//  Funn.
  return 0;								//  IKKE funn.
}


void skrivBaat()  {		//  Oppgave 2A - Skriver alle data om EN båt:
	char regnr[STRLEN / 6];				//  Båtens (reg)nr.
	int nr;								//  Indeks i "baater".
	les("Regnr", regnr, STRLEN / 6);	//  Ber om og leser (reg)nr.
	nr = finnNr(regnr);					//  Finner evt. indeks i "baater".
	if (nr) baater[nr].skriv();			//  Finnes: skriver dens data.
	else    cout << "\n\tIngen båt med dette regnr!\n";	//  Finnes IKKE.
}


void skrivMerke()  {	//  Oppgave 2B - Skriver ALT om ETT merke:
	int nr = les("Merkenr", 1, sisteMerke);  //  Leser aktuell merke-indeks.
	merker[nr].skriv(nr);                    //  Skriver ALT om merket.
}


void slettBaat()  {		//  Oppgave 2C - Sletter (om mulig) en båt:
	char regnr[STRLEN / 6];				//  Båtens (reg)nr.
	int nr;								//  Indeks i "baater".
  if (sisteBaat >= 1)  {				//  Båter finnes:
	  les("Regnr", regnr, STRLEN / 6);	//  Ber om og leser (reg)nr.
	  nr = finnNr(regnr);				//  Finner evt. indeks i "baater".
	  if (nr)  {							//  Finnes:
		  baater[nr] = baater[sisteBaat--];	//  Bakerste flyttes til 'hullet'.
		  cout << "\n\tBåt '" << regnr << "' er slettet. Antall båter igjen: " 
			   << sisteBaat << '\n';
	  } else cout << "\n\tIngen båt med dette regnr!\n"; //  Finnes IKKE.
  } else cout << "\n\tIngen båter i registeret!\n";		 //  Tomt for båter:
}

						//  Oppgave 2D - Legger (om mulig) inn
void nyBaat()  {		//               ny båt og evt. nytt merke også:
  char regnr[STRLEN / 6];				//  Båtens (reg)nr.
  int nr, nr2;							//  Båtens og merkets indeks.
  bool ok = true;						//  ALt OK hittil.

  if (sisteBaat < MAXBAATER)  {			//  Plass til flere båter:
	  les("Regnr", regnr, STRLEN / 6);	//  Ber om og leser (reg)nr.
	  nr = finnNr(regnr);				//  Finner evt. indeks i "baater".
	  if (!nr)  {								//  Finnes IKKE:
		  nr2 = les("Merkenr", 1, MAXMERKER);	//  Merkets (reelle nummer).
 	      if (nr2 > sisteMerke)					//  Nytt merke:
			  if (sisteMerke < MAXMERKER)  {	//  Plass til flere:
				  nr2 = ++sisteMerke;			//  Nytt legges bakerst.
  				  cout << "\n\tNytt merke blir nr: " << sisteMerke << '\n';
				  merker[nr2].lesData();		//  Merkets data leses.
			  } else {  cout << "\n\tFullt med merker!\n";  ok = false;  }
								//  Alt OK ifm. merket - leser ny båts data:
		  if (ok) baater[++sisteBaat].lesData(regnr, nr2);
	  } else cout << "\n\tBåt finnes allerede med dette regnr!\n";
  } else cout << "\n\tFullt med båter i registeret!\n";
}

						//  Oppgave 2E - Leter etter og skriver båter som har
void finnBaat()  {		//				 år og hk i visse intervaller:
	int startAar = les("Startår", STARTAAR, SLUTTAAR),  //  Leser aktuelle
		sluttAar = les("Sluttår", startAar, SLUTTAAR),  //    intervaller for
		startHk = les("Laveste Hk", LAVHK, HOYHK),		//    år og hk.
		sluttHk = les("Høyeste Hk", startHk, HOYHK),
		aar, hk;				//  En aktuell båts år og hk.
	bool utskrift = false;		//  Utskrift/funn har hittil IKKE forekommet.
								//  Går gjennom båtene:
	for (int i = 1; i <= sisteBaat; i++)  {		//  Henter båtens år og hk:
		aar = baater[i].hentAar();    hk = baater[i].hentHk();
		if (aar >= startAar  &&  aar <= sluttAar  &&   //  I rette intervaller?
			hk >= startHk  &&  hk <= sluttHk)  {
			utskrift = true;					//  Utskrift skjer.
			baater[i].skriv();					//  Aktuell båt skrives.
		}
	}										//  Utskrift har IKKE forekommet:
	if (!utskrift)  cout << "\n\tIngen båter funnet ut fra søkekriteriene.\n";
}


void skrivTilFil()  {     //  Oppgave 2F - Skriver HELE datastrukturen til fil:
	int i;									//  Løkkevariabel.
	ofstream utfil1("MERKER.DT2");			//  Åpner aktuell første fil.
	ofstream utfil2("BAATER.DT2");			//  Åpner aktuell andre fil.

	utfil1 << sisteMerke << '\n';
	for (i = 1; i <= sisteMerke; i++)
		merker[i].skrivTilFil(utfil1);

	utfil2 << sisteBaat << '\n';
	for (i = 1; i <= sisteBaat; i++)
		baater[i].skrivTilFil(utfil2);
}


void lesFraFil()  {          //  Oppgave 2G - Leser inn HELE datastrukturen:
	int i;									//  Løkkevariabel.
	ifstream innfil1("MERKER.DTA");			//  Åpner aktuell første fil.
	ifstream innfil2("BAATER.DTA");			//  Åpner aktuell andre fil.

	if (innfil1 && innfil2)  {               //  Begge filene finnes:
		innfil1 >> sisteMerke;   innfil1.ignore();
		for (i = 1; i <= sisteMerke; i++)
			merker[i].lesFraFil(innfil1);

		innfil2 >> sisteBaat;   innfil2.ignore();
		for (i = 1; i <= sisteBaat; i++)
			baater[i].lesFraFil(innfil2);
	} else                                   //  Minst en av filene finnes ikke:
		cout << "\n\nFinner ikke minst en av filene!\n\n";
}
