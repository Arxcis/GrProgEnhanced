#include <iostream>

using namespace std;


class Data {
  private:
     int id;
	 int hoyde;
	 float vekt;

  public:
      Data()                      { id = 0;  hoyde = 0;  vekt = 0.0F;  }
      Data(int i)                 { id = i;  hoyde = 0;  vekt = 0.0F;  }
      Data(int h, float v)        { id = 0;  hoyde = h;  vekt = v;     }
      Data(int i, int h, float v) { id = i;  hoyde = h;  vekt = v;     }

      void skriv1()  { cout << "\nID: "     << id;  }
      void skriv2()  { cout << "  Høyde: "  << hoyde << "  Vekt: "   << vekt;  }
      void skriv()   { skriv1();  skriv2();  }

      void les1()    { cout << "\nID: ";    cin >> id;  }
      void les2()    { cout << "\nHøyde: "; cin >> hoyde;
                       cout << "\nVekt: ";  cin >> vekt;  }
      void les()     { les1();  les2();  } 
      void sett(int i, int h, float v) { id = i;  hoyde = h;  vekt = v;  }

      bool erLik(Data d)  {
        return (id == d.id  &&  hoyde == d.hoyde  &&  vekt == d.vekt);
      }
};


int main()  {
  int i, h = 0; 
  float v = 0.0F;
  Data d1, 
	   d2(2),
	   d3(167, 65.4F),
	   d4(4, 183, 78.5F);

  d1.skriv();
  d2.skriv();
  d3.skriv();
  d4.skriv();
/*
  d1.les();
  d2.les2();
  d3.les1();

  d1.skriv();
  d2.skriv();
  d3.skriv();
  d4.skriv();
*/
  cout << "\n\nSkriv en ID: ";  cin >> i;
  d2.sett(i, h, v);
  d2.skriv();

  cout << "\n\nD1 og D2 er";
  if (!d1.erLik(d2)) cout << " IKKE";
  cout << " LIKE!";

  cout << "\n\n";
  return 0;
}

