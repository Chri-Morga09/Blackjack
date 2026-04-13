#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Game::Game() {
    puntataCorrente = 0;
    partitaInCorso = false;
}

void Game::distribuisciCarte() {
    giocatore.aggiungiCarta(mazzo);
    giocatore.aggiungiCarta(mazzo);
    banco.aggiungiCarta(mazzo);
    banco.aggiungiCarta(mazzo);
    aggiornaPunteggi();
}

void Game::aggiornaPunteggi() {
    giocatore.getValoreManoAttuale();
    banco.getValoreManoAttuale();
}

void Game::iniziaGioco() {
    mazzo.reset();
    partitaInCorso = true;

    cout << "Hai " << giocatore.getFiche() << " fiche." << endl;
    cout << "Inserisci puntata: ";
    cin >> puntataCorrente;

    while (puntataCorrente > giocatore.getFiche() || puntataCorrente <= 0) {
        cout << "Puntata non valida. Riprova: ";
        cin >> puntataCorrente;
    }

    distribuisciCarte();
}

void Game::turnoGiocatore() {
    char scelta;
    cout << "--- INIZIO GIOCO ---" << endl;
    do {
        
        cout << "Hit (h) o Stand (s)? ";
        cin >> scelta;
        if (scelta == 'h') {
            giocatore.aggiungiCarta(mazzo);
            aggiornaPunteggi();
            mostraStato();
        }
    } while (scelta != 's' && giocatore.getValoreManoAttuale() <= 21);

    if (giocatore.getValoreManoAttuale() > 21) {
        cout << "Hai sballato!" << endl;
    }
}

void Game::turnoBanco() {
    while (banco.getValoreManoAttuale() < 17) {
        banco.aggiungiCarta(mazzo);
        aggiornaPunteggi();
    }
    cout << "Turno del banco terminato." << endl;
}
void Game::determinaVincitore() {
    int punteggioG = giocatore.getValoreManoAttuale();
    int punteggioB = banco.getValoreManoAttuale();

    cout << "Punteggio giocatore: " << punteggioG << endl;
    cout << "Punteggio banco: " << punteggioB << endl;

    if (punteggioG > 21)
    {
        cout << "Hai perso!" << endl;
        giocatore.perditaFiche(puntataCorrente);
    }
    else if (punteggioB > 21 || punteggioG > punteggioB)
    {
        cout << "Hai vinto!" << endl;
        giocatore.vincitaFiche(puntataCorrente);
    }
    else if (punteggioG < punteggioB)
    {
        cout << "Hai perso!" << endl;
        giocatore.perditaFiche(puntataCorrente);
    }
    else
    {
        cout << "Pareggio!" << endl;
    }

    cout << "Fiche attuali: " << giocatore.getFiche() << endl;
}

void Game::mostraStato() {
    cout << "Carte giocatore: " << giocatore.getValoreManoAttuale() << endl;
    cout << "Carte banco: " << banco.getValoreManoAttuale() << endl;
}

bool Game::continuaPartita() {
    return giocatore.getFiche() > 0 && mazzo.carteRimanenti() > 0;
}

void Game::resetPartita() {
    mazzo.reset();
    giocatore.svuotaMano();
    banco.svuotaMano();
    puntataCorrente = 0;
    partitaInCorso = true;
}
