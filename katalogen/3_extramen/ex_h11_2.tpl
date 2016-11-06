//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H11_2.TPL

//  Skjellettet/template for eksamen i C++, 6.desember 2011, oppgave 2.
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
       default:   skriv_meny();            break;
     }
     kommando = les("ùnske");
   }
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


void Bedrift::skriv()  {     //  Skriver ALLE medlemsdata:
        //  Oppgave 2A:  Lag innmaten
}

                             //  Setter ALLE medlemsdata:
void Bedrift::les_data(char nvn[])  {    
        //  Oppgave 2B:  Lag innmaten
}

                          // Legger til et antall treningstimer pÜ dag nr.'d':
void Bedrift::registrer(int d)  {          
        //  Oppgave 2D:  Lag innmaten
}

                             //  Returnerer 'true/false' til om noen har
bool Bedrift::noen_innom(int d)  {  //   hatt treningstime(r) pÜ dag nr.'d'.
        //  Oppgave 2E:  Lag innmaten
}

                             //  Skriver faktura for en mÜned til fil:
void Bedrift::faktura(ostream* ut)  {               
        //  Oppgave 2F:  Lag innmaten
}

                             //  Leser alt om en bedrift fra fil:
void Bedrift::les_fra_fil(istream* inn, char nvn[])  {
        //  Oppgave 2G:  Lag innmaten
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


void skriv_bedrift() {       //  Skriver (om mulig) EN gitt bedrift:
        //  Oppgave 2A:  Lag innmaten
}


void ny_bedrift() {          //  Legger (om mulig) inn en ny bedrift:
        //  Oppgave 2B:  Lag innmaten
}


void fjern_bedrift() {       //  Sletter (om mulig) en bedrift:
        //  Oppgave 2C:  Lag innmaten
}

                       //  Registerer treningstimer for ansatte fra en bedrift:
void registrer_time(int d) {
        //  Oppgave 2D:  Lag innmaten
}

                  //  For bedrifter som har hatt ansatte innom pÜ treningstimer
void ansatte_innom_en_dag() {   //  dag nr.'d', skrives navn og dette antallet:
        //  Oppgave 2E:  Lag innmaten
}

                       //  Skriver alle bedriftene og faktura for hver av dem:
void maanedsskifte() {   
        //  Oppgave 2F:  Lag innmaten
}


void les_fra_fil()  {        //  Leser inn HELE datastrukturen:
        //  Oppgave 2G:  Lag innmaten
}

