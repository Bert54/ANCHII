#ifndef CARDSCREEN_HPP
#define CARDSCREEN_HPP

#include <QMainWindow>

namespace Ui {
class CardScreen;
}

class CardScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit CardScreen(QWidget *parent = 0);
    ~CardScreen();

    Ui::CardScreen *ui;
};

#endif // CARDSCREEN_HPP
