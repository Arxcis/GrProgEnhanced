//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_S06_2.CPP

//  Løsningsforslag til eksamen i C++, 9.august 2006, oppgave 2.
//  Laget av Frode Haug, HiG, mai 2006.


//  Program som holder orden på ulike personers aktiviteter/gjøremål
//     de ulike dagene i løpet av en uke.


                        //  INCLUDE:
#include <iostream>          //  cin, cout
#include <fstream>           //  ifstream, fstream
#include <cctype>            //  toupper
#include <cstring>           //  strcpy, strcmp

using namespace std;

                        //  CONST:
const int ANT_DAGER  =  7;   //  Antall ukedager.
const int STRLEN     = 30;   //  Max. tekstlengde.
const int MAXPERS    = 50;   //  Max. antall personer i kartoteket.


                        //  KLASSER:
class Person  {              //  Personen og dens daglige aktiviteter:
  private:
    char navn[STRLEN];       //  Navn.
    char ukedag[ANT_DAGER+1][STRLEN];  //  Aktivitetene de ulike ukedagene.
    int  les_dagnr();        //  Privat hjelpefunksjon.

  public: 
                 //  Returnerer true/false til om personen har 'navn' lik 't':
    bool er_lik(char nvn[])  { return (!strcmp(navn, nvn)); }
    void les_data();         //  Deklarasjon av medlemsfunksjoner:
    void skriv_alt();
    void skriv_navn();
    void ny();
    void fjern();
    void skriv_til_fil(ostream* ut);
    void les_fra_fil(istream* inn);
};

                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les_kommando();
int finn_person(char t[]);
void ny_person();
void skriv_person();
void skriv_alle_personer();
void ny_aktivitet();
void fjern_aktivitet();
void skriv_til_fil();
void les_fra_fil();


                        //  GLOBALE VARIABLE:
Person personer[MAXPERS+1];  //  Array med Person-objekter.
int siste_brukt;             //  Siste brukte objekt hittil (nr.1 --> )

                        
int main()  {           //  HOVEDPROGRAM:
   char kommando;
   
   les_fra_fil();                                   //  Oppgave 2g

   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'P':  ny_person();             break;   //  Oppgave 2a
       case 'S':  skriv_person();          break;   //  Oppgave 2b
       case 'A':  skriv_alle_personer();   break;   //  Oppgave 2c
       case 'N':  ny_aktivitet();          break;   //  Oppgave 2d
       case 'F':  fjern_aktivitet();       break;   //  Oppgave 2e
       default:   skriv_meny();            break;
     }
     kommando = les_kommando();
   }
//  skriv_til_fil();                                  //  Oppgave 2f
  cout << "\n\n";
  return 0;
}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:

int Person::les_dagnr()  {   //  Leser og returnerer et tall i intervallet 0-7:
  int nr;
  do  {
    cout << "\n\tDagnr (0=avslutt, 1=søndag, ...., 7=lørdag): ";
    cin >> nr;  cin.ignore();
  } while (nr < 0  ||  nr > ANT_DAGER);
  return nr;
}


void Person::les_data()  {   //  OPPGAVE 2A  -  Leser navn og "nullstiller":
  cout << "\tNavn: ";  cin.getline(navn, STRLEN);
  for (int i = 1;  i <= ANT_DAGER;  i++)
      strcpy(ukedag[i], "-----");
  ny();                      //  Leser evt. ønskede initielle aktiviteter.
}


void Person::skriv_alt()  {  //  OPPGAVE 2B -  Skriver alt om en person:
  for (int i = 1;  i <= ANT_DAGER;  i++)  {    //  For alle ukedagene:
      cout << "\t\t";
      switch (i)  {
        case 1: cout << " Søn";   break;       //  Skriver ukedagens navn:
        case 2: cout << " Man";   break;
        case 3: cout << "Tirs";   break;
        case 4: cout << " Ons";   break;
        case 5: cout << "Tors";   break;
        case 6: cout << " Fre";   break;
        case 7: cout << " Lør";   break;
      }                       //  Skriver aktivitet eller "tomt" (-----):
      cout << "dag : " << ukedag[i]  << '\n';
  }
}


void Person::skriv_navn()  { //  OPPGAVE 2C -  Skriver KUN personens navn:
  cout << "\tNavn: " << navn << '\n';
}


void Person::ny()  {         //  OPPGAVE 2D  -  Leser ny(e) aktivitet(er):
  int nr;
  nr = les_dagnr();          //  Ber om et ukedagnr evt. 0
  while (nr != 0)  {         //     for å avslutte.
    cout << "\tNy aktivitet dag nr." << nr << ": ";
    cin.getline(ukedag[nr], STRLEN);  //  Leser inn ny aktivitet.
    nr = les_dagnr();        //  Ber igjen om et ukedagnr evt. 0.
  }
}


void Person::fjern()  {      //  OPPGAVE 2E  -  Fjerner en/flere aktivitet(er):
  int nr;
  nr = les_dagnr();          //  Ber om et ukedagnr evt. 0
  while (nr != 0)  {         //     for å avslutte.
    cout << "\t\tAktiviteten '" << ukedag[nr] << "' er fjernet!\n";
    strcpy(ukedag[nr], "-----");  //  Nullstiller dagen/aktiviteten.
    nr = les_dagnr();        //  Ber igjen om et ukedagnr evt. 0.
  }
}


void Person::skriv_til_fil(ostream* ut)  {    //  OPPGAVE 2F  -  Skriv til fil:
  *ut << navn << '\n';                        //  Skriver navnet og alle
  for (int i = 1;  i <= ANT_DAGER;  i++)      //    aktivitetene for personen.
      *ut << ukedag[i] << '\n';
}


void Person::les_fra_fil(istream* inn)  {  //  OPPGAVE 2G  -  Les fra fil:
  (*inn).getline(navn, STRLEN);            //  Leser navnet og alle  
  for (int i = 1;  i <= ANT_DAGER;  i++)   //    aktivitetene for personen.
      (*inn).getline(ukedag[i], STRLEN);   
}


                        //  DEFINISJON AV FUNKSJONER:
	  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tP = ny Person\n";
  cout << "\tS = Skriv person\n";
  cout << "\tA = skriv Alle personer\n";
  cout << "\tN = Ny aktivitet\n";
  cout << "\tF = Fjern aktivitet\n";
  cout << "\tQ = quit/avslutt\n";
}


char les_kommando()  {       //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi ønske:  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}


int finn_person(char t[])  {   //  Returnerer (om mulig) indeksen for personen
  for (int i = 1;  i <= siste_brukt;  i++)   //  med navn lik 't':
      if (personer[i].er_lik(t)) return i;
  return 0;
}


void ny_person()  {          //  OPPGAVE 2A - Ny person i kartoteket:
  if (siste_brukt < MAXPERS)                //  Plass til flere:
     personer[++siste_brukt].les_data();    //  Ny tas i bruk, dataene leses.
  else
    cout << "\n\tKartoteket er fullt med " << MAXPERS << " personer!\n\n";
}


void skriv_person()  {       //  OPPGAVE 2B - Skriv alt om en gitt person:
  char nvn[STRLEN];
  int nr;                    //  Leser aktuell persons navn:
  cout << "\tSkriv alt om navnet: ";  cin.getline(nvn, STRLEN);
  if ((nr = finn_person(nvn)) != 0)    //  Personen finnes:
      personer[nr].skriv_alt();        //  Skriver ALT om vedkommende.
  else
    cout << "\n\tIngen person med dette navnet!\n\n";
}


void skriv_alle_personer()  {   //  OPPGAVE 2C - Skriver ALLE personenes navn:
  cout << "\n\tALLE PERSONENE I KARTOTEKET:\n";
  for (int i = 1;  i <= siste_brukt;  i++)
      personer[i].skriv_navn();
}


void ny_aktivitet()  {       //  OPPGAVE 2D - Legger inn ny(e) aktivitet(er):
  char nvn[STRLEN];
  int nr;                    //  Leser aktuell persons navn:
  cout << "\tNy aktivitet hos navnet: ";  cin.getline(nvn, STRLEN);
  if ((nr = finn_person(nvn)) != 0)    //  Personen finnes:
      personer[nr].ny();               //  Ny(e) aktivitet(er) registreres.
  else
    cout << "\n\tIngen person med dette navnet!\n\n";
}


void fjern_aktivitet()  {    //  (OPPGAVE 2E - Fjerner aktivitet(er):)
  char nvn[STRLEN];
  int nr;                    //  Leser aktuell persons navn:
  cout << "\tFjern aktivitet hos navnet: ";  cin.getline(nvn, STRLEN);
  if ((nr = finn_person(nvn)) != 0)    //  Personen finnes:
      personer[nr].fjern();            //  Aktivitet(er) fjernes.
  else
    cout << "\n\tIngen person med dette navnet!\n\n";
}


void skriv_til_fil()  {      //  OPPGAVE 2F - Skriver datastrukturen til fil:
  ofstream utfil("aktivitet.dta");
  utfil << siste_brukt << '\n';              //  Skriver antall personer totalt. 
  for (int i = 1;  i <= siste_brukt;  i++)   //  ALLE personene skrives til fil:
      personer[i].skriv_til_fil(&utfil);
}


void les_fra_fil()  {        //  OPPGAVE 2G - Leser datastrukturen fra fil:
  ifstream innfil("aktivitet.dta");
  int i;

  if (innfil)  {                        //  Filen var mulig å åpne:
     innfil >> siste_brukt;  innfil.ignore();   //  Leser antall personer.
     for (i = 1;  i <= siste_brukt;  i++)       //  For hver person:
         personer[i].les_fra_fil(&innfil);      //  Leser ALLE dens data.
  } else                                //  Filen lot seg ikke åpne:
    cout << "\n\nFant ikke filen 'AKTIVITET.DTA'!\n\n";
}
