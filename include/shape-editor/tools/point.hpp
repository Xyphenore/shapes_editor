#ifndef SHAPE_EDITOR_POINT_HPP
#define SHAPE_EDITOR_POINT_HPP

#include <cstdint>
#include <string>

#include "position.hpp"

namespace shape_editor {
    /**
     * A point of a shape.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     */
    class Point final {
    public:
        static const std::string CLASS;

        using Size_t = int8_t;
        using Thick_t = int32_t;

        /**
         * Size of points.
         */
        static constexpr Size_t SIZE = 6;

        /**
         * Thickness of anchor line.
         */
        static constexpr Thick_t THICK_ANCHOR = SIZE;

        //*******************************************************************
        //  Constructors/Destructor                                           *
        //*******************************************************************

        /**
         * Create a point to the given position.
         *
         * @param [in]position The position of the point.
         *
         * @throws TODO
         *
         * @exceptsafe STRONG.
         *
         * @since 1.0
         * @version 1.0
         */
        explicit Point( Position position );

        //*******************************************************************
        //  Methods                                                           *
        //*******************************************************************

        /**
         * @return Return the position of the point.
         *
         * @exceptsafe NO-THROWS.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the getter to get the position of the point.")]]
        Position position() const noexcept;

        /**
         * Set the position of the point.
         *
         * @param[in] position
         *
         * @throws TODO
         *
         * @exceptsafe STRONG.
         *
         * @return Return a reference to the point.
         */
        Point& moveTo( Position position );

        // TODO A mettre en place
        Point& moveOf( Position position );

        // TODO Reflechir a comment définir la méthod isOver en fonction de l'utilisation
        bool isOver( Position mouse ) const noexcept;

        // TODO Reflechir a comment définir la méthod isOver en fonction de l'utilisation
        Point& draw( const Window& window ) const;

        bool operator<=>( const Point& point ) const noexcept = default;

    private:
        Position pos_;
    };
} // namespace shape_editor

#endif // SHAPE_EDITOR_POINT_HPP
