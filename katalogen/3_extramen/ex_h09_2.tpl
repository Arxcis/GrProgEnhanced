//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H09_2.TPL

//  Skjellettet/template for eksamen i C++, 7.desember 2009, oppgave 2.
//  Laget av Frode Haug, HiG, november 2009.

//  Program som holder orden pÜ nÜr ulike underholdningsinnslag er brukt.
//  Kan fÜ skrevet ut data om innslagene ut fra ulike kriterier.
  

                        //  INCLUDE:
#include <fstream>           //  ifstream, ofstream
#include <iostream>          //  cin, cout
#include <cstring>           //  strlen
#include <cctype>            //  toupper
using namespace std;

                        //  ENUM og CONST:
enum kategori  {  Video, Audio, Bilde, Web, Historie, Dokument, PPT  };
const int STRLEN      =      160;   //  Max. tekstlengde.
const int MAXINNSLAG  =     1000;   //  Max. antall innslag i "databasen".
const int MAXSEMESTER =       20;   //  Max. antall semestre et innslag vises.
const int MAXBAKOVER  =       10;   //  Max. antall Ür bakover.
const int STARTAAR    =     1980;   //  Fõrste Ür innslag ble brukt.
const int SLUTTAAR    =     2009;   //  Hittil siste Ür innslag ble brukt.


class Innslag {            //  KLASSE:
  private:
    char beskrivelse[STRLEN];     //  Beskrivelse av/tekst om innslaget.
    kategori type;                //  Hva slags kategori innslaget er av.
    int ant_semester;             //  Antall semestre hittil brukt/vist.
    int semester[MAXSEMESTER+1];  //  Semestrene innslaget er brukt/vist,
                                  //     pÜ formen:  1xx = Vxx,  2xx = Hxx
    void skriv(int semest);       //  To interne funksjoner:
    void skriv(kategori kat);

  public:                    //  Definisjon/deklarasjon av medlemsfunksjoner:
    void skriv_data();                           //  Oppgave 2A
    void les_data();                             //  Oppgave 2B
    void brukt();                                //  Oppgave 2C
    bool er(kategori typ)  {  return (type == typ);  }
    bool vist(int sem);                          //  Oppgave 2E
    bool eldre(int aa);                          //  Oppgave 2F
    void les_fra_fil(istream* inn, char typ);    //  Oppgave 2G
    void skriv_til_fil(ostream* ut);             //  Extra
};

                    //  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les(char t[]);
void les(const char t[], char s[], const int LEN);
int  les(const char t[], const int min, const int max);

kategori les_kategori();
int      les_semester();

void skriv_innslag();        //  Oppgave 2A
void nytt_innslag();         //  Oppgave 2B
void brukt_innslag();        //  Oppgave 2C
void skriv_kategori();       //  Oppgave 2D
void skriv_semester();       //  Oppgave 2E
void skriv_eldre();          //  Oppgave 2F
void les_fra_fil();          //  Oppgave 2G
void skriv_til_fil();        //  Extra

                        //  GLOBALE VARIABLE:
Innslag innslagene[MAXINNSLAG+1];    //  Array med Innslag-objekter.
int siste_innslag;                   //  Indeks for siste Innslag hittil brukt.

							  
int main()  {           //  HOVEDPROGRAM:
   char kommando;

   les_fra_fil();                             //  Oppgave 2G
   skriv_meny();
   kommando = les("ùnske");
   while (kommando != 'Q')  {
     switch (kommando)  {
       case 'I':  skriv_innslag();   break;   //  Oppgave 2A
       case 'N':  nytt_innslag();    break;   //  Oppgave 2B
       case 'B':  brukt_innslag();   break;   //  Oppgave 2C
       case 'K':  skriv_kategori();  break;   //  Oppgave 2D
       case 'S':  skriv_semester();  break;   //  Oppgave 2E
       case 'E':  skriv_eldre();     break;   //  Oppgave 2F
       case 'T':  skriv_til_fil();   break;   //  Extra
       default:   skriv_meny();      break;
     }
     kommando = les("ùnske");
   }
  skriv_til_fil();                            //  Extra
  cout << "\n\n";
  return 0;
}


//  *****************   DEFINISJON AV KLASSE-FUNKSJONER:  *****************

                                     //  Gjõr om og skriver semester Xyy
void Innslag::skriv(int semest)  {   //    som 'V'yy eller 'H'yy: 
  cout << ((semest/100 == 1) ? "V" : "H")       //  1 --> V, 2 --> H
       << ((semest % 100 < 10) ? "0" : "") << semest % 100; // To siste sifre
}
                                     
void Innslag::skriv(kategori kat)  {  //  Enum-verdien 'kat' skrives som tekst:
  switch (kat)  {
    case Video:       cout << "Video";           break;
    case Audio:       cout << "Audio";           break;
    case Bilde:       cout << "Bilde";           break;
    case Web:         cout << "Webside/URL";     break;
    case Historie:    cout << "Historie/vits";   break;
    case Dokument:    cout << "Dokument";        break;
    case PPT:         cout << "Powerpoint";      break;
    default:          cout << "Ugyldig innslag-type!";    break;
  }
}

                                //  Skriver ALLE objektets data, bruker
void Innslag::skriv_data()  {   //    ogsÜ interne funksjoner til dette:
        //  Oppgave 2A:  Lag innmaten
}

                             
void Innslag::les_data()  {     //  Leser/setter objektets hoveddata:
        //  Oppgave 2B:  Lag innmaten
}

                         
void Innslag::brukt()  {        //  Setter at innslaget (igjen) er brukt:
        //  Oppgave 2C:  Lag innmaten
}

                                 //  Finner ut og returnerer om er
bool Innslag::vist(int sem)  {   //    vist/brukt et gitt semester:   
        //  Oppgave 2E:  Lag innmaten
}

                                 //  Finner ut og returnerer om er vist/brukt
bool Innslag::eldre(int aa)  {   //    de 10 siste Ürene fõr 'aa'.
        //  Oppgave 2F:  Lag innmaten
}


                                 //  Leser ALT om innslagene fra fil:
void Innslag::les_fra_fil(istream* inn, char typ)  {
        //  Oppgave 2G:  Lag innmaten
}

                                 //  Skriver ALT om innslagene til fil:
void Innslag::skriv_til_fil(ostream* ut)  {
        //  EXTRA
}



// **********************   DEFINISJON AV FUNKSJONER:    *********************

void skriv_meny()  {         //  Presenterer lovlige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER LOVLIG:\n";
  cout << "\tI   = skriv alt om ETT spesielt Innslag\n";
  cout << "\tN   = legg inn et Nytt innslag\n";
  cout << "\tB   = sett et innslag som Brukt (igjen)\n";
  cout << "\tK   = skriv ALLE innslag av en viss Kategori\n";
  cout << "\tS   = skriv ALLE innslag brukt et visst Semester\n";
  cout << "\tE   = skriv ALLE Eldre innslag (som er en stund siden vist/bruk)\n";
  cout << "\tT   = skriv Til fil\n";
  cout << "\tQ   = Quit/avslutt\n";
}


char les(char t[])  {        //  Henter ett ikke-blankt upcaset tegn:
  char ch;
  cout << '\n' << t << ":  ";   //  Skriver medsendt ledetekst.
  cin >> ch;   cin.ignore();    //  Leser ETT tegn. Forkaster '\n'.
  return (toupper(ch));         //  Upcaser og returnerer.
}

                             //  Leser inn en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {  
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, LEN);          //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
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

                             //  Leser type innslag som et tegn,
kategori les_kategori()  {   //    gjõr om og returnerer enum-verdi:
  char ch;
  do                               //  Looper til lovlig bokstav/tegn:
    ch = les("\tInnslag-type (V, A, B, W, H, D, P)");
  while (ch != 'V'  &&  ch != 'A'  &&  ch != 'B'  && 
         ch != 'W'  &&  ch != 'H'  &&  ch != 'D'  &&  ch != 'P');
  switch (ch)  {                   //  Returnerer aktuell enum-verdi:
    case 'V': return Video; case 'A': return Audio;    case 'B': return Bilde;
    case 'W': return Web;       case 'H': return Historie;
    case 'D': return Dokument;  case 'P': return PPT;
  }
}

                             //  Leser semester som 'V' eller 'H', samt et
int les_semester()  {        //    tosifret Ürstall (xx). Gjõr om til og
  char ch;                   //    returnerer 1xx eller 2xx (der 1=V, 2=H):
  int  nr;
  do
    ch = les("\tSemester (V, H)");         //  Leser semester.
  while (ch != 'V'  &&  ch != 'H');        //  Sikrer at er 'V' eller 'H'
  nr = les("èr", 0, 99);                   //  èrstall i intervallet: 0-99
  return (ch == 'V' ? 100+nr : 200+nr);    //  Vxx --> 1xx     Hxx --> 2xx
}


void skriv_innslag()  {      //  Skriver alt om õnsket innslag:
        //  Oppgave 2A:  Lag innmaten
}


void nytt_innslag()  {       //  Legger (om mulig) inn nytt innslag:
        //  Oppgave 2B:  Lag innmaten
}

                             //  Registrerer at allerede eksisterende
void brukt_innslag()  {      //    innslag er brukt/vist en gang til:
        //  Oppgave 2C:  Lag innmaten
}

                             
void skriv_kategori()  {     //  Skriver ALLE innslag i en gitt kategori: 
        //  Oppgave 2D:  Lag innmaten
}

                             
void skriv_semester()  {     //  Skriver ALLE innslag i et gitt semester:
        //  Oppgave 2E:  Beskriv hva som er ulikt ift 2D.
}

                             //  Skriver alle innslag (max 10 Ür)
void skriv_eldre()  {        //     eldre enn et visst Ürstall:
        //  Oppgave 2F:  Lag innmaten
}


void les_fra_fil()  {        //  Leser ALT fra fil:
        //  Oppgave 2G:  Lag innmaten
}


void skriv_til_fil()  {      //  Skriver ALT til fil:
        //  EXTRA
}

