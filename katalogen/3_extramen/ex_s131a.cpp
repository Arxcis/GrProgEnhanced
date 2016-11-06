//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S131A.CPP

//  L›sning til kontinuasjonseksamen i C++, 16.august 2013, oppgave 1A.
//  Laget av Frode Haug, HiG, juli 2013.


#include <iostream>
#include <cstring>
using namespace std;

char txt[] = "FORTSATT-ER-GRESK-SOMMERFERIE-ALLER-ALLER-BEST";

int main()   {
   int i = 20,  j = i % 6,  k = i % 19;

   do  {
     cout << txt[i + j + (k++)] << '\n';    i += j;    j += k;
   } while (txt[i-1] != 'L');

   j = 4;
   for (i = strlen(txt) % 10;   i <= strlen(txt);   j *= j,  i +=j)
       cout << txt[i] << ' ' << txt[i+j] << '\n';

   return 0;
}


//   Utskrift:    R
//                E
//                A
//                T R
//                E L
