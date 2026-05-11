#pragma once

#include "Card.h"
#include <string>
using namespace std;

class Mano {
private:
    Card carte[12];  // le carte dela mano, massimo 12
    int numCarte;   // quante carte ho in mano
    bool coperta;  //attributo stato carta;

public:
    Mano();                      // costruttore, parto senza carte
    void aggiungiCarta(Card c);  // agiungo una carta
    Card getCarta(int i);        // prendo la carta in posizione i
    int getNumCarte();           // quante carte ho
    int calcolaValore();         // calcola il totale dele carte
    void svuota();               // svuoto la mano
    string toString();           // stampa le carte
};