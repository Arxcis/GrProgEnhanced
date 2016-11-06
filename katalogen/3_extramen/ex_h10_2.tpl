//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H10_2.TPL

//  Skjellettet/template for eksamen i C++, 7.desember 2010, oppgave 2.
//  Laget av Frode Haug, HiG, november 2010.

//  Program som holder orden pÜ kampene en fotballentusiast har
//  sett mellom ulike lag i Premier League (UK) i lõpet av EN sesong. 
  

                        //  INCLUDE:
#include <fstream>           //  ifstream, ofstream
#include <iostream>          //  cin, cout
#include <iomanip>           //  setw
#include <cstring>           //  strlen, strcpy
#include <cctype>            //  toupper
using namespace std;

                        //  ENUM og CONST:
enum Type  { Navn, Fork, Bane };
const int STRLEN     =     30;    //  Max. tekstlengde.
const int FASTLAG    =     20;    //  Fast antall lag i Premier League.
const int MAXKAMPER  =    120;    //  Max. antall kamper i lõpet av EN sesong.
const int MAXMAAL    =     20;    //  Max. mÜl det gÜr an Ü score i en PL-kamp.


class Lag {            //  KLASSER:
  private:
    char navn[STRLEN];            //  Lagets navn.
    char fork[STRLEN/6];          //  Forkortelse for lagsnavnet.
    char bane[STRLEN];            //  Navn pÜ lagets hjemmebane.

  public:                    //  Deklarasjon av medlemsfunksjoner:
    void skriv(int n);                //  Oppgave 2A
    void hent(char txt[], Type ty);   //  Ferdiglaget (se nedenfor).
    void les_fra_fil(istream* inn);   //  Oppgave 2G
    void skriv_til_fil(ostream* ut);  //       Extra
};


class Kamp {
  private:
    int  dato,                    //  Kampdato, pÜ formatet: èèMMDD.
         klokken,                 //  Startklokkeslett, pÜ formatet: TTMM
         Hlag, Blag,              //  Hjemme- og bortelagets indeks i "lagene".
         Hres, Bres;              //  Hjemme- og bortelagets mÜl(score).

  public:                    //  Definisjon/deklarasjon av medlemsfunksjoner:
    void skriv();                            //  Oppgave 2B
    void skriv_alt();                        //  Oppgave 2C
    bool involvert(int n)  { return(Hlag == n  ||  Blag == n); }  //  (oppg.2D)
    void resultat();                         //  Oppgave 2E
    void ny();                               //  Oppgave 2F
    void les_fra_fil(istream* inn, int d);   //  Oppgave 2G
    void skriv_til_fil(ostream* ut);         //  Extra
};

                    //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
void konverter(int d);
char les(char t[]);
int  les(const char t[], const int min, const int max);

void skriv_alle_lag();       //  Oppgave 2A
void skriv_alle_kamper();    //  Oppgave 2B
void skriv_en_kamp();        //  Oppgave 2C
void skriv_ett_lag();        //  Oppgave 2D
void resultat();             //  Oppgave 2E
void ny_kamp();              //  Oppgave 2F
void les_fra_filer();        //  Oppgave 2G
void skriv_til_filer();      //  Extra

                        //  GLOBALE VARIABLE:
Lag  lagene[FASTLAG+1];      //  Array med Lag-objekter.
Kamp kampene[MAXKAMPER+1];   //  Array med Kamp-objekter.
int siste_kamp;              //  Indeks for siste Kamp hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   les_fra_filer();                             //  Oppgave 2G
   skriv_meny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'G':  skriv_alle_lag();    break;   //  Oppgave 2A
       case 'M':  skriv_alle_kamper(); break;   //  Oppgave 2B
       case 'K':  skriv_en_kamp();     break;   //  Oppgave 2C
       case 'L':  skriv_ett_lag();     break;   //  Oppgave 2D
       case 'R':  resultat();          break;   //  Oppgave 2E
       case 'N':  ny_kamp();           break;   //  Oppgave 2F
       case 'T':  skriv_til_filer();   break;   //  Extra
       default:   skriv_meny();        break;
     }
     kommando = les("ùnske");
   }
  skriv_til_filer();                            //  Extra
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Lag::skriv(int n)  {    //  Skriver alle datamedlemmer:
        //  Oppgave 2A:  Lag innmaten
}

                               // Ut fra 'ty' kopieres datamedlem inn i 'txt':
void Lag::hent(char txt[], Type ty)  {    // (brukes ifm. oppgave 2B og 2C) 
  switch (ty)  {
     case Navn:  strcpy(txt, navn);  break;
     case Fork:  strcpy(txt, fork);  break;
     case Bane:  strcpy(txt, bane);  break;
  }
}


void Lag::les_fra_fil(istream* inn)  {    //  Leser fra fil:
        //  Oppgave 2G:  Lag innmaten
}


void Lag::skriv_til_fil(ostream* ut)  {   //  Skriver til fil:
        //  EXTRA
}

//  --------------------------------------------------------------------------

void Kamp::skriv()  {        //  Skriver ALLE datamedlemmer:
        //  Oppgave 2B:  Lag innmaten
}


void Kamp::skriv_alt()  {    //  Skriver ALT + mer om lagene:
        //  Oppgave 2C:  Lag innmaten
}


void Kamp::resultat()  {     //  Leser/registrerer kampresultat:
        //  Oppgave 2E:  Lag innmaten
}


void Kamp::ny()  {           //  Registrerer helt ny kamp:
        //  Oppgave 2F:  Lag innmaten
}
                             //  Leser alt fra fil:
void Kamp::les_fra_fil(istream* inn, int d)  {
        //  Oppgave 2G:  Lag innmaten
}

                             //  Skriver alt til fil:
void Kamp::skriv_til_fil(ostream* ut)  {
        //  EXTRA
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tG   = skriv alle laGene\n";
  cout << "\tM   = skriv alle kaMpene\n";
  cout << "\tK   = skriv alt om en Kamp\n";
  cout << "\tL   = skriv alle kampene for ett Lag\n";
  cout << "\tR   = registrer/legg inn Resulutat\n";
  cout << "\tN   = Ny kamp legges inn\n";
  cout << "\tT   = skriv Til filer\n";
  cout << "\tQ   = Quit/avslutt\n";
}

                             //  Gjõr om dato ('d') pÜ formatet: èèMMDD
void konverter(int d)  {     //    til utsfriften: DD/MM-èè :
  cout <<  d % 100  <<  '/'  <<  (d / 100) % 100  <<  '-'  <<  d / 10000;
}


char les(char t[])  {        //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << '\n' << t << ":  ";   //  Skriver medsendt ledetekst.
  cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
  return (toupper(ch));         //  Upcaser og returnerer.
}

                             // Leser et tall i et visst intervall:
int les(const char t[], const int min, const int max)  { 
  int n;
  do  {                                  // Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;   cin.ignore();            // Leser inn ett tall.
  } while(n < min  ||  n > max);         // Sjekker at i lovlig intervall.
  return n;                              // Returnerer innlest tall.
}


void skriv_alle_lag()  {     //  Skriver ALLE lagene:
        //  Oppgave 2A:  Lag innmaten
}


void skriv_alle_kamper()  {  //  Skriver ALLE kampene:
        //  Oppgave 2B:  Lag innmaten
}


void skriv_en_kamp()  {      //  Skriver ALT om EN kamp:
        //  Oppgave 2C:  Lag innmaten
}


void skriv_ett_lag()  {      //  Skriver ALLE kampene for ETT lag:
        //  Oppgave 2D:  Lag innmaten
}


void resultat()  {           //  Leser inn ett nytt resultat: 
        //  Oppgave 2E:  Lag innmaten
}


void ny_kamp()  {            //  Registrerer en ny kamp:
        //  Oppgave 2F:  Lag innmaten
}


void les_fra_filer()  {      //  Leser inn HELE datastrukturen:
        //  Oppgave 2G:  Lag innmaten
}


void skriv_til_filer()  {    //  Skriver HELE datastrukturen til fil:
        //  EXTRA
}
