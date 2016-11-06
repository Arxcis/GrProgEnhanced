//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H03_2.CPP

//  Løsningsforslag til eksamen i C++, 15.desember 2003, oppgave 2.
//  Laget av Frode Haug, HiG, desember 2003.


//  Program som holder orden på ulike enheter (lag/foreninger/klubber/.....)
//  og navnet på denne enhetens medlemmer/deltagere/spillere/.....



                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream
#include <cstring>            //  strcmp, strcpy, strlen
#include <cctype>             //  toupper

using namespace std;

                        //  CONST:
const int MAXENHET =   30;    //  Max. antall enheter i datastrukturen.
const int MAXPERS  =  100;    //  Max. antall personer i enheten.
const int STRLEN   =   40;    //  Max. lengde på tekststrenger.


                        //  KLASSE:
class Enhet  {                //  Enhet:
  private:
    char navn[STRLEN];        //  Navn.
    char adr[STRLEN*2];       //  Adresse (gate, postnr, poststed).
    char email[STRLEN];       //  Email-adresse
    int  tlf;                 //  Telefonnummer.
    int  ant;                 //  Antall medlemmer/deltagere/spillere/.....
    char delt_navn[MAXPERS][STRLEN];   //  2-dimensjonal char-array med navnet
                                       //     til/på enhetens deltagere.
  public:
    Enhet();                  //  Deklarasjon av medlemsfunksjoner:
    bool er_lik(char t[]);
    void skriv();
    void skriv_alt();
    void ny();
    void finn(char t[]);
    void slett();
    void les_fra_fil(istream* inn, char buf[]);
};


                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les_kommando();
void les_tekst(char t[], char s[], int LEN);

void skriv_alle();
int  finn_enhet();
void skriv_enhet();
void ny_deltager();
void finn_deltager();
void slett_deltager();
void les_fra_fil();


                        //  GLOBALE VARIABLE:
int siste_enhet;               //  Indeksen for siste brukte enhet.
Enhet enheter[MAXENHET+1];     //  Array med enhet-objekter.


                        //  HOVEDPROGRAM:
int main()  {
   char kommando;
   
   les_fra_fil();                            //  Oppgave 2g

   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'A':  skriv_alle();     break;   //  Oppgave 2a
       case 'E':  skriv_enhet();    break;   //  Oppgave 2c
       case 'N':  ny_deltager();    break;   //  Oppgave 2d
       case 'F':  finn_deltager();  break;   //  Oppgave 2e
       case 'S':  slett_deltager(); break;   //  Oppgave 2f
       default:   skriv_meny();     break;
     }
     kommando = les_kommando();
   }
  cout << "\n\n";
  return 0;
}


                        //  DEFINISJON AV KLASSE-FUNKSJONER:
Enhet :: Enhet()  {          //  Nullstiller/initierer alle medlemmene:
  ant = tlf = 0;
  strcpy(navn, "");  strcpy(adr, "");  strcpy(email, "");
}

                             //  Returnerer true/false til om objektet
bool Enhet :: er_lik(char t[])  {    //  har et gitt navn:
  return (!strcmp(navn, t));
}


void Enhet :: skriv()  {     //  Skriver alle HOVEDDATA om objektet:
  cout << '\n' << navn << ",  " << adr << "\n\t" << email 
       << ",  tlf: " << tlf  << "  #deltagere: " << ant << '\n';
}


void Enhet :: skriv_alt()  { //  Skriver ALLE DATA om objektet:
  skriv();
  for (int i = 1;  i <= ant;  i++)
      cout << '\t' << i << ":  " << delt_navn[i] << '\n';
}


void Enhet :: ny()  {        //  Legger inn (om plass) navnet til/for en ny
  if (ant < MAXPERS-1)       //    deltager i enheten:
     les_tekst("Ny deltagers navn", delt_navn[++ant], STRLEN);
  else
     cout << "\n\tIkke plass til flere deltagere i enheten!\n";
}

                             //  Leter etter en gitt deltager i enheten:
void Enhet :: finn(char t[])  {     //  Ved funn:  Skriver objektets HOVEDDATA
  for (int i = 1;  i <= ant;  i++)  //             og avslutter løkka:
      if (!strcmp(delt_navn[i], t))  {  skriv();  break;  }
}


void Enhet :: slett()  {    //  Sletter (om mulig) en deltager i enheten:
  int nr;
  for (int i = 1;  i <= ant;  i++)
      cout << '\t' << i << ":  " << delt_navn[i] << '\n';  //  Skriver alle.
  cout << "\n\tSlett nr: ";  cin >> nr;   cin.ignore();    //  Leser nummer.
  if (nr >= 1  &&  nr <= ant)                    //  Lovlig indeks:
     strcpy(delt_navn[nr], delt_navn[ant--]);   //  Sletter/fjerner deltager.
  else
     cout << "\n\tDeltagernummer utenfor gyldig intervall!\n";
}

                            //  Leser alle data om en enhet fra fil:
void Enhet :: les_fra_fil(istream* inn, char buf[])  {
  strcpy(navn, buf);                        //  Får inn navn som parameter.
  (*inn).getline(adr, STRLEN*2);            //  Leser adressen.
  (*inn).getline(email, STRLEN);            //  Leser email-adressen.
  *inn >> tlf >> ant;  (*inn).ignore();     //  Leser telefon og ant.deltagere.
  for (int i = 1;  i <= ant;  i++)          //  Leser deltagernes navn:
     (*inn).getline(delt_navn[i], STRLEN);
}



                        //  DEFINISJON AV FUNKSJONER:
		  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tA = skriv data om Alle enhetene\n";
  cout << "\tE = skriv ALLE data om EN Enhet\n";
  cout << "\tN = Ny deltager i en enhet\n";
  cout << "\tF = Finn en deltager\n";
  cout << "\tS = Slett/fjern en deltager\n";
  cout << "\tQ = quit/avslutt\n";
}


char les_kommando()  {       //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi ønske:  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}


void les_tekst(char t[], char s[], int LEN) {  //  Leser inn ikke-blank tekst:
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, LEN);          //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}


                             //  OPPGAVE 2A:
void skriv_alle()  {              //  Skriver HOVEDDATAENE om ALLE enhetene:
  for (int i = 1;  i <= siste_enhet;  i++)
      enheter[i].skriv();
}


                             //  OPPGAVE 2B:    Ut fra enhetens navn, så returneres dens
int finn_enhet(char t[])  {     //  indeks i "enheter", evt.'0' om ikke finnes:
  for (int i = 1;  i <= siste_enhet;  i++)
      if (enheter[i].er_lik(t))  return i;
  return 0;
}


                             //  OPPGAVE 2C:
void skriv_enhet()  {             //  Skriver ALLE data om en enhet:
  char nvn[STRLEN];               //  Enhetens navn.
  int  nr;                        //  Enhetens indeks i "enheter"-arrayen.
  les_tekst("Skriv enheten", nvn, STRLEN);  //  Leser enhetens navn.
  if ((nr = finn_enhet(nvn)) != 0) //  Finner (om mulig) dets indeks.
     enheter[nr].skriv_alt();      //  Skriver ALT om enheten.
  else 
     cout << "\n\tIngen enhet med dette navnet!\n";
}


                             //  OPPGAVE 2D:
void ny_deltager()  {             //  Legger inn en ny deltager i en enhet:
  char nvn[STRLEN];               //  Enhetens navn.
  int  nr;                        //  Enhetens indeks i "enheter"-arrayen.
  les_tekst("Ny deltager i enheten", nvn, STRLEN);  //  Leser enhetens navn.
  if ((nr = finn_enhet(nvn)) != 0)  //  Finner (om mulig) dets indeks.
     enheter[nr].ny();              //  Legger inn ny deltager.
  else 
    cout << "\n\tIngen enhet med dette navnet!\n";
}


                             //  OPPGAVE 2E:
void finn_deltager()  {           //  Skriver ALLE enheter i deltager er med i:
  char nvn[STRLEN];               //  Deltagerens navn.
  les_tekst("Finn deltager", nvn, STRLEN);   //  Leser deltagers navn.
  cout << "\n\t" << nvn << " er deltager i enheten(e):\n";
  for (int i = 1;  i <= siste_enhet;  i++)  // Går gjennom ALLE enhetene og evt.
      enheter[i].finn(nvn);    //  skriver data om dem der hun/han er deltager.
}


                             //  OPPGAVE 2F:
void slett_deltager()  {       //  Sletter (om mulig) en deltager:
  char nvn[STRLEN];            //  Enhetens navn.
  int  nr;                     //  Enhetens indeks i "enheter"-arrayen.
  les_tekst("Slett deltager i enheten", nvn, STRLEN);  //  Leser enhetens navn.
  if ((nr = finn_enhet(nvn)) != 0)   //  Finner (om mulig) dets indeks.
     enheter[nr].slett();            //  Sletter evt. en av dets deltagere.
  else 
     cout << "\n\tIngen enhet med dette navnet!\n";
}


                             //  OPPGAVE 2G:
void les_fra_fil()  {       //  Leser hele datastrukturen fra fil:
  char buffer[STRLEN*2];                //  Hjelpetekst (buffer).
  ifstream innfil("enhet.dta");         //  Åpner aktuell fil.
  if (innfil)  {                        //  Filen finnes:
      siste_enhet = 0;                  //  Nullstiller ant.objekter brukt.
      innfil.getline(buffer, STRLEN);   //  Henter (om mulig) 1.linje.
      while (!innfil.eof()  &&  siste_enhet < MAXENHET)  { // Ny post, nok plass:
        enheter[++siste_enhet].les_fra_fil(&innfil, buffer);
        innfil.getline(buffer, STRLEN);      //  Henter (om mulig) neste linje.
      }
  } else
    cout << "\n\tFinner ikke filen 'ENHET.DTA'!";
}
