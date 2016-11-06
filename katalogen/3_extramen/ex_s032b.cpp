//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S032B.CPP

//  L›sning til eksamen i C++, 9.august 2003, oppgave 2B.
//  Laget av Frode Haug, HiG, august 2003.



#include <iostream>
#include <cstring>
using namespace std;

char tekst[] = "KONTINUASJONSEKSAMEN";


void skriv(char t[], int n, int m)  {
  for (int i = n;  i <= m;  i+=3)
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
  skriv(tekst, 0, strlen(tekst)-2);
  cout << hent(tekst, 4) << ' ' << hent(tekst, 8) << '\n';
  cout << char(hent(tekst, 12)+4) << ' ' << int(hent(tekst, 8)) << '\n';
  rokk(tekst[4], tekst[7]);
  skriv(tekst, 1, 9);
  rokk(tekst[5], tekst[hent(tekst, 14)-'D']);
  skriv(tekst, 1, 3);
  return 0;
}


//   Utskrift:
//       K T U J S S E
//       T A
//       R 65
//       O A I
//       N

