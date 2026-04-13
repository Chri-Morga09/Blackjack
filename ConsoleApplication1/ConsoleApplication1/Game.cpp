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
    giocatore.aggiungiCarta(mazzo.drawCard().getRank());
    giocatore.aggiungiCarta(mazzo.drawCard().getRank());
    banco.aggiungiCarta(mazzo.drawCard().getRank());
    banco.aggiungiCarta(mazzo.drawCard().getRank());
    aggiornaPunteggi();
}

void Game::aggiornaPunteggi() {
    giocatore.getPunteggio();
    banco.getPunteggio();
}

void Game::iniziaGioco() {
    mazzo.shuffle();
    puntataCorrente = 0;
    partitaInCorso = true;
    distribuisciCarte();
    mostraStato();
}

void Game::turnoGiocatore() {
    char scelta;
    do {
        cout << "Hit (h) o Stand (s)? ";
        cin >> scelta;
        if (scelta == 'h') {
            giocatore.aggiungiCarta(mazzo.drawCard().getRank());
            aggiornaPunteggi();
            mostraStato();     
        }
    } while (scelta != 's');

    if (giocatore.getPunteggio() > 21) {
        cout << "Hai sballato!" << endl;
    }
}

void Game::turnoBanco() {
    while (banco.getPunteggio() < 17) {
        banco.aggiungiCarta(mazzo.drawCard().getRank());
        aggiornaPunteggi();
    }
    cout << "Turno del banco terminato." << endl;
}

void Game::determinaVincitore() {
    int punteggioG = giocatore.getPunteggio();
    int punteggioB = banco.getPunteggio();

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
    cout << "Carte giocatore: " << giocatore.getPunteggio() << endl;
    cout << "Carte banco: " << banco.getPunteggio() << endl;
}

bool Game::continuaPartita() {
    return giocatore.getFiches() > 0 && mazzo.cardsLeft() > 0;
}

void Game::resetPartita() {
    mazzo.reset();
    giocatore.svuotaMano();
    banco.svuotaMano();
    puntataCorrente = 0;
    partitaInCorso = true;
}
