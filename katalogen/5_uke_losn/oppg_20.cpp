//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_20.CPP


//   L›sningsforslag til oppgave nr.20  i   C++ -programmering.


//   Program som viser bruken av funksjoner:
//      - med parametre/argumenter
//      - parametrene blir enten verdi- eller referanse-overf›rt ('&')
//      - med returverdi ('return')  


#include <iostream>

using namespace std;


void lesDato(int & da,  int & maane,  int & aa);
bool skuddaar(int aa);
int  dagerIMaaned(int m, int a);
int  dagnummer(int da, int maane, int aa);


int main()  {

  int dag, maaned, aar, dagnr;

  do  {
	  
   lesDato(dag, maaned, aar);                   //  Leser inn dato.
                                                //  Lovlig dato-format:
   if ((dagnr = dagnummer(dag, maaned, aar)) != 0)   //  Skriver dagummeret:
      cout << "\nDatoens dagnummer i †ret:      " << dagnr;

  } while (dagnr != 0);                         // Looper s†lenge lovlig dato.

  cout << "\n\n\nUlovlig dato er inntastet, derfor avslutter program.\n\n";
  return 0;
}

                                   //  Leser inn tre verdier til de medsendte
                                   //    parametrene. De aktuelle oppdateres
                                   //    DIREKTE, da de er referanse-overf›rt.
void  lesDato(int & da,  int & maane,  int & aa)  {
  cout << "\n\n\nDato (p† formen: dd mm ††††):  ";
  cin >> da >> maane >> aa;
}

                                   //  Sjekker om et visst †r er skudd†r.
bool  skuddaar(int aa)  {          //  Skudd†r dersom: (delelig med 400)
	                               //    ELLER (delelig med 4 OG ikke med 100).
  return ((aa % 400 == 0) || ((aa % 4 == 0) && (aa % 100) != 0));
}

                                   //  Returnerer antall dager i m†ned
int dagerIMaaned(int m, int a)  {  //    nr."m" i †ret "a".
  switch (m)  {
     case 1: case 3: case 5: case 7:
     case 8: case 10: case 12:         return 31;
     case 4: case 6: case 9: case 11:  return 30;
     case 2: if    (skuddaar(a))       return 29; 
		     else                      return 28;
  }
}

                                   //  Ut fra datoens input, s† returneres
                                   //   (om mulig) denne datoens dagnummer
                                   //   i †ret, ellers returneres '0'.
int  dagnummer(int da, int maane, int aa)  {
  int totalDagnr, i;

  if (aa < 1600  ||  aa > 2100)   return 0;    //  Ulovlig †r.
  if (maane < 1  ||  maane > 12)  return 0;    //  Ulovlig m†ned.
                                               //  Ulovlig dag:
  if (da < 1     ||  da > dagerIMaaned(maane, aa))  return 0; 
                                   //  Vi er n† garantert at vi har med en
                                   //    lovlig dato † gj›re.
  totalDagnr = da;
  for (i = 1;  i < maane;  i++)                // Regner ut datoens dagnummer.
     totalDagnr += dagerIMaaned(i, aa);

  return totalDagnr;                           // Returnerer dagnummeret.
}
