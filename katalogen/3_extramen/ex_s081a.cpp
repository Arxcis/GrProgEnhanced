//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S081A.CPP

//  L›sning til kontinuasjonseksamen i C++, 12.august 2008, oppgave 1A.
//  Laget av Frode Haug, HiG, mai 2008.


#include <iostream>
#include <cstring>

using namespace std;

char txt[] = "STORHAMARJENTENE-HERJET-I-AARHUS/DANMARK-I-SOMMER";

int main()   {

  int i = 35,   j = i % 9,   k = strlen(txt)-i;

  while (i > 19)  {
    cout << txt[i] << ' ' << txt[i/3] << '\n';
	i -= j;
  }

  cout << k << ' ' << txt[k / 4] << ' ' << txt[(k % 6) + 1] << '\n';

  txt[23] = '\0';
  i = 13;  k = i*4-32;  i /= 4;
  
  cout << txt << ' ' << txt[k] << txt[k+1] << txt[k+2] << '\n';
  cout << txt[k % i] << '\n';
  return 0;
}



//   Utskrift:
//      N N
//      A J
//      14 R R
//      STORHAMARJENTENE-HERJET JET
//      O
