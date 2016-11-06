//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_50.CPP

//   L›sningsforslag til oppgave nr.50  i   C++ -programmering.

//   Basert p† forslag/innspill fra Daniel Solstad.


//   Programmet looper (nedover) gjennom en rekke med heltall.
//   Det skrives ut litt ulike tekster ut fra hva tallet er.


#include <iostream>          //  cout, cin
#include <iomanip>           //  setw

using namespace std;

const int MAX = 24;          //  Max. antall flasker i en kasse.

int main()  {
  int i;
                                     //  G†r gjennom tallene (nedover),
  for (i = MAX;  i >= 1;  i--)  {    //     og skriver litt ulike tekster:
    cout << setw(2) << i << " brusflaske" << ((i > 1) ? "r" : "") << " i kassen, "
         << setw(2) << i << " flaske" << ((i > 1) ? "r" : "") << " med brus.\n"
         << ((i > 1) ? "Ta en og drikk den opp, "
                     : "G† til butikken og kj›p mer, ")
         << setw(2) << ((i > 1) ? i-1 : MAX) << " flaske" 
         << ((i != 2) ? "r" : "") << " igjen i kassen.\n";
  }
  return 0;
}
