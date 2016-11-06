//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_52.CPP

//   L›sningsforslag til oppgave nr.52  i   C++ -programmering.

//   Basert p† forslag/innspill fra Simen Gr›ndahl.


//   Programmet skriver fortl›pende tall fra 1 og oppover. Det skrives
//   10 og 10 tall ad gangen, til brukeren ikke ›nsker dette mer.


#include <iostream>
using namespace std;

int main()  {
  int i, j;
  char fortsette;

				//  Versjon 1 (der bruker % og break):
  for (i = 1;  i > 0;  i++)  {                //  "Evig"(!) for-l›kke:
      cout << i << '\n';                      //  Skriver tallet ('i').
      if (i % 10 == 0)  {                     //  Stanser for hver tiende:
         cout <<"Kj›re videre/mer (J/n): ";   //  Sp›r brukeren:
         cin >> fortsette;
         if (fortsette == 'n')  break;        //  Avbyter/hopper ut av l›kken. 
      }
  }
  cout << "\n\n\n";

				//  Versjon 2 (der IKKE bruker % og break):
  i = 1;  j = 0;                              //  Initierer variable - VIKTIG!
  do  {
     j++;                                     //  Neste 10-intervall.
     for ( ;  i <= 10*j;  i++)                //  NB:  L›kkeinnholdet!
         cout << i << '\n';                   //  Skriver 10 tall.
     cout <<"Kj›re videre/mer (J/n): ";       //  Sp›r brukeren:
     cin >> fortsette;
  } while (fortsette != 'n');                 //  Fortsette eller ei.

  cout << "\n\n\n";
  return 0;
}
