#include "anchii.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ui::Anchii w;
    w.show();

    return a.exec();
}
