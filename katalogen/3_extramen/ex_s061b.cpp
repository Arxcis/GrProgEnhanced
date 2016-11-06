//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_S06_1B.TXT

//  Løsning til eksamen i C++, 9.august 2006, oppgave 1B.
//  Laget av Frode Haug, HiG, mai 2006.


#include <iostream>
using namespace std;

char tekst[] = "BILGUMMIDEKKOVERFLATEBEHANDLING";

void skriv(char t[], int n, int m, int d)  {
  for (int i = n;  i <= m;  i+=d)
      cout << t[i] << ' ';
  cout << '\n';
}


char hent(char t[], int nr)  {
  return t[--nr];
}


void rokk(char & a, char & b)  {
  char c = a;  a = b;  b = c;
}


int main() {
  skriv(tekst, 7, 23, 5);
  cout << hent(tekst, 9) << ' ' << hent(tekst, 27) << '\n';
  cout << char(int(tekst[19])+4) << '\n';
  rokk(tekst[3], tekst[8]);    skriv(tekst, 0, 7, 1);
  rokk(tekst[4], tekst[hent(tekst, 23)-'D']);
  skriv(tekst, 1, 4, 3);
  return 0;
}



//  Utskrift:  I O L E
//             D D
//             X
//             B I L D U M M I
//             U I
