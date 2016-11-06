//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S091B.CPP

//  L›sning til kontinuasjonseksamen i C++, 14.august 2009, oppgave 1B.
//  Laget av Frode Haug, HiG, mai 2009.


#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 30;

char txt[4][LEN] = { "Arsenal", "Rangers", "Atletico Madrid", "Paris Saint-Germain" };

class Lag   {
  private:
    char txt[LEN];
    int  nr;

  public:
    Lag()                {  strcpy(txt, "");  nr = 0;  }
    Lag(char t[], int n) {  strcpy(txt, t);   nr = n;  }
    void funk()          {  cout << nr << ": " << txt << '\n';  }
    bool funk(char t[])  {  return (!strcmp(txt, t));  }
    int  funk(int n, int m =2)  { return (nr += (n*m));  }
};


int main()  {
  Lag l1(txt[0], 1), l2(txt[1], 2), l3(txt[2], 3), l4(txt[3], 4), l5;
  l2.funk();
  l5 = l1;  l1 = l3;  l3 = l5;
  l3.funk();
  cout << ( (l1.funk("Arsenal")) ? "!!!" : ":-(" ) << '\n';
  cout << l2.funk(4, 5) << '\n';
  cout << l4.funk(10)   << '\n';
  return 0;
}



//  Utskrift:  2: Rangers
//             1: Arsenal
//             :-(
//             22
//             24
