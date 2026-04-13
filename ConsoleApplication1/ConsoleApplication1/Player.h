#pragma once
#include"Deck.h"
#include <string>
class Player {

private:
	Deck mazzo;
	std::string nome;
	int fiche;
	int ValoreManoAttuale;
public:
	Player();
	Player(std::string nome);  //costruttore che aggiunge nome

	void vincitaFiche(int valore);   //somma un valore alle fiche
	void perditaFiche(int valore);   //sottrae un valore alle fiche
  void aggiungiCarta(Deck mazzo);  //aggiorna il valore delle carte nella mano
   void svuotaMano();  //svuota la mano alla fine del turno

   int getFiche();  //prende valore fiche
   int getValoreManoAttuale(); //prende valore carte
   std::string getNome();  //prende il nome

	std::string ToString();  //per stampare i valori

};