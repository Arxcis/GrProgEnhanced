//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_19.CPP

//   Programeksempel nr.19 for forelesning i  C++ -programmering. 

//   "Oppsummerende" eksempel fra kap.2-7 med bruk av:
//       - enkel bruken av klasse m/data og medlemsfunksjoner
//       - array inni objekter
//       - array av objekter
//       - loopende hovedmeny som håndterer brukervalg og hjelpmeny


                        //  INCLUDE:
#include <iostream>          //  cout, cin
#include <cctype>            //  toupper

using namespace std;

                        //  CONST:
const int   MAXKONTO = 100;  //  Max. antall konti.
const int   STRLEN   =  40;  //  Lengde på innleste strenger.        


                        //  KLASSE:
class Konto  {
  private:
    float saldo;             //  Innestående sum.
    char navn[STRLEN];       //  Kontoeierens navn.
  
  public:
    Konto()                  //  Constructor som initierer:
      { saldo = 0.0F; }
				             //  Oppdaterer saldo med en (+/-) sum.
    void pengerInnUt(float belop) 
      { saldo += belop; }

    void lesNavn();          //  Deklarasjon av to funksjoner (IKKE inline):
    void skrivSaldo();
};

                        //  DEKLARASJON AV FUNKSJONER:
void skrivMeny();
char lesKommando();
int  lesNr();
void nyKonto();
void transaksjon();
void seSaldo();

                        //  GLOBALE VARIABLE:
Konto konti[MAXKONTO];                 //  Array med konto-objekter.
int  sisteBrukt = 0;                   //  Siste brukte element i "konti".

                        
int main()  {          //  HOVEDPROGRAMMET:
   char kommando;
   
   skrivMeny();
   kommando = lesKommando();

   while (kommando != 'Q')  {     // Looper til Q' tastes:
     switch (kommando)  {
       case 'N': nyKonto();     break; // N = registrer ny vare.
       case 'T': transaksjon(); break; // T = penger inn på/ut fra konto.
       case 'S': seSaldo();     break; // S = se saldo for konto.
       default:  skrivMeny();   break;
     }
	 kommando = lesKommando();
   }
   cout << "\n\n";
   return 0;
}
				       
                        //  DEFINISJON AV KLASSE-FUNKSJONER:
				             
void Konto::lesNavn()  {           //  Leser navnet til kontoinnehaveren:
  cout << "\nKontoeierens navn:  ";
  cin.getline(navn, STRLEN);
}


void Konto::skrivSaldo()  {        //  Skriver nåværende saldo:
  cout << "\nKontoens innehaver:  " << navn
       << "\nInnestående beløp:   " << saldo << '\n';
}


                        //  DEFINISJON AV FUNKSJONER:
void skrivMeny()  {                //  Meny meny for lovlige valg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:";
  cout << "\n\tN - opprett ny konto";
  cout << "\n\tT - penger inn på/ut fra konto";
  cout << "\n\tS - se saldo for en konto";
  cout << "\n\tQ - avslutt program";
}

				       
char lesKommando()  {       // Leser en kommando og returnerer dette:
  char ch;
  cout << "\n\nKommando (N, T, S, Q):  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}


int lesNr()  {              // Leser et kontonummer og returnerer dette:
  int nr;

  do  {
    cout << "\nKontonummer (0-" << sisteBrukt << "):  ";
    cin >> nr;
  } while (nr < 0  ||  nr > sisteBrukt);
  return nr;
}
				       
				       
void nyKonto()  {           //  Tar i bruk (om mulig) en ny konto:
  if (sisteBrukt < MAXKONTO-1)  {     //  Fremdeles ledige konti:
    ++sisteBrukt;
    konti[sisteBrukt].lesNavn();      //  Leser navnet for den nye kontoen.
  } else
    cout << "\nAlle " << MAXKONTO << " kontoene er allerede i bruk.";
}

				       
void transaksjon()  {        //  Tar ut/setter inn et beløp:
  int   nr;
  float belop;

  if ((nr = lesNr()) != 0)  {         //  Dersom lovlig kontonummer:
     cout << "Beløp (negativt = ut, positivt = inn):  ";
     cin >> belop;                    //  Leser beløp inn/ut.
     konti[nr].pengerInnUt(belop);    //  Oppdateres kontoens saldo.
  }
}
				       
				       
void seSaldo()  {           //  Skriver en kontos saldo:
  int nr;

  if ((nr = lesNr()) != 0)            //  Dersom lovlig kontonummer:
     konti[nr].skrivSaldo();          //  Skriver aktuell saldo.  
}
