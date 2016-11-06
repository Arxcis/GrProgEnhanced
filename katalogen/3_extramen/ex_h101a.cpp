//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H101A.CPP

//  L›sning til eksamen i C++, 7.desember 2010, oppgave 1A.
//  Laget av Frode Haug, HiG, november 2010.


#include <iostream>
#include <cstring>

using namespace std;

char txt[] = "NESTE-GANG-VIL-ARSENAL-BANKE-TOTTENHAM-GRUNDIG";

int main()   {
  int i = 8,  j = 28 % i;

  cout << txt[i] <<  ' ' << txt[j] << '\n';

  i /= j;
  while (i <= 15)  {
	cout << txt[i*(j/2)] << ' ' << txt[i*j] << '\n';
    i *= i;   j += 2;
  }

  j = 7;
  for (i = 30;  i > 22;  i-=j)
      cout << txt[i-j] << ' ' << txt[i+j] << '\n';

  return 0;
}



//   Utskrift:    N E
//                E N
//                I A
//                B M
//                R O
