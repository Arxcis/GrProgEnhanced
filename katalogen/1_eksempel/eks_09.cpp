//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_09.CPP

//   Programeksempel nr.9 for forelesning i  C++ -programmering.

//   "Oppsummerende" eksempel fra kap.3 med bruk av:  for, while, if og switch


#include <iostream>
#include <cctype>      //  toupper
#include <cmath>       //  sqrt
#include <iomanip>     //  setw

using namespace std;


int main()  {

  int i, k1, k2, nr;
  char kommando;

  cout << "F›lgende kommandoer er lovlige:\n";
  cout << "\tH <k1> <k2>   - Beregner hypotenusen ut fra katetene k1 og k2\n";
  cout << "\tT <nr>        - Skriver tegn 'nr' i Ascii-alfabetet\n";
  cout << "\tG <nr>        - Skriver gangetabellen for tallet 'nr'\n";
  cout << "\tA eller Q     - Avslutte programet\n\n";

  cout << "\n\nGi kommando (m/parametre):  ";
  cin >> kommando;
  kommando = toupper(kommando);

  while (kommando != 'Q'  && kommando != 'A')  {
    switch (kommando)  {
      case 'H': cin  >> k1 >> k2;
		cout << "\tHypotenusen er:  " << sqrt(k1*k1 + k2*k2) << '\n';
		break;

      case 'T': cin >> nr;
		if (nr >= 0  &&  nr <= 255)
           cout << "\tTegnet er:  " << (unsigned char) nr << '\n';
		else
		   cout << "\tTallet utenfor aktuelt/lovlig intervall\n";
		break;

      case 'G': cin >> nr;
		for (i = 1;  i <=20;  i++)
		    cout << '\t' << setw(4) << i*nr << '\n';
		break;

      default: // Denne kopieringen hadde vi reelt IKKE foretatt, men istedet
               // benyttet oss av en funksjon.  Dette l‘rer vi f›rst om i kap.5.
	       cout << "F›lgende kommandoer er lovlige:\n";
	       cout << "\tH <k1> <k2>   - Beregner hypotenusen ut fra katetene k1 og k2\n";
	       cout << "\tT <nr>        - Skriver tegn 'nr' i Ascii-alfabetet\n";
	       cout << "\tG <nr>        - Skriver gangetabellen for tallet 'nr'\n";
	       cout << "\tA eller Q     - Avslutte programet\n\n";
	       break;
    }
    cout << "\n\nGi kommando (m/parametre):  ";
    cin >> kommando;
    kommando = toupper(kommando);
  }
  cout << "\n\nTakk for denne gang, takk for denne gang!\n\n";
  return 0;
}

