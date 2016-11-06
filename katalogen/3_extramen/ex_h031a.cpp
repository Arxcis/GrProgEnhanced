//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H031A.CPP

//  Løsning til eksamen i C++, 15.desember 2003, oppgave 1A.
//  Laget av Frode Haug, HiG, november 2003.


#include <iostream>

using namespace std;


char txt[] = "STEINALDERSPILLESTIL";


int main()  {
  int i, j;

  for (i = 5;  i <= 19;  i += j)  {
     cout << txt[i + 10 / 3] << '\n';
	 j = i * 2;
  }

  j = 18;  i = j / 3;
  while (j > i-3)  {
    cout << txt[--j] << '\n';
    j -= i;
  }

  cout << "\n\n";
  return 0;
}



//   Utskrift:
//       E
//       I
//       T
//       S
//       I
