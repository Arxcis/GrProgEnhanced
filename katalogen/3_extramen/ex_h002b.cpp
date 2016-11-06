//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H002B.CPP

//  L›sning til eksamen i C++, 7.desember 2000, oppgave 2B.
//  Laget av Frode Haug, HiG, november 2000.



#include <iostream>
#include <cstring>

using namespace std;

struct rec1  {
  int x, y;
};

struct rec2  {
 rec1 r1, r2;
 char txt[5];
};

rec2 samling[] = { { {100, 200}, {300, 400}, "321" },
                   { {100, 300}, {200, 400}, "231" },
                   { {200, 300}, {100, 400}, "132" } };

rec2 beregn(rec2 rr1, rec2 rr2)  {
  int x1 = (rr1.r1.x + rr2.r1.x) / 2,
      y1 = (rr1.r1.y + rr2.r1.y) / 2,
      x2 = (rr1.r2.x + rr2.r2.x) / 2,
      y2 = (rr1.r2.y + rr2.r2.y) / 2;
  rec2 rr3 = { {x1, y1}, {x2, y2}, ""};  strcpy(rr3.txt, rr2.txt);
  return rr3;
}



int main()  {
  rec2 r3;
  r3 = beregn(samling[0], samling[1]);
  cout << '\n' << r3.r1.x << ' ' << r3.r1.y
       << ' '  << r3.r2.x << ' ' << r3.r2.y << ' ' << r3.txt;
  r3 = beregn(samling[0], samling[2]);
  cout << '\n' << r3.r2.x << ' ' << r3.r2.y
       << ' '  << r3.r1.x << ' ' << r3.r1.y << ' ' << r3.txt;
  r3 = beregn(samling[2], samling[1]);
  cout << '\n' << r3.r1.x << ' ' << r3.r1.y
       << ' '  << r3.r2.x << ' ' << r3.r2.y << ' ' << r3.txt;

  return 0;
}


//   Utskrift:
//      100 250 250 400 231
//      200 400 150 250 132
//      150 300 150 400 231
