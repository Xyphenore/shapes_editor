#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>
#include <memory>

#include "../../Shape/Shape.hpp"


/// Class Square, elle permet de construire, modifier et supprimer des Square.
/// Elle permet aussi de les dessiner sur une EZWindow
class Square
        : public Shape {

private:
    /// Longueur du Square
    uint length{ 0 };

public:

    /// Construit un Square avec une couleur donnée, une épaisseur, son ancre et sa longueur
    /// \param[in] color : const EZColor. La couleur voulue
    /// \param[in] thick : const int. L'épaisseur du cercle
    /// \param[in] x : const coord. La position x de son ancre
    /// \param[in] y : const coord. La position y de son ancre
    /// \param[in] length : const uint. La longueur du Square
    /// \return Square
    /// \warning Elle ne vérifie pas si l'épaisseur est valide
    /// \warning Elle ne vérifie pas si les coordonnées de l'ancre sont valides
    /// \warning  Elle ne vérifie pas si la longueur fournie est valide
    Square( EZColor color, int thick, Coord x, Coord y, uint length );

    /// \warning Le constructeur de copie est supprimé
    Square( const Square& ) = delete;

    /// Construit un Square à partir d'un flux d'entrée fourni
    /// \param[in,out] is : std::istream&. Le flux d'entrée
    /// \return Square
    /// \warning Elle ne vérifie pas si le flux d'entrée, fourni est valide
    explicit Square( std::istream& );

    /// Détruit le Square courant
    ~Square() override = default;

    //***********************************
    // DECLARATION DES FONCTIONS MEMBRES*
    //***********************************

    /// Retourne la longueur du Square courant
    /// \return uint
    [[nodiscard]] inline uint getLength() const { return length; }


    /// Modifie la longueur du Square courant
    /// \param[in] length : const uint. La nouvelle longueur voulue
    /// \warning Ne vérifie pas si la longueur fournie est valide
    inline void setLength( const uint _length ) { length = _length; }


    /// Dessine le Square courant
    /// \param[in,out] window : EZWindow&. La fenêtre sur laquelle on dessine le Square
    void draw( EZWindow& window ) const override;


    /// Modifie la taille
    /// \param[in] _h : const uint. La nouvelle hauteur
    /// \param[in] _w : const uint. La nouvelle largeur
    /// \param[in] p : Point*. Le point à modifier
    void setSize( Size _w, Size _h, Point* p ) override;


    /// Retourne le périmètre du Square courant
    /// \return double.
    [[nodiscard]] inline double perimeter() const override { return length + length + length + length; }


    /// Écrit dans un flux de sortie, les caractéristiques du Square courant
    /// \param[in,out] os : std::ostream&. Le flux de sortie
    void write( std::ostream& ) const override;


    //***************************************
    // DECLARATION DES FONCTIONS NON MEMBRES*
    //***************************************




};

#endif //SQUARE_HPP
