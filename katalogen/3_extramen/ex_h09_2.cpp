//  Fil:   FRODEH \ C++ \ EXTRAMEN \ EX_H09_2.CPP

//  Lõsningsforslag til eksamen i C++, 7.desember 2009, oppgave 2.
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

                                //  Oppgave 2A - Skriver ALLE objektets data,
void Innslag::skriv_data()  {   //    bruker ogsÜ interne funksjoner til dette:
  cout << "\n\t";     skriv(type);     cout << ": " << beskrivelse;
  cout << "\n\tVist " << ant_semester << " ganger:";
  for (int i = 1;  i <= ant_semester;  i++) {  //  Skriver alle semstrene:
      cout << "  ";   skriv(semester[i]);  
  }
  cout << '\n';
}

                             //  Oppgave 2B - Leser/setter objektets hoveddata:
void Innslag::les_data()  {
  les("Beskrivelse (fil, URL, ....)", beskrivelse, STRLEN);
  type = les_kategori();
  ant_semester = 0;
}

                         //  Oppgave 2C - Setter at innslaget (igjen) er brukt:
void Innslag::brukt()  {
  if (ant_semester < MAXSEMESTER)  {    //  Plass til enda en registrering:
     cout << "\n\tInnslaget: " << beskrivelse << " er brukt\n";
     semester[++ant_semester] = les_semester();  //  Legger inn nytt semester.
  } else                                //  Ikke plass til fler registreringer:
     cout << "\n\n\tInnslaget er vist " << MAXSEMESTER
          << " ganger allerede (som er max registreringer).\n";
}

                                 //  Oppgave 2E - Finner ut og returnerer om
bool Innslag::vist(int sem)  {   //    er vist/brukt et gitt semester:   
  for (int i = 1;  i <= ant_semester;  i++)
      if (semester[i] == sem)  return true;  //  Treff pÜ semester.
  return false;                  //  If-setningen over slo aldri til.
}

                                 //  Oppgave 2F - Finner ut og returnerer om er
bool Innslag::eldre(int aa)  {   //    vist/brukt de 10 siste Ürene fõr 'aa'.
  int i, j;
  for (i = 0;  i < MAXBAKOVER;  i++)          //  GÜr gjennom 10 Ür:
      for (j = 1;  j <= ant_semester;  j++)   //  Ser pÜ semestrene brukt/vist.
                                 //  To siste sifrene i tallene er like:
          if ((semester[j] % 100) == ((aa-i) % 100)) return true;
  return false;
}


                             //  OPPGAVE 2G - Leser ALT om innslagene fra fil:
void Innslag::les_fra_fil(istream* inn, char typ)  {
  switch (typ)  {                        //  Gjõr om bokstav til enum-verdi:
    case 'V':  type = Video;     break;    case 'A':  type = Audio;     break;
    case 'B':  type = Bilde;     break;    case 'W':  type = Web;       break;
    case 'H':  type = Historie;  break;    case 'D':  type = Dokument;  break;
    case 'P':  type = PPT;       break;
  }
  *inn >> ant_semester;                  //  Leser antall semestre vist/brukt.
  for (int i = 1;  i <= ant_semester;  i++)
      *inn >> semester[i];               //  Leser alle semestrene.
  (*inn).ignore();
  (*inn).getline(beskrivelse, STRLEN);   //  Leser beskrivelsen.
}

                             //  EXTRA - Skriver ALT om innslagene til fil:
void Innslag::skriv_til_fil(ostream* ut)  {
  switch (type)  {                       //  Skriver enum-verdi som bokstav:
    case Video:    *ut << 'V'; break;
    case Audio:    *ut << 'A'; break;
    case Bilde:    *ut << 'B'; break;
    case Web:      *ut << 'W'; break;
    case Historie: *ut << 'H'; break;
    case Dokument: *ut << 'D'; break;
    case PPT:      *ut << 'P'; break;
   }
  *ut << ' ' << ant_semester;           //  Skriver antall semestre vist/brukt:
  for (int i = 1;  i <= ant_semester;  i++)   //  Skriver alle semestrene:
      *ut << ' ' << semester[i];        
  *ut << '\n' << beskrivelse << '\n';   //  Skriver beskrivelse,
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


void skriv_innslag()  {      //  Oppgave 2A - Skriver alt om õnsket innslag:
  innslagene[les("Se ALT om innslag nr", 1, siste_innslag)].skriv_data();
}


void nytt_innslag()  {     //  Oppgave 2B - Legger (om mulig) inn nytt innslag:
  if (siste_innslag < MAXINNSLAG)             //  Plass til flere:
     innslagene[++siste_innslag].les_data();  //  Nytt objekt -  data leses:
  else                                        //  Fullt:
     cout << "\n\n\tFullt med " << MAXINNSLAG 
          << " innslag i datastrukturen allerede!\n";
}

                          //  Oppgave 2C - Registrerer at allerede eksisterende
void brukt_innslag()  {   //    innslag er brukt/vist en gang til:
  int nr;                 //  ùnsket (innslags) nummer er ulikt 0:
  if ((nr = les("Nylig brukt innslag nr", 0, siste_innslag)) != 0)
     innslagene[nr].brukt();   //  Registreres igjen som brukt/vist.
}

                      //  Oppgave 2D - Skriver ALLE innslag i en gitt kategori:
void skriv_kategori()  {      
  bool funn = false;                 //  Hittil ingen utskrift.
  kategori type = les_kategori();    //  Leser õnsket kategori.

  for (int i = 1;  i <= siste_innslag;  i++)  //  GÜr gjennom alle innslagene:
      if (innslagene[i].er(type))  {          //  Er av aktuell kategori?
         funn = true;                         //  Utskrift har forekommet.
         innslagene[i].skriv_data();          //  Skriver alt om innslaget.
      }
  if (!funn)                                  //  Ingen utskrifter foretatt:
     cout << "\n\tIngen innslag av denne kategorien.\n";
}

                      //  Oppgave 2E - Skriver ALLE innslag i et gitt semester:
void skriv_semester()  {   //   (For kommentarer:  se 2D ovenfor)
  bool funn = false;
  int  sem = les_semester();               //  Ulikt 2D (se rett ovenfor).

  for (int i = 1;  i <= siste_innslag;  i++)
      if (innslagene[i].vist(sem))  {      //  Noe ulikt 2D (se rett ovenfor).
         funn = true;
         innslagene[i].skriv_data();
      }
  if (!funn)
     cout << "\n\tIngen innslag ble vist/brukt dette semesteret.\n";
}

                         //  Oppgave 2F - Skriver alle innslag (max 10 Ür)
void skriv_eldre()  {    //     eldre enn et visst Ürstall:
  int aar = les("èr", STARTAAR, SLUTTAAR);     //  Leser lovlig Ürstall.

  for (int i = 1;  i <= siste_innslag;  i++)   //  GÜr gjennom alle innslagene:
      if (innslagene[i].eldre(aar))            //  Innslaget eldre enn Üret.
         innslagene[i].skriv_data();           //  Skriver alt om innslaget.
}


void les_fra_fil()  {        //  OPPGAVE 2G - Leser ALT fra fil:
  char tegn;                     //  Fõrste tegn (=innslag-type) i en post.
  ifstream innfil("INNSLAG.DTA");
  
  if (innfil)  {                 //  Filen finnes:
     siste_innslag = 0;          //  Nullstiller global variabel.
     innfil >> tegn;             //  Leser (om mulig) det fõrste tegnet.
                                 //   Ikke slutt og fortsatt plass:
     while (!innfil.eof() &&  siste_innslag < MAXINNSLAG)  {
                                 //  Objektene leser resten selv:
       innslagene[++siste_innslag].les_fra_fil(&innfil, tegn); 
       innfil >> tegn;           //  Leser (om mulig) det neste tegnet.
     }
  } else
    cout << "\n\n\tFant ikke filen 'INNSLAG.DTA'\n";
}


void skriv_til_fil()  {      //  EXTRA - Skriver ALT til fil:
  int i;
  ofstream utfil("INNSLAG.DTA");             //  èpner aktuell fil.

  for (i = 1;  i <= siste_innslag;  i++)     //  GÜr gjennom ALLE innslagene:
      innslagene[i].skriv_til_fil(&utfil);   //  De skriver seg selv til fil.
}
