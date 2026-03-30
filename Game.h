#pragma once
#include<iostream>
#include "Deck.h"
#include "Player.h"
using namespace std;

class Game {
private:
    Deck mazzo;
    Player giocatore;
    Player banco;
    int puntataCorrente;
    bool partitaInCorso;
    void distribuisciCarte();
    void aggiornaPunteggi();

public:
    Game();
    void iniziaGioco();
    void turnoGiocatore();
    void turnoBanco();
    void determinaVincitore();
    void mostraStato();
    bool continuaPartita();
    void resetPartita();
};
