#include <cstdint>

//#include "include/shape-editor/application.hpp"
#include "libs/ez-draw++/ez-draw++.hpp"

#include "include/shape-editor/ui/window.hpp"

int32_t main() {
//    shape_editor::Application<EZDraw, EZWindow> application;
//
//    application.serve();

    std::cout << "Taille de 2 void* : " << 2 * sizeof( void* ) << std::endl;
    std::cout << "Taille de window : " << sizeof( shape_editor::Window<EZWindow> ) << std::endl;

    return EXIT_SUCCESS;
}
