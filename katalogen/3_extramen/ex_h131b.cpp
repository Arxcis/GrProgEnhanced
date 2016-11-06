//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H131B.CPP

//  L›sning til eksamen i C++, 3.desember 2013, oppgave 1B.
//  Laget av Frode Haug, HiG, november 2013.


#include <iostream>
#include <cstring>
using namespace std;

class Band  {
  private:
    char navn[20];
    char medlemmer[40];
    int  aar1, aar2;
  public:
    Band(char n[], char m[], int a1, int a2) 
       {  strcpy(navn, n);  strcpy(medlemmer, m);  aar1 = a1;  aar2 = a2;  }
    void skriv()   {  cout << aar1 << '-' << aar2; }
    void skriv2()  {  skriv();   cout << ": " << medlemmer;  }
    bool inneholderTeksten(const char t[])  { return (strstr(medlemmer, t)); }
    void funk(const char t[])               {  strcat(medlemmer, t);  }
    bool funk(Band b)  {  return (!strcmp(medlemmer, b.medlemmer));  }
};


int main()  {
  Band b1("Dire Straits 1", "MK-DK-JI-PW", 1977, 1980),
       b2("Dire Straits 2", "MK-HL-JI-AC-PW", 1980, 1982),
       b5("Dire Straits 5", "MK-JS-JI-AC-GF-TW", 1985, 1988);
  b5.skriv2();                                  cout << '\n';
  cout << "Alan Clark spilte "; if (!b1.inneholderTeksten("AC")) cout << "IKKE ";
  cout << "i DS i perioden ";   b1.skriv();     cout << '\n';
  cout << "Alan Clark spilte "; if (!b2.inneholderTeksten("AC")) cout << "IKKE ";
  cout << "i DS i perioden ";   b2.skriv();     cout << '\n';
  b5.funk("-CW-JdK");  b5.skriv2();             cout << '\n';
  if (b2.funk(b1))  cout << "DS\n"; else cout << "AFC\n";
  return 0;
}


//  Utskrift:  1985-1988: MK-JS-JI-AC-GF-TW
//             Alan Clark spilte IKKE i DS i perioden 1977-1980
//             Alan Clark spilte i DS i perioden 1980-1982
//             1985-1988: MK-JS-JI-AC-GF-TW-CW-JdK
//             AFC
