//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_22.CPP


//   L›sningsforslag til oppgave nr.22  i   C++ -programmering.


//   Oppgaven omhandler lengden, fem stilkarakterer og poengsummene
//   for "ANTHOPPERE" hoppere. Disse sorteres etter poengsummene.

//   Alle ekstraoppgavene (1-3) er tatt med i l›sningsforslaget.
//   Disse st†r aller sist i koden (etter "main").


#include <iostream>                  //  cin, cout
#include <iomanip>                   //  setw, setprecision
#include <cstring>                   //  strcpy, strlen
#include <cstdlib>                   //  atof
#include <cctype>                    //  isalpha

using namespace std;

const int   TABELLPKT  =  80;        //  Lengden som gir "NORMPOENG" poeng.
const float NORMPOENG  =  70.0F;     //  Poengsummen ved lengden TABELLPKT.
const float MTRVERDI   =   1.4F;     //  Antall poeng pr. lengdemeter.
const int   ANTDOMMERE =   5;        //  Antall stilkarakterer.
const int   ANTHOPPERE =   5;        //  Antall deltagende hoppere.
const int   STRLEN      =  40;       //  Max.lengde p† hopperens navn.


class Hopper  {                      //  Klassen "Hopper":
  private:
    char  navn[STRLEN]; 
    float poengsum;
    float lengde;
    float karakter[ANTDOMMERE];

                                       //  To skjulte/hidden funksjoner:
    int    minMax(float tall[], const int MAX, char type);
    float  summer(float tall[], const int MAX, int ignorer1, int ignorer2);

  public:
    float  hentPoengsum()          {  return poengsum;    }
    void   lagreNavn(char nvn[])   {  strcpy(navn, nvn);  }
    void   lagreLengde(float len)  {  lengde = len;       }
    void   lagreKarakter(float kar[], const int MAX);
    void   beregnPoengsum();
    void   skrivData();
};


void  sorterPoengsummene();         //  Fire funksjoner, prim‘rt brukt
bool  lovlig(char nvn[]);            //    i ekstraoppgavene:
void  les(const char tekst[], char nvn[], const int MAX);
float les(const char tekst[], const float MIN, const float MAX);


Hopper hoppere[ANTHOPPERE];           //  Array med "Hopper"-objekter.


int main()  {                         //  HOVEDPROGRAMMET:
  int i, j;
  char nvn[STRLEN];                   //  Brukes til † lese inn hoppernavn.
  float kar[ANTDOMMERE];              //  Brukes til † lese inn stilkarakterer.

  for (i = 0;  i < ANTHOPPERE;  i++)  {
     les("Navn:  ", nvn, STRLEN);      //  Leser inn alle hoppernavnene. 
     hoppere[i].lagreNavn(nvn);        //  Lagrer disse i objektene.
  }

  for (i = 0;  i < ANTHOPPERE;  i++)  {        // Leser inn og lagrer
     cout << "\n\nHopper nr." << i+1 << ":";   //   en hoppers lengde.
     hoppere[i].lagreLengde(les("\tLengde:     ", 20, 130));

     for (j = 0;  j < ANTDOMMERE;  j++)        // Leser inn hopperens
        kar[j] = les("\tKarakter:  ", 5, 20);  //   stilkarakterer.

     hoppere[i].lagreKarakter(kar, ANTDOMMERE);    //  Lagrer karakterer
                                                   //    i objektet.
     hoppere[i].beregnPoengsum();                  //  Regner ut en hoppers
  }                                                //    poengsum.

  sorterPoengsummene();               //  Sorterer hopperne etter poengsum.

  cout << "\n\nHOPPERNES POENGSUMMER:\n";

  cout << setiosflags(ios::fixed)      //  For † f† ›nsket antall desimaler
       << setiosflags(ios::showpoint)  //    (side 272-273 i læreboka).
       << setprecision(2);

  for (i = 0;  i < ANTHOPPERE;  i++)    //  Skriver resultatliste.
     hoppere[i].skrivData();

  cout << "\n\n";
  return 0;
}

//  I en array med "MAX" elementer,  s† returnerer funksjonen med INDEKSEN for
//   det ELEMENTET som er MINST (n†r "type"= N), eller STØRST (n†r "type" = X):
int Hopper::minMax(float tall[], const int MAX, char type)  {
	float minMaxHittil = tall[0];      //  Antar at f›rste element er min/max
	int i, indeks = 0;

	for (i = 1; i < MAX; i++)          //  Finner et mindre/st›rre element:
		if ((type == 'N'  &&  tall[i] < minMaxHittil) ||
			(type == 'X'  &&  tall[i] > minMaxHittil))  {
		minMaxHittil = tall[i];        //  Oppdaterer variable.
		indeks = i;
		}
	return  indeks;                    //  Returnerer indeksen.
}

				//  Elementene i arrayen "tall" med "MAX" elementer summeres, 
				//    unntatt de to med indeksen "ignorer1/2":
float Hopper::summer(float tall[], const int MAX,
	                 int ignorer1, int ignorer2)  {
	float summen = 0.0F;
	int i;

	for (i = 0; i < MAX; i++)              //  G†r gjennom HELE arrayen og
		summen += tall[i];                 //    summerer ALLE elementene.

	summen -= tall[ignorer1];              //  Trekker fra igjen de to som
	summen -= tall[ignorer2];              //    skal ignoreres.

	return  summen;                        //  Returnerer resultatet.  
}

					//  Kopierer over og lagrer unna "MAX" stilkarakterer:
void Hopper::lagreKarakter(float kar[], const int MAX)  {
	int i;
	for (i = 0; i < MAX; i++)
		karakter[i] = kar[i];
}

					//  Beregner hopperens poengsum, 
					//    p† grunnlag av stilkarakterer og hopplengde:
void Hopper::beregnPoengsum()  {
	int minNr, maxNr;
	float lenPoeng, stilPoeng;
							//  Finner h›yeste og laveste karakter:
	minNr = minMax(karakter, ANTDOMMERE, 'N');
	maxNr = minMax(karakter, ANTDOMMERE, 'X');
							//  Summerer de tre 'midterste' stil karakterene:
	stilPoeng = summer(karakter, ANTDOMMERE, minNr, maxNr);
							//  Beregner lengdepoeng:
	lenPoeng = NORMPOENG + ((lengde - TABELLPKT) * MTRVERDI);

	poengsum = lenPoeng + stilPoeng;   //  Beregner total poengsum.
}

					//  Skriver en hoppers poengsum og navn:
void Hopper::skrivData()  {
	cout << '\n' << setw(10) << poengsum << '\t' << navn;
}


				//  Skriver ledeteksten "tekst". Leser verdier inn i "nvn",
				//    der denne	teksten er max. "MAX" lang:
void les(const char tekst[], char nvn[], const int MAX)  {
	do  {
		cout << '\n' << tekst;
		cin.getline(nvn, MAX);
	} while (!lovlig(nvn));              //   Looper inntil et lovlig navn.
}

				//  Skriver ledeteksten "tekst". Leser inn en streng/tekst,
				//    helt til dette inneholder et NUMERISK VERDI (tall), 
				//    og at dette tallet er i intervallet MIN-MAX:
float les(const char tekst[], const float MIN, const float MAX)  {
	char tallTekst[STRLEN];
	float tall;

	do  {
		cout << '\n' << tekst << '(' << MIN << '-' << MAX << "):  ";
		cin.getline(tallTekst, STRLEN);   //  Leser inn en TEKST
		tall = atof(tallTekst);           //  Pr›ver † konvertere til et tall
	} while (tall == 0 || tall < MIN || tall > MAX);
			//  Looper inntil klarer † konvertere korrekt (dvs. tall != 0)
			//    og at tallet er i korrekt intervall.
	return tall;
}

		//  Sorterer alle objektene i arrayen "hoppere", slikat den med h›yeste
		//    poengsum kommer f›rst. Bruker "seleksjonssortering":
void sorterPoengsummene()  {
  int     i, j, indeks;
  float   storst, pSum;
  Hopper  temp;
                                       //  G†r gjennom alle hopperne:
  for (i = 0;  i < ANTHOPPERE-1;  i++)  {
     storst = hoppere[i].hentPoengsum();  //  Antar at den f›rste ikke-
     indeks = i;                          //    sorterte er st›rst.
                                          //  Sjekker alle etterf›lgende:
     for (j = i+1;  j < ANTHOPPERE; j++)  {
        pSum = hoppere[j].hentPoengsum();
        if (storst < pSum)  {         //  Har funnet en ny st›rste-verdi:
           storst = pSum;             //  Oppdaterer hjelpe-variable:
           indeks = j;
        }
     }

     if (indeks != i)  {               //  Dersom en ny st›rste er funnet:
        temp = hoppere[i];             //  Bytter om de to hopper-objektene:
        hoppere[i] = hoppere[indeks];
        hoppere[indeks] = temp;
     }
  }
}

				//  Sjekker om en tekst KUN inneholder bokstaver og blanke:
bool lovlig(char nvn[])  {
  int i, len = strlen(nvn);

  for (i = 0;  i < len;  i++)          //  G†r gjennom hele tekststrengen.
    if (!isalpha(nvn[i])  &&  nvn[i] != ' ')
       return false;                   //  Dersom et ulovlig tegn:
                                       //    returnere umiddelbart med 'false'
  return true;                         //  For-l›kka gikk greit, uten uthopp,
}                                      //    dvs. alt er OK, returnere 'true'.
