#include "Player.h"
#include"Card.h"
#include <string>

Player::Player()
{
	this->nome;
	this->fiche = 100;
	this->ValoreCarteAttuale = 0;
}

Player::Player(std::string nome)
{
	this->nome = nome;
	this->fiche = 100;
	this->ValoreCarteAttuale = 0;
}

int Player::vincitaFiche(int valore)
{
	this->fiche = fiche + valore;
	return this->fiche;
}
int Player::perditaFiche(int valore)
{
	if (this->fiche > valore)
	{
		this->fiche = this->fiche - valore;
	}
	return this->fiche;
}
int Player::aggiornaManoAttuale(int valore)
{
	this->ValoreCarteAttuale = ValoreCarteAttuale + valore;
	return this->ValoreCarteAttuale;
}

int Player::getFiche()
{
	return this->fiche;
}
int Player::getValoreCarteAttuale()
{
	return this->ValoreCarteAttuale;
}
std::string Player::getNome()
{
	return this->nome;
}
std::string Player::ToString()
{
	std::string s;
	s = "nome: " +this->nome +" fiche: " + std::to_string(this->fiche) + " valore carte attuale " + std::to_string(this->ValoreCarteAttuale);
	return s;

}