#include <iostream>
#include "Game.h"

using namespace std;

int mainGame() {

    Game gioco;

    int risposta;

    do {

        gioco.distribuisciCarte();

        gioco.turnoGiocatore();

        gioco.turnoBanco();

        gioco.determinaVincitore();

        cout << endl << "Vuoi giocare ancora?" << endl;
        cout << "1 = Si" << endl;
        cout << "2 = No" << endl;

        cin >> risposta;

        while (risposta != 1 &&risposta != 2) {

            cout << "Scelta non valida. Reinserisci: ";

            cin >> risposta;
        }

        if (risposta == 1) {

            gioco.resetPartita();
        }

    } while (risposta != 2);

    return 0;
}