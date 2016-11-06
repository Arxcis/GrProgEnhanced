//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S99_3.CPP

//  L›sningsforslag til eksamen i C++, 17.august 1999, oppgave 3.
//  Laget av Frode Haug, HiG, august 1999.

//  Programmet h†ndterer informasjon omkring fagnummer, fagnavn, 
//  studenters navn og deres karakterer i ulike fag.

                             //  INCLUDE:
#include <iostream>          //  cout, cin
#include <fstream>           //  ifstream
#include <cctype>            //  toupper
#include <cstring>           //  strcmp, strcpy, strlen

using namespace std;

                             //  CONST:
const int FAGNR_LEN =  11;   //  Max.lengde for et fagnummer (inkl. '\0').
const int NAVN_LEN  =  51;   //  Max.lengde for fag-/studentnavn (inkl.'\0').
const int ANT_FAG   =  31;   //  Max. antall ulike fag EN student kan ta.
const int MAX_FAG   =  61;   //  Max. antall ulike fag p† skolen.
const int MAX_STUD  = 101;   //  Max. antall studenter i kartoteket.
                   //  NB: Bruker ikke element nr.0 for de tre sistnevnte !

                             //  STRUCT:
struct fag {                 
  char nr[FAGNR_LEN];        //  Fagets unike nummer (bokstaver og tall).
  char navn[NAVN_LEN];       //  Fagets navn.
};

struct fagdata  {
  char  nr[FAGNR_LEN];       //  Fagnummer.
  float karakter;            //  Karakteren i dette faget.
};

struct student  {
  char    navn[NAVN_LEN];    //  Studentens unike navn.
  int     ant_resultat;      //  Antall resultater registrert p† studenten.
  fagdata resultat[ANT_FAG]; //  Studentens resultater (fagnummer og karakter).
};

                             //  DEKLARASJON AV FUNKSJONER:
void strip(char txt[]);
void les(char txt1[], char txt2[], const int N);
int  finn_fag(char nr[]);
int  finn_student(char nvn[]);
void skriv_meny();
void nytt_fag();
void ny_student();           //  Oppgave 3a
void ny_karakter();          //  Oppgave 3b
void oversikt();             //  Oppgave 3c
void les_fra_filer();        //  Oppgave 3d

                             //  GLOBALE VARIABLE:
fag     fagene[MAX_FAG];
student studentene[MAX_STUD];
int     siste_fag,  siste_student;

                             //  MAIN:
int main()   {
  char kommando;

  les_fra_filer();           //  Oppgave 3d
  skriv_meny();
  cout << "\n\nKommando:  ";  cin >> kommando;  cin.ignore();
  kommando = toupper(kommando);

  while (kommando != 'Q')  {
    switch (kommando)  {
      case 'F': nytt_fag();     break;
      case 'S': ny_student();   break;   //  Oppgave 3a
      case 'K': ny_karakter();  break;   //  Oppgave 3b
      case 'O': oversikt();     break;   //  Oppgave 3c
      default:  skriv_meny();   break;
    }
    cout << "\n\nKommando:  ";  cin >> kommando;  cin.ignore();
    kommando = toupper(kommando);
  }
//   skriv_til_filer();      //  IKKE en del av eksamensoppgaven † lage denne.
 return 0;
}

                             //  DEFINISJON AV FUNKSJONER:
void strip(char txt[])  {            //  Tar vekk alle overfl›dige ' ' (blanke)
  while (txt[strlen(txt)-1] == ' ')  //    p† slutten av en tekst.
      txt[strlen(txt)-1] = '\0';
}


void les(char txt1[], char txt2[], const int N)  {  // Ber om og leser en tekst.
  do {
    cout << "\n\t" << txt1 << ": ";   //  Skriver ut ledetekst/prompt.
    cin.getline(txt2, N);           //  Leser tekst fra brukeren.
  } while (strlen(txt2) == 0);        //  Forkaster s† lenge kun ENTER/CR.
}


int finn_fag(char nr[])  {   //  Returnerer indeksen for et gitt fagnummer:
  for (int i = 1;  i <= siste_fag;  i++)
      if (!strcmp(fagene[i].nr, nr))  return i;           // Funnet !
  return 0;                  //  Ingen treff.
}

int finn_student(char nvn[])  {  //  Returnerer indeksen for en gitt student:
  for (int i = 1;  i <= siste_student;  i++)
      if (!strcmp(studentene[i].navn, nvn))  return i;    // Funnet !
  return 0;                  //  Ingen treff.
}

  
void skriv_meny()  {         //  Skriver brukerens lovlige valg:
  cout << "\n\nF›lgende kommandoer er tilgjengelige:";
  cout << "\n\tF - nytt Fag";
  cout << "\n\tS - ny Student";
  cout << "\n\tK - ny Karakter hos en student";
  cout << "\n\tO - Oversikt over EN students karakterer";
  cout << "\n\tQ - Quit / avslutt";
}


void nytt_fag()  {          //  Registerer et nytt fag/kurs:
  char num[FAGNR_LEN];       //  Nytt unikt fagnummer.

  if (siste_fag < MAX_FAG-1)  {                //  Plass til flere fag:
     les("Nytt fagnummer", num, FAGNR_LEN);    //  Leser inn nytt fagnummer.
     if (!finn_fag(num))  {     //  Faget eksisterer IKKE allerede: 
        siste_fag++;            //  Tar i bruk neste "skuff" i 'fagene'-arrayen.
        strcpy(fagene[siste_fag].nr, num);     //  Kopierer inn nytt fagnummer.
                                //  Leser inn navnet til det nye faget:
        les("Nytt fagnavn  ", fagene[siste_fag].navn, NAVN_LEN);
     } else                     //  Faget finnes allerede:
       cout << "\n\tDette fagnummeret eksisterer allerede !\n";
  } else                        //  IKKE plass til flere fag:
    cout << "\n\tFULLT med " << MAX_FAG-1 << " fag allerede !";
}


void ny_student()  {        //  OPPGAVE 3a:
  char nvn[NAVN_LEN];        //  Nytt unikt studentnavn.

  if (siste_student < MAX_STUD-1)  {            //  Plass til flere studenter:
     les("Nytt studentnavn", nvn, NAVN_LEN);    //  Leser inn nytt studentnavn.
     if (!finn_student(nvn))  { //  Studenten eksisterer IKKE allerede: 
        siste_student++;        //  Tar i bruk neste "skuff" i 'studentene'.
        strcpy(studentene[siste_student].navn, nvn); //  Kopierer studentnavn.
                                //  M huske † nullstille studentens 'resultat'.
        studentene[siste_student].ant_resultat = 0;
     } else                     //  Studenten finnes allerede:
       cout << "\n\tDenne studenten eksisterer allerede !\n";
  } else                        //  IKKE plass til flere studenter:
    cout << "\n\tFULLT med " << MAX_STUD-1 << " studenter allerede !";
}


void ny_karakter()  {       //  OPPGAVE 3b:
  char nvn[NAVN_LEN];        //  Aktuelt studentnavn.
  char num[FAGNR_LEN];       //  Aktuelt fagnummer.
  int  ind;                  //  Studentens indeks i 'studentene'.
  int   n;                   //  Hjelpevaribel for † forkorte koden.
  float k;                   //  En annen hjelpevaribel for † forkorte koden.

  les("Studentnavn", nvn, NAVN_LEN);         //  Leser aktuelt studentnavn.
  if ((ind = finn_student(nvn)) != 0)  {     //  Studenten finnes:
     if (studentene[ind].ant_resultat < ANT_FAG-1)  {  // Flere resultater mulig:
        les("Fagnummer", num, FAGNR_LEN);    //  Leser aktuelt fagnummer.
        if (finn_fag(num) != 0)  {           //  Faget finnes:
           n = ++studentene[ind].ant_resultat;   //  Teller opp antall resultater.
           strcpy(studentene[ind].resultat[n].nr, num);  // Lagrer fagnummeret.
           do  {
             cout << "\tKarakter (1.0-6.0):  ";  //  Leser aktuell karakter:
             cin >> k;
           } while (k < 1.0  ||  k > 6.0);       //  I lovlig intervall ?
           cin.ignore();                         //  Skipper buffer-rest.
           studentene[ind].resultat[n].karakter = k;   //  Lagrer karakter.
        } else                                 //  Faget finnes IKKE:
        cout << "\n\tIntet fag/kurs med dette navnet !\n";
     } else                                   //  Fullt med resultater:
       cout << "\n\tFULLT med " << ANT_FAG-1 << " resultater allerede !";
  } else                                      //  Studenten finnes IKKE:
    cout << "\n\tIngen student med dette navnet !\n";
}


void oversikt()  {          //  OPPGAVE 3c:
  char nvn[NAVN_LEN];        //  Aktuelt studentnavn.
  int  ind;                  //  Studentens indeks i 'studentene'.
  int  ind2;                 //  Fagnummerets indeks i 'fagene'.
  les("Studentnavn", nvn, NAVN_LEN);      //  Leser aktuelt studentnavn.
  if ((ind = finn_student(nvn)) != 0)  {  // Studenten finnes:
     cout << "\n\t" << studentene[ind].navn << " har "    // Navnet:
          << studentene[ind].ant_resultat << " karakter(er):";  // #resultat:
                                          //  Skriver ALLE resultatene:
     for (int j = 1;  j <= studentene[ind].ant_resultat;  j++)  {
                                          //  Skriver EN karakter:
         cout << "\n\t\t" << studentene[ind].resultat[j].karakter << '\t';
                                          //  Finner fagets indeks i 'fagene':
         ind2 = finn_fag(studentene[ind].resultat[j].nr);
                                          // Skriver fagets nummer og navn:
         cout << fagene[ind2].nr << '\t' << fagene[ind2].navn;
     }
  } else                     // Studenten finnes IKKE:
    cout << "\n\tIngen student med dette navnet !\n";
}


void les_fra_filer()  {      //  OPPGAVE 3d:
  int i, j;
  ifstream inn1("KAR_FAG.DTA");
  ifstream inn2("KAR_STUD.DTA");

  if (inn1)  {                               //  Filen lar seg †pne:
     inn1 >> siste_fag;  inn1.ignore();      //  Leser antall fag p† filen.
     for (i = 1;  i <= siste_fag;  i++)  {   //  For hvert fag:
         inn1.get(fagene[i].nr, FAGNR_LEN);  //  Leser fagets nummer:
         strip(fagene[i].nr);                //  Tar vekk avsluttende blanke.
         inn1.getline(fagene[i].navn, NAVN_LEN); //  Fagets navn.
     }
     if (inn2)  {                            //  Filen lar seg †pne:
        inn2 >> siste_student;   inn2.ignore();    //  Leser antall studenter.
        for (i = 1;  i <= siste_student;  i++)  {  //  For hver student:
            inn2.getline(studentene[i].navn, NAVN_LEN);  // Leser navn.
                                             //  Leser antall resultat:
            inn2 >> studentene[i].ant_resultat;  inn2.ignore();
                                             //  Leser resultatene:
            for (j = 1;  j <= studentene[i].ant_resultat;  j++)  {
                inn2.get(studentene[i].resultat[j].nr, FAGNR_LEN); // Fagnummer.
                strip(studentene[i].resultat[j].nr); // Fjerner avsluttende ' '.
                                                     // Leser fagets karakter:
                inn2 >> studentene[i].resultat[j].karakter;  inn2.ignore();
            }
        }
     } else                                  //  Filen lar seg IKKE †pne:
    cout << "\n\nKlarer ikke † †pne filen 'KAR_STUD.DTA' !";
  } else                                     //  Filen lar seg IKKE †pne:
    cout << "\n\nKlarer ikke † †pne filen 'KAR_FAG.DTA' !";
}
