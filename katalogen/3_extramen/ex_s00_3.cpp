//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S00_3.CPP

//  Lõsningsforslag til eksamen i C++, 16.august 2000, oppgave 3.
//  Laget av Frode Haug, HiG, juli 2000.


//  Programmet holder orden pÜ ulike personers arbeidstid
//  (pr.dag og totalt) for siste/innevërende mÜned.
//
//  NB: Avsluttes vha. det "hemmelige" ansattnummeret "9999".


                             //  INCLUDE:
#include <iostream>              //  cin, cout
#include <fstream>               //  ifstream, ofstream
#include "timer.h"               //  For Ü avlese klokka pÜ datamaskinen.

using namespace std;

                             //  CONST:
const int NVN_LEN     = 30;      //  Max. lengde for ansattes navn.
const int ANT_DAGER   = 23;      //  Max. antall arbeidsdager i en mÜned.
const int ANT_ANSATTE = 5;       //  Eksakt antall ansatte.

                             //  STRUCT:
struct tid  {                    //  Struct for tidspunkt m/
  int time, min;                 //   time- og minuttangivelse.
};

struct ansatt  {                 //  Struct for en ansatt:
  char navn[NVN_LEN];            //  Vedkommendes navn
  tid  tider[ANT_DAGER][3];      //  0=kommer,  1=gÜr,  2=dagens arb.tid.
  tid  total_arbtid;             //  Total arbeidstid for HELE mÜneden.
};


                             //  DEKLARASJON AV FUNKSJONER:
void les_fra_fil();
void skriv_til_fil();
int  les_ansattnr();
void hent_tidspunkt(int& ti, int& mi);

                             //  GLOBALE VARIABLE:
int dagnr;                            //  NÜvërende arbeidsdag i mÜneden.
ansatt alle_ansatte[ANT_ANSATTE+1];   //  Tidsdata om alle de ansatte.


                             //  MAIN:
int main()  {
  int time, min, nr,             //  Avlest tidspunkt (time, min) og ansattnr.
      t1, t2, m1, m2, tot1, tot2, arb, totarb;   //  Div. hjelpevarible for Ü
                                                 //    fÜ kortere regneuttrykk.
  les_fra_fil();                 //  Leser datastrukturen fra fil.
  nr = les_ansattnr();           //  Leser et ansattnummer.
  while (nr != 9999)  {          //  SÜ lenge ikke skal avslutte:
    hent_tidspunkt(time, min);   //  Avleser tidspunkt pÜ datamaskinen.

                                 //  OPPGAVE 3B:

    if (alle_ansatte[nr].tider[dagnr][0].time == 0) { // KOMMER til arb.plassen:
       alle_ansatte[nr].tider[dagnr][0].time = time;  // Lagrer unna ankomst-
       alle_ansatte[nr].tider[dagnr][0].min  = min;   //   tidspunktet.
       cout << "\n\tKOMMER !\n\n";
    } else  {                                         // GèR fra arb.plassen:
       alle_ansatte[nr].tider[dagnr][1].time = time;  // Lagrer unna avgangs- 
       alle_ansatte[nr].tider[dagnr][1].min  = min;   //   tidspunktet.
       t1 = alle_ansatte[nr].tider[dagnr][0].time;    // Henter ankomst-
       m1 = alle_ansatte[nr].tider[dagnr][0].min;     //   tidspunket.
       t2 = time;  m2 = min;     // Avgang-tidspunkt kopieres til hjelpevariable.
       tot1 = t1*60 + m1;        // Beregner totalt antall min. siden midnatt
       tot2 = t2*60 + m2;        //   nÜr ankom til og nÜr gikk fra arb.plassen.
       arb = tot2 - tot1;        // Beregner total lengde pÜ arb.dagen (i min).
       alle_ansatte[nr].tider[dagnr][2].time = arb / 60;  // Lagrer unna som 
       alle_ansatte[nr].tider[dagnr][2].min  = arb % 60;  //  timer og minutter.
       cout << "\n\tGèR!\tArbeidstid idag:\t"             // Skriver dette til
            << arb/60 << ':' << arb%60 << "\n";           //  skjermen.

       totarb = alle_ansatte[nr].total_arbtid.time*60 +   // Beregner TOTALT ant.
                alle_ansatte[nr].total_arbtid.min +       //  minutter arbeidet.
                arb;
       alle_ansatte[nr].total_arbtid.time = totarb / 60;  // Lagrer unna som
       alle_ansatte[nr].total_arbtid.min  = totarb % 60;  //  timer og minutter.
       cout << "\n\t\tArbeidstid totalt:\t"               // Skriver dette til
            << totarb/60 << ':' << totarb%60 << "\n\n";   //  skjermen ogsÜ.
    }
    nr = les_ansattnr();         //  Leser et nytt ansattnummer.
  }
//  skriv_til_fil();               //  Skriver datastrukturen til fil.
  return 0;
}


                             //  DEFINISJON AV FUNKSJONER:
                                 //  OPPGAVE 3C:
void les_fra_fil()  {            //  Leser hele datastrukturen fra fil:
  ifstream innfil("ARBTID.DTA"); //  èpner aktuell fil.
  int i, j;                      //  Lõkkevarible.

  if (innfil)  {                 //  Filen finnes:
     innfil >> dagnr;            //  Leser neste dagnummer som skal behandles.
     if (dagnr < ANT_DAGER)  {         //  Plass til Ü lese inn flere dager:
        for (i = 1;  i <= ANT_ANSATTE;  i++)  {   //  Leser inn om ALLE ansatte:
            innfil.ignore();                      //  Skipper blank (etter tall).
                                                  //  Leser ansattes navn:
            innfil.getline(alle_ansatte[i].navn, NVN_LEN);
            for (j = 0;  j < dagnr;  j++)         //  Leser vedkommendes tider:
                innfil >> alle_ansatte[i].tider[j][0].time  //  Ankomst:
                       >> alle_ansatte[i].tider[j][0].min
                       >> alle_ansatte[i].tider[j][1].time  //  Avgang:
                       >> alle_ansatte[i].tider[j][1].min
                       >> alle_ansatte[i].tider[j][2].time  //  Arb.tid EN dag:
                       >> alle_ansatte[i].tider[j][2].min;
            if (dagnr > 0)
               innfil >> alle_ansatte[i].total_arbtid.time  //  TOTAL arb.tid:
                      >> alle_ansatte[i].total_arbtid.min;
        }
     } else                               //  Har lest inn alle dagene allerede:
       cout << "\n\nFULLT!  Alle dagene denne mÜneden er allerede lest inn!";
  } else                         //  Filen finnes ikke:
    cout << "\n\nFinner ikke filen 'ARBTID.DTA' !";
}


void skriv_til_fil()  {          //  Skriver hele datastrukturen til fil:
                                 //  OPPGAVE 3D:
  ofstream utfil("ARBTID.DTA");  //  èpner aktuell fil.
  int i, j;                      //  Lõkkevarible.

  utfil << ++dagnr << '\n';      //  Leser NESTE dagnummer som skal behandles.
  for (i = 1;  i <= ANT_ANSATTE;  i++)  {         // Skriver ut om ALLE ansatte:
      utfil << alle_ansatte[i].navn << '\n';      // Skriver ansattes navn.
      for (j = 0;  j < dagnr;  j++)               // For alle innleste dager:
          utfil <<  alle_ansatte[i].tider[j][0].time << '\t'  // Ankomst:
                <<  alle_ansatte[i].tider[j][0].min  << '\t'
                <<  alle_ansatte[i].tider[j][1].time << '\t'  // Avgang:
                <<  alle_ansatte[i].tider[j][1].min  << '\t'
                <<  alle_ansatte[i].tider[j][2].time << '\t'  // Arb.tid EN dag:
                <<  alle_ansatte[i].tider[j][2].min  << '\n';
      utfil <<  alle_ansatte[i].total_arbtid.time << '\t'     // TOTAL arb.tid:
            <<  alle_ansatte[i].total_arbtid.min  << '\n';
  }
}


int les_ansattnr()  {        //  Leser et LOVLIG ansattnummer:
  int num;
  do  {
    cout << "Ansattnummer (1-" << ANT_ANSATTE << "): ";
    cin >> num;              //  Mè vëre i rett intervall eller "9999":
  } while ( num < 1  ||  (num > ANT_ANSATTE  &&  num != 9999) );
  return num;  
}

                             // Avleser nÜvërende tidspunkt (time og minutt).
void hent_tidspunkt(int& ti, int& mi)  { 
  Timer tid;
  int sek;
  tid.hent(ti, mi, sek);
}
