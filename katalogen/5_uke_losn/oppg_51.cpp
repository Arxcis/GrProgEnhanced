//   Fil:  FRODEH \ CPP \ LAB_LOSN \ OPPG_51.CPP

//   L›sningsforslag til oppgave nr.51  i   C++ -programmering.


// ----------------------------------------------------------------------------
//  Program / oppg      : Enkel C‘sar kryptering
//  Skrevet av          : Andreas Moe - 11HBISA
//  Dato                : 17.01.2012
// ----------------------------------------------------------------------------
// Informasjon om programmet:
// Dette er et lite og enkelt program som tar en input fra brukeren, deretter
// sp›r om en n›kkel (mellom 0 og 25). Og gj›rer deretter c‘sar kryptering
// p† strengen.
//
// Mangler ved dette programmet:
//      - Sjekker ikke om input bare er bokstaver
//      - Tar bare CIN av input, og kan da kr‘sje ved at brukere skriver
//        inn en ugyldig streng ("Dette er en streng...!", funker d†rlig)
// ----------------------------------------------------------------------------

#include <iostream>                     // CIN - COUT
using namespace std;                    // STD::

const int MSGLEN  = 81;                 // Maks streng lengde av bruker input
const int ALFMIN =  0;                  // Minimum verdi for KEY
const int ALFMAX = 25;                  // Maximum verdi for KEY
const int ALFSTART = int('A');		    // Hva er ASCII verdien til A (65...)

int main()
{
     // Her deklarerer vi en KEY int (som setttes til -1 for † indikere at den
     // enda ikke er gyldig), og en int i for † bruke i for l›kker
     int key = -1, i;

     // Her lager vi to char arrays av lik st›rrelse, disse er for † holde p†
     // strengen brukeren gir oss, og den krypterte meldingen. Vi har ogs†
     // er char buffer som vi bruker under utregningen av krypteringen
     char plaintext[MSGLEN], chiper[MSGLEN], buffer;


     // Her sp›r vi brukeren om † gi oss meldingen de vil at vi skal kryptere
     cout << "Skriv inn din melding (Maks " << (MSGLEN - 1) << " tegn)\n> ";
     cin.getline(plaintext, MSGLEN);

     // Her setter vi hele strengen i UPPERCASE
     for (i = 0; i < strlen(plaintext); i++)
         { plaintext[i] = toupper(plaintext[i]); }

     // Her sp›r vi brukeren om en c‘sar KEY, som skal v‘re mellom 0 og 25
     while (key < ALFMIN || key > ALFMAX)
     {
        cout << "\nKey (" << ALFMIN << ".." << ALFMAX << "): ";
        cin >> key;
     }

     // Her looper vi igjennom teksten som brukeren ga oss, og utf›rer
     // C’SAR krypteringen...
     for (i = 0; i < strlen(plaintext); i++)
     {
        // Vi tar f›rst en bokstav, si f.eks 'A'. Vi trekker s† fra ALFSTART
        // som er 65 (siden A har ascii verdi 65). Da sitter vi igjen med 0.
        // Vi plusser s† p† n›kkelen og f†r v†rt fork›yede resultat. Deretter
        // Tar vi MOD ALFMAX (som er her 25 + 1, siden vi bare jobber med A-Z)
        buffer    = char(((plaintext[i] - ALFSTART) + key) % (ALFMAX + 1));

        // Vi tar s† bufferen og legger inn i kode strengen v†r, men plusser
        // f›rst p† ALFSTART (som var 65) slik at vi er tilbake til
        // plasseringen av store bokstaver i ascii tabelen. (65-90)
        chiper[i] = char(buffer + ALFSTART);
     }

     // Vi legger s† p† \0 for † indikere at strengen er avsluttet
     chiper[i] = '\0';

     // Strengene skrives ut for † vise hva resultatet ble
     cout << "\nOrginal  tekst: " << plaintext
          << "\nKryptert tekst: " << chiper << "\n\n";

     return 0;
}
