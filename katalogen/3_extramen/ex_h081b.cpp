//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H081B.CPP

//  L›sning til eksamen i C++, 2.desember 2008, oppgave 1B.
//  Laget av Frode Haug, HiG, november 2008.


#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 40;


class Foo   {
  private:
    char txt[LEN];
    int  nr;

  public:
    Foo()                 {  nr = 0;  strcpy(txt, "NULL");  }
    Foo(int n, char t[])  {  nr = n;  strcpy(txt, t);  }
    void funk()           {  cout << nr << ": " << txt << '\n';  }
    bool funk(int n)      {  return (nr != n);  }
    void funk(char s[], char t[]) 
	  { if (funk(2001)) strcpy(txt, t);  else  strcpy(txt, s); }
};


int main()  {
  Foo o1, o3(2006, "2x Highbury"), o2(1989, "QPR"), o5, o4(2001, "Sommer");  
  o2.funk();  o3.funk();
  o5 = o2;  o1 = o3;  o3= o4;  o2 = o1;  o3 = o5;  o1 = o4;  
  o1.funk();
  cout << o2.funk(2006) << ' ' << o3.funk(2006) << ' ' << o4.funk(2001) << '\n';
  o1.funk("Ferie", "Opphold");  o1.funk();
  return 0;
}



//  Utskrift:  1989: QPR
//             2006: 2x Highbury
//             2001: Sommer
//             0 1 0
//             2001: Ferie
