#ifndef SHAPE_EDITOR_GRID_HPP
#define SHAPE_EDITOR_GRID_HPP

#include <vector>

#include "object.hpp"

namespace shape_editor {
    class Grid
            : public Object {
    public:
        /**
         * The maximum of alpha canal aka the opacity.
         *
         * @version 1.0
         * @since 1.0
         */
        static const int MAX_OPACITY = 255;

        Grid( int length, int height );

    private:
        int width_ = 0;
        int height_ = 0;

        int horizontal_lines_ = 0;
        int vertical_lines_ = 0;

        int alpha_ = MAX_OPACITY;

        bool activated_ = true;

        bool fullscreen_ = false;

        EZColor color_;

        int thickness_;

        Point anchor_;

        bool selected_ = false;

        bool filled_ = false;

        std::vector<Point*> points_;
    };

} // namespace shape_editor

class Grid
        : public Rectangle {

public:

    /// Construit une grille.
    ///\param x : Position x du coin supérieur gauche.
    ///\param y : position y du coin supérieur droit.
    ///\param _squareHeight : nombre(s) de ligne(s) Horizontale que possède la grille.
    ///\param _squareWidth : nombre(s) de ligne(s) Verticale que possède la grille
    Grid( int x, int y, unsigned int _squareHeight, unsigned int squareHeight );

    Grid();

    ///Constructeur de par copie
    Grid( const Grid& );

    /// Constructeur par flux d'entrée
    ///\param is : flux d'entrée
    ///\note Généraelemnt utilisé avec un fichier de sauvegarde
    Grid( std::istream& is );

    ~Grid();

    /// Permet de changer le nombe de ligne verticale et horizontale
    ///\param newHL : nouveau nombre de ligne horizontale
    ///\param newVL : nouveau nombre de ligne verticale
    inline void setLineNumber( unsigned int newHL, unsigned int newVL ) {
        horizontalLine = newHL;
        verticalLine = newVL;
    }

    inline void decreaseVLine() { if ( verticalLine > 0 ) { --verticalLine; } }

    inline void increaseVLine() { if ( verticalLine < std::numeric_limits<unsigned int>::max() ) { ++verticalLine; } }

    inline void decreaseHLine() { if ( horizontalLine > 0 ) { --horizontalLine; } }

    inline void increaseHLine() {
        if ( horizontalLine < std::numeric_limits<unsigned int>::max() ) { ++horizontalLine; }
    }

    /// Permet de récuperer le nombre de ligne horizontale
    ///\return unsigned int
    inline unsigned int getHLine() const { return horizontalLine; }

    /// Permet de récuperer le nombre de ligne Verticale
    ///\return unsigned int
    inline unsigned int getVLine() const { return verticalLine; }

    /// Permet de changer la l'intensité de la couleur de la grille
    ///\param newFade : nouvelle intensité
    ///\warning L'intensité doit être un entier en 0 et 255 !
    inline void setFade( uint8_t newFade ) { Fade = newFade; }

    /// Permet de récupérer l'intesité de la couelur de la grille
    ///\return uint8_t
    inline uint8_t getFade() const { return Fade; }

    /// Renvoie si la grille est activé
    ///\return bool
    inline bool isActivate() const { return Fade; }

    /// Active la grille
    inline void enable() { activate = true; }

    /// Désactive la grille
    inline void disable() { activate = false; }

    /// Inverse L'activation de la grille
    inline void invActivation() { activate = !activate; }

    /// Renvoie si la Grid est "Feet a la Window" (Auteur et largeur égale à celle de la fenetre)
    inline bool isFeetToWindow() const { return feetToWindow; }

    /// permet d'activerou non le "Feet a la Window" (Auteur et largeur égale à celle de la fenetre)
    ///\param feeted : nouvelle valeurs de feet to window
    inline void setFeetToWindow( bool feeted ) { feetToWindow = feeted; }

    /// Permet de dessiné a  la fenetre
    virtual void draw( EZWindow& window ) const;

    /// Permet d'ecrire dans un flux de sortie une sauvegarde de la grille
    ///\param os : flux de sortie dans lequelle sera sauvegarder les donées la grille
    void write( std::ostream& os ) const;


};

#endif // SHAPE_EDITOR_GRID_HPP
