//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_15.CPP


//   L›sningsforslag til oppgave nr.15  i   C++ -programmering.


#include <iostream>

using namespace std;


struct Person  {
  int    nummer;      
  int    alder;
  float  vekt;
};


int main()  {
  Person person1, person2, person3;         //  Definerer 3 Person-variable.
  int    eldst;                             //  Ansattnummer til den eldste.
  int    totAlder;                          //  Summen av vektene.
  float  gjsnVekt;                          //  Gjennomsnittlig vekt.

  cout << "PERSON NR.1";                    //  Leser verdier om 3 personer:
  cout << "\n\tNummer:   ";   cin >> person1.nummer;
  cout << "\tAlder:    ";   cin >> person1.alder;
  cout << "\tVekt:     ";   cin >> person1.vekt;
  cout << "\n\n";

  cout << "PERSON NR.2";
  cout << "\n\tNummer:   ";   cin >> person2.nummer;
  cout << "\tAlder:    ";   cin >> person2.alder;
  cout << "\tVekt:     ";   cin >> person2.vekt;
  cout << "\n\n";

  cout << "PERSON NR.3";
  cout << "\n\tNummer:   ";   cin >> person3.nummer;
  cout << "\tAlder:    ";   cin >> person3.alder;
  cout << "\tVekt:     ";   cin >> person3.vekt;
  cout << "\n\n";
  
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
