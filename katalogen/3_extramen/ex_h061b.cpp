//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H061B.CPP

//  L›sning til eksamen i C++, 20.desember 2006, oppgave 1B.
//  Laget av Frode Haug, HiG, desember 2006.



#include <iostream>
#include <cstring>

using namespace std;

class AA  {
  private:
    char nvn[10];
    int  nr;

  public:
    AA()                 {  strcpy(nvn, "");  nr = 0;      }
    AA(char t[], int n)  {  strcpy(nvn, t);   nr = n;  cout << t << ' ';  }
    void skriv()         {  cout << nvn << "\t#: " << nr;  }
    char funk1()         {  return (char(nvn[4]+4));       }
    bool funk2(AA a)     {  return(nvn[1] == a.nvn[1]);    }
    AA   funk3(int n)    {  return (AA(nvn, nr*n));        }
};


int main()  {
  AA  k1, k2("Petter", 1), k3("Henning", 7);   cout << '\n';
  cout << k3.funk1();                          cout << '\n';
  cout << k3.funk2(k2);                        cout << '\n';
  k1 = k2.funk3(3);                            cout << '\n';
  cout << "K1: ";  k1.skriv();                 cout << '\n';
  return 0;
}


//  Utskrift:  Petter Henning
//             m
//             1
//             Petter
//             K1: Petter      #: 3
