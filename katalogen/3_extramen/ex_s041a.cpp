//  Fil:   FRODEH \ CPP \ EXTRAMEN \ EX_S041A.CPP

//  Løsning til kontinuasjonseksamen i C++, 12.august 2004, oppgave 1A.
//  Laget av Frode Haug, HiG, juni 2004.


#include <iostream>

using namespace std;


char txt[] = "KROMKAKER-OG-MANDELTERTEBUNN-MED-JORDBÆRSAUS-OG-KREM";


int main()  {
  int i, j;

  for (i = 3;  i <= 46;  i += j)  {
     cout << txt[(2*i) +  (i/2)] << '\n';
	 j = i * 3;
  }

  j = 36;  i = j % 10;
  while (j != i)  {
    cout << txt[j+1] << '\n';    
    j -= 10;          
  }

  cout << "\n\n";
  return 0;
}



//   Utskrift:
//       E
//       E
//       B
//       N
//       E
