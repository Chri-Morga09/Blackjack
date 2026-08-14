#include "Banco.h"
using namespace std;
Banco::Banco() {

}
void Banco::aggiungiCarta(Deck& mazzo) {

    mano.aggiungiCarta(mazzo.pescaCarta());
}

Mano& Banco::getMano() {

    return mano;
}

bool Banco::devePescare() {

    if (mano.calcolaValore() < 17)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Banco::svuotaMano() {

    mano.svuota();
}