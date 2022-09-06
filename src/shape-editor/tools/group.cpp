#include<iostream>
#include<stdexcept>

using namespace std;


#include "SetOfShapes.hpp"

//Constructeur
SetOfShapes::SetOfShapes( size_t _maxShapes )
        : shapeArray() {
    cerr << "SetOfShapes::SetOfShapes(" << shapeArray.size() << ")" << endl;
}

//Destructeur
SetOfShapes::~SetOfShapes() {
    cerr << "SetOfShapes::~SetOfShapes()" << endl;
    for ( std::size_t i = 0; i < shapeArray.size(); i++ ) {
        delete shapeArray[i];
    }
}

//***********************************
// DEFINITION DES FONCTIONS MEMBRES *
//***********************************
void SetOfShapes::add( Shape* _pshape ) {
    shapeArray.push_back( _pshape );

}


// TODO à améliorer pour éviter la recopie de tableau
// piste de la liste à explorer.
void SetOfShapes::del( Shape* _pshape ) {
    for ( size_t i = 0; i < shapeArray.size(); i++ ) {
        if ( shapeArray[i] == _pshape ) {
            shapeArray.erase( shapeArray.begin() + i );
        }
    }
    //TODO try catch
    //else throw exception out_of_range ?
}

Shape* SetOfShapes::isOver( uint mouse_x, uint mouse_y ) const {
    for ( size_t i = 0; i < shapeArray.size(); i++ ) {
        if ( shapeArray.at( i )->getAnchor().isOver( mouse_x, mouse_y ) ) {
            return shapeArray.at( i );
        }
    }

    return nullptr;
}


//TODO à creuser
Shape* SetOfShapes::isResizing( uint mouse_x, uint mouse_y ) const {

    for ( auto i: shapeArray ) {
        //cerr << "Bool set of shape = " << shapeArray.at(i)->isResizing(mouse_x, mouse_y) << endl;
        if ( i->isOverSommet( mouse_x, mouse_y ) ) {
            return i;
        }
    }


    return nullptr;
}

void SetOfShapes::draw( EZWindow& window ) const {
    for ( auto i: shapeArray ) {
        i->draw( window );
    }
}

void SetOfShapes::save( ostream& os ) const {
    os << shapeArray.size() << endl;
    os
            << *this; // appelle << sur l'instance courante renvoyée par this et on veut pas l'adresse mais le contenu donc *this
}


//factory: fonction membre de classe
// qui fabrique un pointeur sur sa classe
void SetOfShapes::load( istream& is ) {
    size_t nb_shapes; //variable locale et non la donnée membres
    is >> nb_shapes;
    for ( size_t i = 0; i < nb_shapes; i++ ) {
        add( Shape::load( is ) );
    } // Fonction static donc on l'appelle sur la classe t non sur une instance
}


void SetOfShapes::setThickAll( unsigned int newThick ) {
    std::cout << newThick << '\n';
    for ( size_t i = 0; i < shapeArray.size(); i++ ) {
        shapeArray.at( i )->setThick( newThick );
    }
}

//***********************************
// DEFINITION DES FONCTIONS MEMBRES *
//***********************************

//Surcharge opérateur<<
ostream& operator<<( ostream& os, const SetOfShapes& _sOfShape ) {

    for ( size_t i = 0; i < _sOfShape.getNumberShapes(); i++ ) {
        //_sOfShape.shapes[i]->write(os);
        os << *_sOfShape.getShapeArray().at( i ) << endl;
    }
    return os;
}
