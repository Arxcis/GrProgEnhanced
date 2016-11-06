//  Fil:   FRODEH \ CPP \ EXTRAMEN \ EX_S041B.CPP

//  Løsning til kontinuasjonseksamen i C++, 12.august 2004, oppgave 1B.
//  Laget av Frode Haug, HiG, juni 2004.


#include <iostream>

using namespace std;
 
class B  {
  private:
    int  tall;
	char tegn;
  public:
    B()               {  tall = 123;  tegn = 'S';   skriv();    }
	B(int t, char c)  {  tall = t-19;    tegn =  c+2;           } 
	void skriv()      {  cout << tall << ' ' << tegn  << '\n';  }
    bool funk1(B b)   {  return (tegn <=  b.tegn);              }
    void funk2(int & t, char & c)  {  t = tall * 3 ;  c = char (tall/3);  }
    int  funk3()      {  return (tall % 4 * 12);                }
};


int main()  {
  B b1(321, 'q'), b2;
  int te;  char ch;


  b1.skriv();
  cout << b1.funk1(b2) << '\n';

  b1.funk2(te, ch);  cout << te << ' ' << ch << '\n';
  cout << b2.funk3() << '\n';

  cout << "\n\n";
  return 0;
}




//   Utskrift:
//      123 S
//      302 s
//      0
//      906 d
//      36
