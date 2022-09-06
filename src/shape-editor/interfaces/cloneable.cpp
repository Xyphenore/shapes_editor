#include <memory>

#include "../../../include/shape-editor/interfaces/cloneable.hpp"

namespace shape_editor {
    Cloneable::~Cloneable() noexcept = default;

    std::unique_ptr<Cloneable> Cloneable::clone() const noexcept {
        return clone_impl();
    }

} // namespace shape_editor
