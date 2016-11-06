//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H121A.CPP

//  L›sning til eksamen i C++, 4.desember 2012, oppgave 1A.
//  Laget av Frode Haug, HiG, november 2012.


#include <iostream>
#include <cstring>
using namespace std;

char txt[] = "FLYBILLETT-TIL-LONDONPAASKE-ALLEREDE-BESTILT!!!";

int main()   {
   int i = 17,  j = i % 3,  k = 0;
   bool ferdig = false;
   do  {
     cout << txt[i + (++k)] << '\n';    i *= (j * k);
   } while (i < strlen(txt));

   i = 30 / 6 + 2;  j = strlen(txt) - strlen(txt) + 2; 
   while (!ferdig)  {
     cout << txt[i] << ' ' << txt[j] << '\n';
     i += 4; j++;
     if (i % j == 4)  ferdig = true;
   }
   return 0;
}


//   Utskrift:    D
//                -
//                E Y
//                T B
//                L I
