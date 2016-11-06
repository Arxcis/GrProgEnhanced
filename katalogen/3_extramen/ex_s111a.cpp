//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S111A.CPP

//  L›sning til kontinuasjoneksamen i C++, 11.august 2011, oppgave 1A.
//  Laget av Frode Haug, HiG, mai 2011.


#include <iostream>
#include <cstring>

using namespace std;

char txt[] = "AUGUST-ER-DEILIG-FOR-DA-HAR-JEG-KONTINUASJONSEKSAMEN";

int main()   {
  int i = 13,  j = i % 5;

  cout << txt[i] <<  ' ' << txt[j] << '\n';

  i -= 5;  i*= 4;
  while (i <= 43)  {
	cout << txt[i+(13%5)] << ' ' << txt[j-(i*i/i/i)-2] << '\n';
    j += 2;  i += j;   
  }

  j = 13;
  for (i = 3;  i > 1;  i--)
      cout << txt[j-i] << ' ' << txt[j+i] << '\n';
  return 0;
}



//   Utskrift:    L U
//                T A
//                S G
//                D -
//                E G
