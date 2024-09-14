/**
*@file   dtypes.hpp
*@brief  This is the head file defining float types
*@author gejifeng
*@date   2024/9
*/


#ifndef JKC_CORE_BASE_DTYPES_HPP_
#define JKC_CORE_BASE_DTYPES_HPP_

#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdint>


#include <complex>
#include <type_traits>

#include <jkcrystal/core/extended/extend_floats.hpp>

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

    /**
     * Single precision floating point type.
     */
    using float32 = float;


    /**
     * Double precision floating point type.
     */
    using float64 = double;


    /**
     * The most precise floating-point type.
     */
    using full_precision = double;


    /**
     * Precision used if no precision is explicitly specified.
     */
    using default_precision = double;


    /**
     * Number of bits in a byte
     */
    constexpr size_type byte_size = CHAR_BIT;


    // end of data types declaration


    #define JKC_ENABLE_FOR_ALL_EXECUTORS(_enable_macro) \
    _enable_macro(OmpExecutor, omp);                \
    _enable_macro(CudaExecutor, cuda)


} // namespace jkc

#endif // JKC_CORE_BASE_DTYPES_HPP_