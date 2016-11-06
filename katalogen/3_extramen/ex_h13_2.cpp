//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H13_2.CPP

//  Løsningsforslag til eksamen i C++, 3.desember 2013, oppgave 2.
//  Laget av Frode Haug, HiG, november 2013.

//  Programmet "Dyre Streets" som holder orden på Armani-butikker 
//  i ulike byer, og varekjøpene utført av Dir.Strays i disse.
  

                        //  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <cstring>               //  strcmp, strcpy, strlen
#include <cctype>                //  toupper
using namespace std;

                        //  CONST:
const int STRLEN     =     80;   //  Max. tekstlengde.
const int MAXBUTIKK  =    100;   //  Max. antall butikker.
const int MAXKJOP    =    200;   //  Max. antall kjøp i EN butikk.


class Butikk {         //  KLASSE:
  private:
    char by[STRLEN/2];           //  Byen butikken ligger i.
    char adr[STRLEN];            //  Gateadresse.
    int  aapneUke,               //  Åpnings- og stengetid - uka
         stengeUke,              //              (mandag-fredag)
         aapneLordag,            //  Åpnings- og stengetid - lørdag.
         stengeLordag,
         antKjop;                //  Antall kjøp i butikken.
    int  kjopene[MAXKJOP+1];     //  Summene det er handlet for 
                                 //       (i hele norske kroner).
  public:                     //  Deklarasjon av medlemsfunksjoner:
    Butikk()              {  antKjop = 0;  }
    void skriv();                                //  Oppgave 2A
    void lesData(char b[]);                      //  Oppgave 2B
    void gjorKjop();                             //  Oppgave 2C
    void endreTider();                           //  Oppgave 2D
    int  kjopTotalt();                           //  Oppgave 2E
    void lesFraFil(ifstream & inn, char b[]);    //  Oppgave 2G
    void skrivTilFil(ofstream & ut);
    bool erLik(char t[])  {  return (!strcmp(by, t));  }
};

                    //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
int  finnButikk(char t[]);
void skrivAlleButikker();        //  Oppgave 2A
void nyButikk();                 //  Oppgave 2B
void gjorKjopIButikk();          //  Oppgave 2C
void endreASTider();             //  Oppgave 2D
void storsteKjopene();           //  Oppgave 2F
void lesFraFil();                //  Oppgave 2G
void skrivTilFil();

                        //  GLOBALE VARIABLE:
Butikk butikkene[MAXBUTIKK+1];    //  Array med Butikk-objekter.
int sisteButikk;                  //  Indeks for siste Butikk hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   lesFraFil();                                     //  Oppgave 2G
   skrivMeny();
   kommando = les("Ønske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'A':  skrivAlleButikker();     break;   //  Oppgave 2A
       case 'N':  nyButikk();              break;   //  Oppgave 2B
       case 'K':  gjorKjopIButikk();       break;   //  Oppgave 2C
       case 'E':  endreASTider();          break;   //  Oppgave 2D
       case 'S':  storsteKjopene();        break;   //  Oppgave 2F
       default:   skrivMeny();             break;
     }
     kommando = les("Ønske");
   }
  skrivTilFil();
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

                                //  Oppgave 2A - Skriver ALLE data
void Butikk::skriv()  {         //                 UNNTATT 'kjopene':
  cout << '\t' << by << ", " << adr << '\n'
       << "\t\tMan-Fre: " << aapneUke << '-' << stengeUke
       << "\tLør: " << aapneLordag << '-' << stengeLordag
       << "\tAnt.kjøp: " << antKjop << '\n'; 
}

                               //   Oppgave 2B - Kopierer inn og leser
void Butikk::lesData(char b[])  {  //            ALLE data UNNTATT 'kjopene':
  strcpy(by, b);                   //  Kopierer og lagrer byens navn.
  les("Adresse", adr, STRLEN);     //  Leser butikkens gateadresse.
  aapneUke     = les("Åpner   M-F", 6, 12);             //  Leser åpnings-
  stengeUke    = les("Stenger M-F", aapneUke+1, 23);    //   og lukketider
  aapneLordag  = les("Åpner     L", 6, 12);             //   til rimelige
  stengeLordag = les("Stenger   L", aapneLordag+1, 20); //   tidspunkt.
}


                              //  Oppgave 2C - Gjør (om mulig) 
void Butikk::gjorKjop()  {    //               ETT kjøp i butikken:
  if (antKjop < MAXKJOP)  {              //  Plass til flere kjøp:
     kjopene[++antKjop] = les("Kjøpt for NOK", 100, 100000);  // Leser kjøp.
     cout << "\n\tKjøpet er registrert/lagt inn.\n\n";
  } else                                 //  Fullt med kjøp:
    cout << "\n\tFullt med " << MAXKJOP << " kjøp i denne butikken!\n\n";
}

                              //  Oppgave 2D - Endrer evt.
void Butikk::endreTider()  {  //               åpnings- og/eller lukketid(er):
  int valg;                            //  Brukerens valg/ønske.
  do  {    
    cout << "\n\t1. Åpner   Man-Fre: " << aapneUke      //  Skriver nåværende
         << "\n\t2. Stenger Man-Fre: " << stengeUke     //     verdier:
         << "\n\t3. Åpner   Lør    : " << aapneLordag
         << "\n\t4. Stenger Lør    : " << stengeLordag << '\n';
    valg = les("Endre nr (0 = avslutt)", 0, 4);         //  Endre hvilken?
    if (valg != 0)  {                                   //  Om reelt valg:
       switch (valg)  {                                 //  Endrer aktuell tid:
         case 1:  aapneUke     = les("Åpne   M-F", 6, stengeUke-1);     break;
         case 2:  stengeUke    = les("Stenge M-F", aapneUke+1, 23);     break;
         case 3:  aapneLordag  = les("Åpne     L", 6, stengeLordag-1);  break;
         case 4:  stengeLordag = les("Stenge   L", aapneLordag+1, 20);  break;
       }
    }
  } while (valg != 0);                 //  Looper inntil ønsker å avslutte.
}

                                //  Oppgave 2E - Beregner og returnerer
int Butikk::kjopTotalt()  {     //               totalsummen av ALLE kjøpene:
   int sum = 0;                 //  Initierer totalsummen.
   for (int i = 1;  i <= antKjop;  i++)  //  Går gjennom alle kjøpene.
       sum += kjopene[i];                //  Summerer opp totalen.
   return sum;                           //  Returnerer totalen.
}

                                //  Oppgave 2G - Leser alle egne data fra fil:
void Butikk::lesFraFil(ifstream & inn, char b[])  {  
  strcpy(by, b);                     //  Kopierer/lagrer parameter.
  inn.getline(adr, STRLEN);          //  Leser gateadresse, tider og ant.kjøp:
  inn >> aapneUke >> stengeUke >> aapneLordag >> stengeLordag 
      >> antKjop;   inn.ignore();
  for (int i = 1;  i <= antKjop;  i++)  //  Leser alle kjøpene:
      inn >> kjopene[i];
  inn.ignore();
}

                                //  EXTRA - Skriver ALLE data til fil:
void Butikk::skrivTilFil(ofstream & ut)  {
  ut << by << '\n' << adr << '\n' << aapneUke << ' ' << stengeUke 
     << ' ' << aapneLordag << ' ' << stengeLordag << ' ' << antKjop << '\n';
  for (int i = 1;  i <= antKjop;  i++)    //  Skriver alle kjøpene:
      ut << ' ' << kjopene[i];
  ut << '\n';
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tA   = skriv Alle butikker\n";
  cout << "\tN   = Ny butikk\n";
  cout << "\tK   = gjør Kjøp i en butikk\n";
  cout << "\tE   = Endre åpnings- og/eller stengtid(er)\n";
  cout << "\tS   = butikkene med de (fem) Største kjøpene\n";
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

                              //  Ut fra en bys navn, så returneres dens indeks
int finnButikk(char t[])  {   //    i "butikkene", evt. '0' om ikke er å finne:
  for (int i = 1;  i <= sisteButikk;  i++) 
      if (butikkene[i].erLik(t))  return i;
  return 0;
}



void skrivAlleButikker()  {    //  Oppgave 2A - Skriver data om ALLE butikkene:
  char ch;                                     //  Tegn fra brukeren.
  for (int i = 1;  i <= sisteButikk;  i++)  {  //  Går gjennom alle butikkene
      butikkene[i].skriv();                    //  Butikken skriver resten selv.
      if (i % 10 == 0)  {                      //  Stopper for hver 10.utskrift:
        cout << "\n\n\n\t\t\t\t\t\tSkriv ett tegn .....";  cin  >> ch;
     }
  }
}


void nyButikk() {          //  Oppgave 2B - Legger (om mulig) inn en ny butikk:
  char navn[STRLEN/2];                        //  Ny bys navn.
 
  if (sisteButikk < MAXBUTIKK)  {             //  Plass til flere byer/butikker:
     les("By", navn, STRLEN/2);               //  Leser byens navn.
     if (finnButikk(navn) == 0)  {            //  Ingen butikk i byen allerede:
        butikkene[++sisteButikk].lesData(navn); //  Ny leser selv sine data.
        cout << "\n\tNy butikk lagt inn som nr." << sisteButikk << "\n\n";
     } else                                     //  Butikk finnes:
       cout << "\n\tFinnes en Armani-butikk i denne byen allerede!\n\n";
  } else                                        //  Fullt:
    cout << "\n\tFullt med " << MAXBUTIKK << " butikker allerede!\n\n";
}


void gjorKjopIButikk()  {    //  Oppgave 2C - Gjør ett kjøp i en butikk:
  int nr;
  char navn[STRLEN/2];                        //  Byens navn.

  les("Innkjøp i byen", navn, STRLEN/2);      //  Leser innkjøpsbyens navn.
  if ((nr = finnButikk(navn)) != 0)           //  Butikk er å finne i byen:
     butikkene[nr].gjorKjop();                //  Gjør kjøp i denne butikken.
  else                                        //  Butikk finnes ikke:
    cout << "\n\tFinnes ingen Armani-butikk i denne byen!\n\n";
}


void endreASTider() {       //  Oppgave 2D - Endre tider for EN butikk:
  int nr;
  char navn[STRLEN/2];                          //  Byens navn.

  les("Endre tid(er) i byen", navn, STRLEN/2);  //  Leser byens navn.
  if ((nr = finnButikk(navn)) != 0)             //  Butikk er å finne i byen:
     butikkene[nr].endreTider();                //  Endre tid(er) for butikken.
  else                                          //  Butikk finnes ikke:
    cout << "\n\tFinnes ingen Armani-butikk i denne byen!\n\n";
}

                            //  Oppgave 2F - Skriver butikkene der de (fem)
void storsteKjopene()  {    //         største totalkjøpene har forekommet:
  int i, j, nr,                //  Løkkevariable og butikknummer/-indeks. 
      sum,                     //  Inspisert butikks totalsum.
      slutt;                   //  Indeks for den siste/femte butikken.
  int minstTilStorst[MAXBUTIKK+1];  //  Indirekte adressering av 'butikkene'.
                                    
  for (i = 1;  i <= sisteButikk;  i++)  {  //  Går gjennom alle butikkene:
    sum = butikkene[i].kjopTotalt();       //  Lagrer butikkens totalkjop.
    j = i;                                 //  Initierer teller.
                                           //  Sålenge forrige er større:
    while (j > 1  &&  sum < butikkene[minstTilStorst[j-1]].kjopTotalt())  {
      minstTilStorst[j] = minstTilStorst[j-1];  j--;  // Flytter opp.
    }  
    minstTilStorst[j] = i;                 //  Smetter inn på plass.
  }
                                   //  Initierer max. fem som skal skrives:
  slutt = (sisteButikk > 5)  ? sisteButikk-5 : 0;
  for (i = sisteButikk;  i > slutt;  i--)  {   //  Looper de max. fem:
      nr = minstTilStorst[i];                  //  Lagrer butikkens indeks. 
      butikkene[nr].skriv();                       //  Skriver butikken,
      cout << "\t\t\t\t\tTotalt kjøpt for NOK: " 
           << butikkene[nr].kjopTotalt() << '\n';  //  og dens totalsum.  
  }     
}


void lesFraFil()  {          //  Oppgave 2G - Leser inn HELE datastrukturen:
  char buffer[STRLEN/2];                   //  Butikkens navn.
  ifstream innfil("DYRESTREETS.DTA");      //  Åpner aktuell fil.

  if (innfil)  {                           //  Filen finnes:
     sisteButikk = 0;
     innfil.getline(buffer, STRLEN/2);     //  Leser (om mulig) 1.felt i post.
                                           //  Ikke slutt og plass til flere:
     while (!innfil.eof()  &&  sisteButikk < MAXBUTIKK)   {
       butikkene[++sisteButikk].lesFraFil(innfil, buffer); // Leser selv.
       innfil.getline(buffer, STRLEN/2);   //  Leser (om mulig) 1.felt i post.
     }
  } else                                   //  Filen ble ikke funnet:
    cout << "\n\nFinner ikke filen 'DYRESTREETS.DTA'!\n\n";
}


void skrivTilFil()  {        //  Skriver HELE datastrukturen til fil:
  ofstream utfil("DYRESTREETS.DT2");        //  Åpner aktuell fil.

  cout << "\n\nSkriver til filen 'DYRESTREETS.DTA' .....\n\n";
  for (int i = 1;  i <= sisteButikk;  i++)  //  Alle butikkene skriver seg selv:
      butikkene[i].skrivTilFil(utfil);
}
