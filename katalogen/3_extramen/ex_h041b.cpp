//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H04_1B.CPP

//  Løsning til eksamen i C++, 21.desember 2004, oppgave 1B.
//  Laget av Frode Haug, HiG, desember 2004.


#include <iostream>
#include <cstring>
using namespace std;

class A  {
  private:
	char txt[20];
    int  tall;
  public:
    A()                 {  strcpy(txt, "GOSSINGUTT");  tall = 44;  skriv(); }
	A(char t[], int ta) {  strcpy(txt, t); tall = ta;             } 
	void skriv()        {  cout << txt << '\t' << tall  << '\n';  }
    bool funk1(char c)  {  return (txt[0] == c);         }
    char funk2()        {  return (txt[2]);              }
    char funk3(int n)   {  return (char(int(txt[2])+n));  }
};

int main()  {
    A a1, a2("SLAPPFISK", 19);
	a2.skriv();

    cout << a1.funk1('S') << '\n';

    cout << a2.funk1(a1.funk2()) << '\n';

	cout << a1.funk3(5) << '\n';
	return 0;
}


//  Utskrift:  GOSSINGUTT      44
//             SLAPPFISK       19
//             0
//             1
//             X
