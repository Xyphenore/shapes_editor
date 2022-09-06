#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

//#include "../../Shape/Shape.hpp"
//
//
///// Cette Class permet de construire, modifier et détruire des Rectangles.
///// Elle permet aussi de les dessiner sur une fenêtre EZWindow
//class Rectangle : public Shape {
//private:
//
//    /// Longueur du Rectangle
//    uint width{0};
//
//    /// Hauteur du Rectangle
//    uint height{0};
//
//public:
//
//    /// Construit un Rectangle de la couleur, de l'épaisseur, de la longueur et de la hauteur fournies, aux coordonnées x et y fournies
//    /// \param[in] color : const EZColor. La couleur souhaitée
//    /// \param[in] thick : const int. L'épaisseur du Rectangle
//    /// \param[in] x : const coord. La position x de l'ancre
//    /// \param[in] y : const coord. La position y de l'ancre
//    /// \param[in] width : const uint. La longueur du Rectangle
//    /// \param[in] height : const uint. La hauteur du Rectangle
//    /// \return Rectangle
//    /// \warning Ne vérifie pas que la couleur fournie est valide
//    /// \warning Ne vérifie pas que l'épaisseur fournie est supérieure à 0
//    /// \warning Ne vérifie pas que les coordonnées x et y fournies sont valides
//    /// \warning Ne vérifie pas que la hauteur et la largeur fournies sont valides
//    Rectangle( EZColor color, int thick, Coord x, Coord y, uint width, uint height );
//
//
//    /// \warning Le constructeur de copie est supprimé
//    Rectangle( const Rectangle& ) = delete;
//
//
//    /// Construit un Rectangle à partir d'un flux d'entrée
//    /// \param[in,out] is : std::istream&. Le flux d'entrée
//    /// \return Rectangle
//    /// \warning Ne vérifie pas que le flux d'entrée est valide
//    explicit Rectangle( std::istream& );
//
//
//    /// Détruit un Rectangle
//    ~Rectangle() override = default;
//
//
//    /// \warning Impossible d'affecter un Rectangle à un autre Rectangle
//    Rectangle& operator=( const Rectangle& ) = delete;
//
//
//    //***********************************
//    // DECLARATION DES FONCTIONS MEMBRES*
//    //***********************************
//
//    /// Retourne la Longueur du Rectangle
//    /// \return uint
//    inline uint getWidth() const
//    { return width; }
//
//
//    /// Retourne la Hauteur du Rectangle
//    /// \return uint
//    inline uint getHeight() const
//    { return height; }
//
//    //Setter
//    inline void setWidth(uint _width) {width=_width;}
//    inline void setHeight(uint _height) {height=_height;}
//
//
//    void draw( EZWindow& window ) const override;
//
//    void setSize( Size w, Size h, Point* p) override;
//
//    inline double perimeter() const override
//    { return width + width + height + height; }
//
//    void write( std::ostream& os) const override;
//    //***************************************
//    // DECLARATION DES FONCTIONS NON MEMBRES*
//    //***************************************
//};

#include "classic_shape.hpp"

namespace shape_editor {
    class Rectangle
            : public ClassicShape {
    };
}

#endif //RECTANGLE_HPP
