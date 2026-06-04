#include "Campo.h"

Campo::Campo(
    int larghezzaPx,
    int altezzaPx,
    wstring titolo,
    string fontPath,
    int dimFont,
    sf::Color sfondo
) {
    this->larghezzaPx = larghezzaPx;
    this->altezzaPx = altezzaPx;
    this->dimFont = dimFont;
    this->coloreSfondo = sfondo;

    finestra.create(
        sf::VideoMode(larghezzaPx, altezzaPx),
        sf::String(titolo)
    );

    caricaFont(fontPath);
}

Campo::~Campo() {
    finestra.close();
}

float Campo::colonnaToX(int colonna) {
    return (float)(colonna * LARGHEZZA_CELLA);
}

float Campo::rigaToY(int riga) {
    return (float)(riga * ALTEZZA_CELLA);
}

void Campo::pulisci() {
    finestra.clear(coloreSfondo);
}

void Campo::cancellaRiga(Posizione posizione) {
    cancellaArea(
        posizione,
        getLarghezza(),
        1
    );
}

void  Campo::cancellaArea(Posizione posizione,
    int larghezza,
    int altezza) {

    float x;
    float y;
    float larghezzaPx;
    float altezzaPx;

    sf::RectangleShape rettangolo;

    x = colonnaToX(posizione.getColonna());
    y = rigaToY(posizione.getRiga());

    larghezzaPx = (float)(larghezza * LARGHEZZA_CELLA);
    altezzaPx = (float)(altezza * ALTEZZA_CELLA);

    rettangolo.setPosition(x, y);
    rettangolo.setSize(sf::Vector2f(larghezzaPx, altezzaPx));
    rettangolo.setFillColor(coloreSfondo);

    finestra.draw(rettangolo);
}

void Campo::disegna() {
    finestra.display();
}

void Campo::aggiungiTesto(Posizione posizione, wstring testo) {
    sf::Text oggettoTesto;

    oggettoTesto.setFont(font);
    oggettoTesto.setCharacterSize(dimFont);
    oggettoTesto.setFillColor(FG_BIANCO);
    oggettoTesto.setString(sf::String(testo));

    oggettoTesto.setPosition(
        colonnaToX(posizione.getColonna()),
        rigaToY(posizione.getRiga())
    );

    finestra.draw(oggettoTesto);
}

void Campo::aggiungiTestoAlCentro(int riga, wstring testo) {
    sf::Text oggettoTesto;

    oggettoTesto.setFont(font);
    oggettoTesto.setCharacterSize(dimFont);
    oggettoTesto.setFillColor(FG_BIANCO);
    oggettoTesto.setString(sf::String(testo));

    sf::FloatRect bounds = oggettoTesto.getLocalBounds();

    float x;
    x = ((float)larghezzaPx - bounds.width) / 2.0f;

    oggettoTesto.setPosition(x, rigaToY(riga));

    finestra.draw(oggettoTesto);
}

void Campo::aggiungiNumero(Posizione posizione, int numero) {
    aggiungiTesto(posizione, to_wstring(numero));
}

void Campo::aggiungiSimbolo(Posizione posizione, wchar_t simbolo) {
    wstring testo;

    testo = L"";
    testo = testo + simbolo;

    aggiungiTesto(posizione, testo);
}

void Campo::aggiungiLinea(Posizione posizioneInizio,
    Posizione posizioneFine,
    sf::Color colore,
    float spessore
) {
    float dx = colonnaToX(posizioneFine.getColonna()) - colonnaToX(posizioneInizio.getColonna());
    float dy = rigaToY(posizioneFine.getRiga()) - rigaToY(posizioneInizio.getRiga());
    float lungh = std::sqrt(dx * dx + dy * dy);
    float angolo = std::atan2(dy, dx) * 180.0f / static_cast<float>(PIGRECO);

    sf::RectangleShape linea(sf::Vector2f(lungh, spessore));
    linea.setFillColor(colore);
    linea.setOrigin(0.0f, spessore / 2.0f);
    linea.setPosition(colonnaToX(posizioneInizio.getColonna()), rigaToY(posizioneInizio.getRiga()));
    linea.setRotation(angolo);

    this->finestra.draw(linea);
}

void Campo::aggiungiCerchio(Posizione centro,
    float raggio,
    sf::Color colore) 
{
	sf::CircleShape cerchio(raggio);
    cerchio.setPosition(colonnaToX(centro.getColonna()), rigaToY(centro.getRiga()));
    cerchio.setFillColor(colore);
    this->finestra.draw(cerchio);
}

// Cerchio vuoto (solo bordo) con centro (cx,cy).
void Campo::aggiungiCerchioVuoto(Posizione centro,
    float raggio,
    sf::Color colore,
    float spessore)
{
	sf::CircleShape cerchio(raggio);
    cerchio.setPosition(colonnaToX(centro.getColonna()), rigaToY(centro.getRiga()));
    cerchio.setFillColor(sf::Color::Transparent);
    cerchio.setOutlineColor(colore);
    cerchio.setOutlineThickness(spessore);
	this->finestra.draw(cerchio);
}

// Rettangolo pieno. (x,y) è l'angolo in alto a sinistra.
void Campo::aggiungiRettangolo(Posizione angoloAltoSinistra,
    int larghezza, int altezza,
    sf::Color colore) 
{
    float larchezzaPx = (float)(larghezza * LARGHEZZA_CELLA);
    float altezzaPx = (float)(altezza * ALTEZZA_CELLA);
	sf::RectangleShape rettangolo(sf::Vector2f(larghezzaPx, altezzaPx));
    rettangolo.setFillColor(colore);
    rettangolo.setPosition(colonnaToX(angoloAltoSinistra.getColonna()), rigaToY(angoloAltoSinistra.getRiga()));
	this->finestra.draw(rettangolo);
}

// Rettangolo vuoto (solo bordo).
void Campo::aggiungiRettangoloVuoto(Posizione angoloAltoSinistra,
    int larghezza, int altezza,
    sf::Color colore,
    float spessore)
{
	float larghezzaPx = (float)(larghezza * LARGHEZZA_CELLA);
	float altezzaPx = (float)(altezza * ALTEZZA_CELLA);
    sf::RectangleShape rettangolo(sf::Vector2f(larghezzaPx, altezzaPx));
    rettangolo.setFillColor(sf::Color::Transparent);
    rettangolo.setOutlineColor(colore);
    rettangolo.setOutlineThickness(spessore);
    rettangolo.setPosition(colonnaToX(angoloAltoSinistra.getColonna()), rigaToY(angoloAltoSinistra.getRiga()));
	this->finestra.draw(rettangolo);
}

void Campo::aggiungiImmagine(Posizione posizione, string nomeImmagine, float scalaX, float scalaY) {
    wstring testo;

    sf::Texture tex;
    tex.loadFromFile(nomeImmagine);
    tex.setSmooth(true);

    sf::Sprite sprite(tex);
    sprite.setScale(scalaX, scalaY);
    sprite.setPosition(colonnaToX(posizione.getColonna()), rigaToY(posizione.getRiga()));
    this->finestra.draw(sprite);
}

void Campo::aggiungiImmagine(float pixX, float pixY, string nomeImmagine, float scalaX, float scalaY)
{
    wstring testo;

    sf::Texture tex;
    tex.loadFromFile(nomeImmagine);
    tex.setSmooth(true);

    sf::Sprite sprite(tex);
    sprite.setScale(scalaX, scalaY);
    sprite.setPosition(pixX, pixY);
    this->finestra.draw(sprite);
}

int Campo::getLarghezza() {
    return larghezzaPx / LARGHEZZA_CELLA;
}

int Campo::getAltezza() {
    return altezzaPx / ALTEZZA_CELLA;
}

bool Campo::isAperta() {
    return finestra.isOpen();
}

bool Campo::pollEvent(sf::Event& ev) {
    return finestra.pollEvent(ev);
}

bool Campo::waitEvent(sf::Event& ev) {
    return finestra.waitEvent(ev);
}

// ============================================================
//  Helper interno — caricamento font con fallback di sistema
// ============================================================

void Campo::caricaFont(std::string fontPath)
{
    if (this->font.loadFromFile(fontPath))
        return;

    // Fallback su font monospace di sistema (Windows / Linux / macOS)
    bool caricato =
        this->font.loadFromFile("C:/Windows/Fonts/consola.ttf") ||
        this->font.loadFromFile("C:/Windows/Fonts/cour.ttf") ||
        this->font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf") ||
        this->font.loadFromFile("/System/Library/Fonts/Courier New.ttf");

    if (!caricato)
        exit(1);   // nessun font disponibile: impossibile proseguire
}
