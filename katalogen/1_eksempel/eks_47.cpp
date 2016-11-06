//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_47.CPP

//   Programeksempel nr.47 for forelesning i  C++ -programmering.

//   Leser flere objekter fra filen 'EKS_4647.DTA' med formatet:
//         <Ansattnr> <Avdelingsbokstav>
//         <Navn>
//         <Postadresse>
//   Skriver flere objekter til filen 'EKS_47.DTA' med det samme formatet.


#include <fstream>           //  ifstream, ofstream
#include <iostream>          //  cout, cin

using namespace std;


const int STRLEN  =  80;     //  Max. tekstlengde inkl.'\0'.
const int MAXPERS = 100;     //  Max. personer i datastrukturen/arrayen.

class Person {
  private:
    int  anr;                //  Ansattnummer.
    char avd;                //  Avdeling.
    char navn[STRLEN];       //  Navn.
    char adr[STRLEN];        //  Postnummer og poststed.

  public:                    //  Leser selv inn det meste av sine egne data.
     void lesFraFil(int n, ifstream & inn) {     
       anr = n;                           //  Kopiere inn/lagrer parameter.
       inn >> avd;  inn.ignore();         //  Leser avdeling og '\n'.
       inn.getline(navn, STRLEN);         //  Leser hele linjen med navnet.
       inn.getline(adr, STRLEN);          //  Leser hele linjen med adresse.
     }
                             //  Skriver selv ALLE sine data:
     void skrivTilFil(ofstream & ut)  {  
       ut << anr << ' ' << avd << '\n'      //  EN linje med ansnr og avd.
          << navn << '\n' << adr << '\n';   //  Navn og adr p† hver sin linje.
     }
};


Person personer[MAXPERS];    //  Array med alle Person-objektene.
int antall;                  //  Antall objekter i bruk/datastrukturen.



void lesFraFil()  {          //  Leser ALLE objektene fra fil:
  int nr;                               //  1.felt i en ny post (ansattnr).
  ifstream innfil("eks_4647.dta");      //  Åpner aktuell fil.

  if (innfil)  {                        //  Filen er † finne:
    cout << "\nLeser fra 'EKS_4647.DTA' .....\n";

    innfil >> nr;                       //  Pr›ver † lese starten p† ny post.
    while (!innfil.eof()  &&  antall < MAXPERS-1)  {  // Mer, og ikke fullt.
       personer[++antall].lesFraFil(nr, innfil);      // Objekt leser mer selv.
       innfil >> nr;                    //  Pr›ver † lese starten p† ny post.
    }

  } else                                //  Filen ikke funnet:
    cout << "\nFant ikke filen 'EKS_4647.DTA'.\n\n";
}



void skrivTilFil()  {        //  Skriver ALLE objektene til fil:
  ofstream  utfil("eks_47.dta");        //  pner aktuell fil.

  cout << "\nSkriver til 'EKS_47.DTA' .....\n";
  for (int i = 1;  i <= antall;  i++)   //  G†r gjennom alle og f†r hvert
      personer[i].skrivTilFil(utfil);   //    objekt til † skrive seg selv.
}



int main()  {

  lesFraFil();

  skrivTilFil();

  cout << "\n\n";
  return 0;
}





//     Alternativ skrivem†te som tidligere ble brukt (prim‘rt i EX_.....):
/*
       void lesFraFil(int n, istream * inn) { 
         anr = n;
         *inn >> avd;  (*inn).ignore();
         (*inn).getline(navn, STRLEN);
         (*inn).getline(adr, STRLEN);
       }

       Kalles vha:
         personer[++antall].lesFraFil(nr, &innfil);



       void skrivTilFil(ostream * ut)  {
         *ut << anr << ' ' << avd << '\n'
             << navn << '\n' << adr << '\n';
       }
       Kalles vha:
         personer[i].skrivTilFil(&utfil);
*/

