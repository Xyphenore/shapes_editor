#include<iostream>

#include "Square.hpp"


//Constructeur
Square::Square(
        const EZColor color, const int thick, const Coord x, const Coord y, const uint _length )
        : Shape( color, thick, x, y ), length( _length ) {
    std::cerr << "Square( " << getColor() << ',' << getThick() << ',' << getAnchor().getX() << ',' << getAnchor().getY()
              << ',' << getLength() << ")" << std::endl;

    Shape::addPoint( x + length, y + length );
}


//Constructeur à partir d'un fichier texte
Square::Square( std::istream& is )
        : Shape( is ) {
    is >> length;

    Shape::addPoint( getXAnchor() + length, getYAnchor() + length );
}


//***********************************
// DEFINITION DES FONCTIONS MEMBRES *
//***********************************
void Square::draw( EZWindow& window ) const {
// Appeler le draw de shape
    Shape::draw( window );

    int tmp_x = getAnchor().getX();
    int tmp_y = getAnchor().getY();

    if ( !isFilled() ) {
        window.drawRectangle( static_cast<int>( tmp_x ), static_cast<int>( tmp_y ), static_cast<int>( tmp_x + length ),
                              static_cast<int>( tmp_y + length ) );
    }
    else {
        window.fillRectangle( static_cast<int>( tmp_x ), static_cast<int>( tmp_y ), static_cast<int>(tmp_x + length ),
                              static_cast<int>( tmp_y + length ) );
    }
}


void Square::write( std::ostream& os ) const {
    os << "Square " << getColor() << ' ' << getThick() << ' ' << isFilled() << ' ' << getAnchor() << ' ' << length;
}


void Square::setSize( const Size w, const Size h, Point* p ) {
    setLength( w );
    p->setXY( getXAnchor() + length, getYAnchor() + length );
}


//***************************************
// DEFINITION DES FONCTIONS NON MEMBRES *
//***************************************
