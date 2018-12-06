#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <iostream>

class Media {
public:
    Media(std::string cheminRelatif);
    virtual void* getMedia();
private:
    std::string chemin;
};

#endif // MEDIA_HPP
