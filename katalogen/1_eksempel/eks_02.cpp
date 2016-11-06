//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_02.CPP

//   Programeksempel nr.2 for forelesning i  C++ -programmering. 


#include <iostream>

using namespace std;


int main()  {

   int radie;                               //  Definerer 3 variable:
   float hoyde;
   float volum;
   const float PI = 3.14159F;               //  Definerer floatKONSTANT.

   cout << "Skriv radius (int):   ";        //  Ber om og leser radie.
   cin >> radie;

   cout << "\nSkriv h›yde (float):  ";      //  Ber om og leser h›yde.
   cin >> hoyde;

   volum = (PI * radie * radie) * hoyde;    //  Regner ut s›yles volum.

   cout << "\n\n\tRadie:\tH›yde:\tVolum:\n";       //  Utskrift
   cout << '\t' << radie << '\t' << hoyde << '\t' << volum << '\n';

   return 0;
}
