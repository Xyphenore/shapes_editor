#include "Image.hpp"

Image::Image( int x, int y, std::string _texturePath )
        : Rectangle( ez_black, 1, x, y, 0, 0 ), texturePath( _texturePath ), texture( nullptr ) {
    texture = new EZImage( texturePath.c_str() );
    this->setWidth( texture->getWidth() );
    this->setHeight( texture->getHeight() );
}

Image::Image( const Image& src )
        : Rectangle( src.getColor(), src.getThick(), this->getAnchor().getX(), this->getAnchor().getY(), 0, 0 ),
          texturePath( src.texturePath ), texture( nullptr ) {
    texture = new EZImage( texturePath.c_str() );
    this->setWidth( texture->getWidth() );
    this->setHeight( texture->getHeight() );
}

Image::Image( std::istream& is )
        : Rectangle( is ) {
    is >> texturePath >> activeAlpha >> Zoom >> Rotation;
    texture = new EZImage( texturePath.c_str() );
}

Image::~Image() {
    delete texture;
    std::cerr << "~Image()" << std::endl;
}

void Image::draw( EZWindow& Win ) const {

    EZImage* newTexture = new EZImage( *this->texture->rotate( Rotation % 360, 1 ) );
    EZImage* newTextureTwo = new EZImage( *newTexture->scale( Zoom ) );
    newTextureTwo->setAlpha( canalAlpha );
    newTextureTwo->setOpacity( Opacity );
    EZPixmap* newPixmap = new EZPixmap( *newTextureTwo );

    unsigned int tmp_x = this->getAnchor().getX();
    unsigned int tmp_y = this->getAnchor().getY();

    Win.setThick( 16 );
    newPixmap->paint( Win, tmp_x, tmp_y );
    Win.drawPoint( tmp_x, tmp_y );

    delete newTexture;
    delete newTextureTwo;
    delete newPixmap;
}

void Image::write( std::ostream& os ) const {
    os << "Image" << ' ' << getColor() << ' ' << getThick() << ' ' << isFilled() << ' ' << getAnchor() << ' '
       << this->getWidth() << ' ' << this->getHeight() << ' ' << texturePath << ' ' << activeAlpha << ' ' << Zoom << ' '
       << Rotation;
}
