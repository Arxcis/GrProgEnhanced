//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_46.CPP

//   Programeksempel nr.46 for forelesning i  C++ -programmering.

//   Leser f›rste objekt fra filen 'EKS_4647.DTA' med formatet:
//         <Ansattnr> <Avdelingsbokstav>
//         <Navn>
//         <Postadresse>
//   Skriver objektet til filen 'EKS_46.DTA' med det samme formatet.


#include <fstream>           //  ifstream, ofstream
#include <iostream>          //  cout, cin

using namespace std;


const int STRLEN  =  80;     //  Max. tekstlengde inkl.'\0'.


class Person {
  private:
    int  anr;                //  Ansattnummer.
    char avd;                //  Avdeling.
    char navn[STRLEN];       //  Navn.
    char adr[STRLEN];        //  Postnummer og poststed.

  public:
                             //  Leser selv inn ALLE sine egne data.
     void lesFraFil() {     
       ifstream inn("eks_4647.dta");      //  Åpner aktuell fil.
       if (inn)  {                        //  Filen er † finne:
          inn >> anr >> avd;  inn.ignore();  //  Leser ansnr, avdeling og '\n'.
          inn.getline(navn, STRLEN);         //  Leser hele linjen med navnet.
          inn.getline(adr, STRLEN);          //  Leser hele linjen med adresse.
       } else                             //  Filen ikke funnet:
         cout << "\nFant ikke filen 'EKS_4647.DTA'.\n\n";
     }

                             //  Skriver selv ALLE sine data:
     void skrivTilFil()  {  
       ofstream  ut("eks_46.dta");          //  Åpner aktuell fil.
       ut << anr << ' ' << avd << '\n'      //  EN linje med ansnr og avd.
          << navn << '\n' << adr << '\n';   //  Navn og adr p† hver sin linje.
     }

};


int main()  {

  Person person;

  cout << "\nLeser fra 'EKS_4647.DTA' .....\n";
  person.lesFraFil();

  cout << "\nSkriver til 'EKS_46.DTA' .....\n";
  person.skrivTilFil();

  cout << "\n\n";
  return 0;
}

