//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H08_2.TPL

//  Skjellettet/template for eksamen i C++, 2.desember 2008, oppgave 2.
//  Laget av Frode Haug, HiG, november 2008.

//  Program som holder orden pÜ/teller opp nÜr ulike dyr har
//    vërt Ü se pÜ/foran web-kamera i lõpet av en uke.
  

                        //  INCLUDE:
#include <fstream>           //  ifstream, ofstream
#include <iostream>          //  cin, cout
#include <iomanip>           //  setw
#include <cstring>           //  strcpy, strlen
#include <cctype>            //  toupper
#include "dag_time.h"        //  Funksjoner for avlesing av ukedag og dõgntime

using namespace std;

                        //  CONST:          Ukedagene:
const char DAGER[][5] = { " Sõn", " Man", "Tirs", " Ons", "Tors", " Fre", " Lõr" };
const int  STRLEN      =     40;   //  Max. tekstlengde.
const int  MAXDYR      =     30;   //  Max. antall dyr Ü observere.
const int  ANTDAGER    =      7;   //  Antall dager (en uke) Ü observere.
const int  ANTTIMER    =     24;   //  Antall timer i et dõgn.


class Dyr  {            //  KLASSER:
  private:
    char navn[STRLEN];             //  (Kalle)navn.
    char art[STRLEN];              //  Dyreart.
    int  obs[ANTDAGER][ANTTIMER];  //  Matrise av en ukes observasjoner - 24/7.

  public:                    //  Definisjon/deklarasjon av medlemsfunksjoner:
    Dyr();                                       //  Oppgave 2A
    void lese();                                 //  Oppgave 2A
    void skriv();                                //  Oppgave 2B
    void skriv_navn();                           //  Oppgave 2C
    void observert(int d, int t);                //  Oppgave 2D
    void skriv_til_fil(ostream* ut);             //  Oppgave 2E
    void les_fra_fil(istream* inn, char nvn[]);  //  Oppgave 2F
    void statistikk(int st, int sl);             //  Oppgave 2G
};

                    //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les(char t[]);
void les(const char t[], char s[], const int LEN);
int  les(const char t[], const int min, const int max);

void nytt_dyr();             //  Oppgave 2A
void display_dyr();          //  Oppgave 2B
void meny_av_alle();         //  Oppgave 2C
void observasjon();          //  Oppgave 2D
void skriv_til_fil();        //  Oppgave 2E
void les_fra_fil();          //  Oppgave 2F
void statistikk();           //  Oppgave 2G

                        //  GLOBALE VARIABLE:
Dyr dyrene[MAXDYR+1];        //  Array med Dyr-objekter.
int siste_dyr;               //  Indeks for siste dyr hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   les_fra_fil();                             //  Oppgave 2F
   skriv_meny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  nytt_dyr();       break;    //  Oppgave 2A
       case 'D':  display_dyr();    break;    //  Oppgave 2B
       case 'M':  meny_av_alle();   break;    //  Oppgave 2C
       case 'O':  observasjon();    break;    //  Oppgave 2D
       case 'S':  statistikk();     break;    //  Oppgave 2G
       case 'T':  skriv_til_fil();  break;    //  Oppgave 2E
       default:   skriv_meny();     break;
     }
     kommando = les("ùnske");
   }
  skriv_til_fil();                            //  Oppgave 2E
  cout << "\n\n";
  return 0;
}


//  **********************   DEFINISJON AV KLASSE-FUNKSJONER:  **********************   

Dyr::Dyr()  {                //  Initierer ALLE datamedlemmer:
        //  Oppgave 2A:  Lag innmaten   
}


void Dyr::lese()  {          //  Leser tekstlige datamedlemmer:
        //  Oppgave 2A:  Lag innmaten   
}


void Dyr::skriv()  {         //  Skriver ALT om dyret til skjerm:
        //  Oppgave 2B:  Lag innmaten   
}


void Dyr::skriv_navn()  {    //  Skriver navn og art:
        //  Oppgave 2C:  Lag innmaten   
}

                             //  Teller opp antall observasjoner:
void Dyr::observert(int d, int t)  {
        //  Oppgave 2D:  Lag innmaten   
}

                             //  Skriver ALT om dyret til fil:
void Dyr::skriv_til_fil(ostream* ut)  {
        //  Oppgave 2E:  Lag innmaten   
}

                             //  Leser ALT om dyret fra fil:
void Dyr::les_fra_fil(istream* inn, char nvn[])  {
        //  Oppgave 2F:  Lag innmaten   
}

                             //  Statistikk over hvor ofte dyrene
                             //         har blitt sett i et gitt tidsintervall:
void Dyr::statistikk(int st, int sl)  {
        //  Oppgave 2G:  Lag innmaten   
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN   = Nytt dyr\n";
  cout << "\tD   = Display/skriv ALLE data om ETT dyr\n";
  cout << "\tM   = Meny med ALLE dyrene som skal observeres\n";
  cout << "\tO n = en Observasjon av dyr nr.'n'\n";
  cout << "\tS   = Statistikk over dyr i et visst tidsintervall\n";
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


void nytt_dyr()  {           //  Legger inn (om mulig) ETT nytt dyr:
        //  Oppgave 2A:  Lag innmaten   
}


void display_dyr()  {        //  Skriver ALT om ETT dyr:
        //  Oppgave 2B:  Lag innmaten   
}


void meny_av_alle()  {       //  Skriver meny av/for ALLE dyrene:
        //  Oppgave 2C:  Lag innmaten   
}


void observasjon()  {        //  EN observasjon av et GITT dyr:
        //  Oppgave 2D:  Lag innmaten   
}


void skriv_til_fil()  {      //  Skriver ALT til fil:
        //  Oppgave 2E:  Lag innmaten   
}

void les_fra_fil()  {        //  Leser ALT fra fil:
        //  Oppgave 2F:  Lag innmaten   
}


void statistikk()  {         //  Dyr i et visst tidsintervall:
        //  Oppgave 2G:  Lag innmaten   
}
