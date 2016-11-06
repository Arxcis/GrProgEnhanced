//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S141A.CPP

//  Løsning til kontinuasjonseksamen i C++, 8.august 2014, oppgave 1A.
//  Laget av Frode Haug, HiG, juli 2014.

#include <iostream>
using namespace std;

char txt[] = "ARSENAL-LIVERPOOL-SPILLER-FORSTKOMMENDE-PAASKE";

int main()   {
   int i, j = 18, k = 5, m = j % k;  int n = m * m;

   for (i = j;  i != 45;  i += n)  cout << txt[i] << '\n';

   m++;
   do  {
     cout << txt[j] << '\n';   j += (k + m + n);
   } while (j < i);

   return 0;
}


//   Utskrift:    S
//                O
//                N
//                S
//                N
