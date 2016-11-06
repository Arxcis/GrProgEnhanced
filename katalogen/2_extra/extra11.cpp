#include <iostream>
#include <iomanip>
using namespace std;

void skrivDato(int dag, int mnd, int aar);
void caDagnr(int d, int m);     //  2
int  caDagnr2(int d, int m);    //  3

int main()  {
  skrivDato(6, 4, 60);
  skrivDato(26, 5, 89);
  skrivDato(12, 2, 94);
  skrivDato(29, 9, 11);
  return 0;
}

void skrivDato(int dag, int mnd, int aar)  {
  cout << setw(2) << dag << ". ";
  switch (mnd)  {
	case  1:  cout <<  "januar";    break;
	case  2:  cout <<  "februar";   break;
	case  3:  cout <<  "mars";      break;
	case  4:  cout <<  "april";     break;
	case  5:  cout <<  "mai";       break;
	case  6:  cout <<  "juni";      break;
	case  7:  cout <<  "juli";      break;
	case  8:  cout <<  "august";    break;
	case  9:  cout <<  "september"; break;
	case 10:  cout <<  "oktober";   break;
	case 11:  cout <<  "november";  break;
	case 12:  cout <<  "desember";  break;
	default:  cout <<  "--FEIL--";  break;
  }
  cout << "  " << ((aar < 50)? "20" : "19") << aar
       << "\tca. dagnummer:  ";
 
//  1 - INNEBYGD KODE FOR "ANNET" OPPGAVE/GJØREMÅL:
  int i, dagnr = dag;
  for (i = 1; i < mnd;  i++)
	  dagnr += 30;
  cout << dagnr << '\n'; 

//  caDagnr(dag, mnd);                     //  2a

//  cout << caDagnr2(dag, mnd) << '\n';    //  3a
}


//  2b - FUNKSJON SOM REGNER UT OG SOM SELV SKRIVER UT:
void caDagnr(int d, int m)  {
  int i, dagnr = d;
  for (i = 1; i < m;  i++)
	  dagnr += 30;
  cout << dagnr << '\n';
}


//  3b - FUNKSJON SOM REGNER UT OG RETURNERER VERDI:
int caDagnr2(int d, int m)  {
  int i, dagnr = d;
  for (i = 1; i < m;  i++)
	  dagnr += 30;
  return dagnr;
}
