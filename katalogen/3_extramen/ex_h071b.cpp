//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H071B.CPP

//  L›sning til eksamen i C++, 20.desember 2007, oppgave 1B.
//  Laget av Frode Haug, HiG, desember 2007.


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
	CC()                    { strcpy(txt1, "CC");  strcpy(txt2, txt1);  nr = 99;  }
    CC(char s[], char t[])  { strcpy(txt1, s);     strcpy(txt2, t);     nr = 22;  }
    void funk()             { cout << txt1 << "  " << txt2 << "  " << nr << '\n'; }
    void funk(int n, char s[])  { if (n==1)  strcpy(txt1, s); else strcpy(txt2, s); }
    void funk(char s[], int n)  { if (n==1)  strcpy(s, txt1); else strcpy(s, txt2); }
    bool funk(char s[])     { return (!strcmp(s, txt1)  ||  !strcmp(s, txt2));    }
    char funk(int n)        { return txt1[n % 2]; }
};


int main()  {
  char txt[LEN];
  CC c1, c2("AA", "BB"), c3("BB", "CC");
  c2.funk();
  c1.funk(22, "AA");  c1.funk();
  c3.funk(txt, 22);   cout << txt << '\n';
  cout << c2.funk("CC") << ' ' << c1.funk("AA") << ' ' << c3.funk("AA") << '\n';
  cout << c3.funk(19)   << ' ' << c2.funk(70)   << ' ' << c1.funk(153)  << '\n';

  return 0;
}



//  Utskrift:  AA  BB  22
//             CC  AA  99
//             CC
//             0 1 0
//             B A C