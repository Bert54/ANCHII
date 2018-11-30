/** Cette classe est la classe gérant l'écran de gestion de deck. L'application se content d'y ajouter des composants graphique, QT s'occupe du reste.
 **/

#include "deckscreen.hpp"
#include "ui_deckscreen.h"

/**
 * @brief DeckScreen::DeckScreen Constructeur de l'écran de gestion de deck
 * @param parent
 */
DeckScreen::DeckScreen(QWidget *parent) : QMainWindow(parent), ui(new Ui::DeckScreen) {
    ui->setupUi(this);
}

/**
 * @brief DeckScreen::~DeckScreen Destructeur de l'écran de gestion de deck
 */
DeckScreen::~DeckScreen()
{
    delete ui;
}
