//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_12.CPP


//   L›sningsforslag til oppgave nr.12  i   C++ -programmering.


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {
  int sisteTall = 3000;                     //  Siste mulige primtall.
  int i,j;                                  //  L›kke-variable.
  char ch;                                  //  Leser tastetrykk fra bruker.
  bool primtall;                            //  Boolsk verdi for om er
                                            //     primtall eller ei.
  int n = 0;                                //  Antall primtall funnet.

  for ( i = 3;  i <= sisteTall;  i += 2 )  {    //  G†r gjennom alle tall
                                                //    fra 3 til "sisteTall":
    primtall = true;                            //  Antar at primtall.

    for ( j = 3;  j <= i/2;  j += 2 )       //  Sjekker om delelig med et
                                            //    tall mindre enn halvparten.
      if (i % j == 0)  {                    //  Dersom delelig (ingen rest):
        primtall = false;                   //  Setter at ikke primtall.
        break;                              //  Hopper ut av indre l›kke.
      }

    if (primtall) {                         //  Dersom primtall (=TRUE / 1):
       cout << setw(10) << i;               //  Skriver tallet.
       ++n;                                 //  Teller opp antall forekomster
                                            //    av primtall med 1.
       if (n % 160 == 0)  {                 //  Dersom skrevet 20 linjer
                                            //    (20 * 8 = 160):
          cout << "\n\n" << setw(70) << "Trykk en tast og deretter ENTER/CR ....." << '\n';
          cin >> ch;
       } 
    }
  }
  cout << '\n';
  return 0;
}
