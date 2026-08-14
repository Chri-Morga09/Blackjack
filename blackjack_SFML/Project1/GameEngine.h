#pragma once

#include "InterfacciaUtente.h"
#include <string>
#include"Card.h"
#include"Deck.h"
#include"Banco.h"
#include"Mano.h"
#include"Player.h"
using namespace std;

// ============================================================
//  GameEngine
//
//  Classe che gestisce il test del blackjack.
//  Per ora non usa ancora le classi Carta, Mazzo, Mano.
//  Simula solo il ciclo "dammi carta?".
// ============================================================

class GameEngine {
public:
    GameEngine(InterfacciaUtente& ui, wstring nomeGiocatore);

    void run();
	int getCarteGiocatore();

    void distribuisciCarteIniziali();
    void turnoGiocatore();
    void turnoBanco();
    int determinaVincitore();
    bool continuaPartita();
    void resetPartita();
    Player& getGiocatore(); //riceve oggetto originale senza crearne una copia
    Banco& getBanco(); //riceve oggetto originale senza crearne una copia
private:
    InterfacciaUtente& ui;
    wstring nomeGiocatore;
    int carteGiocatore;

    
    Card card;
    Deck mazzo;
    Banco banco;
    Mano mano;
    Player giocatore;
    bool partitaInCorso;

    void aggiungiSfondo();
    void disegnaCampoEDomanda(wstring domanda);
	void spostaCartaGiocatore(Posizione inizio, Posizione fine);
};
