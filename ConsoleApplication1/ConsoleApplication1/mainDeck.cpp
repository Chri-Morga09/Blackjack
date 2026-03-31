#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Deck.h"

using namespace std;

//0 fiori 
//1 cuori 
//2 picche
//3 quadri 

int mainDeck() {
    // Usa una conversione esplicita per evitare avvisi di perdita di dati
    srand(time(NULL));

    Deck mazzo;

    cout << "TEST CLASSE DECK" << endl;
    cout << "carte iniziali: " << mazzo.cardsLeft() << endl;

    // Pesca 5 carte di prova
    for (int i = 0; i < 5; ++i) {
        Card c = mazzo.drawCard();
        cout << "carta " << i + 1 << ": valore " << c.getRank() << " | seme " << c.getSuit() << endl;
    }

    cout << "carte rimaste dopo la pesca: " << mazzo.cardsLeft() << endl;

    // Test del reset
    mazzo.reset();
    cout << "mazzo resettato. carte disponibili: " << mazzo.cardsLeft() << endl;

    return 0;
}