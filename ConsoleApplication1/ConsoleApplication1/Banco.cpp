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

    return mano.calcolaValore() < 17;
}

void Banco::svuotaMano() {

    mano.svuota();
}