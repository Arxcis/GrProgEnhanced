//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_S05_1A.CPP

//  Løsning til kontinuasjonseksamen i C++, 9.august 2005, oppgave 1A.
//  Laget av Frode Haug, HiG, juni 2005.


#include <iostream>
using namespace std;

char txt[] = "INNI KORNSILOEN HANG EN BJØRK TIL TØRK";

int main()  {
    int i = 17;

    while (i <= 26)  {
       i += 9;
       cout << txt[i] << txt[i+1] << txt[i+2] << '\n';
    }

    for (i = 6;  i <= 312;  i*=i) 
        cout << ((txt[i] > 'Q') ? "<" : ">") << '\n';

    i = 9;
    cout << txt[i * 7 / 3 % 6] << '\n';
    return 0;
}


//  Utskrift:  ØRK
//             ØRK
//             >
//             <
//             I
