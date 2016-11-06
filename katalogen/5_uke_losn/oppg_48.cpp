//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_48.CPP

//   L›sningsforslag til oppgave nr.48  i   C++ -programmering.


//   Programmet leser inn og skriver ut posisjonen 
//   (bredde- og lengdegrad) for tre ulike skip.
//   (Basert p† Ex.10 i kap.6 s.261 i l‘reboka.)


#include <iostream>          //  cout, cin
#include <cctype>            //  toupper
using namespace std;

class Posisjon  {            //  Klassen "Posisjon":
   private:
      int  grad;             //  Grad (0-90 eller 0-180).
      int  min;              //  Minutter (0-59).
      int  sek;              //  Sekunder (0-59).
      char retning;          //  N/S  eller  E/W.

                             //  Leser inn verdi/tall mellom 'min' og 'max':
      int les(int min, int max)  {
        int tall;            //  Hjelpevariabel.
        do  {
          cout << "\tverdi (" << min << '-' << max << "):  ";  cin >> tall;
        } while (tall < min || tall > max);  //  Looper til i rett intervall.
        return tall;         //  Returnerer innlest og lovlig verdi.
      }

   public:                   //  Initierer/nullstiller 4x datamedlemmer:
      Posisjon()  { grad = 0;  min = sek = 0.0F;  retning = 'X';  } 

      Posisjon(int gr, float mi, float se, char re)  //  Lik 4x parametre:
        {  grad = gr;  min = mi;  sek = se;  retning = re;  }

                             //  Leser inn 4x LOVLIGE verdier/datamedlemmer:
      void les(int gr, char r1, char r2)  {
        cout << "grad: ";       grad = les(0, gr); // Bruker privat funksjon:
        cout << "Minutter: ";   min  = les(0, 59);
        cout << "Sekunder: ";   sek  = les(0, 59);
        do  {               //  Sikrer at retninger er lovlig (NS eller EW:
          cout << "Retning (" << r1 << ',' << r2 << "):  ";  
          cin >> retning;  retning = toupper(retning);  // Leser og upcaser.
        } while (retning != r1  &&  retning != r2);
      }

      void skriv()  {               // Skriver p† formen: XºX'X" X
        cout << grad << char(248)   //  = grad-symbol, evt. nr.167(?)
             << min << '\'' << sek << '\"' << ' ' << retning;
      }
};


class Skip  {                //  Klassen "Skip":
   private:
      Posisjon breddegrad;        //  Skipets posisjon i breddegrad (0-90 N/S)
      Posisjon lengdegrad;        //    og lengdegrad (1-180 E/W).
      int      nr;                //  Skipets (unike) ID/nummer.

   public:
      Skip(int n)  { nr = n;  }   //  Setter dets (unike) ID/nummer.

      void les()  {               //  Leser inn eksakt posisjon:
        cout << "\nBredde";  breddegrad.les(90,  'N', 'S');
        cout << "\nLengde";  lengdegrad.les(180, 'E', 'W');
      }

      void skriv()  {             //  Skriver alle skipets data:
        cout << "\nSkipets nr: " << nr
             << "\tbreddegrad: ";  breddegrad.skriv();
        cout << "\tlengdegrad: ";  lengdegrad.skriv();
      }
};


int main()  {             //  Lager 3x skips-objekter, gir dem ID/nummer:
  Skip MorningStar(71), BalticQueen(94), SongOfSurinam(312);
                          //  Leser inn data om alle 3x skip:
  cout << "\n\nPosisjon for Morning Star:";
  MorningStar.les();
  cout << "\n\nPosisjon for Baltic Queen:";
  BalticQueen.les();
  cout << "\n\nPosisjon for Song of Surinam:";
  SongOfSurinam.les();
                          //  Skriver ut data om alle 3x skip:
  cout << "\n\nMorning Star: ";
  MorningStar.skriv();
  cout << "\n\nBaltic Queen: ";
  BalticQueen.skriv();
  cout << "\n\nSong of Surinam: ";
  SongOfSurinam.skriv();

  cout << "\n\n";
  return 0;
}
