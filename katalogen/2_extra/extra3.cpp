#include <iostream>

using namespace std;


struct gruppe {
  char  kode;
  float pris;
};


int main()  {
  char kommando;
  int nr;
  gruppe gr, gr1, gr2 = { 'G', 23.90F };

//  cout << "\nGr1:  " << gr1.kode << ",  " << gr1.pris;
  cout << "\nGr2:  " << gr2.kode << ",  " << gr2.pris;

  cout << "\nKommando (L(es), S(kriv), A(avslutt)):  ";
  cin >> kommando;

  while (kommando != 'a')  {
	  if (kommando == 'l')  {
         do  {
	       cout << "Gr1 sin kode:  ";   cin >> gr1.kode;
	     } while (gr1.kode < 'A' ||  gr1.kode > 'M');
	     cout << "Gr1 sin pris:  ";   cin >> gr1.pris;
	  } else if (kommando == 's')  {
	     cout << "\nHvilket nummer:  ";  cin >> nr;


//  Sette inn Alt.1, 2 og 3 etter tur ......



	  } else
		  cout << "\nUgyldig kommando !\n";

	  cout << "\nKommando (L(es), S(kriv), A(avslutt)):  ";
	  cin >> kommando;
  }
  return 0;
}




/*
Alt 1:
         if (nr == 1)
	        cout << "\nGr1:  " << gr1.kode << ",  " << gr1.pris;
    	 else if (nr == 2)
		    cout << "\nGr2:  " << gr2.kode << ",  " << gr2.pris;
	     else cout << "\nUgyldig nummer !\n";     //   break;

Alt 2:
	     switch(nr)  {
	       case 1:  cout << "\nGr1:  " << gr1.kode << ",  " << gr1.pris;  break;
	       case 2:  cout << "\nGr2:  " << gr2.kode << ",  " << gr2.pris;  break;
	       default: cout << "\nUgyldig nummer !\n";  break;
	     }

Alt 3:
    	 if (nr == 1)  gr = gr1;  else gr = gr2;
	     cout << "\nGr << nr << ":  " << gr.kode << ",  " << gr.pris;
    	 if (nr == 1)  gr1 = gr;  else gr2 = gr;

//   	   gr = (nr == 1)  ?  gr1  :  gr2;

*/