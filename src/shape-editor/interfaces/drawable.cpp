#include "../../../include/shape-editor/interfaces/drawable.hpp"

namespace shape_editor {
    Drawable::~Drawable() noexcept = default;

    Drawable& Drawable::draw() const noexcept {
        return draw_impl();
    }

} // namespace shape_editor
