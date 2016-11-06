//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S151A.CPP

//  L›sning til eksamen i C++, 12.august 2015, oppgave 1A.
//  Laget av Frode Haug, HiG, juni 2015.


#include <iostream>
using namespace std;

char txt[] = "HORNINDAL-NORANGSDALEN-HELLESYLT-GEIRANGER-STRYN-LOEN-OLDEN";

int main()   {
   int i = 10,  j = i % 6,  k = i / j;
   do {
      cout << txt[i+1] << ' ' << txt[i+k] << '\n';
	  i += j;   k *= 2;
   } while (i <= 20);

   i = 100 / 3;  j = 12 + 8 - 10 / 2;  k = j / 3;
   while (i  <  (j * k) / 2 )  {
     cout << txt[i] << ' ' << txt[i+1] << '\n';
	 i += 2;
   }
   return 0;
}


//   Utskrift:    O R
//                G A
//                L L
//                G E
//                I R
