#ifndef STAR_HPP
#define STAR_HPP

#include "../../Shape/Shape.hpp"

class Star
        : public Shape {
private:
    unsigned int rOne;
    unsigned int rTwo;

    std::vector <Point> pointArray;

    unsigned int theta;

public:
    Star( int x, int y, unsigned int pointNumber, unsigned int rayoninterne, unsigned int rayonExterne );

    Star() = delete;

    Star( const Star& src );

    ~Star();

    virtual void draw( EZWindow& Window ) const;

    virtual double perimeter() const;

    virtual void write( std::ostream& ost ) const;

    void setSize( Size w, Size h, Point* p ) override;
};

#endif //STAR_HPP
