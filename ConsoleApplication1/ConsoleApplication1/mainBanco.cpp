#include <iostream>
#include "Banco.h"
#include "Deck.h"

using namespace std;

int mainBanco() {

    Deck mazzo;

    Banco banco;

    banco.aggiungiCarta(mazzo);
    banco.aggiungiCarta(mazzo);

    cout << "=== TEST BANCO ===" << endl;

    cout << banco.getMano().toString()<< endl;

    return 0;
}