//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_40.CPP

//   Programeksempel nr.40 for forelesning i  C++ -programmering. 

//   "Oppsummerende" eksempel fra kap.2-7 og 12 med bruk av:
//          - valg/vilk†rtester og l›kke-konstruksjoner  (kap.3)
//          - funksjoner (u/ m/parametre, verdioverf›ring
//                        retur av EN verdi              (kap.5)
//          - objekter                                   (kap.6)
//          - arrayer av int, char og objekter           (kap.7)
//          - strengh†ndtering: strcpy, strcmp           (kap.7)
//          - skriving til/lesing fra fil                (kap.12)


                        //  INCLUDE:
#include <iostream>          //  cout, cin
#include <fstream>           //  ifstream, ofstream
#include <cstring>           //  strcpy, strcmp

using namespace std;

                        //  CONST:
const int STRLEN  = 40;      //  Max.lengde for et barns navn.
const int MAXAAR  = 15;      //  Max. alder for barnet.
const int MAXBARN = 20;      //  Max. antall barn i tabellen.


                        //  KLASSE:
class Barn  {                //  Klasse som beskriver et barn:
  private:
    char navn[STRLEN];
    int  alder;         //  N†v‘rende alder = antall indekser brukt i "hoyde".
    int  hoyde[MAXAAR+1];    //  Barnets h›yde p† fylte N-†rsdagen.
  public:
    void  lesFraFil(ifstream & inn, char buf[]);
    void  skrivTilFil(ofstream & ut);
    void  skrivData(int n);
    bool  likNavn(char nvn[]);
    void  nyHoyde();
    float gjsnitt();
};

                        //  DEKLARASJON AV FUNKSJONER:
void lesFraFil();
void skrivTilFil();
void displayData();
int  finnBarn(char nvn[]);
int  lesHoyde(int nedre, int ovre);


                        //  GLOBALE VARIABLE:
Barn barnetabell[MAXBARN+1];  //  Array med barn-objekter.
int  sisteBarn;               //  Siste element brukt i arrayen "barnetabell".
                              //     (Blir automatisk initiert til '0'.)

                        
int main()  {           //  HOVEDPROGRAMMET:
  char navnet[STRLEN];     //  Aktuelt barns navn.
  int nr;                  //  Aktuelt barns indeks i arrayen "barnetabell".

  lesFraFil();             //  Leser inn alle data fra fil.

  displayData();           //  Skriver alle data til skjermen.

  cout << "\n\n\nEndre data om barnet:  ";  //  Ber om navnet p† barnet det skal
  cin.getline(navnet, STRLEN);              //    legges inn en ny h›yde for.
                           //  Finner (om mulig) dets indeks i 'barnetabell':
  if ((nr = finnBarn(navnet)) != 0)  {      //  Barnet ble funnet:

     barnetabell[nr].nyHoyde();             // Leser h›yden for et nytt †r.

     cout << "\n\n";
     displayData();        //  Skriver alle data, ogs† den endrede.
                           //  F†r vite aktuelt barns gjennomsnittlige h›yde:
     cout << "\n\n\nGjennomsnittsh›yde: " << barnetabell[nr].gjsnitt() << '\n';
  
     skrivTilFil();        //  Skriver oppdaterte data til filen igjen.

  } else                   //  Navnet/barnet finnes ikke:
    cout << "\n\nIngen barn har dette navnet!\n";

  cout << "\n\n";
  return 0;
}


                        //  DEFINISJON AV KLASSE-FUNKSJONER:
                             //  Leser inn alle barnets data fra fil:
void Barn::lesFraFil(ifstream & inn, char buf[])  {
  strcpy(navn, buf);         //  Kopiere over navnet.
  inn >> alder;              //  Leser barnets alder.
  for (int i = 1;  i <= alder;  i++) // Leser h›yden de ulike †rene:
      inn >> hoyde[i];
  inn.ignore();              // Forkaster '\n' p† slutten av tallinjen.
}

                             //  Skriver ut alle barnets data til fil:
void Barn::skrivTilFil(ofstream & ut)  {
  ut << navn << '\n'         //  Navnet p† egen linje,
     << alder;                       //  barnets alder,
  for (int i = 1;  i <= alder;  i++) //  og dets h›yder de ulike †rene:
      ut << "  " << hoyde[i];
  ut << '\n';                        //  Linjeskift etter alle tallene.
}

                             //  Skriver ut alle barnets data til skjermen.
                             //    F†r inn dets indeks i arrayen som parameter:
void Barn::skrivData(int n)  {              //  Skriver indeks og navn:
  cout << "\n\nBarn nr." << n << " heter:  " << navn << '\n';
  for (int i = 1;  i <= alder;  i++)  {     //  Skriver h›yde de ulike †rene:
      cout << '\t' << i << " †r: " << hoyde[i];
      if (i % 4 == 0)  cout << '\n';        //  Hvert 4.†r skrives linjeskift.
  }
}

                             //  Returnerer om dets navn er lik eller ei med
bool Barn::likNavn(char nvn[])  {   //  parameteren "nvn":
  return (!strcmp(navn, nvn));
}


void Barn::nyHoyde()  {      //  Leser inn en ny h›yde for barnet:
  if (alder < MAXAAR)  {     //  Fortsatt plass til flere innlesninger:
     alder++;                //  Teller opp for det nye †ret.
     cout << "\nBarnets " << alder << "-†rsdag,\n";
                             //  Leser inn ny h›yde. Denne m† v‘re 5 cm h›yere
                             //    enn †ret f›r, og mindre enn 250 cm:
     hoyde[alder] = lesHoyde(hoyde[alder-1]+5, 250);
  } else                     //  Ikke plass til flere h›yder:
     cout << "\nIkke plass til flere data om barnet, fullt allerede med "
          << MAXAAR << " stk.";
}


float Barn::gjsnitt()  {     //  Finner gjennomsnittsh›yden for barnet:
  float total = 0.0F;        //  Initierer totalsummen.
  for (int i = 1;  i <= alder;  i++)   // Summerer sammen alle elementene:
      total += hoyde[i];
  return (total/alder);      // Beregner og returnerer gjennomsnittet.
}


                        //  DEFINISJON AV FUNKSJONER:
void lesFraFil()  {          //  Leser alle dataene/barna fra fil:
  ifstream inn("EKS_40.DTA");//  pner filen det skal leses fra.
  char buffer[STRLEN];       //  Buffer for (om mulig) † lese neste linje.

  if (inn)  {                //  Filen ble funnet:
     inn.getline(buffer, STRLEN);  //  Henter (om mulig) 1.linje.
                                   //  Mer † lese og fortsatt plass i arrayen:
     while (!inn.eof()  &&  sisteBarn < MAXBARN)  {
       sisteBarn++;          //  Tar i bruk neste indeks/'skuff'.
                             //  Barne-objektet leser resten inn selv:
       barnetabell[sisteBarn].lesFraFil(inn, buffer);  
       inn.getline(buffer, STRLEN); //  Henter (om mulig) neste linje/post.
     }
  } else                     // Filen finnes ikke:
    cout << "\nKlarer ikke † finne filen 'EKS_40.DTA'.";
}


void skrivTilFil()  {      //  Skriver alle dataene/barna til fil:
  ofstream ut("EKS_40.DTA");
  for (int i = 1;  i <= sisteBarn;  i++) //  G†r gjennom alle barna:
      barnetabell[i].skrivTilFil(ut);    //  Hver skriver ut alt om seg selv.
}


void displayData()  {       //  Skriver alle dataene/barna til skjermen:
  for (int i = 1;  i <= sisteBarn;  i++) // G†r gjennom alle barna:
      barnetabell[i].skrivData(i);       // Hver skriver ut alt om seg selv.
}

                              
int finnBarn(char nvn[])  { //  Leter etter et barn med navn lik "nvn":
  for (int i = 1;  i <= sisteBarn;  i++)  
      if (barnetabell[i].likNavn(nvn)) return i;   //  Funn/match!
  return 0;                                        //  IKKE funnet!
}

                           //  Returnerer en verdi i ['nedre' ...'ovre']:
int lesHoyde(int nedre, int ovre)  {
  int hoyde;               //  Hjelpevariabel for innlesning.
  do  {                    //  Angir aktuelt intervall:
    cout << "\tangi h›yde (" << nedre << '-' << ovre << "):  ";
    cin >> hoyde;          //  Leser verdi.
  } while (hoyde < nedre  ||  hoyde > ovre);    // I korrekt intervall ?
  return hoyde;            //  Returnerer aktuell/godtatt verdi.
}
