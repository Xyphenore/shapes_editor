#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "../../Shapes/Rectangle/Rectangle.hpp"

#include <memory>

///Permet d'afficher une image.
class Image
        : public Rectangle {
private:

    /// Chemin ou se trouve L'image.
    std::string texturePath;

    /// L'image utilisé.
    EZImage* texture;

    /// Si l'utlisation de l'alpha (opacité) d'une image et utilisé
    bool activeAlpha = true;

    unsigned int findInTab();

    /// Zoom sur l'image.
    ///\warning ne peut que être supérieur à 0 !
    unsigned int Zoom = 1; /* La fonction de re-scale ne fonctionne que avec des entier ! */

    /// Permet d'effectuer des rotation sur l'image.
    int Rotation = 0;

    /// Contient le niveau d'opacité
    ///\warning Valeur en 0 et 255 maximum !
    int Opacity = 255;

    bool canalAlpha = true;

public:

    Image( int x, int y, std::string _texturePath );

    Image( std::istream& is );

    Image() = delete;

    Image( const Image& );

    ~Image();

    /// Dessine L'image à l'écrant.
    ///\param [in] Window : Fenetre ou est imprimer l'image.
    virtual void draw( EZWindow& window ) const;

    /// Change le Zoom sur l'image
    ///\param newFactor : Nouveau Zoom appliqué.

    /// Permet de Changez Rotation de l'image.
    ///\param newRotaion : Nouvelle rotation.
    ///\warning Abusée desroation peut crée une erreur 'out_of_memory'.
    inline void setRotation( int newRotation ) { Rotation = newRotation % 360; }

    inline unsigned int getRotation() const { return Rotation % 360; }

    /// Change le Zoom sur l'image
    ///\param newFactor : Nouveau Zoom appliqué
    inline void setZoom( unsigned int newFactor ) { Zoom = newFactor; }

    /// Recupère le Zoom de l'image
    inline unsigned int getZoom() const { return Zoom; }

    /// Recupère un pointeur sur la texture
    inline EZImage* getTexture() const { return texture; }

    inline void setTexture( EZImage* newTexture ) { texture = newTexture; }

    /// Recupère le chemin de la texture utilisé
    inline std::string getTexturePath() const { return texturePath; }

    /// Recupère la valeur de activeAlpha
    inline bool isAlphaActivate() const { return activeAlpha; }

    /// Permet de modifier le facteur d'opaciter
    ///\param newOpacity : nouvelle opacité
    ///\warning La valeur de l'opacité doit être définit entre 0 et 255 inclu
    inline void setOpacity( unsigned int newOpacity ) { Opacity = newOpacity; }

    /// Permet de récupérer l'opacité de l'image
    inline int getOpacity() const { return Opacity; }

    /// Change la valeur de canalAlpha
    ///\param newAlpah : nouvelle valeur pour canalAlpha
    inline void setCanalAlpha( bool newAlpha ) { canalAlpha = newAlpha; }

    /// Permet de récupérer le canal alpha d'une Image
    inline bool getCanalAlpha() const { return canalAlpha; }


    /// Ecrit une sauvgarde de l'image
    ///\param os : Ecrit sur un flux de sortie une sauvegarde de l'image
    virtual void write( std::ostream& os ) const;

};

#endif //IMAGE_HPP
