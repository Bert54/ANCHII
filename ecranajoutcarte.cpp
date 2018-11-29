#include "ecranajoutcarte.hpp"
#include "ui_ecranajoutcarte.h"

EcranAjoutCarte::EcranAjoutCarte(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EcranAjoutCarte)
{
    ui->setupUi(this);
}

EcranAjoutCarte::~EcranAjoutCarte()
{
    delete ui;
}
