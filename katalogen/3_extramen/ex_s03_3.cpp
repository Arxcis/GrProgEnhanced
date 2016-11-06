//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_S03_3.CPP

//  Løsningsforslag til eksamen i C++, 9.august 2003, oppgave 3.
//  Laget av Frode Haug, HiG, august 2003.


//  Program for å administrere oppdrag ute hos ulike kunder/steder
//  på forskjellige dager i løpet av året.


                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream, ofstream
#include <cstring>            //  strcpy
#include <cctype>             //  toupper

using namespace std;

                        //  CONST:
const int ANTMND = 12;        //  Antall måneder.
const int ANTDAG = 31;        //  Max. antall dager i en måned.
                              //  Antall dager i hver måned
                              //     (NB: ignorerer skuddår!):
const int DAGANTALL[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int STRLEN = 40;        //  Max.lengde for en tekst.


                        //  STRUCT:
struct Oppdrag  {             //  Oppdrag (EN kunde, EN dag):
  char navn[STRLEN];          //  Kundens/stedets navn.
  char adr[STRLEN];           //  Kundens/stedets adresse.
  char merknad[STRLEN];       //  Evt.merknad/kommentar til oppdraget.
  int  tlf;                   //  Kundens tlf.
};


                        //  DEKLARASJON AV FUNKSJONER:
void  skriv_meny();
char  les_kommando();
void  les_inn(int & m, int & d);
void  nytt_oppdrag();
void  slett_oppdrag();
void  oversikt();
void  les_fra_fil();
void  skriv_til_fil();


                        //  GLOBALE VARIABLE:
Oppdrag oppdragene[ANTMND+1][ANTDAG+1]; // Bruker indeksene 1-12(x) og 1-31(y).


                        //  HOVEDPROGRAM:
int main()  {
   char kommando;
   
   les_fra_fil();                         //  Oppgave 3e
   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  nytt_oppdrag();  break; //  Oppgave 3b
       case 'S':  slett_oppdrag(); break; //  Oppgave 3c
       case 'O':  oversikt();      break; //  Oppgave 3d
       case 'F':  skriv_til_fil(); break; //  Oppgave 3f
       default:   skriv_meny();    break;
     }
     kommando = les_kommando();
   }
  return 0;
}

                        //  DEFINISJON AV FUNKSJONER:
	  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN = Nytt oppdrag\n";
  cout << "\tS = Slett oppdrag\n";
  cout << "\tO = Oversikt over en ukes oppdrag\n";
  cout << "\tF = skriv til Fil\n";
  cout << "\tQ = quit/avslutt\n";
}


char les_kommando()  {       //  Henter et ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi ønske:  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}


                        //  OPPGAVE 3A:
                             //  Leser inn måned og dag. Referanseoverførte 
void les_inn(int & m, int & d)  {   // parametre, så de oppdateres direkte:
  do {
    cout << "\n\tMåned (1-" << ANTMND << "): ";    //  Leser lovlig måned:
    cin >> m;
  } while (m < 1 || m > ANTMND);
  do {
    cout << "\n\tDag (1-" << ANTDAG << "): ";      //  Leser lovlig dag:
    cin >> d;
  } while (d < 1 || d > ANTDAG);
  cin.ignore();
}


                        //  OPPGAVE 3B:
void  nytt_oppdrag()  {      //  Legger inn/registrerer nytt oppdrag:
  int mnd, dag;              //  Aktuell måned og dag.
  char tekst[STRLEN];        //  Hjelpearray for tekstlesning.
  
  cout << "\nNYTT OPPDRAG:";
  les_inn(mnd, dag);         //  Leser aktuell måned og dag.
  if (oppdragene[mnd][dag].tlf == 0)  {  //  Intet oppdrag denne dagen:
     cout << "\n\tNavn: ";  cin.getline(tekst, STRLEN);   //  Leser inn data
     strcpy(oppdragene[mnd][dag].navn, tekst);            //    om kunden/
     cout << "\tAdresse: ";  cin.getline(tekst, STRLEN);  //    stedet:
     strcpy(oppdragene[mnd][dag].adr, tekst);
     cout << "\tTelefon: ";  cin >> oppdragene[mnd][dag].tlf;  cin.ignore();
     cout << "\tMerknad: ";  cin.getline(tekst, STRLEN);
     strcpy(oppdragene[mnd][dag].merknad, tekst);
  } else                                 //  Oppdrag allerede:
     cout << "\nAnnet oppdrag allerede denne dagen!\n";
}


                        //  OPPGAVE 3C:
void  slett_oppdrag()  {     //  Sletter/fjerner eksisterende oppdrag:
  int mnd, dag;              //  Aktuell måned og dag.
  
  cout << "\nSLETT OPPDRAG:";
  les_inn(mnd, dag);         //  Leser aktuell måned og dag.
  if (oppdragene[mnd][dag].tlf != 0)  {  //  Oppdrag denne dagen:
     strcpy(oppdragene[mnd][dag].navn, "");   //  Fjerner/sletter alle
     strcpy(oppdragene[mnd][dag].adr, "");    //    lagrede data:
     oppdragene[mnd][dag].tlf = 0;
     strcpy(oppdragene[mnd][dag].merknad, "");
     cout << "\nOppdraget denne dagen er slettet/fjernet.\n";
  } else                                 //  Intet oppdrag:
     cout << "\nIntet oppdrag denne dagen!\n";
}


                        //  OPPGAVE 3D:
void  oversikt()  {          //  Skriver oversikt over oppdrag i fem dager:
  int mnd, dag;              //  Aktuell måned og dag.
  int i;                     //  Løkkevaribel.
  
  cout << "\nOPPDRAGSOVERSIKT (en gitt uke):";
  les_inn(mnd, dag);         //  Leser aktuell måned og dag.
  for (i = dag;  i <= dag+4;  i++)  {   //  Går gjennom de fem aktuelle dagene:
      if (i <= DAGANTALL[mnd])  {       //  Om holder seg innenfor måneden:
         cout << i << ":\t";            //  Skriver dagnummeret:
         if (oppdragene[mnd][i].tlf != 0) {   // Oppdrag denne dagen:
             cout << oppdragene[mnd][i].navn                // Skriver ALLE data
                  << '\t' << oppdragene[mnd][i].adr << '\n' //   om aktuell dag:
                  << '\t' << oppdragene[mnd][i].tlf
                  << '\t' << oppdragene[mnd][i].merknad << '\n';
          } else                         //  Intet oppdrag denne dagen:
             cout << "LEDIG\n";               
      }
  }
}


                        //  OPPGAVE 3E:
void  les_fra_fil()  {       //  Leser hele datastrukturen fra fil:
  int mnd, dag;                     //  Aktuell måned og dag.
  ifstream innfil("oppdrag.dta");   //  Åpner aktuell fil.
  if (innfil)  {                    //  Filen finnes:
     cout << "\nLESER FRA FILEN 'OPPDRAG.DTA' ...\n";
     innfil >> mnd;                 //  Prøver å lese neste måned.
     while (innfil)  {              //  Ennå ikke slutt på filen:
       innfil >> dag;
       innfil >> oppdragene[mnd][dag].tlf;  innfil.ignore();
       innfil.getline(oppdragene[mnd][dag].navn, STRLEN);
       innfil.getline(oppdragene[mnd][dag].adr, STRLEN);
       innfil.getline(oppdragene[mnd][dag].merknad, STRLEN);
       innfil >> mnd;               //  Prøver å lese neste måned.
      }
  } else
    cout << "\n\tFinner ikke filen 'OPPDRAG.DTA'!";
}


                        //  OPPGAVE 3F:
void  skriv_til_fil()  {     //  Skriver hele datastrukturen til fil:
  int i, j;                         //  Løkkevariable.
  ofstream utfil("oppdrag.dta");    //  Åpner aktuell fil.

  cout << "\nSKRIVER TIL FILEN 'OPPDRAG.DTA' ...\n";
  for (i = 1;  i <= ANTMND;  i++)   //  Går gjennom hele året:
      for (j = 1;  j <= ANTDAG;  j++)
          if (oppdragene[i][j].tlf != 0)  {  //  Dagen med oppdrag:
             utfil << i << ' ' << j << ' '   //  Skriver ALLE dets data:
                   << oppdragene[i][j].tlf << ' '
                   << oppdragene[i][j].navn << '\n'
                   << oppdragene[i][j].adr << '\n'
                   << oppdragene[i][j].merknad << '\n';
          }
}
