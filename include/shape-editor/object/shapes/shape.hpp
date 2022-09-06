#ifndef SHAPE_EDITOR_SHAPE_HPP
#define SHAPE_EDITOR_SHAPE_HPP

#include <cstdint>
#include <optional>
#include <string>

#include "../../tools/point.hpp"
#include "../../tools/coefficient.hpp"
#include "../object.hpp"

#include "../../../../libs/ez-draw++/ez-draw++.hpp"

// TODO Documenter

namespace shape_editor::shapes {
    enum class Color {
        BLACK = 0, WHITE = 1, GREY = 2, RED = 3, GREEN = 4, BLUE = 5, YELLOW = 6, CYAN = 7, MAGENTA = 8,
        // TODO
    };

    struct Thickness {
        static constexpr int32_t MAX_THICKNESS = 127;

        int32_t value;
    };

    enum class Fill
            : bool {
        YES = true, NO = false,
    };

    enum class Select
            : bool {
        YES = true, NO = false,
    };

    class Shape
            : public Object {
    public:
        static const std::string CLASS;

        using OptionalPoint = std::optional<Point>;
        using OptionalPointRef = std::optional<Point&>;

        using Perimeter = double;
        using Area = double;

        virtual ~Shape() noexcept = 0;

        [[nodiscard("You call the getter to have the color of the shape.")]]
        Color color() const noexcept;

        [[nodiscard("You call the getter to have the thickness of the shape.")]]
        Thickness thickness() const noexcept;

        [[nodiscard("You call the getter to know if the shape is filled.")]]
        Fill filled() const noexcept;

        [[nodiscard("You call the getter to know if the shape is selected.")]]
        Select selected() const noexcept;

        [[nodiscard("You call the getter to have the perimeter of the shape.")]]
        Perimeter perimeter() const noexcept;

        [[nodiscard("You call the getter to have the area of the shape.")]]
        Area area() const noexcept;

        Shape& set( Color color );

        Shape& set( Thickness thickness );

        Shape& set( Fill fill );

        Shape& set( Select select );

        [[nodiscard("You call the method to know if the mouse is over the shape.")]]
        bool isOver( Position mouse ) const noexcept;

//        Shape& setDimension( Dimension dimension );

        Shape& moveTo( Position position );

        Shape& moveOf( Coefficient coefficient );

        Shape& draw( const Window& window ) const;

    protected:
        [[nodiscard("You call the method to get the vertex of the shape is above the mouse.")]]
        OptionalPoint isOverVertex( Position mouse ) const;

        [[nodiscard("You call the method to get the vertex of the shape is above the mouse.")]]
        OptionalPointRef isOverVertex( Position mouse );

        [[nodiscard("You call the getter to have a copy of the anchor.")]]
        Point anchor() const noexcept;

        [[nodiscard("You call the getter to have a reference to the anchor.")]]
        Point& anchor() noexcept;

        Shape& add( Point point );

        [[nodiscard("You call the getter to have the number of vertices of the shape.")]]
        size_t numberOfVertices() const noexcept;

        [[nodiscard("You call the getter to have a copy of the i vertex of the shape.")]]
        Point vertex( int64_t i ) const;

        [[nodiscard("You call the getter to have a reference of the i vertex of the shape.")]]
        Point& vertex( int64_t i );

    private:
        [[nodiscard("You call the getter to have the color of the shape.")]]
        virtual Color color_impl() const noexcept = 0;

        [[nodiscard("You call the getter to have the thickness of the shape.")]]
        virtual Thickness thickness_impl() const noexcept = 0;

        [[nodiscard("You call the getter to know if the shape is filled.")]]
        virtual Fill filled_impl() const noexcept = 0;

        [[nodiscard("You call the getter to know if the shape is selected.")]]
        virtual Select selected_impl() const noexcept = 0;

        virtual Shape& set_impl( Thickness thick ) = 0;

        virtual Shape& set_impl( Color color ) = 0;

        virtual Shape& set_impl( Fill fill ) = 0;

        virtual Shape& set_impl( Select selected ) = 0;

        [[nodiscard("You call the method to know if the mouse is over the shape.")]]
        virtual bool isOver_impl( Position mouse ) const noexcept = 0;

        virtual Shape& moveTo_impl( Position position ) = 0;

        virtual Shape& moveOf_impl( Coefficient coefficient ) = 0;

        [[nodiscard("You call the getter to have the perimeter of the shape.")]]
        virtual Perimeter perimeter_impl() const noexcept = 0;

        [[nodiscard("You call the getter to have the area of the shape.")]]
        virtual Area area_impl() const noexcept = 0;

        virtual Shape& draw_impl( const Window& window ) const = 0;


        [[nodiscard("You call the getter to have a copy of the anchor.")]]
        virtual Point anchor_impl() const noexcept = 0;

        [[nodiscard("You call the getter to have a reference to the anchor.")]]
        virtual Point& anchor_impl() noexcept = 0;

        virtual Shape& add_impl( Point point ) = 0;

        [[nodiscard("You call the getter to have the number of vertices of the shape.")]]
        virtual size_t numberOfVertices_impl() const noexcept = 0;

        [[nodiscard("You call the method to get the vertex of the shape is above the mouse.")]]
        virtual OptionalPoint isOverVertex_impl( Position mouse ) const = 0;

        [[nodiscard("You call the method to get the vertex of the shape is above the mouse.")]]
        virtual OptionalPointRef isOverVertex_impl( Position mouse ) = 0;

        [[nodiscard("You call the getter to have a copy of the i vertex of the shape.")]]
        virtual Point vertex_impl( int64_t i ) const = 0;

        [[nodiscard("You call the getter to have a reference of the i vertex of the shape.")]]
        virtual Point& vertex_impl( int64_t i ) = 0;
    };
} // namespace shape_editor::shapes

namespace shape_editor::shapes {
    inline Shape::~Shape() noexcept = default;
}

#endif // SHAPE_EDITOR_SHAPE_HPP
