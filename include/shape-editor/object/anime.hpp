#ifndef ANIME_HPP
#define ANIME_HPP

#include "Image.hpp"

class AnimeImage
        : public Image {
private:

    /// Frame actuelle de l'image
    ///\note C'est cette frame qui sera affiché à l'écran.
    unsigned int actualFrame;

    /// Nombre de frame(s) que possède l'image.
    size_t maxFrame;

    /// Largeur horizontale d'une Frame.
    unsigned int frameWidth;

public:

    /// Constructeur de base pour une Image Animé.
    ///\param x : Position x à l'écran de l'image animé.
    ///\param y : Position y à l'écran de l'image animé.
    ///\param texturePath : Chemin de la texture utilisé pour l'image.
    ///\param _maxFrame : Le nombre de Frame total que possède l'image.
    AnimeImage( int x, int y, std::string _texturePath, unsigned int _maxFrame );

    AnimeImage( std::istream& is );

    AnimeImage() = delete;

    ~AnimeImage();

    /// Dessine une image à l'écrant.
    ///\param Win : Fenetre ou s'affiche l'image.
    virtual void draw( EZWindow& Win ) const;

    /// Passe à la frame suivante de l'image.
    inline void nextFrame() { actualFrame++; }

    /// Permet d'ecrire une sauvegarde sur un flux de sortie
    ///\param os : flux de sortie
    virtual void write( std::ostream& os ) const;
};

#endif //ANIME_HPP
