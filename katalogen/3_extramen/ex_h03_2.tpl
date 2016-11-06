//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H03_2.TPL

//  Skjellettet/template for eksamen i C++, 15.desember 2003, oppgave 2.
//  Laget av Frode Haug, HiG, desember 2003.


//  Program som holder orden på ulike enheter (lag/foreninger/klubber/.....)
//  og navnet på denne enhetens medlemmer/deltagere/spillere/.....



                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream
#include <cstring>            //  strcmp, strcpy, strlen
#include <cctype>             //  toupper

using namespace std;

                        //  CONST:
const int MAXENHET =   30;    //  Max. antall enheter i datastrukturen.
const int MAXPERS  =  100;    //  Max. antall personer i enheten.
const int STRLEN   =   40;    //  Max. lengde på tekststrenger.


                        //  KLASSE:
class Enhet  {                //  Enhet:
  private:
    char navn[STRLEN];        //  Navn.
    char adr[STRLEN*2];       //  Adresse (gate, postnr, poststed).
    char email[STRLEN];       //  Email-adresse
    int  tlf;                 //  Telefonnummer.
    int  ant;                 //  Antall medlemmer/deltagere/spillere/.....
    char delt_navn[MAXPERS][STRLEN];   //  2-dimensjonal char-array med navnet
                                       //     til/på enhetens deltagere.
  public:
    Enhet();                  //  Deklarasjon av medlemsfunksjoner:
    bool er_lik(char t[]);
    void skriv();
    void skriv_alt();
    void ny();
    void finn(char t[]);
    void slett();
    void les_fra_fil(istream* inn, char buf[]);
};


                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les_kommando();
void les_tekst(char t[], char s[], int LEN);

void skriv_alle();
int  finn_enhet();
void skriv_enhet();
void ny_deltager();
void finn_deltager();
void slett_deltager();
void les_fra_fil();


                        //  GLOBALE VARIABLE:
int siste_enhet;               //  Indeksen for siste brukte enhet.
Enhet enheter[MAXENHET+1];     //  Array med enhet-objekter.


                        //  HOVEDPROGRAM:
int main()  {
   char kommando;
   
   les_fra_fil();                            //  Oppgave 2g

   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'A':  skriv_alle();     break;   //  Oppgave 2a
       case 'E':  skriv_enhet();    break;   //  Oppgave 2c
       case 'N':  ny_deltager();    break;   //  Oppgave 2d
       case 'F':  finn_deltager();  break;   //  Oppgave 2e
       case 'S':  slett_deltager(); break;   //  Oppgave 2f
       default:   skriv_meny();     break;
     }
     kommando = les_kommando();
   }
  cout << "\n\n";
  return 0;
}


                        //  DEFINISJON AV KLASSE-FUNKSJONER:
Enhet :: Enhet()  {          //  Nullstiller/initierer alle medlemmene:
  ant = tlf = 0;
  strcpy(navn, "");  strcpy(adr, "");  strcpy(email, "");
}

                             //  Returnerer true/false til om objektet
bool Enhet :: er_lik(char t[])  {    //  har et gitt navn:
  return (!strcmp(navn, t));
}


void Enhet :: skriv()  {     //  Skriver alle HOVEDDATA om objektet:
        //  Oppgave 2A:  Lag innmaten
}


void Enhet :: skriv_alt()  { //  Skriver ALLE DATA om objektet:
        //  Oppgave 2C:  Lag innmaten
}


void Enhet :: ny()  {        //  Legger inn (om plass) navnet til/for en ny deltager i enheten:
        //  Oppgave 2D:  Lag innmaten
}

                             //  Leter etter en gitt deltager i enheten:
void Enhet :: finn(char t[])  {
        //  Oppgave 2E:  Lag innmaten
}


void Enhet :: slett()  {    //  Sletter (om mulig) en deltager i enheten:
        //  Oppgave 2F:  Lag innmaten
}

                            //  Leser alle data om en enhet fra fil:
void Enhet :: les_fra_fil(istream* inn, char buf[])  {
        //  Oppgave 2G:  Lag innmaten
}



                        //  DEFINISJON AV FUNKSJONER:
		  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tA = skriv data om Alle enhetene\n";
  cout << "\tE = skriv ALLE data om EN Enhet\n";
  cout << "\tN = Ny deltager i en enhet\n";
  cout << "\tF = Finn en deltager\n";
  cout << "\tS = Slett/fjern en deltager\n";
  cout << "\tQ = quit/avslutt\n";
}


char les_kommando()  {       //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi ønske:  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}


void les_tekst(char t[], char s[], int LEN) {  //  Leser inn ikke-blank tekst:
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, LEN);          //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}


void skriv_alle()  {              //  Skriver HOVEDDATAENE om ALLE enhetene:
        //  Oppgave 2A:  Lag innmaten
}

			                    //  Ut fra enhetens navn, så returneres dens
int finn_enhet(char t[])  {     //  indeks i "enheter", evt.'0' om ikke finnes:
        //  Oppgave 2B:  Lag innmaten
}


void skriv_enhet()  {             //  Skriver ALLE data om en enhet:
        //  Oppgave 2C:  Lag innmaten
}


void ny_deltager()  {             //  Legger inn en ny deltager i en enhet:
        //  Oppgave 2D:  Lag innmaten
}


void finn_deltager()  {           //  Skriver ALLE enheter i deltager er med i:
        //  Oppgave 2E:  Lag innmaten
}


void slett_deltager()  {       //  Sletter (om mulig) en deltager:
        //  Oppgave 2F:  Lag innmaten
}


void les_fra_fil()  {       //  Leser hele datastrukturen fra fil:
        //  Oppgave 2G:  Lag innmaten
}
