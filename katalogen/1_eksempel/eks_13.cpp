//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_13.CPP

//   Programeksempel nr.13 for forelesning i  C++ -programmering. 

//   Program som utfra et ›re-bel›p omgj›r dette til andre pengeenheter.


#include <iostream>
#include <iomanip>

using namespace std;


enum Penger  { femtiore = 50,  krone = 100,       femmer = 500,
               tier = 1000,    femtilapp = 5000,  hundrelapp = 10000  };

int main()  {
  int orer, hele, rest;

  cout << "Skriv inn et bel›p i ›rer:  ";
  cin >> orer;

  hele = orer / hundrelapp;        //  Finner hvor mange hundrelapper.
  cout << "\nDette er " << setw(6) << hele << "  hundrelapp(er)";
  rest = orer % hundrelapp;        //  Finner hvor mye til overs.
  hele = rest / femtilapp;         //  Finner hvor mange femtilapper.
  cout << "\nDette er " << setw(6) << hele << "  femtilapp(er)";
  rest %= femtilapp;               //  Finner hvor mye til overs.

  hele = rest / tier;              //  Finner hvor mange tiere.
  cout << "\nDette er " << setw(6) << hele << "  tier(e)";
  rest %= tier;                    //  Finner hvor mye til overs.

  hele = rest / femmer;            //  Finner hvor mange femmere.
  cout << "\nDette er " << setw(6) << hele << "  femmer(e)";
  rest %= femmer;                  //  Finner hvor mye til overs.

  hele = rest / krone;             //  Finner hvor mange kronestykker.
  cout << "\nDette er " << setw(6) << hele << "  kronestykke(r)";
  rest %= krone;                   //  Finner hvor mye til overs.

  hele = rest / femtiore;          //  Finner hvor mange femti›rer.
  cout << "\nDette er " << setw(6) << hele << "  femti›re(r)";
  rest %= femtiore;                //  Finner hvor mye til overs.

  cout << "\nRest:    " << setw(6) << rest << "  ›re(r)\n";

  return 0;
}
