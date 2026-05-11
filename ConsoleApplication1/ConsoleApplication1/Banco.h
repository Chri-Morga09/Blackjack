#pragma once
#include "Mano.h"
#include "Deck.h"
class Banco
{
private:
	Mano mano;
public:
	Banco();
	void aggiungiCarta(Deck& mazzo);
	Mano& getMano();
	bool devePescare();
	void svuotaMano();
};
