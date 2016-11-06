#include <iostream>
using namespace std;

struct tid  {
  int time;
  int min;
};

int  lesTall(int min, int max);
void lesTid(int & t, int & m);
void lesTid2(tid & ti);
tid  lesTid3();
void skrivUt(tid ti);

int main()  {
  int tall;
  tid t1, t2;
  int tt, mm;


  tall = lesTall(0, 20);
  cout << tall << '\n';

  lesTid(tt, mm);
  cout << tt << ":" << mm << '\n';

  lesTid2(t1);
  cout << t1.time << ":" << t1.min << '\n';
  skrivUt(t1);

  t2 = lesTid3();
  cout << t2.time << ":" << t2.min << '\n';
  skrivUt(t2);

  return 0;
} 


int lesTall(int min, int max)  {
  int t;
  do  {
    cout  << "Skriv et tall (" << min << '-' << max << "): ";
    cin >> t;
  } while (t < min  ||  t > max);
 return t;
}

void lesTid(int & t, int & m)  {
  t = lesTall(0, 23);
  m = lesTall(0, 59);
}

void lesTid2(tid & ti)  {
  ti.time = lesTall(0, 23);
  ti.min  = lesTall(0, 59);
}

tid  lesTid3() {
  tid ti;
  ti.time = lesTall(0, 23);
  ti.min  = lesTall(0, 59);
  return ti;
}

void skrivUt(tid ti) {
  cout << ti.time << ':' << ti.min << '\n';
}
