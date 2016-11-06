//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_49.CPP

//   L›sningsforslag til oppgave nr.49  i   C++ -programmering.

//   Basert p† forslag/innspill fra Ole Johan Rasch.


//   Programmet looper gjennom en rekke med heltall.
//   Tallet skrives p† skjermen, evt. en erstattende tekst
//   om tallet er heltallig delelig med visse andre tall.


#include <iostream>          //  cout, cin
using namespace std;

const int MAX       =  45;   //  Siste tall i sekvensen det g†s gjennom.
const int DIVISOR1  =   3;   //  F›rste tall † dele med.
const int DIVISOR2  =   5;   //  Andre tall † dele med.


int main()  {
  int i;

  for (i = 1;  i <= MAX;  i++)  {                      //  G†r gjennom tallene:
      if (i % DIVISOR1 == 0  &&  i % DIVISOR2 == 0)    //  Delelig med begge:
         cout << "Pompel & Pilt";
      else if (i % DIVISOR1 == 0)                      //  Delelig med f›rste.
         cout << "Pompel";
      else if (i % DIVISOR2 == 0)                      //  Delelig med andre:
         cout << "Pilt";
      else
        cout << i;                                     //  Delelig med ingen:
      cout << '\n';
  }
  return 0;
}
