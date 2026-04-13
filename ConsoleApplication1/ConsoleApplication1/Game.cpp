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
    mazzo.shuffle();
    puntataCorrente = 0;
    partitaInCorso = true;
    distribuisciCarte();
    
}

void Game::turnoGiocatore() {
    char scelta;
    do {
        cout << "--- INIZIO GIOCO ---" << endl;
        cout << "Hit (h) o Stand (s)? ";
        cin >> scelta;
        if (scelta == 'h') {
            giocatore.aggiungiCarta(mazzo);
            aggiornaPunteggi();
            mostraStato();
        }
    } while (scelta != 's');

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
    }
    else if (punteggioB > 21 || punteggioG > punteggioB)
    {
        cout << "Hai vinto!" << endl;
    }    
    else if (punteggioG < punteggioB)
    {
        cout << "Hai perso!" << endl;
    }
    else
    {
        cout << "Pareggio!" << endl;
    }   
}

void Game::mostraStato() {
    cout << "Carte giocatore: " << giocatore.getValoreManoAttuale() << endl;
    cout << "Carte banco: " << banco.getValoreManoAttuale() << endl;
}

bool Game::continuaPartita() {
    return giocatore.getFiche() > 0 && mazzo.cardsLeft() > 0;
}

void Game::resetPartita() {
    mazzo.reset();
    giocatore.svuotaMano();
    banco.svuotaMano();
    puntataCorrente = 0;
    partitaInCorso = true;
}
