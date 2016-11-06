//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S151B.CPP

//  L›sning til eksamen i C++, 12.august 2015, oppgave 1B.
//  Laget av Frode Haug, HiG, juni 2015.


#include <iostream>
#include <cstring>
using namespace std;


class Vin  {
  private:
    char omraade[20];
    char type[20];
    int  aar;
    
  public:
    Vin(char o[], char t[], int a) 
                    {  strcpy(omraade, o);  strcpy(type, t);  aar = a;  }
    void skriv()    {  cout << type << ", " << aar << " (" << omraade << ')';  }
    bool lik(Vin v) {  return (!strcmp(omraade, v.omraade));  }
    bool lik(char t[]) {  return (!strcmp(type, t)  ||  !strcmp(omraade, t));  }
    bool periode(int a1, int a2)  {  return (aar >= a1  &&  aar <= a2);  }
    Vin  velg(Vin v)   {  return ((aar < v.aar)? v : Vin("ARSE", "NAL", 1));  }
};


int main()  {
  Vin vin1("Piemonte", "Barbaresco", 1998) , vin2("Piemonte", "Barolo", 2004),
      vin3("Toscana",  "Brunello",   1997);
  vin3.skriv();  cout << "   ";  vin2.skriv();   cout << '\n';
  cout << vin2.lik(vin3)  << ' '  <<  vin2.lik(vin1)  << '\n';
  cout << vin1.lik("Piemonte")  << ' '  <<  vin3.lik("Barolo")  << '\n';
  cout << vin1.periode(1997, 2002) << ' ' << vin2.periode(1997, 2002) << '\n';
  vin3 = vin1.velg(vin2);     vin3.skriv();      cout << '\n';
  return 0;
}


//  Utskrift:  Brunello, 1997 (Toscana)   Barolo, 2004 (Piemonte)
//             0 1
//             1 0
//             1 0
//             Barolo, 2004 (Piemonte)
