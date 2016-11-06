//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H01_3.CPP

//  L›sningsforslag til eksamen i C++, 5.desember 2001, oppgave 3.
//  Laget av Frode Haug, HiG, november 2001.


//  Programmet h†ndterer informasjon om ulike CD'er:
//       Utgivelses†r, artistnavn, tittel og sangtitler.
//  Disse dataene leses inn fra fil. 
//  Brukeren kan s† legge inn data om nye CD'er. 
//  Hun/han kan ogs† f† skrevet ut ulike oversikter over CD'enes data.


                             //  INCLUDE:
#include <iostream>          //  cin, cout
#include <fstream>           //  ifstream, ofstream
#include <cstring>           //  strlen, strcmp
#include <cctype>            //  toupper
#include <iomanip>           //  setw

using namespace std;
                             //  CONST:
const int MAX_CDER   = 500;  //  Max. antall CD'er i "kartoteket".
const int NVNLEN     =  30;  //  Max.lengde for en tekststreng.
const int MAX_SANGER =  20;  //  Max. sang(titler) p† en CD.

                             //  STRUCT:
struct CD  {                 //  Data om en CD:
  int  utgivelsesaar;        //    - Utgivelses†r.
  char navn[NVNLEN];         //    - Artistnavn.
  char tittel[NVNLEN];       //    - Tittel.
  int  ant_sanger;           //    - Antall sanger.
  char sangtittel[MAX_SANGER][NVNLEN];  //  - Tittel for sang nr.i.
};

                             //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les();
void les(char t[], char s[]);
int  les(char t[], int min, int max);
void ny();                   //  Oppgave 3a
void oversikt();             //  Oppgave 3b
void fjern();                //  Oppgave 3c
void les_fra_fil();          //  Oppgave 3d
void skriv();                //  Oppgave 3e 


                             //  GLOBALE VARIABLE:
CD  cder[MAX_CDER+1];        // Array av CD-struct'er.
int ant_cder;                // Aktuelt antall CD'er i kartoteket.

                            
int main()  {                //  MAIN:
  char valg;

  les_fra_fil();             //  Oppgave 3d

  skriv_meny();
  valg = les();

  while (valg != 'A')  {
    switch(valg)  {
      case 'N':  ny();         break;   //  Oppgave 3a
      case 'O':  oversikt();   break;   //  Oppgave 3b
      case 'F':  fjern();      break;   //  Oppgave 3c
      case 'S':  skriv();      break;   //  Oppgave 3e
      default :  skriv_meny(); break;
    }
    valg = les();
  }
  return 0;
}


                             //  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {         //  Skriver brukerens lovlige valg:
  cout << "\nF›lgende kommandoer er lovlige:";
  cout << "\n\tN - Ny CD";
  cout << "\n\tO - Oversikt over ALLE CD'ene";
  cout << "\n\tF - Fjern en CD";
  cout << "\n\tS - Skriv data om en gitt artist";
  cout << "\n\tA - Avslutt";
}


char les()  {                //  Leser, upcaser og returnerer ETT tegn:
  char ch;
  cout << "\nKommando:  ";
  cin >> ch;                 //  Leser.
  cin.ignore();              //  Forkaster neste tegn (='\n').
  return (toupper(ch));      //  Upcaser og returnerer.
}


void les(char t[], char s[]) {    //  Leser inn en tekst med lengde ulik 0.
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, NVNLEN);           //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}


int les(char t[], int min, int max)  {   // Leser et tall i et visst intervall.
  int n;
  do  {                                  // Skriver ledetekst:
    cout << '\t' << t << '(' << min << '-' << max << "): ";
    cin >> n;                            // Leser inn ett tall.
  } while(n < min  ||  n > max);         // Sjekker at i lovlig intervall.
  return n;                              // Returnerer innlest tall.
}


                                       //  Leser inn alle data om en ny CD:
void ny()  {                 //  OPPGAVE 3A
  if (ant_cder < MAX_CDER)  {            // Fortsatt plass til CD'er:
     cout << "\nREGISTRERER NY CD:\n";
     ant_cder++;                         // Tar i bruk neste "skuff".
     les("Artistnavn", cder[ant_cder].navn);    // Leser inn de ulike dataene:
     les("CD-tittel", cder[ant_cder].tittel);
     cder[ant_cder].utgivelsesaar = les("Utgivelses†r", 1950, 2010);
     cder[ant_cder].ant_sanger    = les("Antall sanger", 3, MAX_SANGER);
     cin.ignore();
     for (int i = 0;  i < cder[ant_cder].ant_sanger;  i++)
         les("Sang", cder[ant_cder].sangtittel[i]);
  } else
    cout << "\n\n\tKARTOTEKET ER FULLT MED " << MAX_CDER << " CD'ER !\n\n";
}


                                    //  Skriver oversikt over HELE kartoteket:
void oversikt()  {           //  OPPGAVE 3B
  char ch;
  for (int i = 1;  i <= ant_cder;  i++)  {  //  G†r gjennom ALLE CD'ene:
                                        //  Skriver data om EN CD:
      cout << setw(4) << i << ":\t" << cder[i].navn << "  (" 
           << cder[i].utgivelsesaar << ")\n\t" <<  cder[i].tittel << ",  "
           << cder[i].ant_sanger << " sanger.\n";
                                        //  Stanser for hver 10.artist:
      if (i % 10 ==0)  {  cout << "\n\n\t\t\t\tTrykk en tast .....\n"; cin >> ch;  }
  }
}


                                       //  Fjerner alle dataene om en gitt CD:
void fjern()  {              //  OPPGAVE 3C
  int nr;                                     //  CD-nummer.
  cout << "\nFJERN EN CD:\n";                  
  nr = les("CD-nr", 0, ant_cder);             //  Leser aktuell CD's nummer.
  if (nr != 0)  {                             //  Reelt nummer er valgt:
     cder[nr] = cder[ant_cder--];             //  Fjerner (overkopierer) den !
     cout << "\n\tCD'en er fjernet.\n\n";
  } else                                      //  Intet nummer (0) ble valgt.
     cout << "\n\tIngen CD ble fjernet!\n\n";
}

                                       //  Leser inn dataene om CD'ene fra
                                       //    fil og inn i datastrukturen:
void les_fra_fil()  {        //  OPPGAVE 3D
  int i, nr;                           //  L›kkevariabel og †rstall.
  ifstream innfil("CD_INFO.DTA");      //  pner aktuelt fil-objekt.

  ant_cder = 0;                        //  Nullstiller antall cd'er totalt.
  if (innfil)  {                       //  Filen finnes:
     innfil >> nr;                     //  Leser (om mulig) neste †rstall.
                                       //  Ikke filslutt, og fortsatt plass:
     while (!innfil.eof()  &&  ant_cder < MAX_CDER)  {
       cder[++ant_cder].utgivelsesaar = nr;       // Kopierer utgivelses†r.
       innfil.ignore();                //  Forkaster ETT blankt tegn.
       innfil.getline(cder[ant_cder].navn, NVNLEN);   // Leser artistnavn.
       innfil.getline(cder[ant_cder].tittel, NVNLEN); // Leser CD'ens tittel.
       innfil >> cder[ant_cder].ant_sanger;       // Leser antall sanger
       innfil.ignore();                //  Forkaster linjeskift.
       for (i = 0; i < cder[ant_cder].ant_sanger;  i++)  // Leser sangtitler:
           innfil.getline(cder[ant_cder].sangtittel[i], NVNLEN); 
       innfil >> nr;                   //  Leser (om mulig) neste †rstall.
     }
  } else                               //  Filen finnes IKKE:
    cout << "Finner ikke filen 'CD_INFO.DTA'\n";
}

                                       //  Skriver ALLE data om EN artist,
                                       //    MED eller UTEN sangtitlene:
void skriv()  {              //  OPPGAVE 3E
  char nvn[NVNLEN];                    //  Aktuelt artistnavn.
  char onske, ch;                      //  MED eller UTEN sangtitler ("onske") ?
  int  i, j;                           //  L›kkevariable.

  cout << "\nALLE CD'ER FRA EN ARTIST:\n";
  les("Artistnavn", nvn);                           //  Leser artistnavn.
  do  {
    cout << "\tM(ed) eller U(ten) sangtitler: ";    //  Leser MED eller UTEN
    cin >> onske;  onske = toupper(onske);          //    sangtitler:
  } while (onske != 'M'  &&  onske != 'U');

  for (i = 1;  i <= ant_cder;  i++)                 //  G†r gjennom ALLE CD'ene:
      if (strcmp(cder[i].navn, nvn) == 0)  {        //  Artistnavn funnet:
         cout << '\n' << setw(4) << i << ":\t" << cder[i].tittel << "  (" 
              << cder[i].utgivelsesaar << "),  "
              << cder[i].ant_sanger << " sanger.\n";
         if (onske == 'M')  {                       //  Sangtitlene skrives:
            for (j = 0;  j < cder[i].ant_sanger;  j++)    // G†r gjennom dem:
                cout << "\n\t\t" << cder[i].sangtittel[j];
            cout << "\n\n\t\t\t\tTrykk en tast .....\n"; cin >> ch;  // Venter.
         }
      }
}
