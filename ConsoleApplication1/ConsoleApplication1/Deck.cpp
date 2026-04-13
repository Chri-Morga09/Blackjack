#include "Deck.h"
#include <ctime>

srand(time(NULL));

Deck::Deck() {
    reset();
}

// crea le 52 carte standard
void Deck::generaMazzo() {
    int contatore = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            this->carte[contatore] = Card(i, j); 
            contatore++;
        }
    }
    this->indiceProxCarta = 0;
}

// rimescola carte
void Deck::mescola() {
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = this->carte[i];
        this->carte[i] = this->carte[j];
        this->carte[j] = temp;
    }
    this->indiceProxCarta = 0; // reset dell'indice dopo aver mischiato
}

// pesca la carta in cima
Card Deck::pescaCarta() {
    if (this->indiceProxCarta >= 52) {
        reset(); // se finiscono ricomincia
    }
    return this->carte[indiceProxCarta++];
}

// Calcola quante carte restano
int Deck::carteRimanenti() {
    return 52 - this->indiceProxCarta;
}

// Reset totale
void Deck::reset() {
    generaMazzo();
    mescola();
}
