#include "Card.h"

//costruttore vuoto: inizializza carta con valori di default
Card::Card() {
    this->suit = 0;  // seme di default
    this->rank = 1;  // valore di default (asso)
}

//costruttore con parametri: inizializza carta con seme e valore scelti
Card::Card(int s, int r) {
    this->suit = s;
    this->rank = r;
}

//restituisce il seme della carta
int Card::getSuit() {
    return this->suit;
}

//restituisce il valore della carta
int Card::getRank() {
    return this->rank;
}