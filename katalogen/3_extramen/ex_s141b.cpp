//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S141B.CPP

//  Løsning til kontinuasjonseksamen i C++, 8.august 2014, oppgave 1B.
//  Laget av Frode Haug, HiG, juli 2014.


#include <iostream>
#include <cstring>
using namespace std;

class Klasse  {
  private:
    char txt1[20], txt2[20];
    int  int1, int2;
  public:
    Klasse(char t1[], char t2[])
      {  strcpy(txt1, t1);  strcpy(txt2, t2);  int1 = 304;  int2 = int1 + 8;  }
    Klasse(char t1[], char t2[], int i1, int i2)
      {  strcpy(txt1, t2);  strcpy(txt2, t1);  int1 = i1;   int2 = i2;  }
    void funk(int n)  
      {  cout << ((n == 1) ? txt1 : txt2) << ' ' << ((n == 1) ? int1 : int2);  }
    bool funk(char t[])       {  return (!strcmp(txt1, t));  }
    int  funk(int n, int m)   {  return ((n > m) ? n : int1);  }
};


int main()  {
  Klasse  k1("Blindern", "Lahaugmoen"),  k2("Liverpool", "Arsenal", 3, 1);
  k1.funk(1);    cout << "  ";   k1.funk(2);   cout << '\n';
  k2.funk(2);    cout << "  ";   k2.funk(1);   cout << '\n';
  cout << k1.funk("Arsenal") << '\n';
  cout << k2.funk("Arsenal") << '\n';
  cout << k2.funk(4, 2) << ' ' << k1.funk(304, 308) << '\n';
  return 0;
}


//  Utskrift:  Blindern 304  Lahaugmoen 312
//             Liverpool 1  Arsenal 3
//             0
//             1
//             4 304
