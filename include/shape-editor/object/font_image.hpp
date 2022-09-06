#ifndef FONT_IMAGE_HPP
#define FONT_IMAGE_HPP

#include <iostream>
#include <string>
#include "../../Shapes/Rectangle/Rectangle.hpp"
#include <vector>
#include <fstream>

/// Structure nécessaire au fonctionnement de FontImage, il s’agit d'un simple point qui n'est définit que par des coordonnées x et y.
struct vertex {
    unsigned int x, y;
};

class FontImage
        : public Rectangle {
private:

    /// Texte qui sera écrit avec la font.
    std::string textToPrint;

    /// Chemin qui contient la texture qui sera utilisé pour écrire à l'écran
    std::string texturePath;

    /// Largeur et Hauteut de **1 Character** de la texture utilisé.
    int charWidth;
    int charHeight;

    /// Liste ordonné des lettres comprises dans la texture
    std::vector<char> letterList;

    /// Liste dynamique de pair :
    ///\param char : Le caractère.
    ///\param vertex : Les coordonnés du poing gauche supérieur à partir du qu'elle commence le caractère.
    ///\note Exemple : pour le charactère 't', sa texture peut commencer sur l'image en x=64 et y=32
    std::vector<std::pair<char, vertex>> letterArray;

    /// Image qui servira à la font
    EZImage* texture;

    /// Fonction privée qui cherche parmi la liste de pairs, le pair qui contient le caractère en argument.
    ///\param Character : Character qui est cherché dans la liste de pair.
    ///\return L'index de la pair our se trouve le charatcer donné en argument.
    size_t findInTab( char c );

    /// Zoom appliqué sur la police
    unsigned int Zoom = 1;

public:

    /// Constructeur de base d'une *"chaine de texture"*
    FontImage(
            std::string _textToPrint, std::string _texturePath, int x, int y, unsigned int charW, unsigned int charH,
            char letterTab[], size_t letterNumber );

    /// Constructeur par lecture d'un fichier de configuration ordonné.
    ///\param textToPrint Le text qui serat imprimé à l'ecrant
    ///\param FontConfigFile Le fichier de configuration ordonné ou seront disposé touttes les information néccessaire à la contruction de l'objet(chemin de texture,largeur et hauteur d'un chrater,lettre disponible)
    FontImage( std::string _textToPrint, std::string FontConfigFile, int x, int y );

    /// Constructeur par lecture de fichier, utilisé pour charger une sauvegarde d'une FontImage
    FontImage( std::istream& is );

    FontImage() = delete;

    /// Constructeur par copie basique
    FontImage( const FontImage& );

    ///Destructeur Basique
    ~FontImage();

    /// Ecrit du texte avec la font créé lors de la construction.
    ///\param [in] window : La fenêtre où serat imprimez la FontImage.
    virtual void draw( EZWindow& window ) const;

    /// Sauvegarde la font écrit à l'écran.
    ///\param os : Ecrit sur un flux de sortie une sauvegarde de la FontImage.
    void write( std::ostream& os ) const;

    /// Permets de changer le zoom sur la fontImage.
    ///\param newZoom : Nouvelle valeur du Zoom
    inline void setZoom( unsigned int newZoom ) { Zoom = newZoom; }

    ///Permets d'avoire la valeur du Zoom sur la FontImage.
    inline unsigned int getZoom() const { return Zoom; }
};

#endif //FONT_IMAGE_HPP
