#include "Game.h"
#include <iostream>
#include <cstdlib>  
using namespace std;
Game::Game() {
	// Costruttore
	puntataCorrente = 0;
	partitaInCorso = false;
}
void Game::distribuisciCarte() {
	//  distribuisce le carte iniziali
  //  giocatore.aggiungiCarta(mazzo.drawCard());
   // giocatore.aggiungiCarta(mazzo.drawCard());
   // banco.aggiungiCarta(mazzo.drawCard());
   // banco.aggiungiCarta(mazzo.drawCard());
	aggiornaPunteggi();
}
void Game::aggiornaPunteggi() {
	//  aggiorna i punteggi dei giocatori
	//giocatore.calcolaPunteggio();
   // banco.calcolaPunteggio();
}
void Game::iniziaGioco() {
	// Inizia la partita
	mazzo.shuffle();
	puntataCorrente = 0;
	partitaInCorso = true;
	distribuisciCarte();
	mostraStato();
}
void Game::turnoGiocatore() {
	// Turno del giocatore
	char scelta;

	do {
		cout << "Hit (h) o Stand (s)? ";
		cin >> scelta;

		if (scelta == 'h') {
			// giocatore.aggiungiCarta(mazzo.drawCard());
			aggiornaPunteggi();
			mostraStato();

			//if (giocatore.getPunteggio() > 21) {
		   //     cout << "Hai sballato!" << endl;
		   //     break;
		   // }
		}

	} while (scelta != 's');
}
void Game::turnoBanco() {
	// Turno del banco
   // while (banco.getPunteggio() < 17) {
   //     banco.aggiungiCarta(mazzo.drawCard());
  //      aggiornaPunteggi();
   // }

	cout << "Turno del banco terminato." << endl;
}
void Game::determinaVincitore() {
	// Determina il vincitore
   // int punteggioG = giocatore.getPunteggio();
   //int punteggioB = banco.getPunteggio();
	int punteggioG = 6;
	int punteggioB = 7;
	cout << "Punteggio giocatore: " << punteggioG << endl;
	cout << "Punteggio banco: " << punteggioB << endl;

	if (punteggioG > 21)
		cout << "Hai perso!" << endl;
	else if (punteggioB > 21 || punteggioG > punteggioB)
		cout << "Hai vinto!" << endl;
	else if (punteggioG < punteggioB)
		cout << "Hai perso!" << endl;
	else
		cout << "Pareggio!" << endl;
}
void Game::mostraStato() {
	// Mostra lo stato attuale delle mani
	cout << "Carte giocatore: ";
	//  giocatore.mostraMano();

	cout << endl << "Carte banco: ";
	// banco.mostraMano();

	cout << endl;
}
bool Game::continuaPartita() {
	// Controlla se la partita può continuare
   // return giocatore.getFiches() > 0 && mazzo.cardsLeft() > 0;
	return false;
}
void Game::resetPartita() {
	// Resetta la partita
	mazzo.reset();
	//giocatore.svuotaMano();
	//banco.svuotaMano();

	puntataCorrente = 0;
	partitaInCorso = true;
}