//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S07_2.CPP

//  L›sningsforslag til kontinuasjonseksamen i C++, 8.august 2007, oppgave 2.
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
    void skriv_til_fil();                           //  Oppgave 2f
  public: 
    Kunde()                 {  brukes = false;   }  //  Oppgave 2a (4 linjer):
    bool ibruk()            {  return brukes;    }
    int  hent_vekt()        {  return vekt_inn;  }
    void reg_innvekt(int v) {  vekt_inn = v;  brukes = true;   }
    void drar();                                    //  Oppgave 2e
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

void Kunde::drar()  {   //  OPPGAVE 2E - Leser ALLE rest-data når kunde drar:
  cout << "\n\tVekt inn: " << vekt_inn << '\n';
  vekt_ut = les("Ut-vekt  ", vekt_inn, MAXVEKT);  //  Leser avreis-vekt.
  type = les();                      //  Leser om Grus, Pukk eller Sand.
  dimensjon = les("Dimensjon", 0, 50);  //  Leser aktuell dim. på det hentet.
  les("Navn   ", navn, STRLEN);      //  Leser navnet og
  les("Adresse", adr, STRLEN*2);     //    adresse (gateadr og postadr):
  skriv_til_fil();                   //  Skriver ALT om kunden til fil.
  brukes = false;                    //  Resetter relevant/viktig datamedlem.
}


void Kunde::skriv_til_fil()  {  // OPPGAVE 2F - Skriver ALT om kunden til fil:
  fstream utfil("GRUSTAK.DTA", ios::app | ios::out); //  Legger til bakerst.
  utfil << navn << '\n' << adr << '\n';          //  Skriver mavn og adrese.
  utfil << (vekt_ut - vekt_inn) << " kg med ";   //  Skriver kg hentet/kjøpt.
  switch (type)  {                               //  Skriver hva hentet:
    case Grus:  utfil << "GRUS";  break;
    case Pukk:  utfil << "PUKK";  break;
    case Sand:  utfil << "SAND";  break;
  }
  utfil << " dim: " << dimensjon << "\n\n";      //  Skriver varens dimensjon.
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

                            //  OPPGAVE 2B - Skriver status for alle numrene 
void skriv()  {             //               (om er i bruk eller ledig):
  int i;

  cout << "\nFølgende numre BRUKES:\n";
  for (i = 1;  i <= MAXKJORETOY;  i++)        //  Skriver indekser/nr i bruk:
      if (kundene[i].ibruk()) cout << ' ' << i;

  cout << "\n\nFølgende numre er LEDIGE:\n";
  for (i = 1;  i <= MAXKJORETOY;  i++)        //  Skriver indekser/nr ledig:
      if (!kundene[i].ibruk()) cout << ' ' << i;
  cout << "\n\n";
}


void kommer()  {            //  OPPGAVE 2C - Ny kunde/kjøretøy kommer:
  int nr;
  nr = les("Nytt nummer", 1, MAXKJORETOY);  //  Ledig nr. leses inn.
  if (!kundene[nr].ibruk())                 //  Er et lovlig/ledig nr:
                                            //  Leser og registrerer inn-vekt:
     kundene[nr].reg_innvekt(les("Inn-vekt   ", 0, MAXVEKT));
  else                                      //  Feil - nr. IKKE ledig:
     cout << "\nDette nummeret er allerede i bruk!\n\n";
}


void endre()  {             //  OPPGAVE 2D - Endre vekt for et gitt nummer:
  int nr;
  nr = les("Endre nummer", 1, MAXKJORETOY);        //  Aktuellt nr. leses inn.
  if (kundene[nr].ibruk()) {                       //  Er et OK/brukt nr:
     cout << "\n\tNåværende inn-vekt: " << kundene[nr].hent_vekt() << '\n';
                                        //  Leser og registrerer NY inn-vekt:
     kundene[nr].reg_innvekt(les("Ny inn-vekt    ", 0, MAXVEKT));
  } else                                           //  Feil - nr. IKKE i bruk:
     cout << "\nDette nummeret er IKKE i bruk!\n\n";
}

                            //  OPPGAVE 2E - Leser resten av ALLE dataene,
void drar()  {              //               (og kunden skrives til fil):
  int nr;
  nr = les("Nummer som drar", 1, MAXKJORETOY); //  Aktuelt nr. leses inn.
  if (kundene[nr].ibruk()) {                   //  Er et OK/brukt nr:
     kundene[nr].drar();                       //  Reg. resten av ALLE data.
  } else                                       //  Feil - nr. IKKE i bruk:
     cout << "\nDette nummeret er IKKE i bruk!\n\n";
}
