//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H00_3.CPP

//  Løsningsforslag til eksamen i C++, 7.desember 2000, oppgave 3.
//  Laget av Frode Haug, HiG, november 2000.
//  En god del endret/modifisert av FrodeH, HiG, høsten 2003.


//  Programmet holder orden på ulike personers poeng i spillet Yatzy.
//  Postnavn leses FRA fil og sluttresultatet skrives TIL fil.


                             //  INCLUDE:
#include <iostream>               //  cin, cout
#include <fstream>                //  ifstream, ofstream
#include <cstring>                //  strcpy
#include <iomanip>                //  setw

using namespace std;

                             //  CONST:
const int TXT_LEN      = 20;     //  Max. lengde på tekster (navn).
const int MAX_SPILLERE =  6;     //  Max. antall spillere som kan delta.
const int MAX_POSTER   = 23;     //  Max. antall ulike poster i Yatzy.
const int MAX_POENG    = 50;     //  Max. antall poeng i EN omgang.
const int BONUS_GRENSE = 63;     //  Om summen av post nr.0-5 (1'ere-6'ere)
const int BONUS        = 50;     //    >= BONUS_GRENSE gis 'BONUS' ekstrapoeng.

                             //  KLASSER:
class Poster {                          //  Klasse med postnavnene:
  private:
    char postnavn[MAX_POSTER][TXT_LEN]; //  Navnet/tittelen til de ulike postene.

  public:                               //  Returnerer navnet til post nr.'n':
    void hent(char navn[], int n)  {  strcpy(navn, postnavn[n]);  }
    void les_fra_fil();                 //  Oppgave 3D
};


class Spiller  {
  private:	
    char navn[TXT_LEN];          //  Spillerens navn.
    int  poeng[MAX_POSTER];      //  Hver enkelt post's poeng (nr.0 brukes !)
  
  public:
    void initier(int n);                         //  Oppgave 3C
    void les_poeng(int n);                       //  Oppgave 3F
    void beregn_totalsum();                      //  Oppgave 3F
    void skriv_til_fil(ostream* ut);             //  Oppgave 3E
};


                             //  DEKLARASJON AV FUNKSJONER:
int  summer(int p[MAX_POSTER], int n, int m);    //  Oppgave 3B
void initier_spillere();                         //  Oppgave 3C
void skriv_resultat_til_fil();                   //  Oppgave 3E

                             //  GLOBALE VARIABLE:
Poster postnavnene;                 //  Alle postnavnene lagres i ETT objekt.
Spiller deltager[MAX_SPILLERE+1];   //  Deltagende spillere (nr.0 brukes ikke).
int  siste_post, ant_spillere;      //  Aktuelt antall poster og spillere.

                          
int main()  {                //  HOVEDPROGRAMMET:
  int i, j;

  postnavnene.les_fra_fil();     //  Leser postnavene/-titlene fra fil.

  initier_spillere();            //  Initierer/nullstiller spillerne.
  cout << "\n\n";
                             //  OPPGAVE 3F:
  for (j = 0;  j <= siste_post-1;  j++)  {      //  Går gjennom ALLE postene:
      for (i = 1;  i <= ant_spillere;  i++)     //  Går gjennom alle spillerne:
          deltager[i].les_poeng(j);             //  EN spiller leser EN post.
      if (j == 5)  j += 2;                      //  Om "sum" er satt skal det
  }                                             //    hoppes over to poster !

  for (i = 1;  i <= ant_spillere;  i++)         //  Setter TOTALSUM for alle.
      deltager[i].beregn_totalsum();

  skriv_resultat_til_fil();                     //  Skriver alt til fil.

  cout << "\n\n";
  return 0;
}

                             //  DEFINISJON AV KLASSE-FUNKSJONER:

                             //  OPPGAVE 3D:
void Poster::les_fra_fil()  {    //  Leser navnet/tittelen på postene fra fil:
  ifstream innfil("YATZY.DTA");  //  Åpner aktuell fil.
  char buffer[TXT_LEN];          //  Buffer for å hente en og en linje.
  int nr = 0;                    //  Nåværende post-/linjenummer.

  if (innfil)  {                 //  Filen finnes:
     innfil.getline(buffer, TXT_LEN);             // Leser (om mulig) EN linje.
     while (!innfil.eof() &&  nr < MAX_POSTER)  { // Ikke nådd filslutt:
       strcpy(postnavn[nr++], buffer);   //  Lagrer unna postens navn/tittel.
       innfil.getline(buffer, TXT_LEN);  //  Leser (om mulig) EN linje.
     }
     siste_post = nr-1;          //  Tar vare på siste brukte indeks/skuff.
	 cout << "\n\nHar lest inn postnavnene fra filen 'YATZY.DTA' !\n";
  } else                         //  Filen finnes ikke:
    cout << "\n\nFinner ikke filen 'YATZY.DTA' !\n";
}

                             //  OPPGAVE 3C:
void Spiller::initier(int n)  {   
  int i;
  cout << "\n\t" << n << ". spillers navn:  ";   //  Leser spillerens navn
  cin.getline(navn, TXT_LEN);                    //     og nullstiller alle
  for (i = 0;  i <= siste_post;  i++) poeng[i] = 0; //  poengene:
}

                             //  OPPGAVE 3F:
void Spiller::les_poeng(int n)  {      //  Leser poengene for post nr.'n':
  char pnvn[TXT_LEN];
  postnavnene.hent(pnvn, n);           //  Henter aktuelt postnavn.
  do  {
    cout << navn << "'s poeng på " << pnvn << ":  ";  
    cin >> poeng[n];                   //  Leser lovlige poeng:
   } while (poeng[n] < 0 || poeng[n] > MAX_POENG);

  if (n == 5)  {                       //  Er ferdig med 6'erne: 
     poeng[6] = summer(poeng, 0, 5);   //  Beregner sum post 0-5.
     postnavnene.hent(pnvn, 6);        //  Skriver ut denne summen:
     cout << "\t\t" << pnvn << ": " << poeng[6]<<'\n';
     if (poeng[6] >= BONUS_GRENSE) poeng[7] = BONUS; // Gir/setter evt.bonus.
  }
}

                             //  OPPGAVE 3F:
void Spiller::beregn_totalsum()  {     //  Beregner spillerens TOTALSUM:
  poeng[siste_post] = summer(poeng, 6, siste_post-1);
}

                             //  OPPGAVE 3E:
void Spiller::skriv_til_fil(ostream* ut)  {  //  ALLE data skrives til fil:
  int i;                                     
  char pnvn[TXT_LEN];                      //  Aktuelt postnavn.
  *ut << navn << ":\n";                    //  Skriver spillers navn.
  for (i = 0;  i <= siste_post;  i++)  {   //  Går gjennom alle postene:
      postnavnene.hent(pnvn, i);
      *ut << '\t' << pnvn << ":\t"         //  Skriver postnavn
          << setw(3) << poeng[i] << '\n';  //    og poeng:
  }
  *ut << '\n';                             //  Ekstra '\n' mellom hver spiller.
}

                             //  DEFINISJON AV FUNKSJONER:

                             //  OPPGAVE 3B:
int  summer(int p[MAX_POSTER], int n, int m)  {
  int sum = 0;                   //  Beregner summen av elementene i en 
  for (int i = n;  i <= m;  i++) //     delarray fra indeks nr.'n' til nr.'m':
     sum += p[i];
  return sum;                    //  Returnerer svaret.
}


                             //  OPPGAVE 3C:
void initier_spillere()  {       //  Leser antall spillere, deres navn og 
  int i;                         //     initierer/nullstiller poengene.
  do  {                          //  Leser et LOVLIG antall spillere:
    cout << "\nAntall spillere (1-" << MAX_SPILLERE << "):  ";
    cin >> ant_spillere;
  } while (ant_spillere < 1 || ant_spillere > MAX_SPILLERE);
  cin.ignore();

  for (i = 1;  i <= ant_spillere;  i++)  //  Leser navn og nullstiller
        deltager[i].initier(i);          //     poengene for spilleren:
}


                             //  OPPGAVE 3E:
void skriv_resultat_til_fil()  { //  Skriver spillernes resultat til fil:
  ofstream utfil("YATZY.RES");   //  Åpner aktuell fil.
  int i;                         //  Løkkevaribel.

  for (i = 1;  i <= ant_spillere;  i++)     //  Går gjennom alle spillerne:
	  deltager[i].skriv_til_fil(&utfil);    //  Skriver ALLE dataene til fil.
  cout << "\n\nResultatene er skrevet til filen 'YATZY.RES'.\n";  //  Melding.
}
