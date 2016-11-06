//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S16_2.CPP

//  Løsningsforslag til kontinuasjonseksamen i C++, august 2016, oppgave 2.
//  Laget av Frode Haug, NTNU

//  Programmet holder orden på den neste ukens bestillinger/bookinger for
//  en rutebåt sine morgen- og ettermiddagsturer mellom to byer/steder.


					//  INCLUDE:
#include <fstream>				//  ifstream, ofstream
#include <iostream>				//  cin, cout
#include <cstring>				//  strcpy, strlen
#include <cctype>				//  toupper
using namespace std;

					//  CONST:
const int  STRLEN    =  60;		//  Max. tekstlengde.
const int  MAXTURER  =  20;		//  Max. antall turer (5 dager * 4 turer pr.dag).
const int  MAXPASS =    10;		//  Max. antall passasjerer på EN tur.
const char ukedag[5][5]   = { "Man", "Tirs", "Ons", "Tors", "Fre" };
const char rutetid[2][8] =  { "Morgen", "Emiddag" };
const char steder[2][7]   = { "Gjøvik", "Hamar" };


class Tur  {		//  KLASSE:
private:
	char bestiller[MAXPASS+1][STRLEN];	//  Bestillernes navn og (mobil)tfnr.
	int antall;						//  Nåværende antall bestillinger på turen.

public:						//  Deklarasjon/definisjon av medlemsfunksjoner:
	Tur()				{  antall = 0;  }
	void skriv();								//  Oppgave 2A
	void bestill();								//  Oppgave 2B
	void avbestill();							//  Oppgave 2B
	void nullstill();							//  Oppgave 2C
	int  antallLedige()	{ return (MAXPASS - antall); }
	void skrivTilFil(ofstream & ut);			//  Oppgave 2E
	void lesFraFil(ifstream & inn);				//  Oppgave 2F
};

					//  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char les();
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
void SBAN(char valg);				//  Oppgave 2C
void ledigPaaTurer();				//  Oppgave 2D
void skrivTilFil();					//  Oppgave 2E
void lesFraFil();					//  Oppgave 2F
int  lesOgBestemIndeks();			//  Oppgave 2G


					//  GLOBAL VARIABEL:
Tur turer[MAXTURER];			//  Alle bestillinger på båtturer kommende uke.


int main()  {		//  HOVEDPROGRAM:
	char kommando;

	lesFraFil();								//  Oppgave 2F
	skrivMeny();
	cout << "\nØnske:  ";  kommando = les();
	while (kommando != 'Q')  {
		switch (kommando)  {
		case 'S':  
		case 'B':
		case 'A':
		case 'N':  SBAN(kommando);		break;	//  Oppgave 2C
		case 'L':  ledigPaaTurer();		break;	//  Oppgave 2D
		default:   skrivMeny();			break;
		}
		cout << "\nØnske:  ";  kommando = les();
	}
	skrivTilFil();								//  Oppgave 2E
	cout << "\n\n";
	return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

void Tur::skriv()  {		//  Oppgave 2A - Skriver ALT om en tur:
  cout << "\tAntall bestillinger:  " << antall << '\n';
  for (int i = 1; i <= antall; i++)				//  Alle bestillernes navn/tlf:
	  cout << "\t\t" << i << ": " << bestiller[i] << '\n';
}


void Tur::bestill()  {		//  Oppgave 2B - Registrerer (om mulig) bestilling:
	if (antall < MAXPASS)  {
		les("Navn og tlf", bestiller[++antall], STRLEN);
	} else
		cout << "\tTuren er fullbooket med " << MAXPASS << " passasjerer.\n";
}


void Tur::avbestill()  {	//  Oppgave 2B - En booking avbestilles:
	skriv();					//  Flytter den bakerste frem:
	strcpy(bestiller[les("Avbestill nr", 1, antall)], bestiller[antall]);
	antall--;					//  Teller ned antall bestillinger.
}


void Tur::nullstill()  {	//  Oppgave 2C - ALT på EN tur nullstilles:
	for (int i = 1; i <= antall; i++)
		strcpy(bestiller[i], "");		//  Bestillerne fjernes.
	antall = 0;							//  Antallet nullstilles.
}

							//  OPPGAVE 2E - ALT om turen skrives til fil:
void Tur::skrivTilFil(ofstream & ut)  {			
	ut << antall << '\n';				//  Antall bestillinger.
	for (int i = 1; i <= antall; i++)
		ut << bestiller[i] << '\n';		//  Bestillernes navn/tlf.
}

							//  Oppgave 2F - ALT om turen leses fra fil:
void Tur::lesFraFil(ifstream & inn)  {
	inn >> antall;  inn.ignore();			//  Antall bestillinger.
	for (int i = 1; i <= antall; i++)
		inn.getline(bestiller[i], STRLEN);	//  Bestillernes navn/tlf.
}



// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skrivMeny()  {          //  Presenterer lovlige menyvalg:
	cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
	cout << "\tS = Skriv alt om EN tur\n";
	cout << "\tB = Bestill på en tur\n";
	cout << "\tA = Avbestill på en tur\n";
	cout << "\tN = Nullstill EN tur\n";
	cout << "\t    Alle kommandoene ovenfor etterfølges av tre bokstaver:\n";
	cout << "\t\tM(an)  (t)I(rs)  O(ns)  T(ors)  F(re)\n";
	cout << "\t\tM(orgen)  E(ttermiddag)\n";
	cout << "\t\tG(jøvik)  H(amar)\n";
	cout << "\tL = Ledige plasser på ALLE turer\n";
	cout << "\tQ = Quit/avslutt\n";
}


char les()  {			//  Henter ett ikke-blankt upcaset tegn:
	char ch;
	cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
	return (toupper(ch));         //  Upcaser og returnerer.
}

						//  Leser et tall i et visst intervall:
int les(const char t[], const int min, const int max)  {
	int n;
	do  {								// Skriver ledetekst:
		cout << '\t' << t << " (" << min << '-' << max << "): ";
		cin >> n;   cin.ignore();		// Leser inn ett tall.
	} while (n < min || n > max);		// Sjekker at i lovlig intervall.
	return n;							// Returnerer innlest tall.
}

						//  Leser en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {
	do  {
		cout << '\t' << t << ": ";	cin.getline(s, LEN); //  Ledetekst og leser.
	} while (strlen(s) == 0);             //  Sjekker at tekstlengden er ulik 0.
}


void SBAN(char valg)  {	//  Oppgave 2C - Felles funksjon for 4x kommandoer:
	int indeks = lesOgBestemIndeks();  // Leser og finner(?) aktuell ruteindeks.
//								cout << "\t\t\t\(indeks: " << indeks << ")\n";
	if (indeks >= 0)  {				   // Fant lovlig indeks:
		switch (valg)  {
		  case 'S':	turer[indeks].skriv();			  break;
		  case 'B':	turer[indeks].bestill();		  break;
		  case 'A':	turer[indeks].avbestill();		  break;
		  case 'N':	turer[indeks].nullstill();		  break;
		  default:  cout << "\tUlovlig kommando!\n";  break;
		}
	} else								//  Ulovlig(e) parametre:
		cout << "\tEn eller flere ulovlige parametre!\n";
}


void ledigPaaTurer()  {		//  Oppgave 2D - Skriver status for ALLE turene:
	int tall;
	for (int i = 0; i < MAXTURER; i++)  {	//  For hver tur:
		cout << '\t';    tall = i % 4;		//  Skriver dagnavn for hver fjerde:
		if (tall == 0)  cout << ukedag[i / 4] << "dag: "; else cout << '\t';
											//  Skriver 'Morgen' / 'Emiddag':
		if (tall < 2)   cout << rutetid[0];  else cout << rutetid[1];
		cout << "\ttil ";					//  Skriver 'Gjøvik' / 'Hamar':
		if (tall == 0 || tall == 2) cout << steder[0];  else cout << steder[1];
		cout << "\t#ledige: " << turer[i].antallLedige() << '\n';  // Ant.ledige
	}
}


void skrivTilFil()  {	//  Oppgave 2E - Skriver HELE datastrukturen til fil:
	ofstream utfil("RUTEBAT.DT2");
	for (int i = 0; i < MAXTURER; i++)
		turer[i].skrivTilFil(utfil);
}


void lesFraFil()  {		//  Oppgave 2F - Leser HELE datastrukturen fra fil:
	ifstream innfil("RUTEBAT.DTA");
	if (innfil)
		for (int i = 0; i < MAXTURER; i++)
			turer[i].lesFraFil(innfil);
	else
		cout << "\n\tFinner ikke filen 'RUTEBAT.DTA'!\n";
}

								//  Oppgave 2G - Leser 3x bokstaver. 
int  lesOgBestemIndeks()  {		//		Prøver å konvertere til lovlig indeks:
  char dag, tid, retn;				//  3x bokstaver.
  int d, t, r;						//  Bokstavene omgjort til tall.
  cin >> dag >> tid >> retn;  cin.ignore();		//  Leser bokstaver og upcaser:
  dag = toupper(dag);    tid = toupper(tid);    retn = toupper(retn);
  switch (dag)  {					//  Gjør om ukedagens bokstav til der denne 
     case 'M':  d =  0;   break;	//     starter i arrayen:
     case 'I':  d =  4;   break;
     case 'O':  d =  8;   break;
     case 'T':  d = 12;   break;
     case 'F':  d = 16;   break;
     default:   return -1;			//  Ulovlig bokstav for ukedag.
  }						//  Gjør om når på dagen og retning til tall (om mulig):
  if (tid == 'M')  t = 0; else if (tid == 'E')  t = 2;  else return -1;
  if (retn == 'G') r = 0; else if (retn == 'H') r = 1;  else return -1;
  return (d + t + r);	//  Alt OK - beregner og returnerer eksakt indeks.
}
