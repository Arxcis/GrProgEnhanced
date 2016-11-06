//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_01.CPP

//   Programeksempel nr.1 for forelesning i  C++ -programmering. 


#include <iostream>                         //  cout, cin

using namespace std;


int main()  {

   int ivar1;                               //  Definerer heltallsvariabel.
   int ivar2 = 23;                          //  Initierer heltallsvariabel.

   char cvar1;                              //  Definerer tegnvariabel.

   cout << "\nSkriv inn et heltall: ";  
   cin >> ivar1;                            //  Leser heltall fra brukeren.

   cout << "\nSkriv inn et tegn:    ";
   cin >> cvar1;                            //  Leser tegn fra brukeren.

   cout << "\n\nTallene er:\n";             //  Skriver ledetekst.
   cout << '\t' << ivar1;                   //  Skriver variabelenes innhold
   cout << '\t' << ivar2 << '\n';           //     med 8 tegn (TAB) imellom.

   cout << "Tegnet er:  " << cvar1 << '\n'; // Skriver innlest tegnet.
   
   cout << "\nDenne linjen inneholder  \\n  som en del av teksten\n";
   cout << "Denne linjen har  << \'\\n\'  etter teksten" << '\n';

   cout << "\nInnlest tegns ASCII-verdi + "
	    << ivar2 << " er:  " << ivar2+cvar1;


   cout << "\n\n  \x02 \x03 \x04 \x05 \x06";  // Skriver spesiell tegn
   cout << "\n\n  \xC8 \xCD \xCA \xCD \xBC" << '\n'; // vha. hexadesimalt nr.

   return 0;
}
