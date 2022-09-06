#include "Text.hpp"

Text::Text( std::string _text, int x, int y, std::string _FontName )
        : Shape( ez_black, 6, x, y ), text( _text ), FontName( _FontName ) {

}

Text::~Text() {

}

Text::Text( const Text& src )
        : Shape( src.getColor(), src.getThick(), src.getAnchor().getX(), src.getAnchor().getY() ), text( src.text ),
          FontName( src.FontName ) {

}

Text::Text( std::istream& is )
        : Shape( is ) {
    char tmp_char = ' ';
    is >> fontSize >> FontName;

    is >> tmp_char;
    if ( tmp_char == '{' ) {
        is >> tmp_char;
        while ( tmp_char != '}' ) {
            text += tmp_char;
            is >> tmp_char;
        }
    }
}

void Text::draw( EZWindow& Win ) const {
    Win.setFont( 2 );
    Win.setThick( 12 );

    this->isSelected() ? Win.setColor( ez_red ) : Win.setColor( ez_black );

    Win.drawText( EZAlign::TL, this->getAnchor().getX() + 5, this->getAnchor().getY() + 5, text );
    Win.drawPoint( this->getAnchor().getX(), this->getAnchor().getY() );
    Win.setColor( ez_black );
}

void Text::write( std::ostream& os ) const {
    os << "Text" << ' ' << this->getColor() << ' ' << this->getThick() << ' ' << this->isFilled() << ' '
       << this->getAnchor() << ' ' << fontSize << ' ' << FontName << ' ' << '{' + text + '}';
}

double Text::perimeter() const {
    return ( double )text.size();
}

void Text::setSize( const Size w, const Size h, Point* p ) {
    std::cout << "patate";
}
