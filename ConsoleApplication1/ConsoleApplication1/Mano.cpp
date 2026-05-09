#include "Mano.h"
using namespace std;

// parto con zero carte in mano
Mano::Mano() {

    this->numCarte = 0;
}

// agiungo la carta nella prima posizione libera
void Mano::aggiungiCarta(Card c) {

    this->carte[this->numCarte] = c;  // meto la carta
    this->numCarte++;                  // aggiorno il contatore
}

// ritorna la carta in posizione i
Card Mano::getCarta(int i) {

    return this->carte[i];
}

// ritorna quante carte ho in mano
int Mano::getNumCarte() {

    return this->numCarte;
}

// calcola il valore totale dela mano
int Mano::calcolaValore() {

    int totale = 0;
    int assi = 0;

    // scorro tute le carte e sommo i valori
    for (int i = 0; i < this->numCarte; i++) {

        int r = this->carte[i].getRank();
        if (r == 1) { totale += 11; assi++; }  // lasso vale 11
        else if (r >= 10) { totale += 10; }           // figure valgono 10
        else { totale += r; }            // gli altri il loro valore
    }

    // se sforo 21 lasso diventa 1
    while (totale > 21 && assi > 0) {

        totale -= 10;
        assi--;
    }

    return totale;
}

// svuoto la mano, azzero il contatore
void Mano::svuota() {

    this->numCarte = 0;
}

// creo la stringa con tute le carte e il totale
string Mano::toString() {

    string risultato = "";
    for (int i = 0; i < this->numCarte; i++) {
        risultato += this->carte[i].toString();  // agiungo la carta
        if (i < this->numCarte - 1) {
            risultato += ", ";  // meto la virgola tra le carte
        }
    }
    risultato += " | Totale: " + to_string(this->calcolaValore());  // agiungo il totale
    return risultato;
}