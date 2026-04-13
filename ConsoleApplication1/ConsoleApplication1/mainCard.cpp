#include <iostream>
#include "Card.h"
using namespace std;

int mainCard() {

    //carta inizio
    Card c1;      
    cout << endl<<"Carta 1: " << c1.toString() << endl;

    //jack di picche
    Card c2(3, 11);   
    cout << "Carta 2. " << c2.toString() << endl;

    c1.setSuit(2);
    c1.setRank(13);
    cout << "Carta 1 modificata: " << c1.toString() << endl;

    return 0;  
}