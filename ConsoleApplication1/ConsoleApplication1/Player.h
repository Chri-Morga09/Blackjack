#pragma once
#include <string>
class Player {

private:
	std::string nome;
	int fiche;
	int ValoreCarteAttuale;
public:
	Player();
	Player(std::string nome);
	int aggiornaFiche(int valore);
   int aggiornaValoreCarteAttuale(int valore);
	std::string ToString();

};