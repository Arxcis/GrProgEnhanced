//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_18B.CPP

//   Programeksempel nr.18 for forelesning i  C++ -programmering. 

//   Eksemplet viser ulike storage classes synlighet.


#include <iostream>

using namespace std;


void funk1(int);
void funk2();



int A;


  //  A er synlig

int main()  {
  int B;

  //  A og B er synlig

  return 0;
}


void funk1(int C)  {
  int D;

  //  A, C og D er synlig

}


int E;


void funk2()  {
  int F;

  //  A, E og F er synlig

  for (int G = 0;  G < 10;  G++)  {

  //  A, E, F og G er synlig

  }

  if (F == E)  {
    int H;

  //  A, E, F og H er synlig

  }

  //  A, E og F er synlig

}

  //  A og E er synlig

