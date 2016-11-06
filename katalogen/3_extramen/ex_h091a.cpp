//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H091A.CPP

//  L›sning til eksamen i C++, 7.desember 2009, oppgave 1A.
//  Laget av Frode Haug, HiG, november 2009.


#include <iostream>
#include <cstring>

using namespace std;

char txt[] = "DREAMTHEATER-OG-DROPKICK-MURPHYS";

int main()   {
  int i = 5,  j = (i * i) % 7;

  cout << txt[i] <<  ' ' << txt[j] << '\n'; 

  i *= j;
  while (i <= strlen(txt) )  {
    cout << txt[i - (j * 2) + 1] << ' ';
    i += j*3; cout << i << '\n';
  }

  for (i = strlen(txt)-4, j = 2;  j > 0;  j--)
      cout << txt[i+j] << ' ' << txt[i-j] << '\n';

  return 0;
}



//   Utskrift:    T M
//                O 32
//                M 44
//                Y U
//                H R
