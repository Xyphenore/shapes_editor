#include <string>

#include "../../../include/shape-editor/tools/position.hpp"
#include "../../../include/shape-editor/tools/point.hpp"

namespace shape_editor {
    const std::string Point::CLASS = "Point";

    Point::Point( const Position position )
            : pos_{ position } {}

    Position Point::position() const noexcept {
        return pos_;
    }

    Point& Point::moveTo( Position position ) {
        pos_ = position;

        return *this;
    }

} // namespace shape_editor
