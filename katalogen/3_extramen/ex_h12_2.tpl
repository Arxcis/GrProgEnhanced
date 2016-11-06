//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H12_2.TPL

//  Skjellettet/template for eksamen i C++, 4.desember 2012, oppgave 2.
//  Laget av Frode Haug, HiG, november 2012.

//  Program som holder orden p† en maskinkj›rers oppdrag (br›yting og str›ing)
//  hos ulike faste kunder i l›pet av en vintersesong.
  

                        //  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <cstring>               //  strcpy, strlen
#include <cctype>                //  toupper
using namespace std;

                        //  CONST:
const int STRLEN     =     80;   //  Max. tekstlengde.
const int MAXKUNDER  =    100;   //  Max. antall kunder.
const int MAXOPPDRAG =     50;   //  Max. antall oppdrag hos EN kunde.


class Kunde {         //  KLASSE:
  private:
    char navn[STRLEN/2];          //  Kundens navn.
    char adr[STRLEN];             //  Gateadresse.
    int  tlf;                     //  Telefon (fast eller mobil).
    int  antOppdrag;              //  Antall oppdrag (hittil) hos kunden.
    int  oppdrag[MAXOPPDRAG+1];   //  Datoene for oppdragene (p† formen: MMDD).

  public:                     //  Deklarasjon av medlemsfunksjoner:
    Kunde()         {  antOppdrag = 0;  }
    void lesData();                              //  Oppgave 2B
    void skriv();                                //  Oppgave 2C
    bool registrer(int d);                       //  Oppgave 2D
    void skriv2(int n);                          //  Oppgave 2F
    void lesFraFil(istream* inn, char nvn[]);    //  Oppgave 2G
    void skrivTilFil(ostream* ut);
};

                    //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
int  lesDato();                  //  Oppgave 2A
void nyKunde();                  //  Oppgave 2B og 2E
void skrivAlleKunder();          //  Oppgave 2C
void registrerOppdrag(int d);    //  Oppgave 2D
void skrivEnKunde();             //  Oppgave 2F
void lesFraFil();                //  Oppgave 2G
void skrivTilFil();

                        //  GLOBALE VARIABLE:
Kunde kunder[MAXKUNDER+1];       //  Array med Kunde-objekter.
int sisteBrukt;                  //  Indeks for siste Kunde hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   int dato;                     //  Dagens dato p† formen: MMDD.
   char kommando;

   lesFraFil();                                     //  Oppgave 2G
   dato = lesDato();
   skrivMeny();
   kommando = les("nske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  nyKunde();               break;   //  Oppgave 2B og 2E
       case 'A':  skrivAlleKunder();       break;   //  Oppgave 2C
       case 'R':  registrerOppdrag(dato);  break;   //  Oppgave 2D
       case 'S':  skrivEnKunde();          break;   //  Oppgave 2F
       case 'T':  skrivTilFil();           break;
       default:   skrivMeny();             break;
     }
     kommando = les("nske");
   }
  skrivTilFil();
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Kunde::lesData()  {           //  Leser alle kundens data:
        //  Oppgave 2B:  Lag innmaten
}


void Kunde::skriv()  {             //  Skriver kundens data:
        //  Oppgave 2C:  Lag innmaten
}


bool Kunde::registrer(int d)  {   //  Registrerer ETT nytt oppdrag:
        //  Oppgave 2D:  Lag innmaten
}


void Kunde::skriv2(int n)  {    // Skriver ALLE oppdrag eller kun EN gitt m†ned:
        //  Oppgave 2F:  Lag innmaten
}

                                   //  Leser kunden fra fil:
void Kunde::lesFraFil(istream* inn, char nvn[])  {   
        //  Oppgave 2G:  Lag innmaten
}


void Kunde::skrivTilFil(ostream* ut)  {       //  Skriver kunden til fil:
  *ut << navn << '\n' << adr << '\n' << tlf << ' ' << antOppdrag;
  for (int i = 1;  i <= antOppdrag;  i++)
      *ut << ' ' << oppdrag[i];
  *ut << '\n';
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN   = Ny kunde\n";
  cout << "\tA   = skriv Alle kunder\n";
  cout << "\tR   = Registrer oppdrag\n";
  cout << "\tS   = Skriv EN kunde\n";
  cout << "\tT   = skriv Til filer\n";
  cout << "\tQ   = Quit/avslutt\n";
}


char les(char t[])  {        //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << '\n' << t << ":  ";   //  Skriver medsendt ledetekst.
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
  } while (strlen(s) == 0);		//  Sjekker at tekstlengden er ulik 0.
}


int  lesDato()  {            //  Leser dag og m†ned. Returnerer p† formen MMDD:
        //  Oppgave 2A:  Lag innmaten
}

                            
void nyKunde()  {            //  Legger/smetter (om mulig) inn en ny kunde:
        //  Oppgave 2B og 2E:  Lag innmaten
}


void skrivAlleKunder()  {         //  Skriver data om ALLE kundene:
        //  Oppgave 2C:  Lag innmaten
}


void registrerOppdrag(int d)  {   //  Registrer oppdrag p† kunde(r):
        //  Oppgave 2D:  Lag innmaten
}


void skrivEnKunde()  {            //  Skriv (alt) om EN kunde:
        //  Oppgave 2F:  Lag innmaten
}


void lesFraFil()  {               //  Leser inn HELE datastrukturen:
        //  Oppgave 2G:  Lag innmaten
}


void skrivTilFil()  {             //  Skriver HELE datastrukturen til fil:
  ofstream utfil("VINTER.DTA");            //  pner aktuell fil.
  cout << "\n\nSkriver til filen 'VINTER.DTA' .....\n\n";
  for (int i = 1;  i <= sisteBrukt;  i++)  //  Alle kundene skriver seg selv:
      kunder[i].skrivTilFil(&utfil);
}
