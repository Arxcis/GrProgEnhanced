//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_10.CPP


//   L›sningsforslag til oppgave nr.10  i   C++ -programmering.
 


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {
  int pinner = 25;                          //  Antall pinner igjen. 
  int menneske, maskin;                     //  Antall som henholdsvis
                                            //    brukeren og maskinen tar.
  do {
    cout << "\n\nDet er " << pinner << " pinner.";
    cout << "\n\tDu kan ta 1, 2 eller 3 stk.  Skriv antall:  ";
    cin >> menneske;                        //  Leser antallet brukeren tar.
    pinner -= menneske;                     //  Beregner antall igjen.
    maskin = 4 - menneske;                  //  Beregner maskinens antall.
    cout << "\n\nDet er " << pinner << " pinner.";
    cout << "\n\tJeg tar " << maskin << " pinne(r).";
    pinner -= maskin;                       //  Beregner antall igjen.
  } while (pinner != 1);                    //  Looper til brukeren taper !

  cout << "\n\n\nDet er 1 pinne igjen, og DU m† ta den. DU TAPER !\n\n\n";

  return 0;
}
