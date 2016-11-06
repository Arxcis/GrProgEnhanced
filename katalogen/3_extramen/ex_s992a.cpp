#include <iostream>

using namespace std;

const int N   = 10;
const int M   = 5;
const int INC = 2;

int main()   {
  int i=0, j;
  while (i < N)  {
    cout << i << ":  ";
    for (j = 1;  j <=  i+1;  j += 2)
        cout << j << "  ";
    cout << '\n';
    i += INC;
  }
  return 0;
}


//  Utskrift:  0:  1
//             2:  1  3
//             4:  1  3  5
//             6:  1  3  5  7
//             8:  1  3  5  7  9
