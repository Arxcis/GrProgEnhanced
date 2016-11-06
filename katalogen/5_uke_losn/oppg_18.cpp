//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_18.CPP


//   L›sningsforslag til oppgave nr.18  i   C++ -programmering.


			     //  INCLUDE:
#include <iostream>

using namespace std;


			     //  GLOBALE VARIABLE:
float  sistePris,                     //  Siste innleste bel›p for kunde.
       endreSum,                      //  Det som skal trekkes fra p† kunden.
       innlevertSum,                  //  Det kunden leverer for † betale.
       kundeSum,                      //  Totalsum for n†v‘rende kunde.
       totalSum;                      //  Totalsum for ALLE kundene.

			     //  HOVEDPROGRAM:
int main()  {
  char kommando;

  totalSum = 0.0F;                    //  Nullstiller ALLE kundenes totalsum.

  do  {
    sistePris = kundeSum = 0.0F;      //  Nullstiller for EN kunde.

    cout << "\n\n\tKommando (V(arekj›p), A(ngre siste), E(ndre), S(um)):  ";
    cin >> kommando;                  //  Leser kommando.
									  //  Looper til 'S' eller 's': 
    while (kommando != 's'  &&  kommando != 'S')  {
      switch (kommando)  {
	    case 'v':  case 'V':   
			       cout << "\n\t\tVarepris:  ";
			       cin >> sistePris;         //  Leser varepris.
			       kundeSum += sistePris;    //  Adderer til kundens totalsum.
			       break;

	    case 'a':  case 'A':   
			       cout << "\n\t\tTrekker fra siste bel›p p† kr." << sistePris;
			       kundeSum -= sistePris;    //  Trekker fra siste kj›p.
			       sistePris = 0;            //  Nullstiller det siste kj›pet.
			       break;

	    case 'e':  case 'E':   
			       cout << "\n\t\tBel›p † trekke fra:  ";
			       cin >> endreSum;          // Leser endringssum
							                 // I rett intervall:
				   if (endreSum >= 0 && endreSum <= kundeSum)  {
			          kundeSum -= endreSum;  // Trekker fra.
				      sistePris = 0;         // Nullstiller.
			       }  else                   // Galt intervall: 
				      cout << "\n\t\tBel›pet utenfor "
				           << "intervallet (0-" << kundeSum << ").";
			       break;
      }
      cout << "\n\n\tKommando (V(arekj›p), A(ngre siste), E(ndre), S(um)):  ";
      cin >> kommando;                     //  Leser kommando.
    }

				       //  Skriver kundens totale sum:
    cout << "\n\n\t\tKunden har handlet for kr." << kundeSum;

    totalSum += kundeSum;            //  Oppsummerer ALLE kundenes sum.

    cout << "\n\n\tKommando (T(ilbake), R(esultat, totalt), "
	     << "N(y) kunde, Q(uit)):  ";
    cin >> kommando;                       //  Leser kommando:
    while (kommando != 'q'  &&  kommando != 'Q'  &&
	       kommando != 'n'  &&  kommando != 'N')  {
      switch (kommando)  {
	    case 't':  case 'T':   
			       cout << "\n\t\tInnlevert bel›p:  ";
			       cin >> innlevertSum;    // Leser levert bel›p.
										   //  Penger tilbake:               
			       if (innlevertSum >= kundeSum)
				       cout << "\n\t\tKunden skal ha tilbake kr."
				            << innlevertSum - kundeSum;
			       else                    //  For lite levert inn:
				       cout << "\n\t\tInnlevert bel›p MINDRE enn "
				            << "handlebel›pet p† kr." << kundeSum;
			       break;

	    case 'r':  case 'R':               //  ALLE kundenes sum:
			       cout << "\n\n\t\tTotalt solgt for kr." << totalSum;     
			       break;
      }
      cout << "\n\n\tKommando (T(ilbake), R(esultat, totalt), "
	       << "N(y) kunde, Q(uit)):  ";
      cin >> kommando;                //  Leser kommando.
    }
  } while (kommando != 'q'  &&  kommando != 'Q');

				       //  ALLE kundenes totale handlesum.
  cout << "\n\n\t\tTotalt solgt for kr." << totalSum << '\n';
  return 0;
}
