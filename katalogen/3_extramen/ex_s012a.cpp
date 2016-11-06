//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S012A.CPP

//  L›sningsforslag til eksamen i C++, 17.august 2001, oppgave 2A.
//  Laget av Frode Haug, HiG, august 2001.



#include <iostream>

using namespace std;

int main()   {
  int i=10, j;

  while (i > 0)  {
    cout << i << ":  ";
    for (j = 1;  j <  i*2;  j *= 2)
        cout << j << "  ";
    cout << '\n';
    i -= 2;
  }
  return 0;
}


//   Utskrift:
//      10: 1  2  4  8  16
//       8: 1  2  4  8 
//       6: 1  2  4  8 
//       4: 1  2  4
//       2: 1  2
