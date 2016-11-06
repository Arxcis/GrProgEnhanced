
#include <fstream>
#include <iostream>

using namespace std;


int main()  {
  ofstream utfil("TESTTEST.DTA");                            //   1:
  utfil << "Tester at fil lages/oppstår\n";
  cout << "\n\nHar laget en fil!\n\n";

  utfil.close();                                             //   3.

  const int STRLEN = 80;                                     //   2:
  ifstream innfil("TESTTEST.DTA");
  char str[STRLEN];

  if (innfil)  {                                             //   4.

     innfil.getline(str, STRLEN);                            //   2:
     cout << "\n\n" << str << "\n\n";

  } else                                                     //   4:
     cout << "\nFant ikke filen 'TESTTEST.DTA'!\n\n";

  return 0;
}

