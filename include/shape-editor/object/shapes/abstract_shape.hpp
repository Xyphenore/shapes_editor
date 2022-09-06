#ifndef SHAPE_EDITOR_ABSTRACT_SHAPE_HPP
#define SHAPE_EDITOR_ABSTRACT_SHAPE_HPP

#include <vector>

#include "shape.hpp"
#include "../../tools/point.hpp"

#include "../../../../libs/ez-draw++/ez-draw++.hpp"

// TODO utiliser std::hypot pour calculer la distance entre deux points
// TODO Faire une surcharge de std::distance avec deux points ainsi que position
// TODO std::pow et std::sqrt, std::abs
// std::midpoint, pgm, lgm
// TODO Utiliser des id pour les points, cela permet d'utiliser les memes points entre différentes shapes

namespace shape_editor::shapes {
    class AbstractShape
            : public Shape {
    public:


    protected:
        AbstractShape( EZColor color, Thickness thick, Position position );

        AbstractShape() noexcept = default;

        AbstractShape( const AbstractShape& ) = default;

        AbstractShape( AbstractShape&& ) = default;

        AbstractShape& operator=( const AbstractShape& ) = default;

        AbstractShape& operator=( AbstractShape&& ) = default;

    private:
        EZColor color_ = ez_black;

        Thickness thick_ = 1;

        bool selected_ = false;

        bool filled_ = false;

        std::vector<std::reference_wrapper<Point>> vertices_;
    };
}

#endif // SHAPE_EDITOR_ABSTRACT_SHAPE_HPP
