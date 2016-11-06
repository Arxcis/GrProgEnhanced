//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_32.CPP


//   L›sningsforslag til oppgave nr.32  i   C++ -programmering.


//   Programmet leser data fra filen "BILER.DTA" inn i enkeltvariable.


#include <fstream>                     //  ifstream
#include <iostream>                    //  cout
#include <cstring>                     //  strncpy
#include <cstdlib>                     //  atoi

using namespace std;

				       //  Alle de tre neste lengdene inkluderer ogs† '\0':
const int  REGLEN = 9;                 //  Registreringsnummerets lengde 
const int  STRLEN = 21;                //  De fleste feltenes lengde.
const int  BUFLEN = 103;               //  Total linjelengde.

const int  POS1   = 0;                 //  Posisjon i buffer for †rstall
const int  POS2   = 6;                 //  Posisjon i buffer for reg.nr
const int  POS3   = 16;                //  Posisjon i buffer for bilType
const int  POS4   = 38;                //  Posisjon i buffer for navn
const int  POS5   = 60;                //  Posisjon i buffer for gate
const int  POS6   = 82;                //  Posisjon i buffer for poststed

void registrer();
void skriv();

int   linjeNr = 0;                     //  Nummeret p† innleste linje.
int   aarstall;                        //  Bilens †rgang.
char  regNr[REGLEN];
char  bilType[STRLEN];
char  navn[STRLEN];
char  gate[STRLEN];
char  poststed[STRLEN];
char  buffer[BUFLEN];                  //  En HEL linje (uten '\n') fra filen.

 
int main()  {
  ifstream innfil("BILER.DTA");

  if (innfil)  {
    innfil.getline(buffer, BUFLEN);      //  Pr›ver † lese f›rste linje.
    while (innfil)  {                    //  S†lenge flere linjer † lese:
      registrer();                       //  Hent ut hver enkelt felt.
      skriv();                           //  Skriv feltene separat.
      innfil.getline(buffer, BUFLEN);    //  Pr›v † lese neste linje.
	}
  } else
	cout << "\n\nKlarer ikke † finne/†pne filen 'BILER.DTA' !";
  cout << '\n';
  return 0;
}

				                   //  Stykker opp "buffer" i de ulike felter, 
                                   //   og legger disse inn i enkelt-variable:
void registrer()  {
  aarstall = atoi(buffer);             //  Leser tallet f›rst i "buffer".
	    //  Kopierer aktuell subtekst, startende i "buffer+POSn", og
	    //     med maxlengde "xxxLEN-1". '-1' for † ha plass til '\0':
  strncpy(regNr,    buffer+POS2,  REGLEN-1);   regNr[REGLEN-1]    = '\0';
  strncpy(bilType,  buffer+POS3,  STRLEN-1);   bilType[STRLEN-1]  = '\0';
  strncpy(navn,     buffer+POS4,  STRLEN-1);   navn[STRLEN-1]     = '\0';
  strncpy(gate,     buffer+POS5,  STRLEN-1);   gate[STRLEN-1]     = '\0';
  strncpy(poststed, buffer+POS6,  STRLEN-1); 
	    //  N†r man tar ut en tekst INNI en annen en (som i de fire
	    //     f›rste tilfellene), s† M man manuelt selv legge til '\0':
	    //  Legg merke til at det for tilfellene "bilType", "navn" og
	    //     "gate" ALLTID blir hentet ut 20 tegn, selv om de ikke er
	    //     s† lange. De siste blir best†ende av blanke. Det g†r an †
	    //     lage en liten og enkel funksjon som tar disse vekk, 
	    //     men dette er ikke gjort her.
}


			    //  Skriver alle enkelt-variablenes innhold.
			    //  Alle tekstene skrives med '-' foran og bak:
void skriv()  {
  cout << '\n'     << ++linjeNr << ':';
  cout << '\t'     << aarstall;
  cout << "\n\t-"  << regNr     << '-';
  cout << "\n\t-"  << bilType   << '-';
  cout << "\n\t-"  << navn      << '-';
  cout << "\n\t-"  << gate      << '-';
  cout << "\n\t-"  << poststed  << '-';
}
