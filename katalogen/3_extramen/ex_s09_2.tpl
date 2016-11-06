//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S09_2.CPP

//  Skjellettet/template for kontinuasjonseksamen i C++, 14.august 2009, oppgave 2.
//  Laget av Frode Haug, HiG, mai 2009.

//  Program som holder orden pÜ status for utleie av sykler for ETT
//     firma med tre ulike utleiesteder.
  

                        //  INCLUDE:
#include <fstream>           //  ifstream, ofstream
#include <iostream>          //  cin, cout
#include <iomanip>           //  setw
#include <cstring>           //  strcpy, strlen
#include <cctype>            //  toupper
using namespace std;

                        //  CONST og ENUM:
const int  STRLEN     =       40;   //  Max. tekstlengde.
const int  MAXSYKLER  =      100;   //  Max. antall sykler til utleie.
const int  MINDAG     =      100;   //  Min. dagnummer i Üret (i april).
const int  MAXDAG     =      300;   //  Max. dagnummer i Üret (i oktober).
const int  MINTLF     = 10000000;   //  Min. telefonnummer.
const int  MAXTLF     = 99999999;   //  Max. telefonnummer.
enum  Sted { Haugastol, Finse, Flaam  };   //  Steder med sykkelutleie.


class Sykkel  {         //  KLASSER:
  private:
    char navn[STRLEN];             //  Leiers navn.
    int  tlf;                      //  Leiers kontaktinfo - kun (mobil)telefon.
    int  dagnr;                    //  Dagnummeret i Üret sykkelen ble leiet.
    bool ledig;                    //  Sykkelen ledig eller ei.
    Sted sted;                     //  Stedet sykkelen ble leiet/befinner seg.

  public:                    //  Definisjon/deklarasjon av medlemsfunksjoner:
    Sykkel();                               //  Oppgave 2A
    bool er_ledig()   {  return ledig;  }
    Sted hent_sted()  {  return sted;   }
    void skriv_sted();                      //  Oppgave 2A
    void skriv(int n);                      //  Oppgave 2C
    void utlever();                         //  Oppgave 2D
    void innlever();                        //  Oppgave 2E
    void skriv_til_fil(ostream* ut);        //  Oppgave 2F
    void les_fra_fil(istream* inn);         //  Oppgave 2G
};

                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les(char t[]);
void les(const char t[], char s[], const int LEN);
int  les(const char t[], const int min, const int max);

Sted les_sted();             //  Oppgave 2B
int  finn_ledig(Sted h);     //  Oppgave 2B
void skriv_alle();           //  Oppgave 2C
void utlevering();           //  Oppgave 2D
void innlevering();          //  Oppgave 2E
void skriv_til_fil();        //  Oppgave 2F
void les_fra_fil();          //  Oppgave 2G


                        //  GLOBALE VARIABLE:
Sykkel syklene[MAXSYKLER+1]; //  Sykkel-objekter (bruker indeks 1-100).
int dagnummer;               //  Innevërende dags nummer i Üret.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   les_fra_fil();                             //  Oppgave 2G
   dagnummer = les("Dagens dagnummer i Üret", MINDAG, MAXDAG);

   skriv_meny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'U':  utlevering();     break;    //  Oppgave 2D
       case 'I':  innlevering();    break;    //  Oppgave 2E
       case 'S':  skriv_alle();     break;    //  Oppgave 2C
       case 'T':  skriv_til_fil();  break;    //  Oppgave 2F
       default:   skriv_meny();     break;
     }
     kommando = les("ùnske");
   }
  skriv_til_fil();                            //  Oppgave 2F
  cout << "\n\n";
  return 0;
}


// *******************   DEFINISJON AV KLASSE-FUNKSJONER:  *******************

Sykkel::Sykkel()  {             //  OPPGAVE 2A - Initierer ALLE datamedlemmer:
//  Lag innmat
}


void Sykkel::skriv_sted()  {      //  OPPGAVE 2A - Enum-verdi ut som tekst:
//  Lag innmat
}


void Sykkel::skriv(int n)  {      //  OPPGAVE 2C - ALLE data (til skjerm):
//  Lag innmat
}


void Sykkel::utlever()  {         //  OPPGAVE 2D - Data settes nÜr leies:
//  Lag innmat
}


void Sykkel::innlever()  {        //  OPPGAVE 2E - Skriver info, resetter data:
//  Lag innmat
}

                             //  OPPGAVE 2F - Skriver ALT om sykkelen til fil:
void Sykkel::skriv_til_fil(ostream* ut)  {
//  Lag innmat
}

                             //  OPPGAVE 2G - Leser ALT om sykkelen fra fil:
void Sykkel::les_fra_fil(istream* inn)  {
//  Lag innmat
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tU   = Utleie/Utlevering av sykkel\n";
  cout << "\tI   = Innlevering av sykkel\n";
  cout << "\tS   = Skriv alle syklene\n";
  cout << "\tT   = skriv Til fil\n";
  cout << "\tQ   = Quit/avslutt\n";
}


char les(char t[])  {        //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << '\n' << t << ":  ";   //  Skriver medsendt ledetekst.
  cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
  return (toupper(ch));         //  Upcaser og returnerer.
}

                             //  Leser inn en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {  
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, LEN);          //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}

                             // Leser et tall i et visst intervall:
int les(const char t[], const int min, const int max)  { 
  int n;
  do  {                                  // Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;   cin.ignore();            // Leser inn ett tall.
  } while(n < min  ||  n > max);         // Sjekker at i lovlig intervall.
  return n;                              // Returnerer innlest tall.
}


Sted les_sted()  {           //  OPPGAVE 2B - Finner/leser "enumverdi":
//  Lag innmat
}


int finn_ledig(Sted h)  {   // OPPGAVE 2B - Indeks (om mulig) til ledig sykkel:
//  Lag innmat
}


void skriv_alle()  {         //  OPPGAVE 2C -Skriver ALT om ALLE syklene:
//  Lag innmat
}


void utlevering()  {         //  OPPGAVE 2D - Utlever en sykkel et sted:
//  Lag innmat
}


void innlevering()  {        //  OPPGAVE 2E - Innlever en sykkel ett sted:
//  Lag innmat
}


void skriv_til_fil()  {      //  OPPGAVE 2F - Skriver ALT til fil:
//  Lag innmat
}


void les_fra_fil()  {        //  OPPGAVE 2G - Leser ALT fra fil:
//  Lag innmat
}
