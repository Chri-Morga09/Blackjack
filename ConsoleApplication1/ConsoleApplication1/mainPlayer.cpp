#include <iostream>
#include <string>
#include "Player.h"
#include"Deck.h"
using namespace std;
int mainPlayer()
{
	cout << "TEST CLASSE PLAYER" << endl;
	Player giocatore1 = Player("Alessandro");

	Deck mazzo;
	giocatore1.vincitaFiche(200);


	giocatore1.perditaFiche(100);


	giocatore1.aggiungiCarta(mazzo);


	std::string nome1 = giocatore1.getNome();
	int fiche1 = giocatore1.getFiche();
	cout<<giocatore1.ToString();


	return 0;
}
