//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H07_2.CPP

//  Lõsningsforslag til eksamen i C++, 20.desember 2007, oppgave 2.
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
    void les_fra_fil(int nr, istream* inn);         //  EXTRA
    void skriv_til_fil(ostream* ut);                //  EXTRA
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
void Bil::skriv()  {         //  OPPGAVE 2A - Skriver alle bilens data:
  cout << '\t' << regnr << ", " << aarsmodell << ", " << type << '\n';
}

                             //  OPPGAVE 2B - Skriver bilens data, unntatt regnr,
void Bil::skriv2()  {        //               men ogsÜ dens eier(firma):
  cout << "\n\t" << aarsmodell << ", " << type << "\n\tEies av firmaet:\n\t";
  firmaer[firmanr].skriv();
}
                             
                           //  Oppgave 2E - Registrerer/leser ALLE bilens data:
void Bil::les_data(char t[], int fnr)  { 
  strcpy(regnr, t);                    //  Kopierer over de to parametrene:
  firmanr = fnr;
  les("Biltype  ", type, STRLEN);      //  Leser inn de to andre:
  aarsmodell = les("èrsmodell", 1980, 2020);
}

                             //  OPPGAVE 2F - Skriver ALLE bilens data til fil:
void Bil::skriv_til_fil(ostream* ut)  {
  *ut << regnr << ' ' << aarsmodell << ' ' << firmanr << '\n' << type << '\n';
}

                             //  OPPGAVE 2G - Leser ALLE bilens data fra fil:
void Bil::les_fra_fil(char t[], istream* inn)  {
  strcpy(regnr, t);
  *inn >> aarsmodell >> firmanr;   (*inn).ignore();
  (*inn).getline(type, STRLEN);
}


void Firma::skriv()  {       //  OPPGAVE 2A - Skriver alle firmaets data:
  cout << '\t' << navn << ", tlf: " << tlf << "\n\t\t" << adr << '\n';
}


void Firma::skriv2()  {       //  OPPGAVE 2C - Skriver firmaets data (-navn):
  cout << '\t' << "Tlf: " << tlf << "\n\t\t" << adr << '\n';
}

                         //  Oppgave 2E - Registrerer/leser ALLE firmaets data:
void Firma::les_data(char t[])  { 
  strcpy(navn, t);
  les("Adresse  ", adr, STRLEN*2);
  tlf = les("Telefon", 10000000, 99999999);
}

                             //  EXTRA - Skriver ALLE bilens data til fil:
void Firma::skriv_til_fil(ostream* ut)  {
   *ut << tlf << ' ' << navn << '\n' << adr << '\n';
}

                             //  EXTRA - Leser ALLE bilens data fra fil:
void Firma::les_fra_fil(int nr, istream* inn)  {
  tlf = nr;
  (*inn).getline(navn, STRLEN);
  (*inn).getline(adr, STRLEN*2);
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


void skriv()  {             //  OPPGAVE 2A - Skriver ALLE bilene og firmaene:
  char ch;
  int i;
  cout << "\n\nALLE BILENE I KARTOTEKET (" << siste_bil << " stk):\n";
  for (i = 1;  i <= siste_bil;  i++)     //  GÜr gjennom ALLE bilene,
      biler[i].skriv();                  //   og skriver hver enkelt:
  cout << "\t\t\t\t\t\tSkriv ett tegn .....";  cin >> ch;  //  Leser ETT tegn.
  cout << "\n\nALLE FIRMAENE I KARTOTEKET (" << siste_firma << " stk):\n";
  for (i = 1;  i <= siste_firma;  i++)   //  GÜr gjennom ALLE firmaene,
      firmaer[i].skriv();                //   og skriver hver enkelt:
  cout << "\n\n";
}


void skriv_bil()  {         //  OPPGAVE 2B - Skriver ALLE data om EN bil:
  int nr;                                            //  Aktuell bils indeks.
  char regnr[STRLEN/4];
  les("Skriv ALLE data om regnr", regnr, STRLEN/4);  //  Leser regnr.
  if ((nr = finn_bil(regnr)) != 0)                   //  Bilen finnes:
     biler[nr].skriv2();                             //  Skriver ALT om den.
  else
     cout << "\n\tIngen bil med dette regnummeret.\n\n";
}

                            //  OPPGAVE 2C - Skriver ALLE data om ETT firma,
void skriv_firma()  {       //               inkludert alle dets biler:
  int nr, i;                                  //  Firmaets indeks og lõkkevar.
  char navn[STRLEN];                          //  Aktuelt firmas navn.
  les("Skriv ALLE data om biler eid av firma", navn, STRLEN);  // Leser firma.
  if ((nr = finn_firma(navn)) != 0)  {        //  Firmaet finnes:
     firmaer[nr].skriv2();                    //  Skriver ALLE firmaets navn.
     cout << "\n\tEier bilene:\n";
     for (i = 1;  i <= siste_bil;  i++)  {    //  GÜr gjennom ALLE bilene:
         if (biler[i].eies_av(nr))            //  For de som eies av firmaet,
            biler[i].skriv();                 //    skrives ALLE bilens data.
     }
  } else
    cout << "\n\tIngen firma med dette navnet.\n\n";
}

                            
void slett_bil()  {         //  OPPGAVE 2D - Sletter/fjerner EN bil:
  int nr;                                        //  Aktuell bils indeks.
  char regnr[STRLEN/4];
  if (siste_bil > 0)  {                          //  Biler finnes:
     les("Slett regnr", regnr, STRLEN/4);        //  Leser regnr.
     if ((nr = finn_bil(regnr)) != 0)  {         //  Fant aktuell bil:
        biler[nr] = biler[siste_bil--];          //  Siste bil flyttes til der
        cout << "\n\tBilen er fjernet.\n\n";     //   den slettede har vërt.
     }  else
        cout << "\n\tIngen bil med dette regnummeret.\n\n";
  } else
    cout << "\n\tTomt for biler allerede.\n\n";
}

                            //  OPPGAVE 2E - Legger inn (om mulig) en ny bil,
void ny_bil()  {            //               og evt. ett nytt firma:
  int nr;                                          //  Aktuelt firmas indeks.
  char regnr[STRLEN/4], navn[STRLEN];
                                                   //  Plass til bil/firma:
  if (siste_bil < MAXBILER  &&  siste_firma < MAXFIRMAER)  {
     les("Nytt regnr", regnr, STRLEN/4);           //  Leser regnr.
     if (finn_bil(regnr) == 0)  {                  //  Bilens finnes IKKE:
        les("Firmaets navn", navn, STRLEN);        //  Leser firmanavn.
        if ((nr = finn_firma(navn)) == 0)  {       //  Firmaet finnes IKKE:
           firmaer[++siste_firma].les_data(navn);  //  Leser nytt firmas data.
           nr = siste_firma;                       //  Indeks oppdaters.
        }
        biler[++siste_bil].les_data(regnr, nr);    //  Leser ny bils data.
     } else
       cout << "\n\tBil finnes allerede med dette regnummeret.\n\n";
  } else
    cout << "\n\tIkke plass til flere biler og/eller firmaer.\n\n";
} 


void skriv_til_fil()  {   //  OPPGAVE 2F - Skriver HELE datastrukturen til fil:
  int i;
  ofstream utfil("BILER.DTA");           //  èpner aktuell fil.

  for (i = 1;  i <= siste_bil;  i++)     //  GÜr gjennom ALLE bilene:
      biler[i].skriv_til_fil(&utfil);    //  De skriver seg selv til fil.

//  EXTRA (resten av funksjonen):
  ofstream utfil2("FIRMAER.DTA");        //  èpner annen aktuell fil.
  for (i = 1;  i <= siste_firma;  i++)   //  GÜr gjennom ALLE firmaene:
      firmaer[i].skriv_til_fil(&utfil2); //  De skriver seg selv til fil.
}


void les_fra_fil()  {       //  OPPGAVE 2G - Leser HELE datastrukturen fra fil:
  char buffer[STRLEN/4];                   //  Fõrste tekst i en Bil-post.
  ifstream innfil("BILER.DTA");            //  èpner aktuell fil.

  siste_bil = siste_firma = 0;             //  Nullstiller globale variable.

  if (innfil)  {                           //  Filen var Ü finne:
     innfil >> buffer;                     //  Leser (om mulig) regnr.
     while (!innfil.eof() &&  siste_bil < MAXBILER)  {   // Ikke slutt, plass:
       biler[++siste_bil].les_fra_fil(buffer, &innfil);  // Leser resten selv.
       innfil >> buffer;                   //  Leser (om mulig) regnr.
     }
  } else
    cout << "\nFant ikke filen 'BILER.DTA'!\n\n";

//  EXTRA (resten av funksjonen):
  int nr;                                  //  Telefonnummer.
  ifstream innfil2("FIRMAER.DTA");         //  èpner annen aktuell fil.
  if (innfil2)  {                          //  Filen var Ü finne:
     innfil2 >> nr;                        //  Leser (om mulig) tlfnr.
     while (!innfil2.eof() &&  siste_bil < MAXFIRMAER)  { // Ikke slutt, plass:
       innfil2.ignore();                   //  Forkaster ETT blankt tegn.
       firmaer[++siste_firma].les_fra_fil(nr, &innfil2); // Leser resten selv.
       innfil2 >> nr;                      //  Leser (om mulig) tlfnr.
     }
  } else
    cout << "\nFant ikke filen 'FIRMAER.DTA'!\n\n";
}
