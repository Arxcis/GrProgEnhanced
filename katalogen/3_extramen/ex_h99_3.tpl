
                             //  INCLUDE:
#include <iostream>          //  cin, cout
#include <fstream>           //  ifstream, ofstream
#include <cctype>            //  toupper
#include <cstring>           //  strcmp

using namespace std;

                             //  CONST:
const int ANT_TRALLER  = 30; //  Antall traller som er til utleie.
const int NVNLEN       = 40; //  Max.lengde for en tekststreng.

                             //  STRUCT:
struct tralle  {             //  Data om en tralle:
  char navn[NVNLEN];         //  Dens navn.
  bool laant;                //  Om utl�nt (=true) eller ledig (=false).
};

                             //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les_kommando();
int  les_nr();
void utlaan() ;              //  Oppgave 3a
void innlevering();          //  Oppgave 3b
void les_fra_fil();          //  Oppgave 3c
void skriv_til_fil();        //  Oppgave 3d
void finn_person();          //  Oppgave 3e
void utlaan2();              //  Oppgave 3f


                             //  GLOBALE VARIABLE:
tralle status[ANT_TRALLER+1]; // Array av tralle-struct'er
int ant_laant;                // Antall traller som for �yeblikket er utl�nt.


                             //  MAIN:
int main()  {
  char valg;

  les_fra_fil();             //  Oppgave 3c

  skriv_meny();
  valg = les_kommando();

  while (valg != 'A')  {
    switch(valg)  {
      case 'U':  utlaan();       break;   //  Oppgave 3a
//    case 'U':  utlaan2();      break;   //  Oppgave 3f
      case 'I':  innlevering();  break;   //  Oppgave 3b
      case 'F':  finn_person();  break;   //  Oppgave 3e
      default :  skriv_meny();   break;
    }
    valg = les_kommando();
  }
  return 0;
}


                             //  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {         //  Skriver brukerens lovlige valg:
  cout << "\nF�lgende kommandoer er lovlige:";
  cout << "\n\tU - Utl�n av tralle";
  cout << "\n\tI - Innlevering av tralle";
  cout << "\n\tF - Finn ut om en gitt person l�ner";
  cout << "\n\tA - Avslutt";
}


char les_kommando()  {       //  Leser, upcaser og returnerer ETT tegn:
  char ch;
  cout << "\nKommando:  ";
  cin >> ch;                 //  Leser.
  cin.ignore();              //  Forkaster neste tegn (='\n').
  return toupper(ch);        //  Upcaser og returnerer.
}


int les_nr()  {              //  Leser og returnerer et tall i arrayens
  int n;                     //     indeks-intervall:
  do  {
    cout << "\n\tNummer (1-" << ANT_TRALLER << "):  ";
    cin >> n;  cin.ignore();
  } while (n < 1  ||  n > ANT_TRALLER);
  return n;
}

                                       // L�ner ut (om mulig) en ledig tralle:
void utlaan()  {             //  Oppgave 3a
     // Lag innmaten
}


                                       //  Innleverer (om mulig) en tralle:
void innlevering()  {        //  Oppgave 3b
     // Lag innmaten
}


                                       //  Leser inn dataene om tralleutl�n
                                       //    fra fil og inn i datastrukturen:
void les_fra_fil()  {        //  Oppgave 3c
     // Lag innmaten
}


                                       //  Skriver hele datastrukturen til fil:
void skriv_til_fil()  {      //  Oppgave 3d
     // Lag innmaten
}


                                       //  Finner ut om en gitt person har
                                       //    l�nt noen tralle, og skriver
                                       //    is�fall aktuelt trallenummer:
void finn_person()  {        //  Oppgave 3e
     // Lag innmaten
}


                                  //  Annen versjon av oppgave 3a, som l�ner ut
                                  //    (om mulig) F�RSTE ledige trallenummer:
void utlaan2()  {            //  Oppgave 3f
     // Lag innmaten
}
