#include "cardscreen.hpp"
#include "ui_cardscreen.h"

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
