#ifndef SELECTOR_HPP
#define SELECTOR_HPP

#include <iostream>
#include <vector>

#include "../Point/Point.hpp"
#include "../Shape/Shape.hpp"

/// Classe selecteur, elle permet d'avoire une liste de Shapes séléctionné et éfectuer des traitement dessus.
class Selector {
private:
    /// Liste de tout les shapes Selectionnée
    std::vector<Shape*> selectedArray;


public:
    Selector();

    Selector( const Selector& src );

    ~Selector();

    /// Retourne la liste
    /// \return std::vecor<Shape *>
    inline std::vector<Shape*> getArray() const { return selectedArray; }

    /// Permet d'ajouter une forme dans la liste et d'effectuer des traitements (Changement de couleur, d'éppaiseur ,...)
    /// L'on peu considérée cette commande comme une sélection d'une instance de Shape
    /// \note Si la shape sélectionnée fait déja par de la liste de selectionnions alors elle échange de place avec le 1ere element de la sélection
    /// \param [in] aRandomShape : Une shape à selectionner
    void add( Shape* );

    /// Vide la liste des sélections
    ///\warning Cette fonction vite **toute** la liste de sélection !
    void clear();

    /// Redessine en *rouge* les valeurs selectionnés.
    /// \param [in] Window : La fenêtre où les traitements seront appliqués
    void paintSelected( EZWindow Win );

    ///Vide la liste des sélections **Sauf** le 1ere élement
    void clearExpecptfirst();

    bool isSelected( const Shape* ) const;

    void setFirstPlace( Shape* p1 );
};

#endif //SELECTOR_HPP
