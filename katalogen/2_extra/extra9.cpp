#include <iostream>
#include <iomanip>
using namespace std;

const int MAXALDER = 120;
const int INITALDER = 10;

class Person  {
  private:
    int ansattnr;
    int alder;

    float hoyde[MAXALDER];

  public:
    Person()        { ansattnr =  0;  alder = -1; cout << "Constr1\n"; }
    Person(int nr)  { ansattnr = nr;  alder = -1; cout << "Constr2\n"; }

    ~Person()       { cout << "Objekt 'dør'\n";  }

    void skriv()  {  
      int i;
      cout << "Ansatt: " << ansattnr << '\n';
      for (i = 0;  i <= alder;  i++)
          cout << setw(3) << i << ":  " << setw(5) << hoyde[i] << '\n';
    }
   
    void initier(float h[], const int INITA)  {
      int i;
      alder = INITA;
      for (i = 0;  i <= INITA;  i++)
	      hoyde[i] = h[i];
    }

    void lesHoyde()  {
      if (alder < MAXALDER-1)  {
	     cout << "\nHøyde ved " << ++alder << " år: ";
	     cin >> hoyde[alder];
      } else
        cout << "\nMaxalder på (" << MAXALDER-1 
             << " år) er innlest allerede!\n";
    }
};



int main()  {
 int i; 
 char ch;

 Person pers(45);
 float hoy[MAXALDER];

 pers.skriv();

 for (i = 0;  i <= INITALDER;  i++)  hoy[i] = 50.0F +(i*9.0F);
 
 pers.initier(hoy, INITALDER);

 pers.skriv();

 do  {
   pers.lesHoyde();
   pers.skriv();
   cout << "\nLese ny høyde (j/N): ";  cin >> ch;
 } while (ch == 'j');
 
 cout << "\n\n";
 return 0;
}