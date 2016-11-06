//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_25.CPP


//   L›sningsforslag til oppgave nr.25  i   C++ -programmering.


//   Oppgaven omhandler et husregnskap med antall kroner brukt 
//   p† 9 poster/form†l i l›pet av †rets 12 m†neder. Totalsummene 
//   brukt hver m†ned, p† hver post og totalt skrives ogs†.


#include <iostream>                    //  cin, cout
#include <iomanip>                     //  setw

using namespace std;


const int STRLEN1 =  4;                //  M†nedsnavnets lengde (inkl. '\0')
const int STRLEN2 =  8;                //  Postnavnets lengde (inkl. '\0')
const int MAANED  = 13;                //  12 m†neder + 1 ekstra kolonne
const int POST    = 10;                //  9 poster + 1 ekstra linje

int regnskap[POST][MAANED];            //  To-dimensjonal array alle summene.
				       //  To string-arrayer: 
char mNvn[MAANED][STRLEN1] = { "Jan", "Feb", "Mar", "Apr", "Mai", "Jun",
			   "Jul", "Aug", "Sep", "Okt", "Nov", "Des", "Sum" };
char pNvn[POST][STRLEN2]   = { "Husleie", "Mat", "Str›m", "Kom.avg", "Avis",
			   "Abbonem", "Ferie", "Festing", "Diverse", "Sum" };
 

int main()  {                         //  HOVEDPROGRAMMET:
  int i,j;
  char ch;

  for (j = 0;  j < MAANED-1;  j++)  {       //  G†r gjennom alle m†nedene:
    cout << "\n\nINNLESING AV UTLEGG FOR " << mNvn[j] << "-MNED:\n";
    for (i = 0;  i < POST-1;  i++)  {       //  G†r gjennom alle postene:
       cout << '\n' << pNvn[i] << "\t:  ";
       cin >> regnskap[i][j];               //  Leser inn i aktuell "boks".

       regnskap[POST-1][j]   += regnskap[i][j];      // Summerer kolonnene.
       regnskap[i][MAANED-1] += regnskap[i][j];      // Summerer linjene.
       regnskap[POST-1][MAANED-1] += regnskap[i][j]; // Summerer "nedre h›yre
						                             //  hj›rne" i tabellen.
    }
    cout << "\n\n\tAlle postene ferdiglest for denne m†neden. Trykk en tast og ENTER";
    cin >> ch;
  }

  cout << "\n\n\n\nHUSREGNSKAP FOR HELE RET:\n\n\t";
  for (j = 0;  j < MAANED;  j++)       //  Egen linje med alle m†nedsnavnene:
    cout << ' ' << mNvn[j] << ' ';

  for (i = 0;  i < POST;  i++)  {      //  Skriver linjene (inkl. "sum")
    cout << '\n' << pNvn[i] << '\t';
    for (j = 0;  j < MAANED;  j++)  {        //  P† EN linje: alle m†nedene
       cout << setw(5) << regnskap[i][j];    //    (inkl. "sum")
    }
  }
  cout << '\n';
  return 0;
}
