#include "Player.h"
#include"Card.h"
#include"Deck.h"
#include <string>

Player::Player()
{
	this->nome;
	this->fiche = 100;
	this->puntata = 0;
	this->ValoreManoAttuale = 0;
}

Player::Player(std::string nome)
{
	this->nome = nome;
	this->fiche = 100;
	this->puntata = 0;
	this->ValoreManoAttuale = 0;
}

void Player::vincitaFiche()
{
	this->fiche = this->fiche + this->puntata * 2;
}
void Player::perditaFiche()
{
	if (this->fiche > 0)
	{
		this->fiche = this->fiche - this->puntata;
	}
	else
	{
		this->fiche = 0;
	}
	
}
void Player::Puntata(int valore)
{
	if (valore < this->fiche&& valore>0)
	{
		this->puntata = valore;
	}
}
void Player::aggiungiCarta(Deck& mazzo)
{
	int valore = mazzo.drawCard().getRank();
	if (valore > 10)      
	{
		valore = 10;       // il valore di J/Q/R vale sempre 10
	}
	this->ValoreManoAttuale += valore;
	if (valore == 1)
	{
		if (this->ValoreManoAttuale + 10 <= 21)
			this->ValoreManoAttuale += 10; 
	}
}
void Player::svuotaMano()
{
	this->ValoreManoAttuale = 0;
}

int Player::getFiche()
{
	return this->fiche;
}
int Player::getValoreManoAttuale()
{
	return this->ValoreManoAttuale;
}int Player::getPuntata()
{
	return this->puntata;
}
std::string Player::getNome()
{
	return this->nome;
}
std::string Player::ToString()
{
	std::string s;
	s = "nome: " +this->nome +" fiche: " + std::to_string(this->fiche) + " valore carte attuale: " + std::to_string(this->ValoreManoAttuale);
	return s;

}