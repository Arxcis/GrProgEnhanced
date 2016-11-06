//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H012B.CPP

//  L›sning til eksamen i C++, 5.desember 2001, oppgave 2B.
//  Laget av Frode Haug, HiG, november 2001.



#include <iostream>
#include <cstring>

using namespace std;
 
void funk1(char t[], int nn = 4) {
  cout << t[nn] << '\n';
}


void funk2(int & nn, char t[]) {
  nn = strlen(t) / 2;
}


int funk3(int nn, int mm) {
  int s = 1;
  for (int i = 1; i <= mm; i++)  s *= nn;
  return s;
}


int main()  {
  int n;
  funk1("LUNGEMOS");
  funk1("STLTERMOS", 9);
  funk2(n, "PLSE, LOMPE OG BRD");  cout << n << '\n';
  cout << funk3(2, 5) << '\n';
  funk2(n, "TRRFISK");  cout << funk3(3, n) << '\n';
  return 0;
}




//   Utskrift:
//      E 
//      S
//      10 
//      32 
//      81 

