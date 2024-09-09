#ifndef JKC_CORE_BASE_DTYPES_HPP_
#define JKC_CORE_BASE_DTYPES_HPP_

#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdint>


#include <complex>
#include <type_traits>

namespace jkc {

    /**
    * Integral type used for allocation quantities.
    */
    using size_type = std::size_t;

    /**
    * 8-bit signed integral type.
    */
    using int8 = std::int8_t;

    /**
     * 16-bit signed integral type.
     */
    using int16 = std::int16_t;


    /**
     * 32-bit signed integral type.
     */
    using int32 = std::int32_t;


    /**
     * 64-bit signed integral type.
     */
    using int64 = std::int64_t;


    /**
     * 8-bit unsigned integral type.
     */
    using uint8 = std::uint8_t;

    /**
     * 16-bit unsigned integral type.
     */
    using uint16 = std::uint16_t;


    /**
     * 32-bit unsigned integral type.
     */
    using uint32 = std::uint32_t;


    /**
     * 64-bit unsigned integral type.
     */
    using uint64 = std::uint64_t;


    /**
     *
     */
    using uintptr = std::uintptr_t;


} // namespace jkc

#endif // JKC_CORE_BASE_DTYPES_HPP_