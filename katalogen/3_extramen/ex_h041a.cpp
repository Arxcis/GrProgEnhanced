//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H04_1A.CPP

//  Løsning til eksamen i C++, 21.desember 2004, oppgave 1A.
//  Laget av Frode Haug, HiG, desember 2004.


#include <iostream>
#include <cstring>
using namespace std;

const int X = 32;
char txt[] = "GRUNNLEGGENDE PROGRAMMERING MED FRODEH ER SPESIELT FESTLIG!";

int main()  {
	int i, j = 3;

    for (i = X;  i < strlen(txt)-1;  i++)  cout << txt[i];
    cout << '\n';
    
	for (i = 6;  i < 25;  i += j)
		if (txt[i] != 'E'  &&  txt[i] != 'R')  cout << txt[i] << ' ';
    cout << '\n';

    while (j <= X-i)
       cout << txt[5*j++] << '\n';
	return 0;
}


//  Utskrift:  FRODEH ER SPESIELT FESTLIG
//             M I
//             R
//             M
//             N
