#include<iostream>
#include "Circle.hpp"

//Constructeur
Circle::Circle(
        const EZColor color, const Thick thick, const Coord x, const Coord y, const Size rad )
        : Shape( color, thick, x, y ), radius( rad ) {
    std::cerr << "Circle::Circle( " << getColor() << ',' << getThick() << ',' << getAnchor() << ',' << radius << ")"
              << std::endl;

    Shape::addPoint( x + radius, y + radius );
}


//Constructeur à partir d'un fichier texte
Circle::Circle( std::istream& is )
        : Shape( is ) {
    is >> radius;

    Shape::addPoint( getXAnchor() + radius, getYAnchor() + radius );
}


//***********************************
// DEFINITION DES FONCTIONS MEMBRES *
//***********************************


void Circle::draw( EZWindow& window ) const {
    // Appeler le draw de shape
    Shape::draw( window );

    auto tmp_x = getXAnchor();
    auto tmp_y = getYAnchor();

    if ( !isFilled() ) {
        window.drawCircle( tmp_x, tmp_y, tmp_x + radius, tmp_y + radius );
    }
    else {
        window.fillCircle( tmp_x, tmp_y, tmp_x + radius, tmp_y + radius );
    }
}

void Circle::write( std::ostream& os ) const {
    os << "Circle" << ' ' << getColor() << ' ' << getThick() << ' ' << isFilled() << ' ' << getAnchor() << ' '
       << radius;
}


void Circle::setSize( const Size w, const Size h, Point* p ) {
    setRadius( w );

    p->setXY( getXAnchor() + radius, getYAnchor() + radius );
}
