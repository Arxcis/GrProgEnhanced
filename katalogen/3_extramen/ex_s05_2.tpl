//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_S05_2.TPL

//  Skjellett/omriss for kontinuasjonseksamen i C++, 9.august 2005, oppgave 2.
//  Laget av Frode Haug, HiG, juni 2005.


//  Program som holder orden på ulike varer og leverandørene for disse.


                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream, fstream
#include <cctype>             //  toupper

using namespace std;

                        //  CONST:
const int MAXVARE  = 500;     //  Max. antall varer i datastrukturen.
const int MAXLEV   = 200;     //  Max. antall leverandører i datastrukturen.
const int MAXANT = 10000;     //  Max. antall av en vare.
const int STRLEN   =  40;     //  Max. lengde på tekststrenger.

                        //  KLASSER:
class Vare  {                 //  Vare:
  private:
    char navn[STRLEN];        //  Navn.
    int  levnr,               //  Leverandørens nummer/indeks.
         ant_igjen,           //  Antall igjen på lager.
         grense;              //  Etterbestillingsgrense.
    bool bestilt;             //  Har bestilt eller ei.

  public:
    void skriv(int n);        //  Deklarasjon av medlemsfunksjoner:
    void les_inn();
    void selg();
    void bestilling();
    void paafyll();
    void les_fra_fil(istream* inn, int nr);
};


class Leverandor  {           //  Leverandør:
  private:
    char navn[STRLEN];        //  Navn.
    char adr[STRLEN];         //  Adresse.
    int tlf;                  //  Telefon.

  public:
    void skriv(int n);        //  Deklarasjon av medlemsfunksjoner:
    void les_inn();
    void skriv_til_fil(fstream* ut);
    void les_fra_fil(istream* inn, int nr);
};


                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les_kommando();
int  les(char t[], int min, int max);
void ny_leverandor();
void skriv_vare();
void skriv_leverandorer();
void ny_vare();
void selg_vare();
void bestilling_ankommet();
void les_fra_fil();


                        //  GLOBALE VARIABLE:
int siste_vare;                      //  Indeksen for siste brukte vare.
int siste_leverandor;                //  Indeksen for siste brukte leverandør.
Vare varer[MAXVARE+1];               //  Array med Vare-objekter.
Leverandor leverandorer[MAXLEV+1];   //  Array med Leverandor-objekter.

                        
int main()  {           //  HOVEDPROGRAM:
   char kommando;
   
   les_fra_fil();                                 //  Oppgave 2f

   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'L':  ny_leverandor();       break;   //  Oppgave 2a
       case 'V':  ny_vare();             break;   //  Oppgave 2c
       case 'X':  skriv_vare();          break;   //  Oppgave 2b
       case 'Y':  skriv_leverandorer();  break;
       case 'S':  selg_vare();           break;   //  Oppgave 2d
       case 'B':  bestilling_ankommet(); break;   //  Oppgave 2e
       default:   skriv_meny();          break;
     }
     kommando = les_kommando();
   }
  cout << "\n\n";
  return 0;
}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:

void Vare::skriv(int n)  {   //  OPPGAVE 2B  -  Skriver ALLE data:
  //  Lag innmaten
}


void Vare::les_inn()  {      //  OPPGAVE 2C  -  Leser inn ALLE data:
  //  Lag innmaten
}


void Vare::selg()  {        //  OPPGAVE 2D  -  Et antall av varen selges:
  //  Lag innmaten
}


void Vare::bestilling()  {  //  OPPGAVE 2D  -  Etterbestilling skrives til fil:
  //  Lag innmaten
}


void Vare:: paafyll()  {     //  OPPGAVE 2E  -  Påfylling/bestilling ankommet:
  //  Lag innmaten
}

                             //  OPPGAVE 2F  -  Leser inn ALLE data fra fil:
void Vare::les_fra_fil(istream* inn, int nr)  {
  //  Lag innmaten
}


void Leverandor::skriv(int n)  {   //  EKSTRA - FERDIGLAGET
  cout << '\t' << n << ": " << navn << '\t' << adr << '\t' << tlf << '\n';
}


void Leverandor::les_inn()  {      //  OPPGAVE 2A  -  Leser inn ALLE data:
  //  Lag innmaten
}

                             //  OPPGAVE 2D  -  Data ifm. etterbestilling til fil:
void Leverandor::skriv_til_fil(fstream* ut)  {
  //  Lag innmaten
}

                             //  OPPGAVE 2F  -  Leser inn ALLE data fra fil:
void Leverandor::les_fra_fil(istream* inn, int nr)  {
  //  Lag innmaten
}


                        //  DEFINISJON AV FUNKSJONER:
		  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tL = ny Leverandør\n";
  cout << "\tV = ny Vare\n";
  cout << "\tX = skriv vare\n";
  cout << "\tY = skriv leverandører\n";
  cout << "\tS = Selg vare\n";
  cout << "\tB = Bestilling/påfylling ankommet fra leverandør\n";
  cout << "\tQ = quit/avslutt\n";
}



char les_kommando()  {       //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi ønske:  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}


int les(char t[], int min, int max)  {   //  Leser et tall i et visst intervall.
  int n;
  do  {                                  //  Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;                            //  Leser inn ett tall.
  } while(n < min  ||  n > max);         //  Sjekker at i lovlig intervall.
  cin.ignore();                          //  Forkaster ett tegn ('\n').
  return n;                              //  Returnerer innlest tall.
}

							 
void ny_leverandor()  {      //  OPPGAVE 2A - Registrerer en ny leverandør:
  //  Lag innmaten
}	

							 
void skriv_vare()  {         //  OPPGAVE 2B - Skriver ALLE data om EN vare:
  //  Lag innmaten
}	

							 
void skriv_leverandorer()  { //  EKSTRA - FERDIGLAGET
  cout << "\nOVERSIKT OVER ALLE LEVERANDØRENE:\n";
  for (int i = 1;  i <= siste_leverandor;  i++)
      leverandorer[i].skriv(i);
}	

							 
void ny_vare()  {            //  OPPGAVE 2C - Registrerer en ny vare:
  //  Lag innmaten
}	

							 
void selg_vare()  {          //  OPPGAVE 2D - Selg et antall av en vare:
  //  Lag innmaten
}	

							 
void bestilling_ankommet()  {  //  OPPGAVE 2E - Påfyll av en vare:
  //  Lag innmaten
}	

							 
void les_fra_fil()  {        //  OPPGAVE 2F - Leser HELE datastrukturen fra filer:
  //  Lag innmaten
}	
