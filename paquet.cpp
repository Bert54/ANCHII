/** Cette classe représente un paquet de l'application, qui contient des cartes.
 **/

#include "paquet.hpp"

#include "QDebug"

/**
 * @brief Paquet::Paquet Constructeur d'un paquet
 * @param nom Le nom du nouveau paquet
 */
Paquet::Paquet(std::string nom) {
    this->nom = nom;
}

Paquet::~Paquet() {
    for (Carte *c: this->cartes) {
        delete c;
    }
}

/**
 * @brief Paquet::getNomPaquet Retourne le nom de ce paquet
 * @return Le nom de ce paquet
 */
std::string Paquet::getNomPaquet() {
    return this->nom;
}

/**
 * @brief Paquet::ajouterCarte Ajoute une nouvelle carte dans le paquet actif
 * @param question La question de la carte
 * @param reponse La réponse de la carte
 */
void Paquet::ajouterCarte(std::string question, std::string reponse) {
    Carte *carte = new Carte(question, reponse);
    cartes.push_back(carte);
}

/**
 * @brief Paquet::ajouterCarteASupprimer Ajoute une carte dans la liste des cartes à supprimer
 * @param question La question de la carte à supprimer
 */
void Paquet::ajouterCarteASupprimer(std::string question) {
    int indice = getNumeroCarte(question);  // Numéro de la carte à supprimer
    Carte *carte = this->cartes.at(indice);     // Carte à supprimer
    if(carte->getSuppression()) {   // La carte est déjà dans la liste des cartes à supprimer, donc on l'enlève
        for(int i = 0 ; i < (int)this->cartesASupprimer.size() ; i++) {  // On cherche l'indice de l'indice de la carte à supprimer
            if(this->cartesASupprimer.at(i) == indice) {
                // Suppression de l'indice de la carte dans la liste
                this->cartesASupprimer.erase(this->cartesASupprimer.begin() + i);
            }
        }
    }
    else {
        // On ajoute la carte à la liste des cartes à supprimer
        this->cartesASupprimer.push_back(indice);
    }
    carte->ajouterASupprimer();  // On change le statut de la carte à supprimer
}

/**
 * @brief Paquet::supprimerCartes Supprime une carte en connaissant sa question
 * @param question La question de la carte
 */
void Paquet::supprimerCartes() {
    // On trie la liste des indices par ordre decroissant pour supprimer les cartes par le plus grand indice
    Carte *c;
    std::sort (this->cartesASupprimer.begin(), this->cartesASupprimer.end());
    // On supprime les cartes de la liste
    for(int indice : this->cartesASupprimer) {
        c = this->cartes[indice];
        this->cartes.erase(this->cartes.begin() + indice);
        delete c;
    }
    // On réinitialise la liste
    initCartesASupprimer();
}

/**
 * @brief Paquet::initCartesASupprimer Mise a vide de la liste de cartes a supprimer
 */
void Paquet::initCartesASupprimer() {
    this->cartesASupprimer.clear();
}

/**
 * @brief Paquet::getNumeroCarte Retourne le numero de la carte associee a la question
 * @param question Question d'une carte
 * @return Indice de la carte
 */
int Paquet::getNumeroCarte(std::string question) {
    int i = 0;
    int indice;
    for(Carte *c : this->cartes) {
        if(!question.compare(c->getQuestion())) { // On compare la question en paramètre avec celle de chaque carte
            indice = i; // On fixe la valeur de l'indice
        }
        i++;    // On incrémente la valeur de i
    }
    return indice;
}

/**
 * @brief Paquet::getCartes Récuèpre les cartes du paquet actif
 * @return La liste des cartes du paquet actif
 */
std::vector<Carte*> Paquet::getCartes() {
    return this->cartes;
}
