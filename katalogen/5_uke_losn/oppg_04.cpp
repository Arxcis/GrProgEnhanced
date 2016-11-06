//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_04.CPP


//   L›sningsforslag til oppgave nr.4  i   C++ -programmering.


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {

  int  t1, t2, t3;                          //  Definerer seks hjelpevariable
  int  kv1, kv2, kv3;

  cout << "Skriv inn heltall nr.1:  ";   cin >> t1;   //  Prompting og
  cout << "Skriv inn heltall nr.2:  ";   cin >> t2;   //    innlesing av
  cout << "Skriv inn heltall nr.3:  ";   cin >> t3;   //    tre verdier.

  kv1 = t1 * t1;                            //  Kvadrerer innleste verdier.
  kv2 = t2 * t2;
  kv3 = t3 * t3;
                                            // Utskrift av kvadratene:
  cout << "\n\nKvadratet av" << setw(6) << t1 << "  er:" << setw(12) << kv1;
  cout <<   "\nKvadratet av" << setw(6) << t2 << "  er:" << setw(12) << kv2;
  cout <<   "\nKvadratet av" << setw(6) << t3 << "  er:" << setw(12) << kv3 << '\n';

                                            // Utskrift av summer
                                            //   og gjennomsnitt:
  cout << "\n\nSummen av tallene er:       " << setw(12) << t1 + t2 + t3;
  cout << "\nSummen av kvadratene er:    " << setw(12) << kv1 + kv2 + kv3;
  cout << "\nGj.snittet av tallene er:   " << setw(12) << (t1+t2+t3)/3;
  cout << "\nGj.snittet av kvadratene er:" << setw(12) << (kv1+kv2+kv3)/3;
   
  return 0;
}  
