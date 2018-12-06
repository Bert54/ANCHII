#ifndef MEDIAIMAGE_HPP
#define MEDIAIMAGE_HPP

#include <iostream>

class MediaImage {
public:
    MediaImage() {}
    MediaImage(std::string cheminRelatif);
    virtual ~MediaImage() {}
    std::string getMedia();

private:
    // Le chemin du média
    std::string chemin;
};

#endif // MEDIAIMAGE_HPP
