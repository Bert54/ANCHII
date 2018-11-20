#ifndef DECKSCREEN_HPP
#define DECKSCREEN_HPP

#include <QMainWindow>

namespace Ui {
class DeckScreen;
}

class DeckScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeckScreen(QWidget *parent = 0);
    ~DeckScreen();

    Ui::DeckScreen *ui;
};

#endif // DECKSCREEN_HPP
