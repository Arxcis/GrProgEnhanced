//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S14_2.CPP

//  Løsningsforslag til kontinuasjonseksamen i C++, 8.august 2014, oppgave 2.
//  Laget av Frode Haug, HiG, juli 2014.

//  Program som holder orden på kunder og deres bestilling 
//  av vindusglass med ulike mål og fra ulike produsenter.
  

                        //  INCLUDE:
#include <fstream>               //  ifstream, ofstream
#include <iostream>              //  cin, cout
#include <iomanip>               //  setw
#include <cstring>               //  strcpy, strlen
#include <cctype>                //  toupper
using namespace std;

                        //  CONST:
const int STRLEN     =   40;     //  Tekstlengde.
const int MAXGLASS   =   20;     //  Max. ulike glassmål.
const int MAXKUNDE   =  400;     //  Max. antall kunder.
const int KVMPRIS    = 1300;     //  Pris pr.kvm - uansett produsent.


class Kunde {           //  KLASSER:
  private:
    char navn[STRLEN];           //  Navn.
    char adr[STRLEN*4];          //  Gate- og postadresse.
    int  tlf,                    //  Telefon.
         startDato,              //  Arbeidets startdato (på formen: MMDD).
         antDager;               //  Antall dager på/til arbeidet.
    int  glass[MAXGLASS];        //  Antall bestilt av glass nr.i.
 
  public:                        //  Deklarasjon av medlemsfunksjoner:
    Kunde();
    void skriv();                           //  Oppgave 2B (og 2C)
    void skrivEnkelt();                     //  Oppgave 2B
    void skrivOmfattende();                 //  Oppgave 2C
    void lesData();                         //  Oppgave 2D
    void faktura();                         //  Oppgave 2E
    void lesFraFil(ifstream & inn, int t);  //  Oppgave 2F
    int  hentBestilt(int n);                //  Oppgave 2G
    void skrivTilFil(ofstream & ut);
};


class Glass {
  private:
    char produsent[STRLEN];      //  Produsentens navn.
    int  bredde, hoyde;          //  Glassets mål (bredde/høyde) i mm(!).

  public:                        //  Deklarasjon av medlemsfunksjoner:
    Glass();
    void skriv();                           //  Oppgave 2A
    float kvm();                            //  Oppgave 2E
    void lesFraFil(ifstream & inn);         //  Oppgave 2F
};



                    //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);

void skrivAlleGlassene();        //  Oppgave 2A
void skrivKundeEnkelt();         //  Ferdiglaget (Oppgave 2B)
void skrivKundeOmfattende();     //  Ferdiglaget (Oppgave 2C)
void nyKunde();                  //  Oppgave 2D
void faktura();                  //  Ferdiglaget (Oppgave 2E)
void lesFraFil();                //  Oppgave 2F
void glasStatistikk();           //  Oppgave 2G
void skrivTilFil();

                        //  GLOBALE VARIABLE:
Kunde kundene[MAXKUNDE+1];       //  Array med Kunde-objekter.
Glass glassene[MAXGLASS];        //  Array med Glass-objekter
int sisteKunde;                  //  Indeks for siste Kunde hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   lesFraFil();                                     //  Oppgave 2F
   skrivMeny();
   kommando = les("Ønske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'G':  skrivAlleGlassene();     break;   //  Oppgave 2A
       case 'E':  skrivKundeEnkelt();      break;   //  Oppgave 2B
       case 'O':  skrivKundeOmfattende();  break;   //  Oppgave 2C
       case 'N':  nyKunde();               break;   //  Oppgave 2D
       case 'F':  faktura();               break;   //  Oppgave 2E
       case 'S':  glasStatistikk();        break;   //  Oppgave 2G
       default:   skrivMeny();             break;
     }
     kommando = les("Ønske");
   }
  skrivTilFil();
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

Kunde::Kunde()  {             //  Initierer/nullstiller ALLE datamedlemmer:
   strcpy(navn, "");  strcpy(adr, "");  tlf = startDato = antDager = 0;
   for (int i = 0;  i < MAXGLASS;  i++)  glass[i] = 0;
}


void Kunde::skriv()  {        //  Oppgave 2B (og 2C) - Skriver enkeltdataene:
  cout << "\n\t" << navn << ", " << adr << "\n\tTlf: " << tlf 
       << "  Startdato: " << startDato << "  Ant.dager: " << antDager << '\n';
}

                              //  Oppgave 2B - Skriver alle data,
void Kunde::skrivEnkelt()  {  //          inkl. TOTALT antall bestilte glass:
  int tot = 0;                           //  Totalt antall bestilte glass.
  skriv();                               //  Skriver enkeltdataene.
  for (int i = 0;  i < MAXGLASS;  i++)   //  Oppsummerer antall glass totalt
      tot +=  glass[i];                  //  bestilt, og skriver dette:
  cout << "\t\tTotalt antall glass bestilt: " << tot << '\n'; 
}

                              //  Oppgave 2C - Skriver alle data, inkl. hvor
void Kunde::skrivOmfattende()  {      //  mange bestilt av de ulike glassene.
  skriv();                               //  Skriver enkeltdataene.
  for (int i = 0;  i < MAXGLASS;  i++)   //  Går gjennom alle glassene:
      if (glass[i] != 0)  {              //  Har bestilt glass nr.i.
         cout << '\t' << glass[i] << " stk av glasset"; //  Skriver antallet.
         glassene[i].skriv();            //  Glasset skriver seg selv.
      }
}


void Kunde::lesData()  {      //  Oppgave 2D - Leser ALLE egne data:
  int mm,dd, ant, nr;         //  Måned, dag, antall ulike klass og glassnr.

  les("Navn   ", navn, STRLEN);                 //  Leser egne data:
  les("Adresse", adr, STRLEN*4);                
  tlf  = les("Telefon", 10000000, 99999999);
  mm   = les("Start mnd", 1, 12);               //  Leser måned 
  dd   = les("Start dag", 1, 31);               //    og dag:
  startDato = mm*100 + dd;                      //  Bygger int med: MMDD   
  antDager = les("Antall arbeidsdager", 1, 50); //  Leser ant.arb.dager. 
  ant = les("Antall ulike glass ", 1, MAXGLASS); //  Leser antall glass:
  for (int i = 0;  i < ant;  i++)  {            //  For hvert glass:
      cout << '\n';
      nr = les("Glass nr", 0, MAXGLASS-1);      //  Leser dets nummer,
      glass[nr] = les("Antall av dette glasset", 0, 100); // og antallet.
  }
}


void Kunde::faktura()  {     //  Oppgave 2E - Skriver faktura/regning/totalsum:
  float kvm, sum, totalSum = 0;  //  Kvadratmtr, sum ETT glassmål, totalsum
  cout << '\n';
  for (int i = 0;  i < MAXGLASS;  i++)   //  Går gjennom alle glassene:
      if (glass[i] != 0)  {              //  Har bestilt aktuelt glass:
         kvm = glassene[i].kvm();        //  Henter glassets mål i kvm.
         sum = glass[i] * kvm * KVMPRIS; //  Total pris på bestilt glass.
         totalSum += sum;                //  Totalsummen for alt. 
         cout << "\tGlass nr." << i << ": " << glass[i] << " stk. a " 
              << setw(6) << kvm <<  " kvm. Sum: " << sum << '\n';
      }
   cout << "\n\tTotalsum: " << totalSum << '\n';
}

                            //  Oppgave 2F - Leser alt om kunden fra fil:
void Kunde::lesFraFil(ifstream & inn, int t)  {       
  tlf = t;                                     //  Lagrer unna telefon.
  inn >> startDato >> antDager;  inn.ignore(); //  Leser 2x:   - int'er.
  inn.getline(navn, STRLEN);    inn.getline(adr, STRLEN*4);//  - tekster.
                                               //  Leser bestilte glass:
  for (int i = 0;  i < MAXGLASS;  i++)  inn >> glass[i];   inn.ignore();
}

                             
int Kunde::hentBestilt(int n)  {  //  Oppgave 2G - Returnerer antall   
   return (glass[n]);             //               bestilte glass av nr.'n'.
}

                                  //  EXTRA - Skriver ALLE data til fil:
void Kunde::skrivTilFil(ofstream & ut)  {
  ut << tlf << "  " << startDato << "  " << antDager << '\n'
     << navn << '\n' << adr << '\n';
  for (int i = 0;  i < MAXGLASS;  i++)   //  Skriver alle glassene:
      ut << ' ' << glass[i];
  ut << '\n';
}



Glass::Glass()  {          //  Initierer/nullstiller ALLE datamedlemmer:
  strcpy(produsent, "");  bredde = hoyde =  0;
}


void Glass::skriv()  {     //  Oppgave 2A - Skriver ALLE data om glasset:
  cout << '\t' << setw(4) << bredde << 'x' 
       << setw(4) << hoyde << "  " << produsent << '\n';
}


float Glass::kvm()  {    //  Oppgave 2E - Retunerer glassets areal i kvm:
  return ( (hoyde/1000.0F) * (bredde/1000.0F));
}


void Glass::lesFraFil(ifstream & inn)  {  // Oppgave 2F - Leser ALLE egne data:
  inn >> bredde >> hoyde;   inn.ignore();
  inn.getline(produsent, STRLEN);
}



// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tG   = skriv alle Glassene\n";
  cout << "\tE   = skriv alle kundene - Enkelt\n";
  cout << "\tO   = skriv alle kundene - Omfattende\n";
  cout << "\tN   = Ny kunde\n";
  cout << "\tF   = Faktura\n";
  cout << "\tS   = Statistikk for/over alle glassene\n";
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


void skrivAlleGlassene()  { // Oppgave 2A - Skriver alle data om alle glassene:
  cout << "\nAlle glass(målene) i systemet:\n";
  for (int i = 0;  i < MAXGLASS;  i++)
      glassene[i].skriv();
}


void skrivKundeEnkelt()  {      //  Oppgave 2B - Skriver hoveddata om EN kunde:
  kundene[les("Enkle data om kunde nr.", 1, sisteKunde)].skrivEnkelt();
}


void skrivKundeOmfattende()  {     //  Oppgave 2C - Skriver ALT om EN kunde:
  kundene[les("Omfattende data om kunde nr.", 1, sisteKunde)].skrivOmfattende();
}


void nyKunde()  {           //  Oppgave 2D - Legger (om mulig) inn en ny kunde:
  if (sisteKunde < MAXKUNDE)  {          //  Plass til flere kunder:
     cout << "Ny kunde legges inn som nr." << ++sisteKunde << ":\n";
     kundene[sisteKunde].lesData();      //  Kunder leser alle data selv.
  } else                                 //  Fullt:
    cout << "\n\tFullt med " << MAXKUNDE << " kunder allerede!\n\n";
}


void faktura()  {           //  Oppgave 2E - Skriver en kundes faktura/regning:
  kundene[les("Faktura/regningen for kunde nr.", 1, sisteKunde)].faktura();
}


void lesFraFil()  {         //  Oppgave 2F - Leser inn HELE datastrukturen:
  int tlf;                                 //  Evt. 1.felt i en ny Kunde-post.
  ifstream innfil1("GLASS.DTA");           //  Åpner 1.fil.
  ifstream innfil2("GLASSKUNDER.DTA");     //  Åpner 2.fil.


  if (innfil1  &&  innfil2)  {             //  Filene finnes:
     cout << "\n\Leser fra filene 'GLASS(KUNDER).DTA' .....\n\n";
     for (int i = 0;  i < MAXGLASS;  i++)  //  Leser ALT inn fra 1.filen:
         glassene[i].lesFraFil(innfil1);
                                           //  Leser ALT inn fra 2.filen:
     sisteKunde = 0;
     innfil2 >> tlf;                       //  Leser (om mulig) 1.felt i post.													
                                           //  Ikke slutt og plass til flere:
     while (!innfil2.eof()  &&  sisteKunde < MAXKUNDE)   {
       kundene[++sisteKunde].lesFraFil(innfil2, tlf); // Leser resten selv.
       innfil2 >> tlf;                     //  Leser (om mulig) 1.felt i post.
     }
  } else                                   //  Filen ble ikke funnet:
    cout << "\n\nMinst en av datafilene finnes ikke!\n\n";
}

                             //  Oppgave 2G - Skriver totalantallet bestilt av
void glasStatistikk()  {     //    hvert glassmål og hvem bestilt mest av:
  int i, j, max = 0, glassNr;      //  Løkkevariable, max.solgt og dets indeks.
  int totAnt;                      //  Totalt antall av aktuelt glassmål.
   
  for (i = 0;  i < MAXGLASS;  i++)  {     //  For hvert glass:
      totAnt = 0;                         //  Nullstiller totalt av glassmålet.
      for (j = 1;  j <= sisteKunde;  j++)      // For hver kunde:
          totAnt += kundene[j].hentBestilt(i); // Henter #bestilt av glass nr.i
      if (totAnt > max)  {                     // Ny maks antall bestilt/solgt?
         max = totAnt;                         // Oppdaterer maks bestilt 
         glassNr = i;                          //   og dets indeks/nr.
      }
      if (totAnt > 0)                          // Om noen bestilt - skriver:
         cout << "\tGlass nr." << i << " - solgt " << totAnt << " stk\n";
  }
  if (max > 0)                        //  Noen solgt i det hele tatt - skriver:
     cout << "\n\tSolgt mest av nr." << glassNr << " (" << max << " stk).\n";
  else                                //  Ingen bestilt i det hele tatt: 
     cout << "\n\tIngen glass solgt!\n";
}


void skrivTilFil()  {    //  Skriver kundene til fil ('glassene' er statiske):
  ofstream utfil("GLASSKUNDER.DT2");        //  Åpner aktuell fil.

  cout << "\n\nSkriver til filen 'GLASSKUNDER.DTA' .....\n\n";
  for (int i = 1;  i <= sisteKunde;  i++)   //  Alle kundene skriver seg selv:
      kundene[i].skrivTilFil(utfil);
}
