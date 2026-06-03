#include "InterfacciaUtente.h"

// ============================================================
//  Costruttore
// ============================================================
InterfacciaUtente::InterfacciaUtente(Campo& campo, Tastiera& tastiera)
    : campo(campo), tastiera(tastiera)
{
}

// ============================================================
//  Ciclo di visualizzazione
// ============================================================

void InterfacciaUtente::pulisci() {
    campo.pulisci();
}

void InterfacciaUtente::disegna() {
    campo.disegna();
}

// ============================================================
//  Output generico
// ============================================================

void InterfacciaUtente::aggiungiTesto(Posizione posizione, wstring testo) {
    campo.aggiungiTesto(posizione, testo);
}

void InterfacciaUtente::aggiungiTestoAlCentro(int riga, wstring testo) {
    campo.aggiungiTestoAlCentro(riga, testo);
}

void InterfacciaUtente::aggiungiNumero(Posizione posizione, int numero) {
    campo.aggiungiTesto(posizione, to_wstring(numero));
}

void InterfacciaUtente::aggiungiNumero(Posizione posizione, double numero) {
    campo.aggiungiTesto(posizione, to_wstring(numero));
}

void InterfacciaUtente::aggiungiSimbolo(Posizione posizione, wchar_t simbolo) {
    wstring testo;

    testo = L"";
    testo = testo + simbolo;

    campo.aggiungiTesto(posizione, testo);
}

void InterfacciaUtente::aggiungiLineaOrizzontaleWChar(
    Posizione inizio,
    int colonnaFine,
    wchar_t carattere
) {
    campo.aggiungiLineaOrizzontaleWChar(inizio, colonnaFine, carattere);
}

void InterfacciaUtente::aggiungiRettangoloVuotoWChar(
    Posizione posizione,
    int larghezza,
    int altezza
) {
    campo.aggiungiRettangoloVuotoWChar(posizione, larghezza, altezza);
}

void InterfacciaUtente::aggiungiRettangoloPienoWChar(
    Posizione posizione,
    int larghezza,
    int altezza,
    wchar_t carattere
) {
    campo.aggiungiRettangoloPienoWChar(posizione, larghezza, altezza, carattere);
}

void InterfacciaUtente::aggiungiLinea(Posizione posizioneInizio, Posizione posizioneFine, sf::Color colore, float spessore)
{
    campo.aggiungiLinea(posizioneInizio, posizioneFine, colore, spessore);
}

void InterfacciaUtente::aggiungiCerchio(Posizione centro, float raggio, sf::Color colore)
{
    campo.aggiungiCerchio(centro, raggio, colore);

}

void InterfacciaUtente::aggiungiCerchioVuoto(Posizione centro, float raggio, sf::Color colore, float spessore)
{
    campo.aggiungiCerchioVuoto(centro, raggio, colore, spessore);

}

void InterfacciaUtente::aggiungiRettangolo(Posizione angoloAltoSinistra, int larghezza, int altezza, sf::Color colore)
{
    campo.aggiungiRettangolo(angoloAltoSinistra, larghezza, altezza, colore);

}
void InterfacciaUtente::aggiungiRettangoloVuoto(Posizione angoloAltoSinistra, int larghezza, int altezza, sf::Color colore, float spessore)
{
    campo.aggiungiRettangoloVuoto(angoloAltoSinistra, larghezza, altezza, colore, spessore);
}

void InterfacciaUtente::aggiungiImmagine(Posizione posizione, string nomeImmagine, float scalaX, float scalaY) {
    campo.aggiungiImmagine(posizione, nomeImmagine, scalaX, scalaY);
}

void InterfacciaUtente::aggiungiImmagine(float pixX, float pixY, string nomeImmagine, float scalaX, float scalaY) {
    campo.aggiungiImmagine(pixX, pixY, nomeImmagine, scalaX, scalaY);
}

void InterfacciaUtente::sleep(int millisecondi)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(millisecondi));
}

// ============================================================
//  Input testuale
// ============================================================

wstring InterfacciaUtente::leggiStringa(
    Posizione posizioneRisposta,
    Posizione posizioneDomanda,
    wstring domanda
) {
    return tastiera.leggiStringa(
        campo,
        posizioneRisposta,
        posizioneDomanda,
        domanda
    );
}

int InterfacciaUtente::leggiIntero(
    Posizione posizioneRisposta,
    Posizione posizioneDomanda,
    wstring domanda,
    int valDefault,
    int minVal,
    int maxVal
) {
    return tastiera.leggiIntero(
        campo,
        posizioneDomanda,
        posizioneRisposta,
        domanda,
        valDefault,
        minVal,
        maxVal
    );
}

// ============================================================
//  Input da tastiera
// ============================================================

int InterfacciaUtente::leggiTasto() {
    return tastiera.leggi();
}

int InterfacciaUtente::leggiTastoBloccante() {
    return tastiera.leggiBloccante();
}

bool InterfacciaUtente::tastoPremuto() {
    return tastiera.tastoPremuto();
}

void InterfacciaUtente::svuotaBuffer() {
    tastiera.svuotaBuffer();
}

bool InterfacciaUtente::isEsc(int codice) {
    return codice == TASTO_ESC;
}

bool InterfacciaUtente::isInvio(int codice) {
    return codice == TASTO_INVIO;
}

bool InterfacciaUtente::isFreccia(int codice) {
    return tastiera.isFreccia(codice);
}

bool InterfacciaUtente::isFrecciaSu(int codice) {
    return codice == TASTO_SU;
}

bool InterfacciaUtente::isFrecciaGiu(int codice) {
    return codice == TASTO_GIU;
}

bool InterfacciaUtente::isFrecciaSinistra(int codice) {
    return codice == TASTO_SINISTRA;
}

bool InterfacciaUtente::isFrecciaDestra(int codice) {
    return codice == TASTO_DESTRA;
}

bool InterfacciaUtente::isTastoFunzione(int codice) {
    if (codice == TASTO_F1) return true;
    if (codice == TASTO_F2) return true;
    if (codice == TASTO_F3) return true;
    if (codice == TASTO_F4) return true;
    if (codice == TASTO_F5) return true;
    if (codice == TASTO_F6) return true;
    if (codice == TASTO_F7) return true;
    if (codice == TASTO_F8) return true;
    if (codice == TASTO_F9) return true;
    if (codice == TASTO_F10) return true;

    return false;
}

// ============================================================
//  Informazioni sul campo
// ============================================================

int InterfacciaUtente::getLarghezza() {
    return campo.getLarghezza();
}

int InterfacciaUtente::getAltezza() {
    return campo.getAltezza();
}