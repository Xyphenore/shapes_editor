#ifndef SHAPE_EDITOR_DIMENSION_HPP
#define SHAPE_EDITOR_DIMENSION_HPP

#include <cstdint>
#include <string>

namespace shape_editor {
    /**
     * The dimension of an object.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     *
     * @see shape_editor::Window
     */
    class Dimension final {
    public:
        static const std::string CLASS;

        using Width = int32_t;
        using Height = int32_t;

        /**
         * Create a dimension with width and height.
         *
         * @param[in] width
         * @param[in] height
         *
         * @throws TODO
         *
         * @exceptsafe STRONG.
         *
         * @since 1.0
         * @version 1.0
         */
        explicit Dimension( Width x, Height y );

        /**
         * @return Return the width of the dimension.
         *
         * @exceptsafe NO-THROWS.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the getter to have the width.")]]
        Width width() const noexcept;

        /**
         * @return Return the height of the dimension.
         *
         * @exceptsafe NO-THROWS.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the getter to have the height.")]]
        Height height() const noexcept;

        /**
         * Set the width.
         *
         * @param[in] new_width
         *
         * @exceptsafe STRONG.
         *
         * @return Return a reference of the dimension.
         *
         * @since 1.0
         * @version 1.0
         */
        Dimension& setWidth( Width new_width );

        /**
         * Set the height.
         *
         * @param[in] new_height
         *
         * @exceptsafe STRONG.
         *
         * @return Return a reference of the dimension.
         *
         * @since 1.0
         * @version 1.0
         */
        Dimension& setheight( Height new_height );

        bool operator<=>( const Dimension& position ) const noexcept = default;

    private:
        Width width_ = 0;
        Height height_ = 0;
    };

} // namespace shape_editor

#endif // SHAPE_EDITOR_DIMENSION_HPP
