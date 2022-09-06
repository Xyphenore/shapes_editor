#include<iostream>
#include<stdexcept>

using namespace std;

#include "../../Shape/Shape.hpp"
#include "Polygone.hpp"

Polygone::Polygone(
        ulong _color, int _thick, uint _x, uint _y, uint _ax, uint _ay, uint _bx, uint _by, uint _cx, uint _cy,
        size_t _nbSommets )
        : Shape( _color, _thick, _x, _y ) {
//new Polygone(ez_black,1,getWidth()/2,getHeight()/2-50,
// getWidth()/2-25,getHeight()/2-30,
// getWidth()/2+25,getHeight()/2-30));
    cerr << "Polygone::Polygone( " << getColor() << ',' << getThick() << ',' << _x << ',' << _y << ',' << _ax << ','
         << _ay << ',' << _bx << ',' << _by << ',' << _cx << ',' << _cy << ',' << getNBSommets() << ")" << endl;


    Shape::addPoint( _ax, _ay );
    Shape::addPoint( _bx, _by );
    Shape::addPoint( _cx, _cy );

    uint mov_x = ( _ax + _bx + _cx ) / 3;
    uint mov_y = ( _ay + _by + _cy ) / 3;
    setXYAnchor( mov_x, mov_y );

    cerr << "nb points = " << getNBSommets() << endl;
}

//Constructeur par copie
Polygone::Polygone( const Polygone& orig )
        : Polygone( orig.getColor(), orig.getThick(), orig.getAnchor().getX(), orig.getAnchor().getY(),
                    orig.getA()->getX(), orig.getA()->getY(), orig.getB()->getX(), orig.getB()->getY(),
                    orig.getC()->getX(), orig.getC()->getY(), orig.getNBSommets() ) {
    cerr << "Polygone::Polygone(const Polygone& orig)" << endl;
}

//Constructeur à partir d'un fichier texte
Polygone::Polygone( istream& is )
        : Shape( is ) {
    std::size_t nbSommets;
    is >> nbSommets;

    for ( std::size_t i = 0; i < nbSommets; i++ ) {
        Coord tmpx;
        Coord tmpy;
        is >> tmpx >> tmpy;
        Shape::addPoint( tmpx, tmpy );
    }
}

//Destructeur
Polygone::~Polygone() { cerr << "~Polygone()" << endl; }


//***********************************
// DECLARATION DES FONCTIONS MEMBRES*
//***********************************


void Polygone::draw( EZWindow& window ) const {
    Shape::draw( window );

    const auto nbSommets = getNBSommets();
    for ( size_t i = 0; i < nbSommets - 1; i++ ) {
        window.drawLine( getXSommet( i ), getYSommet( i ), getXSommet( i + 1 ), getYSommet( i + 1 ) );
    }

    window.drawLine( getXSommet( nbSommets - 1 ), getYSommet( nbSommets - 1 ), getXSommet( 0 ), getYSommet( 0 ) );
}


void Polygone::setSize( const Size w, const Size h, Point* p ) {
    uint mov_x = ( getA()->getX() + getB()->getX() + getC()->getX() ) / 3;
    uint mov_y = ( getA()->getY() + getB()->getY() + getC()->getY() ) / 3;
    setXYAnchor( mov_x, mov_y );

    //p->setXY(getAnchor().getX()+_w,getAnchor().getY()+_h);
}

/*double Polygone::side(Point a, Point b)
{

}*/

double Polygone::perimeter() const {
    return 0;
}

void Polygone::write( ostream& os ) const {
    os << "Polygone" << ' ' << getColor() << ' ' << getThick() << ' ' << isFilled() << ' ' << getAnchor() << ' '
       << getNBSommets() << ' ';

    for ( std::size_t i = 0; i < getNBSommets(); i++ ) {
        os << getSommet( i ) << ' ';
    }
}
