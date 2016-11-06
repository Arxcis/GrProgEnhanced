//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H111B.CPP

//  L›sning til eksamen i C++, 6.desember 2011, oppgave 1B.
//  Laget av Frode Haug, HiG, november 2011.


#include <iostream>
#include <cstring>

using namespace std;

const int LEN = 20;

class Objekt  {
  private:
    char txt[LEN];
	char tegn;
	int  tall;
  public:
	Objekt(char tx[], char te, int ta) 
		                {  strcpy(txt, tx);  tegn = te;  tall = ta;  }
	void funk1()        {  cout << txt << ' ' << tegn << ' ' << tall;  }
	bool funk2(char te, int n1, int n2) 
	                    {  return (txt[n1] == te  ||  txt[n2] == te);  }
	char funk3()        {  return (char(int(tegn) + tall));  }
	void funk4(int ta)  {  tall = ta;  }
};

int main()  {
  Objekt ob1("Arsenal", 'A', 5), ob2("Chelsea", 'H', 3);
  ob2.funk1();  cout << "   ";  ob1.funk1();  cout << '\n';
  cout << ob2.funk2('e', 3, 6) << '\n';
  cout << ob1.funk2('a', 0, 5) << ' ' << ob2.funk2('E', 2, 5) << '\n';
  cout << ob2.funk3() << ' ' << ob1.funk3() << '\n';
  ob2.funk4(-7);  cout << ob1.funk2(ob2.funk3(), 0, 1) << '\n';
  return 0;
}


//  Utskrift:  Chelsea H 3   Arsenal A 5
//             0
//             1 0
//             K F
//             1
