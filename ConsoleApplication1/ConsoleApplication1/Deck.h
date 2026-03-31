#pragma once
#include "Card.h"
class Deck {
private:
    Card cards[52];      // Array statico di 52 carte
    int topCardIndex;    // Indice della prossima carta da pescare

    void generate();     // Riempie il mazzo in ordine

public:
    Deck();              // Costruttore
     
    void shuffle();      // Mescola il mazzo 
    Card drawCard();     // Pesca una carta
    int cardsLeft();     // Quante carte rimangono
    void reset();        // Rigenera e rimescola
};
