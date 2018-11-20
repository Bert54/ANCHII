#include "deckscreen.hpp"
#include "ui_deckscreen.h"

DeckScreen::DeckScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeckScreen)
{
    ui->setupUi(this);
}

DeckScreen::~DeckScreen()
{
    delete ui;
}
