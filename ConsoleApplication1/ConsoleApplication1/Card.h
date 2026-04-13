#pragma once
#include <string>
using namespace std;

class Card {

private:
     int suit; //seme della carta
    int rank;  //valire della carta

public:
    Card();  //costruttore vuoto che crea carta di default
    Card(int s, int r); //costruttore con parametri vche crea carta specifica

    int getSuit();//restituisce il seme
    int getRank();//restituisce il valorw
    void setSuit(int s); //imposta il seme
    void setRank(int r);//imposta il valore

    string toString();
};