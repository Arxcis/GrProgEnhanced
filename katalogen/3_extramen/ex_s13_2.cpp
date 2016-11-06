//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S13_2.CPP

//  Lõsning til kontinuasjonseksamen i C++, 16.august 2013, oppgave 2.
//  Laget av Frode Haug, HiG, juli 2013.

//  Program som holder orden pÜ personene i en sosial gruppe,
//  og pÜ hvilke dager disse evt. kan mõtes/treffes i en gitt mÜned.
  

                        //  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <cstring>               //  strcpy, strlen
#include <cctype>                //  toupper
using namespace std;

                        //  CONST:
const int STRLEN      =    60;   //  Max. tekstlengde.
const int MAXDELTAGER =    20;   //  Max. antall deltagere i gruppen.
const int MINDAG      =    28;   //  Min. antall dager i en mÜned.
const int MAXDAG      =    31;   //  Max. antall dager i en mÜned.


class Deltager {        //  KLASSE:
  private:
    char navn[STRLEN];            //  Deltagerens navn.
    char mail[STRLEN];            //  Mailadresse.
    int  tlf;                     //  Telefon (fast eller mobil).
    bool dag[MAXDAG+1];           //  Kan (ikke) pÜ dag nr.'i'.

  public:                         //  Deklarasjon av medlemsfunksjoner:
    Deltager()          {  nullstill();  }
    void lesData();                              //  Oppgave 2A
    void nullstill();                            //  Oppgave 2C
    void lesDager();                             //  Oppgave 2D
    bool kanDag(int d)  {  return (dag[d]);  }
    void lesFraFil(istream* inn, int t);         //  Oppgave 2F
    void skrivTilFil(ostream* ut);
                           void skriv();
};

                    //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
void nyDeltager();               //  Oppgave 2A
void fjernDeltager();            //  Oppgave 2B
void nullstillAlle();            //  Oppgave 2C
void lesDager();                 //  Oppgave 2D
void finnMoteDager();            //  Oppgave 2E
void lesFraFil();                //  Oppgave 2F
void skrivTilFil();

                        //  GLOBALE VARIABLE:
Deltager deltagere[MAXDELTAGER+1]; //  Array med Deltager-objekter.
int sisteBrukt,                    //  Indeks for siste Deltager hittil brukt.
    antDager;                      //  Antall dager i aktuell mÜned.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   lesFraFil();                                     //  Oppgave 2F
   skrivMeny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  nyDeltager();            break;   //  Oppgave 2A
       case 'F':  fjernDeltager();         break;   //  Oppgave 2B
       case 'U':  nullstillAlle();         break;   //  Oppgave 2C
       case 'L':  lesDager();              break;   //  Oppgave 2D
       case 'D':  finnMoteDager();         break;   //  Oppgave 2E
       case 'T':  skrivTilFil();           break;
       default:   skrivMeny();             break;
     }
     kommando = les("ùnske");
   }
  skrivTilFil();
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Deltager::lesData()  {  //  Oppgave 2A - Leser egne hoveddata:
  les("Navn", navn, STRLEN);             //  Leser deltagerens navn,
  les("Mail", mail, STRLEN);             //    gateadresse og
  tlf = les("Tlf ", 10000000, 99999999); //    telefonnummer (fast/mobil).
  nullstill();                           //  Nullstiller dager kan delta/mõte.
//                              skriv();
}


void Deltager::nullstill()  {  //  Oppgave 2C - Nullstiller alle egne dager:
  for (int i = 1;  i <= MAXDAG;  i++)  dag[i] = false;
}


void Deltager::lesDager()  {   //  Oppgave 2D - Leser aktuelle egne mõtedager:
  int d;                                 //  Aktuell dag.
  nullstill();                           //  Nullstiller alle dager.
  cout << "\n\tSkriv dagnumre - avslutt med 0: ";
  cin >> d;                              //  Leser 1.mõtgedag.
  while (d  != 0)  {                     //  SÜ lenge flere dager:
    if (d >= 1  &&  d <= antDager)       //  Dag i rett intervall:
      dag[d] = true;                     //  Setter at kan mõte.
    else                                 //  Ulovlig dag(nummer):
      cout << "\n\n\tDagnummer " << d << " er utenfor lovlig intervall (1-"
           << antDager << ")!\n\n";
    cin >> d;                            //  Leser neste mõtedag.
  }                                      
  cout << "\n\n\tRegistrert at kan fõlgende dager:\n\t";
  for (int i = 1;  i <= antDager;  i++)  //  Skriver hva registrert:
      if (dag[i]) cout << "  " << i;
  cout << "\n\n";
}

                               //  Oppgave 2F - Leser egne data fra fil:
void Deltager::lesFraFil(istream* inn, int t)  {
  int kan;                                 //  Kan (ikke) mõte (0 eller 1).
  tlf = t;                                 //  Lagrer parameter i 'tlf'.
  (*inn).getline(navn, STRLEN);            //  Leser navn
  (*inn).getline(mail, STRLEN);            //    og mail.
  for (int i = 1;  i <= MAXDAG;  i++)  {   //  Leser HELE mÜneden:
     *inn >> kan;   dag[i] =  (kan == 1);  //  Omgjõr 0/1 til true/false.
  }
  (*inn).ignore();
//                                        skriv();
}

                               //  Skriver deltager til fil:
void Deltager::skrivTilFil(ostream* ut)  {    
  *ut << tlf << ' ' << navn << '\n' << mail << '\n';    //  3x hoveddata:
  for (int i = 1;  i <= MAXDAG;  i++)      //  MÜnedens dager:
    *ut << ((dag[i]) ? " 1" : " 0");       //  Skriver 1/0 for true/false.
  *ut << '\n';
}

                       void Deltager::skriv()  {
                         cout << navn << ",  " << mail << ",  " << tlf << '\n';
                         for (int j = 1;  j <= antDager;  j++)
                             if (dag[j]) cout << ' ' << j;
                         cout << '\n';
                       }


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN   = Ny deltager\n";
  cout << "\tF   = Fjern deltager\n";
  cout << "\tU   = nUllstill dagene for ALLE deltagerne\n";
  cout << "\tL   = Les dager for EN deltager\n";
  cout << "\tD   = finn felles Dager for aktuelle mõter/treff\n";
  cout << "\tT   = skriv Til fil\n";
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


void nyDeltager()  {         //  Oppgave 2A - Legger inn EN ny deltager:
  if (sisteBrukt < MAXDELTAGER)  {          //  Plass til flere deltagere:
     deltagere[++sisteBrukt].lesData();     //  Ny tas i bruk, leser selv data.
     cout << "\n\tNy deltager registrert som nr." << sisteBrukt << '\n';
  } else                                    //  Fullt:
    cout << "\n\tFullt med " << MAXDELTAGER << " deltagere allerede!\n\n";
}


void fjernDeltager()  {      //  Oppgave 2B - Fjerner EN deltager:
  int nr = les("Fjern deltager", 0, sisteBrukt);  //  Ber om deltagernummer.
  if (nr >= 1   &&  nr <= sisteBrukt)  {          //  Aktuell valgt:
     deltagere[nr] = deltagere[sisteBrukt--];   //  Flytter bakerste til "hull".
     cout << "\n\tDeltageren er fjernet/slettet!\n\n";
  } else                                          //  Ingen (0) valgt:
    cout << "\n\tOK - ingen deltager ble fjernet/slettet.\n\n";
}


void nullstillAlle()  {      //  Oppgave 2C - Nullstiller ALLE deltagerne:
  for (int i = 1;  i <= sisteBrukt;  i++)  deltagere[i].nullstill();
                                     // Leser antall dager i oppkommende mÜned:
  antDager = les("Antall dager i NESTE mÜned", MINDAG, MAXDAG);
}


void lesDager()  {           //  Oppgave 2D - Leser EN deltagers mõtedager:
  deltagere[les("Les dager for deltager nr", 1, sisteBrukt)].lesDager();
}

                             
void finnMoteDager()  {      //  Oppgave 2E - Finner dager der flest kan mõte:
  int antallKan[MAXDAG+1];           //  Antall som kan mõte hver mÜnedsdag.
  int i, j;                          //  Lõkkevariable.

  for (j = 1;  j <= MAXDAG;  j++)  antallKan[j] = 0;  // Nullstiller array.

  for (i = 1;  i <= sisteBrukt;  i++)                 //  For hver deltager,
      for (j = 1;  j <= antDager;  j++)               //    og hver mÜnedsdag:
         if (deltagere[i].kanDag(j))  antallKan[j]++; //  Tell opp antall som
                                                      //    kan mõte.
//              for (j = 1;  j <= antDager;  j++)  cout << ' ' << antallKan[j];
//              cout << "\n\n";

  cout << "\n\tFõlgende dager kan ALLE mõte:\n\t\t";  //  ALLE kan mõte
  for (j = 1;  j <= antDager;  j++)                   //    fõlgende dagr:
      if (antallKan[j] == sisteBrukt)  cout << "  " << j;
  cout << '\n';
                                                      //  Mange kan mõte:
  cout << "\n\n\tFõlgende dager kan MINST halvparten mõte:\n\t\t";
  for (j = 1;  j <= antDager;  j++)        //  Minst halvparten, men ikke alle:
      if (antallKan[j] >= (sisteBrukt/2)  &&  antallKan[j] < sisteBrukt)
         cout << ' ' << j << '(' << antallKan[j] << ')';
  cout << "\n\n";
}


void lesFraFil()  {          //  Oppgave 2F - Leser inn HELE datastrukturen:
  int tlf, nr = 0;
  ifstream innfil("SAMLING.DTA");      //  èpner aktuell fil.

  if (innfil)  {                       //  Filen finnes:
     innfil >> sisteBrukt >> antDager; //  Leser 2x globale data.
     innfil >> tlf;                    //  Leser (om mulig) 1.felt i 1.post.
     while (!innfil.eof()  &&  nr < MAXDELTAGER)   {  //  Ikke slutt, plass:
       innfil.ignore();                //  Forkaster blank.
       deltagere[++nr].lesFraFil(&innfil, tlf); // Leser resten selv.
       innfil >> tlf;                  //  Leser (om mulig) 1.felt i neste post.
     }
  } else                               //  Filen ble ikke funnet:
    cout << "\n\nFinner ikke filen 'SAMLING.DTA'!\n\n";
}


void skrivTilFil()  {        //  Skriver HELE datastrukturen til fil:
  ofstream utfil("SAMLING.DT2");              //  èpner aktuell fil.

  cout << "\n\nSkriver til filen 'SAMLING.DTA' .....\n\n";
  utfil << sisteBrukt << ' ' << antDager << '\n';
  for (int i = 1;  i <= sisteBrukt;  i++)     //  Deltagerne skriver seg selv:
      deltagere[i].skrivTilFil(&utfil);
}
