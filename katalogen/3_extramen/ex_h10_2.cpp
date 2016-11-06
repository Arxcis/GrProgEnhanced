//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H10_2.CPP

//  Lõsningsforslag til eksamen i C++, 7.desember 2010, oppgave 2.
//  Laget av Frode Haug, HiG, november 2010.

//  Program som holder orden pÜ kampene en fotballentusiast har
//  sett mellom ulike lag i Premier League (UK) i lõpet av EN sesong. 
  

                        //  INCLUDE:
#include <fstream>           //  ifstream, ofstream
#include <iostream>          //  cin, cout
#include <iomanip>           //  setw
#include <cstring>           //  strlen, strcpy
#include <cctype>            //  toupper
using namespace std;

                        //  ENUM og CONST:
enum Type  { Navn, Fork, Bane };
const int STRLEN     =     30;    //  Max. tekstlengde.
const int FASTLAG    =     20;    //  Fast antall lag i Premier League.
const int MAXKAMPER  =    120;    //  Max. antall kamper i lõpet av EN sesong.
const int MAXMAAL    =     20;    //  Max. mÜl det gÜr an Ü score i en PL-kamp.


class Lag {            //  KLASSER:
  private:
    char navn[STRLEN];            //  Lagets navn.
    char fork[STRLEN/6];          //  Forkortelse for lagsnavnet.
    char bane[STRLEN];            //  Navn pÜ lagets hjemmebane.

  public:                    //  Deklarasjon av medlemsfunksjoner:
    void skriv(int n);                //  Oppgave 2A
    void hent(char txt[], Type ty);   //       Ferdiglaget.
    void les_fra_fil(istream* inn);   //  Oppgave 2G
    void skriv_til_fil(ostream* ut);  //       Extra
};


class Kamp {
  private:
    int  dato,                    //  Kampdato, pÜ formatet: èèMMDD.
         klokken,                 //  Startklokkeslett, pÜ formatet: TTMM
         Hlag, Blag,              //  Hjemme- og bortelagets indeks i "lagene".
         Hres, Bres;              //  Hjemme- og bortelagets mÜl(score).

  public:                    //  Definisjon/deklarasjon av medlemsfunksjoner:
    void skriv();                            //  Oppgave 2B
    void skriv_alt();                        //  Oppgave 2C
    bool involvert(int n)  { return(Hlag == n  ||  Blag == n); }  //  (oppg.2D)
    void resultat();                         //  Oppgave 2E
    void ny();                               //  Oppgave 2F
    void les_fra_fil(istream* inn, int d);   //  Oppgave 2G
    void skriv_til_fil(ostream* ut);         //  Extra
};

                    //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
void konverter(int d);
char les(char t[]);
int  les(const char t[], const int min, const int max);

void skriv_alle_lag();       //  Oppgave 2A
void skriv_alle_kamper();    //  Oppgave 2B
void skriv_en_kamp();        //  Oppgave 2C
void skriv_ett_lag();        //  Oppgave 2D
void resultat();             //  Oppgave 2E
void ny_kamp();              //  Oppgave 2F
void les_fra_filer();        //  Oppgave 2G
void skriv_til_filer();      //  Extra

                        //  GLOBALE VARIABLE:
Lag  lagene[FASTLAG+1];      //  Array med Lag-objekter.
Kamp kampene[MAXKAMPER+1];   //  Array med Kamp-objekter.
int siste_kamp;              //  Indeks for siste Kamp hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   les_fra_filer();                             //  Oppgave 2G
   skriv_meny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'G':  skriv_alle_lag();    break;   //  Oppgave 2A
       case 'M':  skriv_alle_kamper(); break;   //  Oppgave 2B
       case 'K':  skriv_en_kamp();     break;   //  Oppgave 2C
       case 'L':  skriv_ett_lag();     break;   //  Oppgave 2D
       case 'R':  resultat();          break;   //  Oppgave 2E
       case 'N':  ny_kamp();           break;   //  Oppgave 2F
       case 'T':  skriv_til_filer();   break;   //  Extra
       default:   skriv_meny();        break;
     }
     kommando = les("ùnske");
   }
  skriv_til_filer();                            //  Extra
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Lag::skriv(int n)  {    //  OPPGAVE 2A - Skriver alle datamedlemmer:
  cout << '\t' << setw(2) << n << ": " << fork <<  " - " << navn 
       << "\n\t\tBane: " << bane << '\n';
}

                               // Ut fra 'ty' kopieres datamedlem inn i 'txt':
void Lag::hent(char txt[], Type ty)  {    // (brukes ifm. oppgave 2B og 2C) 
  switch (ty)  {
     case Navn:  strcpy(txt, navn);  break;
     case Fork:  strcpy(txt, fork);  break;
     case Bane:  strcpy(txt, bane);  break;
  }
}


void Lag::les_fra_fil(istream* inn)  {    //  OPPGAVE 2G - Leser fra fil:
  *inn >> fork;   (*inn).ignore();  (*inn).getline(navn, STRLEN);
  (*inn).getline(bane, STRLEN);
}


void Lag::skriv_til_fil(ostream* ut)  {   //  EXTRA - Skriver til fil:
  *ut << fork << ' ' << navn << '\n' << bane << '\n';
}

//  --------------------------------------------------------------------------

void Kamp::skriv()  {        //  OPPGAVE 2B - Skriver ALLE datamedlemmer:
  char nvn[STRLEN];
  int time = klokken/100,  min = klokken%100;   //  Henter ut 'tt' og 'mm'.
  lagene[Hlag].hent(nvn, Navn);   cout << nvn << " - ";  //  Henter og skriver
  lagene[Blag].hent(nvn, Navn);   cout << nvn << "   ";  //    lagenes navn:
  if (Hres >= 0)  cout << Hres << " - " << Bres;     //  Resultat registrert.
  else cout << "xx - xx";                            //  Ingen resultat (ennÜ).
  cout << "  (";   konverter(dato);                  //  Skriver dato.
  cout << " kl." << time << ':' << ((min < 10) ? "0" : "") << min << ")\n";
}


void Kamp::skriv_alt()  {    //  Oppgave 2C - Skriver ALT + mer om lagene:
  char buf[STRLEN];
  cout << "\n\t";  skriv();     //  Skriver begge lagenes forkortelser + bane:
  lagene[Hlag].hent(buf, Fork);   cout << "\t\tdvs. " << buf << '-';
  lagene[Blag].hent(buf, Fork);   cout << buf << "  pÜ banen: ";
  lagene[Hlag].hent(buf, Bane);   cout << buf << '\n';
}


void Kamp::resultat()  {     //  Oppgave 2E - Leser/registrerer kampresultat:
  cout << "\n\t";  skriv();                        //  Skriver data hittil.
  if (Hres < 0)  {                                 //  Ikke lest fra fõr:
      Hres = les("Hjemmelagets mÜl", 0, MAXMAAL);  //  Hjemme-mÜl.
      Bres = les("Bortelagets mÜl ", 0, MAXMAAL);  //  Borte-mÜl.
  } else
    cout << "\n\n\tResultat allerede lagret for denne kampen!\n\n";
}


void Kamp::ny()  {           //  OPPGAVE 2F - Registrerer helt ny kamp:
  dato    = les("Dato          ", 100101, 201231);  //  Aktuell dato.
  klokken = les("Klokken       ",   1100,   2300);  //  Aktuelt klokkeslett.
  do  {
    Hlag    = les("Hjemmelag (nr)", 1, FASTLAG);    //  Hjemmelags nummer.
    Blag    = les("Bortelag  (nr)", 1, FASTLAG);    //  Bortelags nummer.
  } while (Hlag == Blag);                           //  Til de to er ULIKE.
  Hres = Bres = -1;                                 //  "Tomt" resultat.
}

                             //  OPPGAVE 2G - Leser alt fra fil:
void Kamp::les_fra_fil(istream* inn, int d)  {
  dato = d;
  *inn >> klokken >> Hlag >> Blag >> Hres >> Bres;  (*inn).ignore();
}

                             //  EXTRA - Skriver alt til fil:
void Kamp::skriv_til_fil(ostream* ut)  {
  *ut << dato << setw(5) << klokken << setw(3) << Hlag << setw(3) << Blag 
      << setw(3) << Hres << setw(3) << Bres << '\n';
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tG   = skriv alle laGene\n";
  cout << "\tM   = skriv alle kaMpene\n";
  cout << "\tK   = skriv alt om en Kamp\n";
  cout << "\tL   = skriv alle kampene for ett Lag\n";
  cout << "\tR   = registrer/legg inn Resulutat\n";
  cout << "\tN   = Ny kamp legges inn\n";
  cout << "\tT   = skriv Til filer\n";
  cout << "\tQ   = Quit/avslutt\n";
}

                             //  Gjõr om dato ('d') pÜ formatet: èèMMDD
void konverter(int d)  {     //    til utsfriften: DD/MM-èè :
  cout <<  d % 100  <<  '/'  <<  (d / 100) % 100  <<  '-'  <<  d / 10000;
}


char les(char t[])  {        //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << '\n' << t << ":  ";   //  Skriver medsendt ledetekst.
  cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
  return (toupper(ch));         //  Upcaser og returnerer.
}

                             // Leser et tall i et visst intervall:
int les(const char t[], const int min, const int max)  { 
  int n;
  do  {                                  // Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;   cin.ignore();            // Leser inn ett tall.
  } while(n < min  ||  n > max);         // Sjekker at i lovlig intervall.
  return n;                              // Returnerer innlest tall.
}


void skriv_alle_lag()  {     //  Oppgave 2A - Skriver ALLE lagene:
  for (int i = 1;  i <= FASTLAG;  i++)
      lagene[i].skriv(i);
}


void skriv_alle_kamper()  {  //  Oppgave 2B - Skriver ALLE kampene:
  for (int i = 1;  i <= siste_kamp;  i++)  {
      cout << "\tKamp nr." << i << ": ";
      kampene[i].skriv();
      if ((i % 10) == 0)  {       //  Stanser for hver tiende:
         char ch;  cout << "\t\t\t\t\t\tSkriv ETT tegn .....";  cin >> ch;
      }
  }
}


void skriv_en_kamp()  {      //  Oppgave 2C - Skriver ALT om EN kamp:
  kampene[les("Kampnummer du vil se ALLE data om", 1, siste_kamp)].skriv_alt();
}


void skriv_ett_lag()  {      //  Oppgave 2D - Skriver ALLE kampene for ETT lag:
  int nr = les("Hvilket lagnummer vil du se alle kamper med", 1, FASTLAG); 
  cout << "\n\n";    lagene[nr].skriv(nr);       //  Skriver lagets data.
  cout << "\n\tAlle kamper sett med laget:\n";
  for (int i = 1;  i <= siste_kamp;  i++)        //  GÜr gjennom alle kampene:
                                                 //  NÜr laget inngÜr: skriver:
      if (kampene[i].involvert(nr)) {  cout << '\t';  kampene[i].skriv(); }
}


void resultat()  {           //  Oppgave 2E - Leser inn ett nytt resultat: 
  int nr = les("Kampnummer du vil legge inn resultat for", 0, siste_kamp); 
  if (nr != 0)                    //  Et gyldig kampnummer:
     kampene[nr].resultat();      //  Leser resultat.
  else
    cout << "\n\n\tOK, ingen resultat blir lest inn/lagret.\n\n";
}


void ny_kamp()  {            //  Oppgave 2F - Registrerer en ny kamp:
  if (siste_kamp < MAXKAMPER)  {      //  Plass til flere kamper:
     cout << "\n\tNy kamp har nummer: " << ++siste_kamp << '\n';
     kampene[siste_kamp].ny();        //  Tar i bruk og leser en ny.
  } else
    cout << "\n\n\tIkke plass til Ü legge inn flere kamper!\n\n";
}


void les_fra_filer()  {      //  Oppgave 2G - Leser inn HELE datastrukturen:
  int dato;
  ifstream innfil1("LAG-10-11.DTA");     //  èpner 2x aktuelle filer:
  ifstream innfil2("KAMPER-10-11.DTA");

  if (innfil1)
     for (int i = 1;  i <= FASTLAG;  i++)  //  Filen HAR 20 lag:
         lagene[i].les_fra_fil(&innfil1);
  else
    cout << "\n\nFant ikke filen 'LAG-10-11.DTA'!\n\n";

  if (innfil2)  {
     innfil2 >> dato;                     //  Leser (om mulig) 1.felt i post.
                                          //  Ikke slutt og plass til flere:
     while (!innfil2.eof()  &&  siste_kamp < MAXKAMPER)   {
       kampene[++siste_kamp].les_fra_fil(&innfil2, dato); // Les resten selv.
       innfil2 >> dato;                   //  Leser (om mulig) 1.felt i post.
     }
  } else
    cout << "\n\nFant ikke filen 'KAMPER-10-11.DTA'!\n\n";
}


void skriv_til_filer()  {    //  Extra - Skriver HELE datastrukturen til fil:
  int i;
  ofstream utfil1("LAG-10-11.DT2");      //  èpner 2x aktuelle filer:
  ofstream utfil2("KAMPER-10-11.DT2");

  for (i = 1;  i <= FASTLAG;  i++)
      lagene[i].skriv_til_fil(&utfil1);

  for (i = 1;  i <= siste_kamp;  i++)
      kampene[i].skriv_til_fil(&utfil2);
}
