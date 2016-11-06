//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_08.CPP

//   Programeksempel nr.8 for forelesning i  C++ -programmering. 
//   Jfr. side 119-120 i "Object-oriented programming in C++"


#include <iostream>

using namespace std;


int main()  {
  const unsigned char WHITE = 219;
  const unsigned char GRAY  = 176;
  unsigned char ch;
 
  for (int count = 0;  count < (80*25)-1;  count++)  {
    ch = WHITE;
    for (int j = 2;  j < count;  j++)
      if (count % j == 0)  {
         ch = GRAY;
         break;
      }
    cout << ch;
  }
  cout << '\n';
  return 0;
}
