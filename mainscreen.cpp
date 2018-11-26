/** Cette classe est la classe gérant l'écran des decks. L'application se content d'y ajouter des composants graphique, QT s'occupe du reste.
 **/

#include "mainscreen.hpp"
#include "ui_mainscreen.h"

/**
 * @brief MainScreen::MainScreen Constructeur de l'écran des paquets
 * @param parent
 */
MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
}

MainScreen::~MainScreen()
{
    delete ui;
}
