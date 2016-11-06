//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_15B.CPP


//   L›sningsforslag til oppgave nr.15  i   C++ -programmering.

//   NB:  Variantl›sning - for † illustrere bruken av funksjoner.


#include <iostream>

using namespace std;


struct Person  {
  int    nummer;      
  int    alder;
  float  vekt;
};


Person les2(int n);
void   les(const int n, Person & p);


int main()  {
  Person person1, person2, person3;         //  Definerer 3 Person-variable.
  int    eldst;                             //  Personnummer til den eldste.
  int    totAlder;                          //  Summen av vektene.
  float  gjsnVekt;                          //  Gjennomsnittlig vekt.

  person1 = les2(1);          //  Leser ved † returnere verdi:
  person2 = les2(2); 
  person3 = les2(3);

//  les(1, person1);            //  Leser vha. referanseoverf›ring:
//  les(2, person2);
//  les(3, person3);


  totAlder = person1.alder + person2.alder + person3.alder;
  gjsnVekt = (person1.vekt + person2.vekt + person3.vekt) / 3.0F;

  eldst = person1.nummer;                   //  Antar at person1 er eldst.
  if (person2.alder > person1.alder)  {     //  Person2 er eldre enn peron1:
     eldst = person2.nummer;
     if (person3.alder > person2.alder)     //  Person3 er eldre enn person2:
        eldst = person3.nummer;
  }                   
  else if (person3.alder > person1.alder)   //  Person3 er eldre enn person1:
     eldst = person3.nummer;
                                            //  Skriver ut resultater:
  cout << "\n\n\nTotal alder:               " << totAlder
       <<     "\nGjennomsnittlig vekt:      " << gjsnVekt
       <<     "\nEldste person har persnr:  " << eldst;
  
  cout << "\n\n";
  return 0;
}


void les(const int n, Person & p)  {
  cout << "PERSON NR." << n << ":\n";
  cout << "\tNummer:   ";   cin >> p.nummer;
  cout << "\tAlder:    ";   cin >> p.alder;
  cout << "\tVekt:     ";   cin >> p.vekt;
  cout << "\n\n";         
}


Person les2(int n) {
  Person p;
  cout << "PERSON NR." << n << ":\n";
  cout << "\tNummer:   ";   cin >> p.nummer;
  cout << "\tAlder:    ";   cin >> p.alder;
  cout << "\tVekt:     ";   cin >> p.vekt;
  cout << "\n\n";
  return p;
}
