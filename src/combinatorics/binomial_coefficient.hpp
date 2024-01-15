#pragma once

#include <limits>
#include <type_traits>

namespace mgb_dsc
{
    /**
     * wrapper around the struct, that evaluates a binomial coefficient n choose k at compile time
     * @param integer_type appropriate type of unsigned integer
     * @note it will not work with multiple precision types that don't support constexpr clauses, furthermore compiler parameter -ftemplate-depth may need to be increased for extreme values
    */
    template <typename integer_type> requires std::numeric_limits<integer_type>::is_integer && std::is_unsigned_v<integer_type>
    struct binomial
    {
        /**
         * struct, that evaluates a binomial coefficient n choose k at compile time
         * @param N unsigned integer
         * @param K unsigned integer
         * @note if N < K then the behavior is undefined
        */
        template <integer_type N, integer_type K>
        struct coefficient
        {
            static constexpr integer_type value = coefficient<N-1,K-1>::value + coefficient<N-1,K>::value;
        };
        /**
         * struct, that evaluates a binomial coefficient n choose k at compile time
         * @param N unsigned integer
         * @param K unsigned integer
         * @note if N < K then the behavior is undefined
        */
        template <integer_type N>
        struct coefficient<N,N>
        {
            static constexpr integer_type value = 1;
        };
        /**
         * struct, that evaluates a binomial coefficient n choose k at compile time
         * @param N unsigned integer
         * @param K unsigned integer
         * @note if N < K then the behavior is undefined
        */
        template <integer_type N>
        struct coefficient<N,0>
        {
            static constexpr integer_type value = 1;
        };
    };

    /**
     * typedef wrapping of binomial<integer_type>::coefficient<N,K>
     * @param integer_type appropriate type of unsigned integer
     * @param N unsigned integer
     * @param K unsigned integer
     * @note it will not work with multiple precision types that don't support constexpr clauses, furthermore compiler parameter -ftemplate-depth may need to be increased for extreme values, finally if N < K then the behavior is undefined
    */
    template <typename integer_type, integer_type N, integer_type K>
    using binomial_coefficient = typename binomial<integer_type>::coefficient<N,K>;

    /**
     * macro wrapping of binomial<integer_type>::coefficient<N,K>::value
     * @param integer_type appropriate type of unsigned integer
     * @param N unsigned integer
     * @param K unsigned integer
     * @note it will not work with multiple precision types that don't support constexpr clauses, furthermore compiler parameter -ftemplate-depth may need to be increased for extreme values, finally if N < K then the behavior is undefined
    */
    template <typename integer_type, integer_type N, integer_type K>
    constexpr integer_type binomial_coefficient_v = binomial_coefficient<integer_type,N,K>::value;
}