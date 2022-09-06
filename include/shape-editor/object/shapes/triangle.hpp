#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "../../Shape/Shape.hpp"


class Triangle
        : public Shape {

private:

public:
    ///Constructeur de Triangle
    ///\param color : couleur de la forme
    ///\param thick : épaisseur des traits de la forme
    ///\param x : position x de lancre
    ///\param y : position y de lancre
    ///\param ax : position x du point a
    ///\param ay : position y de point a
    ///\param bx : position x de point b
    ///\param by : position y de point b
    Triangle(
            ulong _color, int _thick, uint _x, uint _y, uint _ax, uint _ay, uint _bx, uint _by );

    //Constructeur par copie
    Triangle( const Triangle& orig );

    ///Constructeur à partir d'un flux d'entrée
    ///\param is : Flux d'entrée pour lire une sauvegarde.
    explicit Triangle( std::istream& is );

    //Destructeur
    ~Triangle() noexcept override = default;

    //empecher la surcharge d'opérateur d'affectation
    Triangle& operator=( const Triangle& ) = delete;


    //***********************************
    // DECLARATION DES FONCTIONS MEMBRES*
    //***********************************

    inline const Point* getA() const { return getSommet( 0 ); }

    inline const Point* getB() const { return getSommet( 1 ); }


    inline Coord getXA() const { return getXSommet( 0 ); }

    inline Coord getXB() const { return getXSommet( 1 ); }


    inline Coord getYA() const { return getYSommet( 0 ); }

    inline Coord getYB() const { return getYSommet( 1 ); }


    inline void setXYA( const Coord x, const Coord y ) { setXYSommet( 0, x, y ); }

    inline void setXYB( const Coord x, const Coord y ) { setXYSommet( 1, x, y ); }

    ///Fonction qui dessine un Triangle sur l'écran
    ///\param window : Fenêtre où est dessiné le triangle.
    void draw( EZWindow& window ) const override;


    void setSize( Size w, Size h, Point* p ) override;

    // Permet de récuperer le perimetre d'un triangle
    //double side(Point a, Point b);
    double perimeter() const override;

    /// Permet d'ecrire une sauvegarde sur un flux de sortie
    ///\param os : flux de sortie.
    void write( std::ostream& os ) const override;


};

#endif //TRIANGLE_HPP
