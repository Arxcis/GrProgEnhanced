//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S101A.CPP

//  L›sning til kontinuasjonseksamen i C++, 13.august 2010, oppgave 1A.
//  Laget av Frode Haug, HiG, mai 2010.


#include <iostream>
#include <cstring>

using namespace std;

char txt[] = "EMIRATES-STADIUM-HERE-I-COME";

int main()   {
  int i = 13,  j = (i % 11) * i - 1;
  cout << txt[i] <<  ' ' << txt[j] << '\n';

  j -= i;   i %= 5;
  cout << txt[i] <<  ' ' << txt[j] << '\n'; 

  j +=j;  i++;  ++i;
  while (j <= strlen(txt) )  {
    cout << txt[j - (15 % 8)] << ' ';
    j += i;  cout << j << '\n';
  }

  for (i = strlen(txt)-7, j = 3;  j > 0;  j-=2)
      cout << txt[i+j] << ' ' << txt[i-j] << '\n';

  return 0;
}



//   Utskrift:    I O
//                R D
//                H 29
//                C E
//                I E
