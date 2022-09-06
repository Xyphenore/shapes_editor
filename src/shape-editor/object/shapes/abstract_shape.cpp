#include "../../../include/shape-editor/shapes/abstract_shape.hpp"

#include <iostream>
#include <sstream>
#include "Shape.hpp"

#include "Exceptions/Invalid_TypeFactory.hpp"


//***********************************
//		CONSTRUCTEURS/DESTRUCTEUR   	*
//***********************************

//Constructeur par défaut
Shape::Shape( const EZColor _color, const Thick _thick, const Coord x, const Coord y )
        : color( _color ), thick( _thick ), anchor( x, y ) {
    std::cerr << "Shape::Shape(" << color << ',' << _thick << ',' << anchor << ")" << std::endl;
}

//Constructeur de copie
Shape::Shape( const Shape& src )
        : color( src.color ), thick( src.thick ), anchor( src.anchor ) {
    for ( const auto& pts: src.Sommets ) {
        addPoint( pts->getX(), pts->getY() );
    }

    std::cerr << "Shape::Shape(const Shape& src)" << std::endl;
}


// pour construire une instance à partir d'un flux >>
Shape::Shape( std::istream& is ) {
    Coord loc_x;
    Coord loc_y;

    std::cerr << "Shape::Shape(const istream& is)" << std::endl;

    is >> color >> thick >> filled >> loc_x >> loc_y;

    setXYAnchor( loc_x, loc_y );

}

//Destructeur
// Virtual indique au compilateur qu'on choisira
// le destructeur de la classe fille concerné
// au moment de l'execution.
Shape::~Shape() {
    std::cerr << "~Shape()" << std::endl;

    // Destruction des points créés
    for ( size_t i = 0; i < getNBSommets(); i++ ) {
        delete Sommets.at( i );
    }

    // appelle à l'execution le destructeur de la classe fille concernée
}


//***********************************
// DEFINITION DES FONCTIONS MEMBRES *
//***********************************

void Shape::addPoint( Coord x, Coord y ) {
    Sommets.push_back( std::move( new Point( x, y ) ) );
}

void Shape::moveShape( Coord _x, Coord _y ) {
    for ( auto& Sommet: Sommets ) {
        Sommet->setX( ( Sommet->getX() - anchor.getX() ) + _x );
        Sommet->setY( ( Sommet->getY() - anchor.getY() ) + _y );
    }

    setXYAnchor( _x, _y );
}

//Pour la Factory avancée

//Crée l'instance du dictionnaire associatif déclaré dans Shape.hpp
//Constiendra la liste associations chaine + fonction factory associé à cette chaine
std::map<std::string, Shape::factory_function, std::less<> > Shape::map_shapes;

// liste toutes les formes qui ont fait enregistrer une factory dans le map.
void Shape::print_registered_factory_functions( std::ostream& os ) {
    os << "Classes dont les map_shapes ont été enregistrées associées à une chaine de typage :" << std::endl;

    // Boucle for généralisée
    // à chaque itération e sera une ref à l'une des paires
    // contenue dans la factory
    // e.first permet juste d'étudier son bon fonctionnement
    for ( const auto& e: map_shapes ) {
        os << e.first << std::endl;
    }
}


Point* Shape::isOverSommet( Coord mouse_x, Coord mouse_y ) const {
    for ( std::size_t i = 0; i < Sommets.size(); i++ ) {
        if ( Sommets.at( i )->isOver( mouse_x, mouse_y ) ) {
            return Sommets.at( i );
        }
    }

    return nullptr;
}

// Vérifie si les coordonnées en paramètre (position du curseur de la souris)
// sont au dessus des coordonnées de l'ancre de redimension de la forme
bool Shape::isOverSommetBool( Coord mouse_x, Coord mouse_y ) const {
    for ( const auto& Sommet: Sommets ) {
        if ( Sommet->isOver( mouse_x, mouse_y ) ) {
            return true;
        }
    }

    return false;
}


// TODO A tester
void Shape::draw( EZWindow& window ) const {
    window.setColor( color );
    window.setThick( thick );

    /// Dessine l'ancre sous forme de cercle vide.
    window.drawCircle( anchor.getX() - anchor.getSize(), anchor.getY() - anchor.getSize(),
                       anchor.getX() + anchor.getSize(), anchor.getY() + anchor.getSize() );
    if ( selected ) {
        window.setThick( getThick() + 1 );
    }

    if ( Sommets.size() > 0 ) {
        for ( size_t i = 0; i < Sommets.size(); i++ ) {
            Sommets.at( i )->draw( window );
        }
    }

}


Shape* Shape::load( std::istream& is ) {
    std::string typeName;
    is >> typeName;

    try {
        // Récupération de l'adresse de la factory pour le type de Shape voulu
        factory_function f = map_shapes.at( typeName );

        return ( *f )( is );

    }
    catch ( const std::range_error& ) {
        throw invalid_type_Factory( typeName );
    }
}


//***************************************
// DEFINITION DES FONCTIONS NON MEMBRES *
//***************************************

std::ostream& operator<<( std::ostream& os, const Shape& src ) {
    src.write( os );
    return os;
}
