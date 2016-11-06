//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S15_2.TPL

//  Skjellettet/template for eksamen i C++, 12.august 2015, oppgave 2.
//  Laget av Frode Haug, HiG, juli 2015.

//  Programmet holder orden på ulike sykkellag og rytterne/syklistene
//  på disse lagene, samt hvem av syklistene som har brutt sykkelrittet.

 
			//  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <cstring>               //  strcpy, strcmp, strlen
#include <cctype>                //  toupper
using namespace std;


			//  CONST:
const int STRLEN     =     60;     //  Max. tekstlengde.
const int MAXLAG     =     22;     //  Max. antall sykkellag.
const int MAXPRLAG   =      9;     //  Max. antall ryttere pr. lag.
const int KOMP       =     10;     //  Kompensasjon (nr.11 er indeks 1).
                                   //  Max. antall ryttere/syklister:
const int MAXRYTTERE = MAXLAG * (MAXPRLAG + 1);   //  = 220


class Lag  {		//  KLASSE:
  private:
    int  nr;                     //  Nummer/indeks.
    char navn[STRLEN];           //  Navn.
    char land[STRLEN/15];        //  Land/nasjonalitet (tre bokstaver).
    char tlf[STRLEN/2];          //  Kontaktinfo: Telefon
    int  antallRegistrert;       //  Antall ryttere hittil registrert på laget.

  public:                        //  Deklarasjon av medlemsfunksjoner:
    Lag();                       //  (Ferdiglaget nedenfor)
    bool finnes();               //  (Ferdiglaget nedenfor)
    void enRytterTil();          //  (Ferdiglaget nedenfor)
    void skriv();                            //  Oppgave 2B
    void nytt(int n);                        //  Oppgave 2C
    void skrivTilFil(ofstream & ut);         //  Oppgave 2E
    void lesFraFil(int n, ifstream & inn);   //  Oppgave 2F
    int  antallManglendeRyttere();           //  Oppgave 2G
};


class Rytter  {
  private:
    char navn[STRLEN];           //  Syklistens navn.
    char land[STRLEN/15];        //  Land/nasjonalitet (tre bokstaver).
    bool brutt;                  //  Brutt (eller fortsatt med).

  public:                        //  Deklarasjon av medlemsfunksjoner:
    Rytter();                    //  (Ferdiglaget nedenfor)
    bool finnes();               //  (Ferdiglaget nedenfor)
    void skriv();                            //  Oppgave 2A
    void ny();                               //  Oppgave 2D
    void skrivTilFil(ofstream & ut);         //  Oppgave 2E
    void lesFraFil(ifstream & inn);          //  Oppgave 2F
    void bruttRittet();                      //  Oppgave 2G
};


			//  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les();
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
void skrivEnRytter();            //  Oppgave 2A
void skrivEttLag();              //  Oppgave 2B
void nyttLag();                  //  Oppgave 2C
void nyRytter();                 //  Oppgave 2D
void skrivTilFil();              //  Oppgave 2E
void lesFraFil();                //  Oppgave 2F
void rytterBrutt();              //  Oppgave 2G
void statusLagene();             //  Oppgave 2G


			//  GLOBALE VARIABLE:
Lag    lagene[MAXLAG+1];            //  Array med Lag-objekter.
Rytter ryttere[MAXRYTTERE];         //  Array med Rytter-objekter.      

							  
int main()  {			//  HOVEDPROGRAM:
   char kommando;

   lesFraFil();                                     //  Oppgave 2F

   skrivMeny();
   cout << "\nØnske:  ";  kommando = les();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'L':  nyttLag();               break;   //  Oppgave 2C
       case 'R':  nyRytter();              break;   //  Oppgave 2D
       case 'S':  skrivEnRytter();         break;   //  Oppgave 2A
       case 'E':  skrivEttLag();           break;   //  Oppgave 2B
       case 'B':  rytterBrutt();           break;   //  Oppgave 2G
       case 'T':  statusLagene();          break;   //  Oppgave 2G
       default:   skrivMeny();             break;
     }
     cout << "\nØnske:  ";  kommando = les();
   }
  skrivTilFil();                                    //  Oppgave 2E
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

Lag::Lag()   {			//  Constructor initierer alle datamedlemmer:
  nr = 0;  strcpy(navn, "");  strcpy(tlf, "");  antallRegistrert = 0;
}


bool Lag::finnes()  {           //  Returnerer om objektet er i bruk eller ei
  return (strcmp(navn, ""));    //     (er navnet IKKE blankt er det i bruk).
}


void Lag::enRytterTil()  {      //  En rytter til er registrert på/i laget:
  ++antallRegistrert;
}


void Lag::skriv()  {                             //  Skriver ALT om laget:

        //  Oppgave 2B:  Lag innmaten
}


void Lag::nytt(int n)  {                         //  Leser ALLE egne data:

        //  Oppgave 2C:  Lag innmaten
}

 
void Lag::skrivTilFil(ofstream & ut)  {          //  Skriver ALT eget til fil:

        //  Oppgave 2E:  Lag innmaten
}


void Lag::lesFraFil(int n, ifstream & inn)  {    //  Leser ALT eget fra fil:

        //  Oppgave 2F:  Lag innmaten
}

               //  Returnerer antall gjenstående ryttere å registrerer på laget:
int  Lag::antallManglendeRyttere()  {     

        //  Oppgave 2G:  Lag innmaten
}


// --------------------------------------------------------------------------

Rytter::Rytter()  {             //  Constructor initierer alle datamedlemmer:
  strcpy(navn, "");  strcpy(land, "");  brutt = false; 
}    


bool Rytter::finnes()  {        //  Returnerer om objektet er i bruk eller ei
  return (strcmp(navn, ""));    //     (er navnet IKKE blankt er det i bruk).
}


void Rytter::skriv()  {         //  Skriver ALT om rytteren:

        //  Oppgave 2A:  Lag innmaten
}


void Rytter::ny()  {            //  Leser ALLE egne data:

        //  Oppgave 2D:  Lag innmaten
}

                                //  Skriver ALT eget til fil:
void Rytter::skrivTilFil(ofstream & ut)  { 

        //  Oppgave 2E:  Lag innmaten
}

                                //  Leser ALT eget fra fil:
void Rytter::lesFraFil(ifstream & inn)  {     

        //  Oppgave 2F:  Lag innmaten
}


void Rytter::bruttRittet()  {   //  Registrerer at rytter brutt:

        //  Oppgave 2G:  Lag innmaten
}



// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tL  = nytt Lag\n";
  cout << "\tR  = ny Rytter\n";
  cout << "\tS  = Skriv en rytter\n";
  cout << "\tE  = skriv HELE Ett lag\n";
  cout << "\tB  = rytter Brutt\n";
  cout << "\tT  = sTatus lagene\n";
  cout << "\tQ  = Quit/avslutt\n";
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


void skrivEnRytter()  {      //  Skriver ALLE data om EN rytter:

        //  Oppgave 2A:  Lag innmaten
}


void skrivEttLag()  {        //  Skriver ALLE data om ETT lag:

        //  Oppgave 2B:  Lag innmaten
}


void nyttLag()  {            //  Registrerer nytt lag:

        //  Oppgave 2C:  Lag innmaten
}


void nyRytter()  {           //  Registrerer ny rytter:

        //  Oppgave 2D:  Lag innmaten
}


void skrivTilFil()  {        //  Skriver HELE datastrukturen til fil:

        //  Oppgave 2E:  Lag innmaten
}


void lesFraFil()  {          //  Leser HELE datastrukturen fra fil:

        //  Oppgave 2F:  Lag innmaten
}


void rytterBrutt()  {        //  ( Registrerer at rytter har brutt )

        //  Oppgave 2G:  Lag innmaten
}


void statusLagene()  {       //  Skriver status for ALLE lagene:

        //  Oppgave 2G:  Lag innmaten
}