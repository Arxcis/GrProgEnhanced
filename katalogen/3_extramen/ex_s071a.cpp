//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S071A.CPP

//  L›sning til kontinuasjonseksamen i C++, 8.august 2007, oppgave 1A.
//  Laget av Frode Haug, HiG, mai 2007.


#include <iostream>

using namespace std;

char txt[] = "BANANSKALLET-SKULLE-SLUKKE-FYRSTIKKEN";

int main()   {
  int i = 8, j = i+4;	

  i--;  ++j;
  cout << txt[--i] << ' ' << txt[j++] << '\n';

  for (i = 36, j = 15;  j < i;  j+=3, i-=4)
      cout << txt[j] << ' ' << txt[i] << '\n';
  
  j = 25;
  i = (++j  % 7) * 2 - 3;
  cout << i << ' ' << txt[i] << '\n';
  
  return 0;
}


//   Utskrift:
//      K S 
//      U N
//      E I
//      L Y
//      7 A
