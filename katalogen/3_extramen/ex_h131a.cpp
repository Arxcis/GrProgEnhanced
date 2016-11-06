//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H131A.CPP

//  L›sning til eksamen i C++, 3.desember 2013, oppgave 1A.
//  Laget av Frode Haug, HiG, november 2013.


#include <iostream>
#include <cstring>
using namespace std;

char txt[] = "ALAN-CLARK-OG-CHRIS-WHITE-VENTER-BACKSTAGE-I-FEBRUAR";

int main()   {
   int i = 14, j = 7, k = j % 5;

   do  {
      cout << txt[i+j+k] << '\n';
      i += j;  j += k;  k = j % 7;
   } while (i <= 35);

   j = strlen(txt)-35;  k = 5;
   for (i = strlen(txt) % 26;  i <= j;  i += (k*2))
       cout << txt[i] << '\n';       

   return 0;
}


//   Utskrift:    T
//                -
//                F
//                A
//                -
