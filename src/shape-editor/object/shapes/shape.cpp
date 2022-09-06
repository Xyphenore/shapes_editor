#include <optional>
#include <string>

#include "../../../../libs/ez-draw++/ez-draw++.hpp"

#include "../../../include/shape-editor/shapes/shape.hpp"

namespace shape_editor::shapes {
    const std::string Shape::CLASS = "Shape";

    using OptionalPoint = Shape::OptionalPoint;
    using OptionalPointRef = Shape::OptionalPointRef;

    using Perimeter = Shape::Perimeter;
    using Area = Shape::Area;

    Color Shape::color() const noexcept {
        return color_impl();
    }

    Thickness Shape::thickness() const noexcept {
        return thickness_impl();
    }

    Fill Shape::filled() const noexcept {
        return filled_impl();
    }

    Select Shape::selected() const noexcept {
        return selected_impl();
    }

    Shape& Shape::set( const Color color ) {
        return set_impl( color );
    }

    Shape& Shape::set( const Thickness thickness ) {
        return set_impl( thickness );
    }

    Shape& Shape::set( const Select select ) {
        return set_impl( select );
    }

    Shape& Shape::set( const Fill fill ) {
        return set_impl( fill );
    }

    bool Shape::isOver( const Position mouse ) const noexcept {
        return isOver_impl( mouse );
    }

    Shape& Shape::moveTo( const Position position ) {
        return moveTo_impl( position );
    }

    Shape& Shape::moveOf( const Coefficient coefficient ) {
        return moveOf_impl( coefficient );
    }

    Perimeter Shape::perimeter() const noexcept {
        return perimeter_impl();
    }

    Area Shape::area() const noexcept {
        return area_impl();
    }

    Shape& Shape::draw( const Window& window ) const {
        return draw_impl( window );
    }


    OptionalPoint Shape::isOverVertex( const Position mouse ) const {
        return isOverVertex_impl( mouse );
    }

    OptionalPointRef Shape::isOverVertex( const Position mouse ) {
        return isOverVertex_impl( mouse );
    }

    Shape& Shape::add( const Point point ) {
        return add_impl( point );
    }

    size_t Shape::numberOfVertices() const noexcept {
        return numberOfVertices_impl();
    }

    Point Shape::vertex( const int64_t i ) const {
        return vertex_impl( i );
    }

    Point& Shape::vertex( const int64_t i ) {
        return vertex_impl( i );
    }

    Point Shape::anchor() const noexcept {
        return anchor_impl();
    }

    Point& Shape::anchor() noexcept {
        return anchor_impl();
    }
} // namespace shape_editor::shapes
