//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_29.CPP


//   L›sningsforslag til oppgave nr.29  i   C++ -programmering.


//   Programmet trekker skriver tilfeldige bokstaver (A-Z)
//   til filen "BOKSTAV.DTA". 30 linjer med 80 tegn pr.linje.


#include <fstream>                     //  ofstream
#include <cstdlib>                     //  (s)rand

using namespace std;


const int ANTPRLIN = 80;
const int ANTLIN    = 30;


int main()  {
  int i, j;
  ofstream utfil("BOKSTAV.DTA");       //  Definerer og †pner fil.

  srand(0);                            //  Stiller p† tilfeldig tall.

  for (i = 0;  i < ANTLIN;  i++)  {    //   For alle linjene:
     for (j = 0;  j < ANTPRLIN;  j++)             //  For hver linje:
         utfil << char((rand() % 26)+int('A'));   //  Trekker bokstav A-Z.
     utfil << '\n';                               //  Ny linje.
  }
  return 0;
}

