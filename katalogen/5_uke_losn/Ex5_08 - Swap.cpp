// swap.cpp
// function swaps two values passed to it
#include <iostream>
using namespace std;

void swap(int&, int&);        //declaration
//--------------------------------------------------------------
int main()
   {
   int a = 4;
   int b = 7;
   cout << "\nBefore swap a=" << a << ", b=" << b;

   swap(a, b);                //call function to swap values

   cout << "\nAfter swap a=" << a << ", b=" << b << endl;
   return 0;
   }
//--------------------------------------------------------------
void swap(int& a, int&b)      //function swaps values
   {                          //passed by reference
   int temp = a;
   a = b;
   b = temp;
   }