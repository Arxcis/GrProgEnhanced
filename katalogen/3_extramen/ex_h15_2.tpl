//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H15_2.TPL

//  Skjellettet/template for eksamen i C++, 1.desember 2015, oppgave 2.
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

//  Oppgave 2E:  Lag mer kode/funksjon(er).

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

							
void Merke::skriv(int n)  {  //  Skriver ALLE egne data, og ALLE merkets båter:

	//  Oppgave 2B:  Lag innmaten
}


void Merke::lesData()  {					//  Leser ALLE egne data:

	//  Oppgave 2D:  Lag innmaten
}

								
void Merke::skrivTilFil(ofstream & ut)  {	//  Skriver ALT til fil:

	//  Oppgave 2F:  Lag innmaten
}


void Merke::lesFraFil(ifstream & inn)  {	// Leser ALT fra fil:

	//  Oppgave 2G:  Lag innmaten
}



Baat::Baat()  {					//  Constructor initierer alle datamedlemmer:
	strcpy(nr, "");   strcpy(modell, "");   strcpy(eier, "");
	merke = aar = hk = tlf = 0;
}


void Baat::skriv()  {						//  Skriver ALLE egne data:

	//  Oppgave 2A:  Lag innmaten
}


void Baat::lesData(char n[], int m)  {		//  Leser ALLE egne data:

	//  Oppgave 2D:  Lag innmaten
}


void Baat::skrivTilFil(ofstream & ut)  {	//  Skriver ALT til fil:

	//  Oppgave 2F:  Lag innmaten
}


void Baat::lesFraFil(ifstream & inn)  {		//  Leser ALT fra fil:

	//  Oppgave 2G:  Lag innmaten
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
	do  {                                  // Skriver ledetekst:
		cout << '\t' << t << " (" << min << '-' << max << "): ";
		cin >> n;   cin.ignore();            // Leser inn ett tall.
	} while (n < min || n > max);         // Sjekker at i lovlig intervall.
	return n;                              // Returnerer innlest tall.
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


void skrivBaat()  {				//  Skriver alle data om EN båt:

	//  Oppgave 2A:  Lag innmaten
}


void skrivMerke()  {			//  Skriver ALT om ETT merke:

	//  Oppgave 2B:  Lag innmaten
}


void slettBaat()  {				//  Sletter (om mulig) en båt:

	//  Oppgave 2C:  Lag innmaten
}


void nyBaat()  {      //  Legger (om mulig) inn ny båt og evt. nytt merke også:

	//  Oppgave 2D:  Lag innmaten
}

								//  Leter etter og skriver båter som har
void finnBaat()  {				//				 år og hk i visse intervaller:

	//  Oppgave 2E:  Lag innmaten
}


void skrivTilFil()  {			//  Skriver HELE datastrukturen til fil:

	//  Oppgave 2F:  Lag innmaten
}


void lesFraFil()  {				//  Leser inn HELE datastrukturen:

	//  Oppgave 2G:  Lag innmaten
}
