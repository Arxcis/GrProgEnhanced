//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_04.CPP

//   Programeksempel nr.4 for forelesning i  C++ -programmering. 
//   Jfr. side 81-82 i "Object-oriented programming in C++"


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {
   int numb;

   for (numb = 1;   numb <= 10;  numb++)  {
     cout << setw(4) << numb;
     int cube = numb*numb*numb;
     cout << setw(6) << cube << '\n';
   }
   return 0;
}
