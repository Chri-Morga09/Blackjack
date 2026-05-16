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
	int p;
	cout << "Quanto vuoi puntare?";
	cout << " Fiche= " << giocatore1.getFiche() << endl;
	cin >> p;
	giocatore1.Puntata(p);

	giocatore1.aggiungiCarta(mazzo);
	giocatore1.aggiungiCarta(mazzo);
	cout << giocatore1.ToString() << endl;

	giocatore1.vincitaFiche();
	cout << giocatore1.getFiche();

	return 0;
}
