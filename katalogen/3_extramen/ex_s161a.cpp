//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S161A.CPP

//  L›sning til kontinuasjonseksamen i C++, august 2016, oppgave 1A.
//  Laget av Frode Haug, NTNU


#include <iostream>
using namespace std;

char txt[] = "SPRINGSTEEN-OG-STING-HAR-NETTOPP-SPILT-I-OSLO-OG-HAMAR";

int main()   {
	int i = 42,   j = 22 / 7,   k = i - (j * 2);

	cout << txt[k] << ' ' << txt[j] << ' ' << txt[i] << '\n';

	while ((i - k) > j)  {
		cout << txt[j] << ' ' << txt[i + j] << '\n';
		j += 2;
	}
	
	k = 17;   i = int('G' - 'D');

	for (j = k % i;  i >= j;  i--)  {
		cout << txt[k + i + j] << ' ' << txt[k + (i % j)] << '\n';
	}

   return 0;
}


//   Utskrift:    L I S
//                I - 
//                G G
//                A N
//                H I
