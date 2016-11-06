//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_26.CPP


//   L›sningsforslag til oppgave nr.26  i   C++ -programmering.


#include <iostream>                    //  cout, cin
#include <fstream>                     //  ifstream, ofstream
#include <iomanip>                     //  set....
#include <cctype>                      //  toupper

using namespace std;


const int   MAXVARER = 100;            //  Max. antall varer i datastrukturen.
const int   STRLEN   =  40;            //  Lengde p† innleste strenger.
const int   MAXANT  = 10000;           //  Max. antall av en vare.
const float MAXPRI  = 50000.0F;        //  Max. pris p† en vare.


float  lesVerdi(char tekst[], float MAX, float MIN = 0);  //  Pkt.9

class Vare  {                          //  Vare-objekt:
  private:
    char navn[STRLEN];                 //  Varens navn.
    int  antall;                       //  Antallet man har p† lager av varen.
    float pris;                        //  Varens pris.

  public:
    void lesData()  {                  //  Leser inn data om varen:
      cout << "\n\tVarenavn:      ";              //  Navnet:
      cin.getline(navn, STRLEN);
      antall = int(lesVerdi("Antall", MAXANT));   //  Antall og pris:
      pris   = lesVerdi("Pris", MAXPRI);
    }

    void skrivData(int n)  {           //  Skriver alle data om varen:
      cout << '\t' << setw(3) << n    << setw(8) << antall
           << setw(8) << pris << '\t'    << navn << '\n';
    }

    float verdi()  {                   
      return  (pris * antall);         //  Returnerer varens totale verdi.
    }

    void selg()  {                     //  Selger/reduserer antallet av varen:
      int ant;                         //  Leser antallet som skal selges:
      ant = int(lesVerdi("Selge antall", antall));  
      antall -= ant;                   //  Reduserer med "ant" stk.
      cout << "\n\tVaren er redusert med " << ant << " til " << antall << '\n';
    }
                                       
    void lesFraFil(ifstream & inn, int ant)  {  // Leser inn sine data fra fil:
      antall = ant;                            // Lagrer unna inn-parameteren.
      inn >> pris;  inn.ignore();              // Leser pris og ETT blankt tegn.
      inn.getline(navn, STRLEN);               // Leser resten av linjen.
    }

    void skrivTilFil(ofstream & ut)  {  //  Skriver alle sine data til fil:
       ut << antall << ' ' << pris << ' ' << navn << '\n';
    }
};


Vare varer[MAXVARER];                  //  Array med vare-objekter.
int  sisteBrukt = 0;                   //  Siste brukte objekt i "varer".


void  skrivMeny();                     //  Pkt.3
char  lesKommando();                   //  Pkt.4
void  nyVare();                        //  Pkt.5
void  oversikt();                      //  Pkt.6
void  selgVare();                      //  Pkt.7
void  fjernVare();                     //  Pkt.8
void  lesFraFil();                     //  EXTRA
void  skrivTilFil();                   //  EXTRA


int main()  {
   char kommando;
   cout << setiosflags(ios::fixed) << setprecision(0);
   lesFraFil();                        //  EXTRA: IKKE bedt om i oppgaven.

   skrivMeny();                        //  Pkt.2:
   kommando = lesKommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'N':  nyVare();    break;  //  N = registrer ny vare.
       case 'F':  fjernVare(); break;  //  F = fjern en vare fra lager.
       case 'S':  selgVare();  break;  //  S = selg 'x' stk. av vare.
       case 'O':  oversikt();  break;  //  O = oversikt over varelager.
       default:   skrivMeny(); break;  //  Ikke-eksisterende menyvalg.
     }
     kommando = lesKommando();
   }
   skrivTilFil();                      //  EXTRA: IKKE bedt om i oppgaven.
   cout << "\n\n";
   return 0;
}


		   //  Pkt.9: Leser et tall i aktuelt intervall:
float  lesVerdi(char tekst[], const float MAX, const float MIN)  {
  float tall;

  do {
    cout << '\t' << tekst << " (" << MIN << "-" << MAX << "):  ";
    cin >> tall;
  } while (tall < MIN  ||  tall > MAX);
  return tall;
}


		   //  Pkt.3: Funksjon som presenterer lovlige menyvalg:
void skrivMeny()  {
  cout << "\n\nFLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tN = registrer ny vare\n";
  cout << "\tF = fjern en vare\n";
  cout << "\tS = selg 'x' stk. av en vare\n";
  cout << "\tO = oversikt over varelageret\n";
  cout << "\tQ = quit/avslutt\n";
}


		   //  Pkt.4: Funksjon som ber om ett tegn ulikt blank:
char lesKommando()  {
  char ch;
  cout << "\n\nOppgi ›nske:  ";
  cin >> ch;    cin.ignore();
  return toupper(ch);
}


		   //  Pkt.5: Funksjon som (om fortsatt plass igjen) leser
		   //         og registrerer en ny vare i varelageret:
void nyVare()  {

   if (sisteBrukt < MAXVARER-1)  {     //  Fortsatt plass:
     ++sisteBrukt;                     //  Tar i bruk neste objekt.
     cout << "\n\nREGISTRERER NY VARE NR." << sisteBrukt << ": .....\n";
     varer[sisteBrukt].lesData();      //  Ber det selv lese inn sine data.
     cout << "\nAlt om den nye varen er n† ferdig registrert.\n";
   }
   else                                //  Ikke mere plass igjen i varelageret:
     cout << "\nVarelageret er FULLT med " << MAXVARER << " varer allerede.\n";
}



		   //  Pkt.6:  Viser alle data om HELE varelageret:
void oversikt()  {
  float totalVerdi = 0.0F;
  char ch;
  int i;

  if (sisteBrukt > 0)  {            //  Noen vare(r) er registrert.
     cout << "\n\n\tVARELAGERET INNEHOLDER FLGENDE VARER:\n";
     cout << "\n\t Nr.  Antall   Pris\tNavn\n";
     cout << setiosflags(ios::showpoint)  <<  setprecision(2);

     for (i = 1;  i <= sisteBrukt;  ++i)  {   //  G†r gjennom alle varene:
         varer[i].skrivData(i);               //  Hver skriver sine data selv.
         totalVerdi += varer[i].verdi();      //  Beregner totalverdi.
         if ((i % 20) == 0)  {                //  Stanser for hver 20. vare:
            cout << "\t\t\t\t\t\tSkriv ett tegn og ENTER/CR .....\n";
            cin >> ch;
         }
     }                                        //  Varelagerets total verdi:
     cout << "\n\tTotalverdi for varelageret:  " << totalVerdi << '\n';
     cout << resetiosflags(ios::showpoint)  <<  setprecision(0);
  } else
    cout << "\n\nVarelageret er TOMT, derfor umulig † lage en oversikt.\n";
}


			//  Pkt.7:  Funksjon som (om mulig) trekker "ant"
            //          varer fra p† totalantallet for en vare:
void selgVare()  {
   int nr;

   if (sisteBrukt > 0)  {           //  Noen vare(r) er registrert:
      cout << "\n\nSELG EN VARE .....\n";
      nr = int(lesVerdi("Varenummer", sisteBrukt));
      if (nr != 0)                  //  Relevant varenummer:
         varer[nr].selg();          //  Ber da varen om † selge et antall.
   }
   else
      cout << "\nVarelageret er TOMT, derfor umulig † selge noen vare !\n";
}


			   //  Pkt.8: Fjerner en vare fra lageret:
void fjernVare()  {
   int nr;

   if (sisteBrukt > 0)  {           //  Noen vare(r) er registrert:
      cout << "\n\nFJERN EN VARE .....\n";
      nr = int(lesVerdi("Varenummer", sisteBrukt));  //  Leser varenummeret.

      if (nr != 0)  {               //  Relevant varenummer:
         varer[nr] = varer[sisteBrukt];    //  Kopierer siste vare inn
                                            //    der slettet vare l†.
         --sisteBrukt;                     //  "Fjerner" siste vare.
         cout << "\nVare nr." << nr << " er n† fjernet.";
      }
   }
   else
      cout << "\nVarelageret er TOMT, derfor umulig † fjerne noen vare !";  
}


            //  EXTRA:  Lese datastrukturen fra fil:
void  lesFraFil()  {
  ifstream innfil("oppg_26.dta");     //  pner aktuell fil for lesing.
  int ant;                            //  Hjelpevariabel.

  sisteBrukt = 0;                     //  Initierer/nullstiller.
  if (innfil)  {                      //  Filen finnes:
     innfil >> ant;                   //  Leser (om mulig) starten p† neste.
     while (!innfil.eof()  &&  sisteBrukt < MAXVARER-1)  { // Mer og ikke fullt:
       varer[++sisteBrukt].lesFraFil(innfil, ant); //  Objekt leser selv.
       innfil >> ant;                 //  Leser (om mulig) starten p† neste.
     }
  } else cout << "\nFinner ikke filen 'OPPG_26.DTA'.\n\n";
}


            //  EXTRA:  Skrive datastrukturen til fil:
void  skrivTilFil()  {
  ofstream utfil("oppg_26.dta");      //  pner aktuell fil for skriving.
  cout << "\n\nSkriver dataene til filen 'OPPG_26.DTA'.....\n";
  for (int i = 1;  i <= sisteBrukt;  i++)  //  G†r gjennom alle objektene:
      varer[i].skrivTilFil(utfil);         //  Ber hver skrive ut seg selv.
}
