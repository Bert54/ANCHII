/** Anchii est une application permettant une auto révision et auto évaluation de l'utilisateur.
 ** Cette auto révision est stockée par des paquets, eux-même contenant des cartes, chaque
 ** carte contenant une question et une réponse.
 **
 ** @version 1
 **
 ** @author Matthias BERTRAND
 ** @author Matthieu OLEJNICZAK
 ** @author (Alexandre MAURY)
 **/



#include "anchii.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Anchii anchii;
    anchii.show();

    return app.exec();
}
