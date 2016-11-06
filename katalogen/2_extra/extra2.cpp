#include <iostream>
#include <cctype>

using namespace std;

int main()  {
  char svar;
  int pounds, shilling, pence;


  do  {
	 cout << "Pounds: ";   cin >> pounds;
	 while (pounds < 0)  {
		cout << "Pounds (positivt tall): ";   cin >> pounds;
	 }

     do {
	    cout << "Shilling (0-19): ";   cin >> shilling;
     } while (shilling < 0 || shilling > 19);

     do {
   	    cout << "Pence (0-11): ";   cin >> pence;
     } while (pence < 0 || pence > 11);

//  LATER:   MÅ gjøre utregning !

	  cout << "\nIgjen (J/n): ";   cin >> svar;
	  svar = toupper(svar);
  } while (svar != 'N');
//  } while (svar != 'n' && svar !='N');
  cout << "\n\nFerdig !  Kom og t›rk!\n\n";
  return 0;
}
