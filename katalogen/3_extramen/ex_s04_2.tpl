//  Fil:  FRODEH \ CPP \ EXTRAMEN \ EX_S04_2.TPL

//  Skjellettet/template for kontinuasjonseksamen i C++, 12.august 2004, oppgave 2.
//  Laget av Frode Haug, HiG, juni 2004.

//  Program som holder orden på ulike deltagere og deres †rlige
//  deltagelse p† ett eller annet (korpsstevne, speiderleir) i ten†rene.


                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream
#include <cstring>            //  strcpy
#include <cctype>             //  toupper

using namespace std;

                        //  CONST:
const int MAXDELT  =  200;    //  Max. antall tenårings-deltagere.
const int STRLEN   =   40;    //  Max. lengde på tekststrenger.
const int TENLEN   =    7;    //  Antall år man er tenåring.
const int TENSTART =   13;    //  Første tenåringsår.
const int TENSLUTT =   19;    //  Siste tenåringsår.

                        //  KLASSE:
class Deltager  {             //  Tenåringsdeltager:
  private:
	int  nr;                  //  Nummer/ID.
    char navn[STRLEN];        //  Navn.
    char adr[STRLEN*2];       //  Adresse (gate, postnr, poststed).
    int  fodeaar;             //  Fødeselsår.
	bool deltatt[TENLEN];     //  Hvilke tenår (13-19) man har deltatt.

  public:
    Deltager();               //  Deklarasjon av medlemsfunksjoner:
    bool er_lik(int n);
    void skriv();
    void skriv_alt();
    void ny(int n);
    void les_fra_fil(istream* inn, int n);
	void vaert_med(int aar);
};


                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les_kommando();
int  les_nummer();

void skriv_alle();
int  finn_deltager();
void skriv_deltager();
void ny_deltager();
void slett_deltager();
void les_fra_fil();
void les_deltagelse();


                        //  GLOBALE VARIABLE:
Deltager deltagere[MAXDELT+1];  //  Tenåringsdeltager-objekter.
int siste_brukt;                //  Indeksen for siste brukte deltager.


                        //  HOVEDPROGRAM:
int main()  {
   char kommando;
   
   les_fra_fil();                            //  Oppgave 2F

   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'A':  skriv_alle();     break;   //  Oppgave 2A
       case 'E':  skriv_deltager(); break;   //  Oppgave 2C
       case 'N':  ny_deltager();    break;   //  Oppgave 2D
       case 'S':  slett_deltager(); break;   //  Oppgave 2E
       case 'D':  les_deltagelse(); break;   //  Oppgave 2G
       default:   skriv_meny();     break;
     }
     kommando = les_kommando();
   }
  cout << "\n\n";
  return 0;
}


                        //  DEFINISJON AV KLASSE-FUNKSJONER:
Deltager::Deltager()  {      //  Nullstiller/initierer alle medlemmene:
  nr = fodeaar = 0;
  strcpy(navn, "");  strcpy(adr, "");
  for (int i = 0;  i < TENLEN;  i++)  deltatt[i] = false;
}

                             //  Returnerer true/false til om objektet
bool Deltager::er_lik(int n)  {      //  har et gitt nummer:
  return (nr == n);
}


void Deltager::skriv()  {       //  Skriver alle HOVEDDATA om objektet:
        //  Oppgave 2A:  Lag innmaten
}


void Deltager::skriv_alt()  {   //  Skriver ALLE DATA om objektet:
        //  Oppgave 2C:  Lag innmaten
}


void Deltager::ny(int n)  {     //  Leser inn ALLE data til objektet:
        //  Oppgave 2D:  Lag innmaten
}


                            //  Leser alle ALLE om en deltager fra fil:
void Deltager::les_fra_fil(istream* inn, int n)  {
        //  Oppgave 2F:  Lag innmaten
}

                            //  Setter (om mulig) at har deltatt et gitt år:
void Deltager::vaert_med(int aar)  {  //  Får inn aktuelt år som parameter.
        //  Oppgave 2G:  Lag innmaten
}


                        //  DEFINISJON AV FUNKSJONER:
		  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tA = skriv data om Alle deltagerne\n";
  cout << "\tE = skriv ALLE data om EN deltager\n";
  cout << "\tN = Ny deltager\n";
  cout << "\tS = Slett/fjern en deltager\n";
  cout << "\tD = les Deltagelse fra fil\n";
  cout << "\tQ = quit/avslutt\n";
}


char les_kommando()  {       //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi ønske:  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}


int les_nummer()  {          //  Henter et potensielt deltagernummer:
  int nr;
  cout << "\n\tDeltagernummer:  ";   cin >> nr;   cin.ignore();
  return nr;
}


void skriv_alle()  {         //  Skriver HOVEDDATAENE om ALLE deltagerne:
        //  Oppgave 2A:  Lag innmaten
}

                             //   Ut fra deltagerens nummer, så returneres dens 
int finn_deltager(int n)  {  //   indeks i 'deltagere', evt.'0' om ikke finnes:
        //  Oppgave 2B:  Lag innmaten  
}


void skriv_deltager()  {          //  Skriver ALLE data om en deltager:
        //  Oppgave 2C:  Lag innmaten  
}


void ny_deltager()  {             //  Legger inn en ny deltager:
        //  Oppgave 2D:  Lag innmaten  
}


void slett_deltager()  {       //  Sletter (om mulig) en deltager:
        //  Oppgave 2E:  Lag innmaten  
}


void les_fra_fil()  {       //  Leser hele datastrukturen fra fil:
        //  Oppgave 2F:  Lag innmaten  
}

                             //  Leser hvem (nummer) som har deltatt på 
void les_deltagelse()  {     //    arrangementet et gitt år:
        //  Oppgave 2G:  Lag innmaten  
}
