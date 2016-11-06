//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_16.CPP

//   Programeksempel nr.16 for forelesning i  C++ -programmering. 

//   Eksemplet viser bruken av argumenter/parametre inn til funksjoner. 
//   Disse returnerer ogs† verdier.


#include <iostream>

using namespace std;


int finnMinste(float tall[], const int LENGDE);

int finnStorste(float tall[], const int LENGDE);

float summerHoppkarakterer(float tall[], const int LENGDE,
                           int ignorer1, int ignorer2);


const int SIZE1 = 5;
const int SIZE2 = 10;


int main()  {
  float tabell1[SIZE1] = { 1.2F,  3.4F,  5.7F,  17.9F,  0.7F };
  float tabell2[SIZE2] = { 34.5F,  45.7F,  98.6F,  34.2F,  12.9F,
                           76.9F,  34.1F,  98.3F,  54.5F,  56.2F  };
  float tabell3[SIZE1] = { 18.5F,  19.0F,  19.5F,  18.0F,  18.5F  };
  int minsteKar, storsteKar;

  cout << "\nMinste element i TABELL1 har indeks nummer:   " 
       <<  finnMinste(tabell1, SIZE1);                      //  Skriver: '4'
  cout << "\nSt›rste element i TABELL1 har indeks nummer:  " 
       <<  finnStorste(tabell1, SIZE1);                     //  Skriver: '3'

  cout << "\n\nMinste element i TABELL2 har indeks nummer:   " 
       <<  finnMinste(tabell2, SIZE2);                      //  Skriver: '4'
  cout << "\nSt›rste element i TABELL2 har indeks nummer:  " 
       <<  finnStorste(tabell2, SIZE2);                     //  Skriver: '2'

  minsteKar = finnMinste(tabell3, SIZE1);  
  cout << "\n\nMinste element i TABELL3 har indeks nummer:   " 
       << minsteKar;                                        //  Skriver: '3'
  storsteKar = finnStorste(tabell3, SIZE1); 
  cout << "\nSt›rste element i TABELL3 har indeks nummer:  " 
       << storsteKar;                                       //  Skriver: '2'

  cout << "\n\nSummen av hoppkarakterene er:  "             // Skriver: '56'
       << summerHoppkarakterer(tabell3, SIZE1, minsteKar, storsteKar) << '\n';

  return 0;  
}
                                   //  I en array men "LENGDE" elementer, 
                                   //  s† returnerer funksjonen med INDEKSEN
                                   //  for det ELEMENTET som er MINST.
int finnMinste(float tall[], const int LENGDE)  {
  float minstHittil = tall[0];    //  Antar at f›rste element er minst. 
  int indeks = 0;

  for (int i = 1;  i < LENGDE;  i++)
    if (tall[i] < minstHittil)  {    //  Finner et mindre element.
      minstHittil = tall[i];         //  Oppdaterer variable.
      indeks = i;
    }
  return  indeks;                     //  Returnerer indeksen.
}

                                   //  I en array men "LENGDE" elementer, 
                                   //  s† returnerer funksjonen med INDEKSEN
                                   //  for det ELEMENTET som er STØRST.
int finnStorste(float tall[], const int LENGDE)  {
  float storstHittil = tall[0];   //  Antar at f›rste element er st›rst.
  int indeks = 0;

  for (int i = 1;  i < LENGDE;  i++)
    if (tall[i] > storstHittil)  {   //  Finner et st›rre element.
      storstHittil = tall[i];        //  Oppdaterer variable.
      indeks = i;
    }
  return  indeks;                     //  Returnerer indeksen
}

                                      // Elementene i arrayen "tall" med
                                      // "LENGDE" elementer summeres, unntatt
                                      // de to med indeksen "ignorer1/2".
float summerHoppkarakterer(float tall[], const int LENGDE,
                           int ignorer1, int ignorer2)  {
  float summen = 0.0F;

  if (ignorer1 != ignorer2)  {        // Dersom IKKE alle elementene er like:
     for (int i = 0;  i < LENGDE;  i++)  {    //  G†r gjennom hele arrayen:
       if (i != ignorer1  &&  i != ignorer2)  //  Elementet skal v‘re med:
         summen += tall[i];                   //  Oppdaterer totalsummen.
     }
  } else                             // ALLE elementene er like:
    summen = tall[0] * (LENGDE - 2); // Summen er derfor det f›rste elementet
                                     //   multiplisert med antall elementer
                                     //   unntatt 2 stk.
  return  summen;               // Returnerer resultatet.  
}
