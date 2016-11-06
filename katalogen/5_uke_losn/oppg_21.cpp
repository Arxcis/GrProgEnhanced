//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_21.CPP


//   L›sningsforslag til oppgave nr.21  i   C++ -programmering.


//   Program som viser:
//      - bruk av array
//      - array som parameter/argument til funksjoner


#include <iostream>

using namespace std;


const int ANTTEGN = 26;

void  initArray(int arr[], const int MAX);
void  tellForekomster(int arr[]);
void  skrivHistogram(int arr[], const int MAX);


int main()  {
  int bokstavForekomst[ANTTEGN];

  initArray(bokstavForekomst, ANTTEGN);
  tellForekomster(bokstavForekomst);
  skrivHistogram(bokstavForekomst, ANTTEGN);

  cout << "\n\n";
  return 0;
}

                                       //  Nullstiller arrayen "arr".
void  initArray(int arr[], const int MAX)  {
  int i;
  for (i = 0;  i < MAX;  i++)
     arr[i] = 0;
}
                                       //  Teller opp antall ganger de ulike
                                       //    bokstaver forekommer.
void  tellForekomster(int arr[])  {
  char tegn;

  cout << "\nSkriv tegn (bokstaver), avslutt med '!':\n\n";
  do  {
    cin >> tegn;                            //  Henter ett og ett tegn.
    if (tegn >= 'a' &&  tegn <= 'z')        //  Tegnet er: 'a'-'z':
      ++arr[tegn-'a'];                      //  Teller opp. 
    else if (tegn >= 'A' &&  tegn <= 'Z')   //  Tegnet er 'A'-'Z':
      ++arr[tegn-'A'];                      //  Teller opp.
  } while (tegn != '!');                    //  Leser inntil '!' trykkes.
}

                                            //  Skriver horisontalt histogram.                                
void  skrivHistogram(int arr[], const int MAX)  {
   int i, j;

   for (i = 0;  i < MAX;  i++)  {             // G†r gjennom alle bokstavene:
      cout << "\n" << char(i + 'A') << ": ";  // Skriver bokstaven med ':'.
      for (j = 1;  j <= arr[i];  j++)         // Skriver s† mange '*' som
         cout << "*";                         //   antall forekomster.
   }
}
