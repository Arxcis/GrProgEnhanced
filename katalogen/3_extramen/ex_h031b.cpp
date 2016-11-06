//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H031B.CPP

//  Løsning til eksamen i C++, 15.desember 2003, oppgave 1B.
//  Laget av Frode Haug, HiG, november 2003.


#include <iostream>

using namespace std;
 
class A  {
  private:
    int  tall;
	char tegn;
  public:
    A()               {  tall = 99;  tegn = 'w';   skriv();    }
	A(int t, char c)  {  tall = t;   tegn =  c-2;              } 
	void skriv()      {  cout << tall << ' ' << tegn  << '\n'; }
    bool funk1(A a)   {  return (tegn == a.tegn);              }
    void funk2(int & t, int & c)  {  t = tall/3;  c = int(tegn);  }
    int  funk3()      {  return (tall + 6 / 3 * 4);            }
};


int main()  {
  A a1, a2(66, 'y');
  int te, ch;

  a2.skriv();
  cout << a1.funk1(a2) << '\n';

  a1.funk2(te, ch);  cout << te << ' ' << ch << '\n';
  cout << a2.funk3() << '\n';

  cout << "\n\n";
  return 0;
}




//   Utskrift:
//      99 w
//      66 w
//      1
//      33 119
//      74
