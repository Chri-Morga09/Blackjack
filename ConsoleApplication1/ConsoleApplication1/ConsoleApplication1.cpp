#include <iostream>

using namespace std;

// Test classi
int mainCard();
int mainDeck();
int mainMano();
int mainPlayer();
int mainBanco();

// Gioco
int mainGame();

int main() {
    srand(time(NULL));
    cout << "==========================" << endl;
    cout << "     TEST DELLE CLASSI    " << endl;
    cout << "==========================" << endl;

    cout << endl;
    mainCard();

    cout << endl;
    mainDeck();

    cout << endl;
    mainMano();

    cout << endl;
    mainPlayer();

    cout << endl;
    mainBanco();

    cout << endl;
    cout << "==========================" << endl;
    cout << "      AVVIO GIOCO         " << endl;
    cout << "==========================" << endl;

    cout << endl;

    // Avvio blackjack
    mainGame();

    return 0;
}
    

