#include "Player.h"
#include"Card.h"
#include"Deck.h"
#include <string>

Player::Player()
{
	this->nome;
	this->fiche = 100;
	this->ValoreManoAttuale = 0;
}

Player::Player(std::string nome)
{
	this->nome = nome;
	this->fiche = 100;
	this->ValoreManoAttuale = 0;
}

void Player::vincitaFiche(int valore)
{
	this->fiche = fiche + valore;
	
}
void Player::perditaFiche(int valore)
{
	if (this->fiche > valore)
	{
		this->fiche = this->fiche - valore;
	}
	
}
void Player::aggiungiCarta(Deck& mazzo)
{
	int valore = mazzo.pescaCarta().getRank();
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
