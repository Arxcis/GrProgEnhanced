//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S081B.CPP

//  L›sning til kontinuasjonseksamen i C++, 12.august 2008, oppgave 1B.
//  Laget av Frode Haug, HiG, mai 2008.


#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 10;

class CC  {
  private:
    char txt1[LEN];
	char txt2[LEN];
    int  nr;

  public:
	CC()                    { strcpy(txt1, "SS");  strcpy(txt2, txt1);  nr = 33;  }
    CC(char s[], char t[])  { strcpy(txt1, s);     strcpy(txt2, t);     nr = 77;  }
    void funk()             { cout << txt2 << "  " << txt1 << "  " << nr << '\n'; }
    void funk(int n, char s[])  { if (n==0)  strcpy(txt2, s); else strcpy(txt1, s); }
    void funk(char s[], int n)  { if (n==1)  strcpy(s, txt1); else strcpy(s, txt2); }
    bool funk(char s[])     { return (strcmp(s, txt1)  &&  strcmp(s, txt2));      }
    char funk(int n)        { return txt1[n % 3]; }
};


int main()  {
  char txt[LEN];
  CC c1, c2("II", "LL"), c3("SS", "II");
  c2.funk();
  c1.funk(17, "LL");  c1.funk();
  c3.funk(txt, 19);   cout << txt << '\n';
  cout << c2.funk("II") << ' ' << c1.funk("LL") << ' ' << c3.funk("LL") << '\n';
  cout << c3.funk(21)   << ' ' << c2.funk(52)   << ' ' << c1.funk(151)  << '\n';

  return 0;
}



//  Utskrift:  LL  II  77
//             SS  LL  33
//             II
//             0 0 1
//             S I L