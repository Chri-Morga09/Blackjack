#include <iostream>
#include <string>
#include "Player.h"
#include"Card.h"
using namespace std;
int mainPlayer()
{
	Player giocatore1 = Player("Alessandro");
	Player giocatore2 = Player("Marco");
	
	giocatore1.vincitaFiche(200);
	giocatore2.vincitaFiche(100);

	giocatore1.perditaFiche(100);
	giocatore2.perditaFiche(500);

	giocatore1.aggiornaManoAttuale(21);
	giocatore2.aggiornaManoAttuale(18);

	std::string nome1 = giocatore1.getNome();
	int fiche1 = giocatore1.getFiche();
	cout<<giocatore1.ToString();
	cout << endl;
	cout<<giocatore2.ToString();

}
