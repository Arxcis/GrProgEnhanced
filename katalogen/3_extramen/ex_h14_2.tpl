//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H14_2.TPL

//  Skjellettet/template for eksamen i C++, 2.desember 2014, oppgave 2.
//  Laget av Frode Haug, HiG, november 2014.

//  Programmet holder orden på lagene som deltar i en cup-turnering.
//  Hvem som skal spille mot hverandre, og hvem som fortsatt er med,
//  hvem som er utslått og kampoppsettet.
 

			//  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <cstring>               //  strcpy, strlen
#include <cctype>                //  toupper
using namespace std;

			//  CONST og ENUM:
const int STRLEN     =     60;   //  Max. tekstlengde.
const int MAXLAG     =    100;   //  Max. antall lag
enum status  { Alle, Med, Utslaatt };  //  Styrer handlinger noen steder.


class Lag  {		//  KLASSE:
  private:
    char navn[STRLEN];           //  Lagets navn.
    char deltager1[STRLEN];      //  Navnet til 1.deltager.
    char deltager2[STRLEN];      //  Navnet til 2.deltager.
    bool fortsattMed;            //  Laget fortsatt med eller utslått.
    int  motstander;             //  Indeksen til motstanderlaget,
	                         //           eller 0 (null).
public:                     //  Deklarasjon av medlemsfunksjoner:
    Lag();                       //  Ferdiglaget nedenfor.
    void lesData();                              //  Oppgave 2A
    void skriv(int n, status amu);               //  Oppgave 2B
    void endreStatus(status amu);                //  Oppgave 2D
    void skrivTilFil(ofstream & ut);             //  Oppgave 2F
    void lesFraFil(ifstream & inn, char b[]);    //  Oppgave 2G
                             //  3x ferdiglagde - brukes aktivt:
    bool deltarFortsatt()       {  return fortsattMed;  }
    void konkurrererMot(int n)  {  motstander = n;      }
    int  harSpiltMot()          {  return motstander;   }
};

			//  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les();
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
void nyttLag();                  //  Oppgave 2A
void skrivLagene();              //  Oppgave 2B
void oppsettAvKamp();            //  Oppgave 2C
void kampFerdig();               //  Oppgave 2D
void kampOppsettet();            //  Oppgave 2E
void skrivTilFil();              //  Oppgave 2F
void lesFraFil();                //  Oppgave 2G


			//  GLOBALE VARIABLE:
Lag lagene[MAXLAG+1];            //  Array med Lag-objekter.
int sisteLag;                    //  Indeks for siste Lag hittil brukt.

							  
int main()  {		//  HOVEDPROGRAM:
   char kommando;

   lesFraFil();                                     //  Oppgave 2G
   skrivMeny();
   cout << "\nØnske:  ";  kommando = les();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  nyttLag();               break;   //  Oppgave 2A
       case 'S':  skrivLagene();           break;   //  Oppgave 2B
       case 'O':  oppsettAvKamp();         break;   //  Oppgave 2C
       case 'F':  kampFerdig();            break;   //  Oppgave 2D
       case 'K':  kampOppsettet();         break;   //  Oppgave 2E
       default:   skrivMeny();             break;
     }
     cout << "\nØnske:  ";  kommando = les();
   }
  skrivTilFil();                                    //  Oppgave 2F
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

Lag::Lag()   {			//  Constructor initierer alle datamedlemmer:
  strcpy(navn, "");  strcpy(deltager1, "");  strcpy(deltager2, "");
  fortsattMed = true;   motstander = 0;
}

                               
void Lag::lesData()  {		//   Leser ALLE TEKST-data: 

        //  Oppgave 2A:  Lag innmaten
}
				//  Skriver ALLE data om laget når alle skrives
void Lag::skriv(int n, status amu)  {   //   eller de som fortsatt er med:

        //  Oppgave 2B:  Lag innmaten
}
                                //  Endrer når er utslått, og resetter motstanderen:
void Lag::endreStatus(status amu)  {

        //  Oppgave 2D:  Lag innmaten
}

                                
void Lag::skrivTilFil(ofstream & ut)  {           //  Skriver ALLE data til fil:

        //  Oppgave 2F:  Lag innmaten
}


void Lag::lesFraFil(ifstream & inn, char b[])  {  //  Leser alle egne data fra fil:

        //  Oppgave 2G:  Lag innmaten
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN    = Nytt lag\n";
  cout << "\tS A  = Skriv Alle lagene\n";
  cout << "\tS M  = Skriv lagene som fortsatt er Med\n";
  cout << "\tO    = Oppsett av kamp\n";
  cout << "\tF    = Ferdig med kamp/konkurranse\n";
  cout << "\tK    = Kampoppsettet\n";
  cout << "\tQ    = Quit/avslutt\n";
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
  } while(n < min  ||  n > max);         // Sjekker at i lovlig intervall.
  return n;                              // Returnerer innlest tall.
}

				//  Leser en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {  
  do  {
    cout << '\t' << t << ": ";	cin.getline(s, LEN); //  Ledetekst og leser.
  } while (strlen(s) == 0);             //  Sjekker at tekstlengden er ulik 0.
}


void nyttLag() {		 //  Legger (om mulig) inn et nytt lag:

        //  Oppgave 2A:  Lag innmaten
}


void skrivLagene()  {    //  Skriver lagene (ALLE eller kun de som fortsatt er MED:

        //  Oppgave 2B:  Lag innmaten
}

			 //  Legger inn (om mulig) hvilke to
void oppsettAvKamp()  {	 //        lag som skal konkurrere mot hverandre:

        //  Oppgave 2C:  Lag innmaten
}

			 //  Registrerer (om mulig) resultatet
void kampFerdig()  {     //          av konkurrranse/kamp (hvem vant/tapte):

        //  Oppgave 2D:  Lag innmaten
}


void kampOppsettet()  {  //  Skriver alle kampene (med høyeste lagnummer først):

        //  Oppgave 2E:  Lag innmaten
}


void skrivTilFil()  {    //  Skriver HELE datastrukturen til fil:

        //  Oppgave 2F:  Lag innmaten
}


void lesFraFil()  {      //  Leser inn HELE datastrukturen:

        //  Oppgave 2G:  Lag innmaten
}
