//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S022B.CPP

//  L›sning til eksamen i C++, 9.august 2002, oppgave 2B.
//  Laget av Frode Haug, HiG, juli 2002.



#include <iostream>

using namespace std;

struct rec  {
  char text[10];
  char tegn;
};

rec recorder[] =  { {"MOR", 'M'},  {"FAR", 'F'},   {"TANTE", 'T'},
                    {"BROR", 'B'}, {"NIESE", 'N'}, {"BABY", 'B'}   };

void funk0(char txt[], char c)
  {  cout << txt << '\t' << c << '\n';  }

void funk(rec a)
  {  funk0(a.text, a.tegn);  }

void funk(char txt[], char c = 'X')
  {  funk0(txt, c);  }

void funk(char c, char txt[]="BESSA")
  {  funk0(txt, c);  }

void funk(int i, int j)
  {  rec a = recorder[i];  recorder[i] = recorder[j];  recorder[j] = a;  }

int main()  {
  funk(recorder[2]);
  funk(recorder[3].text);
  funk(recorder[1].tegn);
  funk(4, 5);
  funk(recorder[4].text, 'Z');
  funk(recorder[5].tegn, "BESSANT");
  return 0;
}



//   Utskrift:
//      TANTE   T
//      BROR    X
//      BESSA   F
//      BABY    Z
//      BESSANT N

