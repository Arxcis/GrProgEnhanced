//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_03.CPP

//   Programeksempel nr.3 for forelesning i  C++ -programmering. 


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {
	                                   //  Aritmetikk:
  int t1, t2, t3;
  float f1, f2;
  char ch;

  cout << "Tast inn 3 heltall:  ";
  cin >> t1 >> t2 >> t3;
  f1 = (t1 + t2 + t3) / 3;          //  NB!  H›yre side er INT
  cout << "\nTallenes HELTALLIGE gjennomsnitt:  " << f1;
  cout << "\n\t\tTrykk en tast og deretter ENTER/CR.";  cin >> ch;
  f2 = (t1 + t2 + t3) / 3.0F;       //  NB!  H›yre side er FLOAT
  cout << "\nTallenes DESIMALE gjennomsnitt:    " << f2;
  cout << "\n\t\tTrykk en tast og deretter ENTER/CR.";  cin >> ch;


                                    //  Aritmetikk og utskrift:
  const int d1 = 10;
  int t4 = t1;                      //  NB!  Legg merke til \':
  cout << "\n\nVariabelen  \'t4\'  (=" << t4 << ") ›ket med  ";
  t4 += d1;
  cout << d1 << "  er:   " << t4;
  cout << "\n\t\tTrykk en tast og deretter ENTER/CR.";  cin >> ch;
  cout << "\nInnholdet i variabelen ›kes med  1  til:   " << ++t4;
  cout << "\n\t\tTrykk en tast og deretter ENTER/CR.";  cin >> ch;


/*                                  // (Unsigned) char:
  char c1;
  unsigned char c2;
  c1 = 'Ï';
  c2 = 'Ï';
  cout << "\n\nDe to tegnene er:  \'" << c1 << "\'  og  \'" << c2 << '\'';
  cout << "\n\t\tTrykk en tast og deretter ENTER/CR.";  cin >> ch;
  cout << "\nASCII-verdien er:  " << int(c1) << "  og  " << int(c2);
                                    //  NB!  "c1" har NEGATIVT innhold
  cout << "\n\t\tTrykk en tast og deretter ENTER/CR.";  cin >> ch;
                                    //  Setw og \t:
  cout << "\n\n\t\t\t   INN:\t    UT:";
  cout << '\n' << setw(20) << "Mat:" << "\t\t" << setw(8) << "1750";
  cout << '\n' << setw(20) << "Ferie:" << "\t\t" << setw(8) << "11250";
  cout << '\n' << setw(20) << "Forsikringer:" << "\t\t" << setw(8) << "550";
  cout << '\n' << setw(20) << "L›nn:" << '\t' << setw(8) << "9750";
  cout << "\n\t\tTrykk en tast og deretter ENTER/CR.";  cin >> ch;
*/

                                    //  Innlesing av enkelttegn:
  char c3, c4, c5, c6;
  cout << "\n\nSkriv inn 2 tegn:        ";
  cin >> c3;
  cin >> c4;
  cout << "\nTegnene er:  " << c3 << "  og  " << c4;
  cout << "\n\nSkriv inn 2 andre tegn:  ";
  cin >> c5 >> c6;
  cout << "Tegnene er:  " << c5 << "  og  " << c6;
  cout << "\n\t\tTrykk en tast og deretter ENTER/CR.";  cin >> ch;

                                    //  Modulus-operatoren (dvs. '%'):
  int tid, time, min, sek;
  cout << "\n\nSkriv totaltid (i sekunder):   ";
  cin >> tid;
  time = tid / 3600;
  min  = (tid % 3600) / 60;
  sek  = tid % 60;
  cout << "Dvs. " << time << " time(r)  " 
                  << min  << " minutt(er)  "
                  << sek  << " sekund(er)\n";
  return 0;
}
