//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S15_2.CPP

//  Løsningsforslag til eksamen i C++, 12.august 2015, oppgave 2.
//  Laget av Frode Haug, HiG, juli 2015.

//  Programmet holder orden på ulike sykkellag og rytterne/syklistene
//  på disse lagene, samt hvem av syklistene som har brutt sykkelrittet.

 
			//  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <cstring>               //  strcpy, strcmp, strlen
#include <cctype>                //  toupper
using namespace std;


			//  CONST:
const int STRLEN     =     60;     //  Max. tekstlengde.
const int MAXLAG     =     22;     //  Max. antall sykkellag.
const int MAXPRLAG   =      9;     //  Max. antall ryttere pr. lag.
const int KOMP       =     10;     //  Kompensasjon (nr.11 er indeks 1).
                                   //  Max. antall ryttere/syklister:
const int MAXRYTTERE = MAXLAG * (MAXPRLAG + 1);   //  = 220


class Lag  {		//  KLASSE:
  private:
    int  nr;                     //  Nummer/indeks.
    char navn[STRLEN];           //  Navn.
    char land[STRLEN/15];        //  Land/nasjonalitet (tre bokstaver).
    char tlf[STRLEN/2];          //  Kontaktinfo: Telefon
    int  antallRegistrert;       //  Antall ryttere hittil registrert på laget.

  public:                        //  Deklarasjon av medlemsfunksjoner:
    Lag();                       //  (Ferdiglaget nedenfor)
    bool finnes();               //  (Ferdiglaget nedenfor)
    void enRytterTil();          //  (Ferdiglaget nedenfor)
    void skriv();                            //  Oppgave 2B
    void nytt(int n);                        //  Oppgave 2C
    void skrivTilFil(ofstream & ut);         //  Oppgave 2E
    void lesFraFil(int n, ifstream & inn);   //  Oppgave 2F
    int  antallManglendeRyttere();           //  Oppgave 2G
};


class Rytter  {
  private:
    char navn[STRLEN];           //  Syklistens navn.
    char land[STRLEN/15];        //  Land/nasjonalitet (tre bokstaver).
    bool brutt;                  //  Brutt (eller fortsatt med).

  public:                        //  Deklarasjon av medlemsfunksjoner:
    Rytter();                    //  (Ferdiglaget nedenfor)
    bool finnes();               //  (Ferdiglaget nedenfor)
    void skriv();                            //  Oppgave 2A
    void ny();                               //  Oppgave 2D
    void skrivTilFil(ofstream & ut);         //  Oppgave 2E
    void lesFraFil(ifstream & inn);          //  Oppgave 2F
    void bruttRittet();                      //  Oppgave 2G
};


			//  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les();
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
void skrivEnRytter();            //  Oppgave 2A
void skrivEttLag();              //  Oppgave 2B
void nyttLag();                  //  Oppgave 2C
void nyRytter();                 //  Oppgave 2D
void skrivTilFil();              //  Oppgave 2E
void lesFraFil();                //  Oppgave 2F
void rytterBrutt();              //  Oppgave 2G
void statusLagene();             //  Oppgave 2G


			//  GLOBALE VARIABLE:
Lag    lagene[MAXLAG+1];            //  Array med Lag-objekter.
Rytter ryttere[MAXRYTTERE];         //  Array med Rytter-objekter.      

							  
int main()  {			//  HOVEDPROGRAM:
   char kommando;

   lesFraFil();                                     //  Oppgave 2F

   skrivMeny();
   cout << "\nØnske:  ";  kommando = les();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'L':  nyttLag();               break;   //  Oppgave 2C
       case 'R':  nyRytter();              break;   //  Oppgave 2D
       case 'S':  skrivEnRytter();         break;   //  Oppgave 2A
       case 'E':  skrivEttLag();           break;   //  Oppgave 2B
       case 'B':  rytterBrutt();           break;   //  Oppgave 2G
       case 'T':  statusLagene();          break;   //  Oppgave 2G
       default:   skrivMeny();             break;
     }
     cout << "\nØnske:  ";  kommando = les();
   }
  skrivTilFil();                                    //  Oppgave 2E
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

Lag::Lag()   {			//  Constructor initierer alle datamedlemmer:
  nr = 0;  strcpy(navn, "");  strcpy(tlf, "");  antallRegistrert = 0;
}


bool Lag::finnes()  {           //  Returnerer om objektet er i bruk eller ei
  return (strcmp(navn, ""));    //     (er navnet IKKE blankt er det i bruk).
}


void Lag::enRytterTil()  {      //  En rytter til er registrert på/i laget:
  ++antallRegistrert;
}


void Lag::skriv()  {            //  Oppgave 2B - Skriver ALT om laget:
  int start = (nr-1) * 10;             //  Beregner rytternes RELLE startindeks.
                                       //  Skriver ALLE egne data: 
  cout << "\n\t" << navn << ", " << land << ", tlf: " << tlf 
       << "\n\t" << antallRegistrert << " ryttere/syklister registrert:\n";
  for (int i = 1;  i <= MAXPRLAG;  i++)       //  For ALLE aktuelle ryttere:
      if (ryttere[start+i].finnes())  {       //  En gitt rytter finnes:
         cout << "\t\t" << start+KOMP+i << ':';   //  Skriver AKTUELT startnr.
         ryttere[start+i].skriv();                //  Rytter skriver seg selv.
      }  
}


void Lag::nytt(int n)  {        //  Oppgave 2C - Leser ALLE egne data:
  nr = n;                              //  Gjemmer unna parameter (egen indeks).
  antallRegistrert = 0;                //  Nullstiller.
  les("Navn", navn, STRLEN);           //  Leser 3x tekster:
  les("Land", land, STRLEN/15);
  les("Tlf ", tlf,  STRLEN/2);
}


void Lag::skrivTilFil(ofstream & ut)  {   //  Oppgave 2E - Skriver ALT eget
  ut << land << ' ' << antallRegistrert   //               til fil:
     << ' ' << tlf << '\n' << navn << '\n';
}


void Lag::lesFraFil(int n, ifstream & inn)  {  //  Oppgave 2F - Leser ALT eget
  nr = n;                                      //               fra fil:
  inn >> land >> antallRegistrert;   inn.ignore();
  inn.getline(tlf,  STRLEN/2);
  inn.getline(navn, STRLEN);
}


int  Lag::antallManglendeRyttere()  {     //  Oppgave 2G - Returnerer antall
   return (MAXPRLAG - antallRegistrert);  //            gjenstående ryttere å 
}                                         //            registrerer på laget.


// --------------------------------------------------------------------------

Rytter::Rytter()  {             //  Constructor initierer alle datamedlemmer:
  strcpy(navn, "");  strcpy(land, "");  brutt = false; 
}    


bool Rytter::finnes()  {        //  Returnerer om objektet er i bruk eller ei
  return (strcmp(navn, ""));    //     (er navnet IKKE blankt er det i bruk).
}


void Rytter::skriv()  {         //  Oppgave 2A - Skriver ALT om rytteren:
  cout << '\t' << navn << ", " << land << ((brutt)? ", BRUTT" : "") << '\n';
}


void Rytter::ny()  {            //  Oppgave 2D - Leser ALLE egne data:
  brutt = false;                       //  Initierer.
  les("Navn", navn, STRLEN);           //  Leser 2x tekster:
  les("Land", land, STRLEN/15);
}

                                //  Oppgave 2E - Skriver ALT eget til fil:
void Rytter::skrivTilFil(ofstream & ut)  { 
  ut << ((brutt) ? "0" : "1") << ' ' << land << ' ' << navn << '\n';
}

                                //  Oppgave 2F - Leser ALT eget fra fil:
void Rytter::lesFraFil(ifstream & inn)  {     
  int nr;
  inn >> nr >> land;  inn.ignore();   brutt = (nr == 0);
  inn.getline(navn, STRLEN); 
}


void Rytter::bruttRittet()  {   //  Oppgave 2G - Registrerer at rytter brutt:
  cout << "\tHar rytteren VIREKELIG brutt (j/N): ";  //  Ønsker virkelig?
  if (les() == 'J')                               //  Ja:
     brutt = true;                                //     Registrerer at brutt.
  else                                            //  Nei:
     cout << "\tOK, ingen endring har skjedd.\n";  //    Tilbakemelding.
}



// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tL  = nytt Lag\n";
  cout << "\tR  = ny Rytter\n";
  cout << "\tS  = Skriv en rytter\n";
  cout << "\tE  = skriv HELE Ett lag\n";
  cout << "\tB  = rytter Brutt\n";
  cout << "\tT  = sTatus lagene\n";
  cout << "\tQ  = Quit/avslutt\n";
}


char les()  {			//  Henter ett ikke-blankt upcaset tegn:
  char ch;
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
  } while (strlen(s) == 0);             //  Sjekker at tekstlengden er ulik 0.
}


void skrivEnRytter()  {  //  Oppgave 2A - Skriver ALLE data om EN rytter:
                         //     Leser startnummer. Konverterer til REELL indeks: 
  int nr = les("Skriv alt om rytter nr", 11, MAXRYTTERE+MAXPRLAG) - KOMP;
  if (ryttere[nr].finnes())   //  Rytteren finnes:
     ryttere[nr].skriv();     //  Skriver selv alle egne data.
  else
     cout << "\n\tIngen rytter ennå registrert på dette nummeret!\n\n";
}


void skrivEttLag()  {        //  Oppgave 2B - Skriver ALLE data om ETT lag:
  int nr = les("Skriv ALT om lag nr", 1, MAXLAG);   //  Leser lagnummer.
  if (lagene[nr].finnes())              //  Laget finnes:
     lagene[nr].skriv();                //  Skriver selv alle egne data.
  else
     cout << "\n\tIngen lag ennå registrert på dette nummeret!\n\n";
}


void nyttLag()  {            //  Oppgave 2C - Registrerer nytt lag:
  int nr = les("Nytt lag nr", 1, MAXLAG);  //  Leser lagnummer.
  if (!lagene[nr].finnes())                //  Laget finnes:
     lagene[nr].nytt(nr);                  //  Leser selv alle egne data.
  else
     cout << "\n\tLag allerede registrert på dette nummeret!\n\n";
}


void nyRytter()  {          //  Oppgave 2D - Registrerer ny rytter:
                            //  Leser rytterens aktuelle nummer:
  int lagNr, nr = les("Nytt rytter nr", 11, MAXRYTTERE+MAXPRLAG);
  if (nr % 10)  {           //  Rytternummer ender IKKE på '0' (null).
                            //  Beregner lagets nummer og REELL indeks:
     lagNr = nr / 10;   nr -= KOMP; 
     if (!ryttere[nr].finnes())  {      //  Rytteren finnes IKKE allerede:
        if (lagene[lagNr].finnes())  {  //  Laget finnes:
           lagene[lagNr].skriv();       //  Skriver ALT om laget.
                                        //  Ønsker å legges til dette lager?:
           cout << "\tTilhører rytteren dette laget (J/n): ";
           if (les() != 'N')  {               //  "Ja":
              ryttere[nr].ny();               //  Leser ALLE egne data.
              lagene[lagNr].enRytterTil();    //  Lagets antall telles opp.
           }
        } else
          cout << "\n\tRytterens lag finnes ikke ennå!\n\n";
     } else
       cout << "\n\tRytter allerede registrert på dette nummeret!\n\n";
  } else
     cout << "\n\tRytternummer kan ikke ende på '0' (null)!\n\n";
}


void skrivTilFil()  {      //  Oppgave 2E - Skriver HELE datastrukturen til fil:
  int i;
  ofstream utfil("SYKKELLAG.DT2");
  for (i = 1;  i <= MAXLAG;  i++)         //  For hvert lag:
      if (lagene[i].finnes())  {          //  Laget finnes:
         utfil << i << ' ';               //  Skriver dets indeks,
         lagene[i].skrivTilFil(utfil);    //    og skriver selv ALLE egne data.
      }

  ofstream utfil2("RYTTERE.DT2");
  for (i = 1;  i <= MAXRYTTERE;  i++)     //  For hver rytter/syklist:
      if (ryttere[i].finnes())  {         //  Rytteren finnes: 
         utfil2 << i << ' ';              //  Skriver dens REELLE indeks,
         ryttere[i].skrivTilFil(utfil2);  //    og skriver selv ALLE egne data.
      } 
}


void lesFraFil()  {          //  Oppgave 2F - Leser HELE datastrukturen fra fil:
  int nr;                               //  Lagets/rytterens nummer/indeks.
  ifstream innfil("SYKKELLAG.DTA");     //  Åpner aktuell fil.

  if (innfil)  {                            //  Filen finnes:
     innfil >>  nr;                         //  Leser (om mulig) 1.felt i post.
     while (!innfil.eof())  {               //  Filen ennå ikke slutt:
       lagene[nr].lesFraFil(nr, innfil);    //  Leser resten selv.
       innfil >>  nr;                       //  Leser (om mulig) 1.felt i post.
     }
  } else                                    //  Filen ble ikke funnet:
    cout << "\n\nFinner ikke filen 'SYKKELLAG.DTA'!\n\n";

  ifstream innfil2("RYTTERE.DTA");
  if (innfil2)  {                           //  Filen finnes:
     innfil2 >> nr;                         //  Leser (om mulig) REELL indeks.
     while (!innfil2.eof())  {              //  Filen ennå ikke slutt:  
       ryttere[nr].lesFraFil(innfil2);      //  Leser resten selv.
       innfil2 >> nr;                       //  Leser (om mulig) REELL indeks.
     }
  } else                                     //  Filen ble ikke funnet:
    cout << "\n\nFinner ikke filen 'RYTTERE.DTA'!\n\n";
}


void rytterBrutt()  {    //  ( Oppgave 2G - Registrerer at rytter har brutt )
                         //     Leser startnummer. Konverterer til REELL indeks: 
  int nr = les("Brutt rytter nr", 11, MAXRYTTERE+MAXPRLAG) - KOMP;   
  if (ryttere[nr].finnes())                        //  Rytteren finnes:
     ryttere[nr].bruttRittet();                    //  Registrerer at har brutt.
  else
     cout << "\n\tIngen rytter ennå registrert på dette nummeret!\n\n";
}


void statusLagene()  {         //  Oppgave 2G - Skriver status for ALLE lagene:
  int i, antall;                   //  Løkkevariabel, antall manglende ryttere.
  cout << "\n\tStatus for alle lagene:\n";
  for (i = 1;  i <= MAXLAG;  i++)  {    //  For hvert lag:
     cout << "\t\t" << i << ": ";       //  Skriver dets indeks.
     if (!lagene[i].finnes())           //  Laget finnes IKKE (ennå):
        cout << "\tFINNES IKKE";          
     else if ((antall = lagene[i].antallManglendeRyttere()))  // Ryttere mangler  
        cout << '\t' << antall << " ryttere å registrere";
     else                               //  Alt OK (finnes og alle registrert):
        cout << "OK";
     cout << '\n';
  }
}