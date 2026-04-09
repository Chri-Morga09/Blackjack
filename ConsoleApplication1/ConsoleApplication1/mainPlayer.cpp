#include <iostream>
#include <string>
#include "Player.h"
using namespace std;
int main()
{
	Player giocatore1 = Player("Alessandro");
	Player giocatore2 = Player("Marco");
	
	giocatore1.vincitaFiche(200);
	giocatore2.vincitaFiche(100);

	giocatore1.perditaFiche(100);
	giocatore2.perditaFiche(500);

	giocatore1.aggiornaValoreCarteAttuale(21);
	giocatore2.aggiornaValoreCarteAttuale(18);

	std::string nome1 = giocatore1.getNome();
	int fiche1 = giocatore1.getFiche();
	cout<<giocatore1.ToString();
	cout << endl;
	cout<<giocatore2.ToString();

}
