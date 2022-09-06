#ifndef SHAPE_EDITOR_APPLICATION_HPP
#define SHAPE_EDITOR_APPLICATION_HPP

#include <vector>

#include "ui/window.hpp"

namespace shape_editor {
    template <class WindowType>
    class Window;

    /**
     * An application with windows.
     *
     * @tparam ApplicationType A class, which will be encapsulated.
     *
     * @version 1.0
     * @since 1.0
     * @author Axel DAVID
     */
    template <class ApplicationType, class WindowType>
    class Application final {
    public:
        Application();

        /**
         * Run the main loop.
         *
         * @throw TODO
         *
         * @exceptsafe BASIC.
         *
         * @version 1.0
         * @since 1.0
         *
         * @return Return a reference to the Application.
         */
        Application& serve();

        Application& addWindow( WindowType window );

    private:
        std::vector<std::reference_wrapper<Window<WindowType>>> windows_;

        ApplicationType application_;

        /**
         * Initialize the application.
         *
         * @exceptsafe NO-THOWS.
         *
         * @version 1.0
         * @since 1.0
         */
        void initialise() noexcept;
    };

} // namespace shape_editor

#endif // SHAPE_EDITOR_APPLICATION_HPP
