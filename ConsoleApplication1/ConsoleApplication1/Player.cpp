#include "Player.h"
#include"Card.h"
#include"Deck.h"
#include <string>

Player::Player()
{
	// le fiche partono predefinite da zero
	this->nome;
	this->fiche = 100;
	this->puntata = 0;

}

Player::Player(std::string nome)
{
	this->nome = nome;
	this->fiche = 100;
	this->puntata = 0;
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
	this->manoGiocatore.aggiungiCarta(mazzo.pescaCarta());

}
void Player::svuotaMano()
{
	this->manoGiocatore.svuota();
}

int Player::getFiche()
{
	return this->fiche;
}
int Player::getValoreManoAttuale()
{
	return this->manoGiocatore.calcolaValore();
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
	s = "nome: " + this->nome + " fiche: " + std::to_string(this->fiche) + " Puntata= " + std::to_string(this->puntata);
	s += this->manoGiocatore.toString();
	return s;

}
