//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S07_2.TPL

//  Skjellettet/template for kontinuasjonseksamen i C++, 8.august 2007, oppg.2.
//  Laget av Frode Haug, HiG, mai 2007.

//  Program som holder orden på vekten før og etter at kjøretøyer
//      (m/tilhenger) henter grus/pukk/sand i et grustak.


                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  fstream
#include <cctype>             //  toupper
#include <cstring>            //  strlen

using namespace std;

                        //  CONST:
const int  STRLEN      =     40;  //  Max. tekstlengde.
const int  MAXKJORETOY =     50;  //  Max. antall kjøretøy i grustaket.
const int  MAXVEKT     = 100000;  //  Max.vekt = 100 tonn.

                        //  ENUM:
enum Type { Grus, Pukk, Sand };

                        //  KLASSE:
class Kunde  {             //  Kunden/kjøretøyet som henter noe i grustaket:
  private:
    bool brukes;           //  Om objektet er i bruk eller ei for tiden.
    int  vekt_inn,         //  Totalvekt på bil (og tilhenger) ved ankomst.
         vekt_ut,          //  Totalvekt på bil (og tilhenger) ved avreise.
         dimensjon;        //  Dimensjonen (i cm) på hentet/kjøpt "vare".
    char navn[STRLEN];     //  Tittel/navn.
    char adr[STRLEN*2];    //  Både gateadr og postadr.
    Type type;             //  Grus, pukk eller sand (er hentet/kjøpt).

                           //  Definisjon/deklarasjon av medlemsfunksjoner:
    void skriv_til_fil();                  //  Oppgave 2f
  public: 
    Kunde();                               //  Oppgave 2a
    bool ibruk();                          //  Oppgave 2a
    int  hent_vekt();                      //  Oppgave 2a
    void reg_innvekt(int v);               //  Oppgave 2a
    void drar();                           //  Oppgave 2e
};

                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
Type les();
void skriv();
void kommer();
void endre();
void drar();

                        //  GLOBALE VARIABLE:
Kunde kundene[MAXKJORETOY+1];      //  Array med Kunde-objekter.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   skriv_meny();
   kommando = les("Ønske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'S':  skriv();       break;    //  Oppgave 2b
       case 'K':  kommer();      break;    //  Oppgave 2c
       case 'E':  endre();       break;    //  Oppgave 2d
       case 'D':  drar();        break;    //  Oppgave 2e
       default:   skriv_meny();  break;
     }
     kommando = les("Ønske");
   }
  cout << "\n\n";
  return 0;
}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:

void Kunde::drar()  {   //  Leser ALLE rest-data når kunde drar:
        //  Oppgave 2E:  Lag innmaten
}


void Kunde::skriv_til_fil()  {  //  Skriver ALT om kunden til fil:
        //  Oppgave 2F:  Lag innmaten
}

                        //  DEFINISJON AV FUNKSJONER:

void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tS = Skriv status for alle de 50 numrene\n";
  cout << "\tK = kunde/kjøretøy Kommer\n";
  cout << "\tD = kunde/kjøretøy Drar\n";
  cout << "\tE = Endre vekt for et kjøretøy som er tilstede\n";
  cout << "\tQ = Quit/avslutt\n";
}


char les(char t[])  {       //  Henter ett ikke-blankt upcaset tegn:
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

                            //  Leser inn en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {  
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, LEN);          //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}


Type les()  {               //  Leser og returnerer hva som er hentet:
  int n = les("Hentet (1=grus, 2=pukk, 3=sand): ", 1, 3);
  switch (n)  {                    //  Gjør om fra tall-verdi til enum-verdi
    case 1:  return Grus;  break;  //     og returnerer dette:
    case 2:  return Pukk;  break;
    case 3:  return Sand;  break;
  }
}

                  
void skriv()  {  // Skriver status for alle numrene (om er i bruk eller ledig): 
        //  Oppgave 2B:  Lag innmaten
}


void kommer()  {            //  Ny kunde/kjøretøy kommer:
        //  Oppgave 2C:  Lag innmaten
}


void endre()  {             //  Endre vekt for et gitt nummer:
        //  Oppgave 2D:  Lag innmaten
}


void drar()  {   // Leser resten av ALLE dataene, (og kunden skrives til fil):
        //  Oppgave 2E:  Lag innmaten
}
