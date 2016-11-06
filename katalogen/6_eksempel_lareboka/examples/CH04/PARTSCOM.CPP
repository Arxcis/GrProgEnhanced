// partscom.cpp
// uses parts inventory to demonstrate structures
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct                        //no tag needed
   {
   int modelnumber;           //ID number of widget
   int partnumber;            //ID number of widget part
   float cost;                //cost of part
   } part1;                   //definition goes here
////////////////////////////////////////////////////////////////
int main()
   {
   part1.modelnumber = 6244;  //give values to structure members
   part1.partnumber = 373;
   part1.cost = 217.55F;
                              //display structure members
   cout << "Model "  << part1.modelnumber;
   cout << ", part "   << part1.partnumber;
   cout << ", costs $" << part1.cost << endl;
   return 0;
   }