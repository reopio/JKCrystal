/**
*@file   exception.hpp
*@brief  This is the head file defining custom exceptions for the JKCrystal library.
*        The exceptions are used to signal errors in the library.   
*        The exceptions are derived from the standard exception class.
*        You can add your own exceptions by deriving from the Error class.
*@author gejifeng
*@date   2024/9
*/


#ifndef JKC_CORE_JKCEXCEPTION_HPP_
#define JKC_CORE_JKCEXCEPTION_HPP_


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
     * NotSupported is thrown in case it is not possible to
     * perform the requested operation on the given object type.
     */
    class NotSupported : public Error {
        public:
            /**
             * Initializes a NotSupported error.
             * @param file The name of the offending source file
             * @param line The source code line number where the error occurred
             * @param func The name of the function where the error occured
             * @param obj_type The object type on which the requested operation
                             cannot be performed.
            */
            NotSupported(const std::string &file, int line, const std::string &func,
                        const std::string &obj_type)
                : Error(file, line,
                        "Operation " + func + " does not support parameters of type " +
                            obj_type)
            {}
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

    
    /**
     * CublasError is thrown when a cuBLAS routine throws a non-zero error code.
     */
    class CublasError : public Error {
        public:
            /**
             * Initializes a cuBLAS error.
             * @param file The name of the offending source file
             * @param line The source code line number where the error occurred
             * @param func The name of the cuBLAS routine that failed
             * @param error_code The resulting cuBLAS error code
             */
            CublasError(const std::string &file, int line, const std::string &func,
                        int64 error_code)
                : Error(file, line, func + ": " + get_error(error_code))
            {}

        private:
            static std::string get_error(int64 error_code);
    };


    /**
     * CusparseError is thrown when a cusparse routine throws a non-zero error code.
     */
    class CusparseError : public Error {
        public:
            /**
             * Initializes a cuSPARSE error.
             * @param file The name of the offending source file
             * @param line The source code line number where the error occurred
             * @param func The name of the cuSPARSE routine that failed
             * @param error_code The resulting cuSPARSE error code
             */
            CusparseError(const std::string &file, int line, const std::string &func,
                        int64 error_code)
                : Error(file, line, func + ": " + get_error(error_code))
            {}

        private:
            static std::string get_error(int64 error_code);
    };


    /**
     * AMGXError is thrown when AMGX library throws an error code.
     */
    class AMGXError : public Error {
        public:
            /**
             * Initializes a cuSPARSE error.
             * @param file The name of the offending source file
             * @param line The source code line number where the error occurred
             * @param func The name of the cuSPARSE routine that failed
             * @param error_code The resulting cuSPARSE error code
             */
            AMGXError(const std::string &file, int line, const std::string &func,
                        int64 error_code)
                : Error(file, line, func + ": " + get_error(error_code))
            {}

        private:
            static std::string get_error(int64 error_code);
    };


    /**
     * MPIError is thrown when MPI throws an error code.
     */
    class MPIError : public Error {
        public:
            /**
             * Initializes a cuSPARSE error.
             * @param file The name of the offending source file
             * @param line The source code line number where the error occurred
             * @param func The name of the cuSPARSE routine that failed
             * @param error_code The resulting cuSPARSE error code
             */
            MPIError(const std::string &file, int line, const std::string &func,
                        int64 error_code)
                : Error(file, line, func + ": " + get_error(error_code))
            {}

        private:
            static std::string get_error(int64 error_code);
    };


    /**
     * torchError is thrown when tnn library throws an error code.
     */
    class   torchError : public Error {
        public:
            /**
             * Initializes a cuSPARSE error.
             * @param file The name of the offending source file
             * @param line The source code line number where the error occurred
             * @param func The name of the cuSPARSE routine that failed
             * @param error_code The resulting cuSPARSE error code
             */
            torchError(const std::string &file, int line, const std::string &func,
                        int64 error_code)
                : Error(file, line, func + ": " + get_error(error_code))
            {}

        private:
            static std::string get_error(int64 error_code);
    };


    /**
     * AllocationError is thrown if a memory allocation fails.
     */
    class AllocationError : public Error {
        public:
            /**
             * Initializes an allocation error.
             * @param file The name of the offending source file
             * @param line The source code line number where the error occurred
             * @param device The device on which the error occurred
             * @param bytes The size of the memory block whose allocation failed.
             */
            AllocationError(const std::string &file, int line,
                            const std::string &device, size_type bytes)
                : Error(file, line,
                        device + ": failed to allocate memory block of " +
                            std::to_string(bytes) + "B")
            {}
    };


    /**
     * OutOfBoundsError is thrown if a memory access is detected to be
     * out-of-bounds.
     */
    class OutOfBoundsError : public Error {
        public:
            /**
             * Initializes an OutOfBoundsError.
             * @param file  The name of the offending source file
             * @param line  The source code line number where the error occurred
             * @param index  The position that was accessed
             * @param bound  The first out-of-bound index
             */
            OutOfBoundsError(const std::string &file, int line, size_type index,
                            size_type bound)
                : Error(file, line,
                        "trying to access index " + std::to_string(index) +
                            " in a memory block of " + std::to_string(bound) +
                            " elements")
            {}
    };


    /**
     * GMemoryError is thrown if a general memory error is detected
     * general memory error.
     */
    class GMemoryError : public Error {
        public:
            /**
             * Initializes an OutOfBoundsError.
             * @param file  The name of the offending source file
             * @param line  The source code line number where the error occurred
             * @param index  The position that was accessed
             * @param bound  The first out-of-bound index
             */
            GMemoryError(const std::string &file, int line, size_type index,
                            size_type bound)
                : Error(file, line,
                        "Memory error detected")
            {}
    };


}

#endif // JKC_CORE_EXCEPTION_HPP_