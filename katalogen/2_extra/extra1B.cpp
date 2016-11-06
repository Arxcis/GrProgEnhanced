#include <iostream>
using namespace std;


int main()   {
   char kommando;
   int i, tall, alder;

   cout << " .............\n";
   cout << "Kommando: ";    cin >> kommando;

   while (kommando != 'q')  {

	   if (kommando == 'a')  {
	      cout << "Multiplikasjon av: ";  cin >> tall;
          for (i = 1;  i <= 15;  i++)
              cout << i*tall << "  ";
	      cout << "\n\n";

	   } else if (kommando == 'b')  {
          cout << "Alder: ";  cin >> alder;
	      while (alder > 100)  {
                cout << "Alder SKAL være mindre enn 100: ";
		        cin >> alder;
 	      }
          if (alder < 10)
		       cout << "Barn!\n";
          else if (alder < 20)
		       cout << "Ungdom!\n";
          else if (alder < 30)
		       cout << "Student!\n";
          else if (alder < 50)
		       cout << "Moden!\n";
          else if (alder < 80)
		       cout << "Aldrende!\n";
          else
 		       cout << "Oldis!\n";
	   } else if (kommando == 'c')  {

           // ......................

       } else
         cout << "...........\n";
     cout << "Kommando: ";    cin >> kommando;
   }
   return 0;
}
