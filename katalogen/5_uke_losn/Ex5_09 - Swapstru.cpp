// swapstru.cpp
// function swaps two structures passed to it
#include <iostream>
#include <iomanip>             //for setw()
using namespace std;
//--------------------------------------------------------------
struct time                    //time structure
   {
   int hours;
   int minutes;
   int seconds;
   };
//--------------------------------------------------------------

void swap(time&, time&);       //prototypes
void tshow(time);
int main()
   {                           //initialize two times
   time t1 = {0, 20, 40}, t2={1, 30, 50};

   cout << "\nBefore swap t1=";
   tshow(t1);                  //show times
   cout << ", t2=";
   tshow(t2);

   swap(t1, t2);               //call function to swap values

   cout << "\n\nAfter swap t1=";
   tshow(t1);                  //show times again
   cout << ", t2=";
   tshow(t2);
   cout << "\n\n";
   return 0;
   }
//--------------------------------------------------------------
void swap(time& t1, time& t2)  //function swaps time values
   {                           //passed by reference
   time temp = t1;
   t1 = t2;
   t2 = temp;
   }
//--------------------------------------------------------------
void tshow(time t)             //function displays time
   {
   cout.fill('0');             //with leading zeros
   cout << t.hours
        << ':' << setw(2) << t.minutes
        << ':' << setw(2) << t.seconds;
   }
