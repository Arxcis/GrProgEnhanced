//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_S06_1A.TXT

//  Løsning til eksamen i C++, 9.august 2006, oppgave 1A.
//  Laget av Frode Haug, HiG, mai 2006.


#include <iostream>
using namespace std;

char txt[] = "DILL-DALL-DOLLOM";

int main()  {
  int i, j = 15;
  for (i = 3;  i < 18;  i+=5, j-=5)
      cout << txt[i] << ' ' << txt[j] << '\n';

  i = 12;  j = 2;
  while (j < i)  {
    cout <<  txt[i] << ' ' << txt[j] << '\n';
    j += 3;  i-= j;    
  }
  return 0;
}



//  Utskrift:  L M
//             L D
//             L D
//             L L
//             L D
