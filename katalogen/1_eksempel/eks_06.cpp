//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_06.CPP

//   Programeksempel nr.6 for forelesning i C++ -programmering. 

//   Program som beregner poengsummer for et sk›ytel›p. F›rst leses
//   l›pernes kj›nn inn, deretter aktuell distanse. Tilsist leses tiden
//   inn, og poengsummen beregnes. Dette siste gjentas til brukeren sl†r
//   inn en negativ tid for minutter.


#include <iostream>
#include <iomanip>

using namespace std;


int main()  {

  char kjonn;                               //  L›pernes kj›nn.
  int distanse;                             //  Aktuell distanse.
  int ant500;                               //  "Distanse" best†r av
                                            //    "ant500" 500-metre.
  int min, sek, hundr;                      //  Tre tider som leses inn.
  float poeng;                              //  Beregnet antall poeng.

  do  {                                     //  Leser inn l›pernes kj›nn:
    cout << "\nSkriv kj›nn (m/k):  ";
    cin >> kjonn;
  } while (kjonn != 'm'  &&  kjonn != 'k'); //  Looper til 'm' eller 'k'.

  if (kjonn == 'k')  {                      //  "kjonn" = 'k':
    do  {                                   //  Looper til lovlig distanse
      cout << "\nDistanse (500, 1500, 3000, 5000):  ";    // er skrevet inn:
      cin >> distanse;
    } while (distanse != 500   &&  distanse != 1500  &&
             distanse != 3000  &&  distanse != 5000);
  } 
  else  {                                   //  "kjonn" = 'm':
    cout << "\nDistanse:  ";                //  Ber om distanse.
    cin >> distanse;
    while (distanse != 500   &&  distanse != 1500  &&      // Looper til
             distanse != 5000  &&  distanse != 10000)  {   // lovlig distanse
      cout << "\nDistanse (500, 1500, 5000, 10000):  ";    // er skrevet inn:
      cin >> distanse;                      
    }
  }

  ant500 = distanse / 500;                  //  Beregner antall 500-metre
                                            //    i distansen.
  cout << setiosflags(ios::fixed)           //  Setter at flyttall alltid
       << setiosflags(ios::showpoint)       //    skal skrives med 3 desimaler
       << setprecision(3);                  //    (side 274 i læreboka).
                     
  cout << "\n\nTid (mm  ss  hh):  ";        
  cin >> min;                               //  Leser inn kun antall minutter.
  while (min >= 0)  {                       //  S†lenge positivt tall:
    cin >> sek >> hundr;                    //  Leser sekunder og hundredel.
    poeng = ((min*60) + sek + (hundr/100.0F)) / float(ant500);  
    cout << "Poeng:  " << poeng;          //  Beregner og skriver poengsum.
    cout << "\n\n\nTid (mm  ss  hh):  ";
    cin >> min;                             //  Leser nytt antall minutter.
  }
  return 0;
}
