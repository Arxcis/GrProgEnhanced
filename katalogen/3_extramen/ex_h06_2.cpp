//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H06_2.CPP

//  Løsningsforslag til eksamen i C++, 20.desember 2006, oppgave 2.
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
    void skriv_til_fil(ostream* ut);
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
void skriv_til_fil();


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
//  skriv_til_fil();
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

                        //  OPPGAVE 2F - Returnerer true/false til om bladet
                        //               utgis på et evt. gitt dagnummer en
bool Blad::utgis(int d, int u, char f)  {  //  evt. gitt uke og om evt. 
  bool skrives = false;                    //  først i måneden:
  switch (utgivelse)  {                    //  Ukedag stemmer:
    case Ukentlig:  if (dagnr == d)                   skrives = true;  break;
                                           //  Ukedag stemmer og partallsuke:
    case Annenhver: if (dagnr == d  &&  (u % 2) == 0) skrives = true;  break;
                                           //  Tirsdag og 1.uke i måneden:
    case Maanedlig: if (d == 2  &&  f == 'J')         skrives = true;  break;
  }
  return (skrives);
}


void Blad:: skriv()  {  //  OPPGAVE 2A - Skriver ALLE bladets data:
  cout << "\t\"" << tittel << "\" fra " << forlag << ", "
       << dagnavn[dagnr-1] << "dag - ";
  switch(utgivelse)  {
    case Ukentlig:   cout << "ukentlig";          break;
    case Annenhver:  cout << "annenhver uke";     break;
    case Maanedlig:  cout << "månedlig (1.uka)";  break;
  }
  cout << '\n';
}

                        //  OPPGAVE 2B - Leser ALLE bladets data:
void Blad::lesinn(const char tit[])  {      
  strcpy(tittel, tit);                    //  Kopierer bare inn tittelen.
  les("Forlag", forlag, STRLEN);          //  Bruker hjelpefunksjoner for
  utgivelse = les();                      //    å lese alle de tre andre
  dagnr = les("Dagnummer", 1, ANTDAGER);  //    datamedlemmene.
}


void Blad::endre()  {   //  OPPGAVE 2E  -  Endrer utgivelsestidspunkt:
  skriv();                         //  Skriver alle de nåværende dataene.   
  cout << "\n\tNytt utgivelsestidspunkt:\n";
  dagnr = les("Dagnummer", 1, ANTDAGER);  //  Leser ny utgivelsesdag
  utgivelse = les();                      //    og hvor ofte/frekvens.
}

                        //  OPPGAVE 2D  -  Leser ETT objekts data fra fil:
void Blad::les_fra_fil(char tit[], istream* inn)  {  
  char n;
  strcpy(tittel, tit);            //  Får inn tittelen og kopierer bare over.
  (*inn).getline(forlag, STRLEN); //  Leser forlaget,
  *inn >> dagnr >> n;  (*inn).ignore();  // og utg.dag og hvor ofte (U, A, M).
  switch (n)  {                          // Konverterer bokstav til enum:
    case 'U':  utgivelse = Ukentlig;    break;
    case 'A':  utgivelse = Annenhver;   break;
    case 'M':  utgivelse = Maanedlig;   break;            //  Ugyldig bokstav:
    default:  cout << "Utgivelse på filen er IKKE 'U', 'A' eller 'M'!\n"; 
                                                                       break;
  }
}

                             //  EXTRA - Skriver alle et objekts data til fil:
void Blad::skriv_til_fil(ostream* ut)  {    
  *ut << tittel << '\n' << forlag << '\n' << dagnr << ' ';
  switch(utgivelse)  {
    case Ukentlig:   *ut << 'U';  break;
    case Annenhver:  *ut << 'A';  break;
    case Maanedlig:  *ut << 'M';  break;
  }
  *ut << '\n';
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



void alle_blader()  {       //  OPPGAVE 2A - Skriver dataene om ALLE bladene:
  char ch;
  if (siste_blad > 0)  {                      //  Blad er registrert:
     cout << "\nData om ALLE bladene:\n";
     for (int i = 1;  i <= siste_blad;  i++) { // Går gjennom alle bladene:
         blader[i].skriv();                  //  Hver av dem skriver seg selv.
         if (i % 20 == 0)                    //  Stopper for hver tyvende:
            {  cout << "\n\t\t\t\t\t\tSkriv ETT tegn .....";  cin >> ch;  }
     }
  } else                                   //  Ingen blad innlest/registrert:
    cout << "\nIngen blad registrert. Bruk kommandoen 'N' først.\n";
}

	
void nytt_blad()  {         //  OPPGAVE 2B - Registrerer/legger inn nytt blad:
  char tittel[STRLEN];
  if (siste_blad < MAXBLAD)  {           //  Om fortsatt plass til flere blad:
     les("Tittel", tittel, STRLEN);      //  Leser dets tittel.
     if (finn(Tittel, tittel) == 0)      //  Finnes ikke allerede:
        blader[++siste_blad].lesinn(tittel);  //  Nytt blad leser resten selv.
     else                                //  Bladet finnes allerede:
        cout << "\n\tDette bladet finnes allerede!\n\n";
  } else                                 //  Fullt med blader:
     cout << "\n\tDatastrukturen FULL med " << MAXBLAD << " blader!\n\n";
}

	
void forlags_blader()  {    //  OPPGAVE 2C - Skriver alle blad fra ETT forlag:
  char forlag[STRLEN];
  if (siste_blad > 0)  {                     //  Blad er registrert:
     cout << "\nData om bladene fra ETT forlag:\n";
     les("Forlagets navn", forlag, STRLEN);  //  Leser forlagets navn.
     if (finn(Forlag, forlag) != 0)  {       //  Om MINST ett forlag finnes:
        for (int i = 1;  i <= siste_blad;  i++)  // Går gjennom alle bladene:
                                             //  De aktuelle skriver seg selv:
            if (blader[i].er_lik(Forlag, forlag)) blader[i].skriv();
     } else
        cout << "\n\tDette forlaget finnes ikke!\n\n";
  } else                                    //  Ingen blad innlest/registrert:
    cout << "\nIngen blad registrert. Bruk kommandoen 'N' først.\n";
}


void les_fra_fil()  {        //  OPPGAVE 2D - Leser datastrukturen fra fil:
  ifstream innfil("blader.dta");
  char titt[STRLEN];                    //  Et blads tittel/navn.
  if (innfil)  {                        //  Filen var mulig å åpne:
     siste_blad = 0;                    //  Nullstiller/initierer.
     innfil.getline(titt, STRLEN);      //  Leser (om mulig) neste bladtittel.
                                        //  Mer å lese fra filen og IKKE fullt:
     while (!innfil.eof()  &&  siste_blad < MAXBLAD)  {          
       blader[++siste_blad].les_fra_fil(titt, &innfil); //  Leser resten selv.
       innfil.getline(titt, STRLEN);    //  Leser (om mulig) neste bladtittel.
     }
  } else                                //  Filen lot seg ikke åpne:
    cout << "\n\nFant ikke filen 'BLADER.DTA'!\n\n";
}


void endre_utgivelse()  {    //  OPPGAVE 2E - Endrer utgivelse for et blad:
  char tittel[STRLEN];                  //  Bladets tittel.
  int n;                                //  Dets indeks i arrayen 'blader':
  les("Endre utgivelse for bladet", tittel, STRLEN);
  if ((n = finn(Tittel, tittel)) != 0)  //  Bladet er å finne.
     blader[n].endre();                 //  Det skriver ut seg selv.
  else                                  //  Bladet fantes ikke:
     cout << "\n\tDette bladet finnes ikke!\n\n";
}

                             //  OPPGAVE 2F - Skriver ALLE bladene som utgis
void utgivelser()  {         //                 en gitt dag:
  int  dagnr, ukenr;         //  Aktuelt dagnumnmer og ukenummer.
  char forst;                //  Om dette er 1.uken i en måned eller ei.

  dagnr = les("Dagnummer", 1, ANTDAGER);   //  Leser aktuell ukedag.
  ukenr = les("Ukenummer", 1, 53);         //  Leser aktuelt ukenummer.
  do
    forst = les("\t1.uke i måneden (j/n)?"); //  Leser om månedens 1.uke:
  while (forst != 'J'  &&  forst != 'N');
  cout << "\nFølgende blad utgis på denne dagen:\n";
  for (int i = 1;  i <= siste_blad;  i++)   // Går gjennom alle bladene:
      if (blader[i].utgis(dagnr, ukenr, forst))  //  Om utgis på gitt dag:
          blader[i].skriv();                //  Skriver da seg selv.
}


void skriv_til_fil()  {      //  EXTRA - Skriver datastrukturen til fil:
  ofstream utfil("blader.dta");
  for (int i = 1;  i <= siste_blad;  i++)   // Går gjennom alle bladene:
      blader[i].skriv_til_fil(&utfil);      //  Hvert av dem skriver seg selv.
}
