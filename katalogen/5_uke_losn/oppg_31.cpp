//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_31.CPP


//   L›sningsforslag til oppgave nr.31  i   C++ -programmering.


//   Leser v‘rdata fra filen "METROLOG.DTA" og
//   beregner noen "statistiske" verdier.


#include <fstream>
#include <iostream>

using namespace std;


int main()  {
  int    dagNr, minTemp, maxTemp, nedbor;   //  Tallene p† hver linje i filen
                                            //  Summene av det lest p† filen:
  int    antDager = 0,  totMin = 0,  totMax = 0,  totNedbor = 0;
  int    diffDag, nedborDag;                   //  Dagnr. med st›rste verdier.
  int    diffStorst = -1,  nedborStorst = -1;  //  St›rste verdier hittil.

  ifstream innfil("METROLOG.DTA");             //  Definerer og †pner fil.

  if (innfil)  {
    innfil >> dagNr;                          //  Pr›ver † lese f›rste verdi.
    while (!innfil.eof())  {                  //  S†lenge mere † lese:
      innfil >> minTemp >> maxTemp >> nedbor; //  Leser resten av linja.   
      ++antDager;                             //  Enda en dag innlest. 
      totMin     +=  minTemp;                 //  Beregner totalsummer:  
      totMax     +=  maxTemp;
      totNedbor  +=  nedbor;
      if (nedbor > nedborStorst)  {          //  Dersom ny dag med mest nedb›r:
         nedborStorst = nedbor;
         nedborDag    = dagNr;
	  }

      if ((maxTemp - minTemp)  >  diffStorst)  {    //  Dersom ny dag med
         diffStorst = maxTemp - minTemp;            //  st›rst temp.forskjell:
         diffDag    = dagNr;
	  }
      innfil >> dagNr;                        //  Pr›ver † lese neste dagNr.
	}
                                              //  Utregninger og utskrift:
    cout << "\nGjennomsnittlig minimumstemperatur:   " << totMin/antDager;
    cout << "\nGjennomsnittlig maksimumstemperatur:  " << totMax/antDager;
    cout << "\nGjennomsnittlig nedb›rsmengde:        " << totNedbor/antDager;
    cout << "\nDag nr." << diffDag << " hadde st›rste temperaturforskjell med "
         << diffStorst << " grader.";
    cout << "\nDag nr." << nedborDag << " hadde mest nedb›r med "
         << nedborStorst << " mm.\n\n";
  } else 
	cout << "\n\nKlarer ikke † finne/†pne filen 'METROLOG.DTA' !\n\n";
  return 0;
}

