//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H022B.CPP

//  L›sning til eksamen i C++, 19.desember 2002, oppgave 2B.
//  Laget av Frode Haug, HiG, desember 2002.


#include <iostream>

using namespace std;
 
void funk(char t[], int nn=2) {
  cout << t[nn/2] << '\n';
}


void funk(int & nn, char t[]) {
  nn /= 3;
  cout << t[nn] << '\n';
}


char funk(char t[], int mm, int nn) {
  return t[mm*nn];
}


int main()  {
  int n = 10, mm = 3;
  funk("BRILLEETUI", 10); 
  funk(n, "BRILLEETUI");
  funk("BRILLEETUI");
  cout << funk("BRILLEETUI", mm, n) << '\n';  
  cout << int(funk("BRILLEETUI", 2, 4)) << '\n';
  return 0;
}





//   Utskrift:
//      E
//      L
//      R
//      I
//      85    (= ASCII-nummeret til 'U')