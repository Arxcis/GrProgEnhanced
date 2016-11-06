#include <iostream>
#include <cstring>
using namespace std;


const int STRLEN  = 80;
const int MAXPERS =  5;

class Person {
  private:
    char navn[STRLEN];
    char adr[STRLEN];
	int  pnr;
    char psted[STRLEN];

  public:
	Person()  { pnr = 0;  strcpy(navn, "");  strcpy(adr, "");  strcpy(psted, ""); }

	void skriv(int nr)  {
      cout << "\nData om person nr." << nr << ':'
		   << "\n\t" << navn << ", " << adr 
		   << "\n\t" << pnr << ' ' << psted;
//	  cout << "\nNavnet er på " << strlen(navn) << " tegn\n";
	}

    void les()  {
      cout << "\nNavn:     ";  cin.getline(navn, STRLEN);
      cout << "Adresse:  ";    cin.getline(adr, STRLEN);
      cout << "Poststed: ";    cin.getline(psted, STRLEN);
      cout << "Postnr:   ";    cin >> pnr;   cin.ignore();
	}

	void sett(char n[STRLEN], char a[], char p[], int nr)  {
       strcpy(navn, n);  strcpy(adr, a);  strcpy(psted, p);   pnr = nr;
	}

	void hent(char n[])  {  strcpy(n, navn);  }

	bool erLik(char n[])  {
//    if (strcmp(navn, n) == 0)  return true;
//	  else return false;
        return (!strcmp(navn, n));

	}
};


int main()  {
  int i;
  Person personer[MAXPERS];
  char nvn[STRLEN];

  for (i = 1;  i < 3;  i++) {
    cout << "\nSkriv inn data om person nr." << i << ':';
    personer[i].les();
  }

  personer[3].sett("cc", "ccc", "cccc", 4444);
  
  personer[4] = personer[2];

  for (i = 1;  i < MAXPERS;  i++)
    personer[i].skriv(i);

  personer[2].hent(nvn);
  cout << "\n\nPerson nr.2 heter: " << nvn;

  if (personer[1].erLik("Kari"))  cout << "\nTreff !!!";
  else cout << "\nIkke like navn.";

  cout << "\n\n";
  return 0;
}

