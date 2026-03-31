#include "Deck.h"
#include <cstdlib> // Per rand()

// Costruttore
Deck::Deck() {
    reset();
}

// Crea le 52 carte standard
void Deck::generate() {
    int count = 0;
    for (int s = 0; s < 4; s++) {
        for (int r = 1; r <= 13; r++) {
            this->cards[count] = Card(s, r); 
            count++;
        }
    }
    this->topCardIndex = 0;
}

// Algoritmo di rimescolamento manuale
void Deck::shuffle() {
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = this->cards[i];
        this->cards[i] = this->cards[j];
        this->cards[j] = temp;
    }
    this->topCardIndex = 0; // Reset dell'indice dopo aver mischiato
}

// Pesca la carta in cima
Card Deck::drawCard() {
    if (this->topCardIndex >= 52) {
        reset(); // Se finiscono, ricomincia
    }
    return this->cards[topCardIndex++];
}

// Calcola quante carte restano
int Deck::cardsLeft() {
    return 52 - this->topCardIndex;
}

// Reset totale
void Deck::reset() {
    generate();
    shuffle();
}