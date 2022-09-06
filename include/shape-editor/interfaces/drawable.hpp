#ifndef SHAPE_EDITOR_DRAWABLE_HPP
#define SHAPE_EDITOR_DRAWABLE_HPP

namespace shape_editor {
    /**
     * Interface for a drawable object.
     *
     * @version 1.0
     * @since 1.0
     * @author Axel DAVID
     *
     * @see shape_editor::Object
     */
    class Drawable {
    public:
        virtual ~Drawable() noexcept = 0;

        /**
         * Draw the object on the window.
         *
         * @exceptsafe NO-THROWS.
         *
         * @version 1.0
         * @since 1.0
         *
         * @return Return the reference of the object.
         */
        Drawable& draw() const noexcept;

    private:
        /**
         * Implementation of the draw method.
         *
         * @exceptsafe NO-THROWS.
         *
         * @version 1.0
         * @since 1.0
         *
         * @return Return the reference of the object.
         */
        virtual Drawable& draw_impl() const noexcept = 0;
    };

} // namespace shape_editor

#endif // SHAPE_EDITOR_DRAWABLE_HPP
