#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "../../Shape/Shape.hpp"

class Ellipse
        : public Shape {
private:
    //Données membres
    Size semiWidth{ 1 };
    Size semiHeight{ 1 };


public:
    //Constructeur
    Ellipse( EZColor color, Thick thick, Coord x, Coord y, Size semiWidth, Size semiHeight );

    //Constructeur par copie
    Ellipse( const Ellipse& );

    //Constructeur à partir d'un fichier texte
    explicit Ellipse( std::istream& );

    //Destructeur
    ~Ellipse() noexcept override = default;

    //***********************************
    // DECLARATION DES FONCTIONS MEMBRES*
    //***********************************
    //Getter
    inline Size getSemiWidth() const { return semiWidth; }

    inline Size getSemiHeight() const { return semiHeight; }

    //Setter
    inline void setSemiWidth( const Size _semiWidth ) { semiWidth = _semiWidth; }

    inline void setSemiHeight( const Size _semiHeight ) { semiHeight = _semiHeight; }

    //Fonctions diverses
    void draw( EZWindow& window ) const override;

    double perimeter() const override;

    void setSize( Size w, Size h, Point* p ) override;

    void write( std::ostream& ) const override;
    //***************************************
    // DECLARATION DES FONCTIONS NON MEMBRES*
    //***************************************
};

#endif //ELLIPSE_HPP
