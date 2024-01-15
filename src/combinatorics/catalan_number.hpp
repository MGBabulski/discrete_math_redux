#pragma once

#include "binomial_coefficient.hpp"
#include <limits>
#include <type_traits>

namespace mgb_dsc
{
    /**
     * wrapper around the struct, that calculates nth Catalan number for a given unsigned integer type
     * @param integer_type appropriate type of unsigned integer
     * @note it will not work with multiple precision types that don't support constexpr clauses, furthermore compiler parameter -ftemplate-depth may need to be increased for extreme values
    */
    template <typename integer_type> requires std::numeric_limits<integer_type>::is_integer && std::is_unsigned_v<integer_type>
    struct catalan
    {
        /**
         * struct, that calculates n-th Catalan number for a given unsigned integer type
         * @param N unsigned integer
         * @note the bool is there only to trick compiler that other struct is not a full specialization - in general you should use one of the macros to avoid double instantiaton
        */
        template <integer_type N, bool B>
        struct number
        {
            static constexpr integer_type value = binomial_coefficient_v<integer_type,2*N,N> - binomial_coefficient_v<integer_type,2*N,N+1>;
        };
        /**
         * struct, that calculates n-th Catalan number for a given unsigned integer type
         * @param N unsigned integer
         * @note the bool is there only to trick compiler that this struct is not a full specialization - in general you should use one of the macros to avoid double instantiaton
        */
        template <bool B>
        struct number<0,B>
        {
            static constexpr integer_type value = 1;
        };
    };

    /**
     * typedef wrapping of catalan<type>::number<N>
     * @param integer_type appropriate type of unsigned integer
     * @param N unsigned integer
     * @note it will not work with multiple precision types that don't support constexpr clauses, furthermore compiler parameter -ftemplate-depth may need to be increased for extreme values
    */
    template <typename integer_type, integer_type N>
    using catalan_number = typename catalan<integer_type>::number<N,true>;

    /**
     * macro wrapping of catalan<type>::number<N>::value
     * @param integer_type appropriate type of unsigned integer
     * @param N unsigned integer
     * @note it will not work with multiple precision types that don't support constexpr clauses, furthermore compiler parameter -ftemplate-depth may need to be increased for extreme values
    */
    template <typename integer_type, integer_type N>
    constexpr integer_type catalan_number_v = catalan_number<integer_type,N>::value;
}