#include<iostream>
#include<cmath>

#include "Ellipse.hpp"

//Constructeur
Ellipse::Ellipse(
        const EZColor color, const Thick thick, const Coord x, const Coord y, const Size _semiWidth,
        const Size _semiHeight )
        : Shape( color, thick, x, y ), semiWidth( _semiWidth ), semiHeight( _semiHeight ) {
    std::cerr << "Ellipse::Ellipse( " << getColor() << ',' << getThick() << ',' << getAnchor() << ',' << _semiWidth
              << ',' << _semiHeight << ")" << std::endl;

    addPoint( x + semiWidth, y + semiHeight );
}

//Constructeur par copie
Ellipse::Ellipse( const Ellipse& src )
        : Ellipse( src.getColor(), src.getThick(), src.getXAnchor(), src.getYAnchor(), src.semiWidth, src.semiHeight ) {
    std::cerr << "Ellipse::Ellipse(const Ellipse& src)" << std::endl;
}

//Constructeur à partir d'un fichier texte
Ellipse::Ellipse( std::istream& is )
        : Shape( is ) {
    is >> semiWidth >> semiHeight;

    Shape::addPoint( getXAnchor() + semiWidth, getYAnchor() + semiHeight );
}


//***********************************
// DEFINITION DES FONCTIONS MEMBRES *
//***********************************

void Ellipse::draw( EZWindow& window ) const {
// Appeler le draw de shape
    Shape::draw( window );

    int tmp_x = getXAnchor();
    int tmp_y = getYAnchor();

    if ( !isFilled() ) {
        window.drawCircle( tmp_x, tmp_y, tmp_x + semiWidth, tmp_y + semiHeight );
    }
    else {
        window.fillCircle( tmp_x, tmp_y, tmp_x + semiWidth, tmp_y + semiHeight );
    }
}

void Ellipse::write( std::ostream& os ) const {
    os << "Ellipse" << ' ' << getColor() << ' ' << getThick() << ' ' << isFilled() << ' ' << getAnchor() << ' '
       << semiWidth << ' ' << semiHeight;
}

double Ellipse::perimeter() const {
//à vérifier : Formule de Ramanujan
    return ( G_PI * ( 3 * ( getSemiWidth() + getSemiHeight() ) - sqrt( ( ( 3 * getSemiWidth() ) + getSemiHeight() ) *
                                                                       ( getSemiWidth() +
                                                                         ( 3 * getSemiHeight() ) ) ) ) );
}

void Ellipse::setSize( const Size w, const Size h, Point* p ) {
    setSemiWidth( w );
    setSemiHeight( h );

    p->setXY( getXAnchor() + semiWidth, getYAnchor() + semiHeight );
}
