#include "anchii.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Anchii anchii;
    anchii.show();

    return app.exec();
}
