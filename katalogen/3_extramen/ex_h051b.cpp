//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H05_1B.CPP

//  Løsning til eksamen i C++, 19.desember 2005, oppgave 1B.
//  Laget av Frode Haug, HiG, desember 2005.


#include <iostream>
#include <cstring>
using namespace std;

enum Type { Taper, Vinner };

class Lag  {
  private:
    char navn[10];
	Type type;

  public:
	Lag()                   {  strcpy(navn, "Arsenal");  type = Vinner;        }
    Lag(char t[], Type tt)  {  strcpy(navn, t);  type = tt;                    }
	void skriv() { cout << navn << " - " << ((type==Vinner)? "Vinner" : "Taper") << '\n'; }
    char funk1()            {  return (char(navn[3]+3));                       }
	bool funk2(Lag l)       {  return (navn[5] == l.navn[1]);                  }
    void funk3()            {  strcat(navn, "UU-UUU");  cout << navn << '\n';  }
};


int main()  {
  Lag lag1, lag2("ManU", Taper);
  lag2.skriv();    lag1.skriv();
  cout << lag2.funk1() << '\n';
  if (lag1.funk2(lag2)) cout << "2-0\n"; else cout << "3-0\n";
  lag2.funk3();
  return 0;
}


//  Utskrift:  ManU - Taper
//             Arsenal - Vinner
//             X
//             2-0
//             ManUUU-UUU
