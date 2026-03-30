#pragma once

class Card {

private:

    int suit;  // seme della carta
    int rank;  // valire della carta

public:
    Card();                  // costruttore vuoto che crea carta di default
    Card(int s, int r);      // costruttore con parametri vche crea carta specifica

    int getSuit();           // restituisce il seme
    int getRank();           // restituisce il valorw
};