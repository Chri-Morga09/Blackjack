#include <iostream>
#include <string>
#include "Player.h"
using namespace std;
int main()
{
	Player giocatore1 = Player("Alessandro");
	Player giocatore2 = Player("Marco");
	
	giocatore1.aggiornaFiche(200);
	giocatore2.aggiornaFiche(100);

	giocatore1.aggiornaValoreCarteAttuale(21);
	giocatore2.aggiornaValoreCarteAttuale(18);

	cout<<giocatore1.ToString();
	cout << endl;
	cout<<giocatore2.ToString();

}