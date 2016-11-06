//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_24.CPP


//   L›sningsforslag til oppgave nr.24  i   C++ -programmering.


//   Oppgaven omhandler en- og to-dimensjonale arrayer,
//   der de en-dimensjonale inneholder gjennomsnittet av
//   tallene i linjene og kolonnene i den to-dimenjonale.


#include <iostream>                    //  cout, set
#include <cstdlib>                     //  (s)rand
#include <iomanip>                     //  setw

using namespace std;


const int  ANTLIN  =  8;
const int  ANTKOL  = 10;


void  fyllRandom(int arr1[][ANTKOL], const int ALIN, const int AKOL);

void  regnSnitt(int arr1[][ANTKOL], float arr2[], float arr3[],
                const int ALIN, const int AKOL); 

void  skriv(int arr1[][ANTKOL], float arr2[], float arr3[],
            const int ALIN, const int AKOL); 


int   tall[ANTLIN][ANTKOL];            //  To-dimensjonal array
float snittLinje[ANTLIN];              //  En-dimensjonal array
float snittKolonne[ANTKOL];            //  En-dimensjonal array


int main()  {                          //  HOVEDPROGRAMMET:
  srand(0);
  fyllRandom(tall, ANTLIN, ANTKOL);
  regnSnitt(tall, snittLinje, snittKolonne, ANTLIN, ANTKOL);
  skriv(tall, snittLinje, snittKolonne, ANTLIN, ANTKOL);
  return 0;
}

                             //  Fyller en to-dimensjonal array med tilfeldige
                             //    tall mellom 10 og 20:
void  fyllRandom(int arr1[][ANTKOL], const int ALIN, const int AKOL)  {
  int i, j;
  
  for ( i = 0;  i < ALIN;  i++)
      for (j = 0;  j < AKOL;  j++)
          arr1[i][j] = (rand() % 11) + 10;
}

                        //  Regner ut snittet p† hver linje og i hver kolonne.
                        //    Legger resultatene i "arr2" og "arr3":
void  regnSnitt(int arr1[][ANTKOL], float arr2[], float arr3[],
                const int ALIN, const int AKOL)  {
  int i, j;

  for ( i = 0;  i < ALIN;  i++)
      for (j = 0;  j < AKOL;  j++)  {
        arr2[i]  += arr1[i][j];        //  Summerer hver linje.
        arr3[j]  += arr1[i][j];        //  Summerer hver kolonne.
  }

  for ( i = 0;  i < ALIN;  i++)        //  Finner snittet for linjene.
    arr2[i] /= AKOL;

  for (j = 0;  j < AKOL;  j++)         //  Finner snitter for kolonnene.
    arr3[j] /= ALIN;
}

                          //  Skriver ut de tre arrayenes innhold:
void  skriv(int arr1[][ANTKOL], float arr2[], float arr3[],
            const int ALIN, const int AKOL)  {
  int i, j;

  cout << setiosflags(ios::fixed)      //  Setter opp hvordan float-tall
       << setiosflags(ios::showpoint)  //    skal presenteres
       << setprecision(2);             //    (side 272-273 i læreboka).

  for (i = 0;  i < ALIN;  i++)  {      //  Skriver den to-dimensjonale 
     for (j = 0;  j < AKOL;  j++)      //    arrayens innhold,
         cout << setw(7) << arr1[i][j];
     cout << setw(8) << arr2[i] << '\n';   //  og snittet for linjene.
  }
  for (j = 0;  j < AKOL;  j++)         //  Nederst skrives kolonne-snittet.
      cout << setw(7) << arr3[j];
  cout << '\n';
}
