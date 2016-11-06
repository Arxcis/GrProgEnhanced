//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H081A.CPP

//  L›sning til eksamen i C++, 2.desember 2008, oppgave 1A.
//  Laget av Frode Haug, HiG, november 2008.


#include <iostream>
#include <cstring>

using namespace std;

char txt[] = "TARZAN-HENGER-LENGE-I-JUNGELLIANENE";

int main()   {

  int i = 17, j = i % 3, k = i / j, len = strlen(txt);
  
  cout << txt[j] << ' ' << txt[k] << '\n';   --i;

  while (i <= len-k)  {
    i += k;  cout << txt[i] << ' ' << txt[i+j] << '\n';
  }

  cout << txt[len % 5] << ' ' << txt[len / 5] << '\n';
  cout << txt[17 - 4 * 2 / 3] << ' ' << txt[17 % 3 * 5] << '\n';

  return 0;
}



//   Utskrift:
//      R E
//      N E
//      E E
//      T H
//      E G
