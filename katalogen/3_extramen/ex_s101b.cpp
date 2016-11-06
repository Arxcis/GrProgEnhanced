//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S101B.CPP

//  L›sning til kontinuasjonseksamen i C++, 13.august 2010, oppgave 1B.
//  Laget av Frode Haug, HiG, mai 2010.


#include <iostream>
#include <cstring>
using namespace std;


class Klasse  {
  private:
    char text[40];  int nr1, nr2;
  public:
    Klasse(char t[], int n1, int n2)  {  strcpy(text, t);  nr1 = n1;  nr2 = n2;  }
    void display()  {  cout << text << ": " << nr1 << ' ' << nr2 << ' ';  }
    void sett(int n, int m)  { if (m == 1)  nr1 = n;  else nr2 = n;  }
    bool funk()     {  return (nr1 <= nr2);  }
    int  funk(int n){  return (nr2 - n);     }
};


int main()  {
  Klasse k1("K1", 11, 31), k3("K3", 32, 22), k2("K2", 33, 21);
  k1.display();    k2.display();   k3.display();  cout << '\n';
  k2.sett(11, 2);  k2.display();   cout << '\n';
  cout << k1.funk()  << ' ' << k3.funk() << '\n';
  cout << k2.funk(10) << ' ' << k3.funk(19) << '\n';
  k3.sett(22, 1);  k2.sett(10, 1);
  cout << k1.funk(k2.funk()) << ' ' << k2.funk(k3.funk()) << '\n';
  return 0;
}



//  Utskrift:  K1: 11 31 K2: 33 21 K3: 32 22
//             K2: 33 11
//             1 0
//             1 3
//             30 10
