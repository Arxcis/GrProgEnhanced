			//  INCLUDE:
#include <iostream>          //  cout, cin
#include <cctype>            //  toupper

using namespace std;
			//  CONST:
const int ANT_SERIER =  500;      //   25   //  Max. antall ulike serier.
const int ANT_MERKER = 2000;      //  100   //  Max. antall ulike merker.
const int STRLEN     =   80;                //  Max. tekstlengde.

			//  STRUCT:
struct Serie  {

//   Lag innmaten (se oppgave 1)
};


struct Merke  {

//   Lag innmaten (se oppgave 1)
};


			//  DEKLARASJON AV PROSEDYRER:
void skriv_meny();
void ny_serie();
void skriv_merke();
void skriv_serie();
void skriv_aar();

			//  GLOBALE VARIABLE:
Serie serier[ANT_SERIER+1];     //  Array med data om de ulike seriene.
Merke merker[ANT_MERKER+1];     //  Array med data om de ulike merkene.
int siste_serie = 0,            //  Siste indeks brukt i serie-arrayen.
    siste_merke = 0;            //  Siste indeks brukt i merke-arrayen.


			//  HOVEDPROGRAM:
int main()  {
  char kommando;

  skriv_meny();                             //  Skriver kommando-meny.
  cout << "\n\nGi kommando:  ";             //  Leser brukerens valg:
  cin >> kommando;  kommando = toupper(kommando);

  while (kommando != 'Q')  {                //  Looper til Quit/Avslutt:
    switch (kommando)  {
      case 'N':  ny_serie();       break;   //  H†ndterer de ulike valgene: 
      case 'M':  skriv_merke();    break;
      case 'S':  skriv_serie();    break;
      case 'A':  skriv_aar();      break;
      default :  skriv_meny();     break;   //  Skriver kommando-meny.
    }
    cout << "\n\nGi kommando:  ";             //  Leser brukerens valg:
    cin >> kommando;  kommando = toupper(kommando);
  }
  return 0;
}


void skriv_meny() {
  cout << "\n\n\nFLGENDE KOMMANDOER ER TILGJENGELIGE:";
  cout << "\n\tN - Ny serie (merker)";
  cout << "\n\tM - Skriv alle data om et Merke";
  cout << "\n\tS - Skriv data om en Serie";
  cout << "\n\tA - Skriv data om alle serier et gitt r";
  cout << "\n\tQ - Quit/avslutt";
}


void ny_serie()  {          //  Registrere en ny serie og alle dets merker:

//   Lag innmaten (se oppgave 2)
}


void skriv_merke()  { //  Skriver (om mulig) alle data om et spesifikt merke:

//   Lag innmaten (se oppgave 3)
}


void skriv_serie()  { //  Skriver (om mulig) data om en spesifikk serie:

//   Lag innmaten (se oppgave 4)
}


void skriv_aar()  {   //  Skriver (om mulig) data om alle serier et gitt †r:

//   Lag innmaten (se oppgave 5)
}
