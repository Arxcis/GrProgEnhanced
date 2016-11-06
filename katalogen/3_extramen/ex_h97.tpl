			//  INCLUDE:
#include <iostream>         //  cout, cin
#include <cstring>          //  strcpy, strcmp
#include <cctype>           //  toupper

using namespace std;

			//  CONST:
const int NVN_LEN   = 30;    //  Max.lengde for et lands navn.
const int KORT_LEN  =  4;    //  Max.lengde for en valuta-betegnelse
const int ANT_LAND  = 14;    //  Antall ulike land/valutaer i programmet

			//  STRUCT:
struct Valuta  {

//  Lag innmaten (se oppgave 1).
};

			//  DEKLARASJON AV PROSEDYRER:
int   finn_indeks(const char beteg[]);
void  les_navn(const char text[], char nvn[]);
float les_tall(const char text[]);
void  skriv_meny();
void  initier_navn();
void  les_kurs();
void  norsk_til_fremmed();
void  fremmed1_til_fremmed2();
void  endre_kurs();

			//  GLOBALE VARIABLE:
//  Definer relevant datastruktur (se oppgave 1).


			//  HOVEDPROGRAM:
int main()  {
  char kommando;

  initier_navn();         //  Setter opp landenes navn og valuta-betegnelse.
  les_kurs();             //  Leser landenes aktuelle kurs (fra tastaturet).

  skriv_meny();
  cout << "\n\nGi kommando:  ";  cin >> kommando;
  kommando = toupper(kommando);

  while (kommando != 'Q')  {
    switch (kommando)  {
      case 'N':  norsk_til_fremmed();       break;
      case 'F':  fremmed1_til_fremmed2();   break;
      case 'K':  endre_kurs();	            break;
      default :  skriv_meny();              break;
    }
    cout << "\n\nGi kommando:  ";  cin >> kommando;
    kommando = toupper(kommando);
  }
  return 0;
}

			//  DEFINISJON AV PROSEDYRER:
                                   //  Finner (om mulig) indeks for betegnelse.
int finn_indeks(const char beteg[])  {

//    Skriv innmaten (se oppgave 2).
}

                                   //  Leser inn en valuta-betegnelse.
void les_navn(const char text[], char nvn[])  {

//    Skriv innmaten (se oppgave 3).
}

                                   //  Leser inn et positivt tall.
float les_tall(const char text[])  {

//    Skriv innmaten (se oppgave 3).
}


void skriv_meny() {
  cout << "\n\n\nFLGENDE KOMMANDOER ER TILGJENGELIGE:";
  cout << "\n\tN - Omregning fra Norske kroner til en utenlandsk";
  cout << "\n\tF - Omregning fra en utenlandsk/Fremmed til en annen";
  cout << "\n\tK - endring av en Kurs";
  cout << "\n\tQ - Quit/avslutt";
}

                                   
void initier_navn()  {             //  Setter opp landenes navn og betegnelse.

//    Skriv innmaten (se oppgave 4).
}


void les_kurs()  {            //  Leser inn aktuelle kurser (fra tastaturet).

//    Skriv innmaten (se oppgave 4).
}


void norsk_til_fremmed()  {   // Regner om norske kroner til utenlandsk valuta.

//    Skriv innmaten (se oppgave 5).
}


void fremmed1_til_fremmed2()  {   //  Regner om mellom to utenlandske valutaer.  

//    Skriv innmaten (se oppgave 6).
}


void endre_kurs()  {              //  Endrer kursen for en valuta.

//    Skriv innmaten (se oppgave 7).
}
