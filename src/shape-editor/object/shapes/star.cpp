#include "Star.hpp"
#include <cmath>

Star::Star( int x, int y, unsigned int pointeNumber, unsigned int _rOne, unsigned int _rTwo )
        : Shape( ez_black, 6, x, y ), rOne( _rOne ), rTwo( _rTwo ), theta( 0 ) {
    double tmp_x = 0;
    double tmp_y = 0;

    rOne += x;
    rTwo += y;


    for ( size_t i = 0; i < pointeNumber * 2; i++ ) {
        theta = ( ( 2 * G_PI ) * pointeNumber ) / i;

        if ( i % 2 == 0 ) {
            tmp_x = rOne * cos( theta );
            tmp_y = rOne * sin( theta );
        }
        else {
            tmp_x = rTwo * cos( theta );
            tmp_y = rTwo * sin( theta );
        }

        pointArray.push_back( Point( tmp_x, tmp_y ) );
        std::cout << theta << "  \n";
    }
}

Star::Star( const Star& src )
        : Shape( src.getColor(), src.getThick(), src.getAnchor().getX(), src.getAnchor().getY() ), rOne( src.rOne ),
          rTwo( src.rTwo ), theta( 0 ) {
    for ( size_t i = 0; i < pointArray.size(); i++ ) {
        pointArray.push_back( src.pointArray[i] );
    }
}

Star::~Star() {

}

void Star::draw( EZWindow& Win ) const {
    for ( size_t i = 0; i < pointArray.size(); i++ ) {
        pointArray.at( i ).draw( Win );
    }
}

void Star::write( std::ostream& ost ) const {
    std::cout << "blabla";
}

void Star::setSize( Size w, Size h, Point* p ) {
    std::cout << "blabla";
}

double Star::perimeter() const {
    return 0;
}
