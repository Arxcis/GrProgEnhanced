// powerx.cpp
// overloaded function raises number to a power
// can use char, int, long, float, or double types
#include <iostream>
using namespace std;
//--------------------------------------------------------------
char power(char n, int p=2);       //p has default value 2
int power(int n, int p=2);
long power(long n, int p=2);
float power(float n, int p=2);
double power(double n, int p=2);
//--------------------------------------------------------------
int main()
   {
   char chNumber, chAnswer;
   int intNumber, intAnswer;
   long lonNumber, lonAnswer;
   float flNumber, flAnswer;
   double dbNumber, dbAnswer;

   chNumber = 5;                    //type char
   chAnswer = power(chNumber, 3);
   cout << "\nchAnswer = " << int(chAnswer);

   intNumber = 25;                  //type int
   intAnswer = power(intNumber, 3);
   cout << "\nintAnswer = " << intAnswer;

   lonNumber = 50;                  //type long
   lonAnswer = power(lonNumber, 3);
   cout << "\nlonAnswer = " << lonAnswer;

   flNumber = 123.456F;             //type float
   flAnswer = power(flNumber, 3);
   cout << "\nflAnswer = " << flAnswer;

   dbNumber = 123456789123456.0;    //type double
   dbAnswer = power(dbNumber, 3);
   cout << "\ndbAnswer = " << dbAnswer << endl;
   return 0;
   }
//--------------------------------------------------------------
//power()
//returns number n raised to a power p
char power( char n, int p )         //type char
   {
   char result = 1.0;               //start with 1
   for(int j=0; j<p; j++)           //multiply by n
      result *= n;                  //p times
   return result;
   }
//--------------------------------------------------------------
int power( int n, int p )           //type int
   {
   int result = 1.0;                //start with 1
   for(int j=0; j<p; j++)           //multiply by n
      result *= n;                  //p times
   return result;
   }
//--------------------------------------------------------------
long power( long n, int p )         //type long
   {
   long result = 1.0;               //start with 1
   for(int j=0; j<p; j++)           //multiply by n
      result *= n;                  //p times
   return result;
   }
//--------------------------------------------------------------
float power( float n, int p )       //type float
   {
   float result = 1.0;              //start with 1
   for(int j=0; j<p; j++)           //multiply by n
      result *= n;                  //p times
   return result;
   }
//--------------------------------------------------------------
double power( double n, int p )     //type double
   {
   double result = 1.0;             //start with 1
   for(int j=0; j<p; j++)           //multiply by n
      result *= n;                  //p times
   return result;
   }

