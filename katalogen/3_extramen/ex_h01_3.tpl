//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H01_3.TPL

//  Skjellettet/template for eksamen i C++, 5.desember 2001, oppgave 3.
//  Laget av Frode Haug, HiG, november 2001.


//  Programmet h†ndterer informasjon om ulike CD'er:
//       Utgivelses†r, artistnavn, tittel og sangtitler.
//  Disse dataene leses inn fra fil. 
//  Brukeren kan s† legge inn data om nye CD'er. 
//  Hun/han kan ogs† f† skrevet ut ulike oversikter over CD'enes data.


                             //  INCLUDE:
#include <iostream>          //  cin, cout
#include <fstream>           //  ifstream, ofstream
#include <cstring>           //  strlen, strcmp
#include <cctype>            //  toupper
#include <iomanip>           //  setw

using namespace std;

                             //  CONST:
const int MAX_CDER   = 500;  //  Max. antall CD'er i "kartoteket".
const int NVNLEN     =  30;  //  Max.lengde for en tekststreng.
const int MAX_SANGER =  20;  //  Max. sang(titler) p† en CD.

                             //  STRUCT:
struct CD  {                 //  Data om en CD:
  int  utgivelsesaar;        //    - Utgivelses†r.
  char navn[NVNLEN];         //    - Artistnavn.
  char tittel[NVNLEN];       //    - Tittel.
  int  ant_sanger;           //    - Antall sanger.
  char sangtittel[MAX_SANGER][NVNLEN];  //  - Tittel for sang nr.i.
};

                             //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les();
void les(char t[], char s[]);
int  les(char t[], int min, int max);
void ny();                   //  Oppgave 3a
void oversikt();             //  Oppgave 3b
void fjern();                //  Oppgave 3c
void les_fra_fil();          //  Oppgave 3d
void skriv();                //  Oppgave 3e 


                             //  GLOBALE VARIABLE:
CD  cder[MAX_CDER+1];        // Array av CD-struct'er.
int ant_cder;                // Aktuelt antall CD'er i kartoteket.

                            
int main()  {                //  MAIN:
  char valg;

  les_fra_fil();             //  Oppgave 3d

  skriv_meny();
  valg = les();

  while (valg != 'A')  {
    switch(valg)  {
      case 'N':  ny();         break;   //  Oppgave 3a
      case 'O':  oversikt();   break;   //  Oppgave 3b
      case 'F':  fjern();      break;   //  Oppgave 3c
      case 'S':  skriv();      break;   //  Oppgave 3e
      default :  skriv_meny(); break;
    }
    valg = les();
  }
  return 0;
}


                             //  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {         //  Skriver brukerens lovlige valg:
  cout << "\nF›lgende kommandoer er lovlige:";
  cout << "\n\tN - Ny CD";
  cout << "\n\tO - Oversikt over ALLE CD'ene";
  cout << "\n\tF - Fjern en CD";
  cout << "\n\tS - Skriv data om en gitt artist";
  cout << "\n\tA - Avslutt";
}


char les()  {                //  Leser, upcaser og returnerer ETT tegn:
  char ch;
  cout << "\nKommando:  ";
  cin >> ch;                 //  Leser.
  cin.ignore();              //  Forkaster neste tegn (='\n').
  return (toupper(ch));      //  Upcaser og returnerer.
}


void les(char t[], char s[]) {    //  Leser inn en tekst med lengde ulik 0.
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, NVNLEN);           //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}


int les(char t[], int min, int max)  {   // Leser et tall i et visst intervall.
  int n;
  do  {                                  // Skriver ledetekst:
    cout << '\t' << t << '(' << min << '-' << max << "): ";
    cin >> n;                            // Leser inn ett tall.
  } while(n < min  ||  n > max);         // Sjekker at i lovlig intervall.
  return n;                              // Returnerer innlest tall.
}


                                //  Leser inn alle data om en ny CD:
void ny()  {

    //  Oppgave 3A:  Lag innmaten
}


                                //  Skriver oversikt over HELE kartoteket:
void oversikt()  {

    //  Oppgave 3B:  Lag innmaten
}


                                //  Fjerner alle dataene om en gitt CD:
void fjern()  {

    //  Oppgave 3C:  Lag innmaten
}

                                //  Leser inn dataene om CD'ene fra
                                //    fil og inn i datastrukturen:
void les_fra_fil()  {

    //  Oppgave 3D:  Lag innmaten
}

                                //  Skriver ALLE data om EN artist,
                                //    MED eller UTEN sangtitlene:
void skriv()  {

    //  Oppgave 3E:  Lag innmaten
}
