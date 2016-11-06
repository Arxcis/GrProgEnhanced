// fracfunc.cpp
// four-function calculator for fractions; uses functions
#include <iostream>
using namespace std;

// comments refer      a     c      a*d + b*c
// to identities      --- + ---  =  ---------
// of the form         b     d         b*d
//--------------------------------------------------------------
struct frac                               //fraction structure
   {
   long num;
   long den;
   };
//--------------------------------------------------------------
frac fadd(frac, frac);                    //declarations
frac fsub(frac, frac);
frac fmul(frac, frac);
frac fdiv(frac, frac);
//--------------------------------------------------------------
int main()
   {
   frac f1, f2, f3;                       //"fractions"
   char dummy, op;

   do {
      cout << "\n\nEnter fraction, operator, fraction";
      cout << "\nform 3/4+3/8 (or 0/1+0/1 to exit): ";
      cin >> f1.num >> dummy >> f1.den;   //get fraction f1
      cin >> op;
      cin >> f2.num >> dummy >> f2.den;   //get fraction f2

      switch(op)
         {
         case '+': f3 = fadd(f1, f2); break;
         case '-': f3 = fsub(f1, f2); break;
         case '*': f3 = fmul(f1, f2); break;
         case '/': f3 = fdiv(f1, f2); break;
         default: cout << "No such operator";
         }                                //display fraction f3
      cout << "Answer = " << f3.num << '/' << f3.den;
      }while( !(f1.num==0 && f2.num==0) ); //until nums = zero
   cout << endl;
   return 0;
   }
//--------------------------------------------------------------
frac fadd(frac f1, frac f2)               //add
   {                                      //(a*d+b*c) / (b*d)
   frac f;
   f.num = f1.num * f2.den + f1.den * f2.num;
   f.den = f1.den * f2.den;
   return f;
   }
//--------------------------------------------------------------
frac fsub(frac f1, frac f2)               //subtract
   {                                      //(a*d-b*c) / (b*d)
   frac f;
   f.num = f1.num * f2.den - f1.den * f2.num;
   f.den = f1.den * f2.den;
   return f;
   }
//--------------------------------------------------------------
frac fmul(frac f1, frac f2)               //multiply
   {                                      //(a*c) / (b*d)
   frac f;
   f.num = f1.num * f2.num;
   f.den = f1.den * f2.den;
   return f;
   }
//--------------------------------------------------------------
frac fdiv(frac f1, frac f2)               //divide
   {                                      //(a*d) / (b*c)
   frac f;
   f.num = f1.num * f2.den;
   f.den = f1.den * f2.num;
   return f;
   }

