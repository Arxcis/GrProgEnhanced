// hms_secs.cpp
// function coverts hours-minutes-seconds to seconds
#include <iostream>
using namespace std;

long hms_to_secs(int h, int m, int s);    //declaration

int main()
   {
   int hours, minutes, seconds;
   long totalsecs;
   char dummy;
   
   do {
      cout << "\n\nEnter time (format 12:59:59)";
      cout << "\n(0:0:0 to quit): ";      //get hrs, mins, secs
      cin >> hours >> dummy >> minutes >> dummy >> seconds;
                                          //call function
      totalsecs = hms_to_secs(hours, minutes, seconds);
      cout << "Seconds = " << totalsecs;  //display seconds
      }while( hours || minutes || seconds ); //quit if all zeros
   cout << endl;
   return 0;
   }
//--------------------------------------------------------------
// function converts hms to secs
long hms_to_secs(int h, int m, int s)
   {                                      // returns seconds
   return static_cast<long>(h*3600) + m*60 + s;  
   }