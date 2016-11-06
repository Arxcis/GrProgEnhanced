//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_S16_2.TPL

//  Skjellettet/template for kontinuasjonseksamen i C++, august 2016, oppgave 2.
//  Laget av Frode Haug, HiG, NTNU

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

void Tur::skriv()  {		//  Skriver ALT om en tur:

	//  Oppgave 2A:  Lag innmaten
}


void Tur::bestill()  {		//  Registrerer (om mulig) bestilling:

	//  Oppgave 2B:  Lag innmaten
}


void Tur::avbestill()  {	//  En booking avbestilles:

	//  Oppgave 2B:  Lag innmaten
}


void Tur::nullstill()  {	//  ALT på EN tur nullstilles:

	//  Oppgave 2C:  Lag innmaten
}

							//  ALT om turen skrives til fil:
void Tur::skrivTilFil(ofstream & ut)  {			

	//  Oppgave 2E:  Lag innmaten
}

							//  ALT om turen leses fra fil:
void Tur::lesFraFil(ifstream & inn)  {

	//  Oppgave 2F:  Lag innmaten
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


void SBAN(char valg)  {		//  Felles funksjon for 4x kommandoer:

	//  Oppgave 2C:  Lag innmaten
}


void ledigPaaTurer()  {		//  Skriver status for ALLE turene:

	//  Oppgave 2D:  Lag innmaten
}


void skrivTilFil()  {		//  Skriver HELE datastrukturen til fil:

	//  Oppgave 2E:  Lag innmaten
}


void lesFraFil()  {			//  Leser HELE datastrukturen fra fil:

	//  Oppgave 2F:  Lag innmaten
}

								//  Leser 3x bokstaver. 
int  lesOgBestemIndeks()  {		//		Prøver å konvertere til lovlig indeks:

	//  Oppgave 2G:  Lag innmaten
}
