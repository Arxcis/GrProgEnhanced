//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_23.CPP


//   L›sningsforslag til oppgave nr.23  i   C++ -programmering.


//   Oppgaven omhandler innlesing og kontroll av personnummer.


#include <iostream>                    //  cin, cout
#include <cstring>                     //  strlen
#include <cctype>                      //  isdigit

using namespace std;


const int STRLEN = 40;
const int PNRLEN = 11;

bool  korrektPersNr(char nr[]);
bool  skuddaar(int aa);
int   dagnummer(int da, int maane, int aa);



int main()  {                         //  HOVEDPROGRAMMET:
  char pnr[STRLEN];

  cout << "Personnummer:  ";           //  Leser inn en tekst.
  cin.getline(pnr, STRLEN);

  if (korrektPersNr(pnr))              //  Sjekker om lovlig personnummer:
     cout << "\n\nLovlig personnummer.\n";
  else
     cout << "\n\nULOVLIG personnummer.\n";

  return 0;
}

                                       //  Sjekker om argumentet "nr"
                                       //  inneholder et lovlig personnummer.
bool korrektPersNr(char nr[])  {
   int i, len = strlen(nr);
   int p[PNRLEN];                      //  Inneholder SIFRENE i "nr".
   int dag, maaned, aar;               //  F›dedatoen.
   int undividNr;                      //  Tallet i posisjon 7-9.

   if (len != 11) 
      return  false;                   //  a) IKKE 11 lang

   for (i = 0; i < len;  i++)      
     if (!isdigit(nr[i]))              //  b) IKKE av bare sifre/tall
        return  false;

   for (i = 0;  i < len;  i++)         //  Konverterer ASCII-sifre til
     p[i] = int(nr[i]-'0');            //    int'er. Legger i array.

   dag    = p[0]*10  +  p[1];          // dag    = 0-99
   maaned = p[2]*10  +  p[3];          // maaned = 0-99
   aar    = 1900 + p[4]*10  +  p[5];   // aar    = 1900-1999

   if (dagnummer(dag, maaned, aar) == 0)
      return  false;                   //  c) IKKE lovlig dato

   undividNr = p[6]*100  +  p[7]*10  +  p[8]; 
                                       //  undividNr = 0-999
   
   if (undividNr < 100  ||  undividNr > 499)
      return  false;                   //  d) IKKE i intervallet 100-499

   if ((3*p[0] + 7*p[1] + 6*p[2] + 1*p[3] + 8*p[4] +  9*p[5] + 
             4*p[6] + 5*p[7] + 2*p[8] + 1*p[9])  %  11  != 0    ||
       (5*p[0] + 4*p[1] + 3*p[2] + 2*p[3] + 7*p[4] +  6*p[5] + 
             5*p[6] + 4*p[7] + 3*p[8] + 2*p[9] + 1*p[10])  %  11  != 0)
       return  false;                  //  e) Kontroll-sifre stemmer IKKE.

   return true;                        //  Ellers er alt OK.
}

                              // (IDENTISK med OPPG_20.CPP.)
                              //  Sjekker om et visst †r er skudd†r:
bool  skuddaar(int aa)  {			//  Skudd†r dersom: (delelig med 400)
									//    ELLER (delelig med 4 OG ikke med 100):
	return ((aa % 400 == 0) || ((aa % 4 == 0) && (aa % 100) != 0));
}

                                   // (IDENTISK med OPPG_20.CPP.)
                                   //  Ut fra datoens input, s† returneres
                                   //   (om mulig) denne datoens dagnummer
                                   //   i †ret, ellers returneres '0'.
int  dagnummer(int da, int maane, int aa)  {
                                   //  Setter opp antall dager i m†nedene.
                                   //   Verdien for februar settes senere.
  int dagerPrMaaned[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int totalDagNr, i;

  if (aa < 1900  ||  aa > 1999)   return 0;    //  Ulovlig †r.
  if (maane < 1  ||  maane > 12)  return 0;    //  Ulovlig m†ned.
                                               //  Ut fra om †ret er skudd†r
                                               //    eller ei, s† settes
                                               //    verdien for februar:
  dagerPrMaaned[1] = (skuddaar(aa))  ?  29 : 28;
                                               // Ulovlig dag:
  if (da < 1     ||  da > dagerPrMaaned[maane-1])  return 0; 
                                               //  Vi er n† garantert at vi
                                               //    har med en lovlig dato
                                               //    † gj›re.
  totalDagNr = da;
  for (i = 0;  i < maane-1;  i++)              // Regner ut datoens dagnummer.
     totalDagNr += dagerPrMaaned[i];

  return totalDagNr;                           // Returnerer dagnummeret.
}
