//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S131B.CPP

//  L›sning til kontinuasjonseksamen i C++, 16.august 2013, oppgave 1B.
//  Laget av Frode Haug, HiG, juli 2013.


#include <iostream>
#include <cstring>
using namespace std;

class Sykkel  {
  private:
    char navn[30];
    char lag[30];
  public:
    Sykkel(char l[], char n[])  {  strcpy(navn, n);  strcpy(lag, l);     }
    void skriv()                {  cout << navn << ", " << lag << '\n';  }
    bool erLik(char l[])        {  return (!strcmp(lag, l));             }
    bool har(char c)            {  return (navn[1] == c);                }
    void bygg(char n[])         {  strcat(navn, " "); strcat(navn, n);   }
    int  len()                  {  return(strlen(navn)-strlen(lag));  }
};


int main()  {
  Sykkel s1("Sky", "Froome"),     s3("Sky", "Boasson"),
         s2("Belkin", "Mollema"), s4("Saxo-Tinkoff", "Contador");
  s3.skriv();
  cout << (int) s2.erLik("Sky") << ' ' << (int) s1.erLik("Sky") << '\n';
  cout << (int) s1.har('o') << ' ' << (int) s2.har('o') << ' '
       << (int) s3.har('o') << ' ' << (int) s4.har('o') << '\n';
  s3.bygg("Hagen");   s3.skriv();
  cout << s1.len() << ' ' << s3.len() << ' ' << s4.len() << '\n';
  return 0;
}


//  Utskrift:  Boasson, Sky
//             0 1
//             0 1 1 1 
//             Boasson Hagen, Sky
//             3 10 -4
