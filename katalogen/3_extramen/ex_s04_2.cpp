//  Fil:  FRODEH \ CPP \ EXTRAMEN \ EX_S04_2.CPP

//  Løsningsforslag til kontinuasjonseksamen i C++, 12.august 2004, oppgave 2.
//  Laget av Frode Haug, HiG, juni 2004.


//  Program som holder orden på ulike deltagere og deres †rlige
//  deltagelse p† ett eller annet (korpsstevne, speiderleir) i ten†rene.


                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream
#include <cstring>            //  strcpy
#include <cctype>             //  toupper

using namespace std;

                        //  CONST:
const int MAXDELT  =  200;    //  Max. antall tenårings-deltagere.
const int STRLEN   =   40;    //  Max. lengde på tekststrenger.
const int TENLEN   =    7;    //  Antall år man er tenåring.
const int TENSTART =   13;    //  Første tenåringsår.
const int TENSLUTT =   19;    //  Siste tenåringsår.

                        //  KLASSE:
class Deltager  {             //  Tenåringsdeltager:
  private:
	int  nr;                  //  Nummer/ID.
    char navn[STRLEN];        //  Navn.
    char adr[STRLEN*2];       //  Adresse (gate, postnr, poststed).
    int  fodeaar;             //  Fødeselsår.
	bool deltatt[TENLEN];     //  Hvilke tenår (13-19) man har deltatt.

  public:
    Deltager();               //  Deklarasjon av medlemsfunksjoner:
    bool er_lik(int n);
    void skriv();
    void skriv_alt();
    void ny(int n);
    void les_fra_fil(istream* inn, int n);
	void vaert_med(int aar);
};


                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les_kommando();
int  les_nummer();

void skriv_alle();
int  finn_deltager();
void skriv_deltager();
void ny_deltager();
void slett_deltager();
void les_fra_fil();
void les_deltagelse();


                        //  GLOBALE VARIABLE:
Deltager deltagere[MAXDELT+1];  //  Tenåringsdeltager-objekter.
int siste_brukt;                //  Indeksen for siste brukte deltager.


                        //  HOVEDPROGRAM:
int main()  {
   char kommando;
   
   les_fra_fil();                            //  Oppgave 2F

   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'A':  skriv_alle();     break;   //  Oppgave 2A
       case 'E':  skriv_deltager(); break;   //  Oppgave 2C
       case 'N':  ny_deltager();    break;   //  Oppgave 2D
       case 'S':  slett_deltager(); break;   //  Oppgave 2E
       case 'D':  les_deltagelse(); break;   //  Oppgave 2G
       default:   skriv_meny();     break;
     }
     kommando = les_kommando();
   }
  cout << "\n\n";
  return 0;
}


                        //  DEFINISJON AV KLASSE-FUNKSJONER:
Deltager::Deltager()  {      //  Nullstiller/initierer alle medlemmene:
  nr = fodeaar = 0;
  strcpy(navn, "");  strcpy(adr, "");
  for (int i = 0;  i < TENLEN;  i++)  deltatt[i] = false;
}

                             //  Returnerer true/false til om objektet
bool Deltager::er_lik(int n)  {      //  har et gitt nummer:
  return (nr == n);
}


void Deltager::skriv()  {       //  Skriver alle HOVEDDATA om objektet:
  cout << nr << " (" << fodeaar << "): " << navn << ", " << adr << '\n';
}


void Deltager::skriv_alt()  {   //  Skriver ALLE DATA om objektet:
  skriv();
  for (int i = 0;  i < TENLEN;  i++)
      cout << "  " << i+TENSTART << ": " << (deltatt[i] ? "Ja " : "Nei");
  cout << '\n';
}


void Deltager::ny(int n)  {     //  Leser inn ALLE data til objektet:
  nr = n;                       //  Får inn nummer som parameter.
  cout << "\tNavn:      ";  cin.getline(navn, STRLEN);  // Leser resten:
  cout << "\tAdresse:   ";  cin.getline(adr, STRLEN*2);
  cout << "\tFødselsår: ";  cin >> fodeaar;  cin.ignore();
  for (int i = 0;  i < TENLEN;  i++)  deltatt[i] = false;  // Nullstiller.
}


                            //  Leser alle ALLE om en deltager fra fil:
void Deltager::les_fra_fil(istream* inn, int n)  {
  int tall;
  nr = n;                                  //  Får inn nummer som parameter.
  (*inn).getline(navn, STRLEN);            //  Leser navnet.
  (*inn).getline(adr, STRLEN*2);           //  Leser adressen.
  *inn >> fodeaar;                         //  Leser fødeår.
  for (int i = 0;  i < TENLEN;  i++)  {    //  Leser deltagelse i tenår.
      *inn >> tall;                        //  Leser '0' eller '1'.
      deltatt[i] = (tall) ? true : false;  //  Konverterer til boolsk.
  }
}

                            //  Setter (om mulig) at har deltatt et gitt år:
void Deltager::vaert_med(int aar)  {  //  Får inn aktuelt år som parameter.
  int alder = aar - fodeaar;          //  Finner vedkommendes alder dette året.
  int n = alder - TENSTART;           //  Indeks fra 0 - (TENLEN-1) (???)

  if (alder >= TENSTART  &&  alder <= TENSLUTT)  {  //  Var tenåring det året:
     if (!deltatt[n])  deltatt[n] = true;           //  Ikke deltatt tidligere:
	 else  
		cout << "\n\t" << nr << " (" << navn 
		     << ") har allerede deltatt når var " << alder << " år!\n";
  } else
	cout << "\n\t" << nr << " (" << navn << ") er IKKE tenåring dette året!\n";
}


                        //  DEFINISJON AV FUNKSJONER:
		  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tA = skriv data om Alle deltagerne\n";
  cout << "\tE = skriv ALLE data om EN deltager\n";
  cout << "\tN = Ny deltager\n";
  cout << "\tS = Slett/fjern en deltager\n";
  cout << "\tD = les Deltagelse fra fil\n";
  cout << "\tQ = quit/avslutt\n";
}


char les_kommando()  {       //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi ønske:  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}


int les_nummer()  {          //  Henter et potensielt deltagernummer:
  int nr;
  cout << "\n\tDeltagernummer:  ";   cin >> nr;   cin.ignore();
  return nr;
}


                             //  OPPGAVE 2A:
void skriv_alle()  {              //  Skriver HOVEDDATAENE om ALLE deltagerne:
  for (int i = 1;  i <= siste_brukt;  i++)
      deltagere[i].skriv();
}


                             //  OPPGAVE 2B:    Ut fra deltagerens nummer, 
int finn_deltager(int n)  {       //  så returneres dens indeks i 'deltagere',
  for (int i = 1;  i <= siste_brukt;  i++)   //  evt.'0' om ikke finnes:
      if (deltagere[i].er_lik(n))  return i;
  return 0;
}


                             //  OPPGAVE 2C:
void skriv_deltager()  {          //  Skriver ALLE data om en deltager:
  int nr;                         //  Deltagerens nummer.
  int n;                          //  Deltagerens indeks i 'deltagere'.
  nr = les_nummer();              //  Leser deltagerens nummer.
  if ((n = finn_deltager(nr)) != 0) //  Finner (om mulig) dets indeks.
     deltagere[n].skriv_alt();      //  Skriver ALT om deltageren.
  else 
     cout << "\n\tIngen deltager med dette nummeret!\n";
}


                             //  OPPGAVE 2D:
void ny_deltager()  {             //  Legger inn en ny deltager:
  int nr;                         //  Ny deltagers potensielle nummer.
  if (siste_brukt < MAXDELT)  {   //  Plass til flere deltagere:
     nr = les_nummer();           //  Leser evt. nytt nummer.
     if ((finn_deltager(nr)) == 0)   //  Ingen med dette nummer allerede:
        deltagere[++siste_brukt].ny(nr);  // Tar i bruk nytt objekt.
     else
	    cout << "\n\tEn deltager har allerede dette nummeret!\n";
  } else
    cout << "\n\tIkke plass til flere deltagere!\n";
}


                             //  OPPGAVE 2E:
void slett_deltager()  {       //  Sletter (om mulig) en deltager:
  int nr;                         //  Deltagerens nummer.
  int n;                          //  Deltagerens indeks i 'deltagere'.
  nr = les_nummer();              //  Leser deltagerens nummer.
  if ((n = finn_deltager(nr)) != 0) //  Finner (om mulig) dets indeks.
     deltagere[n] = deltagere[siste_brukt--];  //  Flytter siste inn i "hullet".
  else 
     cout << "\n\tIngen deltager med dette nummeret!\n";
}


                             //  OPPGAVE 2F:
void les_fra_fil()  {       //  Leser hele datastrukturen fra fil:
  ifstream innfil("tenaring.dta");      //  Åpner aktuell fil.
  int n;
  
  if (innfil)  {                        //  Filen finnes:
	  siste_brukt = 0;                  //  Nullstiller ant.objekter brukt.
	  innfil >> n;                      //  Henter (om mulig) 1.nummer/tall.
      while (!innfil.eof()  &&  siste_brukt < MAXDELT)  { // Ny post, nok plass:
		innfil.ignore();                //  Hopper over '\n'.
        deltagere[++siste_brukt].les_fra_fil(&innfil, n);
        innfil >> n;                    //  Henter (om mulig) neste nummer/talll.
      }
  } else
    cout << "\n\tFinner ikke filen 'TENARING.DTA'!\n";
}


                             //  OPPGAVE 2G:
                             //  Leser hvem (nummer) som har deltatt på 
void les_deltagelse()  {     //    arrangementet et gitt år:
  int nr;                           //  Deltagerens nummer.
  int n;                            //  Deltagerens indeks i 'deltagere'.
  int aar;                          //  Årstall deltagelsen gjelder for.
  ifstream innfil("deltager.dta");  //  Åpner aktuell fil.
  
  if (innfil)  {                    //  Filen finnes:
     innfil >> aar >> nr;           //  Leser aktuelt år og første nummer.
     while (!innfil.eof())  {
       if ((n = finn_deltager(nr)) != 0) //  Finner (om mulig) dets indeks.
          deltagere[n].vaert_med(aar);   //  Registrerer deltagelse.
	   else
          cout << "\n\tIngen deltager med nummer " << nr << "!\n";
  	   innfil >> nr;                //  Leser (om mulig) neste nummer.
	 }
  } else
    cout << "\n\tFinner ikke filen 'DELTAGER.DTA'!\n";
}
