#include "FontImage.hpp"

FontImage::FontImage(
        std::string _textToPrint, std::string _texturePath, int x, int y, unsigned int charW, unsigned int charH,
        char letterTab[], size_t letterNumber )
        : Rectangle( ez_black, 6, x, y, _textToPrint.size() * charW, charH ), textToPrint( _textToPrint ),
          texturePath( _texturePath ), charWidth( charW ), charHeight( charH ), letterList(), letterArray(),
          texture( nullptr ) {

    this->texture = new EZImage( _texturePath.c_str() );
    this->setWidth( textToPrint.size() * charWidth );
    this->setHeight( charHeight );

    for ( size_t i = 0; i < 26; i++ ) {
        letterList.push_back( letterTab[i] );
    }

    unsigned int _x = 0;
    unsigned int _y = 0;
    unsigned int ligne = 0;

    for ( unsigned int i = 0; i < letterList.size(); i++ ) {
        std::pair<char, vertex> tmpP;
        if ( _x >= texture->getWidth() ) {
            ligne++;
            _x = 0;
            _y += charHeight;
        }

        tmpP.first = letterList[i];
        tmpP.second.x = _x;
        tmpP.second.y = _y;

        letterArray.push_back( tmpP );
        _x += charWidth;
    }
}

FontImage::FontImage( std::string _textToPrint, std::string ConfigFile, int x, int y )
        : Rectangle( ez_black, 0, x, y, 0, 0 ), textToPrint( _textToPrint ) {
    std::ifstream SRC( ConfigFile );
    std::string tmpStr;

    SRC >> texturePath >> charWidth >> charHeight;


    texture = new EZImage( texturePath.c_str() );
    this->setWidth( texture->getWidth() );
    this->setHeight( texture->getHeight() );


    for ( size_t i = 0; !SRC.eof(); i++ ) {
        char tmpChar;
        SRC >> tmpChar;
        letterList.push_back( tmpChar );
    }

    std::cout << texturePath << "\n";

    unsigned int _x = 0;
    unsigned int _y = 0;
    unsigned int ligne = 0;

    for ( unsigned int i = 0; i < letterList.size(); i++ ) {
        std::pair<char, vertex> tmpP;
        if ( _x >= texture->getWidth() ) {
            ligne++;
            _x = 0;
            _y += charHeight;

        }

        tmpP.first = letterList[i];
        tmpP.second.x = _x;
        tmpP.second.y = _y;

        letterArray.push_back( tmpP );
        _x += charWidth;
    }
}

FontImage::FontImage( std::istream& is )
        : Rectangle( is ), textToPrint( "" ), texturePath( "" ), charWidth( 0 ), charHeight( 0 ), letterList(),
          letterArray(), texture( nullptr ) {
    char tmp_char = ' ';
    is >> charWidth >> charHeight >> Zoom;

    is >> tmp_char;
    if ( tmp_char == '{' ) {
        is >> tmp_char;
        while ( tmp_char != '}' ) {
            texturePath += tmp_char;
            is >> tmp_char;
        }
    }

    is >> tmp_char;
    if ( tmp_char == '{' ) {
        letterList.clear();
        is >> tmp_char;
        while ( tmp_char != '}' ) {
            letterList.push_back( tmp_char );
            is >> tmp_char;
            std::cout << tmp_char;
        }
    }

    is >> tmp_char;
    if ( tmp_char == '{' ) {
        is >> tmp_char;
        while ( tmp_char != '}' ) {
            textToPrint += tmp_char;
            is >> tmp_char;
        }
    }

    this->texture = new EZImage( texturePath.c_str() );
    this->setWidth( textToPrint.size() * charWidth );
    this->setHeight( charHeight );

    unsigned int _x = 0;
    unsigned int _y = 0;
    unsigned int ligne = 0;

    for ( unsigned int i = 0; i < letterList.size(); i++ ) {
        std::pair<char, vertex> tmpP;
        if ( _x >= texture->getWidth() ) {
            ligne++;
            _x = 0;
            _y += charHeight;

        }

        tmpP.first = letterList[i];
        tmpP.second.x = _x;
        tmpP.second.y = _y;

        letterArray.push_back( tmpP );
        _x += charWidth;
    }
}

FontImage::~FontImage() {
    delete texture;
}

size_t FontImage::findInTab( char c ) {
    for ( size_t i = 0; i <= letterList.size(); i++ ) {
        if ( letterList[i] == c ) {
            return i;
        }
    }

    return 0;
}

void FontImage::draw( EZWindow& window ) const {

    vertex tmp;
    for ( size_t i = 0; i < textToPrint.size(); i++ ) {
        for ( size_t j = 0; j < letterArray.size(); j++ ) {
            if ( letterArray[j].first == textToPrint.at( i ) ) {
                tmp.x = letterArray[j].second.x;
                tmp.y = letterArray[j].second.y;
            }
        }


        EZImage* newTexture = new EZImage( *this->texture->scale( Zoom ) ); /* out Of Memory */
        unsigned int tmp_x = this->getAnchor().getX();
        unsigned int tmp_y = this->getAnchor().getY();

        newTexture->paintSubimage( window, tmp_x + ( i * charWidth * Zoom ), tmp_y + charHeight, tmp.x * Zoom,
                                   tmp.y * Zoom, charWidth * Zoom, charHeight * Zoom );
        window.drawPoint( tmp_x, tmp_y );
        this->getAnchor().draw( window );

        delete newTexture;

    }
}

void FontImage::write( std::ostream& os ) const {
    os << "FontImage" << ' ' << getColor() << ' ' << getThick() << ' ' << isFilled() << ' ' << getAnchor() << ' '
       << getWidth() << ' ' << getHeight() << ' ' << charWidth << ' ' << charHeight << ' ' << Zoom << ' '
       << '{' + texturePath + '}' << ' ' << '{';
    for ( size_t i = 0; i < letterArray.size(); i++ ) {
        os << letterArray.at( i ).first;
    }
    os << '}' << ' ' << "{" + textToPrint + "}";
}
