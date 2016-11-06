//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S13_2.TPL

//  Skjellettet/template for kontinuasjonseksamen i C++, 16.august 2013, oppgave 2.
//  Laget av Frode Haug, HiG, juli 2013.

//  Program som holder orden pÜ personene i en sosial gruppe,
//  og pÜ hvilke dager disse evt. kan mõtes/treffes i en gitt mÜned.
  

                        //  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <cstring>               //  strcpy, strlen
#include <cctype>                //  toupper
using namespace std;

                        //  CONST:
const int STRLEN      =    60;   //  Max. tekstlengde.
const int MAXDELTAGER =    20;   //  Max. antall deltagere i gruppen.
const int MINDAG      =    28;   //  Min. antall dager i en mÜned.
const int MAXDAG      =    31;   //  Max. antall dager i en mÜned.


class Deltager {        //  KLASSE:
  private:
    char navn[STRLEN];            //  Deltagerens navn.
    char mail[STRLEN];            //  Mailadresse.
    int  tlf;                     //  Telefon (fast eller mobil).
    bool dag[MAXDAG+1];           //  Kan (ikke) pÜ dag nr.'i'.

  public:                         //  Deklarasjon av medlemsfunksjoner:
    Deltager()          {  nullstill();  }
    void lesData();                              //  Oppgave 2A
    void nullstill();                            //  Oppgave 2C
    void lesDager();                             //  Oppgave 2D
    bool kanDag(int d)  {  return (dag[d]);  }
    void lesFraFil(istream* inn, int t);         //  Oppgave 2F
};

                    //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
void nyDeltager();               //  Oppgave 2A
void fjernDeltager();            //  Oppgave 2B
void nullstillAlle();            //  Oppgave 2C
void lesDager();                 //  Oppgave 2D
void finnMoteDager();            //  Oppgave 2E
void lesFraFil();                //  Oppgave 2F

                        //  GLOBALE VARIABLE:
Deltager deltagere[MAXDELTAGER+1]; //  Array med Deltager-objekter.
int sisteBrukt,                    //  Indeks for siste Deltager hittil brukt.
    antDager;                      //  Antall dager i aktuell mÜned.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   lesFraFil();                                     //  Oppgave 2F
   skrivMeny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  nyDeltager();            break;   //  Oppgave 2A
       case 'F':  fjernDeltager();         break;   //  Oppgave 2B
       case 'U':  nullstillAlle();         break;   //  Oppgave 2C
       case 'L':  lesDager();              break;   //  Oppgave 2D
       case 'D':  finnMoteDager();         break;   //  Oppgave 2E
       default:   skrivMeny();             break;
     }
     kommando = les("ùnske");
   }
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Deltager::lesData()  {    //  Leser egne hoveddata:
        //  Oppgave 2A:  Lag innmaten
}


void Deltager::nullstill()  {  //  Nullstiller alle egne dager:
        //  Oppgave 2C:  Lag innmaten
}


void Deltager::lesDager()  {   //  Leser aktuelle egne mõtedager:
        //  Oppgave 2D:  Lag innmaten
}

                               //  Leser egne data fra fil:
void Deltager::lesFraFil(istream* inn, int t)  {
        //  Oppgave 2F:  Lag innmaten
}



// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN   = Ny deltager\n";
  cout << "\tF   = Fjern deltager\n";
  cout << "\tU   = nUllstill dagene for ALLE deltagerne\n";
  cout << "\tL   = Les dager for EN deltager\n";
  cout << "\tD   = finn felles Dager for aktuelle mõter/treff\n";
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


void nyDeltager()  {         //  Legger inn EN ny deltager:
        //  Oppgave 2A:  Lag innmaten
}


void fjernDeltager()  {      //  Fjerner EN deltager:
        //  Oppgave 2B:  Lag innmaten
}


void nullstillAlle()  {      //  Nullstiller ALLE deltagerne:
        //  Oppgave 2C:  Lag innmaten
}


void lesDager()  {           //  Leser EN deltagers mõtedager:
        //  Oppgave 2D:  Lag innmaten
}

                             
void finnMoteDager()  {      //  Finner dager der flest kan mõte:
        //  Oppgave 2E:  Lag innmaten
}


void lesFraFil()  {          //  Leser inn HELE datastrukturen:
        //  Oppgave 2F:  Lag innmaten
}
