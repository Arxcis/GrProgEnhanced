//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H14_2.CPP

//  Løsningsforslag til eksamen i C++, 2.desember 2014, oppgave 2.
//  Laget av Frode Haug, HiG, november 2014.

//  Programmet holder orden på lagene som deltar i en cup-turnering.
//  Hvem som skal spille mot hverandre, og hvem som fortsatt er med,
//  hvem som er utslått og kampoppsettet.
 
			//  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <cstring>               //  strcpy, strlen
#include <cctype>                //  toupper
using namespace std;

			//  CONST og ENUM:
const int STRLEN     =     60;   //  Max. tekstlengde.
const int MAXLAG     =    100;   //  Max. antall lag
enum status  { Alle, Med, Utslaatt };  //  Styrer handlinger noen steder.


class Lag  {		//  KLASSE:
  private:
    char navn[STRLEN];           //  Lagets navn.
    char deltager1[STRLEN];      //  Navnet til 1.deltager.
    char deltager2[STRLEN];      //  Navnet til 2.deltager.
    bool fortsattMed;            //  Laget fortsatt med eller utslått.
    int  motstander;             //  Indeksen til motstanderlaget,
	                         //           eller 0 (null).
public:                     //  Deklarasjon av medlemsfunksjoner:
    Lag();                       //  Ferdiglaget nedenfor.
    void lesData();                              //  Oppgave 2A
    void skriv(int n, status amu);               //  Oppgave 2B
    void endreStatus(status amu);                //  Oppgave 2D
    void skrivTilFil(ofstream & ut);             //  Oppgave 2F
    void lesFraFil(ifstream & inn, char b[]);    //  Oppgave 2G
			//  3x ferdiglagde - brukes aktivt:
    bool deltarFortsatt()       {  return fortsattMed;  }
    void konkurrererMot(int n)  {  motstander = n;      }
    int  harSpiltMot()          {  return motstander;   }
};

			//  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les();
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
void nyttLag();                  //  Oppgave 2A
void skrivLagene();              //  Oppgave 2B
void oppsettAvKamp();            //  Oppgave 2C
void kampFerdig();               //  Oppgave 2D
void kampOppsettet();            //  Oppgave 2E
void skrivTilFil();              //  Oppgave 2F
void lesFraFil();                //  Oppgave 2G


			//  GLOBALE VARIABLE:
Lag lagene[MAXLAG+1];            //  Array med Lag-objekter.
int sisteLag;                    //  Indeks for siste Lag hittil brukt.

							  
int main()  {			//  HOVEDPROGRAM:
   char kommando;

   lesFraFil();                                     //  Oppgave 2G
   skrivMeny();
   cout << "\nØnske:  ";  kommando = les();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  nyttLag();               break;   //  Oppgave 2A
       case 'S':  skrivLagene();           break;   //  Oppgave 2B
       case 'O':  oppsettAvKamp();         break;   //  Oppgave 2C
       case 'F':  kampFerdig();            break;   //  Oppgave 2D
       case 'K':  kampOppsettet();         break;   //  Oppgave 2E
       default:   skrivMeny();             break;
     }
     cout << "\nØnske:  ";  kommando = les();
   }
  skrivTilFil();                                    //  Oppgave 2F
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

Lag::Lag()   {			//  Constructor initierer alle datamedlemmer:
  strcpy(navn, "");  strcpy(deltager1, "");  strcpy(deltager2, "");
  fortsattMed = true;   motstander = 0;
}

                               
void Lag::lesData()  {		//   Oppgave 2A - Leser ALLE TEKST-data: 
  les("Lagets navn     ", navn, STRLEN);       //  Leser lagets navn.
  les("1.deltagers navn", deltager1, STRLEN);  //  Leser 1.deltagers navn.
  les("2.deltagers navn", deltager2, STRLEN);  //  Leser 2.deltagers navn.
}
				//  Oppgave 2B - Skriver ALLE data om laget når
				//   alle skrives eller de som fortsatt er med:
void Lag::skriv(int n, status amu)  {     //  Datamedlemmene SKAL skrives:
   if ((amu == Alle)  ||  (amu == Med  &&  fortsattMed))  {
      cout << '\t' << n << ":  " << navn << '\t'       //  Skriver nr. og navn,
	   << ((!fortsattMed) ? "IKKE " : "") << "MED"; //   og (ikke) med.
	                                  //  'med':  skriver neste motstander.
      if (fortsattMed)  cout << "\tNeste motstander: " << motstander;
	                                  //  Skriver Begge deltagernes navn:
      cout << "\n\t\tDeltagere: " << deltager1 << " og " << deltager2 << '\n';
   }
}
                                       //  Oppgave 2D - Endrer når er utslått,
void Lag::endreStatus(status amu)  {   //            og resetter motstanderen:
  if (amu == Utslaatt)  fortsattMed = false;
  motstander = 0;
}

                           //  Oppgave 2F - Skriver ALLE data til fil:
void Lag::skrivTilFil(ofstream & ut)  {
  ut << navn << '\n' << deltager1 << '\n' << deltager2 << '\n'
     << fortsattMed << ' ' << motstander << '\n';
}

                          //  Oppgave 2G - Leser alle egne data fra fil:
void Lag::lesFraFil(ifstream & inn, char b[])  {  
  int med;
  strcpy(navn, b);                      //  Kopierer/lagrer parameter.
  inn.getline(deltager1, STRLEN);       //  Leser 1.deltagers navn.
  inn.getline(deltager2, STRLEN);       //  Leser 2.deltagers navn.
  inn >> med >> motstander;             //  Leser om fortsatt med og 
  inn.ignore();                         //     neste motstander.
  fortsattMed = bool(med);              //  Gjør om 0/1 til false/true.
}


// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN    = Nytt lag\n";
  cout << "\tS A  = Skriv Alle lagene\n";
  cout << "\tS M  = Skriv lagene som fortsatt er Med\n";
  cout << "\tO    = Oppsett av kamp\n";
  cout << "\tF    = Ferdig med kamp/konkurranse\n";
  cout << "\tK    = Kampoppsettet\n";
  cout << "\tQ    = Quit/avslutt\n";
}


char les()  {			//  Henter ett ikke-blankt upcaset tegn:
  char ch;
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
  } while (strlen(s) == 0);             //  Sjekker at tekstlengden er ulik 0.
}


void nyttLag() {		//  Oppgave 2A - Legger (om mulig) inn et nytt lag:
  if (sisteLag < MAXLAG)  {                   //  Plass til flere lag:
     cout << "\n\tNytt lag legges inn som nr." << ++sisteLag << ":\n";
     lagene[sisteLag].lesData();              //  Ny leser selv sine data.
  } else                                      //  Fullt:
    cout << "\n\tFullt med " << MAXLAG << " lag allerede!\n\n";
}

			 //  Oppgave 2B - Skriver lagene (ALLE eller kun
void skrivLagene()  {    //               de som fortsatt er MED:
  char onske = les();                        //  Leser 2.parameter/bokstav.
  if (onske == 'A'  ||  onske == 'M')  {     //  En av de lovlige bokstavene:
     for (int i = 1;  i <= sisteLag;  i++)   //  For hvert lag: 
         if (onske == 'A') lagene[i].skriv(i, Alle);  //  Skriver ALLE.
	 else		   lagene[i].skriv(i, Med);   //  Skriver de MED.
  } else                                     //  2.bokstav 'ulovlig':
    cout << "\n\tKommando nr.2 MÅ være enten 'A' eller 'M'.\n\n";
}

 			//  Oppgave 2C - Legger inn (om mulig) hvilke to
void oppsettAvKamp()  { //               lag som skal konkurrere mot hverandre:
   int nr1 = les("Første lag", 1, sisteLag),   //  Leser lagenes numre:
       nr2 = les("Andre  lag", 1, sisteLag);
   if (nr1 !=  nr2)  {               //  To ulike lag er skrevet inn:
                                     //  Ingen lag har motstander allerede:
      if (lagene[nr1].harSpiltMot() == 0  && lagene[nr2].harSpiltMot() == 0)  {
	                                       //  Ingen av lagene er utslått:
	 if (lagene[nr1].deltarFortsatt()  &&  lagene[nr2].deltarFortsatt())  {
            lagene[nr1].konkurrererMot(nr2);   //  De angis som hverandres
            lagene[nr2].konkurrererMot(nr1);   //    motstandere.
	 } else                          //  Lag(ene) er utslått:
          cout << "\n\tMinst ett av lagene er utslått/deltar ikke lengre.\n\n";
      } else                             //  Lag(ene) har motstander allerede:
        cout << "\n\tMinst ett av lagene er involvert i en kamp allerede!\n\n";
   } else                                //  Samme lagnummer er skrevet:
    cout << "\n\tLagenes numre må være ulike!\n\n";
}

		      //  Oppgave 2D - Registrerer (om mulig) resultatet
void kampFerdig()  {  //               av konkurrranse/kamp (hvem vant/tapte):
   int nr1 = les("Laget som vant ", 1, sisteLag),  //  Leser lagenes numre:
       nr2 = les("Laget som tapte", 1, sisteLag);
                                      //  Riktige motstandere/kamp er angitt:
   if (lagene[nr1].harSpiltMot() == nr2  &&  lagene[nr2].harSpiltMot() == nr1)
   {
      lagene[nr1].endreStatus(Med);       //  Setter at fortsatt 'Med'.
      lagene[nr2].endreStatus(Utslaatt);  //  Setter at 'Utslått'.
   } else                             //  Feil lagnummer er angitt:
    cout << "\n\tDisse to lagene har ikke konkurrert mot hverandre!\n\n";
}


			    //  Oppgave 2E - Skriver alle kampene 
void kampOppsettet()  {     //               (med høyeste lagnummer først):
  int motstander, kampNr = 0;                  //  Initierer kampnummer-teller:
  cout << "\n\tKAMPOPPSETTET:\n";
  for (int i = sisteLag;  i >= 1;  i--)  {     //  Går baklengs gjennom lagene:
      motstander = lagene[i].harSpiltMot();    //  Henter lagets motstandernr.
	                                  //  Har motstander, og egen indeks større
      if (motstander != 0  &&  i > motstander)  {     //  enn motstanderen sin:
         cout << "\t\tKamp nr." << ++kampNr << ":  "  //  Skriver kampnr og
	      << i << " - " << motstander << '\n';    //  involverte lags nr.
      }
  }
}


void skrivTilFil()  {     //  Oppgave 2F - Skriver HELE datastrukturen til fil:
  ofstream utfil("PROSKONK.DT2");          //  Åpner aktuell fil.

  cout << "\n\nSkriver til filen 'PROSKONK.DTA' .....\n\n";
  for (int i = 1;  i <= sisteLag;  i++)    //  Alle lagene skriver seg selv:
      lagene[i].skrivTilFil(utfil);
}


void lesFraFil()  {          //  Oppgave 2G - Leser inn HELE datastrukturen:
  char buffer[STRLEN];                     //  Lagets navn.
  ifstream innfil("PROSKONK.DTA");         //  Åpner aktuell fil.

  if (innfil)  {                           //  Filen finnes:
     sisteLag = 0;                         //  Nullstiller (for å være sikker).
     innfil.getline(buffer, STRLEN);       //  Leser (om mulig) 1.felt i post.
                                           //  Ikke slutt og plass til flere:
     while (!innfil.eof()  &&  sisteLag < MAXLAG)   {
       lagene[++sisteLag].lesFraFil(innfil, buffer); // Leser resten selv.
       innfil.getline(buffer, STRLEN);     //  Leser (om mulig) 1.felt i post.
     }
  } else                                   //  Filen ble ikke funnet:
    cout << "\n\nFinner ikke filen 'PROSKONK.DTA'!\n\n";
}
