#include <iostream>
#include "Mano.h"
using namespace std;

int mainMano() {
    Mano m;  // creo la mano

    // creo le carte usando la classe Card che abbiamo gia
    Card c1(0, 1);   // asso di cuori
    Card c2(3, 13);  // re di picche
    Card c3(1, 5);   // 5 di quadri

    // stampo quante carte ho allinizio
    cout << "Carte in mano: " << m.getNumCarte() << endl;

     // agggiungo le prime due carte e stampo
    m.aggiungiCarta(c1);
    m.aggiungiCarta(c2);
    cout << "Mano: " << m.toString() << endl;

      // agiungo terza carta e ristampo

    m.aggiungiCarta(c3);
    cout << "Mano: " << m.toString() << endl;

    // svuoto la mano e controllo
    m.svuota();
    cout << "Dopo svuota - Carte: " << m.getNumCarte() << endl;

    return 0;
}