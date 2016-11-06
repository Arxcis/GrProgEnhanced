//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H04_2.TPL

//  Skjellett/omriss for eksamen i C++, 21.desember 2004, oppgave 2.
//  Laget av Frode Haug, HiG, desember 2004.


//  Program som holder orden på ulike aktører (skuespillere, sangere, dansere),
//  og hvilke oppsetninger/ensembler hver enkelt av dem til enhver tid inngår i.


                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream
#include <cstring>            //  strcmp, strcpy
#include <cctype>             //  toupper

using namespace std;

                        //  CONST:
const int MAXAKT   = 500;     //  Max. antall aktører i datastrukturen.
const int MAXOPPS  = 200;     //  Max. antall oppsetninger i datastrukturen.
const int MAXENS   =  30;     //  Max. ant. aktører i en oppsetning (ensemble).
const int STRLEN   =  40;     //  Max. lengde på tekststrenger.

                        //  ENUM:
enum Profesjon  { skuespiller, sanger, danser };

                        //  KLASSER:
class Aktor  {                //  Aktør:
  private:
    char navn[STRLEN];        //  Navn.
    Profesjon profesjon;      //  Aktørens profesjon (skuesp, sanger, danser).
  public:
    void skriv(int n);        //  Deklarasjon av medlemsfunksjoner:
    void ny();
    void sett(char nvn[], char prof);
    bool har_profesjon(Profesjon prof);
};


class Oppsetning  {           //  Oppsetning:
  private:
    char navn[STRLEN];        //  Navn.
    int  start_dato,          //  Start- og sluttdato for oppsetningen, 
         slutt_dato,          //     begge på formen:  ååååmmdd .
         sal,                 //  Sal/scenen det spilles på/i: Tall fra 1-10.
         antall;              //  Antall aktører i ensemblet (oppsetningen).
    int ensemble[MAXENS+1];   //  Indeksene i "aktorer" for de i ensemblet.

  public:
    void skriv();             //  Deklarasjon av medlemsfunksjoner:
    void ny();
    bool spilles(int d);
    bool lik(char t[]);
    void les_fra_fil(istream* inn, char nvn[]);
};


                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les_kommando();
int  les(char t[], int min, int max);
int  les_og_finn_oppsetning();

void skriv_aktorer();
void ny_aktor();
void skriv_oppsetning();
void ny_oppsetning();
void skriv_oppsetninger_paa_tidspunkt();
void les_fra_fil();

                        //  GLOBALE VARIABLE:
int siste_aktor;                     //  Indeksen for siste brukte aktør.
int siste_oppsetning;                //  Indeksen for siste brukte oppsetning.
Aktor aktorer[MAXAKT+1];             //  Array med Aktor-objekter.
Oppsetning oppsetninger[MAXOPPS+1];  //  Array med Oppsetning-objekter.

                        
int main()  {           //  HOVEDPROGRAM:
   char kommando;
   
   les_fra_fil();                               //  Oppgave 2g

   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'S':  skriv_aktorer();     break;   //  Oppgave 2a
       case 'A':  ny_aktor();          break;   //  Oppgave 2b
       case 'T':  skriv_oppsetning();  break;   //  Oppgave 2c  og  2e
       case 'O':  ny_oppsetning();     break;   //  Oppgave 2d
       case 'P':  skriv_oppsetninger_paa_tidspunkt(); break;   //  Oppgave 2f
       default:   skriv_meny();        break;
     }
     kommando = les_kommando();
   }
  cout << "\n\n";
  return 0;
}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:

void Aktor::skriv(int n)  {  //  Skriver ALLE aktørens data:
        //  Oppgave 2A:  Lag innmaten
}


void Aktor::ny()  {          //  Leser inn data om ny aktør:
        //  Oppgave 2B:  Lag innmaten
}


void Aktor::sett(char nvn[], char prof)  {   //  Setter verdier:
        //  Oppgave 2G:  Lag innmaten
}


bool Aktor::har_profesjon(Profesjon prof)  {  //  Returnerer om har/er av en 
 return (profesjon == prof);                  //    gitt profesjon.
}


void Oppsetning::skriv()  {  //  Skriver ALT om oppsetningen: 
        //  Oppgave 2C og 2E:  Lag innmaten
}

void Oppsetning::ny()  {     //  Leser inn data om ny oppsetning:
        //  Oppgave 2D:  Lag innmaten
}


bool Oppsetning::spilles(int d)  {  //  Returnerer om 'd' er inni tidsintervallet:
        //  Oppgave 2F:  Lag innmaten
}


bool Oppsetning::lik(char t[])  {  //  Returnerer om har navnet 't':
  return (!strcmp(navn, t));
}

                             //  Leser alt om oppsetning fra fil:
void Oppsetning::les_fra_fil(istream* inn, char nvn[])  {   
        //  Oppgave 2G:  Lag innmaten
}


                        //  DEFINISJON AV FUNKSJONER:
		  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tS = Skriv alle data om en aktør\n";
  cout << "\tA = ny Aktør\n";
  cout << "\tT = skriv alle data om en oppseTning\n";
  cout << "\tO = ny Oppsetning\n";
  cout << "\tP = skriv alle oppsetninger på et gitt tidsPunkt\n";
  cout << "\tQ = quit/avslutt\n";
}


char les_kommando()  {       //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi ønske:  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}


int les(char t[], int min, int max)  {   // Leser et tall i et visst intervall.
  int n;
  do  {                                  // Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;                            // Leser inn ett tall.
  } while(n < min  ||  n > max);         // Sjekker at i lovlig intervall.
  return n;                              // Returnerer innlest tall.
}


int les_og_finn_oppsetning()  {    //  Leser og evt. finner oppsetnings indeks:
  char nvn[STRLEN];
  int i;
  cout << "\tOppsetnings-navn:  ";   //  Leser aktuell oppsetnings navn:
  cin.getline(nvn, STRLEN);
  for (i = 1;  i <= siste_oppsetning;  i++)     //  Leter etter denne:
      if (oppsetninger[i].lik(nvn)) return i;   //  Match: returnerer indeks.
  return 0;                                     //  Ingen treff/match.
}


void skriv_aktorer()  {      //  Skriver ALLE aktørene:
        //  Oppgave 2A:  Lag innmaten
}


void ny_aktor()  {           //  Ny aktør registreres:
        //  Oppgave 2B:  Lag innmaten
}

                             //  Skriver ALT om en oppsetning:
void skriv_oppsetning()  {   
        //  Oppgave 2C og 2E:  Lag innmaten
}


void ny_oppsetning()  {      //  Ny oppsetning registreres:
        //  Oppgave 2D:  Lag innmaten
}

                             //  Skriv ALLE oppsetninger
void skriv_oppsetninger_paa_tidspunkt()  {   //   som går en viss dato:
        //  Oppgave 2F:  Lag innmaten
}


void les_fra_fil()  {     //  Leser HELE datastrukturen fra fil:
        //  Oppgave 2G:  Lag innmaten
}
