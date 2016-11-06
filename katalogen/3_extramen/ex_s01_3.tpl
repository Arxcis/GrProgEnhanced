                             //  INCLUDE:
#include <iostream>              //  cin, cout
#include <fstream>               //  ifstream
#include <cstring>               //  strcmp, strlen
#include <iomanip>               //  setw

using namespace std;

                             //  CONST:
const int NVN_LEN     = 20;      //  Max. lengde for et lags navn.
const int MAX_LAG     = 30;      //  Max. antall lag p†/i tabellen.
const int SEIER       =  3;      //  Antall poeng for en seier.
const int UAVGJORT    =  1;      //  Antall poeng for en uavgjort.

                             //  STRUCT:
struct Lag  {                    //  Struct for et lag m/
  char navn[NVN_LEN];            //     dets navn,
  int ant_kamper,                //     antall kamper totalt spilt,
      ant_seire,                 //     antall seire,
      ant_uavgjort,              //     antall uavgjort,
      ant_tap,                   //     antall tap,
      ant_scoret,                //     antall m†l scoret,
      ant_innsluppet,            //     antall m†l innsluppet,
      ant_poeng;                 //     antall poeng totalt.
};

                             //  DEKLARASJON AV FUNKSJONER:
int  finn_lag(char nvn[]);
void les_fra_fil();
void skriv_tabell();
void sorter(int n);

                             //  GLOBALE VARIABLE:
int ant_lag;                     //  Antall lag/linjer i tabellen/p† filen.
Lag tabellen[MAX_LAG+1];         //  Tabellen med lagene.


                             //  HOVEDPROGRAMMET:
int main()  {
  char navn1[NVN_LEN], navn2[NVN_LEN];               //  De to lagenes navn.
  int maal1, maal2;                                  //  M†lene de har scoret.
  int nr1, nr2;                                      //  Deres nr. i tabellen.
  les_fra_fil();                                     //  Leser tabell fra fil.
  skriv_tabell();                                    //  Skriver til skjermen.

//  Oppgave 3e:  Lag resten av innmaten

  return 0;
}


                             //  DEFINISJON AV FUNKSJONER:

                                 //  Leter etter laget med navnet "nvn" i
int finn_lag(char nvn[])  {      //    arrayen "tabellen".

  //  Oppgave 3a:  Lag innmaten
}


void les_fra_fil()  {            //  Leser datastrukturen/tabellen fra fil:

  //  Oppgave 3b:  Lag innmaten
}


void skriv_tabell()  {           //  Skriver tabellen til skjermen.

  //  Oppgave 3c:  Lag innmaten
}

                                 //  Innstikkssorterer et lag (om mulig)
void sorter(int n)  {            //    h›yere opp p† tabellen.

  //  Oppgave 3d:  Lag innmaten
}
