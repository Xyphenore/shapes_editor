#include <string>

#include "../../../include/shape-editor/tools/position.hpp"

namespace shape_editor {
    const std::string Position::CLASS = "Position";

    using Coordinate = Position::Coordinate;

    Position::Position( const Coordinate x, const Coordinate y )
            : x_( x ), y_( y ) {}

    Coordinate Position::x() const noexcept {
        return x_;
    }

    Coordinate Position::y() const noexcept {
        return y_;
    }

    Position& Position::setX( const Coordinate x ) {
        x_ = x;

        return *this;
    }

    Position& Position::setY( const Coordinate y ) {
        y_ = y;

        return *this;
    }

} // namespace shape_editor
