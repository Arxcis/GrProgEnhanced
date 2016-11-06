//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_06.CPP


//   L›sningsforslag til oppgave nr.6  i   C++ -programmering.


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {

  cout << "\t\tKamper\tSeire\tUavgj.\tTap\tPoeng\n";
  cout << "STORHAMAR\t"   << setw(4) << "18"
       << setw(8) << "14" << setw(8) << "1"
       << setw(8) << "3"  << setw(8) << "29" << '\n';
  cout << "Lillehammer\t" << setw(4) << "18"
       << setw(8) << "12" << setw(8) << "4"
       << setw(8) << "2"  << setw(8) << "28" << '\n';
  cout << "Stavanger\t"   << setw(4) << "18"
       << setw(8) << "10" << setw(8) << "3"
       << setw(8) << "5"  << setw(8) << "23" << '\n';
  cout << "VIF Hockey\t"  << setw(4) << "18"
       << setw(8) << "10" << setw(8) << "2"
       << setw(8) << "6"  << setw(8) << "22" << '\n';
  cout << "\nGRATULERER MED SERIEMESTERSKAPET, STORHAMAR !!\n\n";
  return 0;
}
