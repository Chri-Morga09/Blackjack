#include "InterfacciaUtente.h"
#include "GameEngine.h"

using namespace std;

// ============================================================
//  Costanti principali
// ============================================================

const int LARGHEZZA_FINESTRA = 900;
const int ALTEZZA_FINESTRA = 600;

const int RIGA_TITOLO_MAIN = 1;

const int RIGA_DOMANDA_NOME = 20;
const int COL_DOMANDA_NOME = 4;

const int RIGA_RISPOSTA_NOME = 22;
const int COL_RISPOSTA_NOME = 4;

// ============================================================
//  main
// ============================================================

int main() {
    // creo il Campo su cui disegnare
    Campo campo(LARGHEZZA_FINESTRA, ALTEZZA_FINESTRA, L"Test Blackjack",
        "C:/Windows/Fonts/seguisym.ttf");   // glifi Unicode
    // creo la Tastiera da cui ricevere l'input dell'utente
    Tastiera tastiera(campo);
    // inserisco Campo e Tastiera nella InterfacciaUtente
    InterfacciaUtente ui(campo, tastiera);

    // ------------------------------------------------------------
    // Richiesta nome giocatore
    // ------------------------------------------------------------
    wstring nomeGiocatore;

    nomeGiocatore = ui.leggiStringa(
        Posizione(RIGA_RISPOSTA_NOME, COL_RISPOSTA_NOME),
        Posizione(RIGA_DOMANDA_NOME, COL_DOMANDA_NOME),
        L"Come ti chiami?"
    );

    if (nomeGiocatore == L"") {
        nomeGiocatore = L"Giocatore";
    }

    // ------------------------------------------------------------
    // Saluto al giocatore e Schermata istruzioni
    // ------------------------------------------------------------

    ui.pulisci();

    ui.aggiungiTestoAlCentro(RIGA_TITOLO_MAIN, L"BLACKJACK - TEST INTERFACCIA");

    ui.aggiungiTestoAlCentro(RIGA_DOMANDA_NOME-3, L"Benvenuto " + nomeGiocatore + L" !");

    ui.aggiungiTestoAlCentro(RIGA_DOMANDA_NOME-1, L"In queso esempio per girare una carta premi il tasto 's' ");
    ui.aggiungiTestoAlCentro(RIGA_DOMANDA_NOME, L"premi ESC per terminare");
    ui.aggiungiTestoAlCentro(RIGA_DOMANDA_NOME+1, L"Premi un tasto per iniziare a giocare");

    ui.disegna();

    ui.leggiTastoBloccante();

    // ------------------------------------------------------------
    // Avvio GameEngine
    // ------------------------------------------------------------

    GameEngine gioco(ui, nomeGiocatore);
    gioco.run();

    // ------------------------------------------------------------
    // Saluto finale
    // ------------------------------------------------------------

    ui.pulisci();

    ui.aggiungiTestoAlCentro(RIGA_TITOLO_MAIN, L"FINE TEST BLACKJACK");
    ui.aggiungiTesto(Posizione(8, 8), L"Ciao ");
    ui.aggiungiTesto(Posizione(8, 14), nomeGiocatore);
    ui.aggiungiTesto(Posizione(10, 8), L"Hai ricevuto carte:");
    ui.aggiungiNumero(Posizione(10, 29), gioco.getCarteGiocatore());
    ui.aggiungiTesto(Posizione(14, 8), L"Premi ESC per terminare.");

    ui.disegna();

    // ------------------------------------------------------------
    // Attesa del tasto ESC ogni altro tasto non ha effetto
    // ------------------------------------------------------------
    int tasto;
    do {
        tasto = ui.leggiTastoBloccante();
    } while (ui.isAperta() && !ui.isEsc(tasto));

    return 0;
}