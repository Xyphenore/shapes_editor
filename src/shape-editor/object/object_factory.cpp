#include <iostream>
#include <memory>
#include <unordered_map>

#include "../../../include/shape-editor/object/object.hpp"
#include "../../../include/shape-editor/object/object_factory.hpp"

namespace shape_editor {
    std::unique_ptr<Object> ObjectFactory::load( std::istream& input ) {
        // TODO: Implement
    }

    std::ostream& ObjectFactory::save( const Object& object, std::ostream& output ) {
        output << object.serialize();
        return output;
    }

    void ObjectFactory::register_builder( std::string class_name, ObjectFactory::Builder builder ) {
        if ( ObjectFactory::builders_.contains( class_name ) ) {
            throw std::runtime_error( "Already registered" );
        }

        ObjectFactory::builders_.try_emplace( std::move( class_name ), builder );
    }

} // namespace shape_editor
