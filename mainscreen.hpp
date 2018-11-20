#ifndef MAINSCREEN_HPP
#define MAINSCREEN_HPP

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainScreen;
}

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = 0);
    ~MainScreen();

    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_HPP
