//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S11_2.CPP

//  Lõsningsforslag til kontinuasjoneksamen i C++, 11.august 2011, oppgave 2.
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
    int  ant_tot,             //  Tot.ant.personer som trengs til/pÜ oppgaven.
         ant_naa;             //  NÜvërende antall pÜ oppgaven.
    int  hvem[MAXPERS+1];     //  Hvilke personer (numre) som for õyeblikket 
                              //    er satt pÜ/betjener oppgaven.
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

void Oppgave::initier()  {      //  Oppgave 2A - Leser inn/initierer alle data:
  cout << "\n\tOppgavens navn: ";  cin.getline(navn, STRLEN);  //  Navn
  ant_tot = les("Antall personer", 1, MAXPERS);                //  ant_tot
  ant_naa = 0;                                                 //  ant_naa

}


void Oppgave::skriv(int n)  {    //  OPPGAVE 2C - Skriver alle datamedlemmer:
  cout << '\t' << setw(2) << n << ": " << navn 
       << "\t(" << ant_naa << '/' << ant_tot << ") - personer: ";
  for (int i = 1;  i <= ant_naa;  i++)  cout << "  " << hvem[i];  // Personer.
  cout << '\n';
}


bool Oppgave::fullt()  {               //  Oppgave 2D - Returnerer om 
  return (ant_tot == ant_naa);         //    oppgaven er fylt opp med personer.
}


void Oppgave::oppdater()  {   //  Oppgave 2E - Person(er) kommer for Ü arbeide:
  int i, ant;
  skriv(0);                           //  Skriver nÜvërende data/status.
  if (ant_naa < ant_tot) {            //  Plass til flere pÜ oppgaven: 
     ant = les("Antall ankommet", 0, ant_tot-ant_naa);  //  Antall nye.
     for (i = 1;  i <= ant;  i++)     //  Leser nye personers (unike) nummer:
         hvem[ant_naa+i] = les("Personnummer", 1, SISTEPERS);
     ant_naa += ant;                  //  Oppdaterer totalantallet pÜ oppgaven:
     skriv(0);                        //  Skriver evt. oppdatert status.
  } else                              //  Fullt (med personer) pÜ oppgaven:
    cout << "\n\n\tAllerede nok personer pÜ/til oppgavenn!\n";
}


void Oppgave::skriv_til_fil(ostream* ut)  {   //  OPPGAVE 2F - Skriver til fil:
  *ut << navn << '\n' << ant_tot << ' ' << ant_naa;
  for (int i = 1;  i <= ant_naa;  i++)  *ut << ' ' << hvem[i];
  *ut << '\n';
}


void Oppgave::les_fra_fil(istream* inn)  {    //  OPPGAVE 2G - Leser fra fil:
  (*inn).getline(navn, STRLEN);                           //  Navn
  *inn >> ant_tot >> ant_naa;                             //  ant_tot / ant_naa
  for (int i = 1;  i <= ant_naa;  i++)  *inn >> hvem[i];  //  Personnr/-ID
  (*inn).ignore();
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


void ny()  {             //  Oppgave 2A - Legger (om mulig) inn en ny oppgave:
  if (siste_oppgave < MAXOPPG)  {           //  Plass til flere oppgaver:
     cout << "\n\tNy oppgave nr." << ++siste_oppgave << ":\n";
     oppgavene[siste_oppgave].initier();    //  Legger inn nye personer.
  } else                                    //  Fullt med oppgaver:
    cout << "\n\tFullt med " <<  MAXOPPG << " oppgaver allerde!\n\n";
}


void fjern()  {                //  Oppgave 2B - Fjerner/sletter en oppgave:
  int nr = les("Fjern oppgave nr.", 0, siste_oppgave),   //  Leser oppgavenr.
      svar;                                      //  Brukersvar.  
  if (nr != 0)  {                                //  Oppgaven finnes:
     svar = les("ùnsker du VIRKELIG Ü fjerne (0=nei, 1=ja", 0, 1);
     if (svar == 1)  {
        if (nr != siste_oppgave)  {              //  Oppgave er IKKE sist:
           oppgavene[nr] = oppgavene[siste_oppgave];   //  Flytter bakerste.
           cout << "\n\tSiste ble flyttet til den slettedes plass/nummer.\n\n";
        } else                                   //  Siste oppgave:
           cout << "\n\tSiste/bakerste oppgave ble fjernet/slettet.\n\n";
        siste_oppgave--;
     } else                                      //  Ingen blir fjernet:
       cout << "\n\tOK, ingen oppgave blir fjernet/slettet.\n\n";
  } else                                         //  Ingen blir fjernet:
    cout << "\n\tIngen oppgave ble fjernet/slettet.\n\n";
}


void status()  {         //  Oppgave 2C - Skriver status for ALLE oppgavene:
  for (int i = 1;  i <= siste_oppgave;  i++)  oppgavene[i].skriv(i);
  cout << '\n';
}


void ledig()  {       //  Oppgave 2D - Skriver status for alle LEDIGE oppgaver:
  for (int i = 1;  i <= siste_oppgave;  i++) 
      if (!oppgavene[i].fullt()) oppgavene[i].skriv(i);   // IKKE fullt.
  cout << '\n';
}


void ankommer()  {       //  Oppgave 2E - Person(er) ankommer for Ü jobbe:
  oppgavene[les("Oppgavenr", 1, siste_oppgave)].oppdater();
}


void skriv_til_fil()  {  //  Oppgave 2F - Skriver HELE datastrukturen til fil:
  ofstream utfil("OPPGAVER.DT2");                //  Aktuell fil Üpnes.
  utfil << siste_oppgave << '\n';                //  Skriver antall oppgaver.
  for (int i = 1;  i <= siste_oppgave;  i++)     //  Skriver en og en oppgave:
      oppgavene[i].skriv_til_fil(&utfil);
}


void les_fra_fil()  {    //  Oppgave 2G - Leser HELE datastrukturen fra fil:
  ifstream innfil("OPPGAVER.DTA");               //  Aktuell fil Üpnes.
  if (innfil)  {                                 //  Filen finnes:
     innfil >> siste_oppgave;  innfil.ignore();  //  Leser antall oppgaver.
     for (int i = 1;  i <= siste_oppgave;  i++)  //  Leser en og en oppgave:
         oppgavene[i].les_fra_fil(&innfil);
  } else                                         //  Filen finnes IKKE:
    cout << "\n\nFant ikke filen 'OPPGAVER.DTA'!\n\n";
}
