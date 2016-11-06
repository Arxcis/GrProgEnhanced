//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S01_3.CPP

//  L›sningsforslag til eksamen i C++, 17.august 2001, oppgave 3.
//  Laget av Frode Haug, HiG, august 2001.


//  Programmet leser inn en lagspill-tabell fra fil. Leser deretter 
//  inn fortl›pende resultatet mellom to og to lag. Oppdaterer s†
//  lagenes data, sorterer tabellen og skriver den til skjermen/fil.


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
                             //  OPPGAVE E:
  cout << "\nHjemmelag (kun ENTER = avslutt):  ";    //  Leser (om mulig)
  cin.getline(navn1, NVN_LEN);                       //    hjemmelagets navn.
  while (strlen(navn1))  {                           //  Har funnet et navn:
    nr1 = finn_lag(navn1);                           //  Finnes i tabellen ?
    if (nr1)  {                                      //  Ja:
       cout << "Bortelag:  ";                        
       cin.getline(navn2, NVN_LEN);                  //  Leser bortelagets navn.
       nr2 = finn_lag(navn2);                        //  Finnes i tabellen ?
       if (nr2)  {                                   //  Ja:
                                                     //  Leser resultatet:
          cout << "M†l av " << navn1 << ":  ";  cin >> maal1;
          cout << "M†l av " << navn2 << ":  ";  cin >> maal2; cin.ignore();
          tabellen[nr1].ant_kamper++;                //  Oppdaterer lagenes
          tabellen[nr2].ant_kamper++;                //    ulike data:
          tabellen[nr1].ant_scoret += maal1;
          tabellen[nr1].ant_innsluppet += maal2;
          tabellen[nr2].ant_scoret += maal2;
          tabellen[nr2].ant_innsluppet += maal1;
          if (maal1 > maal2)  {                      //  Lag1 vant:
             tabellen[nr1].ant_seire++;              //    Teller opp seire,
             tabellen[nr1].ant_poeng += SEIER;       //      poeng og
             tabellen[nr2].ant_tap++;                //      tap.
             sorter(nr1);                            //    Lag1 avanserer ?
          } else if (maal2 > maal1)  {               //  Lag2 vant:
             tabellen[nr1].ant_tap++;                //    Teller opp tap,
             tabellen[nr2].ant_seire++;              //      seire og
             tabellen[nr2].ant_poeng += SEIER;       //      poeng.
             sorter(nr2);                            //    Lag2 avanserer ?
          } else {                                   //  Uavgjort:
             tabellen[nr1].ant_uavgjort++;           //    Teller opp uavgjort
             tabellen[nr1].ant_poeng += UAVGJORT;    //      og poeng for lag1:
             sorter(nr1);                            //    Laget avanserer ?
             nr2 = finn_lag(navn2);                  //    Finner plassen igjen
                                                     //      (for KAN ha flyttet
                                                     //      seg om lag1 avanserte).
             tabellen[nr2].ant_uavgjort++;           //    Teller opp uavgjort
             tabellen[nr2].ant_poeng += UAVGJORT;    //      og poeng for lag2:
             sorter(nr2);                            //    Laget avanserer ?
          }

          skriv_tabell();                            //  Skriver ny tabell.

       } else                                        //  Fant ikke bortelaget.
         cout << "\nFEIL: Laget '" << navn2 << "' finnes ikke i tabellen !\n";
    } else                                           //  Fant ikke hjemmelaget.
      cout << "\nFEIL: Laget '" << navn1 << "' finnes ikke i tabellen !\n";

    cout << "\nHjemmelag (kun ENTER = avslutt):  ";  //  Leser (om mulig)
    cin.getline(navn1, NVN_LEN);                     //    hjemmelagets navn.
  }
  return 0;
}


                             //  DEFINISJON AV FUNKSJONER:

                             //  OPPGAVE 3A:
                                 //  Leter etter laget med navnet "nvn" i
int finn_lag(char nvn[])  {      //    arrayen "tabellen".
  int len = strlen(nvn);         //  Finner antall aktuelle tegn † sammenligne.
  for (int i = 1;  i <= ant_lag;  i++)   //  G†r gjennom hele tabellen:
      if (!strncmp(tabellen[i].navn, nvn, len)) return i;  // Returnerer indeks.
  return 0;                      //  Ellers returneres 0 (null).
} 


                             //  OPPGAVE 3B:
void les_fra_fil()  {            //  Leser datastrukturen/tabellen fra fil:
  ifstream innfil("TABELL.DTA"); //  pner aktuell fil.
  int i;                         //  L›kkevaribel.

  if (innfil)  {                 //  Filen finnes:
     innfil >> ant_lag;          //  Leser inn antall lag p† filen/i tabellen.
     if (ant_lag <= MAX_LAG)  {                   //  Plass til alle lagene:
        for (i = 1;  i <= ant_lag;  i++)  {       //  Leser inn om ALLE lagene:
            innfil.ignore();               //  Skipper '\n' etter forrige tall.
            innfil.get(tabellen[i].navn, NVN_LEN);   //  Leser lagets navn,
                                           //    INKLUDERT avsluttende blanke !
            innfil >> tabellen[i].ant_kamper         //  Og alle andre data
                   >> tabellen[i].ant_seire          //    om laget p† den
                   >> tabellen[i].ant_uavgjort       //    samme linjen:
                   >> tabellen[i].ant_tap
                   >> tabellen[i].ant_scoret
                   >> tabellen[i].ant_innsluppet
                   >> tabellen[i].ant_poeng;
        }
     } else                      //  For mange lag p† filen:
       cout << "\n\nFEIL: Ikke plass til alle lagene i programmets array !\n";
  } else                         //  Filen finnes ikke:
    cout << "\n\nFEIL: Finner ikke filen 'TABELL.DTA' !\n";
}


                             //  OPPGAVE 3C:
void skriv_tabell()  {           //  Skriver tabellen til skjermen.
  cout << '\n'<< setw(22) << "K" << setw(4) << "S" << setw(3) << "U"
       << setw(3) << "T" << setw(12) << "P" << '\n';   //  Lager enkel heading.
  for (int i = 1;  i <= ant_lag;  i++)                 //  Skriver alle data om
      cout << tabellen[i].navn << setw(3)              //    alle lagene i faste
           << tabellen[i].ant_kamper << setw(4)        //    kolonner/posisjoner.
           << tabellen[i].ant_seire << setw(3)
           << tabellen[i].ant_uavgjort << setw(3)
           << tabellen[i].ant_tap << setw(5)
           << tabellen[i].ant_scoret << '-' << setw(2)
           << tabellen[i].ant_innsluppet << setw(4)
           << tabellen[i].ant_poeng << '\n';
}

                             //  OPPGAVE 3D:
                                 //  Innstikkssorterer et lag (om mulig)
void sorter(int n)  {            //    h›yere opp p† tabellen.
  Lag laget = tabellen[n];       //  "Gjemmer unna" laget som evnt. skal
                                 //    smettes inn h›yere opp i tabellen.
                                 //  S† lange lagene foran har d†rligere
                                 //    poengsum, og ikke n†dd fram til
                                 //    det f›rste laget:
  while (n > 1  &&  tabellen[n-1].ant_poeng < laget.ant_poeng)  {
     tabellen[n] = tabellen[n-1];   //  Flytter et lag ett hakk ned i tabellen.
     --n;                           //  Sammenligner s† med den foran der.
  }
  tabellen[n] = laget;           //  Funnet plassen og smetter inn.
}
