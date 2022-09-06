#include <ostream>
#include <string>

#include "../../../include/shape-editor/object/object.hpp"

namespace shape_editor {
    Object::~Object() noexcept = default;

    Object& Object::draw() const noexcept {
        return draw_impl();
    }

    void Object::save( std::ostream& output ) const noexcept {
        return save_impl( output );
    }

    std::string Object::save() const noexcept {
        return save_impl();
    }

} // namespace shape_editor
