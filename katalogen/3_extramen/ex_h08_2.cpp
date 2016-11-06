//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H08_2.CPP

//  Lõsningsforslag til eksamen i C++, 2.desember 2008, oppgave 2.
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

Dyr::Dyr()  {                //  OPPGAVE 2A - Initierer ALLE datamedlemmer:
  int i, j;
  strcpy(navn, "");  strcpy(art, "");      //  Initierer til "tomt".
  for (i = 0;  i < ANTDAGER;  i++)         //  Nullstiller hele matrisen:
      for (j = 0;  j < ANTTIMER;  j++)
          obs[i][j] = 0;
}


void Dyr::lese()  {          //  OPPGAVE 2A - Leser tekstlige datamedlemmer:
  les("Navn", navn, STRLEN);
  les("Art ", art, STRLEN);
}


void Dyr::skriv()  {         //  OPPGAVE 2B - Skriver ALT om dyret til skjerm:
  int i, j;
  cout << '\n';  skriv_navn();  cout << '\t';  //  Skriver navn og art.
  for (j = 0;  j < ANTTIMER;  j++)             //  Skriver egen linje med
      cout << setw(3) << j;                    //    alle timene 0, 1, ..., 23.
  for (i = 0;  i < ANTDAGER;  i++)  {          //  For hver dag:
     cout << '\n' << DAGER[i] << "dag:";       //  Skriver 'xxxxdag'.
     for (j = 0;  j < ANTTIMER;  j++)          //  Skriver ALT EN dag:
         cout << setw(3) << obs[i][j];
  }
  cout << '\n';
}


void Dyr::skriv_navn()  {    //  OPPGAVE 2C - Skriver navn og art:
  cout << navn << " (" << art << ")\n";
}

                             //  OPPGAVE 2D - Teller opp antall observasjoner:
void Dyr::observert(int d, int t)  {
  if ((d >= 0  &&  d < ANTDAGER)  &&     //  Dag (0-6) og time(0-23) 
      (t >= 0  &&  t < ANTTIMER))        //     i rett intervall.
     obs[d][t]++;                        //  Teller opp med 1.
  else
    cout << "\n\n\tUkedags- og/eller dagnummer utenfor lovlig intervall!\n";
}

                             //  OPPGAVE 2E - Skriver ALT om dyret til fil:
void Dyr::skriv_til_fil(ostream* ut)  {
   int i, j;
   *ut << navn << '\n' << art << '\n';   //  Navn og art pÜ hver sin linje.
   for (i = 0;  i < ANTDAGER;  i++) {    //  For hver dag,
       for (j = 0;  j < ANTTIMER;  j++)  //    og hver time den dagen:
           *ut << ' ' << obs[i][j];      //  Skriver ant.observasjoner.
       *ut << '\n';
   }
}

                             //  OPPGAVE 2F - Leser ALT om dyret fra fil:
void Dyr::les_fra_fil(istream* inn, char nvn[])  {
   int i, j;
   strcpy(navn, nvn);                    //  Kopierer inn/over navnet.
  (*inn).getline(art, STRLEN);           //  Leser art.
  for (i = 0;  i < ANTDAGER;  i++)       //  Leser alle dagenes
      for (j = 0;  j < ANTTIMER;  j++)   //    og timenes
          *inn >> obs[i][j];             //    observasjoner.
  (*inn).ignore();                       //  Forkaster aller siste '\n'.
}

                             //  OPPGAVE 2G - Statistikk over hvor ofte dyrene
                             //         har blitt sett i et gitt tidsintervall:
void Dyr::statistikk(int st, int sl)  {
  int i, j, ant = 0;
  cout << '\n';  skriv_navn();           //  Skriver navn og art.
  for (i = 0;  i < ANTDAGER;  i++)       //  For hver ukedag,
      for (j = st;  j <= sl;  j++)       //    og for tidsintervallet:
          ant += obs[i][j];              //  Teller opp ant.observasjoner.
  cout << "\t(" << ant << " ganger)\n";  //  Skriver resultatet av opptellingen.
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


void nytt_dyr()  {           //  OPPGAVE 2A - Legger inn (om mulig) ETT nytt dyr:
  if (siste_dyr < MAXDYR)  {             //  Plass til flere dyr:
     dyrene[++siste_dyr].lese();         //  Tar i bruk nytt. Leser selv data.
  } else
    cout << "\n\n\tFullt med " << MAXDYR << " dyr i datastrukturen allerede!\n";
}


void display_dyr()  {        //  OPPGAVE 2B - Skriver ALT om ETT dyr:
                                              //  Leser dyrets nummer/indeks:
  dyrene[les("Nr", 1, siste_dyr)].skriv();    //  Skriver seg selv til skjerm.
}


void meny_av_alle()  {       //  OPPGAVE 2C - Skriver meny av/for ALLE dyrene:
  int i;
  for (i = 1;  i <= siste_dyr;  i++)  {   //  For hvert dyr:
      cout << setw(2) << i << ":\t";      //  Skriver dets indeks/nummer,
      dyrene[i].skriv_navn();             //    samt navn og art.
  }
}


void observasjon()  {        //  OPPGAVE 2D - EN observasjon av et GITT dyr:
  int n;
  Dag_Time dt;                            //  Dag_Time-objekt.

  cin >> n;  cin.ignore();                //  Leser dyrets indeks/nummer.
  if (n >= 1 &&  n <= siste_dyr)  {       //  Indeks/nummer er lovlig.
                                          //  Avleser systemets ukedag og time:
     dyrene[n].observert(dt.hent_dag(), dt.hent_time()); //  Obs. registreres.
  } else
    cout << "\n\n\tNummer utenfor intervallet 1-" << siste_dyr << " !\n";
}


void skriv_til_fil()  {      //  OPPGAVE 2E - Skriver ALT til fil:
  int i;
  ofstream utfil("OBS_DYR.DTA");          //  èpner aktuell fil.

  for (i = 1;  i <= siste_dyr;  i++)      //  GÜr gjennom ALLE dyrene:
      dyrene[i].skriv_til_fil(&utfil);    //  De skriver seg selv til fil.

}


void les_fra_fil()  {        //  OPPGAVE 2F - Leser ALT fra fil:
  char buffer[STRLEN];                   //  Fõrste tekst i en Dyr-post.
  ifstream innfil("OBS_DYR.DTA");
  
  if (innfil)  {                         //  Filen finnes:
     siste_dyr = 0;                      //  Nullstiller global variabel.
     innfil.getline(buffer, STRLEN);     //  Leser (om mulig) dyre(kalle)navn.
     while (!innfil.eof() &&  siste_dyr < MAXDYR)  {   // Ikke slutt, plass:
       dyrene[++siste_dyr].les_fra_fil(&innfil, buffer);  // Leser resten selv.
       innfil.getline(buffer, STRLEN);     //  Leser (om mulig) dyre(kalle)navn.
     }
  } else
    cout << "\n\n\tFant ikke filen 'OBS_DYR.DTA'\n";
}


void statistikk()  {         //  Oppgave 2G - Dyr i et visst tidsintervall:
  int i, start = les("Starttime", 0, ANTTIMER-1),       //  Leser fõrste og
         slutt = les("Sluttime ", start, ANTTIMER-1);   //    siste time.

  for (i = 1;  i <= siste_dyr;  i++)       //  GÜr gjennom ALLE dyrene:
      dyrene[i].statistikk(start, slutt);  //  De skriver selv statistikk.
}
