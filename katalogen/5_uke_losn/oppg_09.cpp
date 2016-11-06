//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_09.CPP


//   L›sningsforslag til oppgave nr.9  i   C++ -programmering.



#include <iostream>
#include <iomanip>

using namespace std;


int main()  {
  int tall1, tall2;                         //  Definerer 3 variable.
  char svar;

  do  {
    cout << "Skriv inn tall nr.1:  ";       //  Leser inn 2 verdier:
    cin >> tall1;
    cout << "Skriv inn tall nr.2:  ";
    cin >> tall2;
                                            //  Utskrifter med beregning:
    cout << "\n\n" << setw(6) << tall1 << "  +"
         << setw(8) << tall2 << " =" << setw(10) << tall1+tall2;
    cout << "\n\n" << setw(6) << tall1 << "  -"
         << setw(8) << tall2 << " =" << setw(10) << tall1-tall2;
    cout << "\n\n" << setw(6) << tall1 << "  *"
         << setw(8) << tall2 << " =" << setw(10) << tall1*tall2;

    cout << "\n\nVil du fortsette (j/N):  ";    //  Ber om brukerens respons.
    cin >> svar;
  } while (svar == 'j');                  //  Looper s†lenge brukeren ›nsker.
  return 0;
}
