//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S071B.CPP

//  L›sning til kontinuasjonseksamen i C++, 8.august 2007, oppgave 1B.
//  Laget av Frode Haug, HiG, mai 2007.


#include <iostream>
#include <cstring>

using namespace std;

class AA  {
  private:
    char nvn[10];
    int  nr;

  public:
    AA()                 {  strcpy(nvn, "");  nr = 3;      }
    AA(char t[], int n)  {  strcpy(nvn, t);   nr = n;  cout << t << ' ';  }
    void skriv()         {  cout << nvn << "\t#: " << nr;  }
    char funk1()         {  return (char(nvn[2]+2));       }
    bool funk2(AA a)     {  return(nvn[4] >= a.nvn[3]);    }
    AA   funk3(int n)    {  return (AA(nvn, nr*n/3));      }
};


int main()  {
  AA  k1, k2("Mildrid", 4), k3("Svanhild", 7);  cout << '\n';
  cout << k3.funk1();                           cout << '\n';
  cout << k3.funk2(k2);                         cout << '\n';
  k1 = k2.funk3(3);                             cout << '\n';
  cout << "K1: ";  k1.skriv();                  cout << '\n';
  return 0;
}


//  Utskrift:  Mildrid Svanhild
//             c
//             1
//             Mildrid
//             K1: Mildrid     #: 4