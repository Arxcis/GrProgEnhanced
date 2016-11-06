
//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S10_2.CPP

//  Lõsningsforslag til kontinuasjonseksamen i C++, 13.august 2010, oppgave 2.
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
    void skriv_til_fil(ostream* ut);             //  Extra
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
    void skriv_til_fil(ostream* ut);             //  Extra
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
void skriv_til_fil();          //  Extra


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
       case 'T':  skriv_til_fil();    break;   //  Extra
       default:   skriv_meny();       break;
     }
     kommando = les("ùnske");
   }
  skriv_til_fil();                             //  Extra
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Havn::skriv_data()  {   //  Skriver ALLE objektets data til skjerm:
  cout << "\n\tHavnen '" << hnavn << "' ligger pÜ õya '" 
       << onavn << "' som har " << ant_innbyggere << " innbyggere.\n\n";
}


void Havn::les_data(const char t[])  {   //  Leser/setter alle objektets data:
  strcpy(hnavn, t);
  les("ùy-navn", onavn, STRLEN);
  ant_innbyggere = les("Antall innbyggere", 0, MAXINNBYG);
}


void Havn::les_fra_fil(istream* inn)  {   //  Leser objektets data fra fil:
  (*inn).getline(hnavn, STRLEN);
  (*inn).getline(onavn, STRLEN);
  *inn >> ant_innbyggere;  (*inn).ignore();
}


void Havn::skriv_til_fil(ostream* ut)  {  //  Skriver objektets data til fil:
  *ut << hnavn << '\n' << onavn << '\n' << ant_innbyggere << '\n';
}


// ---------------------------------------------------------------------------

void Rute::skriv_data()  {   //  Skriver alle objektets data til skjerm:
  cout << "\n\tBÜten '" << bnavn << "' gÜr innom havnene:\n\t\t";
  for (int i = 1;  i <= ant_stopp;  i++)  {   //  GÜr gjennom alle havnene:
      havner[ruten[i]].skriv_havn();          //  Skriver deres navn.
      if (i < ant_stopp) cout << ",  ";    // Komma-separerer (unntatt siste).
  }
  cout << '\n';
}


void Rute::les_data()  {     //  Leser ALLE objektets data fra tastaturet:
  int nr, i = 0;
  char navn[STRLEN];
  les("BÜtens navn", bnavn, STRLEN);                      //  Leser: BÜtnavn
  ant_stopp = les("Antall stoppesteder/havner", 1, MAXSTOPP);  //    Ant.havner
  while (i < ant_stopp)  {         //  EnnÜ ikke lest (korrekt) alle havn-navn:
    cout << "\t\tHavn nr." << i+1;
    les("", navn, STRLEN);              //  Leser aktuelt havn-navn.
    if ((nr = finn_havn(navn)) != 0)    //  Havnen finnes:
       ruten[++i] = nr;                 //  Legger dets indeks inn i ruten.
    else
       cout << "\t\t\tIngen havn med dette navnet. Prõv igjen.\n\n";
  }
}


bool Rute::stanser(int n)  {     //  Er ruten/bÜten innom havn nr.'n'?
  for (int i = 1;  i <= ant_stopp;  i++)  //  GÜr gjennom hele ruten:
      if (ruten[i] == n)  return true;    //  Treff!
  return false;                           //  Ikke funnet i arrayen.
}


void Rute::endre()  {            //  Legge inn (om mulig) en ny havn pÜ ruten:
  int n, nr, i;                  //  Indeksnr, havnenr og lõkkevariabel. 
  char navn[STRLEN];             //  Havnenavn.

  if (ant_stopp < MAXSTOPP)  {                  //  Plass til flere:
     skriv_data();                              //  Skriver nÜvërende rute.
     les("Ny havns navn", navn, STRLEN);        //  Leser aktuell havns navn.
     if ((nr = finn_havn(navn)) != 0)  {        //  Finner dets indeks.
        n = les("Dette skal vëre havn nr", 1, ++ant_stopp);  //  Ny inn hvor?
        for (i = ant_stopp;  i > n;  i--)       //  Flytter alle opp ETT hakk:
            ruten[i] = ruten[i-1];
        ruten[n] = nr;                          //  Smetter inn ny havn.
        skriv_data();                           //  Skriver ny rute.
     } else
       cout << "\t\tIngen havn med dette navnet!\n\n";
  } else
     cout << "\t\tIkke plass til flere stoppesteder/havner pÜ ruten!\n\n";
}


void Rute::les_fra_fil(istream* inn)  {    //  Leser objektets data fra fil:
  (*inn).getline(bnavn, STRLEN);               //  Leser: bÜtnavn.
  *inn >> ant_stopp;                           //         antall havner.
  for (int i = 1;  i <= ant_stopp;  i++)       //         alle havnenes indeks:
	  *inn >> ruten[i];
  (*inn).ignore();                             //         linjeskift.
}


void Rute::skriv_til_fil(ostream* ut)  {   //  Skriver objektets data til fil:
  *ut << bnavn << '\n' << ant_stopp;          // Skriver: bÜtnvn & ant.havner.
  for (int i = 1;  i <= ant_stopp;  i++)      //          alle havnenes indeks:
      *ut << ' ' << ruten[i];
  *ut << '\n';                                //          linjeskift.
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


int  finn_havn(const char t[])  {   // Finner (om mulig) en havns indeks:
  for (int i = 1;  i <= siste_havn;  i++)   //  GÜr gjennom alle havene:
      if (havner[i].er_lik(t)) return i;    //  Havn nr.'i' har navnet 't'.
  return 0;                                 //  Ingen treff/match.
}


void skriv_havn()  {          //  Oppgave 2A - Skriver/displayer en gitt havn:
  char navn[STRLEN];                        //  Havnenavn.
  int nr;                                   //  Havnens indeks.
  les("Se hvilken havn", navn, STRLEN);     //  Leser õnsket havnenavn.
  if ((nr = finn_havn(navn)) != 0)          //  Havnen finnes (har indeks):
     havner[nr].skriv_data();               //  Den skrives.     
  else
     cout << "\n\tIngen havn med dette navnet!\n\n";
}


void ny_havn()  {                //  Oppgave 2B - Legger inn ny havn:
  char navn[STRLEN];                        //  Havnenavn.
  if (siste_havn < MAXHAVNER)  {            //  Plass til flere:
     les("Ny havns navn", navn, STRLEN);    //  Leser ny havns navn.
     if (!finn_havn(navn))                  //  Havnen finnes IKKE allerede:
        havner[++siste_havn].les_data(navn);  //  Ny opprettes og data leses.      
     else
        cout << "\n\tFinnes allerede en havn med dette navnet!\n\n";
  } else
     cout << "\n\tFullt med havner i datastrukturen!\n\n";
}


void skriv_rute()  {             //  Oppgave 2C - Skriver/displayer en rute:
                                     //  Et gitt rutenummer skrives/vises: 
  ruter[les("Se rute nr", 1, siste_rute)].skriv_data();
}


void ny_rute()  {                //  Oppgave 2D - Ny rute opprettes/lages:
  if (siste_rute < MAXRUTER)            //  Plass til flere ruter:
     ruter[++siste_rute].les_data();    //  Ny opprettes og data leses.
  else
     cout << "\n\tFullt med ruter i datastrukturen!\n\n";
}


void alle_innom_havn()  {  //  Oppgave 2E - Skriver alle ruter innom gitt havn:
  int i, nr;                            //  Lõkkevariabel og havneindeks.
  char navn[STRLEN];                    //  Havnenavn.
  les("Havns navn", navn, STRLEN);      //  Leser aktuelt havnenavn.
  if ((nr = finn_havn(navn)) != 0)  {   //  Finner havnens indeks:
     cout << "\n\tFõlgende rutenumre stanser i denne havnen:\n\t";
     for (i = 1;  i <= siste_rute;  i++)     //  Skriver alle rutenumre som er
         if (ruter[i].stanser(nr)) cout << '\t' << i;   //  innom havnen.
     cout << '\n';
  } else
    cout << "\n\tIngen havn med dette navnet!\n\n";
}


void nytt_stoppested()  {        //  Oppgave 2F - Legger inn ny havn pÜ rute.
                                     //  Et gitt rutenummer endres: 
  ruter[les("Endre rute nr", 1, siste_rute)].endre();
}


void les_fra_fil()  {       //  Oppgave 2G - Leser HELE datastrukturen fra fil:
  int i;
  ifstream innfil("RUTEHAVN.DTA");             //  èpner aktuell fil.

  innfil >> siste_havn;  innfil.ignore();      //  Skriver hvor mye brukt av
  for (i = 1;  i <= siste_havn; i++)           //    de to arrayene, samt ALLE
      havner[i].les_fra_fil(&innfil);          //    objektenes data i BEGGE
                                               //    arrayene:
  innfil >> siste_rute;  innfil.ignore();
  for (i = 1;  i <= siste_rute; i++)
      ruter[i].les_fra_fil(&innfil);
}


void skriv_til_fil()  {        //  Extra - Skriver HELE datastrukturen til fil:
  int i;
  ofstream utfil("RUTEHAVN.DT2");             //  èpner aktuell fil.

  utfil << siste_havn << '\n';
  for (i = 1;  i <= siste_havn;  i++)         //  GÜr gjennom ALLE havnene:
      havner[i].skriv_til_fil(&utfil);        //  De skriver seg selv til fil.

  utfil << siste_rute << '\n';
  for (i = 1;  i <= siste_rute;  i++)         //  GÜr gjennom ALLE rutene:
      ruter[i].skriv_til_fil(&utfil);         //  De skriver seg selv til fil.
}
