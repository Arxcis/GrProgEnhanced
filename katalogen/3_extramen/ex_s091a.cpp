//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S091A.CPP

//  L›sning til kontinuasjonseksamen i C++, 14.august 2009, oppgave 1A.
//  Laget av Frode Haug, HiG, mai 2009.


#include <iostream>
#include <cstring>

using namespace std;


int main()   {
  char txt[] = "EMIRATES-CUP-VAR-EN-STOOOOR-OPPLEVELSE";
  int i = 20, j = i % 7, k = (i*2) / j, len = strlen(txt);
  
  cout << txt[j] << ' ' << txt[k] << '\n';

  while ((i += k) < len)  {
    cout << txt[i] << ' ' << txt[i - (5 % 3)] << '\n';
  }

  i = int(true);  j = int(false) + 4;

  cout << txt[i] << ' ' << txt[j] << '\n';
  cout << txt[(len%j)+i] << ' ' << txt[k-j] << '\n';

  return 0;
}



//   Utskrift:
//      E E
//      R O
//      E P
//      M A
//      R I
