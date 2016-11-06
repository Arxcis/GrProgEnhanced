//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_11.CPP


//   L›sningsforslag til oppgave nr.11  i   C++ -programmering.


//   NB: Dette programmet vil nok prim‘rt kun kj›res p† Windows-plattformer,
//       da det "m†" benytte seg av conio.h (som IKKE er standard C++).


#include <iostream>

using namespace std;

#include <conio.h>


int main()  {
  char ch = 'a';                            //  Sikre at ikke er '\r'.
  int antSiff = 0;                          //  Antall innleste sifre = 0.   
  int total = 0;                            //  Inneholder innlest tall.

  cout << "Tast inn et tall:  ";

  ch = getche();
  while (ch != '\r'  &&  antSiff < 9)  {    //  Leser tegn inntil ENTER
                                            //     eller lest 9 stykker.
    if (ch >= '0'  &&  ch <= '9')  {        //  Dersom lovlig siffer 0-9:
       ++antSiff;                           //  Teller opp antall siffer
       total = total * 10  + (ch - '0');    //  Beregner ny tallverdi.
    }
    ch = getche();
  }
  cout << "\nTallet er:  " << total << '\n';
  
  return 0;
}
