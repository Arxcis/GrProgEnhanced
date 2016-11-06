//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S161B.CPP

//  L›sning til kontinuasjonseksamen i C++, august 2016, oppgave 1B.
//  Laget av Frode Haug, NTNU


#include <iostream>
#include <cstring>
using namespace std;

class Hytte  {
  private:
	char sted[20];
	int  pnr;

  public:
	Hytte(char s[], int p)  {  strcpy(sted, s);  pnr = p;  }
	void  funk()  {  cout << sted << ',' << pnr;  }
	void  funk(int i, int j, bool fa)  {  cout << ((fa) ? sted[i] : sted[j]);  }
	Hytte funk(Hytte h)  { return (Hytte(h.sted, pnr - h.pnr)); }
	char  funk(int a, int b = 4)  { return (sted[a - 2*b]); }
	int   funk2()  { return (pnr % 100); }
};


int main()  {
	Hytte h1("Mysuseter", 2674), h2("Lom", 2686), h3("Ustaoset", 3539);
	h1.funk();  cout << ' ';  h2.funk(); cout << ' '; h3.funk(); cout << '\n';
	cout << h2.funk2() - h1.funk2() << '\n';
	h3.funk(5, 2, true);  cout << ' ';  h2.funk(5, 2, false);  cout << '\n';
	Hytte h4 = h2.funk(h1);  h4.funk();  cout << '\n';
	cout << h1.funk(10, 3) << ' ' << h3.funk(13) << '\n';
	return 0;
}


//  Utskrift:  Mysuseter,2674 Lom,2686 Ustaoset,3539
//             12
//             s m
//             Mysuseter,12
//             s s
