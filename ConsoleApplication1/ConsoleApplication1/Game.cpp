#include "Game.h"
void Game::turnoGiocatore() {
    giocatore.aggiungiCarta(mazzo);
}

void Game::turnoBanco() {
    while (banco.devePescare()) {

        banco.aggiungiCarta(mazzo);
    }
}

int Game::determinaVincitore() {

    int valoreGiocatore =giocatore.getMano().calcolaValore();

    int valoreBanco =banco.getMano().calcolaValore();

    if (valoreGiocatore > 21) {

        return -1; //giocatore ha perso
    }

    if (valoreBanco > 21) {

        return 1; //banco ha sballato
    }

    if (valoreGiocatore > valoreBanco) {

        return 1; //giocatore ha vinto
    }

    if (valoreBanco > valoreGiocatore) {

        return -1; //giocatore ha perso
    }

    return 0;
}

bool Game::continuaPartita() {

    return partitaInCorso;
}

void Game::resetPartita() {

    giocatore.svuotaMano();
    banco.svuotaMano();
    mazzo.reset();
}

Player& Game::getGiocatore() {

    return giocatore;
}

Banco& Game::getBanco() {

    return banco;
}