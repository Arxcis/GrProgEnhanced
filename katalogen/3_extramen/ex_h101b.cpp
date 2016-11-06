//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H101B.CPP

//  L›sning til eksamen i C++, 7.desember 2010, oppgave 1B.
//  Laget av Frode Haug, HiG, november 2010.


#include <iostream>
#include <cstring>

using namespace std;

const int LEN = 40;


class Klasse   {
  private:
    char txt[LEN];
	int  nr;
	bool jada;

  public:
	Klasse(char t[], int n)  {  strcpy(txt, t);  nr = n;  jada = bool(n % 2);  }
	void funk() { cout << nr << '-' << txt << ": " << ((jada) ? "ARS" : "TOT"); }
	bool funk(int n)         {  return( n >= 1  &&  n < 20);  }
	int  funk(char t[])      {  return ((strlen(txt) + strlen(t)) / 2); }
};


int main()  {
    Klasse ob1("Vinner", 20),  ob2("Taper", 1);
	ob1.funk();  cout << "   ";  ob2.funk();  cout << '\n';
    cout << ob1.funk(20)  << ' ' << ob2.funk(1) << '\n';
    cout << ob1.funk("ABCD")  << ' ' << ob2.funk("ABC") << '\n';
    cout << ob1.funk("EMIRATES")  << ' ' << ob2.funk("STADIUM") << '\n';
    cout << ob2.funk(ob1.funk("TOTTENHAM-HOTSPURS-TAPER-IGJEN-OG-IGJEN")) << '\n';
	return 0;
}



//  Utskrift:  20-Vinner: TOT   1-Taper: ARS
//             0 1
//             5 4
//             7 6
//             0
