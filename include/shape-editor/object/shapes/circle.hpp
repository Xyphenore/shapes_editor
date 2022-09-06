#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <numbers>

constexpr auto pi = std::numbers::pi_v<long double>;

constexpr double PI = 3.141592653589793238462643383279;

#include "../../Shape/Shape.hpp"

class Circle
        : public Shape {
private:
    /// Le rayon du Circle
    Size radius{ 0 };

public:
    /// \warning Impossible de créer un Circle sans attributs fournis
    constexpr Circle() = delete;

    /// Construit un Circle de la couleur et de l'épaisseur données, aux coordonnées x,y fournis
    /// \param[in] color : \ref EZColor . La couleur souhaitée
    /// \param[in] thick : \ref Thick . L'épaisseur souhaitée
    /// \param[in] x : \ref Coord . La position \ref x de l'ancre
    /// \param[in] y : \ref Coord . La position \ref y de l'ancre
    /// \param[in] rad : \ref Size . Le rayon de Circle
    /// \pre 0 <= x <= Width de la fenêtre d'affichage
    /// \pre 0 <= y <= Height de la fenêtre d'affichage
    /// \pre 0 < rad <= Height de la fenêtre d'affichage
    /// \pre 0 < thick <= // TODO determiner le max
    /// \post Un \ref Circle pouvant être afficher entièrement dans la fenêtre
    /// \post \ref getX() == x
    /// \post \ref getY() == y
    /// \post \ref getColor() == color
    /// \post \ref Shape::getThick() == thick
    /// \post \ref getRadius() == rad
    /// \return Circle
    /// \warning Ne vérifie pas si les paramètres fournis respectent les préconditions
    Circle( EZColor color, Thick thick, Coord x, Coord y, Size radius );


    /// \warning Impossible de créer un Circle à partir d'un autre
    constexpr Circle( const Circle& ) = delete;


    /// Construit un Circle à partir d'un flux d'entrée
    /// \param[in,out] is : std::istream& . Le flux d'entrée
    /// \pre 0 <= x <= Width de la fenêtre d'affichage
    /// \pre 0 <= y <= Height de la fenêtre d'affichage
    /// \pre 0 < rad <= Height de la fenêtre d'affichage
    /// \pre 0 < thick <= // TODO determiner le max
    /// \post Un \ref Circle pouvant être afficher entièrement dans la fenêtre
    /// \post \ref getX() == x
    /// \post \ref getY() == y
    /// \post \ref getColor() == color
    /// \post \ref Shape::getThick() == thick
    /// \post \ref getRadius() == rad
    /// \return Circle
    /// \warning Ne vérifie pas si les données du flux entrant permettent de construire un Circle correctement
    explicit Circle( std::istream& );


    /// Détruit un \ref Circle
    ~Circle() noexcept override = default;

    //***********************************
    // DECLARATION DES FONCTIONS MEMBRES*
    //***********************************

    /// Retourne le rayon du Circle
    /// \return \ref radius : \ref Size
    inline Size getRadius() const { return radius; }

    /// Modifie le rayon sur Circle courant par le rayon fourni en pramètre
    /// \param[in] rad : \ref Size . Le nouveau rayon
    /// \pre 0 < rad <= Height de la fenêtre d'affichage
    /// \post \ref getRadius() == rad
    /// \warning Ne vérifie pas si le rayon fournis respecte la précondition
    inline void setRadius( const Size rad ) { radius = rad; }


    /// Permet de dessiner un Circle sur la fenêtre fournie en paramètre
    /// \param[in,out] window : \ref EZWindow . La fenêtre sur laquelle on veut dessiner
    void draw( EZWindow& window ) const override;


    /// Retourne la périmètre du Circle courant
    /// \return perimeter : double
    inline double perimeter() const override { return 2 * G_PI * radius; }


    /// Permet de redimensionner un Circle, par la largeur et la hauteur fournies
    /// \param[in] w : \ref Size . La largeur de redimenssion
    /// \param[in] h : \ref Size . La hauteur de redimenssion
    /// \param[in,out] p_resize : \ref Point* . Le \ref Point de redimenssion
    void setSize( Size w, Size h, Point* p_resize ) override;


    /// Permet d'écrire le Circle courant sur un flux sortant
    /// \param[in,out] os : std::ostream& . Le flux de sortie
    void write( std::ostream& os ) const override;

};


#endif //CIRCLE_HPP
