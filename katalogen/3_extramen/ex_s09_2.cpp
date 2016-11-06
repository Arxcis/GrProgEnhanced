//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S09_2.CPP

//  Lõsningsforslag til kontinuasjonseksamen i C++, 14.august 2009, oppgave 2.
//  Laget av Frode Haug, HiG, mai 2009.

//  Program som holder orden pÜ status for utleie av sykler for ETT
//     firma med tre ulike utleiesteder.
  

                        //  INCLUDE:
#include <fstream>           //  ifstream, ofstream
#include <iostream>          //  cin, cout
#include <iomanip>           //  setw
#include <cstring>           //  strcpy, strlen
#include <cctype>            //  toupper
using namespace std;

                        //  CONST og ENUM:
const int  STRLEN     =       40;   //  Max. tekstlengde.
const int  MAXSYKLER  =      100;   //  Max. antall sykler til utleie.
const int  MINDAG     =      100;   //  Min. dagnummer i Üret (i april).
const int  MAXDAG     =      300;   //  Max. dagnummer i Üret (i oktober).
const int  MINTLF     = 10000000;   //  Min. telefonnummer.
const int  MAXTLF     = 99999999;   //  Max. telefonnummer.
enum  Sted { Haugastol, Finse, Flaam  };   //  Steder med sykkelutleie.


class Sykkel  {         //  KLASSER:
  private:
    char navn[STRLEN];             //  Leiers navn.
    int  tlf;                      //  Leiers kontaktinfo - kun (mobil)telefon.
    int  dagnr;                    //  Dagnummeret i Üret sykkelen ble leiet.
    bool ledig;                    //  Sykkelen ledig eller ei.
    Sted sted;                     //  Stedet sykkelen ble leiet/befinner seg.

  public:                    //  Definisjon/deklarasjon av medlemsfunksjoner:
    Sykkel();                               //  Oppgave 2A
    bool er_ledig()   {  return ledig;  }
    Sted hent_sted()  {  return sted;   }
    void skriv_sted();                      //  Oppgave 2A
    void skriv(int n);                      //  Oppgave 2C
    void utlever();                         //  Oppgave 2D
    void innlever();                        //  Oppgave 2E
    void skriv_til_fil(ostream* ut);        //  Oppgave 2F
    void les_fra_fil(istream* inn);         //  Oppgave 2G
};

                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les(char t[]);
void les(const char t[], char s[], const int LEN);
int  les(const char t[], const int min, const int max);

Sted les_sted();             //  Oppgave 2B
int  finn_ledig(Sted h);     //  Oppgave 2B
void skriv_alle();           //  Oppgave 2C
void utlevering();           //  Oppgave 2D
void innlevering();          //  Oppgave 2E
void skriv_til_fil();        //  Oppgave 2F
void les_fra_fil();          //  Oppgave 2G


                        //  GLOBALE VARIABLE:
Sykkel syklene[MAXSYKLER+1]; //  Sykkel-objekter (bruker indeks 1-100).
int dagnummer;               //  Innevërende dags nummer i Üret.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   les_fra_fil();                             //  Oppgave 2G
   dagnummer = les("Dagens dagnummer i Üret", MINDAG, MAXDAG);

   skriv_meny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'U':  utlevering();     break;    //  Oppgave 2D
       case 'I':  innlevering();    break;    //  Oppgave 2E
       case 'S':  skriv_alle();     break;    //  Oppgave 2C
       case 'T':  skriv_til_fil();  break;    //  Oppgave 2F
       default:   skriv_meny();     break;
     }
     kommando = les("ùnske");
   }
  skriv_til_fil();                            //  Oppgave 2F
  cout << "\n\n";
  return 0;
}


// *******************   DEFINISJON AV KLASSE-FUNKSJONER:  *******************

Sykkel::Sykkel()  {             //  OPPGAVE 2A - Initierer ALLE datamedlemmer:
  strcpy(navn, "");   tlf = dagnr = 0;
  ledig = true;       sted = Haugastol;
}


void Sykkel::skriv_sted()  {      //  OPPGAVE 2A - Enum-verdi ut som tekst:
  switch (sted)  {
    case Haugastol: cout << "Haugastõl";  break;
    case Finse:     cout << "Finse    ";  break;
    case Flaam:     cout << "FlÜm     ";  break;
  }
}


void Sykkel::skriv(int n)  {      //  OPPGAVE 2C - ALLE data (til skjerm):
  cout << setw(3) << n << ": ";          //  Indeks-nummer.
  skriv_sted();                          //  Utleiested.
  cout << '\t';
  if (ledig)  cout << "LEDIG";           //  Ledig.
  else  {                                //  Utleid: Skriver utleiedagnr,
    cout << dagnr << "  " << navn << " (" << tlf << ')';  //  navn og tlf.
  }
  cout << '\n';
}


void Sykkel::utlever()  {         //  OPPGAVE 2D - Data settes nÜr leies:
  dagnr = dagnummer;                     //  Utleid pÜ dagen i dag.
  ledig = false;                         //  Opptatt/utleid.
  les("Leiers navn", navn, STRLEN);      //  Leiers navn.
  tlf = les("Telefon", MINTLF, MAXTLF);  //  Leiers kontaktinfo (telefon).
}


void Sykkel::innlever()  {        //  OPPGAVE 2E - Skriver info, resetter data:
  cout << "\n\tUteid til: " << navn << " i "   //  Skriver leiers navn og
       << dagnummer-dagnr << " dager, fra ";   //     ant. dagers leie.
  skriv_sted();                                //  Skriver utleiested.
  cout << ".\n\n\tInnlevert pÜ\n";
  sted = les_sted();                           //  Lese leveringssted.
  strcpy(navn, "");   tlf = dagnr = 0;  ledig = true;  //  Nullstiller data.
}

                             //  OPPGAVE 2F - Skriver ALT om sykkelen til fil:
void Sykkel::skriv_til_fil(ostream* ut)  {
  *ut << ((ledig)? "L" : "O") << ' ';          //  L(edig) eller O(pptatt).
  switch (sted)  {
    case Haugastol: *ut << 'H';  break;        //  Bokstaver for sted der
    case Finse:     *ut << 'I';  break;        //    befinner seg eller  
    case Flaam:     *ut << 'L';  break;        //    ble leid ut fra.
  }
  *ut << ' ' << dagnr << ' ' << tlf << ' ' << navn << '\n';
}

                             //  OPPGAVE 2G - Leser ALT om sykkelen fra fil:
void Sykkel::les_fra_fil(istream* inn)  {
  char l, s;

  *inn >> l >> s >> dagnr >> tlf;       //  Henter O/L, H/I/L, dagnr, tlf
  (*inn).ignore();
  (*inn).getline(navn, STRLEN);         //  Leiers navn evt. '' (blank).
                                        //  Konvertere 'ledig'
  ledig = (l == 'L');   // =  if (l=='L') ledig = true;  else ledig = false;
  switch (s)  {                         //    og utleiested:
    case 'H':  sted = Haugastol;  break;
    case 'I':  sted = Finse;      break;
    case 'L':  sted = Flaam;      break;
 
  }
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tU   = Utleie/Utlevering av sykkel\n";
  cout << "\tI   = Innlevering av sykkel\n";
  cout << "\tS   = Skriv alle syklene\n";
  cout << "\tT   = skriv Til fil\n";
  cout << "\tQ   = Quit/avslutt\n";
}


char les(char t[])  {        //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << '\n' << t << ":  ";   //  Skriver medsendt ledetekst.
  cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
  return (toupper(ch));         //  Upcaser og returnerer.
}

                             //  Leser inn en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {  
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, LEN);          //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
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


Sted les_sted()  {           //  OPPGAVE 2B - Finner/leser "enumverdi":
                                     //  Heltall (1-3) blir enum-verdi:
  switch (les("sted (1=Haugstõl,2=Finse, 3=FlÜm)", 1, 3))  {
    case 1:  return  Haugastol;
    case 2:  return  Finse;
    case 3:  return  Flaam;
  }
}


int finn_ledig(Sted h)  {   // OPPGAVE 2B - Indeks (om mulig) til ledig sykkel:
  for (int i = 1;  i <= MAXSYKLER;  i++)  //  GÜr gjennom syklene:
                                          //  Nr.i er ledig og pÜ rett sted:
      if (syklene[i].er_ledig()  &&  syklene[i].hent_sted() == h)
         return i;                        //  Returnerer aktuell indeks.
  return 0;                               //  Ingen match - returnerer 0.
}


void skriv_alle()  {         //  OPPGAVE 2C -Skriver ALT om ALLE syklene:
  char ch;

  cout << "\nDagens dagnummer:  " << dagnummer << "\n\n";
  for (int i = 1;  i <= MAXSYKLER;  i++)  {  //  GÜr gjennom ALLE syklene:
      syklene[i].skriv(i);                   //  De skriver seg selv ut.
      if (i % 20 == 0)  {                    //  Stanser for hver 20nde.
         cout << "\t\t\t\t\t\tSkriv ETT tegn og ENTER ...";
         cin >> ch;
      }
  }
}


void utlevering()  {         //  OPPGAVE 2D - Utlever en sykkel et sted:
  int nr;

  cout << "\tUtlever sykkel pÜ\n";        //  Leser bÜde õnsket sted, og finner
  if ((nr = finn_ledig(les_sted())))  {   //    (om mulig) indeks for en ledig:
     cout << "\n\tUtleid sykkel har nr." << nr << '\n';
     syklene[nr].utlever();               //  Sykkelen settes utleid/utlÜnt.
  } else
    cout << "\n\tIngen ledig sykler pÜ dette steder!\n\n";
}


void innlevering()  {        //  OPPGAVE 2E - Innlever en sykkel ett sted:
  int nr = les("Innlever sykkel nr.", 1, MAXSYKLER);  //  Leser aktuelt nr.

  if (!syklene[nr].er_ledig())            //  Om er utlÜnt:
     syklene[nr].innlever();              //  Settes innlevert.
  else
     cout << "\n\tDenne sykkelen er IKKE utlÜnt!\n\n";
}


void skriv_til_fil()  {      //  OPPGAVE 2F - Skriver ALT til fil:
  ofstream utfil("SYKLER.DTA");           //  èpner aktuell fil.

  for (int i = 1;  i <= MAXSYKLER;  i++)  //  GÜr gjennom ALLE syklene:
      syklene[i].skriv_til_fil(&utfil);   //  Skriver seg selv til fil.
}


void les_fra_fil()  {        //  OPPGAVE 2G - Leser ALT fra fil:
  ifstream innfil("SYKLER.DTA");

  if (innfil)  {                            //  Filen finnes:
     for (int i = 1;  i <= MAXSYKLER;  i++) //  For ALLE syklene:
         syklene[i].les_fra_fil(&innfil);   //  Leser seg selv fra fil.
  } else
    cout << "\n\n\tFant ikke filen 'SYKLER.DTA'\n";
}
