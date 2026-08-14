#pragma once
#include "Mano.h"
#include "Deck.h"
class Banco
{
private:
	Mano mano;
public:
	Banco();
	void aggiungiCarta(Deck& mazzo); //riceve il mazzo originale
	Mano& getMano(); //evita copie inutili e permette modifiche dirette
	bool devePescare();
	void svuotaMano();
};
