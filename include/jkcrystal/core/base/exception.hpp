#ifndef JKC_CORE_EXCEPTION_HPP_
#define JKC_CORE_EXCEPTION_HPP_


#include <exception>
#include <string>


#include <jkcrystal/core/base/dtypes.hpp>

namespace jkc {

    /**
     * Error is the base class for all exceptions thrown by the JKCrystal library.
     */
    class Error : public std::exception {
        public:
            /**
             * Initializes an error.
             * @param file The name of the offending source file
             * @param line The source code line number where the error occurred
             * @param what The error message
             */
            Error(const std::string &file, int line, const std::string &what)
                : what_(file + ":" + std::to_string(line) + ": " + what)
            {}

            /**
             * Returns a human-readable string with a more detailed description of the
             * error.
             */
            virtual const char *what() const noexcept override { return what_.c_str(); }

        private:
            const std::string what_;
    };

    /**
     * CudaError is thrown when a CUDA routine throws a non-zero error code.
     */
    class CudaError : public Error {
        public:
            /**
             * Initializes a CUDA error.
             * @param file The name of the offending source file
             * @param line The source code line number where the error occurred
             * @param func The name of the CUDA routine that failed
             * @param error_code The resulting CUDA error code
             */
            CudaError(const std::string &file, int line, const std::string &func,
                    int64 error_code)
                : Error(file, line, func + ": " + get_error(error_code))
            {}

        private:
            static std::string get_error(int64 error_code);
    };


}

#endif // JKC_CORE_EXCEPTION_HPP_