#include<iostream>
#include<stdexcept>

using namespace std;

#include "Rectangle.hpp"

//Constructeur
Rectangle::Rectangle( EZColor _color, int _thick, Coord _x, Coord _y, uint _width, uint _height )
        : Shape( _color, _thick, _x, _y ), width( _width ), height( _height ) {
    //new Rectangle(ez_black,1,getWidth()/2-25,getHeight()/2-25,
    // getWidth()/2+25,getHeight()/2+25));

    cerr << "Rectangle::Rectangle( " << getColor() << ',' << getThick() << ',' << _x << ',' << _y << ',' << _width
         << ',' << _height << ")" << endl;

    Shape::addPoint( _x + width, _y + height );
}

//Constructeur par copie
/*
Rectangle::Rectangle(const Rectangle& orig)
: Rectangle(orig.getColor(),orig.getThick(), orig.getAnchor().getX(), orig.getAnchor().getY(),
orig.width, orig.height)
{cerr << "Rectangle::Rectangle(const Rectangle& orig)" << endl;}
*/
//Constructeur à partir d'un fichier texte
Rectangle::Rectangle( istream& is )
        : Shape( is ), width( 0 ), height( 0 ) {
    is >> width >> height;

    Shape::addPoint( getXAnchor() + width, getYAnchor() + height );
}



//***********************************
// DEFINITION DES FONCTIONS MEMBRES *
//***********************************

void Rectangle::draw( EZWindow& window ) const {
    Shape::draw( window );

    int tmp_x = getAnchor().getX();
    int tmp_y = getAnchor().getY();

    if ( !isFilled() ) {
        window.drawRectangle( tmp_x, tmp_y, tmp_x + width, tmp_y + height );
    }
    else {
        window.fillRectangle( tmp_x, tmp_y, tmp_x + width, tmp_y + height );
    }

}


void Rectangle::write( ostream& os ) const {
    os << "Rectangle" << ' ' << getColor() << ' ' << getThick() << ' ' << isFilled() << ' ' << getAnchor() << ' '
       << width << ' ' << height;
}

void Rectangle::setSize( const Size w, const Size h, Point* p ) {
    setWidth( w );
    setHeight( h );
    p->setXY( getXAnchor() + width, getYAnchor() + height );
}

//***************************************
// DEFINITION DES FONCTIONS NON MEMBRES *
//***************************************
