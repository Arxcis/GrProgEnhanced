//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H05_2.CPP

//  Løsningsforslag til eksamen i C++, 19.desember 2005, oppgave 2.
//  Laget av Frode Haug, HiG, desember 2005.


//  Program som holder orden på bestilling/reservering/booking av et
//     låneobjekt (hall e.l.) til ulike klokkeslett i løpet av en uke.


                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream, fstream
#include <cctype>             //  toupper
#include <cstring>            //  strcpy
#include <iomanip>            //  setw

using namespace std;

                        //  CONST:
const int ANT_DAGER  =  7;    //  Antall dager i en uke.
const int ANT_TIMER  = 14;    //  Timene i løpet av en dag (kl.07.00-20.00).
const int START_TIME =  7;    //  Startklokkeslett om morgenen.
const int STRLEN1    =  5;    //  Max. tekstlengde for en ukedags navn.
const int STRLEN2    = 30;    //  Max. tekstlengde for en bestillers navn.

                        //  KLASSER:
class Ukedag  {               //  Ukedag for bestilling/booking:
  private:
    char navn[STRLEN1];       //  Navn.
    char book[ANT_TIMER][STRLEN2];  //  Navn på bestiller et gitt klokkeslett.

  public:
    void skriv();             //  Deklarasjon av medlemsfunksjoner:
    void resett();
    void bestill();
    void avbestill();
    void skriv_til_fil(ostream* ut);
    void les_fra_fil(char nvn[], istream* inn);
};

                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les_kommando();
int  les(char t[], int min, int max);
void skriv_dag();
void resett_dag();
void bestill_time();
void avbestill_time();
void skriv_til_fil();
void les_fra_fil();


                        //  GLOBALE VARIABLE:
Ukedag uka[ANT_DAGER];               //  Array med Ukedag-objekter.

                        
int main()  {           //  HOVEDPROGRAM:
   char kommando;
   
   les_fra_fil();                                 //  Oppgave 2f
   resett_dag();                                  //  Oppgave 2b

   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'S':  skriv_dag();           break;   //  Oppgave 2a
       case 'B':  bestill_time();        break;   //  Oppgave 2c
       case 'A':  avbestill_time();      break;   //  Oppgave 2d
       default:   skriv_meny();          break;
     }
//     skriv_til_fil();                             //  Oppgave 2e
     kommando = les_kommando();
   }
  cout << "\n\n";
  return 0;
}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:
void Ukedag::skriv()  {      //  OPPGAVE 2A  -  Skriver ALLE data om en ukedag:
  cout << "\n\nDag: " << navn << "dag:";        //  Dagens navn.
  for (int i = 0;  i < ANT_TIMER;  i++)         //  Bookere ulike klokkeslett:
    cout << "\n\t" << setw(2) << i+START_TIME << ".00:\t" << book[i];
}


void Ukedag::resett()  {     //  OPPGAVE 2B  -  Sletter ALLE bestillinger:
  for (int i = 0;  i < ANT_TIMER;  i++)         //  Fjerner ALLE bestillinger:
      strcpy(book[i], "");                      
}


void Ukedag::bestill()  {    //  OPPGAVE 2C  -  Foretar EN bestilling:
  int nr;                                       //  Leser klokkeslett 7-20:
  int time = les("BESTILLING - kl." , START_TIME, START_TIME+ANT_TIMER-1);
  nr = time-START_TIME;                         //  Konverterer til 0-13.
  if (strlen(book[nr]) == 0)  {                 //  Timen er ledig:
     cout << "\tReserverers navn: ";            //  Foretar reservasjon:
     cin.getline(book[nr], STRLEN2);
  } else
	  cout << "\nBestilling/reservasjon/booking allerede dette klokkeslettet!\n";
}


void Ukedag::avbestill()  {  //  OPPGAVE 2D  -  Fjerner/sletter EN bestilling:
  int nr;                                       //  Leser klokkeslett 7-20:
  int time = les("AVBESTILLING - kl." , START_TIME, START_TIME+ANT_TIMER-1);
  nr = time-START_TIME;                         //  Konverterer til 0-13.
  if (strlen(book[nr]))  {                      //  Reservasjon er foretatt:
     cout << "\n\tBestillingen for '" << book[nr] << "' er slettet.\n";
     strcpy(book[nr], "");                      //  Fjerner reservasjonen:
  } else
     cout << "\nIngen bestilling/reservasjon/booking dette klokkeslettet!\n";
}


void Ukedag::skriv_til_fil(ostream* ut)  {  //  OPPGAVE 2E  -  Skriver til fil:
  *ut << navn << '\n';                          //  Navnet på EN linje.
  for (int i = 0;  i < ANT_TIMER;  i++)         //  Alle klokkeslettene en dag:
    if (strlen(book[i]))                        //  Reservasjon:
       *ut << "+ " << book[i] << '\n';          //  Skriver '+' og navnet.
    else                                        //  Ledig:
       *ut << "-\n";                            //  Skriver kun '-'.
}

                                            //  OPPGAVE 2F  -  Leser fra fil:
void Ukedag::les_fra_fil(char nvn[], istream* inn)  {  
  char tegn;                                    //  '+' eller '-'.
  strcpy(navn, nvn);                            //  Kopierer over/inn navnet.
  for (int i = 0;  i < ANT_TIMER;  i++)  {      //  Alle klokkeslettene leses:
    *inn >> tegn;                               //  Henter '+' eller '-'.
    if (tegn == '+')  {                         //  '+'/reservasjon:
       (*inn).ignore();                         //  Skipper EN blank.
       (*inn).getline(book[i], STRLEN2);        //  Leser reservatørs navn.
    }
  }
}

                        //  DEFINISJON AV FUNKSJONER:
		  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tS = Skriv alle bestillinger en gitt dag\n";
  cout << "\tB = Bestill/reserver/book en time\n";
  cout << "\tA = Avbestill en time\n";
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


void skriv_dag()  {          //  OPPGAVE 2A - Skriv ALLE bestillinger EN gitt dag:
  int nr;
  cout << "\n\nSKRIVER ALLE BESTILLINGER\n";
  nr = les("Ukedag (mandag-søndag)", 1, ANT_DAGER); //  Leser ukedag (1-7).
  uka[nr-1].skriv();                                //  Dagens data skrives.
}


void resett_dag()  {		//  OPPGAVE 2B - Slett ALT en gitt dag:
  int nr;
  cout << "\n\nRESETT (SLETT ALT) EN DAG\n";        //  Leser ukedag (0-7):
  nr = les("Ukedag (mandag-søndag, 0=ingen)", 0, ANT_DAGER);
  if (nr)                                           //  Dagnr = 1-7:
    uka[nr-1].resett();                             //  Reservasjonene slettes.
  else                                              //  Dagnr = 0:
    cout << "\nIngen resetting/sletting utført!\n";
}


void bestill_time()  {       //  OPPGAVE 2C - Bestill/reserver/book en time:
  int nr;
  cout << "\n\nBESTILL/RESERVER/BOOK EN TIME\n";    //  Leser ukedag (0-7):
  nr = les("Ukedag (mandag-søndag, 0=angre)", 0, ANT_DAGER);
  if (nr)                                           //  Dagnr = 1-7:
    uka[nr-1].bestill();                            //  Foretar reservasjon.
  else                                              //  Dagnr = 0:
    cout << "\nIngen bestilling utført!\n";
}


void avbestill_time()  {     //  OPPGAVE 2D - Avbestill en time:
  int nr;
  cout << "\n\nAVBESTILL EN TIME\n";                //  Leser ukedag (0-7):
  nr = les("Ukedag (mandag-søndag, 0=angre)", 0, ANT_DAGER);
  if (nr)                                           //  Dagnr = 1-7:
    uka[nr-1].avbestill();                          //  Foretar avbestiling.
  else                                              //  Dagnr = 0:
    cout << "\nIngen avbestilling utført!\n";
}


void skriv_til_fil()  {      //  OPPGAVE 2E - Skriver datastrukturen til fil:
  ofstream utfil("booking.dta");
  for (int i = 0;  i < ANT_DAGER;  i++)   //   ALLE ukedagene skrives til fil:
     uka[i].skriv_til_fil(&utfil);
}


void les_fra_fil()  {        //  OPPGAVE 2F - Leser datastrukturen fra fil:
  ifstream innfil("booking.dta");
  char nvn[STRLEN1];                    //  En ukedags navn.
  int nr = 0;                           //  Aktuelt ukedagsnummer.
  if (innfil)  {                        //  Filen var mulig å åpne:
     innfil >> nvn;                     //  Leser (om mulig) neste ukedagsnavn.
     while (!innfil.eof())  {           //  Ennå mer på filen:
       uka[nr++].les_fra_fil(nvn, &innfil);  //  'Ukedag' leser resten selv.
       innfil >> nvn;                   //  Leser (om mulig) neste ukedagsnavn.
     }
  } else                                //  Filen lot seg ikke åpne:
    cout << "\n\nFant ikke filen 'BOOKING.DTA'!\n\n";
}
