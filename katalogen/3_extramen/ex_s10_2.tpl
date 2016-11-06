
//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S10_2.TPL

//  Skjellettet/template for kontinuasjonseksamen i C++, 13.august 2010, oppgave 2.
//  Laget av Frode Haug, HiG, mai 2010.


//  Program som holder orden pÜ ulike havner/õyer, 
//  og hvilke bÜtruter som gÜr innom de ulike havnene/õyene.
  

                        //  INCLUDE:
#include <fstream>           //  ifstream, ofstream
#include <iostream>          //  cin, cout
#include <cstring>           //  strlen, strcpy, strcmp
#include <cctype>            //  toupper

using namespace std;

                        //  CONST:
const int STRLEN      =       40;   //  Max. tekstlengde.
const int MAXHAVNER   =      200;   //  Max. antall stoppesteder/havner.
const int MAXRUTER    =       50;   //  Max. antall bÜtruter.
const int MAXSTOPP    =       10;   //  Max. antall havner EN rute er innom.
const int MAXINNBYG   = 10000000;   //  Max. antall innbyggere (10 millioner).


class Havn {              //  KLASSER:
  private:
    char hnavn[STRLEN];      //  Havnens navn.
    char onavn[STRLEN];      //  ùyas navn.
    int  ant_innbyggere;     //  Antall innbyggere pÜ õya.

  public:                    //  Definisjon/deklarasjon av medlemsfunksjoner:
    void skriv_data();                           //  Oppgave 2A
    void skriv_havn()  {  cout << hnavn;  }      //  Brukes i oppgave 2C
    void les_data(const char t[]);               //  Oppgave 2B
    bool er_lik(const char t[])  {  return (!strcmp(hnavn, t));  }
    void les_fra_fil(istream* inn);              //  Oppgave 2G
};


class Rute {
  private:
    char bnavn[STRLEN];      //  BÜtens navn.
    int  ant_stopp;          //  Antall stoppesteder/havner ruten er innom.
    int  ruten[MAXSTOPP+1];  //  Indeksen (i "havner") for stoppestedene. 

  public:                    //  Definisjon/deklarasjon av medlemsfunksjoner:
    Rute()  { ant_stopp = 0; }
    void skriv_data();                           //  Oppgave 2C
    void les_data();                             //  Oppgave 2D
    bool stanser(int n);                         //  Brukes i oppgave 2E
    void endre();                                //  Oppgave 2F
    void les_fra_fil(istream* inn);              //  Oppgave 2G
};

                    //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les(char t[]);
void les(const char t[], char s[], const int LEN);
int  les(const char t[], const int min, const int max);
int  finn_havn(const char t[]);

void skriv_havn();             //  Oppgave 2A
void ny_havn();                //  Oppgave 2B
void skriv_rute();             //  Oppgave 2C
void ny_rute();                //  Oppgave 2D
void alle_innom_havn();        //  Oppgave 2E
void nytt_stoppested();        //  Oppgave 2F
void les_fra_fil();            //  Oppgave 2G


                        //  GLOBALE VARIABLE:
Havn havner[MAXHAVNER+1];           //  Array med Havn-objekter.
Rute ruter[MAXRUTER+1];             //  Array med Rute-objekter.
int  siste_havn;                    //  Indeks for siste Havn hittil brukt.
int  siste_rute;                    //  Indeks for siste Rute hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   les_fra_fil();                              //  Oppgave 2G
   skriv_meny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'H':  skriv_havn();       break;   //  Oppgave 2A
       case 'N':  ny_havn();          break;   //  Oppgave 2B
       case 'S':  skriv_rute();       break;   //  Oppgave 2C
       case 'R':  ny_rute();          break;   //  Oppgave 2D
       case 'A':  alle_innom_havn();  break;   //  Oppgave 2E
       case 'E':  nytt_stoppested();  break;   //  Oppgave 2F
       default:   skriv_meny();       break;
     }
     kommando = les("ùnske");
   }
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Havn::skriv_data()  {   //  Skriver ALLE objektets data til skjerm:
        //  Oppgave 2A:  Lag innmaten
}


void Havn::les_data(const char t[])  {   //  Leser/setter alle objektets data:
        //  Oppgave 2B:  Lag innmaten
}


void Havn::les_fra_fil(istream* inn)  {   //  Leser objektets data fra fil:
        //  Oppgave 2G:  Lag innmaten
}


// ---------------------------------------------------------------------------

void Rute::skriv_data()  {   //  Skriver alle objektets data til skjerm:
        //  Oppgave 2C:  Lag innmaten
}


void Rute::les_data()  {     //  Leser ALLE objektets data fra tastaturet:
        //  Oppgave 2D:  Lag innmaten
}


bool Rute::stanser(int n)  {     //  Er ruten/bÜten innom havn nr.'n'?
  for (int i = 1;  i <= ant_stopp;  i++)  //  GÜr gjennom hele ruten:
      if (ruten[i] == n)  return true;    //  Treff!
  return false;                           //  Ikke funnet i arrayen.
}


void Rute::endre()  {            //  Legge inn (om mulig) en ny havn pÜ ruten:
        //  Oppgave 2F:  Lag innmaten
}


void Rute::les_fra_fil(istream* inn)  {    //  Leser objektets data fra fil:
        //  Oppgave 2G:  Lag innmaten
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tH   = skriv en Havn/õy\n";
  cout << "\tN   = Ny havn\n";
  cout << "\tS   = Skriv en rute\n";
  cout << "\tR   = ny Rute\n";
  cout << "\tA   = Alle ruter som gÜr innom en gitt havn/õy\n";
  cout << "\tE   = nytt stoppested (havn) for en Eksisterende rute\n";
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


int  finn_havn(const char t[])  {   // Finner (om mulig) en havns indeks:
  for (int i = 1;  i <= siste_havn;  i++)   //  GÜr gjennom alle havene:
      if (havner[i].er_lik(t)) return i;    //  Havn nr.'i' har navnet 't'.
  return 0;                                 //  Ingen treff/match.
}


void skriv_havn()  {             //  Skriver/displayer en gitt havn:
        //  Oppgave 2A:  Lag innmaten
}


void ny_havn()  {                //  Legger inn ny havn:
        //  Oppgave 2B:  Lag innmaten
}


void skriv_rute()  {             //  Skriver/displayer en rute:
        //  Oppgave 2C:  Lag innmaten
}


void ny_rute()  {                //  Ny rute opprettes/lages:
        //  Oppgave 2D:  Lag innmaten
}


void alle_innom_havn()  {        //  Sriver alle ruter innom gitt havn:
        //  Oppgave 2E:  Lag innmaten
}


void nytt_stoppested()  {        //  Legger inn ny havn pÜ rute.
        //  Oppgave 2F:  Lag innmaten
}


void les_fra_fil()  {            //  Leser HELE datastrukturen fra fil:
        //  Oppgave 2G:  Lag innmaten
}
