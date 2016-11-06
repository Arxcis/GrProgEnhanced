//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S12_2.TPL

//  Skjellettet/template for kontinuasjonseksamen i C++, 18.august 2012, oppgave 2.
//  Laget av Frode Haug, HiG, juni 2012.

//  Program som holder orden p† ulike fjelloverganger som inng†r i et sykkell›p,
//  l›pets fjelletapper, og hvilke av dem som g†r oppom hvilke fjelloverganger.
  

                        //  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <iomanip>               //  setw
#include <cstring>               //  strcpy, strcmp, strlen
#include <cctype>                //  toupper
using namespace std;

                        //  CONST:
const int STRLEN     =     40;   //  Max. tekstlengde.
const int MAXETAPPER =     10;   //  Max. antall etapper.
const int MAXTOPPER  =     50;   //  Max. antall topper.
const int MAXOPPOM   =     10;   //  Max. topper p† EN etappe.


class Topp {            //  KLASSE:
  private:
    char  navn[STRLEN];      //  Toppens navn.
    int   moh,               //  Toppens meter over havet.
          hoyde;             //  Toppens meter fra dalbunnen/stigningsstart.
    float lengde;            //  Veilengde (i km) fra dalbunnen/stigningsstart.

  public:                    //  Deklarasjon av medlemsfunksjoner:
    void skriv();                         //  Oppgave 2A
    void skriv_navn();                    //  Oppgave 2B
    void les_data(char nvn[]);            //  Oppgave 2C
    bool heter(char nvn[]);               //  (Ferdigkodet)
    void les_fra_fil(ifstream & inn);     //  Oppgave 2G
};


class Etappe  {
  private:
    char  startsted[STRLEN];  //  Etappens startsted/-by.
    char  sluttsted[STRLEN];  //  Etappens sluttsted/-by.
    float lengde;             //  Etappens fulle lengde (i km).
    int   ant_topper;         //  Totalt antall topper oppom p† etappen.
    int   topper[MAXOPPOM+1]; //  Toppenes numre i 'toppene'-arrayen.

  public:                    //  Deklarasjon av medlemsfunksjoner:
    void skriv();                         //  Oppgave 2B
    void les_data();                      //  Oppgave 2D
    bool gaar_oppom(int n);               //  Oppgave 2E
    bool start_slutt(char nvn[]);         //  Oppgave 2F
    void les_fra_fil(ifstream & inn);     //  Oppgave 2G
};

                    //  DEKLARASJON AV FUNKSJONER:
void  skriv_meny();
char  les(char t[]);
float les(const char t[], const int min, const int max);
void  les(const char t[], char s[], const int LEN);
int   finn_topp(char nvn[]);
void  skriv_topper();          //  Oppgave 2A
void  skriv_etappe();          //  Oppgave 2B
void  ny_topp();               //  Oppgave 2C
void  ny_etappe();             //  (Ferdigkodet - men kallende skal kodes)
void  oppom();                 //  Oppgave 2E
void  starter_slutter();       //  Oppgave 2F
void  les_fra_fil();           //  Oppgave 2G


                        //  GLOBALE VARIABLE:
Topp   toppene[MAXTOPPER+1];    //  Array med Topp-objekter.
Etappe etappene[MAXETAPPER+1];  //  Array med Etappe-objekter.
int    siste_topp;              //  Indeks for siste Topp hittil brukt.
int    siste_etappe;            //  Indeks for siste Etappe hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   les_fra_fil();                               //  Oppgave 2G
   skriv_meny();

   kommando = les("nske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'P':  skriv_topper();      break;   //  Oppgave 2A
       case 'A':  skriv_etappe();      break;   //  Oppgave 2B
       case 'T':  ny_topp();           break;   //  Oppgave 2C
       case 'E':  ny_etappe();         break;   //  
       case 'O':  oppom();             break;   //  Oppgave 2E
       case 'S':  starter_slutter();   break;   //  Oppgave 2F
       default:   skriv_meny();        break;
     }
     kommando = les("nske");
   }
  cout << "\n\n";
  return 0;
}

//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Topp::skriv()  {                    //  Skriver ALLE data:
        //  Oppgave 2A:  Lag innmaten
}

void Topp::skriv_navn()  {               //  Skriver KUN navnet:
        //  Oppgave 2B:  Lag innmaten
}

void Topp::les_data(char nvn[])  {       //  Leser alle egne data:
        //  Oppgave 2C:  Lag innmaten
}

bool Topp::heter(char nvn[])  {          //  Returnerer 'true/false' til om
  return (!strcmp(navn, nvn));           //    toppen heter 'nvn' eller ei.
}

void Topp::les_fra_fil(ifstream & inn)  {  //  Leser ALT fra fil:
        //  Oppgave 2G:  Lag innmaten
}


void Etappe::skriv()  {                  //  Skriver ALLE data:
        //  Oppgave 2B:  Lag innmaten
}

void Etappe::les_data()  {               //  Leser ALLE data:
        //  Oppgave 2D:  Lag innmaten
}
                                         //  Etappe g†r oppom (true)
bool Etappe::gaar_oppom(int n)   {       //    topp nr.'n' eller ei (false):
        //  Oppgave 2E:  Lag innmaten
}
                                         //  Etappe starter eller slutter
bool Etappe::start_slutt(char nvn[])  {  //    i gitt by ('nvn') eller ei.
        //  Oppgave 2F:  Lag innmaten
}

void Etappe::les_fra_fil(ifstream & inn)  {   //  Leser ALT fra fil:
        //  Oppgave 2G:  Lag innmaten
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tP   = skriv alle toPper\n";
  cout << "\tA   = skriv en etAppe\n";
  cout << "\tT   = ny Topp\n";
  cout << "\tE   = ny Etappe\n";
  cout << "\tO   = etapper som g†r Oppom en gitt topp\n";
  cout << "\tS   = etappe som Starter eller Slutter et gitt sted/by\n";
  cout << "\tQ   = Quit/avslutt\n";
}


char les(char t[])  {        //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << '\n' << t << ":  ";   //  Skriver medsendt ledetekst.
  cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
  return (toupper(ch));         //  Upcaser og returnerer.
}

                             //  Leser et tall i et visst intervall:
float les(const char t[], const int min, const int max)  { 
  float n;
  do  {                               // Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;   cin.ignore();         // Leser inn ett tall.
  } while(n < min  ||  n > max);      // Sjekker at i lovlig intervall.
  return n;                           // Returnerer innlest tall.
}

                             //  Leser en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {  
  do  {
    cout << '\t' << t << ": ";	cin.getline(s, LEN); //  Ledetekst og leser.
  } while (strlen(s) == 0);           //  Sjekker at tekstlengden er ulik 0.
}


int finn_topp(char nvn[])  {          //  Returnerer (om mulig) indeksen for
  for (int i = 1;  i <= siste_topp;  i++)    //  toppen med navn lik 'nvn'.
          if (toppene[i].heter(nvn))  return i;
  return 0;                           //  Ingen match - returnerer '0'.
}


void skriv_topper()  {       //  Skriver ALLE toppene:
        //  Oppgave 2A:  Lag innmaten
}


void skriv_etappe()  {       //  Skriver EN gitt etappe:
        //  Oppgave 2B:  Lag innmaten
}


void ny_topp()  {            //  Legger inn en ny topp:
        //  Oppgave 2C:  Lag innmaten
}


void ny_etappe()  {          //  Legger inn en ny etappe:
  if (siste_etappe < MAXETAPPER)  {         //  Plass til flere:
     etappene[++siste_etappe].les_data();   //  Ny etappe leser ALLE data selv.
  } else                                    //  Fullt med etapper:
    cout << "\n\n\tFullt med etapper i datastrukturen!\n\n";
}


void oppom()  {              //  Etapper som g†r oppom EN gitt topp:
        //  Oppgave 2E:  Lag innmaten
}

                            
void starter_slutter()  {    //  Etappe som starter/slutter et gitt sted/by:
        //  Oppgave 2F:  Lag innmaten
}


void les_fra_fil()  {        //  Leser inn HELE datastrukturen:
        //  Oppgave 2G:  Lag innmaten
}

