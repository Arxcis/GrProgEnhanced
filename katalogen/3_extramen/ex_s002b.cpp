//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S002B.CPP

//  L›sningsforslag til eksamen i C++, 16.august 2000, oppgave 2B.
//  Laget av Frode Haug, HiG, juli 2000.



#include <iostream>

using namespace std;

struct rec  {
  char  text[10];
  float tall;
};

rec recorder[] = { {"AAA", 1.1F}, {"BBB", 2.2F}, {"CCC", 3.3F},
                   {"DDD", 4.4F}, {"EEE", 5.5F}, {"FFF", 6.6F} };

void funk(rec a)
  { cout << a.text << "  " << a.tall << '\n'; }

void funk(char txt[], float f = 7.7F)
  { cout << txt << "  " << f << '\n'; }

void funk(float f, char txt[]="GGG")
  { cout << txt << "  " << f << '\n'; }

int main()  {
  funk(recorder[3]);
  funk(recorder[1].text);
  funk(recorder[2].tall);
  funk(recorder[5].text, 8.8F);
  funk(recorder[4].tall, "HHH");
  return 0;
}


//   Utskrift:
//      DDD  4.4
//      BBB  7.7
//      GGG  3.3
//      FFF  8.8
//      HHH  5.5
