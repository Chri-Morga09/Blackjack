#pragma once

#include "InterfacciaUtente.h"
#include <string>

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

private:
    InterfacciaUtente& ui;
    wstring nomeGiocatore;
    int carteGiocatore;

    void aggiungiSfondo();
    void aggiungiCarteGiocatore();
    void mostraCampoGioco();
	void spostaCartaGiocatore(Posizione inizio, Posizione fine);
};
