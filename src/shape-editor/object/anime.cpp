#include "AnimeImage.hpp"

AnimeImage::AnimeImage( int x, int y, std::string _texturePath, unsigned int _maxFrame )
        : Image( x, y, _texturePath ), actualFrame( 0 ), maxFrame( _maxFrame ), frameWidth( 0 ) {
    frameWidth = this->getTexture()->getWidth() / maxFrame;
}

AnimeImage::AnimeImage( std::istream& is )
        : Image( is ), actualFrame( 0 ), maxFrame( 0 ), frameWidth( 0 ) {
    is >> actualFrame >> maxFrame >> frameWidth;
    frameWidth = this->getTexture()->getWidth() / maxFrame;
}

AnimeImage::~AnimeImage() {

}

void AnimeImage::draw( EZWindow& Win ) const {

    int tmp_x = this->getAnchor().getX();
    int tmp_y = this->getAnchor().getY();

    EZImage* newTexture = this->getTexture()->scale( this->getZoom() );


    newTexture->paintSubimage( Win, tmp_x, tmp_y, ( frameWidth * ( actualFrame % maxFrame ) ) * getZoom(), 0,
                               frameWidth * getZoom(), this->getTexture()->getHeight() * getZoom() );
    Win.setThick( 8 );
    Win.drawPoint( tmp_x, tmp_y );
}

void AnimeImage::write( std::ostream& os ) const {
    os << "AnimeImage" << ' ' << getColor() << ' ' << getThick() << ' ' << isFilled() << ' ' << getAnchor() << ' '
       << this->getWidth() << ' ' << this->getHeight() << ' ' << this->getTexturePath() << ' '
       << this->isAlphaActivate() << ' ' << this->getZoom() << ' ' << this->getRotation() << ' ' << actualFrame << ' '
       << ' ' << maxFrame << ' ' << frameWidth;

}
