//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H091B.CPP

//  L›sning til eksamen i C++, 7.desember 2009, oppgave 1B.
//  Laget av Frode Haug, HiG, november 2009.


#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 40;


class Foo   {
  private:
    char Dropkick[LEN], Theater[LEN];
    bool festlig;

  public:
    Foo(char t1[], char t2[])  
       {  strcpy(Theater, t1);  strcpy(Dropkick, t2);  festlig = true;  }
    void funk1()  {  festlig = !festlig;  }
    bool funk2()  {  return (strcmp(Theater, Dropkick));  }
    void funk3()  {  cout << Dropkick << "   " << Theater << "   "
                          << ((!festlig) ? "ikke " : "") << "festlig\n";  }
};


int main()  {
  Foo  f1("Murphys", "Dream"), f2("Persie", "Cesc"), f3("Per","per");
  f2.funk3(); 
  f1.funk1();  f1.funk3();
  cout << f3.funk2()  << '\n';
  f3.funk1();  f3.funk1();  f3.funk1();  f3.funk3();
  f1 = f3;     f3.funk1();  f3.funk1();  f1.funk3();
  return 0;
}



//  Utskrift:  Cesc   Persie   festlig
//             Dream   Murphys   ikke festlig
//             1
//             per   Per   ikke festlig
//             per   Per   ikke festlig
