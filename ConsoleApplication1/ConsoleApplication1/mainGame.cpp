#include "Game.h"
#include <iostream>
using namespace std;

int mainGame() {    
    Game gioco;
    int risposta;
    cout << "TEST CLASSE GAME" << endl;
    gioco.iniziaGioco();
    gioco.mostraStato();
    gioco.turnoGiocatore();
    gioco.turnoBanco();
    gioco.determinaVincitore();

    do {


        cout << "Vuoi giocare ancora?" << endl;
        cout << "1 == si" << endl;
        cout << "2 == no" << endl;
        cin >> risposta;
        if (risposta == 1)
        {
            gioco.resetPartita();
            gioco.iniziaGioco();
            gioco.mostraStato();
            gioco.turnoGiocatore();
            gioco.turnoBanco();
            gioco.determinaVincitore();
        }
        if (risposta != 1 && risposta != 2)
        {
            cout << "scelta non valida. Reinseriscila" << endl;
        }
        
    } while (risposta != 2);
    


    return 0;
}