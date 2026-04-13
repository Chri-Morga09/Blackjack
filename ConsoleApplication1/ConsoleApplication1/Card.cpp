#include "Card.h"

//costruttore vuoto: inizializza carta con valori di default
Card::Card() {

    this->suit = 0;  //seme di default
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

//imposta il sme;
void Card::setSuit(int s){

    this->suit = s;
}

//imposta il valore
void Card::setRank(int r){

    this->suit = r;
}


string Card::toString(){

    string semi[4];

    semi[0] = "Cuori";
    semi[1] = "Quadri";
    semi[2] = "Fiori";
    semi[3] = "Picche";

    string valori[14];

    valori[0] = "";
    valori[1] = "Asso";
    valori[2] = "2";
    valori[3] = "3";
    valori[4] = "4";
    valori[5] = "5";
    valori[6] = "6";
    valori[7] = "7";
    valori[8] = "8";
    valori[9] = "9";
    valori[10] = "10";
    valori[11] = "Jack";//box
    valori[12] = "Quen";
    valori[13] = "Re";
    

    string risultato = valori[this->rank] + " di " + semi[this->suit];
    return risultato;
}
