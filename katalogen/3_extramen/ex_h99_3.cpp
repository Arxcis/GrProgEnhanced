//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H99_3.CPP

//  L›sningsforslag til eksamen i C++, 14.desember 1999, oppgave 3.
//  Laget av Frode Haug, HiG, desember 1999.


//  Programmet h†ndterer informasjon omkring hvilke traller, via deres
//  unike trallenummer, som for tiden er utl†nt til hvilken person.


                             //  INCLUDE:
#include <iostream>          //  cin, cout
#include <fstream>           //  ifstream, ofstream
#include <cctype>            //  toupper
#include <cstring>           //  strcmp

using namespace std;

                             //  CONST:
const int ANT_TRALLER  = 30; //  Antall traller som er til utleie.
const int NVNLEN       = 40; //  Max.lengde for en tekststreng.

                             //  STRUCT:
struct tralle  {             //  Data om en tralle:
  char navn[NVNLEN];         //  Dens navn.
  bool laant;                //  Om utl†nt (=true) eller ledig (=false).
};

                             //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les_kommando();
int  les_nr();
void utlaan() ;              //  Oppgave 3a
void innlevering();          //  Oppgave 3b
void les_fra_fil();          //  Oppgave 3c
void skriv_til_fil();        //  Oppgave 3d
void finn_person();          //  Oppgave 3e
void utlaan2();              //  Oppgave 3f


                             //  GLOBALE VARIABLE:
tralle status[ANT_TRALLER+1]; // Array av tralle-struct'er
int ant_laant;                // Antall traller som for ›yeblikket er utl†nt.


                             //  MAIN:
int main()  {
  char valg;

  les_fra_fil();             //  Oppgave 3c

  skriv_meny();
  valg = les_kommando();

  while (valg != 'A')  {
    switch(valg)  {
      case 'U':  utlaan();       break;   //  Oppgave 3a
//    case 'U':  utlaan2();      break;   //  Oppgave 3f
      case 'I':  innlevering();  break;   //  Oppgave 3b
      case 'F':  finn_person();  break;   //  Oppgave 3e
      default :  skriv_meny();   break;
    }
    valg = les_kommando();
  }
  return 0;
}


                             //  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {         //  Skriver brukerens lovlige valg:
  cout << "\nF›lgende kommandoer er lovlige:";
  cout << "\n\tU - Utl†n av tralle";
  cout << "\n\tI - Innlevering av tralle";
  cout << "\n\tF - Finn ut om en gitt person l†ner";
  cout << "\n\tA - Avslutt";
}


char les_kommando()  {       //  Leser, upcaser og returnerer ETT tegn:
  char ch;
  cout << "\nKommando:  ";
  cin >> ch;                 //  Leser.
  cin.ignore();              //  Forkaster neste tegn (='\n').
  return toupper(ch);        //  Upcaser og returnerer.
}


int les_nr()  {              //  Leser og returnerer et tall i arrayens
  int n;                     //     indeks-intervall:
  do  {
    cout << "\n\tNummer (1-" << ANT_TRALLER << "):  ";
    cin >> n;  cin.ignore();
  } while (n < 1  ||  n > ANT_TRALLER);
  return n;
}

                                       // L†ner ut (om mulig) en ledig tralle:
void utlaan()  {             //  Oppgave 3a
  int nr;
  if (ant_laant < ANT_TRALLER)  {      //  Flere traller er til l†ns:
     nr = les_nr();                    //  Leser ›nsket/l†nt trallenummer.
     if (!status[nr].laant)  {         //  Trallen er ledig:
        status[nr].laant = true;       //  Setter at aktuelt nummer er utl†nt.
        ant_laant++;                   //  Teller opp totalt antall utl†nt.
        cout << "\tL†ners navn: ";     //  Leser og registrerer tralle-
        cin.getline(status[nr].navn, NVNLEN);    //  l†nerens navn.
        skriv_til_fil();               //  Lagrer dataene p† fil (oppgave 3d).
     } else                            //  nsket tralle er allerede utl†nt:
       cout << "\n\tTralle nr." << nr << " er allerede utl†nt !\n";
  } else                               //  Alle trallene er l†nt ut:
     cout << "\n\tUmulig † l†ne flere, da ALLE trallene er utl†nt !\n";
}


                                       //  Innleverer (om mulig) en tralle:
void innlevering()  {        //  Oppgave 3b
  int nr;
  if (ant_laant > 0)  {                //  Minst EN tralle er utl†nt:
     nr = les_nr();                    //  Leser innlevert tralles nummer.
     if (status[nr].laant)  {          //  Trallen er utl†nt:
        status[nr].laant = false;      //  Setter at n† er den ledig.
        ant_laant--;                   //  Teller ned totalt antall utl†nt.
        cout << "\n\t" << status[nr].navn << " har levert tralla si.\n";
        skriv_til_fil();               //  Lagrer dataene p† fil (oppgave 3d).
     } else                            //  Trallen er IKKE utl†nt.
       cout << "\n\tTralle nr." << nr << " er IKKE utl†nt !\n";
  } else                               //  Ingen tralle er utl†nt:
     cout << "\n\tUmulig † innlevere, da ingen utl†nt !\n";
}


                                       //  Leser inn dataene om tralleutl†n
                                       //    fra fil og inn i datastrukturen:
void les_fra_fil()  {        //  Oppgave 3c
  int nr;
  ifstream innfil("TRALLER.DTA");      //  pner aktuelt fil-objekt.

  ant_laant = 0;                       //  Nullstiller antall totalt utl†nt.
  if (innfil)  {                       //  Filen finnes:
     innfil >> nr;                     //  Leser (om mulig) neste trallenummer.
                                       //  Ikke filslutt, og for mange utl†nt:
     while (!innfil.eof()  &&  ant_laant < ANT_TRALLER)  {
       ant_laant++;                    //  Teller opp totalt antall utl†nt.
       status[nr].laant = true;        //  Setter aktuell tralle som utl†nt.
       innfil.ignore();                //  Forkaster ETT blankt tegn.
       innfil.getline(status[nr].navn, NVNLEN);   // Leser l†nerens navn.
       innfil >> nr;                   //  Leser (om mulig) neste trallenummer.
     }
  } else                               //  Filen finnes IKKE:
    cout << "Finner ikke filen 'TRALLER.DTA'\n";
}


                                       //  Skriver hele datastrukturen til fil:
void skriv_til_fil()  {      //  Oppgave 3d
  ofstream utfil("TRALLER.DTA");       //  pner aktuelt fil-objekt.
  for (int i = 1;  i <= ANT_TRALLER;  i++)  //  G†r gjennom HELE arrayen:
    if (status[i].laant)                    //  Aktuelt nummer/indeks er utl†nt.
       utfil << i << ' ' << status[i].navn << '\n'; // Skriver nummer/indeks
}                                                   //   og navn p† EN fillinje.


                                       //  Finner ut om en gitt person har
                                       //    l†nt noen tralle, og skriver
                                       //    is†fall aktuelt trallenummer:
void finn_person()  {        //  Oppgave 3e
  int nr = 0;
  char nvn[NVNLEN];

  cout << "\n\tFinn navnet: ";         //  Leser navnet for potensiell l†ner:
  cin.getline(nvn, NVNLEN);  
                                       //  G†r gjennom HELE trall-arrayen:
  for (int i = 1;  i <= ANT_TRALLER;  i++)     //  Finner l†ner med s›kt navn:
      if (status[i].laant  &&  strcmp(status[i].navn, nvn) == 0)
         {  nr = i;  break;  }         //  Gjemmer unna aktuell indeks/nummer,
                                       //    og avbryter s›ket/l›kka.
  cout << "\n\tVedkommende har ";      //  Skriver generell start p† setning.
  if (nr != 0)                         //  Fant personen:
     cout << "l†nt tralle nr." << nr << '\n';    //  Skriver trallenummeret.
  else                                 //  Fant IKKE personen:
     cout << "IKKE l†nt noen tralle !\n";
}


                                  //  Annen versjon av oppgave 3a, som l†ner ut
                                  //    (om mulig) FRSTE ledige trallenummer:
void utlaan2()  {            //  Oppgave 3f
  int nr = 1;                     //  Leter fra starten av arrayen (indeks nr.1)
                                  //  etter f›rste ledige trallenummer/indeks:
  while (nr <= ANT_TRALLER  &&  status[nr].laant) 
    nr++;                         //  Teller opp til neste indeks/nummer:

  if (nr <= ANT_TRALLER)  {       //  Indeks ble innenfor arrayens grenser:
     cout << "\n\tVedkommende f†r tralle nr." << nr;    // Skriver trallenummer.
     status[nr].laant = true;     //  Setter aktuelt nummer som utl†nt.
     ant_laant++;                 //  Teller opp totalt antall utl†nt.
     cout << "\n\tL†ners navn: "; //  Leser og registrerer trallel†ners navn:
     cin.getline(status[nr].navn, NVNLEN);
     skriv_til_fil();             //  Lagrer dataene p† fil (oppgave 3d).
  } else                          //  Ingen ledige traller:
     cout << "\n\tUmulig † l†ne flere, da ALLE trallene er utl†nt !\n";
}
