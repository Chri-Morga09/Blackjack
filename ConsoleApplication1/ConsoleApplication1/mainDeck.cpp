#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Deck.h"

using namespace std;

//0 fiori 1 cuori 2 picche 3 quadri

int mainDeck() {
    n=5;
    srand(time(NULL));
    Deck mazzo;
    cout << "TEST CLASSE DECK" << endl;
    cout << "carte iniziali: " << mazzo.carteRimanenti() << endl;

    // pesca n carte di prova
    for (int i = 0; i < n; ++i) {
        Card c = mazzo.pescaCarta();
        cout << "carta " << i + 1 << ": valore " << c.getRank() << " | seme " << c.getSuit() << endl;
    }

    cout << "carte rimaste dopo la pesca: " << mazzo.carteRimanenti() << endl;

    // test del reset
    mazzo.reset();
    cout << "mazzo resettato. carte disponibili: " << mazzo.carteRimanenti() << endl;

    return 0;
}
