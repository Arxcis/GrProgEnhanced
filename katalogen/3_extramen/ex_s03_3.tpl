//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_S03_3.TPL

//  Skjellettet/template for eksamen i C++, 9.august 2003, oppgave 3.
//  Laget av Frode Haug, HiG, august 2003.


//  Program for � administrere oppdrag ute hos ulike kunder/steder
//  p� forskjellige dager i l�pet av �ret.


                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream, ofstream
#include <cstring>            //  strcpy
#include <cctype>             //  toupper

using namespace std;

                        //  CONST:
const int ANTMND = 12;        //  Antall m�neder.
const int ANTDAG = 31;        //  Max. antall dager i en m�ned.
                              //  Antall dager i hver m�ned 
                              //     (NB: ignorerer skudd�r!):
const int DAGANTALL[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int STRLEN = 40;        //  Max.lengde for en tekst.


                        //  STRUCT:
struct Oppdrag  {             //  Oppdrag (EN kunde, EN dag):
  char navn[STRLEN];          //  Kundens/stedets navn.
  char adr[STRLEN];           //  Kundens/stedets adresse.
  char merknad[STRLEN];       //  Evt.merknad/kommentar til oppdraget.
  int  tlf;                   //  Kundens tlf.
};


                        //  DEKLARASJON AV FUNKSJONER:
void  skriv_meny();
char  les_kommando();
void  les_inn(int & m, int & d);
void  nytt_oppdrag();
void  slett_oppdrag();
void  oversikt();
void  les_fra_fil();
void  skriv_til_fil();


                        //  GLOBALE VARIABLE:
Oppdrag oppdragene[ANTMND+1][ANTDAG+1]; // Bruker indeksene 1-12(x) og 1-31(y).


                        //  HOVEDPROGRAM:
int main()  {
   char kommando;
   
   les_fra_fil();                         //  Oppgave 3e
   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  nytt_oppdrag();  break; //  Oppgave 3b
       case 'S':  slett_oppdrag(); break; //  Oppgave 3c
       case 'O':  oversikt();      break; //  Oppgave 3d
       case 'F':  skriv_til_fil(); break; //  Oppgave 3f
       default:   skriv_meny();    break;
     }
     kommando = les_kommando();
   }
  return 0;
}

                        //  DEFINISJON AV FUNKSJONER:
	  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nF�LGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN = Nytt oppdrag\n";
  cout << "\tS = Slett oppdrag\n";
  cout << "\tO = Oversikt over en ukes oppdrag\n";
  cout << "\tF = skriv til Fil\n";
  cout << "\tQ = quit/avslutt\n";
}


char les_kommando()  {       //  Henter et ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi �nske:  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}

                             //  Leser inn m�ned og dag. Referanseoverf�rte 
void les_inn(int & m, int & d)  {   // parametre, s� de oppdateres direkte:
	//  Oppgave 3a:  Lag innmaten
}


void  nytt_oppdrag()  {      //  Legger inn/registrerer nytt oppdrag:
        //  Oppgave 3b:  Lag innmaten
}


void  slett_oppdrag()  {     //  Sletter/fjerner eksisterende oppdrag:
        //  Oppgave 3c:  Lag innmaten
}


void  oversikt()  {          //  Skriver oversikt over oppdrag i fem dager:
        //  Oppgave 3d:  Lag innmaten
}


void  les_fra_fil()  {       //  Leser hele datastrukturen fra fil:
        //  Oppgave 3e:  Lag innmaten
}


void  skriv_til_fil()  {     //  Skriver hele datastrukturen til fil:
        //  Oppgave 3f:  Lag innmaten
}
