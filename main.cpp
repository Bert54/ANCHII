#include "anchii.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Anchii w;
    w.show();

    return a.exec();
}
