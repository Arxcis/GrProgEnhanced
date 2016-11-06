//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H02_3.CPP

//  L›sningsforslag til eksamen i C++, 19.desember 2002, oppgave 3.
//  Laget av Frode Haug, HiG, desember 2002.


//  Program for † administrere ulike kunder og deres bankkontoer.


		   //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream
#include <cstring>            //  strcmp, strcpy
#include <cctype>             //  toupper

using namespace std;


		   //  CONST:
const int MAXKUNDER = 100;    //  Max. antall kunder i datastrukturen.
const int MAXKONTO  =  10;    //  Max. antall kontoer for EN kunde.
const int STRLEN    =  40;    //  Max. lengde p† tekststrenger.


		   //  STRUCT:
struct konto  {               //  Konto:
  int nr;                     //  Kontonummer.
  float belop;                //  Innest†ende bel›p (saldo) p† kontoen.
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
   
   cout << setiosflags(ios::fixed) << setprecision(2);

   les_fra_fil();                         //  Oppgave 3e
   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  ny_kunde();    break;   //  Oppgave 3a
       case 'K':  ny_konto();    break;   //  Oppgave 3b
       case 'O':  oversikt();    break;   //  Oppgave 3c
       case 'T':  transaksjon(); break;   //  Oppgave 3d
       default:   skriv_meny();  break;
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
  cout << "\tT = penger ut fra/inn p† en konto\n";
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
  for (int i = 1;  i <= siste_kunde;  i++)                 // G†r gjennom alle:
      if (strcmp(kunder[i].navn, nvn) == 0)  return i;     // Treff: returnerer.
  cout << "\n\tIngen kunde med dette navnet!\n";           // Ingen treff.
  return 0;
}

			     //  OPPGAVE 3A:
void  ny_kunde()  {          //  Legger inn (om plass) en ny kunde:
  if (siste_kunde < MAXKUNDER)  {
     cout << "\nREGISTRERER NY KUNDE (nr." << siste_kunde+1 << "):";
     cout << "\n\tNavn:    ";  
     cin.getline(kunder[++siste_kunde].navn, STRLEN);   // Leser kundens navn.
     cout << "\tAdresse: ";  
     cin.getline(kunder[siste_kunde].adr, STRLEN*2);    // Leser kundens adr.
     kunder[siste_kunde].ant_kontoer = 0;               // Nuller "ant_kontoer"
  } else
     cout << "\n\tKartoteket er fullt med " << MAXKUNDER << " kunder allerede!";
}

			     //  OPPGAVE 3B:
void  ny_konto()  {          //  Legger inn ny konto hos en eksisterende kunde:
  int nr, ant;                                   // Kundeindeks og ant.kontoer.
  cout << "\nREGISTRERER NY KONTO HOS EN KUNDE";
  if (siste_kunde > 0)  {                           // Kunder finnes:
     nr = les_og_finn_kunde();                      // Pr›ver † finne en kunde.
     if (nr != 0)  {                                // Kunden finnes:
	 if (kunder[nr].ant_kontoer < MAXKONTO)  {  // Plass til en konto til:
	    ant = ++kunder[nr].ant_kontoer;         // ker konto-antallet.
	    cout << "\tKontonummer:  ";
	    cin >> kunder[nr].kontoer[ant].nr;      // Leser nytt kontonummer.
	    do  {
	      cout << "\tBel›p inn:    ";             
	      cin >> kunder[nr].kontoer[ant].belop; // Setter inn penger.
	    } while (kunder[nr].kontoer[ant].belop < 0);   // Negativt bel›p.
	    cin.ignore();                           // Forkaster siste '\n'.
	 } else
	   cout << "\n\tKunden har " << MAXKONTO << " kontoer allerede!";
     }        
  } else
     cout << "\n\tKartoteket er tomt!";
}

			     //  OPPGAVE 3C:
void  oversikt()  {          //  F†r oversikt over alt om en gitt kunde:
  int nr;                                           // Kundeindeks.
  cout << "\nOVERSIKT OVER ALT HOS/FOR EN KUNDE";
  if (siste_kunde > 0)  {                           // Kunder finnes:
     nr = les_og_finn_kunde();                      // Pr›ver † finne en kunde.
     if (nr != 0)  {                                // Kunden finnes:
	cout << "\n\tAdresse:  " << kunder[nr].adr;          // Skriver: adr.
	cout << "\n\t#kontoer: " << kunder[nr].ant_kontoer;  //   - ant.kontoer
	for (int i = 1; i <= kunder[nr].ant_kontoer; i++)
	    cout << "\n\t\tNr: " << kunder[nr].kontoer[i].nr  // - deres nummer
		<< "\tSaldo: "  << kunder[nr].kontoer[i].belop;//- deres saldo
     }  
  } else
     cout << "\n\tKartoteket er tomt!";
}

			     //  OPPGAVE 3D:
void  transaksjon()  {       //  Penger settes inn p†/tas ut av en konto:
  int nr, ant, j;                  // Kundeindeks, ant.kontoer og l›kkevariabel.
  float belop;
  cout << "\nTRANSAKSJON INN P/UT FRA KONTO";
  if (siste_kunde > 0)  {                           // Kunder finnes:
     nr = les_og_finn_kunde();                      // Pr›ver † finne en kunde.
     if (nr != 0)  {                                // Kunden finnes:
	 ant = kunder[nr].ant_kontoer;              // Fyller hjelpevariabel.
	 if (ant > 0)  {                            // Kunden har kontoer: 
	   for (int i = 1; i <= ant; i++)           // Skriver deres kontonr:
	       cout << "\n\t\t" << i << ": " << kunder[nr].kontoer[i].nr;
	   cout << "\n\tIndeks nr: ";  cin >> j;    // Hvilken skal endres ?
	   if (j >= 1  &&  j <= ant)  {             // Lovlig indeksnummer:
	      do  {
		cout << "\tBel›p (+/-): ";  cin >> belop; //Leser bel›p inn/ut.
	      } while (belop < -kunder[nr].kontoer[j].belop); // For stort ut.
	      kunder[nr].kontoer[j].belop += belop;   //  Oppdaterer saldo.
	      cout << "\tKontoen inneholder n† kr: " 
		   << kunder[nr].kontoer[j].belop;
	   } else
	     cout << "\n\tUlovlig indeks!";
	 } else
	   cout << "\n\tKunden har ingen kontoer!";
     }  
  } else
     cout << "\n\tKartoteket er tomt!";
}

			     //  OPPGAVE 3E:
void  les_fra_fil()  {       //  Leser hele datastrukturen fra fil:
  char buffer[STRLEN*2];                         //  Hjelpetekst (buffer).
  int i;                                         //  L›kkevariabel.
  ifstream innfil("KUNTO.DTA");                  //  pner aktuell fil.
  if (innfil)  {                                 //  Filen finnes:
      innfil.getline(buffer, STRLEN);            //  Henter (om mulig) 1.linje.
      while (innfil  &&  siste_kunde < MAXKUNDER)  {  // Mer p† filen og plass:
	strcpy(kunder[++siste_kunde].navn, buffer);   // Kopierer navn.
	innfil.getline(kunder[siste_kunde].adr, STRLEN*2); // Henter: adresse.
	innfil >> kunder[siste_kunde].ant_kontoer;         //    - ant.kontoer
	for (i = 1;  i <= kunder[siste_kunde].ant_kontoer; i++)
	    innfil >> kunder[siste_kunde].kontoer[i].nr      //  - deres nr.
		   >> kunder[siste_kunde].kontoer[i].belop;  //  - deres saldo.
	innfil.ignore();                                   //  Forkaster '\n'.
	innfil.getline(buffer, STRLEN);      //  Henter (om mulig) neste linje.
      }
  } else
    cout << "\n\tFinner ikke filen 'KUNTO.DTA'!";
}
