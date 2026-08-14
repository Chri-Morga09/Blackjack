#pragma once
#include "Card.h"
class Deck {
private:
    Card carte[52];  // vettore che contiene le 52 carte
    int indiceProxCarta;  // indice della prossima carta da pescare
    void generaMazzo();  // riempie il mazzo in ordine in modo casuale

public:
    Deck();            
     
    void mescola();   
    Card pescaCarta();
    int carteRimanenti();   
    void reset();        // rigenera e rimescola il mazzo
};
