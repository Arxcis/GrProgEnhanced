// timefunc.cpp
// adds two time structures, uses functions
#include <iostream>
#include <iomanip>                     //for setw()
using namespace std;
//--------------------------------------------------------------
struct time                            //time structure
   {
   int hours;
   int minutes;
   int seconds;
   };
//--------------------------------------------------------------
long time_to_secs(time);               //prototypes
time secs_to_time(long);

int main()
   {
   time t1, t2, t3;
   long secs1, secs2, secs3;
   char c;
   
   do {                                //get first time
      cout << "\nEnter a time (format 11:59:59): ";
      cin >> t1.hours >> c >> t1.minutes >> c >> t1.seconds;
      secs1 = time_to_secs(t1);        //convert to seconds
                                       //get second time
      cout << "Enter another time: ";
      cin >> t2.hours >> c >> t2.minutes >> c >> t2.seconds;
      secs2 = time_to_secs(t2);        //convert to seconds

      secs3 = secs1 + secs2;           //add seconds values
      t3 = secs_to_time(secs3);        //convert to hms

      cout << "Sum is ";               //display time in hms
      cout.fill('0');                  //with leading zeros
      cout << t3.hours
           << ':' << setw(2) << t3.minutes
           << ':' << setw(2) << t3.seconds;
      cout << "\nDo another (y/n)? ";
      cin >> c;
      } while(c != 'n');   
   return 0;
   }  //end main()
//--------------------------------------------------------------
//function converts time to seconds
long time_to_secs(time t)
   {
   return static_cast<long>(t.hours*3600) + 
                            t.minutes*60 + t.seconds;
   }
//--------------------------------------------------------------
//function converts seconds to time
time secs_to_time(long secs)
   {
   time t;                        //temporary structure
   long remainsecs;
                                  //convert secs to time
   t.hours = static_cast<int>(secs/3600);      
   remainsecs = secs - static_cast<long>(t.hours)*3600;
   t.minutes = static_cast<int>(remainsecs/60);
   t.seconds = static_cast<int>(remainsecs) - t.minutes*60;
   return t;
   }
