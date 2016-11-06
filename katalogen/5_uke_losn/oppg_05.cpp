//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_05.CPP


//   L›sningsforslag til oppgave nr.5  i   C++ -programmering.


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {
  char c1, c2, c3;                          //  Definerer fem hjelpe-
  float f1, f2;                             //    variable.

  cout << "Tast inn tre tegn: ";            //  Leser inn 3 tegn:
  cin >> c1 >> c2 >> c3;

                                            // Caster fra char til int:
  cout << "\n\nTegnet  \'" << c1 << "\'  sin ASCII-verdi er:  " << int(c1);
  cout <<   "\nTegnet  \'" << c2 << "\'  sin ASCII-verdi er:  " << int(c2);
  cout <<   "\nTegnet  \'" << c3 << "\'  sin ASCII-verdi er:  " << int(c3);

  cout << "\n\nTast inn flyttall nr.1:  ";    //  Leser 2 flyttall:
  cin >> f1;
  cout << "\nTast inn flyttall nr.2:  ";
  cin >> f2;
                                    //  Skriver heltallsdelen vha. casting:
  cout << "\n\nFlyttalet  " << f1 << "  har heltallsdelen:  " << int(f1);
  cout << "\nFlyttalet  " << f2 << "  har heltallsdelen:  " << int(f2) << '\n';

  return 0;
}
