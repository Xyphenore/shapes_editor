#ifndef SHAPE_EDITOR_OBJECT_HPP
#define SHAPE_EDITOR_OBJECT_HPP

#include "../interfaces/drawable.hpp"
#include "../interfaces/cloneable.hpp"
#include "../interfaces/serializable.hpp"

namespace shape_editor {
    /**
     * An aggregate of common interfaces.
     *
     * @version 1.0
     * @since 1.0
     * @author Axel DAVID
     *
     * @see shape_editor::Drawable
     * @see shape_editor::Serializable
     * @see shape_editor::Cloneable
     */
    class Object
            : public Drawable, public Cloneable, public Serializable {
    };

} // namespace shape_editor

#endif // SHAPE_EDITOR_OBJECT_HPP
