//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H022A.CPP

//  L›sning til eksamen i C++, 19.desember 2002, oppgave 2A.
//  Laget av Frode Haug, HiG, desember 2002.



#include <iostream>

using namespace std;

char txt[] = "LOMPEPAKKESAMLEMANI";


int main()  {
  bool fortsett = true;
  int i = 1, j;

  do  {
    cout << txt[++i * 2] << '\n';
  } while (i < 3);

  i = 3;
  while (fortsett)  {
    j = (i % 2) ? 3 : 5;
    i += j;  
    cout << i << ": " << txt[i] << '\n';
	if (i > 13) fortsett = false;
  }

  return 0;
}




//   Utskrift:
//       E
//       A
//       6:  A
//       11: A
//       14: E

