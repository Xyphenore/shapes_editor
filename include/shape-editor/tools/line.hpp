#ifndef SHAPE_EDITOR_LINE_HPP
#define SHAPE_EDITOR_LINE_HPP

#include <cstdint>
#include <string>

#include "position.hpp"
#include "point.hpp"

namespace shape_editor {
    /**
     * A line of a shape.
     *
     * @since 1.0
     * @version 1.0
     * @author Axel DAVID
     */
    class Line final {
    public:
        static const std::string CLASS;

        using Size_t = int8_t;

        /**
         * Size of line.
         */
        static constexpr Size_t SIZE = 6;

        //*******************************************************************
        //  Constructors/Destructor                                           *
        //*******************************************************************

        /**
         * Create a line between two points.
         *
         * @param [in]p1, p2 End points.
         *
         * @throws TODO
         *
         * @exceptsafe STRONG.
         *
         * @since 1.0
         * @version 1.0
         */
        explicit Line( Point p1, Point p2 );

        //*******************************************************************
        //  Methods                                                           *
        //*******************************************************************

        /**
         * @return Return the first point of the line.
         *
         * @exceptsafe NO-THROWS.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the getter to get the first point of the line.")]]
        Point p1() const noexcept;

        /**
         * @return Return the second point of the line.
         *
         * @exceptsafe NO-THROWS.
         *
         * @since 1.0
         * @version 1.0
         */
        [[nodiscard("You call the getter to get the second point of the line.")]]
        Point p2() const noexcept;

        /**
         * Set the first point of the line.
         *
         * @param[in] p1 First point of the line.
         *
         * @throws TODO
         *
         * @exceptsafe STRONG.
         *
         * @return Return a reference to the line.
         */
        Line& setP1( Point p1 );

        /**
         * Set the second point of the line.
         *
         * @param[in] p2 Second point of the line.
         *
         * @throws TODO
         *
         * @exceptsafe STRONG.
         *
         * @return Return a reference to the line.
         */
        Line& setP2( Point p2 );

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
        Line& moveTo( Position position );

        // TODO A mettre en place
        Line& moveOf( Position position );

        // TODO Reflechir a comment définir la méthod isOver en fonction de l'utilisation
        bool isOver( Position mouse ) const noexcept;

        // TODO Reflechir a comment définir la méthod isOver en fonction de l'utilisation
        Line& draw( const Window& window ) const;

        bool operator<=>( const Line& line ) const noexcept = default;

    private:
        Point p1_;

        Point p2_;
    };

} // namespace shape_editor

#endif // SHAPE_EDITOR_LINE_HPP
