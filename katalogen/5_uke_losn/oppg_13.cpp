//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_13.CPP


//   L›sningsforslag til oppgave nr.13  i   C++ -programmering.


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {
  int n = 0;                                //  Antall siffer innlest.
  int nummer = 0;                           //  Telefonnummeret.
  char ch;                                  //  Innlest tegn. 
  int i, siffer;
  int del = 10000000;

  cout << "Skriv et 8-sifret telefonnummer: ";

  while (n < 8)  {                          //  S†lenge ikke lest 8 siffer
    cin >> ch;                              //  Henter neste siffer

    if (ch >= '0' && ch <= '9')             //  Dersom et siffer:
       if (ch == '0'  &&  nummer == 0)  {   //  Dersom en startende '0':
         cout << "\n\nFEIL! Telefonnummer starter ikke med \'0\' lenger.";
         cout << "\nPr›v igjen!   Telefonnummer:  ";
       }      
       else  {                              //  Lovlig siffer:
         ++n;                               //  Teller opp antall siffer.
         nummer = (nummer * 10) + (ch - '0');   // Regner sammen tallet.
       }
    else  {                                 //  Ikke et siffer:
      cout << "\n\nFEIL! Kun lovlig med SIFFER i telefonnummeret.";
      cout << "\nPr›v igjen!   Telefonnummer:  ";
      nummer = 0;                           //  Nullstiller variable:
      n = 0;
    }
  }
  
  cout << "\n\n\nTelefonnummeret:  " << nummer;
  cout << "  skrevet i klartekst:\n\t\t";

  for ( i = 8;  i >= 1;  i-- )  {           //  G†r gjennom alle 8 sifre:
    siffer = nummer / del;                  //  Finner f›rste/venstre siffer.

    switch (siffer)  {                      //  Skriver tekst for sifferet:
      case 0:  cout << "null";  break;
      case 1:  cout << "en";    break;
      case 2:  cout << "to";    break;
      case 3:  cout << "tre";   break;
      case 4:  cout << "fire";  break;
      case 5:  cout << "fem";   break;
      case 6:  cout << "seks";  break;
      case 7:  cout << "syv";   break;
      case 8:  cout << "†tte";  break;
      case 9:  cout << "ni";    break;
    }
    nummer -= siffer*del;                 //  Tar vekk f›rste/venstre siffer.
    del /= 10;                            //  Tar vekk EN null.
    if (del > 0)                          //  Fortsatt flere siffer igjen:
      cout << "-";
  }
  cout << '\n';
  return 0;
}
