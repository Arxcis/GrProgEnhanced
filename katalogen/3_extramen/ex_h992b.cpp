//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H992B.CPP

//  Lõsningsforslag til eksamen i C++, 14.desember 1999, oppgave 2B.
//  Laget av Frode Haug, HiG, desember 1999.



#include <iostream>
#include <cstring>

using namespace std;

void funk(char txt[], int n = 1, char ch = 'L')
  {  txt[n] = ch;  }

void funk(char txt[], char ch)
  {  txt[2] = ch;  ch = 'è';  }

void funk(char txt[], char & ch, int n)
  {  ch = txt[n];  strcpy(txt, "MOLBO");  }

int main()  {
  char tekst[] = "FRODE";
  char tegn = 'ù';

  funk(tekst);            cout << tekst << '\n';
  funk(tekst, tegn);      cout << tekst << "  " << tegn << '\n';
  funk(tekst, 3, 'T');    cout << tekst << '\n';
  funk(tekst, tegn, 3);   cout << tekst << "  " << tegn << '\n';
  funk(tekst, 0, tegn);   cout << tekst << '\n';
  return 0;
}

//   Utskrift:
//      FLODE
//      FLùDE  ù
//      FLùTE
//      MOLBO  T
//      TOLBO
