#ifndef SHAPE_EDITOR_SERIALIZABLE_HPP
#define SHAPE_EDITOR_SERIALIZABLE_HPP

#include <string>

namespace shape_editor {
    /**
     * Interface for a serializable object.
     *
     * @version 1.0
     * @since 1.0
     * @author Axel DAVID
     *
     * @see shape_editor::Object
     */
    class Serializable {
    public:
        virtual ~Serializable() noexcept = 0;

        /**
         * Serialize the object.
         *
         * @exceptsafe NO-THROWS.
         *
         * @version 1.0
         * @since 1.0
         *
         * @return Return the std::string representation.
         */
        [[nodiscard("You call the function to serialize the object.")]]
        std::string serialize() const noexcept;

    private:
        /**
         * Implementation of the serialize method.
         *
         * @exceptsafe NO-THROWS.
         *
         * @version 1.0
         * @since 1.0
         *
         * @return Return the std::string representation.
         */
        [[nodiscard("You call the function to serialize the object.")]]
        virtual std::string serialize_impl() const noexcept = 0;
    };

} // namespace shape_editor

#endif // SHAPE_EDITOR_SERIALIZABLE_HPP
