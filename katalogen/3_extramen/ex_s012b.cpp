//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S012B.CPP

//  L›sningsforslag til eksamen i C++, 17.august 2001, oppgave 2B.
//  Laget av Frode Haug, HiG, august 2001.



#include <iostream>
#include <cstring>

using namespace std;

void funk(char txt[], int n = 1, char ch = 'O')
  {  txt[n] = ch;  }

void funk(char txt[], char ch)
  {  txt[3] = ch;  ch = 'E';  }

void funk(char txt[], char & ch, int n)
  {  ch = txt[n];  strcpy(txt, "HALLO");  }

int main()  {
  char tekst[] = "MALLA";
  char tegn = 'O';

  funk(tekst);            cout << tekst << '\n';
  funk(tekst, tegn);      cout << tekst << "  " << tegn << '\n';
  funk(tekst, 2, 'T');    cout << tekst << '\n';
  funk(tekst, tegn, 1);   cout << tekst << "  " << tegn << '\n';
  funk(tekst, 1, tegn);   cout << tekst << '\n';
  return 0;
}


//   Utskrift:
//      MOLLA
//      MOLOA  O
//      MOTOA
//      HALLO  O
//      HOLLO
