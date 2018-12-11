/** Cette classe représente une carte d'un paquet
 **/

#include "carte.hpp"

#include <QDir>
#include <QDebug>

/**
 * @brief Carte::Carte Constructeur d'une carte
 * @param question La question d'une carte
 * @param reponse La réponse d'une carte
 */
Carte::Carte(std::string question, std::string reponse, std::string* mediaQuestion, std::string* mediaReponse) {
    this->question = question;
    this->reponse = reponse;
    // Si on a un média pour la question : on convertit le chemin en chemin local et on crée le média
    if (mediaQuestion != NULL) {
        this->mediaQuestion = new MediaImage(convertFileToLocal(*mediaQuestion));
    }
    else {
        this->mediaQuestion = NULL;
    }
    // Si on a un média pour la réponse : on convertit le chemin en chemin local et on crée le média
    if (mediaReponse != NULL) {
        this->mediaReponse = new MediaImage(convertFileToLocal(*mediaReponse));
    }
    else {
        this->mediaReponse = NULL;
    }
}

/**
 * @brief Carte::~Carte Destructeur de la carte. On détruit les deux médias
 */
Carte::~Carte() {
    delete mediaQuestion;
    delete mediaReponse;
}

/**
 * @brief Carte::convertFileToLocal Permet de récupérer un fichier, de le copier dans un répertoire local (si celui-ci n'existe pas, on le crée) et de mettre à jour le chemin du média afin que celui-ci pointe sur le fichier copié
 * @param path Le chemin du fichier à copier
 * @return Le chemin vers le fichier local
 */
std::string Carte::convertFileToLocal(std::string path) {
    QFileInfo file(QString::fromStdString(path));
    // On vérifie si le répertoire qui va contenir les images existe, si il n'existe pas, alors on le crée
    if (!QDir(QDir::currentPath() + "/Pictures").exists()) {
        QDir().mkdir("Pictures");
    }
    // On copie le fichier
    QFile::copy(file.path() + "/" + file.fileName(), QDir::currentPath() + "/Pictures/" + file.fileName());

    // On construit le nouveau chemin et on le retourne
    std::string pathr = QDir::currentPath().toUtf8().constData();
    pathr = pathr + + "/Pictures/";
    return pathr + file.fileName().toUtf8().constData();
}

/**
 * @brief Carte::getQuestion Retourne la question de cette carte
 * @return La question de cette carte
 */
std::string Carte::getQuestion() {
    return this->question;
}

/**
 * @brief Carte::getQuestion Retourne la reponse de cette carte
 * @return La reponse de cette carte
 */
std::string Carte::getReponse() {
    return this->reponse;
}

/**
 * @brief Carte::getMediaQuestion Retourne le média de la question de cette carte
 * @return Le média de la question de cette carte
 */
MediaImage* Carte::getMediaQuestion() {
    return this->mediaQuestion;
}

/**
 * @brief Carte::getMediaReponse Retourne le média de la réponse de cette carte
 * @return Le média de la réponse de cette carte
 */
MediaImage* Carte::getMediaReponse() {
    return this->mediaReponse;
}

/**
 * @brief Carte::ajouterASupprimer Change le statut de la carte par rapport a sa suppression
 */
void Carte::ajouterASupprimer() {
    if(this->aSupprimer) {     // On change le statut de suppression de la carte
        this->aSupprimer = false;
    }
    else {
        this->aSupprimer = true;
    }
}

/**
 * @brief Carte::getSuppression Retourne le statut de la suppression de la carte
 * @return true si la carte va etre supprimer, false sinon
 */
bool Carte::getSuppression() {
    return this->aSupprimer;
}


