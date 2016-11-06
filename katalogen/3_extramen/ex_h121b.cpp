//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H121B.CPP

//  L›sning til eksamen i C++, 4.desember 2012, oppgave 1B.
//  Laget av Frode Haug, HiG, november 2012.


#include <iostream>
#include <cstring>
using namespace std;

enum Form  {  kvadratisk, oval  };

class Bane  {
  private:
    char navn[20];
    Form form;
    int  ant;
  public:
    Bane(char t[], Form f, int a)  {  strcpy(navn, t);  form = f;  ant = a;  }
    void skriv()                   {  cout << navn << ": " << ant;  }
    bool erLik(Form f)             {  return (form == f);           }
    int  funk(int i = 6000)        {  return (ant % i == 0);        }
    void funk(char t[])            {  strcat(navn, t);              }
    bool funk(char t[], char ch)   {  return (strcmp(navn, t));     }
};

int main()  {
  Bane gammel("Highbury", kvadratisk, 38000),  ny("Emirates", oval, 60000);
  gammel.skriv();  cout << "  ";  ny.skriv();  cout << '\n';
  if (gammel.erLik(oval)) cout << "O'hval\n"; else cout << "NorthBank\n";
  cout << gammel.funk(5000) << ' ' << ny.funk() << '\n';
  ny.funk("Stadium");  ny.skriv();  cout << '\n';
  cout << gammel.funk("Highbury", 'F') << ' ' << ny.funk("Highbury", 'H') << '\n';
  return 0;
}


//  Utskrift:  Highbury: 38000  Emirates: 60000
//             NorthBank
//             0 1
//             EmiratesStadium: 60000
//             0 1
