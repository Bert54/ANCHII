#ifndef PAQUET_HPP
#define PAQUET_HPP

#include <iostream>

class Paquet {
public:

    explicit Paquet(std::string nom);
    std::string getNomPaquet();

private:

    /**
     * @brief nom Le nom de ce paquet
     */
    std::string nom;

};

#endif // PAQUET_H
