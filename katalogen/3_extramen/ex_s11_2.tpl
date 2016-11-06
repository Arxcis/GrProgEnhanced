//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S11_2.TPL

//  Skjellettet/template for kontinuasjoneksamen i C++, 11.august 2011, oppgave 2.
//  Laget av Frode Haug, HiG, mai 2011.


//  Program som holder orden pÜ dugnadsoppgaver/gjõremÜl og de personene
//  som utfõrer dette ved/pÜ et (idretts)arrangement.
  
                        //  INCLUDE:
#include <fstream>           //  ifstream, ofstream
#include <iostream>          //  cin, cout
#include <cstring>           //  strcpy
#include <cctype>            //  toupper
#include <iomanip>           //  setw
using namespace std;

                        //  CONST:
const int STRLEN    =   30;   //  Max. tekstlengde.
const int MAXOPPG   =   20;   //  Max. antall dugnadsoppgaver/gjõremÜl.
const int MAXPERS   =    6;   //  Max. antall personer pÜ/til en oppgave.
const int SISTEPERS = 1000;   //  Siste personnummer/-ID i bruk.


class Oppgave {            //  KLASSER:
  private:
    char navn[STRLEN];        //  Oppgavens navn.

    //  Oppgave 2A:  Lag flere datamedlemmer (tre stk)

  public:                  //  Deklarasjon av medlemsfunksjoner:
    Oppgave()  {  strcpy(navn, "");  ant_tot = ant_naa = 0;  }
    void initier();                   //  Oppgave 2A
    void skriv(int n);                //  Oppgave 2C (og 2D)
    bool fullt();                     //  Oppgave 2D
    void oppdater();                  //  Oppgave 2E
    void skriv_til_fil(ostream* ut);  //  Oppgave 2F
    void les_fra_fil(istream* inn);   //  Oppgave 2G
};



                    //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les(char t[]);
int  les(const char t[], const int min, const int max);

void ny();                   //  Oppgave 2A
void fjern();                //  Oppgave 2B
void status();               //  Oppgave 2C
void ledig();                //  Oppgave 2D
void ankommer();             //  Oppgave 2E
void skriv_til_fil();        //  Oppgave 2F 
void les_fra_fil();          //  Oppgave 2G

                        //  GLOBALE VARIABLE:
Oppgave oppgavene[MAXOPPG+1];  //  Array med Oppgave-objekter.
int siste_oppgave;             //  Indeks for siste Oppgave hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   les_fra_fil();                               //  Oppgave 2G
   skriv_meny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  ny();                break;   //  Oppgave 2A
       case 'F':  fjern();             break;   //  Oppgave 2B
       case 'S':  status();            break;   //  Oppgave 2C
       case 'L':  ledig();             break;   //  Oppgave 2D
       case 'A':  ankommer();          break;   //  Oppgave 2E
       case 'T':  skriv_til_fil();     break;   //  Oppgave 2F
       default:   skriv_meny();        break;
     }
     kommando = les("ùnske");
   }
  skriv_til_fil();                              //  Oppgave 2F
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Oppgave::initier()  {        //  Leser inn/initierer alle data:
        //  Oppgave 2A:  Lag innmaten
}


void Oppgave::skriv(int n)  {     //  Skriver alle datamedlemmer:
        //  Oppgave 2C:  Lag innmaten
}


bool Oppgave::fullt()  {   //  Returnerer om oppgaven er fylt opp med personer:
        //  Oppgave 2D:  Lag innmaten  
}


void Oppgave::oppdater()  {       //  Person(er) kommer for Ü arbeide:
        //  Oppgave 2E:  Lag innmaten
}


void Oppgave::skriv_til_fil(ostream* ut)  {   //  Skriver til fil:
        //  Oppgave 2F:  Lag innmaten
}


void Oppgave::les_fra_fil(istream* inn)  {    //  Leser fra fil:
        //  Oppgave 2G:  Lag innmaten
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN   = Ny oppgave\n";
  cout << "\tF   = Fjern/slett oppgave\n";
  cout << "\tS   = Status ALLE oppgaver\n";
  cout << "\tL   = Ledige oppgaver\n";
  cout << "\tA   = nye personer Ankommer\n";
  cout << "\tT   = skriv Til fil\n";
  cout << "\tQ   = Quit/avslutt\n";
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


void ny()  {             //  Legger (om mulig) inn en ny oppgave:
        //  Oppgave 2A:  Lag innmaten
}


void fjern()  {          //  Fjerner/sletter en oppgave:
        //  Oppgave 2B:  Lag innmaten
}


void status()  {         //  Skriver status for ALLE oppgavene:
        //  Oppgave 2C:  Lag innmaten
}


void ledig()  {          //  Skriver status for alle LEDIGE oppgaver:
        //  Oppgave 2D:  Lag innmaten
}


void ankommer()  {       //  Person(er) ankommer for Ü jobbe:
        //  Oppgave 2E:  Lag innmaten
}


void skriv_til_fil()  {  //  Skriver HELE datastrukturen til fil:
        //  Oppgave 2F:  Lag innmaten
}


void les_fra_fil()  {    //  Leser HELE datastrukturen fra fil:
        //  Oppgave 2G:  Lag innmaten
}

