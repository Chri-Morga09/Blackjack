#include "Game.h"
#include <iostream>
using namespace std;

int mainGame() {    
    Game gioco;

    cout << "TEST CLASSE GAME" << endl;
    gioco.iniziaGioco();
    gioco.mostraStato();
    gioco.turnoGiocatore();
    gioco.turnoBanco();
    gioco.determinaVincitore();
    
    return 0;
}