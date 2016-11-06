//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S002A.CPP

//  L›sningsforslag til eksamen i C++, 16.august 2000, oppgave 2A.
//  Laget av Frode Haug, HiG, juli 2000.



#include <iostream>

using namespace std;

const int LEN = 15;

int main()  {
  char tekst[] = "SJOKOLADEPUDDING";
  int i = 0;

  while (tekst[i])  {
    if (i % 3 == 0)
       cout << tekst[i] << "  " <<  tekst[LEN - i] << '\n';
    i++;
  }
  return 0;
} 


//  Utskrift:
//      S  G
//      K  D
//      A  P
//      P  A
//      D  K
//      G  S
