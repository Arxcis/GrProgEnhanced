//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H141B.CPP

//  L›sning til eksamen i C++, 2.desember 2014, oppgave 1B.
//  Laget av Frode Haug, HiG, november 2014.


#include <iostream>
#include <cstring>
using namespace std;


class Lag  {
  private:
    char navn[20];
    char bane[30];
    int kapasitet;
    
  public:
    Lag(char n[], char b[], int k) 
                  { strcpy(navn, n);  strcpy(bane, b);  kapasitet = k; }
    void skriv()  { cout << navn << ": " << bane << " (" << kapasitet << ')'; }
    bool mindre(Lag l)     {  return (kapasitet < l.kapasitet);  }
    void skjot(char t[])   {  strcat(bane, t);  }
    bool finnes(char t[])  {  return (strstr(bane, t));  }
    Lag  mix(Lag l)  {  return Lag(navn,  l.bane,  kapasitet + l.kapasitet);  }
};


int main()  {
  Lag lag1("Ipswich", "PortmanRoad", 30300),  lag2("Leeds", "EllanRoad", 39460),
      lag3("WestHam", "BoleynGround", 35300);
  lag1.skriv();  cout << "   ";   lag3.skriv();   cout << '\n';  
  if (lag2.mindre(lag3))  cout << "Arsenal\n";  else  cout << "Chelsea\n";
  cout << lag1.finnes("Road") << ' ' << lag3.finnes("Road") << '\n';
  lag3.skjot("/UptonPark");   lag3.skriv();  cout << '\n';
  Lag lag4 = lag3.mix(lag1);  lag4.skriv();  cout << '\n';
  return 0;
}


//  Utskrift:  Ipswich: PortmanRoad (30300)   WestHam: BoleynGround (35300)
//             Chelsea
//             1 0
//             WestHam: BoleynGround/UptonPark (35300)
//             WestHam: PortmanRoad (65600)