//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H12_2.CPP

//  L›sningsforslag til eksamen i C++, 4.desember 2012, oppgave 2.
//  Laget av Frode Haug, HiG, november 2012.

//  Program som holder orden p† en maskinkj›rers oppdrag (br›yting og str›ing)
//  hos ulike faste kunder i l›pet av en vintersesong.
  

                        //  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <cstring>               //  strcpy, strlen
#include <cctype>                //  toupper
using namespace std;

                        //  CONST:
const int STRLEN     =     80;   //  Max. tekstlengde.
const int MAXKUNDER  =    100;   //  Max. antall kunder.
const int MAXOPPDRAG =     50;   //  Max. antall oppdrag hos EN kunde.


class Kunde {         //  KLASSE:
  private:
    char navn[STRLEN/2];          //  Kundens navn.
    char adr[STRLEN];             //  Gateadresse.
    int  tlf;                     //  Telefon (fast eller mobil).
    int  antOppdrag;              //  Antall oppdrag (hittil) hos kunden.
    int  oppdrag[MAXOPPDRAG+1];   //  Datoene for oppdragene (p† formen: MMDD).

  public:                     //  Deklarasjon av medlemsfunksjoner:
    Kunde()         {  antOppdrag = 0;  }
    void lesData();                              //  Oppgave 2B
    void skriv();                                //  Oppgave 2C
    bool registrer(int d);                       //  Oppgave 2D
    void skriv2(int n);                          //  Oppgave 2F
    void lesFraFil(istream* inn, char nvn[]);    //  Oppgave 2G
    void skrivTilFil(ostream* ut);
};

                    //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
int  lesDato();                  //  Oppgave 2A
void nyKunde();                  //  Oppgave 2B og 2E
void skrivAlleKunder();          //  Oppgave 2C
void registrerOppdrag(int d);    //  Oppgave 2D
void skrivEnKunde();             //  Oppgave 2F
void lesFraFil();                //  Oppgave 2G
void skrivTilFil();

                        //  GLOBALE VARIABLE:
Kunde kunder[MAXKUNDER+1];       //  Array med Kunde-objekter.
int sisteBrukt;                  //  Indeks for siste Kunde hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   int dato;                     //  Dagens dato p† formen: MMDD.
   char kommando;

   lesFraFil();                                     //  Oppgave 2G
   dato = lesDato();
   skrivMeny();
   kommando = les("nske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  nyKunde();               break;   //  Oppgave 2B og 2E
       case 'A':  skrivAlleKunder();       break;   //  Oppgave 2C
       case 'R':  registrerOppdrag(dato);  break;   //  Oppgave 2D
       case 'S':  skrivEnKunde();          break;   //  Oppgave 2F
       case 'T':  skrivTilFil();           break;
       default:   skrivMeny();             break;
     }
     kommando = les("nske");
   }
  skrivTilFil();
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Kunde::lesData()  {           //  Oppgave 2B - Leser alle kundens data:
  les("Navn", navn, STRLEN/2);           //  Leser kundens navn,
  les("Gadr", adr,  STRLEN);             //    gateadresse og
  tlf = les("Tlf ", 10000000, 99999999); //    telefonnummer (fast/mobil).
}


void Kunde::skriv()  {             //  Oppgave 2C - Skriver kundens data:
  cout << navn << ", " << adr << ", " << tlf      //  (Skriver IKKE datoene
       << "  #oppdrag: " << antOppdrag << '\n';   //     for oppdragene.)
}


bool Kunde::registrer(int d)  {   //  Oppgave 2D - Registrerer ETT nytt oppdrag:
  if (antOppdrag < MAXOPPDRAG)  {        //  Plass til flere registreringer:
     oppdrag[++antOppdrag] = d;          //  Teller opp og legger inn.
     return true;                        //  Returnerer at utf›rt.
  } else                                 //  Fullt med oppdrag:
     return false;                       //  Returnerer at IKKE utf›rt.
}

                                   //  Oppgave 2F - Skriver ALLE oppdrag eller
void Kunde::skriv2(int n)  {       //               kun EN gitt m†ned:
  int mnd, dag;                    //  M†ned og dag (fra MMDD).
  bool utskrift = false;           //  Ingen utskrift hittil.
  cout << "\n\t";
  skriv();                         //  Skriver alle andre data enn oppdragene.
  for (int i = 1;  i <= antOppdrag;  i++)  {   //  G†r gjennom registreringene:
      mnd = oppdrag[i] / 100;                  //  Henter ut m†nedsnummer.
      dag = oppdrag[i] % 100;                  //  Henter ut dagnummer.
      if (n == 0  ||  n == mnd)  {      //  Skrive alle (0) eller aktuell m†ned:
         utskrift = true;                      //  Utskrift har forekommet.
         cout << "\t\t" << dag << '/' << mnd << '\n';
      }
  }                                     //  Ingen utskrift, 
  if (!utskrift  &&  antOppdrag != 0)   //    men oppdrag er registrert/finnes:
     cout << "\n\tIngen oppdrag denne m†neden.\n";
}

                                   //  Oppgave 2G - Leser kunden fra fil:
void Kunde::lesFraFil(istream* inn, char nvn[])  {   
  strcpy(navn, nvn);                    //  Kopierer inn medsendt navn.
  (*inn).getline(adr, STRLEN);          //  Leser adresse,
  *inn >> tlf >> antOppdrag;            //     telefon og antall oppdrag.
                                        //  Leser datoene for alle oppdragene:
  for (int i = 1;  i <= antOppdrag;  i++)  *inn >> oppdrag[i];
  (*inn).ignore();                      //  Forkaster avsluttende '\n';
}


void Kunde::skrivTilFil(ostream* ut)  {       //  Skriver kunden til fil:
  *ut << navn << '\n' << adr << '\n' << tlf << ' ' << antOppdrag;
  for (int i = 1;  i <= antOppdrag;  i++)
      *ut << ' ' << oppdrag[i];
  *ut << '\n';
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN   = Ny kunde\n";
  cout << "\tA   = skriv Alle kunder\n";
  cout << "\tR   = Registrer oppdrag\n";
  cout << "\tS   = Skriv EN kunde\n";
  cout << "\tT   = skriv Til filer\n";
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

                             //  Oppgave 2A - Leser dag og m†ned.
int  lesDato()  {            //               Returnerer p† formen MMDD:
 int dag = les("Dag  ", 1, 31);      //  Leser aktuelt og "lovlig" dagnummer.
 int mnd = les("M†ned", 1, 12);      //  Leser aktuelt og "lovlig" m†nedsnummer.
 return (mnd*100 + dag);             //  Bygger og returnerer p† formen: MMDD
}

                            
void nyKunde()  {            //  Oppgave 2B og 2E -
  Kunde temp;                //      Legger/smetter (om mulig) inn en ny kunde:
  int nr;
  if (sisteBrukt < MAXKUNDER)  {            //  Plass til flere kunder:
     kunder[++sisteBrukt].lesData();        //  Ny tas i bruk, leser selv data.
     cout << "\n\tNy kunde lagt inn/registrert som nr." << sisteBrukt << '\n';
                             //  Oppgave 2E er de †tte neste linjene:
     if (les("Flytte lengre frem (j/N)") == 'J')  {       //  Vil smette inn:
        nr = les("Smettes inn som nr", 1, sisteBrukt-1);  //  Smettes inn hvor?
        temp = kunder[sisteBrukt];                //  Gjemmer unna den siste.
        for (int i = sisteBrukt;  i > nr;  i--)   //  Flytter alle aktuelle
            kunder[i] = kunder[i-1];              //    opp ETT hakk.
        kunder[nr] = temp;                        // Smetter inn den bakerste.
       cout << "\n\tNy kunde er smettet inn som nr." << nr << '\n';
     }
  } else                                    //  Fullt:
    cout << "\n\tFullt med " << MAXKUNDER << " kunder allerede!\n\n";
}


void skrivAlleKunder()  {    //  Oppgave 2C - Skriver data om ALLE kundene:
  char ch;                                     //  Tegn fra brukeren.
  for (int i = 1;  i <= sisteBrukt;  i++)  {   //  G†r gjennom alle kundene:
      cout << '\t' << i << ": ";               //  Skriver (indeks)nummer.
      kunder[i].skriv();                       //  Kunden skriver resten selv.
      if (i % 20 == 0)  {                      //  Stopper for hver 20.utskrift:
        cout << "\n\n\n\t\t\t\t\t\tSkriv ett tegn .....";  cin  >> ch;
     }
  }
}


void registrerOppdrag(int d)  {   // Oppgave 2D - Registrer oppdrag p† kunde(r):
  int start = les("Start med kundenr", 1, sisteBrukt),        // Leser kunde-
      slutt = les("Slutt med kundenr", start, sisteBrukt);    //   interallet.
  cout << "\n\tRegistrer oppdrag utf›rt hos kunden";          // Felles tekst.
  if (start < slutt)  cout << "e " << start  << '-' << slutt; // Tekst om flere.
  cout << " .....\n";                                         // Felles tekst.
  for (int i = start;  i <= slutt;  i++)      //  G†r gjennom kunde-intervallet:
      if (!kunder[i].registrer(d))            //  Kunde registrerer, om fullt:
         cout << "\n\tAllerede registrert " << MAXOPPDRAG
              << " (=max.antall) oppdrag hos kunde nr." << i << ".\n";
}


void skrivEnKunde()  {       //  Oppgave 2F - Skriv (alt) om EN kunde:
  int nr = les("Skriv data om kunde nr", 1, sisteBrukt);   //  Leser kundenr.
                                           //  Kunden skriver ALLE oppdrag eller
  kunder[nr].skriv2(les("M†nedsnummer (0=alle)", 0, 12));  //  en gitt m†nred.
}


void lesFraFil()  {          //  Oppgave 2G - Leser inn HELE datastrukturen:
  char buffer[STRLEN];                     //  Kundens navn.
  ifstream innfil("VINTER.DTA");           //  pner aktuell fil.

  if (innfil)  {                           //  Filen finnes:
     innfil.getline(buffer, STRLEN/2);     //  Leser (om mulig) 1.felt i post.
                                           //  Ikke slutt og plass til flere:
     while (!innfil.eof()  &&  sisteBrukt < MAXKUNDER)   {
       kunder[++sisteBrukt].lesFraFil(&innfil, buffer); // Leser selv.
       innfil.getline(buffer, STRLEN/2);   //  Leser (om mulig) 1.felt i post.
     }
  } else                                   //  Filen ble ikke funnet:
    cout << "\n\nFinner ikke filen 'VINTER.DTA'!\n\n";
}


void skrivTilFil()  {        //  Skriver HELE datastrukturen til fil:
  ofstream utfil("VINTER.DT2");            //  pner aktuell fil.

  cout << "\n\nSkriver til filen 'VINTER.DTA' .....\n\n";
  for (int i = 1;  i <= sisteBrukt;  i++)  //  Alle kundene skriver seg selv:
      kunder[i].skrivTilFil(&utfil);
}
