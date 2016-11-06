//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_S05_2.CPP

//  L�sningsforslag til kontinuasjonseksamen i C++, 9.august 2005, oppgave 2.
//  Laget av Frode Haug, HiG, juni 2005.


//  Program som holder orden p� ulike varer og leverand�rene for disse.


                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream, fstream
#include <cctype>             //  toupper

using namespace std;

                        //  CONST:
const int MAXVARE  = 500;     //  Max. antall varer i datastrukturen.
const int MAXLEV   = 200;     //  Max. antall leverand�rer i datastrukturen.
const int MAXANT = 10000;     //  Max. antall av en vare.
const int STRLEN   =  40;     //  Max. lengde p� tekststrenger.

                        //  KLASSER:
class Vare  {                 //  Vare:
  private:
    char navn[STRLEN];        //  Navn.
    int  levnr,               //  Leverand�rens nummer/indeks.
         ant_igjen,           //  Antall igjen p� lager.
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


class Leverandor  {           //  Leverand�r:
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
int siste_leverandor;                //  Indeksen for siste brukte leverand�r.
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
  cout << '\t' << n << ": " << navn << "\t#igjen: " << ant_igjen
       << "\tGrense: " << grense << ((bestilt)? "  ETTERBESTILT" : "") <<  "\n\t";
  leverandorer[levnr].skriv(levnr);    //  Inkludert alt om leverand�ren.
}


void Vare::les_inn()  {      //  OPPGAVE 2C  -  Leser inn ALLE data:
  cout << "\n\tNavn: ";  cin.getline(navn, STRLEN);   //  Leser/fyller/initierer alle
  ant_igjen = les("#igjen", 1, MAXANT);               //    egne datamedlemmer:
  grense = les("Grense", 0, ant_igjen-1);
  levnr = les("Leverand�rnr", 1, siste_leverandor);
  bestilt = false;
}


void Vare::selg()  {         //  OPPGAVE 2D  -  Et antall av varen selges:
  int ant;
  ant = les("Antall", 0, ant_igjen);           //  Leser antallet som skal selges.
  ant_igjen -= ant;                            //  Trekker fra.
  if (ant_igjen <= grense  &&  !bestilt)  {    //  Behov for etterbestilling:
     bestilt = true;
     bestilling();
  }
}


void Vare::bestilling()  {  //  OPPGAVE 2D  -  Etterbestilling skrives til fil:
  fstream utfil("bestill.dta", ios::out | ios::app);    //  Skriver TIL SLUTT p� fila.
  int ant;
  cout << "\n\tIgjen p� lager av varen: " << ant_igjen       //  Skriver data og
       << "\n\tBestillingsgrense:       " << grense << '\n'; //    ber om antallet
  ant = les("Bestill antall", grense-ant_igjen+1, MAXANT);   //    som skal bestilles.
  leverandorer[levnr].skriv_til_fil(&utfil);                 //  Lev.data skrives
  utfil << "Bestiller herved " << ant << " stk. av " << navn << "\n\n"; 
}                                                            //  �nsket antall skrives.


void Vare:: paafyll()  {     //  OPPGAVE 2E  -  P�fylling/bestilling ankommet:
  int ant;
  ant = les("Antall", 0, MAXANT);        //  Leser antallet som f�r inn.
  ant_igjen += ant;                      //  Legger til/�ker.
  bestilt = false;
  if (ant_igjen <= grense)  {            //  Om fortsatt under min.grense:
     bestilt = true;                     //  Etterbestiller nok en gang:
     bestilling();
  }
}

                             //  OPPGAVE 2F  -  Leser inn ALLE data fra fil:
void Vare::les_fra_fil(istream* inn, int nr)  {
  int best;
  levnr = nr; 
  (*inn).ignore();                       //  Leser alle egne data fra fil:
  (*inn).getline(navn, STRLEN);
  *inn >> ant_igjen >> grense >> best;
  (*inn).ignore();
  bestilt = (best == 1) ? true : false;  //  Konvertere 0/1 til true/false.
}


void Leverandor::skriv(int n)  {   //  EKSTRA - FERDIGLAGET
  cout << '\t' << n << ": " << navn << '\t' << adr << '\t' << tlf << '\n';
}


void Leverandor::les_inn()  {      //  OPPGAVE 2A  -  Leser inn ALLE data:
  cout << "\n\tNavn: ";  cin.getline(navn, STRLEN);  // Leser/fyller alle egne
  cout << "\tAdr:  ";    cin.getline(adr, STRLEN);   //    datamedlemmer:
  tlf = les("Tlf ", 10000000, 99999999);
}

                             //  OPPGAVE 2D  -  Data ifm. etterbestilling til fil:
void Leverandor::skriv_til_fil(fstream* ut)  {        // Skriver alle egne data 
  *ut << navn << '\t' << adr << '\t' << tlf << '\n';  //   til fil.
}

                             //  OPPGAVE 2F  -  Leser inn ALLE data fra fil:
void Leverandor::les_fra_fil(istream* inn, int nr)  {
  tlf = nr;
  (*inn).ignore();                       //  Leser alle egne data fra fil:
  (*inn).getline(navn, STRLEN);
  (*inn).getline(adr, STRLEN);
}


                        //  DEFINISJON AV FUNKSJONER:
		  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nF�LGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tL = ny Leverand�r\n";
  cout << "\tV = ny Vare\n";
  cout << "\tX = skriv vare\n";
  cout << "\tY = skriv leverand�rer\n";
  cout << "\tS = Selg vare\n";
  cout << "\tB = Bestilling/p�fylling ankommet fra leverand�r\n";
  cout << "\tQ = quit/avslutt\n";
}



char les_kommando()  {       //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi �nske:  ";
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

							 
void ny_leverandor()  {      //  OPPGAVE 2A - Registrerer en ny leverand�r:
  cout << "\nNY LEVERAND�R:\n";
  if (siste_leverandor < MAXLEV)  {             //  Plass til flere:
     cout << "\tLeverand�rnr: " << ++siste_leverandor << ":\n";
     leverandorer[siste_leverandor].les_inn();  //  Tar i bruk ny leverandor,
  } else                                        //    og leser dens data.
     cout << "\n\tLeverand�rlageret er allerede fullt med " 
          << MAXLEV << " leverand�rer!\n";
}	

							 
void skriv_vare()  {         //  OPPGAVE 2B - Skriver ALLE data om EN vare:
  int nr;
  cout << "\nDATA OM EN VARE:\n";
  nr = les("Varenummer", 1, siste_vare);    //  Ber omm aktuelt varenr.
  varer[nr].skriv(nr);                      //  Skriver ALLE dets data.
}	

							 
void skriv_leverandorer()  {    //  EKSTRA - FERDIGLAGET
  cout << "\nOVERSIKT OVER ALLE LEVERAND�RENE:\n";
  for (int i = 1;  i <= siste_leverandor;  i++)
      leverandorer[i].skriv(i);
}	

							 
void ny_vare()  {            //  OPPGAVE 2C - Registrerer en ny vare:
  cout << "\nNY VARE:\n";
  if (siste_vare < MAXVARE)  {                          //  Plass til flere:
     cout << "\tVarenr: " << ++siste_vare << ":\n";
     varer[siste_vare].les_inn();    //  Tar i bruk ny vare, og leser dens data.
  } else
     cout << "\n\tVarelageret er allerede fullt med " 
          << MAXVARE << " varer!\n";
}	

							 
void selg_vare()  {          //  OPPGAVE 2D - Selg et antall av en vare:
  int nr;
  cout << "\nSELG NOE(N) AV EN VARE:\n";
  nr = les("Varenummer", 1, siste_vare);    //  Leser et varenummer.
  varer[nr].selg();                         //  Selger noe av denne varen.
}	

							 
void bestilling_ankommet()  {  //  OPPGAVE 2E - P�fyll av en vare:
  int nr;
  cout << "\n(ETTER)BESTILLING ANKOMMET:\n";
  nr = les("Varenummer", 1, siste_vare);    //  Leser et varenummer.
  varer[nr].paafyll();                      //  F�r inn noe av denne varen.
}	

							 
void les_fra_fil()  {        //  OPPGAVE 2F - Leser HELE datastrukturen fra filer:
  ifstream innfil1("leverand.dta");    //  �pner de to filene det skal leses fra:
  ifstream innfil2("varer.dta");       
  int tall;
 
  siste_vare = siste_leverandor = 0;   //  Nullstiller.

  if (innfil1  && innfil2)  {          //  Begge filene finnes.
                                       //  Leser inn alle leverand�rene:
     innfil1 >> tall;                  //  Leser (om mulig) f�rste telefonnr.
     while (!innfil1.eof() &&  siste_leverandor < MAXLEV)  { // Ikke slutt og plass:
                                       //  Ber objektet lese resten selv:
        leverandorer[++siste_leverandor].les_fra_fil(&innfil1, tall);
        innfil1 >> tall;               //  Leser (om mulig) neste telefonnr.
     }

     innfil2 >> tall;                  //  Leser (om mulig) f�rste leverand�rref.
     while (!innfil2.eof() &&  siste_vare < MAXVARE)  { // Ikke slutt og plass:
                                       //  Ber objektet lese resten selv:
        varer[++siste_vare].les_fra_fil(&innfil2, tall);
        innfil2 >> tall;               //  Leser (om mulig) neste leverand�rref.
     }
  } else                                 // MINST en fil finnes ikke:
    cout << "\n\tMinst en av filene 'LEVERAND.DTA'/'VARER.DTA' finnes ikke!\n";
}	
