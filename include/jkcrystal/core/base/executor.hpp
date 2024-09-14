#ifndef JKC_CORE_BASE_EXECUTOR_HPP_
#define JKC_CORE_BASE_EXECUTOR_HPP_

#include <jkcrystal/core/base/dtypes.hpp>

#include <memory>


namespace jkc{

    class ReferenceExecutor : public OmpExecutor {
        public:
            static std::shared_ptr<ReferenceExecutor> create()
            {
                return std::shared_ptr<ReferenceExecutor>(new ReferenceExecutor());
            }

            void run(const Operation &op) const override
            {
                this->template log<log::Logger::operation_launched>(this, &op);
                op.run(std::static_pointer_cast<const ReferenceExecutor>(
                    this->shared_from_this()));
                this->template log<log::Logger::operation_completed>(this, &op);
            }

        protected:
            ReferenceExecutor() = default;
    };


    class Operation{
        public:
            #define JKC_DECLARE_RUN_OVERLOAD(_type, ...) \
            virtual void run(std::shared_ptr<const _type>) const

            JKC_ENABLE_FOR_ALL_EXECUTORS(JKC_DECLARE_RUN_OVERLOAD);

        #undef JKC_DECLARE_RUN_OVERLOAD

        
            virtual void run(std::shared_ptr<const ReferenceExecutor> executor) const;

            virtual const char *get_name() const noexcept;

    };

}

#endif // JKC_EXECUTOR_HPP_