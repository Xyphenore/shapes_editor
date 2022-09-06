#ifndef POLYGONE_HPP
#define POLYGONE_HPP

#include "../../Shape/Shape.hpp"


class Polygone
        : public Shape {
private:
public:
    //Constructeur
    Polygone(
            ulong _color, int _thick, uint _x, uint _y, uint _ax, uint _ay, uint _bx, uint _by, uint _cx, uint _cy,
            size_t _nbSommets );

    //Constructeur par copie
    Polygone( const Polygone& orig );

    //Constructeur à partir d'un fichier texte
    Polygone( std::istream& is );

    //Destructeur
    ~Polygone();

    //empecher la surcharge d'opérateur d'affectation
    //Polygone& operator=(const Polygone&)= delete;
    //***********************************
    // DECLARATION DES FONCTIONS MEMBRES*
    //***********************************
    //getter
    inline const Point* getA() const { return getSommet( 0 ); }

    inline const Point* getB() const { return getSommet( 1 ); }

    inline const Point* getC() const { return getSommet( 2 ); }

    inline Coord getXA() const { return getXSommet( 0 ); }

    inline Coord getXB() const { return getXSommet( 1 ); }

    inline Coord getXC() const { return getXSommet( 2 ); }

    inline Coord getYA() const { return getYSommet( 0 ); }

    inline Coord getYB() const { return getYSommet( 1 ); }

    inline Coord getYC() const { return getYSommet( 2 ); }

    inline void setXYA( const Coord x, const Coord y ) { setXYSommet( 0, x, y ); }

    inline void setXYB( const Coord x, const Coord y ) { setXYSommet( 1, x, y ); }

    inline void setXYC( const Coord x, const Coord y ) { setXYSommet( 2, x, y ); }


    void draw( EZWindow& window ) const;

    void drawPolygone( EZWindow& window ) const;

    void setSize( Size w, Size h, Point* p ) override;

    double side( Point a, Point b );

    double perimeter() const;

    void write( std::ostream& os ) const;
    //***************************************
    // DECLARATION DES FONCTIONS NON MEMBRES*
    //***************************************


};

#endif //POLYGONE_HPP
