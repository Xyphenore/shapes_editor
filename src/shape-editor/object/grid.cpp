#include "Grid.hpp"

Grid::Grid( int x, int y, unsigned int verticalLineNumber, unsigned int horizontaleLineNumber )
        : Rectangle( ez_black, 6, x, y, 512, 256 ), horizontalLine( verticalLineNumber ),
          verticalLine( horizontaleLineNumber ), activate( true ), feetToWindow( false ) {
    //this->setSommets(this->getAnchor().getX()+this->getWidth(),this->getAnchor().getY()+this->getHeight());
    this->setFill( true );
}

Grid::Grid()
        : Grid( 64, 64, 16, 16 ) {

}

Grid::Grid( std::istream& is )
        : Rectangle( is ) {
    is >> horizontalLine >> verticalLine >> feetToWindow;
}

Grid::Grid( const Grid& src )
        : Rectangle( ez_black, 6, src.getXAnchor(), src.getYAnchor(), src.getWidth(), src.getHeight() ),
          horizontalLine( src.horizontalLine ), verticalLine( src.verticalLine ), Fade( src.Fade ),
          activate( src.activate ), feetToWindow( src.feetToWindow ) {

}

Grid::~Grid() {

}

void Grid::draw( EZWindow& Win ) const {
    int tmp_x = this->getXAnchor();
    int tmp_y = this->getYAnchor();

    if ( activate && isFilled() ) {
        const int usedWidth = ( feetToWindow ? Win.getWidth() : this->getWidth() );
        const int usedHeight = ( feetToWindow ? Win.getHeight() : this->getHeight() );

        Win.setColor( Win.getRGB( Fade, Fade, Fade ) );


        const unsigned int hLigneSpace = ( horizontalLine != 0 ? usedHeight / horizontalLine : 0 );

        for ( unsigned int i = 0; i < horizontalLine; i++ ) {
            Win.drawLine( tmp_x, tmp_y + hLigneSpace * i, tmp_x + usedWidth, tmp_y + hLigneSpace * i );
        }


        const unsigned int vLigneSpace = ( verticalLine != 0 ? usedWidth / verticalLine : 0 );

        for ( unsigned int i = 0; i < verticalLine; i++ ) {
            Win.drawLine( tmp_x + vLigneSpace * i, tmp_y, tmp_x + vLigneSpace * i, tmp_y + usedHeight );
        }


    }

    Win.setThick( 8 );
    Win.drawPoint( tmp_x, tmp_y );

    if ( !feetToWindow ) {
        Win.drawPoint( tmp_x + this->getWidth(), tmp_y + this->getHeight() );
    }

    Win.setThick( 2 );

    if ( isSelected() ) {
        Win.setColor( ez_red );
    }

    if ( !feetToWindow ) {
        Win.drawRectangle( tmp_x, tmp_y, tmp_x + this->getWidth(), tmp_y + this->getHeight() );
    }

    Win.setColor( ez_black );
}

void Grid::write( std::ostream& os ) const {
    os << "Grid" << ' ' << getColor() << ' ' << getThick() << ' ' << isFilled() << ' ' << getAnchor() << ' '
       << getWidth() << ' ' << getHeight() << ' ' << horizontalLine << ' ' << verticalLine << ' ' << feetToWindow;
}
