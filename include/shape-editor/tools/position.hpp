#ifndef SHAPE_EDITOR_POSITION_HPP
#define SHAPE_EDITOR_POSITION_HPP

#include <cstdint>
#include <string>

namespace shape_editor {
    /**
 * The position of a point.
 *
 * @since 1.0
 * @version 1.0
 * @author Axel DAVID
 *
 * @see shape_editor::Point
 */
    class Position final {
    public:
        static const std::string CLASS;

        using Coordinate = int32_t;

        /**
         * Create a position with x and y.
         *
         * @param[in] x
         * @param[in] y
         *
         * @throws TODO
         *
         * @exceptsafe STRONG
         *
         * @since 1.0
         * @version 1.0
         */
        explicit Position( Coordinate x, Coordinate y );

        /**
         * @return Return the coordinate x of the position.
         *
         * @exceptsafe NO-THROWS.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the getter to have the coordinate.")]]
        Coordinate x() const noexcept;

        /**
         * @return Return the coordinate y of the position.
         *
         * @exceptsafe NO-THROWS.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the getter to have the coordinate.")]]
        Coordinate y() const noexcept;

        /**
         * Set the coordinate x.
         *
         * @param[in] x
         *
         * @exceptsafe STRONG.
         *
         * @return Return a reference of the position.
         *
         * @since 1.0
         * @version 1.0
         */
        Position& setX( Coordinate x );

        /**
         * Set the coordinate y.
         *
         * @param[in] y
         *
         * @exceptsafe STRONG.
         *
         * @return Return a reference of the position.
         *
         * @since 1.0
         * @version 1.0
         */
        Position& setY( Coordinate y );

        bool operator<=>( const Position& position ) const noexcept = default;

    private:
        Coordinate x_ = 0;
        Coordinate y_ = 0;
    };
} // namespace shape_editor

#endif // SHAPE_EDITOR_POSITION_HPP
