#ifndef SHAPE_EDITOR_CLONABLE_HPP
#define SHAPE_EDITOR_CLONABLE_HPP

#include <memory>

namespace shape_editor {
    /**
     * Interface for a clonable object.
     *
     * @version 1.0
     * @since 1.0
     * @author Axel DAVID
     *
     * @see shape_editor::Object
     */
    class Cloneable {
    public:
        virtual ~Cloneable() noexcept = 0;

        /**
         * Clone the object.
         *
         * @exceptsafe NO-THROWS.
         *
         * @version 1.0
         * @since 1.0
         *
         * @return Return an owner pointer of the object.
         */
        [[nodiscard("You call the function to clone the object.")]]
        std::unique_ptr<Cloneable> clone() const noexcept;

    private:
        /**
         * Implementation of the clone method.
         *
         * @exceptsafe NO-THROWS.
         *
         * @version 1.0
         * @since 1.0
         *
         * @return Return an owner pointer of the object.
         */
        [[nodiscard("You call the function to clone the object.")]]
        virtual std::unique_ptr<Cloneable> clone_impl() const noexcept = 0;
    };

} // namespace shape_editor

#endif // SHAPE_EDITOR_CLONABLE_HPP
