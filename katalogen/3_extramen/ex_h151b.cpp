//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H151B.CPP

//  L›sning til eksamen i C++, 1.desember 2015, oppgave 1B.
//  Laget av Frode Haug, HiG, november 2015.


#include <iostream>
#include <cstring>
using namespace std;


class Skole  {
  private:
	char nn[60];
	int  antall;
  public:
	Skole(char n[], int a)  { strcpy(nn, n);  antall = a; }
	void  funk()  { cout << nn << ": " << antall;  }
	void  funk(Skole s1, Skole s2)  {  antall += (s1.antall + s2.antall);  }
	Skole funk(Skole s)  {  return (Skole(s.nn, antall));  }
	bool  funk(int a, int b)  {  return (antall < a  ||  antall > b);  }
	void  funk(Skole s1, Skole s2, Skole s3, Skole s4)  {  strcat(nn, " = ");  
	     strcat(nn, s4.nn); strcat(nn, "+"); strcat(nn, s2.nn); strcat(nn, "+");
		 strcat(nn, s1.nn); strcat(nn, "+"); strcat(nn, s3.nn);  }
};


int main()  {
	Skole s0("", 0),  s1("NTNU", 23000),  s2("HiG", 3500),  
		  s3("HiAls", 2200), s4("HiST", 9000),  s5("NTNY", 0);
	s2.funk();    cout << "  ";   s4.funk();		cout << '\n';
	s5.funk(s1, s3);  s5.funk(s4, s2);  s5.funk();	cout << '\n';
	s0 = s5.funk(s1); s0.funk();					cout << '\n';
	cout << s3.funk(2500, 9000) << "  " << s2.funk(3500, 9000) << '\n';
	s5.funk(s3, s4, s2, s1);   s5.funk();			cout << '\n';
	return 0;
}


//  Utskrift:  HiG: 3500  HiST: 9000
//             NTNY: 37700
//             NTNU: 37700
//             1  0
//             NTNY = NTNU+HiST+HiAls+HiG:  37700
