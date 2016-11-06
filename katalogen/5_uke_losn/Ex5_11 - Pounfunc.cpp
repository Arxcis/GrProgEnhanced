// poundstc.cpp
// uses structure for old-style British pounds
#include <iostream>
using namespace std;
//--------------------------------------------------------------
struct sterling                  //old-style pounds
   {
   long pounds;                  //pounds
   int shillings;                //shillings: 20 per pound
   int pence;                    //pence: 12 per shilling
   };
//--------------------------------------------------------------
sterling getpounds();            //declarations
sterling addpounds(sterling, sterling);
void putpounds(sterling);
//--------------------------------------------------------------
int main()
   {
   sterling s1, s2, s3;

   cout << "\nEnter first sterling amount (format 10.19.11): ";
   s1 = getpounds();             //get first sterling value
   cout << "\nEnter second sterling amount: ";
   s2 = getpounds();             //get second sterling value

   s3 = addpounds(s1, s2);       //add two sterling values
   cout << "\nSum is ";
   putpounds(s3);                //display the sum
   cout << endl;
   return 0;
   }  //end main()
//--------------------------------------------------------------
sterling getpounds()             //get sterling amount from user
   {
   sterling s;                   //create temporary sterling
   char ch;                      //(for periods)
                                 //read keyboard: 9.19.11
   cin >> s.pounds >> ch >> s.shillings >> ch >> s.pence;
   return s;                     //return sterling
   }
//--------------------------------------------------------------
                                 //add two sterling amounts
sterling addpounds(sterling s1, sterling s2)
   {
   sterling s3;
   double dpounds1, dpounds2, dpounds3;
   double decshills, decpence, decfrac;
                                 //convert to decimal pounds
   dpounds1 = static_cast<double>(s1.pounds) +
              static_cast<double>(s1.shillings)/20 +
              static_cast<double>(s1.pence)/240;
   dpounds2 = static_cast<double>(s2.pounds) +
              static_cast<double>(s2.shillings)/20 +
              static_cast<double>(s2.pence)/240;
                                 //add decimal pounds
   dpounds3 = dpounds1 + dpounds2;
                                 //convert decimal to sterling
   s3.pounds = static_cast<int>(dpounds3+0.00001);
   decfrac = dpounds3 - s3.pounds;
   decshills = decfrac * 20;
   s3.shillings = static_cast<int>(decshills+0.00001);
   decfrac = decshills - s3.shillings;
   decpence = decfrac * 12;
   s3.pence = static_cast<int>(decpence+0.00001);
   return s3;                    //return sterling
   }
//--------------------------------------------------------------
void putpounds(sterling s)       //display a sterling amount
   {
   char poundsign = static_cast<char>(156);

   cout << poundsign << s.pounds << '.'
        << s.shillings << '.' << s.pence;
   }

