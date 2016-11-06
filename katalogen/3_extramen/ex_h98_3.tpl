//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H98_3.TPL

//  Skjellettet/template for eksamen i C++, 15.desember 1998, oppgave 3.
//  Laget av Frode Haug, HiG, desember 1998.
//  En god del endret/modifisert av FrodeH, HiG, høsten 2003.

//  Program for å administrere telefonnumre (og adresser) for ulike
//  kontakter/familie/venner.

                        //  INCLUDE:
#include <fstream>           //  ifstream
#include <iostream>          //  cout, cin
#include <cctype>            //  toupper
#include <cstring>           //  strcmp, strlen

using namespace std;
                        //  CONST:
const int STRLEN =  60;      //  Max.lengde for en tekststreng.
const int MAXTLF = 200;      //  Max.antall i kartoteket.

                        //  KLASSE:
class Telefonnr {            
  private:

//  Oppgave 3a: Deklarer data-innmaten

  public:                //  Lag innmaten til disse ifm:
    void les_data();               //  Oppgave 3c
    void skriv_data(int n);        //  Oppgave 3d
    bool lik_navn(char nvn[]);     //  Oppgave 3f
    int  hent_telefonnummer();     //  Oppgave 3f
    void les_fra_fil(istream * inn, int nr);  //  Oppgave 3g
};


void skriv_meny();      //  DEKLARASJON AV FUNKSJONER:
void les(char & ch);
void les(char txt[], char txt2[]);
void ny();
void oversikt();
bool slett(int n);
int  finn(char nvn[]);
void les_fra_fil();


//  Oppgave 3a: Definer datastrukturen

                        
int main()  {           //  HOVEDPROGRAMMET:
  char kommando;            //  Brukerens valg/ønske/kommando.
  int nr;                   //  Indeksen som skal slettes (se case 'S').
  int nummer;               //  Indeksen til funnet telefonnumer (se case 'F').
  char navnet[STRLEN];      //  Navnet tilhørende ønsket tlf.nr. (se case 'F').

  les_fra_fil();            //  Oppgave 3g

  skriv_meny();
  les(kommando);             //  Leser brukerens valg/ønske/kommando.
  while (kommando != 'Q')  { //  Så lenge ikke avslutte (quit):
    switch(kommando)  {
      case 'N':   ny();        break;     //  Oppgave 3c

      case 'O':   oversikt();  break;     //  Oppgave 3d

      case 'S':   cout << "\tHvilken indeks vil du slette:  ";  cin >> nr;
                  if (slett(nr))          //  Oppgave 3e
                     cout << "\n\tDenne indeksen er nå slettet.";
                  else
                     cout << "\n\tIndeksen utenfor relevant område!";    break;
      case 'F':   les("Navn", navnet);    //  Oppgave 3b
                  nummer = finn(navnet);  //  Oppgave 3f
                  if (nummer != 0)
                     cout << "\n\tTelefonnummeret er:  " << nummer;
                  else
                     cout << "\n\tIngen i kartoteket har dette navnet!"; break;

      default: skriv_meny();
    }
    les(kommando);
  }
                       //  Burde ha skrevet datastrukturen tilbake til fil.
//  skriv_til_fil();   //  Men dette er ikke en del av denne eksamensoppgaven.
  return 0;
}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:
void Telefonnr :: les_data()  {
    //  Lag resten av innmaten
}

void Telefonnr :: skriv_data(int n)  {
    //  Lag resten av innmaten
}

bool Telefonnr :: lik_navn(char nvn[])  {
    //  Lag resten av innmaten
}

int  Telefonnr :: hent_telefonnummer()  {
    //  Lag resten av innmaten
}

void Telefonnr :: les_fra_fil(istream * inn, int nr)  {
    //  Lag resten av innmaten
}


                        //  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {
  cout << "\n\nFølgende kommandoer er lovlige:"
       << "\n\tN - Nytt telefonnummer inn i kartoteket."
       << "\n\tO - Oversikt over hele kartoteket skrives til skjermen."
       << "\n\tS - Slette alt på en gitt indeks i kartoteket."
       << "\n\tF - Finn telefonnummeret for en gitt person."
       << "\n\tQ - Quit/avslutt.";
}

                             //  Oppdaterer direkte den 'ch' er et alias for 
void les(char & ch)  {       //    (da denne er referanseoverført).
  cout << "\n\nKommando:  ";
  cin >> ch;                 //  Leser brukerens valg/ønske/kommando.
  ch = toupper(ch);          //  Gjør 'ch' om til STOR bokstav.
  cin.ignore();              //  Forkaster neste tegn ('\n').
}

void les(char txt[], char txt2[])  {
  do {                                    

    //  Oppgave 3b: Lag resten av innmaten
  } while (strlen(txt2) == 0);         //  Looper så lenge kun ENTER/CR.
}

void ny()  {
    //  Oppgave 3c: Lag resten av innmaten
}

void oversikt()  {
    //  Oppgave 3d: Lag resten av innmaten
}

bool slett(int n)  {
    //  Oppgave 3e: Lag resten av innmaten
}

int finn(char nvn[])  {
    //  Oppgave 3f: Lag resten av innmaten
}

void les_fra_fil()  {
    //  Oppgave 3g: Lag resten av innmaten
}
