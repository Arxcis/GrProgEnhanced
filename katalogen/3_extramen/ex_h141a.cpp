//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H141A.CPP

//  L›sning til eksamen i C++, 2.desember 2014, oppgave 1A.
//  Laget av Frode Haug, HiG, november 2014.


#include <iostream>
using namespace std;

char txt[] = "FRODE-DRAR-TIL-LONDON-OM-TRE-DAGER-UTEN-AA-SE-ARSENAL!!!";


int main()   {

   int i = 18,  j = i % 5,  k = i / j;
   do {
      cout << txt[i] << ' ' << txt[i+j] << '\n';
      i += k;   j *= 2;
   } while (i <= 30);

   i = j = k =  12 - 3 * 2;
   while (k  <  i * j)  {
     cout << txt[k] << ' ' << txt[k*5/3] << '\n';
     k += 15;
   }

   return 0;
}


//   Utskrift:    D -
//                - A
//                A -
//                D -
//                - U
