//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_10.CPP

//   Programeksempel nr.10 for forelesning i  C++ -programmering. 

//   Viser bruken av: struct, nestede struct og enum.


#include <iostream>

using namespace std;


enum Ukedag { man, tirs, ons, tors, fre, lor, son, alle };


struct Klokkeslett  {
  int time, minutt;
}; 


struct Sending  {
  Klokkeslett start, slutt;
  int         kanal;
  Ukedag      dag;
};


int main()  {
  Sending NyheterTV2  = { { 18, 30}, { 19,  0}, 2, alle};   //  Oppsett av
  Sending NyheterNRK1 = { { 19,  0}, { 19, 30}, 1, alle};   //    ulike
  Sending SportenTV2;                                       //    TV-program.
  int dagnr;                                                //  Hjelpevariabel.

                             //  Leser inn data om "SportenTV2":
  cout << "\nSportenTV2:\n\tStarter (<time> <minutt>):          ";  
    cin >> SportenTV2.start.time;
    cin >> SportenTV2.start.minutt;
  cout << "\tSlutter (<time> <minutt>):          ";  
    cin >> SportenTV2.slutt.time;
    cin >> SportenTV2.slutt.minutt;
  cout << "\tP† kanal nr:                        ";  
    cin >> SportenTV2.kanal;
  cout << "\tUkedag (Man=1, ..., S›n=7, Alle=8): ";  
   cin >> dagnr;             //  Leser ukedagsnummeret (1-8?).

  switch (dagnr)  {          //  Setter enum-verdi ut fra "dagnr":
    case 1:  SportenTV2.dag = man;     break;
    case 2:  SportenTV2.dag = tirs;    break;
    case 3:  SportenTV2.dag = ons;     break;
    case 4:  SportenTV2.dag = tors;    break;
    case 5:  SportenTV2.dag = fre;     break;
    case 6:  SportenTV2.dag = lor;     break;
    case 7:  SportenTV2.dag = son;     break;
    case 8:  SportenTV2.dag = alle;    break;
    default: cout << "\n\tDu har tastet et ulovlig dagnummer!";
             SportenTV2.dag = alle;    break;
  }

                             //  Skriver alle dataene om "SportenTV2":
  cout << "\n\nSportenTV2:"
       << "\n\tStarter kl." << SportenTV2.start.time << ':';
  if (SportenTV2.start.minutt < 10)  cout << '0';  //  Alltid 00, 01, ..59
       cout << SportenTV2.start.minutt;
  cout << "\n\tSlutter kl." << SportenTV2.slutt.time << ':';
  if (SportenTV2.slutt.minutt < 10)  cout << '0';  //  Alltid 00, 01, ..59
       cout << SportenTV2.slutt.minutt;
  cout << "\n\tP† kanal:    "    << SportenTV2.kanal;
  cout << "\n\tP† ukedagen: ";

                             //  Skriver dagnavn ut fra enum-verdi:
  switch (SportenTV2.dag)  {
    case man:   cout << "Man";  break;
    case tirs:  cout << "Tirs"; break;
    case ons:   cout << "Ons";  break;
    case tors:  cout << "Tors"; break;
    case fre:   cout << "Fre";  break;
    case lor:   cout << "L›r";  break;
    case son:   cout << "S›n";  break;
    case alle:  cout << "Alle"; break;
  }
  if (SportenTV2.dag <= son)  cout << "dag";     //  Om ukedag: skriver "dag".


                             //  Beregner og skriver "SportenTV2" varighet:
  cout << "\n\nSportenTV2 varer i " 
       << ((SportenTV2.slutt.time*60 + SportenTV2.slutt.minutt) -
           (SportenTV2.start.time*60 + SportenTV2.start.minutt))
       << " minutter.";


                             //  Finner ut hvilken nyhetssending som er f›rst:
  if (NyheterTV2.start.time < NyheterNRK1.start.time)          //  TV2 f›rst:
     cout << "\n\n\nTV2-nyhetene starter FR NRK1-nyhetene.\n";
  else if (NyheterTV2.start.time > NyheterNRK1.start.time)     //  NRK1 f›rst:
     cout << "\n\n\nNRK1-nyhetene starter FR TV2-nyhetene.\n";
  else  {                                                      //  Samme time:
     if (NyheterTV2.start.minutt < NyheterNRK1.start.minutt)   //  TV2 f›rst:
        cout << "\n\n\nTV2-nyhetene starter FR NRK1-nyhetene.\n";
     else if (NyheterTV2.start.minutt > NyheterNRK1.start.minutt) // NRK1 f›rst:
        cout << "\n\n\nNRK1-nyhetene starter FR TV2-nyhetene.\n";
     else                                         // Nyhetene starter HELT likt:
        cout << "\n\n\nNRK1- og TV2-nyhetene starter LIKT.\n";
  }
  cout << "\n\n";
  return 0;
}
