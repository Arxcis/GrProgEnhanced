//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H06_2.TPL

//  Skjellettet/template for eksamen i C++, 20.desember 2006, oppgave 2.
//  Laget av Frode Haug, HiG, desember 2006.


//  Program som holder orden på blader fra ulike forlag og
//      data om deres utgivelsestidspunkt (dagnummer og hvor ofte/frekvens).


                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream
#include <cctype>             //  toupper
#include <cstring>            //  strcpy, strcmp, strlen

using namespace std;

                        //  CONST:
const int  STRLEN     =  30;  //  Max. tekstlengde for tittel/forlag.
const int  MAXBLAD    = 200;  //  Max. antall blader i datastrukturen.
const int  ANTDAGER   =   6;  //  Antall ukedager det utkommer blader.
const char dagnavn[ANTDAGER][STRLEN/4] =      //  1.del av ukedagenes navn:
                              { "Man", "Tirs", "Ons", "Tors", "Fre", "Lør" };

                        //  ENUM:
enum Type      { Tittel, Forlag };
enum Utgivelse { Ukentlig, Annenhver, Maanedlig };

                        //  KLASSE:
class Blad  {                 //  Ukeblad/tidsskrift:
  private:
    char tittel[STRLEN];      //  Tittel/navn.
    char forlag[STRLEN];      //  Forlag/utgiver.
    int  dagnr;               //  Utgivelsens dagnummer (M=1, Ti=2, ...L=6);
    Utgivelse  utgivelse;     //  Hvor ofte/frekvensen på utgivelsen.

  public:                     //  Deklarasjon av medlemsfunksjoner:
    bool er_lik(Type type, const char t[]);
    bool utgis(int d, int u, char f);
    void skriv();
    void lesinn(const char tit[]);
    void endre();
    void les_fra_fil(char tit[], istream* inn);
};

                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
Utgivelse  les();
int finn(Type type, const char t[]);

void alle_blader();
void nytt_blad();
void forlags_blader();
void les_fra_fil();
void endre_utgivelse();
void utgivelser();

                        //  GLOBALE VARIABLE:
Blad  blader[MAXBLAD+1];      //  Array med Blad-objekter.
int   siste_blad;             //  Aktuelt antall indekser/blad i bruk.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;
   
   les_fra_fil();                                //  Oppgave 2d

   skriv_meny();
   kommando = les("Ønske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'A':  alle_blader();       break;    //  Oppgave 2a
       case 'N':  nytt_blad();         break;    //  Oppgave 2b
       case 'F':  forlags_blader();    break;    //  Oppgave 2c
       case 'E':  endre_utgivelse();   break;    //  Oppgave 2e
       case 'U':  utgivelser();        break;    //  Oppgave 2f
       default:   skriv_meny();        break;
     }
     kommando = les("Ønske");
   }
  cout << "\n\n";
  return 0;
}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:
bool Blad::er_lik(Type type, const char t[])  {   //  Returnerer true/false
  if (type == Tittel)  {                   //   til om ENTEN bladets tittel
     return (!strcmp(tittel, t));          //   ELLER
  } else if (type == Forlag)  {            //   forlag
     return (!strcmp(forlag, t));          //   er lik 't'.
  }
}

                        //  Returnerer true/false til om bladet utgis på et
                        //          evt. gitt dagnummer en evt. gitt uke og
bool Blad::utgis(int d, int u, char f)  {   //  om evt. f›rst i m†neden:
        //  Oppgave 2F:  Lag innmaten   
}


void Blad:: skriv()  {  //  Skriver ALLE bladets data:
        //  Oppgave 2A:  Lag innmaten
}

                        //  Leser ALLE bladets data:
void Blad::lesinn(const char tit[])  {      
        //  Oppgave 2B:  Lag innmaten
}


void Blad::endre()  {   //  Endrer utgivelsestidspunkt:
        //  Oppgave 2E:  Lag innmaten
}

                        //  Leser ETT objekts data fra fil:
void Blad::les_fra_fil(char tit[], istream* inn)  {  
        //  Oppgave 2D:  Lag innmaten
}


                        //  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tA = Alle blader\n";
  cout << "\tN = Nytt blad\n";
  cout << "\tF = blad fra et gitt Forlag\n";
  cout << "\tE = Endre utgivelsestidspunkt for ett blad\n";
  cout << "\tU = blad Utgitt et visst tidspunkt\n";
  cout << "\tQ = quit/avslutt\n";
}


char les(char t[])  {       //  Henter ett ikke-blankt upcaset tegn:
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


Utgivelse les()  {                //  Leser og returnerer hvor ofte utgis:
  int n = les("Utgivelse (1=ukentlig, 2=annenhver, 3=månedlig): ", 1, 3);
  switch (n)  {                   //  Gjør om fra tall-verdi til enum-verdi
    case 1:  return Ukentlig;   break;    //  og returnerer dette.
    case 2:  return Annenhver;  break;
    case 3:  return Maanedlig;  break;
  }
}

                              
int finn(Type type, const char t[])  {       //  Ut fra en tittel ELLER forlag
  for (int i = 1;  i <= siste_blad;  i++)    //    så returneres
      if (blader[i].er_lik(type, t)) return i; //  vedkommendes indeks, evt.
  return 0;                                    //  '0' om ingen treff/match.
}



void alle_blader()  {       //  Skriver dataene om ALLE bladene:
        //  Oppgave 2A:  Lag innmaten
}

	
void nytt_blad()  {         //  Registrerer/legger inn nytt blad:
        //  Oppgave 2B:  Lag innmaten
}

	
void forlags_blader()  {    //  Skriver alle blad fra ETT forlag:
        //  Oppgave 2C:  Lag innmaten
}


void les_fra_fil()  {        //  Leser datastrukturen fra fil:
        //  Oppgave 2D:  Lag innmaten
}


void endre_utgivelse()  {    //  Endrer utgivelse for et blad:
        //  Oppgave 2E:  Lag innmaten
}

                    
void utgivelser()  {         //  Skriver ALLE bladene som utgis en gitt dag:
        //  Oppgave 2F:  Lag innmaten
}

