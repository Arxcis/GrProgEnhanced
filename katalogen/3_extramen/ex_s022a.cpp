//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S022A.CPP

//  L›sning til eksamen i C++, 9.august 2002, oppgave 2A.
//  Laget av Frode Haug, HiG, juli 2002.



#include <iostream>

using namespace std;

char txt[] = "SOPPEKOKER ANNE MARI MARIANNE";


int main()  {
  int i, j;

  for (i = 2; i <= 18;  i*=i)
    cout << txt[i] << '\n';

  for (i = 25, j = 2;  i >= 0;  i-=j, j*=i)
    cout << txt[i] << '\n';

  return 0;
}




//   Utskrift:
//       P
//       E
//       M
//       A
//       R

