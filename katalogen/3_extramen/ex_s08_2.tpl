//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S08_2.TPL

//  Skjellettet/template for kontinuasjonseksamen i C++, 12.august 2008, oppg.2.
//  Laget av Frode Haug, HiG, mai 2008.

//  Program som holder orden pÜ ulike personer som er tilknyttet ulike
//      idrettslag/-klubber som trenere eller oppmenn.
  

                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream, ofstream
#include <cstring>            //  strcpy, strlen, strcmp
#include <cctype>             //  toupper

using namespace std;

                        //  CONST og ENUM:
const int  STRLEN      =     40;  //  Max. tekstlengde.
const int  MAXPERSONER =    500;  //  Max. antall personer (trenere/oppmenn).
const int  MAXLAG      =     50;  //  Max. antall (idretts)lag.
enum funksjon { trener, oppmann, ingen };  //  Verv: Trener ELLER oppmann.

                        
class Person  {            //  KLASSER:
  private:                        //  Personens:
    char navn[STRLEN];            //   - Navn
    char adr[STRLEN*2];           //   - Adresse
    char mail[STRLEN];            //   - Mail-adresse
    char klasse[STRLEN];          //   - èrsklasse i laget, f.eks. J16, G12
    int tlf;                      //   - Telefon
    funksjon verv;                //   - Verv ('trener' eller 'oppmann')
    int lagnr;                    //  Lagets nr/indeks i "lag"-array.

  public:                     //  Definisjon/deklarasjon av medlemsfunksjoner:
    Person();
    void skriv();                                   //  Oppgave 2A
    void skriv2();                                  //  Oppgave 2C
    void les_data(int lnr);                         //  Oppgave 2E
    void skriv_til_fil(ostream* ut);                //  Oppgave 2F
    void les_fra_fil(char t[], istream* inn);       //  Oppgave 2G
    bool har_navn(char t[])   {  return (!strcmp(navn, t)); }  // Har navnet?
    bool har_verv(funksjon v) {  return (verv == v);        }  // Har vervet?
    bool tilhorer_lag(int n)  {  return (lagnr == n);       }  // Tilhõrer lag.
};


class Lag    {
  private:                    //  Lagets:
    char navn[STRLEN];        //   - navn
    char adr[STRLEN*2];       //   - adresse (gate, postnr, poststed)
    char mail[STRLEN];        //   - mail-adresse
    char hjemmeside[STRLEN];  //   - hjemmeside/URL
  
  public:                     //  Definisjon/deklarasjon av medlemsfunksjoner:
    Lag();
    void skriv();                                   //  Oppgave 2A
    void les_data(char t[]);                        //  Oppgave 2D
    bool har_navn(char t[])  {  return (!strcmp(navn, t)); }   //  Har navnet?
};


                    //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char     les(char t[]);
int      les(const char t[], const int min, const int max);
void     les(const char t[], char s[], const int LEN);
funksjon les();
int  finn_person(char t[]);
int  finn_lag(char t[]);

void skriv_person();        //  Oppgave 2A
void skriv_verv();          //  Oppgave 2B
void skriv_lag();           //  Oppgave 2C
void nytt_lag();            //  Oppgave 2D
void ny_person();           //  Oppgave 2E
void skriv_til_fil();       //  Oppgave 2F
void les_fra_fil();         //  Oppgave 2G


                        //  GLOBALE VARIABLE:
Person personer[MAXPERSONER+1];   //  Array med Person-objekter.
Lag    lag[MAXLAG+1];             //  Array med Lag-objekter.
int    siste_person, siste_lag;   //  Indeks for siste person/lag hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   les_fra_fil();                             //  Oppgave 2G
   skriv_meny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'A':   skriv_person();  break;    //  Oppgave 2A
       case 'B':   skriv_verv();    break;    //  Oppgave 2B
       case 'C':   skriv_lag();     break;    //  Oppgave 2C
       case 'L':   nytt_lag();      break;    //  Oppgave 2D
       case 'P':   ny_person();     break;    //  Oppgave 2E
       default:    skriv_meny();    break;
     }
     kommando = les("ùnske");
   }
  skriv_til_fil();                            //  Oppgave 2F
  cout << "\n\n";
  return 0;
}

// ----------------------------------------------------------------------------
                        //  DEFINISJON AV KLASSE-FUNKSJONER:
Person::Person()  {                 //  Initierer alle datamedlemmer:
  strcpy(navn, "");  strcpy(adr, "");  strcpy(mail, "");  strcpy(klasse, "");
  tlf = lagnr = 0;  verv = ingen;
}

void Person::skriv()  {             //  Skriver ALLE personens data:
//   Oppgave 2A: Lag innmaten
}

void Person::skriv2()  {            //  Skriver personens data:
//   Oppgave 2C: Lag innmaten
}

void Person::les_data(int lnr)  {   //  Registrerer/leser ALLE personens data:
//   Oppgave 2E: Lag innmaten
}
                                    //  Skriver ALLE personens data til fil:
void Person::skriv_til_fil(ostream* ut)  {
//   Oppgave 2F: Lag innmaten
}
                                    //  Leser ALLE personens data fra fil:
void Person::les_fra_fil(char t[], istream* inn)  {
//   Oppgave 2G: Lag innmaten
}

// ----------------------------------------------------------------------------

Lag::Lag()  {                       //  Initierer alle datamedlemmer:
  strcpy(navn, ""); strcpy(adr, ""); strcpy(mail, ""); strcpy(hjemmeside, "");
}

void Lag::skriv()  {                //  Skriver alle lagets data:
//   Oppgave 2A: Lag innmaten
}

void Lag::les_data(char t[])  {     //  Registrerer/leser ALLE lagets data:
//   Oppgave 2D: Lag innmaten
}

						
// ----------------------------------------------------------------------------
                        //  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tA = skriv ALT om EN person\n";
  cout << "\tB = skriv ALLE trenere ELLER oppmenn\n";
  cout << "\tC = skriv ALT om et gitt lag\n";
  cout << "\tL = nytt Lag legges inn\n";
  cout << "\tP = ny Person legges inn\n";
  cout << "\tQ = Quit/avslutt\n";
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

                             //  Leser inn en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {  
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, LEN);          //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}


funksjon les()  {            //  Leser 'trener' eller 'oppmann':
  char ch;
  do  {
    cout << "\tT(rener) eller O(ppmann): ";  cin >> ch;  cin.ignore();  
    ch = toupper(ch);
  } while (ch != 'T' &&  ch != 'O');      //  Godtar KUN 'T' eller 'O'.
  return ((ch =='T')? trener : oppmann);  //  Retur av aktuell enum-verdi.
}

                             //  Ut fra en persons navn, returneres dens indeks
int finn_person(char t[])  { //     i "personer", evt. '0' om ikke finnes:
  for (int i = 1;  i <= siste_person;  i++) 
      if (personer[i].har_navn(t))  return i;
  return 0;
}

                             //  Ut fra et lags navn, returneres dens
int finn_lag(char t[])  {    //     indeks i "lag", evt. '0' om ikke finnes:
  for (int i = 1;  i <= siste_lag;  i++) 
      if (lag[i].har_navn(t))  return i;
  return 0;
}

void skriv_person()  {       //  Skriver ALLE data om EN person:
//   Oppgave 2A: Lag innmaten
}

void skriv_verv()  {         //  Skriver ALLE med et gitt verv:
//   Oppgave 2B: Lag innmaten
}
                             //  Skriver ALT om et gitt lag,
void skriv_lag()  {          //    inkludert alle dets trenere/oppmenn:
//   Oppgave 2C: Lag innmaten
}

void nytt_lag()  {           //  Legger inn et nytt UNIKT lag:
//   Oppgave 2D: Lag innmaten
}

void ny_person()  {          //  Legger inn en ny person:
//   Oppgave 2E: Lag innmaten
}


void skriv_til_fil()  {      //  Skriver HELE datastrukturen til fil:
//   Oppgave 2F: Lag innmaten
}


void les_fra_fil()  {        //  Leser HELE datastrukturen fra fil:
//   Oppgave 2G: Lag innmaten
}
