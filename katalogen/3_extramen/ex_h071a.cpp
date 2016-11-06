//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H071A.CPP

//  L›sning til eksamen i C++, 20.desember 2007, oppgave 1A.
//  Laget av Frode Haug, HiG, desember 2007.


#include <iostream>
#include <cstring>

using namespace std;

char txt[] = "KLUBBEN-HADDE-KLUBB-OG-DUPPE";

int main()   {

  int i = 14,   j = i / 3,   k = strlen(txt);

  while (i < 22)  {
    cout << txt[i] << ' ' << txt[i/2] << '\n';
	i += j;
  }

  cout << k << ' ' << txt[k % 6] << txt[(k % 6) + 1] << '\n';

  i = 13;  k = 49 % i;  i /= 4;
  cout << txt[k+i-1] << '\n';
  cout << txt[(k-i)*(j/2)] << '\n';

  return 0;
}



//   Utskrift:
//      K - 
//      B A
//      28 BE
//      E
//      K
