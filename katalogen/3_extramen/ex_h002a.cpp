//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H002A.CPP

//  L›sning til eksamen i C++, 7.desember 2000, oppgave 2A.
//  Laget av Frode Haug, HiG, november 2000.



#include <iostream>

using namespace std;

int main()  {
  char txt[] = "MISSISSIPPI";
  int i = 5, j = 6;

  while (i > 0) {                       
    cout << txt[i] << ' ' << txt[j] << ' ' // Eller:
         << char('K' - 2*i)     << ' '     // static_cast <char>('K' - 2*i)
         << char('D' + 2*j - 7) << '\n';   // static_cast <char>('D' + 2*j - 7)
    i--;  j++;
  }
  return 0;
} 


//  Utskrift:
//      S S A I
//      I I C K
//      S P E M
//      S P G O
//      I I I Q
