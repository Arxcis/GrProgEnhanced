//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S08_2.CPP

//  Lõsningsforslag til kontinuasjonseksamen i C++, 12.august 2008, oppgave 2.
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
    void skriv_til_fil(ostream* ut);                //  EXTRA
    void les_fra_fil(char t[], istream* inn);       //  EXTRA
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
Person::Person()  {                         //  Initierer alle datamedlemmer:
  strcpy(navn, "");  strcpy(adr, "");  strcpy(mail, "");  strcpy(klasse, "");
  tlf = lagnr = 0;  verv = ingen;
}

void Person::skriv()  {         //  OPPGAVE 2A - Skriver ALLE personens data:
  skriv2();                                 //  Skriver ALLE hoveddata,
  lag[lagnr].skriv();                       //    OG data om laget.
}

void Person::skriv2()  {        //  OPPGAVE 2C - Skriver personens data:
  cout << '\t' << navn << ", " << mail << ", " << tlf << '\n'
       << '\t' << adr << "\n\t" << ((verv == trener)? "Trener" : "Oppmann")
       << " for " << klasse << " i klubben/laget.\n";
}

                        //  Oppgave 2E - Registrerer/leser ALLE personens data:
void Person::les_data(int lnr)  {
  lagnr = lnr;                             //  Kopierer over lagnummeret.
  les("Navn       ", navn,   STRLEN);      //  Leser inn de andre dataene.
  les("Adresse    ", adr,    STRLEN*2);      //    Bruker "mange" les-funksjoner:
  les("Mail       ", mail,   STRLEN);
  les("Klasse     ", klasse, STRLEN);
  tlf = les("Telefon    ", 10000000, 99999999);
  verv = les();
}

                          //  OPPGAVE 2F - Skriver ALLE personens data til fil:
void Person::skriv_til_fil(ostream* ut)  {
  *ut << navn << '\n' << adr << '\n' << mail << '\n' << klasse << '\n'
      << tlf << '\n' << lagnr << '\n' << ((verv==trener)? "T" : "O") << '\n';
}

                             //  OPPGAVE 2G - Leser ALLE personens data fra fil:
void Person::les_fra_fil(char t[], istream* inn)  {
  char ch;
  strcpy(navn, t);                         //  Kopierer over navnet.
  (*inn).getline(adr, STRLEN*2);           //  Leser inn alle andre data:
  (*inn).getline(mail, STRLEN);
  (*inn).getline(klasse, STRLEN);
  *inn >> tlf >> lagnr >> ch;  (*inn).ignore();
  verv = (ch == 'T')?  trener : oppmann;   //  Konverterer 'T' eller 'O'.
}

// ----------------------------------------------------------------------------

Lag::Lag()  {                               //  Initierer alle datamedlemmer:
  strcpy(navn, ""); strcpy(adr, ""); strcpy(mail, ""); strcpy(hjemmeside, "");
}


void Lag::skriv()  {       //  OPPGAVE 2A - Skriver alle lagets data:
  cout << '\t' << navn << ",  " << mail << ", " << hjemmeside 
       << "\n\t" << adr << "\n\n";
}

                         //  Oppgave 2D - Registrerer/leser ALLE lagets data:
void Lag::les_data(char t[])  { 
  strcpy(navn, t);                         //  Kopierer over navnet.
  les("Adresse    ", adr,  STRLEN*2);      //  Leser inn de andre dataene.
  les("Mail       ", mail, STRLEN);        //    Bruker "mange" les-funksjoner:
  les("Hjemmeside ", adr,  STRLEN);
}

                             //  EXTRA - Skriver ALLE lagets data til fil:
void Lag::skriv_til_fil(ostream* ut)  {
  *ut << navn << '\n' << adr << '\n' << mail << '\n' << hjemmeside << '\n';
}

                             //  EXTRA - Leser ALLE lagets data fra fil:
void Lag::les_fra_fil(char t[], istream* inn)  {
  strcpy(navn, t);                         //  Kopierer over navnet.
  (*inn).getline(adr, STRLEN*2);           //  Leser inn alle andre data:
  (*inn).getline(mail, STRLEN);
  (*inn).getline(hjemmeside, STRLEN);
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


void skriv_person()  {       //  OPPGAVE 2A - Skriver ALLE data om EN person:
  int nr;                                            //  Aktuell person indeks.
  char navn[STRLEN];                                 //  Aktuell person navn.
  les("Skriv ALLE data om person", navn, STRLEN);    //  Leser navn.
  if ((nr = finn_person(navn)) != 0)                 //  Personen finnes:
     personer[nr].skriv();                           //  Skriver ALT om den.
  else                                               //  Finnes ikke:
     cout << "\n\tIngen person med dette navnet!\n\n";
}


void skriv_verv()  {         //  OPPGAVE 2B - Skriver ALLE med et gitt verv:
  funksjon v = les();                         //  Variabel med verv/funksjon.
  int i;                                      //  Lõkkevariabel

  cout << "\nFÿLGENDE ER " << ((v==trener)? "TRENERE" : "OPPMENN") << ":\n";
  for (i = 1;  i <= siste_person;  i++)       //  Person med aktuelt verv:
      if (personer[i].har_verv(v))  {  personer[i].skriv();  cout << '\n';  }
}

                             //  OPPGAVE 2C - Skriver ALT om et gitt lag,
void skriv_lag()  {          //          inkludert alle dets trenere/oppmenn:
  int nr,                                      //  Aktuelt lags indeks.
      i;                                       //  Lõkkevariabel.
  char navn[STRLEN];                           //  Aktuelt lags navn.
  les("Skriv data om laget", navn, STRLEN);    //  Leser navn.

  if ((nr = finn_lag(navn)) != 0)  {           //  Laget finnes:
     lag[nr].skriv();                          //  Skriver data om laget.
     cout << "\n\tHar trenerne/oppmennene:\n";
     for (i = 1;  i <= siste_person;  i++)     //  GÜr gjennom ALLE personene:
         if (personer[i].tilhorer_lag(nr))  {  //  For de som tilhõrer laget,
            personer[i].skriv2();              //  skrives ALLE personens data.
            cout << '\n';
         }
  } else
    cout << "\n\tIngen lag med dette navnet.\n\n";
}


void nytt_lag()  {           //  OPPGAVE 2D - Legger inn et nytt UNIKT lag:
  char navn[STRLEN];                           //  Nytt lags navn.

  if (siste_lag < MAXLAG)  {                   //  Plass til flere lag:
     les("Nytt lags navn", navn, STRLEN);      //  Leser nytt lags navn.
     if (finn_lag(navn) == 0)                  //  Laget er nytt:
        lag[++siste_lag].les_data(navn);       //  Nytt lag leser data selv.
     else                                      //  Laget finnes allerede:
       cout << "\n\tDet finnes allerede et lag med dette navnet.\n\n";
  } else                                       //  Lag-kartoteket er fullt:
    cout << "\n\tFullt med " << MAXLAG << " lag allerede!\n\n";
}


void ny_person()  {          //  OPPGAVE 2E - Legger inn en ny person:
  int  nr;                                     //  Aktuelt lags indeks.
  char lnvn[STRLEN];                           //  Eksisterende lags navn.

  if (siste_person < MAXPERSONER)  {           //  Plass til flere personer:
     les("Lagets navn", lnvn, STRLEN);         //  Leser eksisterende lagnavn.
     if ((nr = finn_lag(lnvn)) != 0)           //  Laget finnes:
        personer[++siste_person].les_data(nr); //  Ny person leser data selv.
     else                                      //  Laget finnes IKKE:
       cout << "\n\tIngen lag med dette navnet. Bruk kommandoen 'L' fõrst.\n\n";
  } else                                       //  Person-kartoteket er fullt:
    cout << "\n\tFullt med " << MAXPERSONER << " personer allerede!\n\n";
}


void skriv_til_fil()  {   //  OPPGAVE 2F - Skriver HELE datastrukturen til fil:
  int i;
  ofstream utfil("PERSON.DTA");          //  èpner aktuell fil.

  for (i = 1;  i <= siste_person;  i++)  //  GÜr gjennom ALLE personene:
      personer[i].skriv_til_fil(&utfil); //  De skriver seg selv til fil.

//  EXTRA (resten av funksjonen):
  ofstream utfil2("LAG.DTA");            //  èpner annen aktuell fil.
  for (i = 1;  i <= siste_lag;  i++)     //  GÜr gjennom ALLE lagene:
      lag[i].skriv_til_fil(&utfil2);     //  De skriver seg selv til fil.
}


void les_fra_fil()  {     //  OPPGAVE 2G - Leser HELE datastrukturen fra fil:
  char buffer[STRLEN];                     //  Fõrste tekst i en Person-post.
  ifstream innfil("PERSON.DTA");           //  èpner aktuell fil.

  siste_person = siste_lag = 0;            //  Nullstiller globale variable.

  if (innfil)  {                           //  Filen finnes:
     innfil.getline(buffer, STRLEN);       //  Leser (om mulig) personnavn.
     while (!innfil.eof() &&  siste_person < MAXPERSONER)  {  // Mer, og plass:
       personer[++siste_person].les_fra_fil(buffer, &innfil); // Leser selv.
       innfil.getline(buffer, STRLEN);     //  Leser (om mulig) personnavn.
     }
  } else
    cout << "\nFant ikke filen 'PERSON.DTA'!\n\n";

//  EXTRA (resten av funksjonen):
  ifstream innfil2("LAG.DTA");              //  èpner annen aktuell fil.
  if (innfil2)  {                           //  Filen finnes:
     innfil2.getline(buffer, STRLEN);       //  Leser (om mulig) personnavn.
     while (!innfil2.eof() &&  siste_lag < MAXLAG)  {   // Mer,og plass:
       lag[++siste_lag].les_fra_fil(buffer, &innfil2);  // Leser resten selv.
       innfil2.getline(buffer, STRLEN);     //  Leser (om mulig) personnavn.
     }
  } else
    cout << "\nFant ikke filen 'LAG.DTA'!\n\n";
}
