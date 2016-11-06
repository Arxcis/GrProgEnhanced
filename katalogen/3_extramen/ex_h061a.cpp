//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H061A.CPP

//  L›sning til eksamen i C++, 20.desember 2006, oppgave 1A.
//  Laget av Frode Haug, HiG, desember 2006.



#include <iostream>

using namespace std;

char txt[] = "STORHAMAR-ARSENAL-KAMMA";

int main()   {
  int i = 11, j = 11;	

  i--;  ++j;
  cout << i << ' ' << txt[i] << ' ' << j << ' ' << txt[j] << '\n';

  for (i = 0, j = 4;  i < 18;  ++j, i += j)
      cout << i+1 << ": " << txt[i] << '\n';
  
  j = 8;
  i = (j % 3) * (j / 3);
  cout << i << ": " << txt[i] << '\n';
  
  return 0;
}


//   Utskrift:
//      10 A 12 S
//      1: S
//      6: A
//      12: R
//      4: H
