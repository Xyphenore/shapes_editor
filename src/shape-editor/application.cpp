#include "../../libs/ez-draw++/ez-draw++.hpp"

#include "../../include/shape-editor/application.hpp"

#include "../../include/shape-editor/object/object_factory.hpp"
#include "../../include/shape-editor/object/shapes/rectangle.hpp"

namespace shape_editor {
    template <>
    Rectangle build<Rectangle>() {
        return Rectangle();
    }

    template <>
    void Application<EZDraw, EZWindow>::initialise() noexcept {
        application_.setAutoQuit( false );

        auto window = Window<EZWindow>( 320, 480, "FirstWindow" );
        auto test = std::reference_wrapper<Window<EZWindow>>( window );

        windows_.push_back( Window<EZWindow>( 320, 480, "FirstWindow" ) );

        ObjectFactory::register_builder( "Rectangle", build<Rectangle>() );
        ObjectFactory::register_builder( "Square", build<Square>() );
        ObjectFactory::register_builder( "Circle", build<Circle>() );
        ObjectFactory::register_builder( "Ellipse", build<Ellipse>() );
        ObjectFactory::register_builder( "Triangle", build<Triangle>() );
        ObjectFactory::register_builder( "Polygone", build<Polygone>() );
        ObjectFactory::register_builder( "Grid", build<Grid>() );
        ObjectFactory::register_builder( "Image", build<Image>() );
        ObjectFactory::register_builder( "Text", build<Text>() );
        ObjectFactory::register_builder( "FontImage", build<FontImage>() );
        ObjectFactory::register_builder( "AnimeImage", build<AnimeImage>() );
    }

    template <>
    Application<EZDraw, EZWindow>::Application() {
        initialise();
    }

    template <>
    Application<EZDraw, EZWindow>& Application<EZDraw, EZWindow>::serve() {
        application_.mainLoop();
    }

    template <>
    Application<EZDraw, EZWindow>& Application<EZDraw, EZWindow>::addWindow( EZWindow window ) {
        windows_.push_back( std::move( window ) );
    }

} // namespace shape_editor
