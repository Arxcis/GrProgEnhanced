//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_S05_1B.CPP

//  Løsning til kontinuasjonseksamen i C++, 9.august 2005, oppgave 1B.
//  Laget av Frode Haug, HiG, juni 2005.


#include <iostream>
#include <cstring>
using namespace std;

class A  {
  private:
    char txt[20];
    int  tall;
  public:
    A()                 {  strcpy(txt, "BANAN-MATHIESEN");  tall = 44;   }
    A(char t[], int ta) {  strcpy(txt, t);  tall = ta;  skriv();  } 
    void skriv()        {  cout << txt << '\t' << tall  << '\n';  }
    bool funk1(char c)  {  return (txt[4] == char(int(c)+2));     }
    char funk2()        {  return (txt[6]);               }
    char funk3(int n)   {  return (char(int(txt[2])+n));  }
};


int main()  {
    A a1, a2("MAKRELLSTIMEN", 45);
    a1.skriv();

    cout << a1.funk1('L') << '\n';

    cout << a1.funk1(a2.funk2()) << '\n';

    cout << a2.funk3(3) << '\n';
    return 0;
}


//  Utskrift:  MAKRELLSTIMEN    45
//             BANAN-MATHIESEN  44
//             1
//             1
//             N
