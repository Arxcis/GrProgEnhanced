//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H111A.CPP

//  L›sning til eksamen i C++, 6.desember 2011, oppgave 1A.
//  Laget av Frode Haug, HiG, november 2011.


#include <iostream>
#include <cstring>

using namespace std;
char txt[] = "ARSENAL-RULER-ALLTID-UANSETT-RESULTAT";

int main()   {
   int i, j, n = strlen(txt);   //  37
   for (i = 16;  i < n-i;  i++)  {
	   j = i % 5;
	   cout << txt[i+j] << ' ' << txt[i-(j/2)] << '\n';
   }

   i = 3;  j = 16;
   while (j <= n)  {
      cout << txt[j%i] << '\n';
	  i *= 7;  j += j;
   }	
   return 0;
}



//   Utskrift:    T L
//                D L
//                U T
//                R
//                E
