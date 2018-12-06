/** Cette classe est celle qui va contenir un chemin du média associé à la carte,
 ** permettant ensuite de le générer quand nécéssaire
 **/

#include "mediaimage.hpp"

MediaImage::MediaImage(std::string cheminRelatif) {
    this->chemin = cheminRelatif;
}


/**
 * @brief MediaImage::getMedia Retourne le chemin du média
 * @return
 */
std::string MediaImage::getMedia() {
    return this->chemin;
}
