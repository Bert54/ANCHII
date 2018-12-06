/** Cette classe est la classe gérant l'écran d'ajout d'une carte. L'application se content d'y ajouter des composants graphique, QT s'occupe du reste.
 **/

#include "cardscreen.hpp"
#include "ui_cardscreen.h"

/**
 * @brief CardScreen::CardScreen Constructeur de l'écran d'e gestion de deck'ajout d'une carte
 * @param parent
 */
CardScreen::CardScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CardScreen)
{
    ui->setupUi(this);
}

CardScreen::~CardScreen()
{
    delete ui;
}
