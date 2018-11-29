#ifndef ECRANAJOUTCARTE_HPP
#define ECRANAJOUTCARTE_HPP

#include <QMainWindow>

namespace Ui {
class EcranAjoutCarte;
}

class EcranAjoutCarte : public QMainWindow
{
    Q_OBJECT

public:
    explicit EcranAjoutCarte(QWidget *parent = 0);
    ~EcranAjoutCarte();

private:
    Ui::EcranAjoutCarte *ui;
};

#endif // ECRANAJOUTCARTE_HPP
