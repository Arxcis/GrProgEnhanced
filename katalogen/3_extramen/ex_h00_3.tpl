//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H00_3.TPL

//  Skjellettet/template for eksamen i C++, 9.august 2003, oppgave 3.
//  Laget av Frode Haug, HiG, november 2000.
//  En god del endret/modifisert av FrodeH, HiG, høsten 2003.


//  Programmet holder orden på ulike personers poeng i spillet Yatzy.
//  Postnavn leses FRA fil og sluttresultatet skrives TIL fil.


                             //  INCLUDE:
#include <iostream>               //  cin, cout
#include <fstream>                //  ifstream, ofstream
#include <cstring>                //  strcpy
#include <iomanip>                //  setw

using namespace std;

                             //  CONST:
const int TXT_LEN      = 20;     //  Max. lengde på tekster (navn).
const int MAX_SPILLERE =  6;     //  Max. antall spillere som kan delta.
const int MAX_POSTER   = 23;     //  Max. antall ulike poster i Yatzy.
const int MAX_POENG    = 50;     //  Max. antall poeng i EN omgang.
const int BONUS_GRENSE = 63;     //  Om summen av post nr.0-5 (1'ere-6'ere)
const int BONUS        = 50;     //    >= BONUS_GRENSE gis 'BONUS' ekstrapoeng.

                             //  KLASSER:
class Poster {                          //  Klasse med postnavnene:
  private:
    char postnavn[MAX_POSTER][TXT_LEN]; //  Navnet/tittelen til de ulike postene.

  public:                               //  Returnerer navnet til post nr.'n':
    void hent(char navn[], int n)  {  strcpy(navn, postnavn[n]);  }
    void les_fra_fil();                 //  Oppgave 3D
};


class Spiller  {
  private:	
    char navn[TXT_LEN];          //  Spillerens navn.
    int  poeng[MAX_POSTER];      //  Hver enkelt post's poeng (nr.0 brukes !)
  
  public:
    void initier(int n);                         //  Oppgave 3C
    void les_poeng(int n);                       //  Oppgave 3F
    void beregn_totalsum();                      //  Oppgave 3F
    void skriv_til_fil(ostream* ut);             //  Oppgave 3E
};


                             //  DEKLARASJON AV FUNKSJONER:
int  summer(int p[MAX_POSTER], int n, int m);    //  Oppgave 3B
void initier_spillere();                         //  Oppgave 3C
void skriv_resultat_til_fil();                   //  Oppgave 3E

                             //  GLOBALE VARIABLE:
Poster postnavnene;                 //  Alle postnavnene lagres i ETT objekt.
Spiller deltager[MAX_SPILLERE+1];   //  Deltagende spillere (nr.0 brukes ikke).
int  siste_post, ant_spillere;      //  Aktuelt antall poster og spillere.

                          
int main()  {                //  HOVEDPROGRAMMET:
  int i, j;

  postnavnene.les_fra_fil();     //  Leser postnavene/-titlene fra fil.

  initier_spillere();            //  Initierer/nullstiller spillerne.

  //  Oppgave 3F:  Lag resten av innmaten
  
  skriv_resultat_til_fil();                     //  Skriver alt til fil.

  return 0;
}

                             //  DEFINISJON AV KLASSE-FUNKSJONER:
void Poster::les_fra_fil()  {
    //  Oppgave 3D:  Lag innmaten
}


void Spiller::initier(int n)  {   
    //  Oppgave 3C:  Lag innmaten
}


void Spiller::les_poeng(int n)  {
    //  Oppgave 3F:  Lag innmaten
}


void Spiller::beregn_totalsum()  {
    //  Oppgave 3F:  Lag innmaten
}


void Spiller::skriv_til_fil(ostream* ut)  {
    //  Oppgave 3E:  Lag innmaten
}

                             //  DEFINISJON AV FUNKSJONER:
int  summer(int p[MAX_POSTER], int n, int m)  {
    //  Oppgave 3B:  Lag innmaten
}


void initier_spillere()  {
    //  Oppgave 3C:  Lag innmaten
}


void skriv_resultat_til_fil()  {
    //  Oppgave 3E:  Lag innmaten
}
