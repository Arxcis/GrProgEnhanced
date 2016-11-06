//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H98_3.CPP

//  Løsningsforslag til eksamen i C++, 15.desember 1998, oppgave 3.
//  Laget av Frode Haug, HiG, desember 1998.
//  En god del endret/modifisert av FrodeH, HiG, høsten 2003.

//  Program for å administrere telefonnumre (og adresser) for ulike
//  kontakter/familie/venner.


                        //  INCLUDE:
#include <fstream>           //  ifstream
#include <iostream>          //  cout, cin
#include <cctype>            //  toupper
#include <cstring>           //  strcmp, strlen

using namespace std;
                        //  CONST:
const int STRLEN =  60;      //  Max.lengde for en tekststreng.
const int MAXTLF = 200;      //  Max.antall i kartoteket.

                        //  KLASSE:
class Telefonnr {            
  private:                   //  OPPGAVE 3A: Deklarere data-innmaten:
    int nummer;              //  Telefonnummeret.
    char navn[STRLEN];       //  Personens navn,
    char gadr[STRLEN];       //    gateadresse og
    char psted[STRLEN];      //    poststed.
  
  public:
	void les_data();            //  Oppgave 3c
    void skriv_data(int n);     //  Oppgave 3d
    bool lik_navn(char nvn[]);  //  Oppgave 3f
    int  hent_telefonnummer();  //  Oppgave 3f
	void les_fra_fil(istream * inn, int nr);  //  Oppgave 3g
};


void skriv_meny();      //  DEKLARASJON AV FUNKSJONER:
void les(char & ch);
void les(char txt[], char txt2[]);
void ny();
void oversikt();
bool slett(int n);
int  finn(char nvn[]);
void les_fra_fil();


                        //  GLOBALE VARIABLE:
Telefonnr kartotek[MAXTLF+1];   //  OOPPGAVE 3A: Definere datastrukturen:
int siste_brukt;                //  Antall elementer brukt av "kartotek".

                        
int main()  {           //  HOVEDPROGRAMMET:
  char kommando;            //  Brukerens valg/ønske/kommando.
  int nr;                   //  Indeksen som skal slettes (se case 'S').
  int nummer;               //  Indeksen til funnet telefonnumer (se case 'F').
  char navnet[STRLEN];      //  Navnet tilhørende ønsket tlf.nr. (se case 'F').

  les_fra_fil();            //  Oppgave 3g

  skriv_meny();
  les(kommando);             //  Leser brukerens valg/ønske/kommando.
  while (kommando != 'Q')  { //  Så lenge ikke avslutte (quit):
    switch(kommando)  {
      case 'N':   ny();        break;     //  Oppgave 3c

      case 'O':   oversikt();  break;     //  Oppgave 3d

      case 'S':   cout << "\tHvilken indeks vil du slette:  ";  cin >> nr;
                  if (slett(nr))     //  Oppgave 3e
                     cout << "\n\tDenne indeksen er nå slettet.";
                  else
                     cout << "\n\tIndeksen utenfor relevant område!";    break;
      case 'F':   les("Navn", navnet);    //  Oppgave 3b
                  nummer = finn(navnet);  //  Oppgave 3f
                  if (nummer != 0)
                     cout << "\n\tTelefonnummeret er:  " << nummer;
                  else
                     cout << "\n\tIngen i kartoteket har dette navnet!"; break;

      default: skriv_meny();
    }
    les(kommando);
  }
                       //  Burde ha skrevet datastrukturen tilbake til fil.
//  skriv_til_fil();   //  Men dette er ikke en del av denne eksamensoppgaven.
  return 0;
}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:
                        //  OPPGAVE 3C:
void Telefonnr :: les_data()  {
  cout << "\tNytt tlfnr: "; //  Leser telefonnummer og andre data: 
  cin >> nummer;   cin.ignore();
  les("Navn   ", navn);     //  Til dette brukes funksjonen laget i oppgave 3b:
  les("Gateadr", gadr);     //    
  les("Postadr", psted);
}

                        //  OPPGAVE 3D:
void Telefonnr :: skriv_data(int n)  {
  cout << "\nNr." << n << ':'       // Skriver indeks, tlf.nr, navn og adresse:
       << "\t"    << nummer << '\t' << navn  
       << "\n\t\t\t"  << gadr   << ", " << psted;
}

                        //  OPPGAVE 3F:
bool Telefonnr :: lik_navn(char nvn[])  {    
  return (strcmp(nvn, navn) ? false : true); // LIKE: "strcmp" returnerer '0':
}

                        //  OPPGAVE 3F:
int Telefonnr :: hent_telefonnummer()  {
   return nummer;            //  Returnerer (kun) telefonnummeret.
}

                        //  OPPGAVE 3G:
void Telefonnr :: les_fra_fil(istream * inn, int nr)  {  // Filobjektet "inn":
  nummer = nr;            //  Kopierer innlest "nr" til eget "nummer".     
  (*inn).ignore();           //  Forkaster '\n' etter telefonnummeret.
  (*inn).getline(navn, STRLEN);   //  Leser inn navn.
  (*inn).getline(gadr, STRLEN);   //  Leser gateadresse.
  (*inn).getline(psted, STRLEN);  //  Leser poststed.
}



                        //  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {
  cout << "\n\nFølgende kommandoer er lovlige:"
       << "\n\tN - Nytt telefonnummer inn i kartoteket."
       << "\n\tO - Oversikt over hele kartoteket skrives til skjermen."
       << "\n\tS - Slette alt på en gitt indeks i kartoteket."
       << "\n\tF - Finn telefonnummeret for en gitt person."
       << "\n\tQ - Quit/avslutt.";
}

                             //  Oppdaterer direkte den 'ch' er et alias for 
void les(char & ch)  {       //    (da denne er referanseoverført).
  cout << "\n\nKommando:  ";
  cin >> ch;                 //  Leser brukerens valg/ønske/kommando.
  ch = toupper(ch);          //  Gjør 'ch' om til STOR bokstav.
  cin.ignore();              //  Forkaster neste tegn ('\n').
}

                        //  OPPGAVE 3B:
void les(char txt[], char txt2[])  {
  do {                                    
    cout << '\t' << txt << ": ";       //  Skriver ut ledetekst/prompt.
    cin.getline(txt2, STRLEN);         //  Leser tekst fra brukeren. 
  } while (strlen(txt2) == 0);         //  Looper så lenge kun ENTER/CR.
}

                        //  OPPGAVE 3C:
void ny()  {
  if (siste_brukt < MAXTLF)            //  Plass til flere i kartoteket.
     kartotek[++siste_brukt].les_data();  //  Objektet leser resten selv.
  else                                 //  Kartoteket er fullt:
    cout << "\n\n\tTelefonkartoteket er fullt med " << MAXTLF << " stk.";
}

                        //  OPPGAVE 3D:
void oversikt()  {
  if (siste_brukt > 0)                 //  Noen i kartoteket:
     for (int i = 1;  i <= siste_brukt;  i++)   
         kartotek[i].skriv_data(i);    //  Objektet skriver seg selv ut.
  else                                 //  Kartoteket er tomt:
    cout << "\n\n\tTelefonkartoteket er fortiden TOMT.";
}

                        //  OPPGAVE 3E:
bool slett(int n)  {
  if (n >= 1  && n <= siste_brukt)  {  //  Indeks i rett intervall:
     kartotek[n] = kartotek[siste_brukt--]; //  Flytter den siste inn i
     return true;                           //   "hullet" og returnerer 'true'.
  }
  else                                 //  Indeks utenfor intervall: 
     return false;                     //  Returnerer 'false'.  
}


                        //  OPPGAVE 3F:
int finn(char nvn[])  {     //  Går gjennom "alle" objektene. Når får treff
	                        //    på navnet så returneres aktuelt telefonnr:
	for (int i = 1; i <= siste_brukt;  i++)
      if (kartotek[i].lik_navn(nvn))  return (kartotek[i].hent_telefonnummer());
  return 0;                 //  Ellers returneres 0.
}

                        //  OPPGAVE 3G:
void les_fra_fil()  {
  ifstream inn("KARTOTEK.DTA");        //  Åpner filen.
  int nummer;                          //  Telefonnummeret som (om mulig) leses.

  siste_brukt = 0;                     //  Nullstiller elementer brukt. 

  if (inn)  {                          //  Filen finnes: 
     inn >> nummer;                    //  Leser (om mulig) neste tlf.nr.
                  //  Så lenge ikke slutt på filen og ikke fylt opp kartoteket:
     while (!inn.eof()  &&  siste_brukt < MAXTLF)  { // Objektet leser seg selv:
       kartotek[++siste_brukt].les_fra_fil(&inn, nummer);
       inn >> nummer;                  //  Leser (om mulig) neste tlf.nr.
     }
  } else                               //  Filen finnes ikke: 
    cout << "\nFinner ikke filen 'KARTOTEK.DTA'.";
}
