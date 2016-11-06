#include <iostream>

using namespace std;


int main()   {
  int i, tall, sum=0;


//  Sette inn 1, 2, 3a og 3b etter tur ......


  cout << "\n\nSummen er:  " << sum << '\n';
  return 0;
}




/*
1:
  const int N = 5;
  for (i = 1;  i <= N; i++)  {
      cout << "Tast et tall:  ";   cin >> tall;
      sum += tall;
  }


2:
  cout << "Tast et tall: ";   cin >> tall;
  while (tall < 100)  {
     cout << "Tast et tall STØRRE enn 100:  ";
     cin >> tall;
  }
  sum += tall;


3a:
  do {
     cout << "Tast et tall (0 = avslutt):  ";   cin >> tall;
     sum += tall;
  } while (tall != 0);


3b:
  cout << "Tast et tall (neg.tall = avslutt):  ";   cin >> tall;
  while (tall >= 0)  {
    sum+= tall;
    cout << "Tast et tall (neg.tall = avslutt):  ";   cin >> tall;
  }

*/
