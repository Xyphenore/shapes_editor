#include<iostream>

#include "Triangle.hpp"

Triangle::Triangle( ulong _color, int _thick, uint _x, uint _y, uint _ax, uint _ay, uint _bx, uint _by )
        : Shape( _color, _thick, _x, _y ) {
//new Triangle(ez_black,1,getWidth()/2,getHeight()/2-50,
// getWidth()/2-25,getHeight()/2-30,
// getWidth()/2+25,getHeight()/2-30));
    std::cerr << "Triangle::Triangle( " << getColor() << ',' << getThick() << ',' << _x << ',' << _y << ',' << _ax
              << ',' << _ay << ',' << _bx << ',' << _by << ")" << std::endl;

    Shape::addPoint( _ax, _ay );
    Shape::addPoint( _bx, _by );

    std::cerr << "nb points = " << getNBSommets() << std::endl;
}

//Constructeur par copie
Triangle::Triangle( const Triangle& orig )
        : Triangle( orig.getColor(), orig.getThick(), orig.getAnchor().getX(), orig.getAnchor().getY(),
                    orig.getA()->getX(), orig.getA()->getY(), orig.getB()->getX(), orig.getB()->getY() ) {
    std::cerr << "Triangle::Triangle(const Triangle& orig)" << std::endl;
}

//Constructeur à partir d'un fichier texte
Triangle::Triangle( std::istream& is )
        : Shape( is ) {
    uint _ax, _ay, _bx, _by;
    is >> _ax >> _ay >> _bx >> _by;

    Shape::addPoint( _ax, _ay );
    Shape::addPoint( _bx, _by );
}



//***********************************
// DECLARATION DES FONCTIONS MEMBRES*
//***********************************



void Triangle::draw( EZWindow& window ) const {
    Shape::draw( window );

    if ( !isFilled() ) {
        window.drawTriangle( getXAnchor(), getYAnchor(), getXA(), getYA(), getXB(), getYB() );
    }
    else {
        window.fillTriangle( getXAnchor(), getYAnchor(), getXA(), getYA(), getXB(), getYB() );
    }
}

void Triangle::setSize( const Size w, const Size h, Point* p ) {
    p->setXY( getXAnchor() + w, getYAnchor() + h );
}

/*double Triangle::side(Point a, Point b)
{

}*/

double Triangle::perimeter() const {
    return 0;
}

void Triangle::write( std::ostream& os ) const {
    os << "Triangle" << ' ' << getColor() << ' ' << getThick() << ' ' << isFilled() << ' ' << getAnchor() << ' '
       << *getA() << ' ' << *getB();
}
