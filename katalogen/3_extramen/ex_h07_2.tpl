//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H07_2.TPL

//  Skjellettet/template for eksamen i C++, 20.desember 2007, oppgave 2.
//  Laget av Frode Haug, HiG, desember 2007.

//  Program som holder orden pÜ ulike biler tilhõrende ulike firmaer.
  

                        //  INCLUDE:
#include <iostream>           //  cin, cout
#include <fstream>            //  ifstream, ofstream
#include <cstring>            //  strcpy, strlen, strcmp
#include <cctype>             //  toupper

using namespace std;

                        //  CONST:
const int  STRLEN      =     40;  //  Max. tekstlengde.
const int  MAXBILER    =    200;  //  Max. antall biler.
const int  MAXFIRMAER  =     50;  //  Max. antall firmaer.

                        
class Bil  {            //  KLASSER:
  private:
    char regnr[STRLEN/4];     //  Registreringsnummer.
    char type[STRLEN];        //  Biltype/-merke.
    int  aarsmodell;          //  èrsmodell.
    int  firmanr;             //  Firmaets nummer/indeks i "firmaer".

  public:                     //  Definisjon/deklarasjon av medlemsfunksjoner:
    Bil()  {  strcpy(regnr, "");  strcpy(type, "");  aarsmodell = 1980;  }
    void skriv();                                   //  Oppgave 2A
    void skriv2();                                  //  Oppgave 2B
    void les_data(char t[], int fnr);               //  Oppgave 2E
    void skriv_til_fil(ostream* ut);                //  Oppgave 2F
    void les_fra_fil(char t[], istream* inn);       //  Oppgave 2G
    bool eies_av(int n)    {  return (firmanr == n);  }      // Firma som eier.
    bool er_lik(char t[])  {  return (!strcmp(regnr, t)); }  // Sammenligner.
};


class Firma    {
  private:
    char navn[STRLEN];        //  Firmaets navn.
    char adr[STRLEN*2];       //  Adresse (gate, postnr, poststed).
    int  tlf;                 //  Telefon.
  
  public:                     //  Definisjon/deklarasjon av medlemsfunksjoner:
    Firma()  {  strcpy(navn, "");  strcpy(adr, "");  tlf = 12345678;  }
    void skriv();                                   //  Oppgave 2A
    void skriv2();                                  //  Oppgave 2C
    void les_data(char t[]);                        //  Oppgave 2E
    bool er_lik(char t[])  {  return (!strcmp(navn, t)); } // Sammenligner.
};


                    //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les(char t[]);
int  les(const char t[], const int min, const int max);
void les(const char t[], char s[], const int LEN);
int  finn_bil(char t[]);
int  finn_firma(char t[]);

void skriv();               //  Oppgave 2A
void skriv_bil();           //  Oppgave 2B
void skriv_firma();         //  Oppgave 2C
void slett_bil();           //  Oppgave 2D
void ny_bil();              //  Oppgave 2E
void skriv_til_fil();       //  Oppgave 2F
void les_fra_fil();         //  Oppgave 2G


                        //  GLOBALE VARIABLE:
Bil   biler[MAXBILER+1];      //  Array med Bil-objekter.
Firma firmaer[MAXFIRMAER+1];  //  Array med Firma-objekter.
int siste_bil, siste_firma;   //  Indeks for siste bil/firma hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   les_fra_fil();                             //  Oppgave 2G
   skriv_meny();
   kommando = les("ùnske");

   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'S':   skriv();         break;    //  Oppgave 2A
       case 'B':   skriv_bil();     break;    //  Oppgave 2B
       case 'F':   skriv_firma();   break;    //  Oppgave 2C
       case 'R':   slett_bil();     break;    //  Oppgave 2D
       case 'N':   ny_bil();        break;    //  Oppgave 2E
       default:   skriv_meny();  break;
     }
     kommando = les("ùnske");
   }
  skriv_til_fil();                            //  Oppgave 2F
  cout << "\n\n";
  return 0;
}

                        //  DEFINISJON AV KLASSE-FUNKSJONER:
void Bil::skriv()  {         //  Skriver alle bilens data:
        //  Oppgave 2A:  Lag innmaten   
}

                             //  Skriver bilens data, unntatt regnr,
void Bil::skriv2()  {        //    men ogsÜ dens eier(firma):
        //  Oppgave 2B:  Lag innmaten   
}
                             
                           
void Bil::les_data(char t[], int fnr)  {  // Registrerer/leser ALLE bilens data:
        //  Oppgave 2E:  Lag innmaten   
}

                             
void Bil::skriv_til_fil(ostream* ut)  {   //  Skriver ALLE bilens data til fil:
        //  Oppgave 2F:  Lag innmaten   
}

                             
void Bil::les_fra_fil(char t[], istream* inn)  { //  Leser ALLE bilens data fra fil:
        //  Oppgave 2G:  Lag innmaten   
}


void Firma::skriv()  {       //  Skriver alle firmaets data:
        //  Oppgave 2A:  Lag innmaten   
}


void Firma::skriv2()  {       //  Skriver firmaets data (-navn):
        //  Oppgave 2C:  Lag innmaten   
}

                         
void Firma::les_data(char t[])  {   //  Registrerer/leser ALLE firmaets data:
        //  Oppgave 2E:  Lag innmaten   
}


                        //  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tS = Skriv ALLE biler og firmaer\n";
  cout << "\tB = skriv ALT om EN gitt Bil\n";
  cout << "\tF = Skriv ALLE data om ETT gitt Firma og ALLE dets biler\n";
  cout << "\tR = Remove/fjern en gitt bil\n";
  cout << "\tN = Ny bil (og evt. firma) legges inn\n";
  cout << "\tQ = Quit/avslutt\n";
}


char les(char t[])  {       //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << '\n' << t << ":  ";   //  Skriver medsendt ledetekst.
  cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
  return (toupper(ch));         //  Upcaser og returnerer.
}

                            // Leser et tall i et visst intervall:
int les(const char t[], const int min, const int max)  { 
  int n;
  do  {                                  // Skriver ledetekst:
    cout << '\t' << t << " (" << min << '-' << max << "): ";
    cin >> n;   cin.ignore();            // Leser inn ett tall.
  } while(n < min  ||  n > max);         // Sjekker at i lovlig intervall.
  return n;                              // Returnerer innlest tall.
}

                            //  Leser inn en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {  
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, LEN);          //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}

                             //  Ut fra en bils regnr, sÜ returneres dens
int finn_bil(char t[])  {    //     indeks i "biler", evt. '0' om ikke finnes:
  for (int i = 1;  i <= siste_bil;  i++) 
      if (biler[i].er_lik(t))  return i;
  return 0;
}

                             //  Ut fra et firmas navn, sÜ returneres dens
int finn_firma(char t[])  {  //    indeks i "firmaer", evt. '0' om ikke finnes:
  for (int i = 1;  i <= siste_firma;  i++) 
      if (firmaer[i].er_lik(t))  return i;
  return 0;
}


void skriv()  {             //  Skriver ALLE bilene og firmaene:
        //  Oppgave 2A:  Lag innmaten   
}


void skriv_bil()  {         //  Skriver ALLE data om EN bil:
        //  Oppgave 2B:  Lag innmaten   
}

                            //  Skriver ALLE data om ETT firma,
void skriv_firma()  {       //    inkludert alle dets biler:
        //  Oppgave 2C:  Lag innmaten   
}

                            
void slett_bil()  {         //  Sletter/fjerner EN bil:
        //  Oppgave 2D:  Lag innmaten   
}

                            //  Legger inn (om mulig) en ny bil,
void ny_bil()  {            //    og evt. ett nytt firma:
        //  Oppgave 2E:  Lag innmaten   
} 


void skriv_til_fil()  {     //  Skriver HELE datastrukturen til fil:
        //  Oppgave 2F:  Lag innmaten   
}


void les_fra_fil()  {       //  Leser HELE datastrukturen fra fil:
        //  Oppgave 2G:  Lag innmaten   
}
