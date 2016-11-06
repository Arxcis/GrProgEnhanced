// selfcnt.cpp
// function tells how many times it has been called
#include <iostream>
using namespace std;

int selfcnt();               //declaration
// int count = 0;            //remove comment to use external
//--------------------------------------------------------------
int main()
   {
   for(int j=0; j<10; j++)
      {
      cout << "\nselfcnt() has been called "
           << selfcnt() << " times";
      }
   cout << endl;
   return 0;
   }
//--------------------------------------------------------------
int selfcnt()
   {
   static int count = 0;     //comment out to use external

   return ++count;
   }
