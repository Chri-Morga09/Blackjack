#include "Game.h"
#include <iostream>
using namespace std;

int main() {    
    Game gioco;

    gioco.iniziaGioco();
    gioco.mostraStato();
    gioco.turnoGiocatore();
    gioco.turnoBanco();
    gioco.determinaVincitore();
    
    return 0;
}