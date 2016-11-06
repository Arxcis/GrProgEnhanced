//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H11_2.CPP

//  Lõsningsforslag til eksamen i C++, 6.desember 2011, oppgave 2.
//  Laget av Frode Haug, HiG, november 2011.

//  Program som holder orden pÜ bedrifter/firmaer og antall timer ansatte i
//  bedriften har hatt pÜ ett gitt treningssenteret den siste kalendermÜneden.
  

                        //  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <iomanip>               //  setw
#include <cstring>               //  strcpy, strcmp, strlen
#include <cctype>                //  toupper
using namespace std;

                        //  CONST:
const int STRLEN     =     80;   //  Max. tekstlengde.
const int MAXBEDR    =    100;   //  Max. antall bedrifter i datastrukturen.
const int MNDLEN     =     31;   //  Max. antall dager i en mÜned.
const int MAXTIMER   =     10;   //  Max. antall treningstimer pr.registrering.
const int TIMESATS   =    120;   //  Timepris i kroner.



class Bedrift {         //  KLASSE:
  private:
    char navn[STRLEN/2];          //  Bedriftens navn.
    char adr[STRLEN];             //  Adresse (gateadr, postnr, poststed).
    int  tlf;                     //  Telefon (fast eller mobil).
    int  timer[MNDLEN+1];         //  Antall treningstimer pÜ mÜnedens dager.
    void nullstill();             //  Nullstiller 'timer'-arrayen.

  public:                    //  Deklarasjon av medlemsfunksjoner:
    bool heter(char nvn[]);
    void skriv2(int dag);
    void skriv();                                //  Oppgave 2A
    void les_data(char nvn[]);                   //  Oppgave 2B
    void registrer(int dag);                     //  Oppgave 2D
    bool noen_innom(int dag);                    //  Oppgave 2E
    void faktura(ostream* ut);                   //  Oppgave 2F
    void les_fra_fil(istream* inn, char nvn[]);  //  Oppgave 2G
    void skriv_til_fil(ostream* ut);             //  Extra
};

                    //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
int  finn_bedrift(char nvn[]);

void skriv_bedrift();         //  Oppgave 2A
void ny_bedrift();            //  Oppgave 2B
void fjern_bedrift();         //  Oppgave 2C
void registrer_time(int d);   //  Oppgave 2D
void ansatte_innom_en_dag();  //  Oppgave 2E
void maanedsskifte();         //  Oppgave 2F
void les_fra_fil();           //  Oppgave 2G
void skriv_til_fil();         //  Extra

                        //  GLOBALE VARIABLE:
Bedrift bedrifter[MAXBEDR+1];    //  Array med Bedrift-objekter.
int siste_brukt;                 //  Indeks for siste Bedrift hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   int dagnr;                 //  Dagens dagnr i mÜneden (1-31).
   char kommando;

   les_fra_fil();                               //  Oppgave 2G
   dagnr = les("Dagnummer", 1, MNDLEN);
   skriv_meny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'S':  skriv_bedrift();         break;   //  Oppgave 2A
       case 'N':  ny_bedrift();            break;   //  Oppgave 2B
       case 'F':  fjern_bedrift();         break;   //  Oppgave 2C
       case 'R':  registrer_time(dagnr);   break;   //  Oppgave 2D
       case 'H':  ansatte_innom_en_dag();  break;   //  Oppgave 2E
       case 'M':  maanedsskifte();         break;   //  Oppgave 2F
       case 'T':  skriv_til_fil();         break;   //  Extra
       default:   skriv_meny();            break;
     }
     kommando = les("ùnske");
   }
  skriv_til_fil();                              //  Extra
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Bedrift::nullstill()  {         //  Nullstiller 'timer'-arrayen:
  for (int i = 1;  i <= MNDLEN; i++)  timer[i] = 0;
}


bool Bedrift::heter(char nvn[])  {   //  Returnerer 'true/false' til om
  return (!strcmp(navn, nvn));       //    bedriften heter 'nvn' eller ei.
}


void Bedrift::skriv2(int dag)  {    // Skriver bedr.navn og ant.timer pÜ 'dag':
  cout << '\t' << navn << "\tant.timer:  " << timer[dag] << '\n';
}


void Bedrift::skriv()  {     //  Oppgave 2A - Skriver ALLE medlemsdata:
  int i;
  cout << "\n\tNavn:  " << navn << "\tTlf:  " << tlf
       << "\n\tAdr:   " << adr << "\n\t";
  for (i = 1;  i <= MNDLEN;  i++)  cout << setw(2) << i;  cout << "\n\t";
  for (i = 1;  i <= MNDLEN;  i++)  cout << setw(2) << timer[i];  cout << '\n';
}

                             //  Oppgave 2B - Setter ALLE medlemsdata:
void Bedrift::les_data(char nvn[])  {    
  strcpy(navn, nvn);                         //  Kopierer inn 'navn'.
  les("Adresse", adr, STRLEN);               //  Leser adressen.
  tlf = les("Telefon", 10000000, 99999999);  //  Leser korrekt telefonnr.
  nullstill();                               //  Nullstiller 'timer'.
}

                             //  Oppgave 2D - Legger til et antall trenings-
void Bedrift::registrer(int d)  {          //   timer pÜ dag nr.'d':
  timer[d] += les("Ant.timer", 1, MAXTIMER);
}

                             //  Oppgave 2E - Returnerer 'true/false' til om
bool Bedrift::noen_innom(int d)  {         //   noen har hatt treningstime(r)
  return ((timer[d] > 0) ? true : false);  //   pÜ dag nr.'d'.
// evt. bare:   return (timer[d]);
}

                         //  Oppgave 2F - Skriver faktura for en mÜned til fil:
void Bedrift::faktura(ostream* ut)  {               
  int total = 0;                           //  Totalt antall timer i mÜneden.
  *ut << "Navn:     " << navn << '\n' << "Adresse:  " << adr << '\n';
  for (int i = 1;  i <= MNDLEN;  i++)  {   //  GÜr gjennom mÜnedens dager:
	  *ut << '\t' << setw(2) << i << ": " << setw(2) << timer[i];
          total += timer[i];               //  Oppsummerer totalt antall timer.
          if (i % 5 == 0)  *ut << '\n';    //  Linjeskift for hver 5.dag.
  }
  *ut << "\n\tTotalt #timer: " << total    //  Skriver totalt timer og pris:
	  << "\tTotalpris: " << total*TIMESATS << "\n\n\n";
  nullstill();                             //  Nullstiller alle timene igjen.
}

                             //  OPPGAVE 2G - Leser alt om en bedrift fra fil:
void Bedrift::les_fra_fil(istream* inn, char nvn[])  {
  strcpy(navn, nvn);                     //  Kopierer inn navnet.
  (*inn).getline(adr, STRLEN);           //  Leser adresse
  (*inn) >> tlf;                         //    og telefonnummer.
  for (int i = 1;  i <= MNDLEN;  i++)    //  Leser antall timer pÜ hver av
      (*inn) >> timer[i];                //    mÜnedens dager.
  (*inn).ignore();                       //  Skipper '\n'.
}

                             //  EXTRA - Skriver alt om bedriften til fil:
void Bedrift::skriv_til_fil(ostream* ut)  {
  *ut << navn << '\n' << adr << '\n' << tlf << '\n';
  for (int i = 1;  i <= MNDLEN;  i++)
	  *ut << ' ' << timer[i];
  *ut << '\n';
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tS   = Skriv en gitt bedrift\n";
  cout << "\tN   = Ny bedrift\n";
  cout << "\tF   = Fjern/slett bedrift\n";
  cout << "\tR   = Registrer time(r) pÜ en bedrift\n";
  cout << "\tH   = Hvilke bedrifter har hatt ansatte pÜ treningstime(r)\n";
  cout << "\tM   = MÜnedsskifte (lage fakturaer)\n";
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


int finn_bedrift(char nvn[])  {     //  Returnerer (om mulig) indeksen for
  for (int i = 1;  i <= siste_brukt;  i++)    //  bedriften med navn lik 'nvn'.
          if (bedrifter[i].heter(nvn))  return i;
  return 0;                         //  Ingen match - returnerer '0'.
}


void skriv_bedrift() {     //  Oppgave 2A - Skriver (om mulig) EN gitt bedrift:
  char nvn[STRLEN/2];                    //  Bedriftens navn.
  int nr;                                //  Bedriftens indeks i 'bedrifter'.
  les("Skriv bedrift", nvn, STRLEN/2);   //  Leser õnsket bedriftsnavn.
  if ((nr = finn_bedrift(nvn)) != 0)     //  Bedriften finnes:
          bedrifter[nr].skriv();         //  Den skriver seg selv til skjermen.
  else                                   //  Den finnes ikke:
     cout << "\n\tIngen bedrift med dette navnet!\n\n";
}


void ny_bedrift() {       //  Oppgave 2B - Legger (om mulig) inn en ny bedrift:
  char nvn[STRLEN/2];                       //  Bedriftens navn.
  if (siste_brukt < MAXBEDR)  {             //  Plass til flere bedrifter:
     les("Ny bedrift", nvn, STRLEN/2);      //  Leser õnsket bedriftsnavn.
     if (finn_bedrift(nvn) == 0)  {         //  Finnes IKKE fra fõr:
        bedrifter[++siste_brukt].les_data(nvn);            //  Ny tas i bruk,
        cout << "\n\tNy bedrift lagt inn/registrert.\n\n"; //  leser selv data.
     } else                                 //  Finnes allerede:
        cout << "\n\tFinnes bedrift allerede med dette navnet!\n\n";
  } else                                    //  Fullt:
    cout << "\n\tFullt med " << MAXBEDR << " bedrifter allerede!\n\n";
}


void fjern_bedrift() {     //  Oppgave 2C - Sletter (om mulig) en bedrift:
  char nvn[STRLEN/2];                    //  Bedriftens navn.
  int nr;                                //  Bedriftens indeks i 'bedrifter'.
  les("Slett bedrift", nvn, STRLEN/2);   //  Leser õnsket bedriftsnavn.
  if ((nr = finn_bedrift(nvn)) != 0)  {  //  Bedriften finnes:
          bedrifter[nr] = bedrifter[siste_brukt--];  //  Flytter bakerste.
      cout << "\n\tBedriften er fjernet/slettet.\n\n";
  } else                                 //  Finnes ikke:
     cout << "\n\tIngen bedrift med dette navnet!\n\n";
}

                           //  Oppgave 2D - Registerer treningstimer for 
void registrer_time(int d) {             //     ansatte fra en bedrift:
  char nvn[STRLEN/2];                    //  Bedriftens navn.
  int nr;                                //  Bedriftens indeks i 'bedrifter'.
  les("Time(r) for bedriften ", nvn, STRLEN/2);  //  Leser õnsket bedriftsnavn.
  if ((nr = finn_bedrift(nvn)) != 0)     //  Bedriften finnes:
          bedrifter[nr].registrer(d);    //  Registrerer treningstimer dag 'd'.
  else                                   //  Finnes ikke:
     cout << "\n\tIngen bedrift med dette navnet!\n\n";
}

                           //  Oppgave 2E - For bedrifter som har hatt ansatte
void ansatte_innom_en_dag() {           //   innom pÜ treningstimer dag nr.'d',
  int i, d = les("Dag", 1, MNDLEN);     //   skrives navn og dette antallet:
  for (i = 1;  i <= siste_brukt;  i++)
          if (bedrifter[i].noen_innom(d)) bedrifter[i].skriv2(d);
}

                           //  Oppgave 2F -  Skriver alle bedriftene og
void maanedsskifte() {     //                  faktura for hver av dem:  
  cout << "\nDette vil bl.a. medfõre at alle timeregistreringene nullstilles.";
  if (les("ùnsker du virkelig Ü utfõre dette (j/N)") == 'J')  {  // Fortsette?
     ofstream utfil("TRENFAKT.DTA");             //  èpner fil.
     for (int i = 1;  i <= siste_brukt;  i++)    //  For hver bedrift:
             bedrifter[i].faktura(&utfil);       //  Skrives faktura.
     cout << "\n\tFakturaer er skrevet til filen 'TRENFAKT.DTA'.\n\n";
  } else                                         //  Angret/kansellerte:
    cout << "\n\tOK - ingenting har skjedd .....\n\n";
}


void les_fra_fil()  {        //  Oppgave 2G - Leser inn HELE datastrukturen:
  char buffer[STRLEN];                     //  Bedriftens navn.
  ifstream innfil("TRENTIME.DTA");         //  èpner aktuell fil.

  if (innfil)  {                           //  Filen finnes:
     innfil.getline(buffer, STRLEN);       //  Leser (om mulig) 1.felt i post.
                                           //  Ikke slutt og plass til flere:
     while (!innfil.eof()  &&  siste_brukt < MAXBEDR)   {
       bedrifter[++siste_brukt].les_fra_fil(&innfil, buffer); // Leser selv.
       innfil.getline(buffer, STRLEN);     //  Leser (om mulig) 1.felt i post.
     }
  } else                                   //  Filen ble ikke funnet:
    cout << "\n\nFinner ikke filen 'TRENTIME.DTA'!\n\n";
}


void skriv_til_fil()  {      //  Extra - Skriver datastrukturen til fil:
  int i;
  ofstream utfil("TRENTIME.DT2");        //  èpner aktuell fil.

  for (i = 1;  i <= siste_brukt;  i++)   //  Alle bedriftene skriver seg selv:
      bedrifter[i].skriv_til_fil(&utfil);
}
