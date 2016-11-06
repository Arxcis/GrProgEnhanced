//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S14_2.TPL

//  Skjellettet/template for kontinuasjonseksamen i C++, 8.august 2014, oppgave 2.
//  Laget av Frode Haug, HiG, juli 2014.


//  Program som holder orden på kunder og deres bestilling 
//  av vindusglass med ulike mål og fra ulike produsenter.
  

                        //  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <iomanip>               //  setw
#include <cstring>               //  strcpy, strlen
#include <cctype>                //  toupper
using namespace std;

                        //  CONST:
const int STRLEN     =   40;     //  Tekstlengde.
const int MAXGLASS   =   20;     //  Max. ulike glassmål.
const int MAXKUNDE   =  400;     //  Max. antall kunder.
const int KVMPRIS    = 1300;     //  Pris pr.kvm - uansett produsent.


class Kunde {           //  KLASSER:
  private:
    char navn[STRLEN];           //  Navn.
    char adr[STRLEN*4];          //  Gate- og postadresse.
    int  tlf,                    //  Telefon.
         startDato,              //  Arbeidets startdato (på formen: MMDD).
         antDager;               //  Antall dager på/til arbeidet.
    int  glass[MAXGLASS];        //  Antall bestilt av glass nr.i.
 
  public:                        //  Deklarasjon av medlemsfunksjoner:
    Kunde();
    void skriv();                           //  Oppgave 2B (og 2C)
    void skrivEnkelt();                     //  Oppgave 2B
    void skrivOmfattende();                 //  Oppgave 2C
    void lesData();                         //  Oppgave 2D
    void faktura();                         //  Oppgave 2E
    void lesFraFil(ifstream & inn, int t);  //  Oppgave 2F
    int  hentBestilt(int n);                //  Oppgave 2G
};


class Glass {
  private:
    char produsent[STRLEN];      //  Produsentens navn.
    int  bredde, hoyde;          //  Glassets mål (bredde/høyde) i mm(!).

  public:                        //  Deklarasjon av medlemsfunksjoner:
    Glass();
    void skriv();                           //  Oppgave 2A
    float kvm();                            //  Oppgave 2E
    void lesFraFil(ifstream & inn);         //  Oppgave 2F
};



                    //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);

void skrivAlleGlassene();        //  Oppgave 2A
void skrivKundeEnkelt();         //  Ferdiglaget (Oppgave 2B)
void skrivKundeOmfattende();     //  Ferdiglaget (Oppgave 2C)
void nyKunde();                  //  Oppgave 2D
void faktura();                  //  Ferdiglaget (Oppgave 2E)
void lesFraFil();                //  Oppgave 2F
void glasStatistikk();           //  Oppgave 2G

                        //  GLOBALE VARIABLE:
Kunde kundene[MAXKUNDE+1];       //  Array med Kunde-objekter.
Glass glassene[MAXGLASS];        //  Array med Glass-objekter
int sisteKunde;                  //  Indeks for siste Kunde hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   lesFraFil();                                     //  Oppgave 2F
   skrivMeny();
   kommando = les("Ønske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'G':  skrivAlleGlassene();     break;   //  Oppgave 2A
       case 'E':  skrivKundeEnkelt();      break;   //  Oppgave 2B
       case 'O':  skrivKundeOmfattende();  break;   //  Oppgave 2C
       case 'N':  nyKunde();               break;   //  Oppgave 2D
       case 'F':  faktura();               break;   //  Oppgave 2E
       case 'S':  glasStatistikk();        break;   //  Oppgave 2G
       default:   skrivMeny();             break;
     }
     kommando = les("Ønske");
   }
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

Kunde::Kunde()  {             //  Initierer/nullstiller ALLE datamedlemmer:
   strcpy(navn, "");  strcpy(adr, "");  tlf = startDato = antDager = 0;
   for (int i = 0;  i < MAXGLASS;  i++)  glass[i] = 0;
}


void Kunde::skriv()  {        //  Skriver enkeltdataene:
        //  Oppgave 2B (og 2C):  Lag innmaten
}

                    //  Skriver alle data, inkl. TOTALT antall bestilte glass:
void Kunde::skrivEnkelt()  { 
        //  Oppgave 2B:  Lag innmaten
}

                              //  Skriver alle data, inkl. hvor
void Kunde::skrivOmfattende()  {     //  mange bestilt av de ulike glassene.
        //  Oppgave 2C:  Lag innmaten
}


void Kunde::lesData()  {      //  Leser ALLE egne data:
        //  Oppgave 2D:  Lag innmaten
}


void Kunde::faktura()  {     //  Skriver faktura/regning/totalsum:
        //  Oppgave 2E:  Lag innmaten
}

                            //  Leser alt om kunden fra fil:
void Kunde::lesFraFil(ifstream & inn, int t)  {       
        //  Oppgave 2F:  Lag innmaten
}

                            //  Returnerer antall bestilte glass av nr.'n'.    
int Kunde::hentBestilt(int n)  {  
        //  Oppgave 2G:  Lag innmaten
}


Glass::Glass()  {          //  Initierer/nullstiller ALLE datamedlemmer:
  strcpy(produsent, "");  bredde = hoyde =  0;
}


void Glass::skriv()  {     //  Skriver ALLE data om glasset:
        //  Oppgave 2A:  Lag innmaten
}


float Glass::kvm()  {      //  Retunerer glassets areal i kvm:
        //  Oppgave 2E:  Lag innmaten
}


void Glass::lesFraFil(ifstream & inn)  {  // Leser ALLE egne data:
        //  Oppgave 2F:  Lag innmaten
}



// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tG   = skriv alle Glassene\n";
  cout << "\tE   = skriv alle kundene - Enkelt\n";
  cout << "\tO   = skriv alle kundene - Omfattende\n";
  cout << "\tN   = Ny kunde\n";
  cout << "\tF   = Faktura\n";
  cout << "\tS   = Statistikk for/over alle glassene\n";
  cout << "\tQ   = Quit/avslutt\n";
}


char les(char t[])  {        //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << '\n' << t << ":  ";   //  Skriver medsendt ledetekst.
  cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
  return (toupper(ch));         //  Upcaser og returnerer.
}

                               //  Leser et tall i et visst intervall:
int les(const char t[], const int min, const int max)  { 
  int n;
  do  {                                  // Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;   cin.ignore();            // Leser inn ett tall.
  } while(n < min  ||  n > max);         // Sjekker at i lovlig intervall.
  return n;                              // Returnerer innlest tall.
}

                               //  Leser en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {  
  do  {
    cout << '\t' << t << ": ";	cin.getline(s, LEN); //  Ledetekst og leser.
  } while (strlen(s) == 0);		//  Sjekker at tekstlengden er ulik 0.
}


void skrivAlleGlassene()  {    //  Skriver alle data om alle glassene:
        //  Oppgave 2A:  Lag innmaten
}


void skrivKundeEnkelt()  {      //  Skriver hoveddata om EN kunde (oppgave 2B):
  kundene[les("Enkle data om kunde nr.", 1, sisteKunde)].skrivEnkelt();
}


void skrivKundeOmfattende()  {     //  Skriver ALT om EN kunde (oppgave 2C):
  kundene[les("Omfattende data om kunde nr.", 1, sisteKunde)].skrivOmfattende();
}


void nyKunde()  {           //  Legger (om mulig) inn en ny kunde:
        //  Oppgave 2D:  Lag innmaten
}


void faktura()  {           //  Skriver en kundes faktura/regning (oppgave 2E):
  kundene[les("Faktura/regningen for kunde nr.", 1, sisteKunde)].faktura();
}


void lesFraFil()  {         //  Leser inn HELE datastrukturen:
        //  Oppgave 2F:  Lag innmaten
}

                             //  Skriver totalantallet bestilt av
void glasStatistikk()  {     //    hvert glassmål og hvem bestilt mest av:
        //  Oppgave 2G:  Lag innmaten
}
