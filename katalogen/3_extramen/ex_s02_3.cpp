//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S02_3.CPP

//  Løsningsforslag til eksamen i C++, 9.august 2002, oppgave 3.
//  Laget av Frode Haug, HiG, juli 2002.
//  En god del endret/modifisert av FrodeH, HiG, høsten 2003.


//  Programmet håndterer informasjon om ulike bøker (data om deres tittel
//  og forfatter). Disse dataene leses inn fra to ulike filer.
//  Brukeren kan:
//      - legge til en ny bok og dens forfatter
//      - fjerne/slette en gitt bok/forfatter
//      - få utskrift om alle bøkene eller en gitt bok/forfatter.


                        //  INCLUDE:
#include <iostream>          //  cin, cout
#include <iomanip>           //  setw
#include <fstream>           //  ifstream
#include <cstring>           //  strlen, strcmp, strcpy
#include <cctype>            //  toupper

using namespace std;

                        //  CONST:
const int MAX_BOK   = 200;   //  Max. antall titler i datastrukturen.
const int MAX_FORF  =  50;   //  Max. antall forfattere i datastrukturen.
const int STRLEN    =  40;   //  Max.lengde for en tekststreng.

                        //  KLASSER:
class Bok  {                
  private:                   //  Data om en bok:
    char tittel[STRLEN];     //   - Tittel.
    char ISBN[STRLEN/2];     //   - ISBN-nummer.
    int  forf_nr;            //   - Nummer i arrayen "forfattere".
  
  public:
    void skriv(int n, bool forf);
    void skriv_alt();
    void les_data(int nr);
    void sett(int nr)        {  forf_nr = nr;  }
    bool skrevet_av(int nr)  {  return (forf_nr == nr);  }
    void les_fra_fil(istream* inn, int nr);
};


class Forfatter  {          
  private:                   //  Data om en forfatter:
    char navn[STRLEN];       //   - Navn
    char adr[STRLEN];        //   - Adresse (gate, poststed, land).
    char tlf[STRLEN/2];      //   - Telefon (inkl. evt. landskode).
  
  public:
    void skriv();
    void les_data(char nvn[]);
    void hent(char nvn[])  {  strcpy(nvn, navn);         } // Returnerer navn.
    bool er_lik(char t[])  {  return (!strcmp(navn, t)); } // Sammenligner.
    void les_fra_fil(istream* inn, char nvn[]);
};

                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les();
void les(char t[], char s[], int LEN);
int  les(char t[], int min, int max);
int  finn(char t[]);
void skriv_alle_boker();       //  Oppgave 3a
void skriv_bok();              //  Oppgave 3b
void skriv_alt_av_forfatter(); //  Oppgave 3c
void slett_bok();              //  Oppgave 3d
void slett_forfatter();        //  Oppgave 3f
void ny_bok();                 //  Oppgave 3e
void les_fra_fil();
void skriv_til_fil();


                        //  GLOBALE VARIABLE:
Bok       boker[MAX_BOK+1];       //  Array av Bok-objekter.
Forfatter forfattere[MAX_FORF+1]; //  Array av Forfatter-objekter.
int       siste_bok,         //  Aktuelt antall bøker i datastrukturen.
          siste_forfatter;   //  Aktuelt antall forfattere i datastrukturen.

                            
int main()  {           //  HOVEDPROGRAMMET:
  char valg;

  les_fra_fil();             //  Leser inn hele datastrukturen fra to filer.
  skriv_meny();
  valg = les();
  while (valg != 'Q')  {
    switch(valg)  {
      case 'N':  ny_bok();                  break;   //  Oppgave 3e
      case 'A':  skriv_alle_boker();        break;   //  Oppgave 3a
      case 'B':  skriv_bok();               break;   //  Oppgave 3b
      case 'F':  skriv_alt_av_forfatter();  break;   //  Oppgave 3c
      case 'T':  slett_bok();               break;   //  Oppgave 3d
      case 'S':  slett_forfatter();         break;   //  Oppgave 3f
      default :  skriv_meny();              break;
    }
    valg = les();
  }
  skriv_til_fil();
  cout << "\n\n";
  return 0;

}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:
void Bok::skriv(int n, bool forf)  {   //  Skriver ut alle ens egne data:
  cout << setw(8) << n << ":  \"" << tittel << "\", " << ISBN;
  if (forf) {                          //  Forfatterens navn skal skrives:
     char nvn[STRLEN];
     forfattere[forf_nr].hent(nvn);    //  Henter og
     cout << "\n\t\t" << nvn;          //    skriver også det ut:
  }
  cout << '\n';
}


void Bok::skriv_alt()  {   //  Skriver ALLE relevante data (egne + forfatters):
  cout << "\n\t\"" << tittel << "\", " << ISBN;
  forfattere[forf_nr].skriv();   //  Forfatter skriver selv alt om seg selv.
}


void Bok::les_data(int nr) {
  forf_nr = nr;                         //  Kopierer forfatternummer.
  les("\tTittel", tittel, STRLEN);      //  Leser tittel.
  les("\tISBN",   ISBN, STRLEN/2);      //  Leser ISBN-nummer.
}


void Bok::les_fra_fil(istream* inn, int nr)  {
  forf_nr = nr;                         //  Kopierer forfatternummer.
  *inn >> ISBN;   (*inn).ignore();      //  Leser ISBN. Skipper ETT blankt tegn.
  (*inn).getline(tittel, STRLEN);       //  Leser tittel.
}


void Forfatter::skriv()  {
  cout << "\n\tav "   << navn           //  Skriver ALLE data om en forfatter.
       << "\n\tAdr: " << adr
       << "\n\tTlf: " << tlf << '\n';
}


void Forfatter::les_data(char nvn[])  {
  strcpy(navn, nvn);                    //  Kopierer forfatterens navn.
  les("\tAdresse", adr, STRLEN);        //  Leser adr.
  les("\tTelefon", tlf, STRLEN/2);      //    og tlf:
}

                                 //  Leser "alle" forfatterens data fra fil:
void Forfatter::les_fra_fil(istream* inn, char nvn[])  {
  strcpy(navn, nvn);             //  Kopierer navn.
  (*inn).getline(adr, STRLEN);   //  Leser adr.
  *inn >> tlf;  (*inn).ignore(); //  Leser tlfnr, forkaster '\n' til slutt.
}


                        //  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {         //  Skriver brukerens lovlige valg:
  cout << "\nFølgende kommandoer er lovlige:";
  cout << "\n\tN - Ny bok";
  cout << "\n\tA - skriv data om Alle bøkene";
  cout << "\n\tB - skriv alle data om en Bok";
  cout << "\n\tF - skriv alle data om en Forfatter og alle dens bøker";
  cout << "\n\tT - sletT en bok";
  cout << "\n\tS - Slett (om mulig) en forfatter";
  cout << "\n\tQ - Quit / avslutt";
}


char les()  {                //  Leser, upcaser og returnerer ETT tegn:
  char ch;
  cout << "\n\nKommando:  ";
  cin >> ch;  cin.ignore();  //  Leser og forkaster neste tegn (='\n').
  return (toupper(ch));      //  Upcaser og returnerer.
}


void les(char t[], char s[], int LEN) {  //  Leser inn en ikke-blank tekst:
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, LEN);          //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}


int les(char t[], int min, int max)  {   // Leser et tall i et visst intervall.
  int n;
  do  {                                  // Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;                            // Leser inn ett tall.
  } while(n < min  ||  n > max);         // Sjekker at i lovlig intervall.
  return n;                              // Returnerer innlest tall.
}

                                  //  Ut fra en forfatters navn, så returneres
                                  //    vedkommendes indeks i "forfattere",
int finn(char t[])  {             //    evt. '0' om han/hun ikke finnes.
  for (int i = 1;  i <= siste_forfatter;  i++)
      if (forfattere[i].er_lik(t))  return i;
  return 0;
}

                                   //  OPPGAVE 3A
void skriv_alle_boker()  {         //  Skriver data om ALLE bøkene:
  char ch;
  if (siste_bok > 0)  {                       //  Bøker er registrert:
     cout << "\nData om ALLE bøkene:\n";
     for (int i = 1;  i <= siste_bok;  i++) { //  Går gjennom alle bøkene:
         boker[i].skriv(i, true);             //  Hver av dem skriver seg selv.
         if (i % 10 == 0)  {                  //  Stopper for hver tiende:
            cout << "\n\t\t\t\t\t\tSkriv ETT tegn .....";  cin >> ch;
         }
     }
  } else                                 //  Ingen bøker innlest/registrert:
    cout << "\nIngen bøker registrert. Bruk kommandoen 'N' først.\n";
}


void skriv_bok()  {                //  OPPGAVE 3B
  int nr;                                //  Boknummer.
  if (siste_bok > 0)  {                  //  Bøker er registrert:
     nr = les("Skriv ALLE data om bok nummer",1,siste_bok);// Leser aktuelt nr.
     boker[nr].skriv_alt();
  } else                                 //  Ingen bøker innlest/registrert:
    cout << "\nIngen bøker registrert. Bruk kommandoen 'N' først.\n";
}


void skriv_alt_av_forfatter()  {   //  OPPGAVE 3C
  char nvn[STRLEN];                      //  Forfatternavn.
  int  fnr;                              //  Forfatternummer.
  if (siste_forfatter > 0)  {            //  Forfattere er registrert:
     les("Skriv ALLE bøker av forfatteren", nvn, STRLEN); //  Leser forf.nvn.
     if ((fnr = finn(nvn)) != 0)  {         //  Forfatteren finnes:
        for (int i = 1;  i <= siste_bok;  i++)  //  Går gjennom alle bøkene:
            if (boker[i].skrevet_av(fnr))       //  Bok av forfatteren:
                boker[i].skriv(i, false);       //  Skriver data om boken.
     } else                                 //  Forfatteren finnes IKKE:
       cout << "\nIngen forfatter med dette navnet!\n";
  } else                               //  Ingen forfattere innlest/registrert:
    cout << "\nIngen forfattere registrert. Bruk kommandoen 'N' først.\n";
}


void slett_bok()  {                //  OPPGAVE 3D
  int nr;                                //  Boknummer.
  if (siste_bok > 0)  {                  //  Bøker er registrert:
     nr = les("Slett/fjern bok nummer", 0, siste_bok);  // Leser aktuelt nr.
     if (nr != 0)  {                     //  Ønsker virkelig å slette en bok:
        boker[nr] = boker[siste_bok--];  //  Siste bok flyttes inn i "hullet",
        cout << "\nBoken er slettet!\n"; //    og antallet telles ned.
     } else
		cout << "\nIngen bok ble slettet.\n";  //  Angret ved å velge nr.0.
  } else                                 //  Ingen bøker innlest/registrert:
    cout << "\nTomt for bøker allerede!\n";
}


void ny_bok()  {                   //  OPPGAVE 3E
  int  fnr;                              //  Forfatternummer.
  char nvn[STRLEN];                      //  Forfatternavn.
  if (siste_bok < MAX_BOK  &&  siste_forfatter < MAX_FORF) { // Fortsatt plass:
     cout << "\nREGISTERER NY BOK:\n";
     les("\tForfatter", nvn, STRLEN);    //  Leser forfatter.
     if ((fnr = finn(nvn)) == 0)  {      //  Forfatter er ny:
         forfattere[++siste_forfatter].les_data(nvn); // 'Forfatter' leser selv.
         boker[++siste_bok].les_data(siste_forfatter); // 'Bok' leser selv.
     } else                              //  Forfatteren finnes fra før:
         boker[++siste_bok].les_data(fnr);  //  'Bok' leser selv.
  } else                                 //  Fullt i en eller begge arrayene:
    cout << "\nIkke plass til flere bøker og/eller forfattere!";
}


void slett_forfatter()  {          //  OPPGAVE 3F
  char nvn[STRLEN];                      //  Forfatternavn.
  int  fnr,                              //  Forfatternummer.
       i;                                //  Løkkevariabel.
  bool henviser = false;                 //  Om en bok henviser til forf.nr.

  if (siste_forfatter > 0)  {            //  Forfattere er registrert:
     les("Slett forfatteren", nvn, STRLEN);   //  Leser forf.nvn.
     if ((fnr = finn(nvn)) != 0)  {           //  Forfatteren finnes:
         for (i = 1;  i <= siste_bok;  i++)   //  Går gjennom "alle" bøkene:
             if (boker[i].skrevet_av(fnr))  { //  Bok har denne forfatteren:
                henviser = true;  break;   }  //  Setter 'flagg'. Hopper ut.

        if (!henviser)  {                      //  Ingen bok henviste:
                            //  Flytter siste forfatteren til den ledige plass:
           forfattere[fnr] = forfattere[siste_forfatter--];
           for (i = 1;  i <= siste_bok;  i++)  //  Går gjennom alle bøkene:
                                        //  De som henviste til den bakerste,
               if (boker[i].skrevet_av(siste_forfatter+1))
                   boker[i].sett(fnr);  //    oppdateres til der den nå ligger.
           cout << "\nForfatteren er slettet!\n";
        } else                                 //  Minst en bok henviste:
          cout << "\nBok henviser til denne forfatteren. "
               << "Utfør kommandoen 'T' først.\n";
	 } else                                 //  Forfatteren finnes IKKE:
       cout << "\nIngen forfatter med dette navnet!\n";
  } else                               //  Ingen forfattere innlest/registrert:
    cout << "\nTomt for forfattere allerede!\n";

}

                                       //  Leser inn dataene om bøkene og
void les_fra_fil()  {                  //    forfatterne fra to ulike filer:
  int nr;                              //  Forfatternummer.
  char nvn[STRLEN];                    //  Forfatternavn.
  ifstream innfil1("BOOKS.DTA");       //  Åpner aktuelle fil-objekter:
  ifstream innfil2("AUTHORS.DTA");

  if (innfil1)  {                      //  Den ene filen finnes:
     if (innfil2)  {                   //  Den andre filen finnes:
        siste_bok = siste_forfatter = 0; //  Nullstiller antallene totalt.
                                 //  Leser fra filen 'BOOKS.DTA':
        innfil1 >> nr;                 //  Leser (om mulig) neste forfatternr.
                                       //  Ikke filslutt, og fortsatt plass:
        while (!innfil1.eof()  &&  siste_bok < MAX_BOK)  {
          boker[++siste_bok].les_fra_fil(&innfil1, nr);  //  'Bok' leser selv.
          innfil1 >> nr;               //  Leser (om mulig) neste forfatternr.
        }
                                 //  Leser fra filen 'AUTHORS.DTA':
        innfil2.getline(nvn, STRLEN);    //  Leser (om mulig) neste forf.navn.
                                         //  Ikke filslutt, og fortsatt plass:
        while (!innfil2.eof()  &&  siste_forfatter < MAX_FORF)  {
          forfattere[++siste_forfatter].les_fra_fil(&innfil2, nvn);//Leser selv.
          innfil2.getline(nvn, STRLEN); //  Leser (om mulig) neste forf.navn.
        }
     } else                              //  Den andre filen finnes IKKE:
       cout << "Finner ikke filen 'AUTHORS.DTA'\n";
  } else                                 //  Den ene filen finnes IKKE:
    cout << "Finner ikke filen 'BOOKS.DTA'\n";
}


void skriv_til_fil() {
   //   IKKE IMPLEMENTERT.
}
