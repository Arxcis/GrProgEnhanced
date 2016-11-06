//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_14.CPP


//   L›sningsforslag til oppgave nr.14  i   C++ -programmering.


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {
   char oper;                               // Definerer og
   float tall, akkumulator = 0.0F;          //   initierer variable

   cout << setiosflags(ios::fixed)          //  Setter hvordan float presenteres
        << setiosflags(ios::showpoint)      //    (side 272-273 i l‘reboka).
        << setprecision(3);                            

   cout << "Enkel kalkulator starter:\n\n";

   do  {                                           
     cout << "=   "                                    // Skriver ut innholdet 
          << akkumulator << "\n\n: ";                  //   i akkumulatoren.
          
     cin >> oper;                                      // Henter f›rste tegn.

     switch (oper)  {
       case '+':  cin >> tall;                         // Tegnet var '+':
                  akkumulator += tall;
                  break;
       case '-':  cin >> tall;                         // Tegnet var '-':  
                  akkumulator -= tall;
                  break;
       case '*':  cin >> tall;                         // Tegnet var '*':
                  akkumulator *= tall;
                  break;
       case '/':  cin >> tall;                         // Tegnet var '/':
                  if (tall != 0.0F)                    // Lovlig † dele:       
                     akkumulator /= tall;
                  else                                 // Ikke dele med '0':
                     cout << "Feil!  Dele p† null er tull\n";
                  break;
       case 't':  cin >> akkumulator;                  // Nytt innhold i
                  break;                               //   akkumulatoren:
       case 'c':  akkumulator = 0.0F;                  // Nullstille
                  cout << '\n';                        //   akkumulatoren:
                  break;
       case 's':  cout << "\nEnkel kalkulator stopper.\n";
                  break;                               // Avsluttende utskrift.
       default:   cout << "\nFeil!  Ukjent kommando gitt\n"; 
                  break;                               // Ulovlig kommando:  
     }
   } while (oper != 's');                              // L›kke som g†r inntil
                                                       // brukeren skriver 's'

   return 0;
}
