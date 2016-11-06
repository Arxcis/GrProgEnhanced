#include <iostream>

using namespace std;

const int X = 4;
const int Y = 3;

int arr[X][Y] =  { {0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {3, 4, 5} };

int regn(int a[], int n)  {
  int k = 0; 
  for (int i = 0;  i < n;  i++)  k += a[i];
  return k;
}
  
int main()   {
  int i, j;
  cout << regn(arr[0], Y) << '\n';
  cout << regn(arr[2], Y) << '\n';
  cout << regn(arr[3], Y) << '\n';
  for (i = X-1, j = 0;  i > 0;  i--, j++)
      cout << arr[i][j] << "  ";
  cout << '\n';
  return 0;
}


//  Utskrift:  3
//             9
//             12
//             3  3  3
