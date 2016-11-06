//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H05_1A.CPP

//  Løsning til eksamen i C++, 19.desember 2005, oppgave 1A.
//  Laget av Frode Haug, HiG, desember 2005.


#include <iostream>
using namespace std;

char txt[] = "ABBA-BA-AB-BE-EBBA";

int main()  {
  int i, j = 8;
  for (i = 9;  i < 18;  i+=3, j-=2)
      cout << txt[i] << ' ' << txt[j] << '\n';

  i = 0;  j = 17;
  while (i < j)  {
    i += 2; j /= i;    
    cout <<  txt[i] << ' ' << txt[j] << '\n';
  }
	
  return 0;
}


//  Utskrift:  B A
//             E A
//             B -
//             B A
//             - B
