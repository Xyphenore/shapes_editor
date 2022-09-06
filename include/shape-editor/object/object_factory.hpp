#ifndef SHAPE_EDITOR_OBJECT_FACTORY_HPP
#define SHAPE_EDITOR_OBJECT_FACTORY_HPP

#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "object.hpp"
#include "../tools/string_hasher.hpp"

namespace shape_editor {
    /**
     * Instantiate a builder for shape_editor::Object.
     *
     * @tparam Object_Class shape_editor::Object.
     *
     * @throws TODO
     *
     * @exceptsafe STRONG.
     *
     * @version 1.0
     * @since 1.0
     * @author Axel DAVID
     *
     * @return Return an owner pointer to shape_editor::Object.
     */
    template <class Object_Class, typename... Types>
    Object_Class build( Types... args );

    /**
     * Factory to load and save shape_editor::Object.
     *
     * @version 1.0
     * @since 1.0
     * @author Axel DAVID
     *
     * @see shape_editor::Object
     */
    class ObjectFactory final {
    public:
        /**
         * An alias for a functor of an Object Builder.
         *
         * @version 1.0
         * @since 1.0
         */
        using Builder = std::function<std::unique_ptr<Object>()>;

        /**
         * Create a new shape_editor::Object from the input stream.
         *
         * @param [in]input The input stream, which containing the data to create a new shape_editor::Object.
         *
         * @throws TODO
         *
         * @exceptsafe STRONG.
         *
         * @version 1.0
         * @since 1.0
         *
         * @return Return an owner pointer to the new shape_editor::Object.
         */
        static std::unique_ptr<Object> load( std::istream& input );

        /**
         * Save the shape_editor::Object in the output stream.
         *
         * @param [in]object The shape_editor::Object to save.
         * @param [in/out]output The output stream.
         *
         * @throws TODO
         *
         * @exceptsafe STRONG.
         *
         * @version 1.0
         * @since 1.0
         *
         * @return Return the reference to the output stream.
         */
        static std::ostream& save( const Object& object, std::ostream& output );

        /**
         * Register an object builder.
         *
         * @param [in]class_name The class name.
         * @param [in]builder The functor of the object builder.
         *
         * @throws TODO
         * @throws TODO
         *
         * @exceptsafe STRONG.
         *
         * @version 1.0
         * @since 1.0
         */
        static void register_builder( std::string class_name, Builder builder );

        // ----------------------------------------------------------------

        ObjectFactory() = delete;

        ObjectFactory( const ObjectFactory& ) = delete;

        ObjectFactory( ObjectFactory&& ) = delete;

        ObjectFactory& operator=( const ObjectFactory& ) = delete;

        ObjectFactory& operator=( ObjectFactory&& ) = delete;

        ~ObjectFactory() = delete;

    private:
        static std::unordered_map<std::string, Builder, tools::StringHasher, std::equal_to<>> builders_;
    };

} // namespace shape_editor

#endif // SHAPE_EDITOR_OBJECT_FACTORY_HPP
