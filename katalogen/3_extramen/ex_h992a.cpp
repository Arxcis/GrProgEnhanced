//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H992A.CPP

//  L›sningsforslag til eksamen i C++, 14.desember 1999, oppgave 2A.
//  Laget av Frode Haug, HiG, desember 1999.



#include <iostream>

using namespace std;

int main()  {
  char tekst[] = "RISKREMEN";
  int i = 4;

  while (tekst[i] != 'K')  {
    cout << tekst[i] << '\n';

    i = ( i == 8) ?  0  :  i+1;

    if (tekst[i] == 'E')  {
      cout << "eeee!\n";  ++i;
    } else if (tekst[i] == 'R')
      i += 3;
  }
  return 0;
} 


//  Utskrift:
//      R
//      eeee!
//      M
//      eeee!
//      N

