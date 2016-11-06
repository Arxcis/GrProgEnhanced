//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H04_2.CPP

//  Løsningsforslag til eksamen i C++, 21.desember 2004, oppgave 2.
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

void Aktor::skriv(int n)  {  //  OPPGAVE 2A  -  Skriver ALLE aktørens data:
  cout << "\t\tAktør nr." << n << ":  ";        
  switch (profesjon)  {
    case skuespiller:  cout << "Skuespiller";  break;
    case sanger:       cout << "Sanger     ";  break;
    case danser:       cout << "Danser     ";  break;
  }
  cout << '\t' << navn << '\n';
}


void Aktor::ny()  {          //  OPPGAVE 2B  -  Leser inn data om ny aktør:
  char prof; 
  cout << "\tNavn: ";                         //  Leser navnet:
  cin.getline(navn, STRLEN);
  do  {                                       //  Leser profesjonen som tegn:
    cout << "\tProfesjon (S(kuespiller), (s)A(nger), D(anser)):  ";
    cin >> prof;  prof = toupper(prof);
  } while (prof != 'S'  &&  prof != 'A'  &&  prof != 'D');
  switch (prof)  {                            //  Gjør om til enum-type:
    case 'S':  profesjon = skuespiller;  break;
    case 'A':  profesjon = sanger;       break;
    case 'D':  profesjon = danser;       break;
  }
}


void Aktor::sett(char nvn[], char prof)  {   //  OPPGAVE 2G  -  Setter verdier:
  strcpy(navn, nvn);                         //  Setter ALLE egne atributter
  switch (prof)  {                           //    ut fra parametrene:
    case 'S':  profesjon = skuespiller;  break;
    case 'A':  profesjon = sanger;       break;
    case 'D':  profesjon = danser;       break;
  }
}


bool Aktor::har_profesjon(Profesjon prof)  {  //  Returnerer om har/er av en 
 return (profesjon == prof);                  //    gitt profesjon.
}

void Oppsetning::skriv()  {  //  OPPGAVE 2C og 2E - Skriver ALT om oppsetningen: 
  int i, nr;                                  //  Løkkevariabel og indeks.
  int j;                                      //  NY ifm.2E:  Løkkevariabel.
  Profesjon prof;                             //  NY ifm.2E:  Profesjonen
  cout << "\n\tNavn/tittel: " << navn         //  Skriver alle hoveddata:
       << "\n\tSpilletid:   " << start_dato << " - " << slutt_dato
       << "\n\tSal/scene:   " << sal
       << "\n\tAntall i ensemblet: " << antall << '\n';
  for (j = 0;  j <= 2;  j++) {            //  NY ifm.2E: For alle profesjonene:
      prof = (Profesjon) j;               //  NY ifm.2E: Caster om til profesj.
      for (i = 1;  i <= antall;  i++)  {  //  Går gjennom alle aktørene:
          nr = ensemble[i];               //  Henter aktørs indeks.
          if (aktorer[nr].har_profesjon(prof)) //  NY ifm.2E: Av rett profesjon:
             aktorer[nr].skriv(nr);            //  Skriver aktøren.
      } 
  }                                            //  NY ifm.2E
}

void Oppsetning::ny()  {     //  OPPGAVE 2D  - Leser inn data om ny oppsetning:
  int i;                                       //  ALLE hoveddataene leses inn:
  cout << "\tNavn:                  ";  cin.getline(navn,STRLEN);
  cout << "\tStart-dato (ååååmmdd): ";  cin >> start_dato;
  cout << "\tSlutt-dato (ååååmmdd): ";  cin >> slutt_dato;
  sal =    les("Sal           ", 1, 10);       
                             //  Leser "antall" ut fra hva som er mest aktuelt
                             //    (hvem av MAXENS/siste_aktor som er minst):
  antall = (MAXENS < siste_aktor) ? les("Antall i ensemblet", 1, MAXENS)
                                  : les("Antall i ensemblet", 1, siste_aktor);
  for (i = 1;  i <= antall;  i++)              //  Leser alle aktørenes indeks:
	  ensemble[i] = les("Aktørnr", 1, siste_aktor);
}


bool Oppsetning::spilles(int d)  {  //  OPPGAVE 2F  -  Returnerer om 'd' er
  return (start_dato <= d  &&  d <= slutt_dato);   //  inni tidsintervallet.
}


bool Oppsetning::lik(char t[])  {  //  Returnerer om har navnet 't':
  return (!strcmp(navn, t));
}

                             //  OPPGAVE 2G  -  Leser alt om oppsetning fra fil:
void Oppsetning::les_fra_fil(istream* inn, char nvn[])  {   
  int i;
  strcpy(navn, nvn);                //  Kopierer parameteren.
  *inn >> start_dato >> slutt_dato >>  sal >>  antall;  //  Leser flere heltall.
  for (i = 1;  i <= antall;  i++)   //  For alle aktørene:
      *inn >> ensemble[i];          //  Leser deres indeks.
  (*inn).ignore();                  //  Forkaster '\n' etter siste tall.
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


void skriv_aktorer()  {      //  OPPGAVE 2A  -  Skriver ALLE aktørene:
  int i;
  if (siste_aktor >= 1)           //   Det finnes noen aktørere i registeret:
     for (i = 1;  i <= siste_aktor;  i++)  //  Går gjennom ALLE aktørene:
         aktorer[i].skriv(i);              //  Ber hver enkelt skrive seg selv.
  else                                     //  Tomt aktør-register:
     cout << "\n\tAktør-registrert er tomt. Bruk kommandoen 'A' først.\n";
}


void ny_aktor()  {           //  OPPGAVE 2B  - Ny aktør registreres:
  if (siste_aktor < MAXAKT)  {       //  Plass til flere:
     cout << "\n\tNy aktør nr. " << ++siste_aktor << ":\n";  //  Teller opp.
     aktorer[siste_aktor].ny();      //  Ber den nye les resten selv.
  } else                             //  Fullt aktør-register:
     cout << "\n\tAktør-registrert er FULLT med "
          << MAXAKT << " stk. allerede!\n";
}

                        //  OPPGAVE 2C (og 2E)  - Skriver ALT om en oppsetning:
void skriv_oppsetning()  {   
  int nr;
  if (siste_oppsetning >= 1)  {      //   Finnes oppsetninger i registeret:
    if ((nr = les_og_finn_oppsetning()) != 0)  //  Om ønsket er å finne:
      oppsetninger[nr].skriv();                //  Ber den skrive seg selv.
    else                                       //  Oppsetningen finnes ikke:
      cout << "\n\tIngen oppsetning med dette navnet/tittelen!\n";
  } else                                       //  Tomt oppsetnings-register:
     cout << "\n\tOppsetning-registrert er tomt. Bruk kommandoen 'O' først.\n";
}


void ny_oppsetning()  {      //  OPPGAVE 2D  -  Ny oppsetning registreres:
  if (siste_oppsetning < MAXOPPS) {      //  Plass til flere:
     if (siste_aktor >= 1)              //  Finnes minst EN aktør:
         oppsetninger[++siste_oppsetning].ny(); //  Ber den nye les resten selv.
     else                               //  Tomt aktør-register:
         cout << "\n\tAktør-registrert er tomt. Bruk kommandoen 'A' først.\n";
  } else                                 //  Fullt oppsetnings-register:
     cout << "\n\tOppsetnings-registrert er FULLT med "
          << MAXOPPS << " stk. allerede!\n";
}

                             //  OPPGAVE 2F  -  Skriv ALLE oppsetninger
void skriv_oppsetninger_paa_tidspunkt()  {   //   som går en viss dato:
  int dato, i;
  bool utskrift = false;                 //  Ingen utskrift foreløpig.
  cout << "\tAktuell spille-dato (ååååmmdd): ";  cin >> dato;
  for (i = 1;  i <= siste_oppsetning;  i++)  //  Går gjennom alle oppsetningene:
      if (oppsetninger[i].spilles(dato)) {   //  Den spilles på denne datoen:
          utskrift = true;                   //  Minst en utskrift har foregått.
          oppsetninger[i].skriv();           //  Den skriver seg selv.
      }
  if (!utskrift)                             //  Ingen utskrift har forekommet:
      cout << "\n\tIngen oppsetninger på denne datoen.\n";
}


void les_fra_fil()  {     //  OPPGAVE 2G  -  Leser HELE datastrukturen fra fil:
  ifstream innfil1("aktor.dta");       //  Åpner to filer det skal leses fra:
  ifstream innfil2("oppsetn.dta");  
  char buffer[STRLEN];                 //  Tekstlinje-buffer.
  char tegn;                           //  Tegn (S, A, D) for profesjonen.
 
  siste_aktor = siste_oppsetning = 0;  //  Nullstiller.

  if (innfil1  && innfil2)  {          //  Begge filene finnes.
                                       //  Leser inn alle aktørene:
     innfil1 >> tegn;                  //  Prøver å lese "profesjonstegnet".
     while (!innfil1.eof() &&  siste_aktor < MAXAKT)  {  // Ikke slutt og plass:
        innfil1.ignore();              //  Forkaster ETT blankt tegn.
        innfil1.getline(buffer, STRLEN);  //  Leser resten av linjen (navnet).
        aktorer[++siste_aktor].sett(buffer, tegn);  //  Aktøren oppdateres.
        innfil1 >> tegn;               //  Prøver å lese "profesjonstegnet".
     }
                                       //  Leser inn alle oppsetningene:
     innfil2.getline(buffer, STRLEN);    //  Prøver å lese navnet.
	                                     //  Ikke slutt og plass:
     while (!innfil2.eof() &&  siste_oppsetning < MAXOPPS)  {
                                             //  Ber objektet lese resten selv:
       oppsetninger[++siste_oppsetning].les_fra_fil(&innfil2, buffer);
       innfil2.getline(buffer, STRLEN);  //  Prøver å lese navnet.
     }
  } else                                 // MINST en fil finnes ikke:
    cout << "\n\tMinst en av filene 'AKTOR.DTA'/'OPPSETN.DTA' finnes ikke!\n";
}
