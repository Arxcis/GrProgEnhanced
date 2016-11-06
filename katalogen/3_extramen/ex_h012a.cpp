//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H012A.CPP

//  L›sning til eksamen i C++, 5.desember 2001, oppgave 2A.
//  Laget av Frode Haug, HiG, november 2001.



#include <iostream>

using namespace std;

char txt[] = "STORT STORHAMAR";
int indeks[] = { 7, 12, 2, 3, 8, 9 };


int main()  {
  int i;
  for (i = 0; i <= 12;  i+=5)
    cout << txt[i+1] << '\n';

  for (i = 1; i < 3;  i++)
  cout << txt[indeks[i]] << '\n';

  return 0;
}




//   Utskrift:
//       T
//       S
//       A
//       M
//       O

