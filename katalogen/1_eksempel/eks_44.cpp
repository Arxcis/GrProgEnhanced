//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_44.CPP

//   Programeksempel nr.44 for forelesning i  C++ -programmering.

//   "Oppsummerende" eksempel fra kap.6 (klasser/objekter) med bruk av:
//       constructor'er, private data og funksjoner som:
//            - er public
//            - er definert inni (inline) og utenfor klassen (vha."::")
//            - ikke tar parametre
//            - tar parametre    (ogsÜ objekter)
//            - returnerer verdi (ogsÜ objekter)
//       samt generelle funksjoner som (sammen med "main") 
//       hÜndterer/opererer pÜ objektene.
//
//    NB: Dette er EKS_43 omskrevet til bruk av objekter istedet for
//        struct'er og funksjoner som opererer pÜ disse.


#include <iostream>     //  cin, cout
#include <cctype>       //  toupper

using namespace std;

                        //  Inneholder data om EN brõk og funksjoner for Ü
class Brok  {           //    arbeide med / endre pÜ / avlese / beregne den:
private:                //  Private/skjulte/utilgjengelige data utenfra:
	int teller;         //  Brõkens teller (over brõkstreken).
	int nevner;         //  Brõkens nevner (under brõkstreken).

public:					//  Offentlige/Üpne/tilgengelige funksjoner utenfra:
						//  3x constructor'er som initialiserer medlemmene:
	Brok()              { teller = 0;  nevner = 1; }
	Brok(int t)         { teller = t;  nevner = 1; }  // Ikke brukt!
	Brok(int t, int n)  { teller = t;  nevner = n; }

	void lesInn()  {   //  Leser inn teller og nevner for brõken:
		char ch;       //  Dummy-variabel for Ü lese '/'.
		cin >> teller; //  Leser inn brõkens teller.
		cin >> ch;     //  Leser skilletegnet ('/').
		cin >> nevner; //  Leser inn brõkens nevner.
	}

	void skriv()      //  Skriver brõken pÜ/til skjermen:
	{
		cout << teller << '/' << nevner;
	}
	//  Man kan forkorte brõken (finne stõrste felles divisor) ved Ü bruke
	//  den komplette koden gitt i Ex.6-11 s.262 i lëreboka.

	float desimalt()  //  Omgjõr (og returnerer) brõken desimalt:
	{
		return (float(teller) / nevner);
	}

								//  Summerer/adderer brõken med en annen:
	Brok sum(const Brok b)  {            //  =  (t1*n2 + t2*n1) / (n1*n2)
		Brok brok;							//  Lager ny "tom"/nullstilt brõk.
		brok.teller = teller * b.nevner + b.teller * nevner; // Finner teller.
		brok.nevner = nevner * b.nevner;	//  Finner nevner.
		return brok;						//  Returnerer brõken.
	}
								//  Subtraherer/trekker en annen fra brõken:
	Brok diff(const Brok b)  {           // =  (t1*n2 - t2*n1) / (n1*n2)
		int tell = teller * b.nevner - b.teller * nevner;    // Finner teller.
		int nevn = nevner * b.nevner;		//  Finner nevner.
		Brok brok(tell, nevn);				//  Lager ny brõk med differansen.
		return brok;						//  Returnerer denne.
	}

								//  Ganger/produktet mellom brõken og en annen:
	Brok prod(const Brok b)  {           // =  (t1*t2) / (n1*n2)
		Brok brok(teller * b.teller, nevner * b.nevner); //Brõk med produktet.
		return brok;						//  Returnerer denne.
	}

								// Deler/divisjon mellom brõken og en annen:
	Brok div(const Brok b)  {   //  = (t1*n2) / (n1*t2)
								//  Lager brõk med svaret og returnerer denne:
		return Brok(teller * b.nevner, nevner * b.teller);
	}

// NB:  I de fire siste funksjonene ovenfor ("sum", "diff", "prod" og "div")
//      er det BEVISST benyttet FIRE ULIKE mÜter Ü:
//          -"gjemme unna" svarets teller og nevner pÜ
//          - opprette en ny "Brok" med svaret og retur av denne.
//      Den siste ("div") er den mest kompakte, og er derfor Ü foretrekke.

      bool erLik(const Brok b)    //  Returnerer om er lik en annen brõk:
        { return (teller == b.teller  &&  nevner == b.nevner);}

      bool erUlik(const Brok b)   //  Returnerer om er ulik en annen brõk:
        { return (teller != b.teller  ||  nevner != b.nevner); }
};


                       //  Inneholder data om ETT tidspunkt og funksjoner for Ü
class Tidspunkt  {     //    arbeide med / endre pÜ / avlese / beregne den:
  private:             //  Private/skjulte/utilgjengelige data utenfra:
    int time,          //  Timer.
        min,           //  Minutter.
        sek;           //  Sekunder.

  public:               //  Offentlige/Üpne/tilgengelige funksjoner utenfra:
      Tidspunkt()  {  time = min = sek = 0;  }
      Tidspunkt(int t, int m, int s)  {  time = t;  min = m;  sek = s;  }
      void hentInn();   //  For disse tre funksjonene er selve DEFINISJONEN 
      void skriv();     //  flyttet til lengre ned i koden/pÜ filen:
      int  antSek();
};


void skrivMeny();
char lesKommando();
void brokregning();    //  Funksjonen som styrer brõkregningen.

void tidspunkt();      //  Funksjonen som styrer tidsregningen.
int  lesInn(const int MAX);
void sorter(Tidspunkt & t1, Tidspunkt & t2);


                       //  HOVEDPROGRAMMET:
int main()  {            //                   HELT IDENTISK TIL EKS_43.CPP:
  char valg;             //  Brukerens valg/õnske/kommando.

  skrivMeny();           //  Skriver/viser bruker-menyen.
  valg = lesKommando();  //  Leser brukerens valg/õnske/kommando.

  while (valg != 'Q')  { //  SÜ lenge ikke avslutte:
    switch (valg)  {
      case 'B':  brokregning();  break;
      case 'T':  tidspunkt();    break;
      default:   skrivMeny();   break;
    }
    valg = lesKommando(); //  Leser igjen brukerens valg/õnske/kommando.
  }
  cout << "\n\n";
  return 0;
}

                             //              HELT IDENTISK TIL EKS_43.CPP:
void skrivMeny()  {          //  Skriver brukerens valg/muligheter/meny:
  cout << "\n\nFõlgende kommandoer er aktuelle:\n";
  cout << "\tB   - Brõker\n";
  cout << "\tT   - Tidspunkt\n";
  cout << "\tQ   - Quit / avslutt\n";
}

                             //              HELT IDENTISK TIL EKS_43.CPP:
char lesKommando()  {        //  Leser brukerens valg/õnske/kommando:
  char ch;                   //  Innskrevet tegn.
  cout << "\n\nGi kommando (B, T, Q):  ";  //  Ber om ett tegn.
  cin >> ch;    ch = toupper(ch);          //  Leser og upcaser tegn.
  return ch;                 //  Returnerer tegn/kommando.
}



// *********************   B R ù K R E G N I N G :   ********************

void brokregning()  {        //  Hovedfunksjonen som styrer brõkregningen:
  Brok brok1, brok2,         //  To objekter som inneholder brõker.
       svar;                 //  Objektet som er svaret pÜ regnestykket.
  char oper;                 //  Operatoren mellom brõkene.
  bool ok = true;            //  Om gyldig operator er brukt eller ei.

  cout << "\nBrõkregnestykke ( t1/n1 [+, -, *, /] t2/n2 ):  ";
  brok1.lesInn();            //  Den 1.brõken leser inn sine data.
  cin >> oper;               //  Leser operatoren (+, -, *, /) mellom brõkene.
  brok2.lesInn();            //  Den 2.brõken leser inn sine data.

  cout << "\n\n\tBrõkene er ";
  if (brok1.erLik(brok2))   cout << "LIKE!\n";
  if (brok1.erUlik(brok2))  cout << "IKKE LIKE!\n";

  switch(oper)  {            //  Utfõrer regneoperasjon pÜ brõkene alt etter
                             //     hva operatoren mellom dem er:
    case '+': svar = brok1.sum(brok2);   break; // NB! Eller: brok2.sum(brok1)
    case '-': svar = brok1.diff(brok2);  break; // NB! Kan IKKE bytte disse to!
    case '*': svar = brok2.prod(brok1);  break; // NB! Eller: brok1.prod(brok2)
    case '/': svar = brok1.div(brok2);   break; // NB! Kan IKKE bytte disse to!
    default:  ok = false;  cout << "\nUgyldig operator brukt!\n";  break;
  }
  
  if (ok)  {                 //  Operatoren mellom er en av de gyldige:
     cout << "\n\n\t";       //  Skriver begge brõkene og svaret:
     brok1.skriv();   cout << "  " << oper << "  ";
     brok2.skriv();   cout << "  =  ";
     svar.skriv();    cout << "\t(= " << svar.desimalt() << ")\n";
  }
}




// *********************   T I D S P U N K T :   ********************

void Tidspunkt :: hentInn()  {   //  Fyller medlemmene med gyldige verdier:
  cout << "\n\tTime:   ";  time = lesInn(23); 
  cout << "\tMinutt: ";    min  = lesInn(59);
  cout << "\tSekund: ";    sek  = lesInn(59);
}


void Tidspunkt :: skriv()  {      //  Skriver tidspunktet pÜ formen tt:mm:ss :
  cout << ((time < 10) ? "0" : "") << time << ':'   //  Legger evt. til
       << ((min  < 10) ? "0" : "") << min  << ':'   //    innledende
       << ((sek  < 10) ? "0" : "") << sek;  }       //    null ('0'):

int Tidspunkt :: antSek()        //  Gjõr om tidspunktet til sekunder:
  {  return (time*3600 + min*60 + sek);  }



void tidspunkt()  {          //  Hovedfunksjon som styrer tidspunktene:
	                         //  To Tidspunkt-objekter som initieres,
  Tidspunkt tid1(3, 23, 48), tid2(17, 52, 14),
            tid3;            //    og en som brukeren gir verdier til.
  tid3.hentInn();            //  Ber "tid3" lese inn sine egne verdier.
                             //  Ber de tre tidspunktene skrive ut seg selv, 
                             //     ogsÜ deres verdier i kun sekunder:
  cout << "\nTidspunkt nr.1: ";  tid1.skriv();   
                                 cout << "\t#sek: " << tid1.antSek();
  cout << "\nTidspunkt nr.2: ";  tid2.skriv();
                                 cout << "\t#sek: " << tid2.antSek();
  cout << "\nTidspunkt nr.3: ";  tid3.skriv();
                                 cout << "\t#sek: " << tid3.antSek();
  sorter(tid1, tid2);        //  'Tid2' er stõrst hittil.
  sorter(tid2, tid3);        //  'Tid3' ER den aller stõrste.
  sorter(tid1, tid2);        //  'Tid2' ER den nest stõrste.
  cout << "\n\nTidspunktene skrevet i õkende rekkefõlge:\n\t";
  tid1.skriv();  cout << '\t';   //  Skriver ut de sorterte objektene:
  tid2.skriv();  cout << '\t';  
  tid3.skriv();  cout << '\n';
}

                             //              HELT IDENTISK TIL EKS_43.CPP:
                                //  Leser inn og returnerer verdi i
int lesInn(const int MAX)  {    //  intervallet 0 til MAX.    
  int tall;                     //  Innskrevet tallverdi.
  cin >> tall;                  //  Leser tall.
  while (tall < 0  ||  tall > MAX)  {    //  Utenfor gyldig intervall:
     cout << "\ti intervallet (0-" << MAX << "):  ";
     cin >> tall;
  }
  return tall;                  //  Returnerer akseptert (gyldig) tall
}

                             //              NESTEN IDENTISK TIL EKS_43.CPP:
                                   //  Bytter om (om nõdvendig) slik at 't2'
                                   //     ALLTID er stõrre eller lik 't1':
void sorter(Tidspunkt & t1, Tidspunkt & t2)  {
  int ts1 = t1.antSek(),           //  Henter t1 og t2 sine antall sekunder:
      ts2 = t2.antSek();
  Tidspunkt temp;                  //  Hjelpevariabel for Ü kopiere.

  if (ts1 > ts2)  {                //  't1' er stõrst:
     temp = t1;                    //  Bytter om 't1' og 't2':
     t1 = t2;
     t2 = temp;
  }
}
