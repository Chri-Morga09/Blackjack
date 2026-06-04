#include "GameEngine.h"

// ============================================================
//  Costanti schermata
// ============================================================

const int RIGA_TITOLO = 1;

const int RIGA_BANCO = 3;
const int COL_BANCO = 8;

const int RIGA_MAZZO = 3;
const int COL_MAZZO = 25;

const int RIGA_GIOCATORE = 11;
const int COL_GIOCATORE = 8;

const int RIGA_DOMANDA = 22;
const int COL_DOMANDA = 4;

const int RIGA_RISPOSTA = 23;
const int COL_RISPOSTA = 4;

GameEngine::GameEngine(InterfacciaUtente& ui, wstring nomeGiocatore)
    : ui(ui)    // qui GameEngine usa un riferimento a InterfacciaUtente, 
                // quindi nel costruttore è necessario usare la lista di inizializzazione : ui(ui)
{
    this->nomeGiocatore = nomeGiocatore;
    this->carteGiocatore = 0;
}

int GameEngine::getCarteGiocatore()
{
    return carteGiocatore;
}

void GameEngine::run() {
    bool continua = true;
    int risposta;

    // In questo ciclo di gioco, 
    while (continua == true) {

		// prima si prepara la scena da mostrare al giocatore (mostraCampoGioco)
		// con la visualizzazione della domanda "Vuoi una carta?".
		disegnaCampoEDomanda(L"Vuoi una carta? (s/n):");

		// Poi si aspetta la risposta del giocatore (leggiTastoBloccante) e si agisce di conseguenza.
        risposta = ui.leggiTastoBloccante();

        if (risposta == 's' || risposta == 'S') {
			// Se il giocatore vuole una carta, si simula la ricezione di una carta (spostaCartaGiocatore) 
            spostaCartaGiocatore(
                Posizione(RIGA_MAZZO + 1, COL_MAZZO),
                Posizione(RIGA_GIOCATORE + 6, COL_GIOCATORE + (carteGiocatore - 1))
			);
            // e si aggiorna il numero di carte ricevute.
            carteGiocatore = carteGiocatore + 1;
        }
        else {
            continua = false;
        }
    }
}

void GameEngine::aggiungiSfondo() {
    // Titolo
    ui.aggiungiTestoAlCentro(RIGA_TITOLO, L"BLACKJACK");

    // Mazzo
    ui.aggiungiTesto(Posizione(RIGA_MAZZO, COL_MAZZO), L"MAZZO");
    ui.aggiungiImmagine(Posizione(RIGA_MAZZO + 1, COL_MAZZO), "./images/retroBlu.png", 0.5f, 0.5f);

    // Banco
    ui.aggiungiTesto(Posizione(RIGA_BANCO, COL_BANCO), L"BANCO");
    ui.aggiungiRettangoloVuoto(Posizione(RIGA_BANCO + 1, COL_BANCO), 12, 5, sf::Color::White);
    ui.aggiungiTesto(Posizione(RIGA_BANCO + 3, COL_BANCO + 3), L"MAZZO");
    ui.aggiungiImmagine(Posizione(RIGA_BANCO + 1, COL_BANCO), "./images/retroRosso.png", 0.5f, 0.5f);
    ui.aggiungiImmagine(Posizione(RIGA_BANCO + 1, COL_BANCO + 2), "./images/retroBlu.png", 0.5f, 0.5f);
    ui.aggiungiImmagine(Posizione(RIGA_BANCO + 1, COL_BANCO + 4), "./images/retroRosso.png", 0.5f, 0.5f);

    // Giocatore
    ui.aggiungiRettangoloVuoto(Posizione(RIGA_GIOCATORE, COL_GIOCATORE), 12, 5, sf::Color::Yellow);
    ui.aggiungiTesto(Posizione(RIGA_GIOCATORE + 2, COL_GIOCATORE + 3), L"CARTE");
    ui.aggiungiTesto(Posizione(RIGA_GIOCATORE + 6, COL_GIOCATORE), L"Giocatore: " + nomeGiocatore);
    for (int c = 0; c < carteGiocatore; c++) {
        ui.aggiungiImmagine(Posizione(RIGA_GIOCATORE, COL_GIOCATORE + c * 2), "./images/AssoPicche.png", 0.5f, 0.5f);
    }

    // Numero carte
    ui.aggiungiTesto(Posizione(RIGA_GIOCATORE + 8, COL_GIOCATORE), L"Carte ricevute:");
    ui.aggiungiNumero(Posizione(RIGA_GIOCATORE + 8, COL_GIOCATORE + 17), carteGiocatore);
}


void GameEngine::disegnaCampoEDomanda(wstring domanda)
{
    ui.pulisci();

    // si aggiunge lo sfondo con le carte del giocatore,
    aggiungiSfondo();
    ui.aggiungiTesto(Posizione(RIGA_DOMANDA, COL_DOMANDA), domanda);

    ui.disegna();
}

void GameEngine::spostaCartaGiocatore(Posizione inizio, Posizione fine)
{
    int numPassi = 50; // numero di passi per l'animazione
	// coordinate iniziali e finali in pixel
    float x = inizio.getColonna() * LARGHEZZA_CELLA;
    float y = inizio.getRiga() * ALTEZZA_CELLA;

	// calcolo del passo di movimento in pixel per ogni frame
    float dx = (fine.getColonna() - inizio.getColonna()) * LARGHEZZA_CELLA / numPassi;
    float dy = (fine.getRiga() - inizio.getRiga()) * ALTEZZA_CELLA / numPassi;
	
    for (int passo = 0; passo < numPassi; passo++) {
		// In ogni passo dell'animazione, si pulisce la schermata
        ui.pulisci();

        // si aggiunge lo sfondo con le carte del giocatore,
        aggiungiSfondo();

		// e si aggiunge la carta in movimento alla nuova posizione.
        ui.aggiungiImmagine(x, y, "./images/AssoPicche.png", 0.5f, 0.5f);

		// Si mostra il frame corrente.
        ui.disegna();

		// Per rallentare l'animazione, si può inserire una breve pausa.
		ui.sleep(50); // usando la funzione sleep definita in InterfacciaUtente

        x = x + dx * passo / numPassi;
        y = y + dy * passo / numPassi;
	}
}
