//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H13_2.TPL

//  Skjellettet/template for eksamen i C++, 3.desember 2013, oppgave 2.
//  Laget av Frode Haug, HiG, november 2013.

//  Programmet "Dyre Streets" som holder orden på Armani-butikker 
//  i ulike byer, og varekjøpene utført av Dir.Strays i disse.
  

                        //  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <cstring>               //  strcmp, strcpy, strlen
#include <cctype>                //  toupper
using namespace std;

                        //  CONST:
const int STRLEN     =     80;   //  Max. tekstlengde.
const int MAXBUTIKK  =    100;   //  Max. antall butikker.
const int MAXKJOP    =    200;   //  Max. antall kjøp i EN butikk.


class Butikk {         //  KLASSE:
  private:
    char by[STRLEN/2];           //  Byen butikken ligger i.
    char adr[STRLEN];            //  Gateadresse.
    int  aapneUke,               //  Åpnings- og stengetid - uka
         stengeUke,              //              (mandag-fredag)
         aapneLordag,            //  Åpnings- og stengetid - lørdag.
         stengeLordag,
         antKjop;                //  Antall kjøp i butikken.
    int  kjopene[MAXKJOP+1];     //  Summene det er handlet for 
                                 //       (i hele norske kroner).
  public:                     //  Deklarasjon av medlemsfunksjoner:
    Butikk()              {  antKjop = 0;  }
    void skriv();                                //  Oppgave 2A
    void lesData(char b[]);                      //  Oppgave 2B
    void gjorKjop();                             //  Oppgave 2C
    void endreTider();                           //  Oppgave 2D
    int  kjopTotalt();                           //  Oppgave 2E
    void lesFraFil(ifstream & inn, char b[]);    //  Oppgave 2G
    bool erLik(char t[])  {  return (!strcmp(by, t));  }
};

                    //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
int  finnButikk(char t[]);
void skrivAlleButikker();        //  Oppgave 2A
void nyButikk();                 //  Oppgave 2B
void gjorKjopIButikk();          //  Oppgave 2C
void endreASTider();             //  Oppgave 2D
void storsteKjopene();           //  Oppgave 2F
void lesFraFil();                //  Oppgave 2G

                        //  GLOBALE VARIABLE:
Butikk butikkene[MAXBUTIKK+1];    //  Array med Butikk-objekter.
int sisteButikk;                  //  Indeks for siste Butikk hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   lesFraFil();                                     //  Oppgave 2G
   skrivMeny();
   kommando = les("Ønske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'A':  skrivAlleButikker();     break;   //  Oppgave 2A
       case 'N':  nyButikk();              break;   //  Oppgave 2B
       case 'K':  gjorKjopIButikk();       break;   //  Oppgave 2C
       case 'E':  endreASTider();          break;   //  Oppgave 2D
       case 'S':  storsteKjopene();        break;   //  Oppgave 2F
       default:   skrivMeny();             break;
     }
     kommando = les("Ønske");
   }
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************
                                
void Butikk::skriv()  {     //  Skriver ALLE data UNNTATT 'kjopene':             
        //  Oppgave 2A:  Lag innmaten
}

                     //  Kopierer inn og leser ALLE data UNNTATT 'kjopene':
void Butikk::lesData(char b[])  {  
        //  Oppgave 2B:  Lag innmaten
}



void Butikk::gjorKjop()  {   //  Gjør (om mulig) ETT kjøp i butikken:
        //  Oppgave 2C:  Lag innmaten
}


void Butikk::endreTider()  {  //  Endrer evt. åpnings- og/eller lukketid(er):
        //  Oppgave 2D:  Lag innmaten
}

                       // Beregner og returnerer totalsummen av ALLE kjøpene:       
int Butikk::kjopTotalt()  {     
        //  Oppgave 2E:  Lag innmaten
}

                                //  Leser alle egne data fra fil:
void Butikk::lesFraFil(ifstream & inn, char b[])  {  
        //  Oppgave 2G:  Lag innmaten
}



// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tA   = skriv Alle butikker\n";
  cout << "\tN   = Ny butikk\n";
  cout << "\tK   = gjør Kjøp i en butikk\n";
  cout << "\tE   = Endre åpnings- og/eller stengtid(er)\n";
  cout << "\tS   = butikkene med de (fem) Største kjøpene\n";
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

                              //  Ut fra en bys navn, så returneres dens indeks
int finnButikk(char t[])  {   //    i "butikkene", evt. '0' om ikke er å finne:
  for (int i = 1;  i <= sisteButikk;  i++) 
      if (butikkene[i].erLik(t))  return i;
  return 0;
}



void skrivAlleButikker()  {    //  Skriver data om ALLE butikkene:
        //  Oppgave 2A:  Lag innmaten
}


void nyButikk() {              //  Legger (om mulig) inn en ny butikk:
        //  Oppgave 2B:  Lag innmaten
}


void gjorKjopIButikk()  {     //  Gjør ett kjøp i en butikk:
        //  Oppgave 2C:  Lag innmaten
}


void endreASTider() {         //  Endre tider for EN butikk:
        //  Oppgave 2D:  Lag innmaten
}

                              //  Skriver butikkene der de (fem)
void storsteKjopene()  {      //    største totalkjøpene har forekommet:
        //  Oppgave 2F:  Lag innmaten
}


void lesFraFil()  {           //  Leser inn HELE datastrukturen:
        //  Oppgave 2G:  Lag innmaten
}
