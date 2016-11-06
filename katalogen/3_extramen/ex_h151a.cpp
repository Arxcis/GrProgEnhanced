//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H151A.CPP

//  L›sning til eksamen i C++, 1.desember 2015, oppgave 1A.
//  Laget av Frode Haug, HiG, november 2015.


#include <iostream>
using namespace std;

char txt[] = "SISTE-HELGA-I-PAASKA-NESTE-AAR-ER-DET-SPILLEFRI-I-ENGLAND-GRRR!";

int main()   {
	int i = 21, j = 42 / 6, k = i + (j * 3);

	cout << txt[k] << ' ' << txt[j] << ' ' << txt[i] << '\n';

	while (k % i == 0)  {
		j *= 2;
		cout << txt[i+j] << ' ' << txt[k-j+10] << '\n';
		k /= 2;
	}

	k = int(58.97F);  j = int('E' - 'A');  i = k % j;
	do {
		cout << txt[i] << ' ' << txt[k] << ' ' << txt[j] << '\n';
		i++;  ++i;  k--;  --k;
		j *= j;
	} while (j <= k);

   return 0;
}


//   Utskrift:    L E N
//                E S
//                - T
//                S G E
//                E D A
