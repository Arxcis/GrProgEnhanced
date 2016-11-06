//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S032A.CPP

//  L›sning til eksamen i C++, 9.august 2003, oppgave 2A.
//  Laget av Frode Haug, HiG, august 2003.



#include <iostream>

using namespace std;

const int N   = 23;
const int M   = 4;

int main()   {
  int i=3, j, k;
  while (i < N)  {
    cout << i << ": ";
    for (j = 1;  j <=  i/2;  j += 3)
        cout << j << ' ';
    cout << '\n';
	for (k = 0; k < M; k++)  i++;
  }
  return 0;
}





//   Utskrift:
//      3:  1
//      7:  1
//      11: 1 4
//      15: 1 4 7
//      19: 1 4 7
