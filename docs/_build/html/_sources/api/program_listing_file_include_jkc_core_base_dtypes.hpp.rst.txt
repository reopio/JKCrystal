
.. _program_listing_file_include_jkc_core_base_dtypes.hpp:

Program Listing for File dtypes.hpp
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_jkc_core_base_dtypes.hpp>` (``include/jkc/core/base/dtypes.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef JKC_CORE_BASE_DTYPES_HPP_
   #define JKC_CORE_BASE_DTYPES_HPP_
   
   #include <cassert>
   #include <climits>
   #include <cstddef>
   #include <cstdint>
   
   
   #include <complex>
   #include <type_traits>
   
   #include "../extended/extend_flops.hpp"
   
   namespace jkc {
   
       using size_type = std::size_t;
   
       using int8 = std::int8_t;
   
       using int16 = std::int16_t;
   
   
       using int32 = std::int32_t;
   
   
       using int64 = std::int64_t;
   
   
       using uint8 = std::uint8_t;
   
       using uint16 = std::uint16_t;
   
   
       using uint32 = std::uint32_t;
   
   
       using uint64 = std::uint64_t;
   
   
       using uintptr = std::uintptr_t;
   
       using float32 = float;
   
   
       using float64 = double;
   
   
       using full_precision = double;
   
   
       using default_precision = double;
   
   
       constexpr size_type byte_size = CHAR_BIT;
   
   
   } // namespace jkc
   
   #endif // JKC_CORE_BASE_DTYPES_HPP_
