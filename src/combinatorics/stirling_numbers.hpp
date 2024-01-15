#pragma once

#include <limits>
#include <type_traits>

namespace mgb_dsc
{
    /**
     * wrapper around structs, that calculate nth Stirling numbers for a given unsigned integer type
     * @param integer_type appropriate type of unsigned integer
     * @note it will not work with multiple precision types that don't support constexpr clauses, furthermore compiler parameter -ftemplate-depth may need to be increased for extreme values
    */
    template <typename integer_type> requires std::numeric_limits<integer_type>::is_integer && std::is_unsigned_v<integer_type>
    struct stirling
    {
        /**
         * struct, that evaluates a first kind Stirling number n over k at compile time
         * @param N unsigned integer
         * @param K unsigned integer
         * @param enabler syntactic sugar for SFINAE puropses, it's best to ignore it (or just use one of the macros)
         * @note if N < K then the behavior is undefined
        */
        template <integer_type N, integer_type K, typename enabler = void>
        struct first_kind
        {
            static constexpr integer_type value = (N-1) * first_kind<N-1,K>::value + first_kind<N-1,K-1>::value;
        };
        /**
         * struct, that evaluates a first kind Stirling number n over k at compile time
         * @param N unsigned integer
         * @param K unsigned integer
         * @param enabler syntactic sugar for SFINAE puropses, it's best to ignore it (or just use one of the macros)
         * @note if N < K then the behavior is undefined
        */
        template <integer_type N>
        struct first_kind<N,N,void>
        {
            static constexpr integer_type value = 1;
        };
        /**
         * struct, that evaluates a first kind Stirling number n over k at compile time
         * @param N unsigned integer
         * @param K unsigned integer
         * @param enabler syntactic sugar for SFINAE puropses, it's best to ignore it (or just use one of the macros)
         * @note if N < K then the behavior is undefined
        */
        template <integer_type N>
        struct first_kind<N,0,std::enable_if_t<N!=0,void>>
        {
            static constexpr integer_type value = 0;
        };
        /**
         * struct, that evaluates a second kind Stirling number n over k at compile time
         * @param N unsigned integer
         * @param K unsigned integer
         * @param enabler syntactic sugar for SFINAE puropses, it's best to ignore it (or just use one of the macros)
         * @note if N < K then the behavior is undefined
        */
        template <integer_type N, integer_type K, typename enabler = void>
        struct second_kind
        {
            static constexpr integer_type value = K * second_kind<N-1,K>::value + second_kind<N-1,K-1>::value;
        };
        /**
         * struct, that evaluates a second kind Stirling number n over k at compile time
         * @param N unsigned integer
         * @param K unsigned integer
         * @param enabler syntactic sugar for SFINAE puropses, it's best to ignore it (or just use one of the macros)
         * @note if N < K then the behavior is undefined
        */
        template <integer_type N>
        struct second_kind<N,N,void>
        {
            static constexpr integer_type value = 1;
        };
        /**
         * struct, that evaluates a second kind Stirling number n over k at compile time
         * @param N unsigned integer
         * @param K unsigned integer
         * @param enabler syntactic sugar for SFINAE puropses, it's best to ignore it (or just use one of the macros)
         * @note if N < K then the behavior is undefined
        */
        template <integer_type N>
        struct second_kind<N,0,std::enable_if_t<N!=0,void>>
        {
            static constexpr integer_type value = 0;
        };
        /**
         * struct, that evaluates a second kind Stirling number n over k at compile time
         * @param N unsigned integer
         * @param K unsigned integer
         * @param enabler syntactic sugar for SFINAE puropses, it's best to ignore it (or just use one of the macros)
         * @note if N < K then the behavior is undefined
        */
        template <integer_type N>
        struct second_kind<N,1,std::enable_if_t<N!=1,void>>
        {
            static constexpr integer_type value = 1;
        };
    };

    /**
     * typedef wrapping of stirling<integer_type>::first_kind<N,K>
     * @param integer_type appropriate type of unsigned integer
     * @param N unsigned integer
     * @param K unsigned integer
     * @note it will not work with multiple precision types that don't support constexpr clauses, furthermore compiler parameter -ftemplate-depth may need to be increased for extreme values, finally if N < K then the behavior is undefined
    */
    template <typename integer_type, integer_type N, integer_type K>
    using stirling_first_kind = typename stirling<integer_type>::first_kind<N,K>;

    /**
     * typedef wrapping of stirling<integer_type>::second_kind<N,K>
     * @param integer_type appropriate type of unsigned integer
     * @param N unsigned integer
     * @param K unsigned integer
     * @note it will not work with multiple precision types that don't support constexpr clauses, furthermore compiler parameter -ftemplate-depth may need to be increased for extreme values, finally if N < K then the behavior is undefined
    */
    template <typename integer_type, integer_type N, integer_type K>
    using stirling_second_kind = typename stirling<integer_type>::second_kind<N,K>;

    /**
     * macro wrapping of stirling<integer_type>::first_kind<N,K>::value
     * @param integer_type appropriate type of unsigned integer
     * @param N unsigned integer
     * @param K unsigned integer
     * @note it will not work with multiple precision types that don't support constexpr clauses, furthermore compiler parameter -ftemplate-depth may need to be increased for extreme values, finally if N < K then the behavior is undefined
    */
    template <typename integer_type, integer_type N, integer_type K>
    constexpr integer_type stirling_first_kind_v = stirling_first_kind<integer_type,N,K>::value;

    /**
     * macro wrapping of stirling<integer_type>::second_kind<N,K>::value
     * @param integer_type appropriate type of unsigned integer
     * @param N unsigned integer
     * @param K unsigned integer
     * @note it will not work with multiple precision types that don't support constexpr clauses, furthermore compiler parameter -ftemplate-depth may need to be increased for extreme values, finally if N < K then the behavior is undefined
    */
    template <typename integer_type, integer_type N, integer_type K>
    constexpr integer_type stirling_second_kind_v = stirling_second_kind<integer_type,N,K>::value;
}