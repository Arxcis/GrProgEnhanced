
                             //  INCLUDE:
#include <iostream>              //  cin, cout
#include <fstream>               //  ifstream, ofstream
#include "timer.h"               //  For � avlese klokka p� datamaskinen.

using namespace std;

                             //  CONST:
const int NVN_LEN     = 30;      //  Max. lengde for ansattes navn.
const int ANT_DAGER   = 23;      //  Max. antall arbeidsdager i en m�ned.
const int ANT_ANSATTE = 5;       //  Eksakt antall ansatte.

                             //  STRUCT:
struct tid  {                    //  Struct for tidspunkt m/
  int time, min;                 //   time- og minuttangivelse.
};

struct ansatt  {                 //  Struct for en ansatt:
  char navn[NVN_LEN];            //  Vedkommendes navn
  tid  tider[ANT_DAGER][3];      //  0=kommer,  1=g�r,  2=dagens arb.tid.
  tid  total_arbtid;             //  Total arbeidstid for HELE m�neden.
};


                             //  DEKLARASJON AV FUNKSJONER:
void les_fra_fil();
void skriv_til_fil();
int  les_ansattnr();
void hent_tidspunkt(int& ti, int& mi);

                             //  GLOBALE VARIABLE:
int dagnr;                            //  N�v�rende arbeidsdag i m�neden.
ansatt alle_ansatte[ANT_ANSATTE+1];   //  Tidsdata om alle de ansatte.

//  OPPGAVE 3A:  Tegn datastrukturen


                             //  MAIN:
int main()  {
  int time, min, nr;             //  Avlest tidspunkt (time, min) og ansattnr.

  les_fra_fil();                 //  Leser datastrukturen fra fil.
  nr = les_ansattnr();           //  Leser et ansattnummer.
  while (nr != 9999)  {          //  S� lenge ikke skal avslutte:
    hent_tidspunkt(time, min);   //  Avleser tidspunkt p� datamaskinen.

// OPPGAVE 3B:
//   Oppdater ANKOMST- eller AVGANGSTIDSPUNKT og arb.tid (EN dag og TOTALT).

    nr = les_ansattnr();         //  Leser et nytt ansattnummer.
  }
  skriv_til_fil();               //  Skriver datastrukturen til fil.
  return 0;
}


                             //  DEFINISJON AV FUNKSJONER:
void les_fra_fil()  {            //  Leser hele datastrukturen fra fil:

//  OPPGAVE 3C
}


void skriv_til_fil()  {          //  Skriver hele datastrukturen til fil:

//  OPPGAVE 3D
}


int les_ansattnr()  {        //  Leser et LOVLIG ansattnummer:
  int num;
  do  {
    cout << "Ansattnummer (1-" << ANT_ANSATTE << "): ";
    cin >> num;              //  M� v�re i rett intervall eller "9999":
  } while ( num < 1  ||  (num > ANT_ANSATTE  &&  num != 9999) );
  return num;  
}

                             // Avleser n�v�rende tidspunkt (time og minutt).
void hent_tidspunkt(int& ti, int& mi)  { 
  Timer tid;
  int sek;
  tid.hent(ti, mi, sek);
}
