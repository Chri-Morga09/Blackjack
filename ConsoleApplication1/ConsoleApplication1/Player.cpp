#include "Player.h"
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

int Player::aggiornaFiche(int punteggio)
{
	this->fiche = fiche + punteggio;
	return this->fiche;
}

int Player::aggiornaValoreCarteAttuale(int punteggio)
{
	this->ValoreCarteAttuale = ValoreCarteAttuale + punteggio;
	return this->fiche;
}

std::string Player::ToString()
{
	std::string s;
	s = "nome: " +this->nome +" fiche: " + std::to_string(this->fiche) + " valore carte attuale " + std::to_string(this->ValoreCarteAttuale);
	return s;

}