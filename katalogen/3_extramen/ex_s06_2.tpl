//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_S06_2.TPL

//  Skjellettet/template for eksamen i C++, 9.august 2006, oppgave 2.
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
  skriv_til_fil();                                  //  Oppgave 2f
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


void Person::les_data()  {   //  Leser navn og "nullstiller":
        //  Oppgave 2A:  Lag innmaten
}


void Person::skriv_alt()  {  //  Skriver alt om en person:
        //  Oppgave 2B:  Lag innmaten
}


void Person::skriv_navn()  { //  Skriver KUN personens navn:
        //  Oppgave 2C:  Lag innmaten
}


void Person::ny()  {         //  Leser ny(e) aktivitet(er):
        //  Oppgave 2D:  Lag innmaten
}


void Person::fjern()  {      //  Fjerner en/flere aktivitet(er):
        //  Oppgave 2E:  Lag innmaten
}


void Person::skriv_til_fil(ostream* ut)  {    //  Skriv til fil:
        //  Oppgave 2F:  Lag innmaten
}


void Person::les_fra_fil(istream* inn)  {     //  Les fra fil:
        //  Oppgave 2G:  Lag innmaten
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


void ny_person()  {          //  Ny person i kartoteket:
        //  Oppgave 2A:  Lag innmaten
}


void skriv_person()  {       //  Skriv alt om en gitt person:
        //  Oppgave 2B:  Lag innmaten
}


void skriv_alle_personer()  {  //  Skriver ALLE personenes navn:
        //  Oppgave 2C:  Lag innmaten
}


void ny_aktivitet()  {       //  Legger inn ny(e) aktivitet(er):
        //  Oppgave 2D:  Lag innmaten
}


void fjern_aktivitet()  {    //  Fjerner aktivitet(er):
        //  Innmaten "identisk" til oppgave 2B og 2D
}


void skriv_til_fil()  {      //  Skriver datastrukturen til fil:
        //  Oppgave 2F:  Lag innmaten
}


void les_fra_fil()  {        //  Leser datastrukturen fra fil:
        //  Oppgave 2G:  Lag innmaten
}
