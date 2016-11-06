//  Fil:  FRODEH \ C++ \ EXTRAMEN \ EX_H05_2.TPL

//  Skjellettet/template for eksamen i C++, 19.desember 2005, oppgave 2.
//  Laget av Frode Haug, HiG, desember 2005.


//  Program som holder orden på bestilling/reservering/booking av et
//     låneobjekt (hall e.l.) til ulike klokkeslett i løpet av en uke.


                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream, fstream
#include <cctype>             //  toupper
#include <cstring>            //  strcpy
#include <iomanip>            //  setw

using namespace std;

                        //  CONST:
const int ANT_DAGER  =  7;    //  Antall dager i en uke.
const int ANT_TIMER  = 14;    //  Timene i løpet av en dag (kl.07.00-20.00).
const int START_TIME =  7;    //  Startklokkeslett om morgenen.
const int STRLEN1    =  5;    //  Max. tekstlengde for en ukedags navn.
const int STRLEN2    = 30;    //  Max. tekstlengde for en bestillers navn.

                        //  KLASSER:
class Ukedag  {               //  Ukedag for bestilling/booking:
  private:
    char navn[STRLEN1];       //  Navn.
    char book[ANT_TIMER][STRLEN2];  //  Navn på bestiller et gitt klokkeslett.

  public:
    void skriv();             //  Deklarasjon av medlemsfunksjoner:
    void resett();
    void bestill();
    void avbestill();
    void skriv_til_fil(ostream* ut);
    void les_fra_fil(char nvn[], istream* inn);
};

                        //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les_kommando();
int  les(char t[], int min, int max);
void skriv_dag();
void resett_dag();
void bestill_time();
void avbestill_time();
void skriv_til_fil();
void les_fra_fil();


                        //  GLOBALE VARIABLE:
Ukedag uka[ANT_DAGER];               //  Array med Ukedag-objekter.

                        
int main()  {           //  HOVEDPROGRAM:
   char kommando;
   
   les_fra_fil();                                 //  Oppgave 2f
   resett_dag();                                  //  Oppgave 2b

   skriv_meny();
   kommando = les_kommando();
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'S':  skriv_dag();           break;   //  Oppgave 2a
       case 'B':  bestill_time();        break;   //  Oppgave 2c
       case 'A':  avbestill_time();      break;   //  Oppgave 2d
       default:   skriv_meny();          break;
     }
     skriv_til_fil();                             //  Oppgave 2e
     kommando = les_kommando();
   }
  cout << "\n\n";
  return 0;
}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:
void Ukedag::skriv()  {      //  Skriver ALLE data om en ukedag:
        //  Oppgave 2A:  Lag innmaten
}


void Ukedag::resett()  {     //  Sletter ALLE bestillinger:
        //  Oppgave 2B:  Lag innmaten
}


void Ukedag::bestill()  {    //  Foretar EN bestilling:
        //  Oppgave 2C:  Lag innmaten
}


void Ukedag::avbestill()  {  //  Fjerner/sletter EN bestilling:
        //  Oppgave 2D:  Lag innmaten
}


void Ukedag::skriv_til_fil(ostream* ut)  {  //  Skriver til fil:
        //  Oppgave 2E:  Lag innmaten
}

                                            //  Leser fra fil:
void Ukedag::les_fra_fil(char nvn[], istream* inn)  {  
        //  Oppgave 2F:  Lag innmaten
}


                        //  DEFINISJON AV FUNKSJONER:
		  
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tS = Skriv alle bestillinger en gitt dag\n";
  cout << "\tB = Bestill/reserver/book en time\n";
  cout << "\tA = Avbestill en time\n";
  cout << "\tQ = quit/avslutt\n";
}


char les_kommando()  {       //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << "\n\nOppgi ønske:  ";
  cin >> ch;   cin.ignore();
  return toupper(ch);
}


int les(char t[], int min, int max)  {   //  Leser et tall i et visst intervall.
  int n;
  do  {                                  //  Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;                            //  Leser inn ett tall.
  } while(n < min  ||  n > max);         //  Sjekker at i lovlig intervall.
  cin.ignore();                          //  Forkaster ett tegn ('\n').
  return n;                              //  Returnerer innlest tall.
}


void skriv_dag()  {          //  Skriv ALLE bestillinger EN gitt dag:
        //  Oppgave 2A:  Lag innmaten
}


void resett_dag()  {		 //  Slett ALT en gitt dag:
        //  Oppgave 2B:  Lag innmaten
}


void bestill_time()  {       //  Bestill/reserver/book en time:
        //  Oppgave 2C:  Lag innmaten
}


void avbestill_time()  {     //  Avbestill en time:
        //  Oppgave 2D:  Lag innmaten
}


void skriv_til_fil()  {      //  Skriver datastrukturen til fil:
        //  Oppgave 2E:  Lag innmaten
}


void les_fra_fil()  {        //  Leser datastrukturen fra fil:
        //  Oppgave 2F:  Lag innmaten
}
