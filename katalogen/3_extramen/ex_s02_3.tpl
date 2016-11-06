//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S02_3.TPL

//  Skjellettet/template for eksamen i C++, 9.august 2003, oppgave 3.
//  Laget av Frode Haug, HiG, juli 2002.
//  En god del endret/modifisert av FrodeH, HiG, høsten 2003.


//  Programmet håndterer informasjon om ulike bøker (data om deres tittel
//  og forfatter). Brukeren kan:
//      - legge til en ny bok og dens forfatter
//      - fjerne/slette en gitt bok/forfatter
//      - få utskrift om alle bøkene eller en gitt bok/forfatter.


                        //  INCLUDE:
#include <iostream>          //  cin, cout
#include <iomanip>           //  setw
#include <fstream>           //  ifstream
#include <cstring>           //  strlen, strcmp, strcpy
#include <cctype>            //  toupper

using namespace std;

                        //  CONST:
const int MAX_BOK   = 200;   //  Max. antall titler i datastrukturen.
const int MAX_FORF  =  50;   //  Max. antall forfattere i datastrukturen.
const int STRLEN    =  40;   //  Max.lengde for en tekststreng.

                        //  KLASSER:
class Bok  {                
  private:                   //  Data om en bok:
    char tittel[STRLEN];     //   - Tittel.
    char ISBN[STRLEN/2];     //   - ISBN-nummer.
    int  forf_nr;            //   - Nummer i arrayen "forfattere".
  
  public:
    void skriv(int n, bool forf);       //  LAG INNMAT ifm. oppgave 3a (og 3c)
    void skriv_alt();                   //  LAG INNMAT ifm. oppgave 3b
    void les_data(int nr);              //  LAG INNMAT ifm. oppgave 3e
    void sett(int nr)        {  forf_nr = nr;  }
    bool skrevet_av(int nr)  {  return (forf_nr == nr);  }
};


class Forfatter  {          
  private:                   //  Data om en forfatter:
    char navn[STRLEN];       //   - Navn
    char adr[STRLEN];        //   - Adresse (gate, poststed, land).
    char tlf[STRLEN/2];      //   - Telefon (inkl. evt. landskode).
  
  public:
    void skriv();                       //  LAG INNMAT ifm. Bok::skriv_alt()
    void les_data(char nvn[]);          //  LAG INNMAT ifm. oppgave 3e
    void hent(char nvn[])  {  strcpy(nvn, navn);         } // Returnerer navn.
    bool er_lik(char t[])  {  return (!strcmp(navn, t)); } // Sammenligner.
};

                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les();
void les(char t[], char s[], int LEN);
int  les(char t[], int min, int max);
int  finn(char t[]);
void skriv_alle_boker();       //  Oppgave 3a
void skriv_bok();              //  Oppgave 3b
void skriv_alt_av_forfatter(); //  Oppgave 3c
void slett_bok();              //  Oppgave 3d
void slett_forfatter();        //  Oppgave 3f
void ny_bok();                 //  Oppgave 3e

                        //  GLOBALE VARIABLE:
Bok       boker[MAX_BOK+1];       //  Array av Bok-objekter.
Forfatter forfattere[MAX_FORF+1]; //  Array av Forfatter-objekter.
int       siste_bok,         //  Aktuelt antall bøker i datastrukturen.
          siste_forfatter;   //  Aktuelt antall forfattere i datastrukturen.

                            
int main()  {           //  HOVEDPROGRAMMET:
  char valg;

  skriv_meny();
  valg = les();
  while (valg != 'Q')  {
    switch(valg)  {
      case 'N':  ny_bok();                  break;   //  Oppgave 3e
      case 'A':  skriv_alle_boker();        break;   //  Oppgave 3a
      case 'B':  skriv_bok();               break;   //  Oppgave 3b
      case 'F':  skriv_alt_av_forfatter();  break;   //  Oppgave 3c
      case 'T':  slett_bok();               break;   //  Oppgave 3d
      case 'S':  slett_forfatter();         break;   //  Oppgave 3f
      default :  skriv_meny();              break;
    }
    valg = les();
  }
  cout << "\n\n";
  return 0;

}

                        //  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {         //  Skriver brukerens lovlige valg:
  cout << "\nFølgende kommandoer er lovlige:";
  cout << "\n\tN - Ny bok";
  cout << "\n\tA - skriv data om Alle bøkene";
  cout << "\n\tB - skriv alle data om en Bok";
  cout << "\n\tF - skriv alle data om en Forfatter og alle dens bøker";
  cout << "\n\tT - sletT en bok";
  cout << "\n\tS - Slett (om mulig) en forfatter";
  cout << "\n\tQ - Quit / avslutt";
}


char les()  {                //  Leser, upcaser og returnerer ETT tegn:
  char ch;
  cout << "\n\nKommando:  ";
  cin >> ch;  cin.ignore();  //  Leser og forkaster neste tegn (='\n').
  return (toupper(ch));      //  Upcaser og returnerer.
}


void les(char t[], char s[], int LEN) {  //  Leser inn en ikke-blank tekst:
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, LEN);          //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}


int les(char t[], int min, int max)  {   // Leser et tall i et visst intervall.
  int n;
  do  {                                  // Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;                            // Leser inn ett tall.
  } while(n < min  ||  n > max);         // Sjekker at i lovlig intervall.
  return n;                              // Returnerer innlest tall.
}

                                  //  Ut fra en forfatters navn, så returneres
                                  //    vedkommendes indeks i "forfattere",
int finn(char t[])  {             //    evt. '0' om han/hun ikke finnes.
  for (int i = 1;  i <= siste_forfatter;  i++)
      if (forfattere[i].er_lik(t))  return i;
  return 0;
}


void skriv_alle_boker()  {
	//  Oppgave 3a:  Lag innmaten
}


void skriv_bok()  {
	//  Oppgave 3b:  Lag innmaten
}


void skriv_alt_av_forfatter()  {
	//  Oppgave 3c:  Lag innmaten
}

void slett_bok()  {
	//  Oppgave 3d:  Lag innmaten
}


void ny_bok()  {
	//  Oppgave 3e:  Lag innmaten
}


void slett_forfatter()  {
	//  Oppgave 3f:  Lag innmaten
}
