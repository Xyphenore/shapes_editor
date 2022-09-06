#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include "../Shape/Shape.hpp"

class Text
        : public Shape {
private:

    /// Varaible qui contient le texte qui sera écrit à l'ecran.
    std::string text;

    /// La Taille de la font.
    int fontSize = 2;

    /// Nom de la font.
    ///\note Actuellement non-utilisé
    std::string FontName;

public:

    /// Constructeur d'un text
    ///\param text : texte à écrire.
    ///\param x : coordonnée x du texte.
    ///\param y : coordonnée y du texte.
    ///\param FontName : nom de la font
    Text( std::string _text, int x, int y, std::string _FontName );

    /// Constructeur par flux entrant
    ///\param is : flux entrant
    Text( std::istream& is );

    Text() = delete;

    /// Constructeur par copie
    Text( const Text& );

    ~Text();


    /// Dessine le texte à l'écran.
    ///\param Window : Fenetre ou est affiché le texte.
    virtual void draw( EZWindow& Window ) const;

    /// Change le texte afficher à l'ecran
    ///\param newText : le nouveau texte.
    inline void setText( std::string newText ) { text = newText; }

    /// Recupère le Texte
    ///\return std::string
    inline std::string getText() const { return text; }

    /// Permet de changer la taille de la font
    ///\note pour plus d'info sur se sujet - http://eric.remy3.free.fr/EZ-Draw++/EZ-Draw++-1.2-3/html/class_e_z_window_abfb573d451e3832d078f78180dc45513.html#abfb573d451e3832d078f78180dc45513
    inline void setFontSize( uint8_t newSize ) { fontSize = newSize; }

    /// Permet de recupérerla taille vers la font
    ///\return un uint8_t qui est la taille de la font;
    inline uint8_t getFontSize() const { return fontSize; }

    inline void setFontName( std::string newFontName ) { FontName = newFontName; }

    inline std::string getFontName() const { return FontName; }

    /// Ecrit sur un flux sortant une sauvegarde du texte
    ///\param os flux sortant ou sera écrit la sauvegarde.
    virtual void write( std::ostream& os ) const;

    virtual double perimeter() const;

    void setSize( Size w, Size h, Point* p ) override;
};

#endif
