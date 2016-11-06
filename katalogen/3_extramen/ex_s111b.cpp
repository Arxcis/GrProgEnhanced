//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S111B.CPP

//  L›sning til kontinuasjoneksamen i C++, 11.august 2011, oppgave 1B.
//  Laget av Frode Haug, HiG, mai 2011.


#include <iostream>
#include <cstring>

using namespace std;

const int LEN = 40;


class Klasse   {
  private:
    char txt[LEN];
	int  tall;
	bool svar;

  public:
	Klasse(char t[], int n)  {  strcpy(txt, t);  tall = n%3;  svar = (n%2);  }
	void funk() { cout << tall << '-' << txt << ": " << ((!svar) ? "AA" : "BB"); }
	bool funk(int n)         {  return (n <= 28  &&   n > 20);  }
	int  funk(char t[])      {  return (strlen(t) * 4 / 3); }
};


int main()  {
    Klasse ob1("EMIRATES", 20),  ob2("STADIUM", 7);
	ob1.funk();  cout << "   ";  ob2.funk();  cout << '\n';
    cout << ob2.funk(20)  << ' ' << !ob1.funk(28) << '\n';
    cout << ob1.funk("STADIUM")  << ' ' << ob2.funk("EMIRATES") << '\n';
    cout << !ob1.funk((57%25)*4+1)  << ' ' << ob2.funk("CUP") << '\n';
    cout << ob2.funk(ob1.funk("DEILIG-PÅ-ARSENALKAMP-IGJEN")) << '\n';
	return 0;
}



//  Utskrift:  2-EMIRATES: AA   1-STADIUM: BB
//             0 0
//             9 10
//             1 4
//             0
