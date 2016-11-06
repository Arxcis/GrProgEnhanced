//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_20.CPP

//   Programeksempel nr.20 for forelesning i  C++ -programmering. 

//   "Oppsummerende" eksempel fra kap.2-7 med bruk av:
//      - enum
//      - klasser, arrayer, funksjoner
//      - strengmanipulering
//      - søke etter og sammenligne tekster 


//   Eksemplet omhandler et arkiv for en persons musikksamling (ENKELTlåter).
//   Artistnavn, tittel, utgivelsesår, medie (MP3, CD, LP) og kategori
//   (kvinne, mann, gruppe, ...) blir registrert for hvert element.
//   Alt lagres i en array av objekter. Brukeren kan:
//       - registrere en ny utgivelse
//       - få en oversikt over:  - EN artists utgivelser
//                               - titler som matcher med en (sub-)tittel
//                               - HELE arkivet


                        //  INCLUDE:
#include <iostream>                    //  cout, cin
#include <cstring>                     //  strcpy, strcmp, strlen, strstr 
#include <cctype>                      //  toupper

using namespace std;

                        //  CONST:
const int STRLEN1 =  40;               //  Navn's lengde
const int STRLEN2 =  60;               //  Tittel's lengde
const int MAXANT  = 500;               //  Max. registreringer i arkivet

                        //  ENUM:
enum medium   { MP3, CD, plate };
enum type     { kvinne, mann, gruppe, orkester, diverse };

                        
class Musikk  {         //  KLASSE:
  private:
    char    navn[STRLEN1];             //  Artistens navn.
    char    tittel[STRLEN2];           //  Utgivelsens tittel
    int     aar;                       //  Utgivelsesår.
    medium  medie;                     //  MP3, CD eller plate.
    type    kategori;                  //  Kvinne, mann, .....

  public:                              //  Deklarasjon av funksjoner:
    void registrer(char nvn[], char titt[]);
    void display();
    bool likNavn(char tekst[]);
    bool likDelTittel(char tekst[]);
};


                        //  DEKLARASJON AV FUNKSJONER:
void uppercase(char tekst[]);
void hent(const char utTekst[], char innTekst[], const int MAX);
void skrivMeny();                
char lesKommando();
void nyMusikk();
void sokNavn();
void sokTittel();
void oversikt();

                        //  GLOBALE VARIABLE:
Musikk musikkarkiv[MAXANT+1];          //  Array med alle Musikk-objektene.
int    sisteBrukt = 0;                 //  Siste brukte indeks i "musikkarkiv"


int main()  {           //  HOVEDPROGRAMMET:
   char kommando;
   
   skrivMeny();                        //  Skriver brukermeny.
   kommando = lesKommando();           //  Får inn brukers ønske.
				       
   while (kommando != 'Q')  {          //  Looper til 'Q' tastes:
     switch (kommando)  {
       case 'R': nyMusikk();  break;   //  R = registrer ny musikk.
       case 'N': sokNavn();   break;   //  N = skriver alt fra en artist.
       case 'T': sokTittel(); break;   //  T = søke (del av) tittel.
       case 'O': oversikt();   break;  //  O = oversikt over hele arkivet.
       default:  skrivMeny(); break;
     }
     kommando = lesKommando();         //  Får inn brukers ønske.
   }
   cout << "\n\n";
   return 0;
}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:
				             //  Fyller objektets data med verdier:
void Musikk::registrer(char nvn[], char titt[])  {
  int verdi;
  strcpy(navn, nvn);               //  To verdier kommer som parametre:
  strcpy(tittel, titt);
  cout << "\n\tUtgivelsesår:  ";   //  Resten må leses inn fra tastaturet:
  cin >> aar;
  cout << "\n\tMedie (0=MP3, 1=CD, 2=Plate):  ";
  cin >> verdi;                                    // Leser som int.
  medie = (medium) verdi;                          // Caster til enum.
  cout << "\n\tKategori (0=kvinne, 1=mann, 2=gruppe,";
  cout << " 3=orkester, 4=diverse): ";
  cin >> verdi;                                    // Leser som int.
  kategori = (type) verdi;                         // Caster til enum.
}


void Musikk::display()  {    //  Skriver ut objektets data:
  cout << '\n' << navn
       << "\n\t" << tittel
       << "\n\t" << aar  << "\t\t";
  switch (kategori)  {       
    case kvinne:     cout <<  "Kvinne";    break;  //  Bruker 'switch' og
    case mann:       cout <<  "Mann";      break;  //    'cout', da enum-
    case gruppe:     cout <<  "Gruppe";    break;  //    typer ikke kan 
    case orkester:   cout <<  "Orkester";  break;  //    vises DIREKTE
    case diverse:    cout <<  "Diverse";   break;  //    som tekst:
  }
  cout << "\t\t";
  switch (medie)  {
    case MP3:    cout << "MP3";      break;
    case CD:     cout << "CD";       break;
    case plate:  cout << "Plate";    break;
  }
}


bool Musikk::likNavn(char tekst[])  {   //  Er LIKE: "strcmp" returnerer '0':
  return (!strcmp(tekst, navn));
}


bool Musikk::likDelTittel(char tekst[])  {        //  Er IKKE substreng:
  return (strstr(tittel, tekst) != NULL);         //  'strstr' returnerer NULL.
}


                        //  DEFINISJON AV FUNKSJONER:
				              //  Omgjør en tekststreng til KUN STORE bokstaver,
void uppercase(char tekst[])  {    //  også  'æ', 'ø' og 'å':
   int i, len = strlen(tekst);         //  Finner tekstens lengde.
   for (i = 0;  i < len;  i++)  {      //  Går gjennom hele tekststrengen:
       if (tekst[i] == 'æ')  tekst[i] = 'Æ';       // Tegnet er 'æ', 'ø' eller
       else if (tekst[i] == 'ø')  tekst[i] = 'Ø';  //   'å': konverterer til
       else if (tekst[i] == 'å')  tekst[i] = 'Å';  //   stor bokstav.
       else tekst[i] = toupper(tekst[i]);   //  Ellers prøves å konvertere
   }                                        //   'a'-'z' til STOR bokstav.
}

				        //  Leser tekst fra tastaturet:
void hent(const char utTekst[], char innTekst[], const int MAX)  {
  cout << '\n' << utTekst;
  cin.getline(innTekst, MAX);         //  Henter tekst.
  uppercase(innTekst);                //  Konverterer til STORE bokstaver.
}


void skrivMeny()  {    //  Skriver meny for lovlige valg:
  cout << "FØLGENDE KOMMANDOER ER LOVLIG:";
  cout << "\n\tR - registrere ny musikk i arkivet";
  cout << "\n\tN - skriv alle av en artist";
  cout << "\n\tT - søke etter (del av) tittel";
  cout << "\n\tO - skriv oversikt over HELE arkivet";
  cout << "\n\tQ - avslutt program";
// Andre aktuelle menyvalg kunne være:
//    M - skriv alle på et spesielt medie
//    K - skriv alle av en bestemt kategori
//    A - skriv alle fra et bestemt årstall
//    S - skriv arkivet til fil
//    L - les arkivet fra fil
}

				        
char lesKommando()  {  //  Leser og returnerer ETT tegn:
   char ch;
   cout << "\n\n\nKommando (R, N, T, O, Q):  ";
   cin >> ch;  cin.ignore();  
   return toupper(ch);
}

				       
void nyMusikk()  {     //  Legger inn ett nytt element i arkivet:
  char navn[STRLEN1];        //  Artistens navn.
  char tittel[STRLEN2];      //  Utgivelsens tittel.
  int  i;                    //  Løkkevariabel.
  bool funn = false;         //  Hittil ingen duplikater.

  if (sisteBrukt < MAXANT)  {  //  Fortsatt plass igjen:
     cout << "\n\nREGISTRERER NY MUSIKK .....\n";
     hent("\tOppgi artistnavn:  ", navn, STRLEN1);
     hent("\tOppgi tittel:      ", tittel, STRLEN2);

	                         // Prøver å gå gjennom alle:
     for (i = 1;  i <= sisteBrukt;  i++)
         if (musikkarkiv[i].likNavn(navn)  && 
             musikkarkiv[i].likDelTittel(tittel)) break;  // Duplikat!
	 
/*  ALTERNATIVT (for de tre linjene ovenfor og den rett under):
     i = 1;                  //  Initierer variabel.
     while (!funn  &&  i <= sisteBrukt)  {        //  Ingen duplikat hittil
        if (musikkarkiv[i].likNavn(navn)  &&             //   og innenfor arrayen:
           musikkarkiv[i].likDelTittel(tittel))  funn = true; // Duplikat!
        else  i++;           //  OK hittil, sjekke den neste indeksen.
     }
     if (!funn)  {           //  Ingen duplikater funnet, kan legge inn ny:
*/
     if (i == sisteBrukt+1)  {   //  Ingen duplikater - legger inn ny:
        ++sisteBrukt;            //  Tar i bruk neste indeks.
        musikkarkiv[sisteBrukt].registrer(navn, tittel); //  Legger inn.
        cout << "\nFerdig med den nye registeringen.";
     } else                      //  Duplikat funnet (er der allerede):
        cout << "\nDenne er allerede registrert !";

  } else                     //  Arkivet er fullt:
    cout << "\n\nArkivet er fullt med " << MAXANT << " stk. allerede";
}

				       
void sokNavn()  {      //  Skriver alle titlene fra EN artist.
  char navn[STRLEN1];        //  Artistens navn.
  int  i;                    //  Løkkevariabel.

  cout << "\n\nSKRIV ALLE TITLER FRA EN ARTIST .....\n";
  hent("\tOppgi artistnavn:  ", navn, STRLEN1);

  for (i = 1;  i <= sisteBrukt;  i++)           //  Gjennomgår HELE arkivet:
      if (musikkarkiv[i].likNavn(navn))         //  Matcher HELE navnet:
          musikkarkiv[i].display();             //  Skriver objektet.
}

		                //  Skriver ALLE titlene som helt eller
void sokTittel()  {     //  delvis matcher en viss søkestreng.
  char tekst[STRLEN2];       //  Utgivelsens tittel.
  int i;                     //  Løkkevariabel.
  bool funn = false;         //  Hittil ingen funn.

  cout << "\n\nSØKER ETTER (DEL AV) TITTEL .....\n";
  hent("\tOppgi (del av) tittel:  ", tekst, STRLEN2);

  for (i = 1;  i <= sisteBrukt;  i++)              //  Gjennomgår HELE arkivet:
      if (musikkarkiv[i].likDelTittel(tekst)) {    //  Matcher (del)tittel:
          funn = true;                             //  Funn er gjort.
          musikkarkiv[i].display();                //  Skriver objektet.
      }
  if (!funn)                 //  Ingen treff/utskrift:
     cout << "\nIngen tittel inneholder/er lik denne teksten!";
}


void oversikt()  {      //  Skriver en total oversikt over HELE musikkarkivet:
  int i;
  char ch;
  cout << "\nMUSIKK-ARKIVETS INNHOLD:\n";
  for (i = 1;  i <= sisteBrukt;  i++)  {    //  Går gjennom alle elementene:
     musikkarkiv[i].display();              //  Skriver alt om ett element.
     if (i % 7 == 0)  {                     //  Stopper for hver 7.utskrift:
        cout << "\n\n\n\t\t\t\t\t\tSkriv ett tegn .....";  cin  >> ch;
     }
  }
}
