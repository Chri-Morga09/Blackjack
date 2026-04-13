#include <iostream>

int mainGame();
int mainDeck();
int mainCard();
int mainPlayer();

int main()
{
    srand(time(NULL));
    mainPlayer();
    mainCard();
    mainDeck();
    mainGame();
    
   
}
