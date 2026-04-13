#pragma once
#include"Card.h"
#include <string>
class Player {

private:
	Card mano;
	std::string nome;
	int fiche;
	int ValoreCarteAttuale;
public:
	Player();
	Player(std::string nome);  //costruttore che aggiunge nome

	int vincitaFiche(int valore);   //somma un valore alle fiche
	int perditaFiche(int valore);   //sottrae un valore alle fiche
   int aggiornaManoAttuale(int valore);  //aggiorna il valore delle carte nella mano

   int getFiche();  //prende valore fiche
   int getValoreCarteAttuale(); //prende valore carte
   std::string getNome();  //prende il nome

	std::string ToString();  //per stampare i valori

};