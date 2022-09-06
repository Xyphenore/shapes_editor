#ifndef SHAPE_EDITOR_WINDOW_HPP
#define SHAPE_EDITOR_WINDOW_HPP

#include <string>

//#include "../object/shapes/ellipse.hpp"
//#include "../object/shapes/rectangle.hpp"
//#include "../object/shapes/triangle.hpp"
//#include "../object/text.hpp"
#include "../tools/dimension.hpp"
#include "../tools/group.hpp"
//#include "../tools/line.hpp"
//#include "../tools/point.hpp"
//#include "../tools/selector.hpp"

namespace shape_editor {
//    class Application;

    class Event;

    class Key;

    class Group;

    class Selector;

    template <class WindowType>
    class Window final {
    public:
        enum class Showing
                : bool {
            YES = true, NO = false,
        };

        enum class Focused
                : bool {
            YES = true, NO = false,
        };

        enum class Color {
            BLACK = 0, WHITE = 1, GREY = 2, RED = 3, GREEN = 4, BLUE = 5, YELLOW = 6, CYAN = 7, MAGENTA = 8,
            // TODO
        };

        struct Thickness {
            static constexpr int32_t MAX_THICKNESS = 127;

            int32_t value;
        };

        Window( int width, int height, std::string name );

        std::string name() const noexcept;

        Window& setName( std::string new_name );

        Dimension dimension() const noexcept;

        Window& setDimension( Dimension new_dimension );

        Showing isShowing() const noexcept;

        Focused isFocused() const noexcept;

        Window& set( Showing new_showing );

        Window& set( Focused new_focused );

        Window& clear() noexcept;

        Color background() const noexcept;

        Window& set( Color new_background );

        Thickness thickness() const noexcept;

        Window& set( Thickness new_thickness );

//        Window& draw( Point point );
//
//        Window& draw( Line line );
//
//        Window& draw( Rectangle rectangle );
//
//        Window& draw( Ellipse ellipse );
//
//        Window& draw( Triangle triangle );
//
//        Window& draw( Text text );

        Window& refresh() const noexcept;

        Window& refreshEvent() const noexcept;

        Window& startTimer( int delay ) const noexcept;

        Window& stopTimer() const noexcept;

        Window& timerNotify() const noexcept;

        const Event& currentEvent() const noexcept;

        Window& closeEvent() const noexcept;

        Window& buttonPress( int mouse_x, int mouse_y, int button ) const noexcept;

        Window& buttonRelease( int mouse_x, int mouse_y, int button ) const noexcept;

        Window& motionNotify( int mouse_x, int mouse_y, int button ) const noexcept;

        Window& keyPress( Key key ) const noexcept;

        Window& keyRelease( Key key ) const noexcept;

        Window& resizeEvent( int width, int height ) const noexcept;

    private:
        void interfaceShowUp();

        /// Application auquel appartient la window
//        Application* application_;

        /// Ensemble de shape dessiné sur la fenêtre
        Group shapes_;

        /// Sélecteur de shape
//        Selector selector_;

        /// Sélectionne le point de resize
//        Point* resize_point = nullptr;

        enum class Mode {
            SELECTION, RESIZE, TODO,
        };

        enum class Held
                : bool {
            YES = true, NO = false,
        };

        enum class Active
                : bool {
            YES = true, NO = false,
        };

        /// Affiche en au de la fenêtre le mode dans le qu'elle se trouve l'utilisateur
        Mode mode_ = Mode::SELECTION;

        static bool needInitialization;

        static bool mouse_shape;
        static bool err;

        Active activeBackGroundImage = Active::YES;

        /// Left ctrl maintenu
        Held holdLCtrl = Held::NO;

        /// Right ctrl maintenu
        Held holdLAlt = Held::NO;


        /// Pointeur sur fonction va qui fera appel à une fonction à chaque clique gauche
        using clickFunction = void ( * )( int mouse_x, int mouse_y, int button );
        clickFunction click_function = &Window::CLICK_selection;

        /// Fichier de font actuellement utilisé
//        std::string actualFontImageFile{"DefaultFont.txt"};

//        void setColorInSelector(Color newColor) const;


        void CLICK_selection( int mouse_x, int mouse_y, int button );

        void CLICK_makeSquare( int mouse_x, int mouse_y, int button );

        void CLICK_makeRectangle( int mouse_x, int mouse_y, int button );

        void CLICK_makeTriangle( int mouse_x, int mouse_y, int button );

        void CLICK_makeCircle( int mouse_x, int mouse_y, int button );

        void CLICK_makeEllipse( int mouse_x, int mouse_y, int button );

        void CLICK_makePolygone( int mouse_x, int mouse_y, int button );

        void CLICK_makeGrid( int mouse_x, int mouse_y, int button );

        void CLICK_makeImage( int mouse_x, int mouse_y, int button );

        void CLICK_makeImageFont( int mouse_x, int mouse_y, int button );

        void CLICK_makeText( int mouse_x, int mouse_y, int button );

        void CLICK_makeStar( int mouse_x, int mouse_y, int button );

        void CLICK_makeAnimeImage( int mouse_x, int mouse_y, int button );

    };

} // namespace shape_editor

#endif // SHAPE_EDITOR_WINDOW_HPP
