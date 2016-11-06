//  Fil:  FAG_KURS \ 1EA \ EXAMEN \ EX_H97.CPP


//  L›sningsforslag til eksamen i C++ (1EA), h›sten 1997.
//  Laget av Frode Haug, HIG, h›sten 1997.


//  Programmet har innlagt noen land og deres valutabetegnelse.
//  Programmet sp›r brukeren som dagens valutakurser.
//  Deretter kan brukeren utf›re f›lgende operasjoner:
//     - omregne fra norske kroner til en utenlandsk/fremmed valuta.
//     - omregne fra en utenlandsk/fremmed valuta til en annen.
//     - endre kurs for en valuta.


			//  INCLUDE:
#include <iostream>          //  cout, cin
#include <cstring>           //  strcpy, strcmp
#include <cctype>            //  toupper

using namespace std;

			//  CONST:
const int NVN_LEN   = 30;    //  Max.lengde for et lands navn.
const int KORT_LEN  =  4;    //  Max.lengde for en valuta-betegnelse.
const int ANT_LAND  = 14;    //  Antall ulike land/valutaer i programmet.

			//  STRUCT:
struct Valuta  {                //  Struct'en for en valuta:
  char  landsnavn[NVN_LEN];     //    Landets navn.
  char  betegnelse[KORT_LEN];   //    Valuta-betegnelse.
  float kurs;                   //    Aktuell kurs.
};

			//  DEKLARASJON AV PROSEDYRER:
int   finn_indeks(const char beteg[]);
void  les_navn(const char text[], char nvn[]);
float les_tall(const char text[]);
void  skriv_meny();
void  initier_navn();
void  les_kurs();
void  norsk_til_fremmed();
void  fremmed1_til_fremmed2();
void  endre_kurs();

			//  GLOBALE VARIABLE:
Valuta valutaer[ANT_LAND+1];    //  Array med struct'er, en for hvert land.


                        //  HOVEDPROGRAM:
int main()  {
  char kommando;

  initier_navn();            //  Setter opp landenes navn og valuta-betegnelse.
  les_kurs();                //  Leser landenes aktuelle kurs (fra tastaturet).

  skriv_meny();
  cout << "\n\nGi kommando:  ";  cin >> kommando;
  kommando = toupper(kommando);

  while (kommando != 'Q')  {
    switch (kommando)  {
      case 'N':  norsk_til_fremmed();       break;
      case 'F':  fremmed1_til_fremmed2();   break;
      case 'K':  endre_kurs();	            break;
      default :  skriv_meny();              break;
    }
    cout << "\n\nGi kommando:  ";  cin >> kommando;
    kommando = toupper(kommando);
  }
  return 0;
}

			//  DEFINISJON AV PROSEDYRER:
                                   //  Finner (om mulig) indeks for betegnelse.
int finn_indeks(const char beteg[])  {
  for (int i = 1;  i <= ANT_LAND;  i++)  // Leter gjennom landene etter "beteg".
      if (strcmp(beteg, valutaer[i].betegnelse) == 0)  return i;  //  Funn.
  return 0;                        //  Ikke funnet.
}

				   //  Leser inn en valuta-betegnelse.
void les_navn(const char text[], char nvn[])  {
  cout << "\n" << text << ":  ";
  cin >> nvn;
}

				   //  Leser inn et positivt tall.
float les_tall(const char text[])  {
  float tall;
  do  {
    cout << '\n' << text << ":  ";
    cin >> tall;
  }  while (tall < 0);
  return tall;
}


void skriv_meny() {
  cout << "\n\n\nFLGENDE KOMMANDOER ER TILGJENGELIGE:";
  cout << "\n\tN - Omregning fra Norske kroner til en utenlandsk";
  cout << "\n\tF - Omregning fra en utenlandsk/Fremmed til en annen";
  cout << "\n\tK - endring av en Kurs";
  cout << "\n\tQ - Quit/avslutt";
}

                                   //  Setter opp landenes navn og betegnelse.
void initier_navn()  {                              // Kurser pr.8/12-97:
  strcpy(valutaer[1].landsnavn,   "Sverige");
  strcpy(valutaer[1].betegnelse, "SEK");            //    92.26    (0.9226)
  strcpy(valutaer[2].landsnavn,   "Danmark");
  strcpy(valutaer[2].betegnelse, "DKK");            //   106.34    (1.0634)
  strcpy(valutaer[3].landsnavn,   "Finland");
  strcpy(valutaer[3].betegnelse, "FIM");            //   133.92    (1.3392)
  strcpy(valutaer[4].landsnavn,   "USA");
  strcpy(valutaer[4].betegnelse, "USD");            //     7.1780  (7.1780)
  strcpy(valutaer[5].landsnavn,   "Storbritannia");
  strcpy(valutaer[5].betegnelse, "GBP");            //    11.928   (11.928)
  strcpy(valutaer[6].landsnavn,   "Belgia");
  strcpy(valutaer[6].betegnelse, "BEF");            //    19.624   (0.19624)
  strcpy(valutaer[7].landsnavn,   "Spania");
  strcpy(valutaer[7].betegnelse, "ESP");            //     4.790   (0.04790)
  strcpy(valutaer[8].landsnavn,   "Hellas");
  strcpy(valutaer[8].betegnelse, "GRD");            //     2.58    (0.0258)
  strcpy(valutaer[9].landsnavn,   "Tyskland");
  strcpy(valutaer[9].betegnelse, "DEM");            //   404.85    (4.0485)
  strcpy(valutaer[10].landsnavn,   "Sveits");
  strcpy(valutaer[10].betegnelse, "CHF");           //   501.26    (5.0126)
  strcpy(valutaer[11].landsnavn,   "Japan");
  strcpy(valutaer[11].betegnelse, "JPY");           //     5.5557  (0.05557)
  strcpy(valutaer[12].landsnavn,   "Italia");
  strcpy(valutaer[12].betegnelse, "ITL");           //     0.4130  (0.004130)
  strcpy(valutaer[13].landsnavn,   "Frankrike");
  strcpy(valutaer[13].betegnelse, "FRF");           //   120.96    (1.2096)
  strcpy(valutaer[14].landsnavn,   "Nederland");
  strcpy(valutaer[14].betegnelse, "NLG");           //   359.28    (3.5928)
}


void les_kurs()  {            //  Leser inn aktuelle kurser (fra tastaturet).
  cout << "\n\nHva er kursen for:";
  for (int i = 1;  i <= ANT_LAND;  i++)
      valutaer[i].kurs = les_tall(valutaer[i].betegnelse);
}


void norsk_til_fremmed()  {   // Regner om norske kroner til utenlandsk valuta.
  int nr;
  float nkr;
  char beteg[KORT_LEN];

  les_navn("\nnsker † veksle til valutaen", beteg); // Leser valuta-betegnelse.
  nr = finn_indeks(beteg);    //  Finner (om mulig) indeksen.
  if (nr > 0)  {              //  Indeksen funnet:
     nkr = les_tall("\tAntall NORSKE kroner du ›nsker † veksle");
     cout << "\n\tFor " << nkr << " norske kroner f†r du "
	  << nkr/valutaer[nr].kurs << ' ' << beteg << '.';  //  Beregner.
  } else
    cout << "\n\t'" << beteg << "' er en ulovlig valuta-betegnelse!";
}


void fremmed1_til_fremmed2()  {   //  Regner om mellom to utenlandske valutaer.
  int nr1, nr2;
  float belop1;
  char beteg1[KORT_LEN], beteg2[KORT_LEN];

  les_navn("\nnsker † veksle FRA valutaen", beteg1); //Leser valuta-betegnelse.
  nr1 = finn_indeks(beteg1);  //  Finner (om mulig) indeks nr.1.
  if (nr1 > 0)  {             //  Indeks nr.1 er funnet:
     les_navn("nsker † veksle TIL valutaen", beteg2);//Leser valuta-betegnelse.
     nr2 = finn_indeks(beteg2);  //  Finner (om mulig) indeks nr.2.
     if (nr2 > 0)  {             //  Indeks nr.2 er funnet:
	belop1 = les_tall("\tAntallet du ›nsker † veksle inn");
	cout << "\n\tFor " << belop1 << ' ' << beteg1 << " f†r du " // Beregner.
	     << (belop1*valutaer[nr1].kurs)/valutaer[nr2].kurs << ' ' << beteg2;
     } else
       cout << "\n\t'" << beteg2 << "' er en ulovlig valuta-betegnelse!";
  } else
    cout << "\n\t'" << beteg1 << "' er en ulovlig valuta-betegnelse!";
}


void endre_kurs()  {              //  Endrer kursen for en valuta.
  int  nr;
  char beteg[KORT_LEN];

  les_navn("Endre kursen for valutaen", beteg);  // Leser valuta-betegnelse.
  nr = finn_indeks(beteg);                   //  Finner (om mulig) indeksen.
  if (nr > 0)  {                             //  Indeksen funnet.
     cout << "\nGammel kurs: " << valutaer[nr].kurs;
     valutaer[nr].kurs = les_tall("Ny kurs");  //  Endrer kursen.
  } else
    cout << "\n\t'" << beteg << "' er en ulovlig valuta-betegnelse!";
}
