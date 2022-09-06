#include <string>

#include "../../../include/shape-editor/interfaces/serializable.hpp"

namespace shape_editor {
    Serializable::~Serializable() noexcept = default;

    std::string Serializable::serialize() const noexcept {
        return serialize_impl();
    }

} // namespace shape_editor
