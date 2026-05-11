#pragma once
#include<iostream>
#include "Banco.h"
#include "Player.h"
using namespace std;

class Game {
private:
    Deck mazzo;
    Player giocatore;
    Banco banco;
    bool partitaInCorso;


public:
    Game();
    void distribuisciCarte();
    void turnoGiocatore();
    void turnoBanco();
    int determinaVincitore();
    bool continuaPartita();
    void resetPartita();
    Player& getGiocatore();
    Banco& getBanco();
};
