#include <iostream>
#include "Card.h"

using namespace std;

int mainCard() {

    Card carta1(0, 1);
    Card carta2(3, 13);

    cout << "=== TEST CARD ===" << endl;

    cout << carta1.toString() << endl;
    cout << carta2.toString() << endl;

    return 0;
}