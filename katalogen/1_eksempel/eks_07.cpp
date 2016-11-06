//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_07.CPP

//   Programeksempel nr.7 for forelesning i  C++ -programmering. 
//   Jfr.side 113-114 i "Object-oriented programming in C++"


#include <iostream>

using namespace std;


int main()  {

  for (int i=0; i<80; i++)  {
    char ch = (i%8)  ? ' '  : 'x';
    cout << ch; 
  }

  return 0;
}
