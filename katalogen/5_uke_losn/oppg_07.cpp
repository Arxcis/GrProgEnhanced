//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_07.CPP


//   L›sningsforslag til oppgave nr.7  i   C++ -programmering.


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {
  const float PI    = 3.14159F;              //  Definerer aktuelle variable
  const int   HOYDE = 4;
  int radie;

  for (radie = 1;  radie <= 20;  radie++)   //  L›kken gjennom alle radier
    cout << "Sylinder med radie" << setw(4) << radie    // Utskrift med
         << "  og h›yde lik  " << HOYDE << "  har volumet:  " //  tekst og
         << PI * radie * radie * HOYDE << '\n';         //   volumberegning.
  return 0;
}
