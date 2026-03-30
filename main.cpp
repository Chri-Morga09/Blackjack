#include <iostream>
#include "Card.h"
using namespace std;

int main() {
    // creazione di due carte
    Card c1;          
    Card c2(2, 11);   

    // stampa dei dati delle carte
    cout << "Carta 1: seme=" << c1.getSuit() << ", valore=" << c1.getRank() << endl;
    cout << "Carta 2: seme=" << c2.getSuit() << ", valore=" << c2.getRank() << endl;

    return 0;  // fine del programma
}