#ifndef SHAPE_EDITOR_STRING_HASHER_HPP
#define SHAPE_EDITOR_STRING_HASHER_HPP

#include <functional>
#include <string_view>

namespace shape_editor::tools {
    /**
     * Transparent heterogeneous std::string hasher implementation.
     *
     * @version 1.0
     * @since 1.0
     * @author SonarLint
     */
    class StringHasher {
    public:
        // enables heterogeneous lookup
        using is_transparent = void;

        /**
         * Hash the string.
         *
         * @param [in]view A std::string_view or any object, which can be converted in.
         *
         * @exceptsafe NO-THROWS.
         *
         * @return Return the hash value of the string.
         *
         * @version 1.0
         * @since 1.0
         */
        std::size_t operator()( const std::string_view view ) const noexcept {
            const std::hash<std::string_view> hasher;
            return hasher( view );
        }
    };

} // namespace shape_editor::tools

#endif // SHAPE_EDITOR_STRING_HASHER_HPP
