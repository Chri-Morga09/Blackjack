#pragma once
#include"Deck.h"
#include <string>
class Player {

private:
	
	std::string nome;
	int fiche;
	int ValoreManoAttuale;
	int puntata;
public:
	Player();
	Player(std::string nome);  //costruttore che aggiunge nome

	void vincitaFiche();   //somma un valore alle fiche
	void perditaFiche(); //sottrae un valore alle fiche
	void Puntata(int valore); //il giocatore decide quanto puntare
    void aggiungiCarta(Deck& mazzo);  //aggiorna il valore delle carte nella mano
   void svuotaMano();  //svuota la mano alla fine del turno

   int getFiche();  //prende valore fiche
   int getValoreManoAttuale(); //prende valore carte
   int getPuntata();
   std::string getNome();  //prende il nome

	std::string ToString();  //per stampare i valori

};