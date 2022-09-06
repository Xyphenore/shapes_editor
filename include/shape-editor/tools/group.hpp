#ifndef GROUP_HPP
#define GROUP_HPP

#include <string>
#include <string_view>
#include <vector>
#include <initializer_list>

#include "../object/object.hpp"
#include "position.hpp"
#include "../ui/window.hpp"

namespace shape_editor {
    class Group final {
    public:
        using iterator = std::vector<std::reference_wrapper<Object>>::iterator;
        using const_iterator = std::vector<std::reference_wrapper<Object>>::const_iterator;

        Group( size_t count );

        Group& add( Object& object );

        Group& add( std::initializer_list<Object&> objects );

        Group& add( Object&& object );

        Group& erase( const Object& object );

        Group& erase( std::initializer_list<const Object&> objects );

        const Object& object( size_t i ) const;

        Object& object( size_t i );

        Object* isOver( Position mouse ) const;

//        Group& draw( const Window& window ) const;

        std::string save() const;

        static Group& load( std::string_view input );

        size_t size() const noexcept;

        const Object& at( size_t i ) const;

        Object& at( size_t i );

        bool empty() const noexcept;

        void reserve( size_t size );

        size_t capacity() const noexcept;

        void clear();

        void swap( Group& other ) noexcept;

        iterator begin() noexcept;

        const_iterator cbegin() const noexcept;

        iterator end() noexcept;

        const_iterator cend() const noexcept;

        iterator rbegin() noexcept;

        const_iterator crbegin() const noexcept;

        iterator rend() noexcept;

        const_iterator crend() const noexcept;

        bool operator<=>( const Group& other ) const noexcept = default;

    private:


        std::vector<std::reference_wrapper<Object>> objects_;
    };
}

#endif //GROUP_HPP
