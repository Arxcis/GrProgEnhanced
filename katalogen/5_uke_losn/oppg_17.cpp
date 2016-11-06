//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_17.CPP


//   L›sningsforslag til oppgave nr.17  i   C++ -programmering.


#include <iostream>                    //  cout,  cin
#include <iomanip>                     //  set.....

using namespace std;


struct loper  {                        //  Struct om EN sk›ytel›per.
   int    nr;                          //  Startnummer (1 eller 2).
   int    antPasseringer;              //  Antall passeringer av m†lstreken.
   float  tidHittil;                   //  Tiden brukt hittil (i sekunder) .
}; 


int main()  {
  loper  loper1 = { 1, 0, 0.0F },      //  Definerer og initialiserer to
         loper2 = { 2, 0, 0.0F },      //    variable. 
         temp;                         //  Hjelpevariabel.
  int    distanse;                     //  Inneholder en lovlig distanse.
  int    totAntPasseringer;            //  Antall passeringer av m†lstreken
                                       //    i l›pet av "distanse".
  int    loperNr;                      //  Aktuelt l›pernr (1 eller 2)
  int    min, sek, hundr;              //  Passeringstidspunktet.
  float  tid;                          //  Tiden omregnet i sekunder.
  char   svar;                         //  Fortsette ? ('j' eller 'n').


  cout << setiosflags(ios::fixed)      // Setter opp at tidsforskjellen 
       << setiosflags(ios::showpoint)  //    skal vises med 2 desimaler
	   << setprecision(2);			   //    (side 272-273 i læreboka).


  do  {                             // Ber om og leser en korrekt distanse:
    cout << "Distanse (500, 1000, 1500, 3000, 5000, 10000):  ";
    cin >> distanse;
  } while(distanse !=  500  &&  distanse !=  1000  &&
          distanse != 1500  &&  distanse !=  3000  &&
          distanse != 5000  &&  distanse != 10000);

                                       //  Finner ut antall passeringer
  totAntPasseringer = distanse / 400;  //   av m†lstreken.

  if (distanse % 400  !=  0)           //  Dersom ikke et heltallig multiplum
     ++totAntPasseringer;              //    av 400, s† passeres m†lstreken   
                                       //    enda en gang. 

  do  {                                //  S†lenge nye par:

    loper1.antPasseringer = 0;        //  Nullstiller relevante variable:
    loper1.tidHittil = 0.0F;
    loper2.antPasseringer = 0;
    loper2.tidHittil = 0.0F;
                                       //  S†lenge begge to IKKE i m†l:
    while (loper1.antPasseringer < totAntPasseringer  ||
           loper2.antPasseringer < totAntPasseringer)  {

       do  {                           //  Leser aktuelt og korrekt l›pernr:
          cout << "\n\nPassering av l›per nummer (1-2):  ";
          cin >> loperNr;
       } while(loperNr < 1  ||  loperNr > 2);
                                       //  Kopierer aktuell l›per over:
       temp = (loperNr == 1)  ?  loper1  :  loper2;
                                       //  L›peren ikke i m†l allerede:
       if (temp.antPasseringer < totAntPasseringer)  {
          do  {                        //  Leser ny korrekt tid for l›peren:
            cout << "Passeringstid (mm ss hh):         ";
            cin >>  min  >>  sek  >>  hundr;
            tid = min * 60  +  sek  +  hundr/100.0F;
          } while (  min < 0  ||  min > 20  ||
                     sek < 0  ||  sek > 59  ||
                   hundr < 0  || hundr > 99 ||
                     tid < temp.tidHittil + 8 );
                                       //  Beregner rundetiden:
          cout << "\t\tSiste rundetid:   "  <<  tid - temp.tidHittil;

          temp.tidHittil = tid;        //  Oppdaterer med ny passeringstid.
          ++temp.antPasseringer;       //  Teller opp antall passeringer.
                                       //  Dersom kommer i m†l:
          if (temp.antPasseringer == totAntPasseringer)
             cout << "\t\tMLPASSERING !!";

          if (loperNr == 1)            //  Kopierer tilbake fra arbeids-
             loper1 = temp;            //     variabel til aktuell variabel.
          else
             loper2 = temp;

       }  else                         //  L›peren har allerede kommet i m†l:
       cout << "\nLPEREN ER ALLEREDE I ML !\n";
    }

                                       //  Finner den som vant paret:
    if (loper1.tidHittil < loper2.tidHittil)  {           //  L›per nr.1:
       cout << "\n\n\nL›per nr.1 ble parvinner";
       tid = loper1.tidHittil;
    } else if (loper2.tidHittil < loper1.tidHittil)  {    //  L›per nr.2:
       cout << "\n\n\nL›per nr.2 ble parvinner";
       tid = loper2.tidHittil;
    }  else  {                                              //  Likt i m†l:
       cout << "\n\n\nBegge kom likt i m†l";
       tid = loper1.tidHittil;
    }
    cout << ", med tiden:  ";          //  Omregner vinnertid til minutter,
    min = int(tid / 60);               //     sekunder og hundredel.
    sek = int(tid - (min * 60));
    hundr = int((tid - ((min * 60) + sek)) * 100);
    cout << min << ":" << sek << ":" << hundr;

                                       // Ber om og leser inn om flere par:
    cout << "\n\n\nFlere par (J/n):  ";
    cin >> svar;
  } while(svar != 'N'  &&  svar != 'n');
  return 0;
}
