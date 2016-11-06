//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H02_3.TPL

//  Skjellettet/template for eksamen i C++, 19.desember 2002, oppgave 3.
//  Laget av Frode Haug, HiG, desember 2002.


//  Program for å administrere ulike kunder og deres bankkontoer.


		   //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream
#include <cstring>            //  strcmp, strcpy
#include <cctype>             //  toupper

using namespace std;


		   //  CONST:
const int MAXKUNDER = 100;    //  Max. antall kunder i datastrukturen.
const int MAXKONTO  =  10;    //  Max. antall kontoer for EN kunde.
const int STRLEN    =  40;    //  Max. lengde på tekststrenger.


		   //  STRUCT:
struct konto  {               //  Konto:
  int nr;                     //  Kontonummer.
  float belop;                //  Innestående beløp (saldo) på kontoen.
};


struct kunde  {               //  Kunde:
   char navn[STRLEN];         //  Dens navn.
   char adr[STRLEN*2];        //  Dens adresse (gate, postnr, poststed).
   int ant_kontoer;           //  Antall aktive kontoer.
   konto kontoer[MAXKONTO+1]; //  Kundens ulike kontoer.
};


		   //  DEKLARASJON AV FUNKSJONER:
void  skriv_meny();
char  les_kommando();
int   les_og_finn_kunde();
void  ny_kunde();
void  ny_konto();
void  oversikt();
void  transaksjon();
void  les_fra_fil();


		   //  GLOBALE VARIABLE:
int siste_kunde;
kunde kunder[MAXKUNDER+1];


		   //  HOVEDPROGRAM:
int main()  {
   char kommando;

   les_fra_fil();                         //  Oppgave 3e
   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  ny_kunde();    break;   //  Oppgave 3a
       case 'K':  ny_konto();    break;   //  Oppgave 3b
       case 'O':  oversikt();    break;   //  Oppgave 3c
       case 'T':  transaksjon(); break;   //  Oppgave 3d
       default:   skriv_meny();  break;   // 
     }
     kommando = les_kommando();
   }
//   skriv_til_fil();
  return 0;
}

		   //  DEFINISJON AV FUNKSJONER:
		  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN = registrer ny kunde\n";
  cout << "\tK = registrer ny konto hos en kunde\n";
  cout << "\tO = oversikt over en kundes kontoer\n";
  cout << "\tT = penger ut fra/inn på en konto\n";
  cout << "\tQ = quit/avslutt\n";
}


char les_kommando()  {       //  Henter et ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi ›nske:  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}


int les_og_finn_kunde()  {   //  Leser kundenavn og finner (om mulig):
  char nvn[STRLEN];                                        // Kundens navn.
  cout << "\n\tKundens navn: ";  cin.getline(nvn, STRLEN); // Leser navn.
  for (int i = 1;  i <= siste_kunde;  i++)                 // Går gjennom alle:
	  if (strcmp(kunder[i].navn, nvn) == 0)  return i; // Treff: returnerer.
  cout << "\n\tIngen kunde med dette navnet!\n";           // Ingen treff.
  return 0;
}


void  ny_kunde()  {          //  Legger inn (om plass) en ny kunde:
	//  Oppgave 3a:  Lag innmaten
}


void  ny_konto()  {          //  Legger inn ny konto hos en eksisterende kunde:
	//  Oppgave 3b:  Lag innmaten
}


void  oversikt()  {          //  Får oversikt over alt om en gitt kunde:
	//  Oppgave 3c:  Lag innmaten
}


void  transaksjon()  {       //  Penger settes inn på/tas ut av en konto:
	//  Oppgave 3d:  Lag innmaten
}


void  les_fra_fil()  {       //  Leser hele datastrukturen fra fil:
	//  Oppgave 3e:  Lag innmaten
}
