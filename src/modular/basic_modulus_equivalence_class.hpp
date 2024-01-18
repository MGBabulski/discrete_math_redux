#pragma once

#include "modulus_utilities.hpp"

namespace mgb_dsc
{
    /**
     * represents basic equivalence class type of Z-module
     * @param integer_type type used for the implementation
     * @param N modulus of the Z-module
     * @note if N <= 1 the class will operate as if the module is a trivial Z_1 with one equivalence class [0]
    */
    template <typename integer_type, integer_type N>
    class basic_modulus_equivalence_class : public crtp_modulus_equivalence_class_interface<basic_modulus_equivalence_class<integer_type,N>,integer_type>
    {
    private:
        integer_type value;
    public:
        ///constructor
        constexpr basic_modulus_equivalence_class (const integer_type i = 0) : value(i) {}
        /**
         * @returns representant of this equivalence class
         * @note the representant may not be normalized
        */
        constexpr integer_type get_representant () const noexcept
        {
            if constexpr (N <= 1)
            {
                return 0;
            }
            else
            {
                return value;
            }
        }
        /**
         * @returns normalized representant of this equivalence class
        */
        constexpr integer_type get_normalized_value () const noexcept
        {
            if constexpr (N <= 1)
            {
                return 0;
            }
            else
            {
                return (value+N)%N;
            }
        }
        /**
         * @returns modulus of this class
        */
        constexpr integer_type get_modulus () const noexcept
        {
            if constexpr (N <= 1)
            {
                return 0;
            }
            else
            {
                return N;
            }
        }
        /**
         * @param i value to be checked
         * @returns true if i is representant of this equivalence class, false otherwise
        */
        constexpr bool is_representant (const integer_type &i) const noexcept
        {
            if constexpr (N <= 1)
            {
                return true;
            }
            else
            {
                return ((i%N)+N)%N == get_normalized_value();
            }
        }
        /**
         * @returns true if both types describe the same equivalence class, false otherwise
        */
        friend constexpr bool operator== (const basic_modulus_equivalence_class &a, const basic_modulus_equivalence_class &b) noexcept
        {
            if constexpr (N <= 1)
            {
                return true;
            }
            else
            {
                return a.get_normalized_value() == b.get_normalized_value();
            }
        }
        /**
         * @returns class [c] that represents sum of classes [a] and [b]
        */
        friend constexpr basic_modulus_equivalence_class operator+ (const basic_modulus_equivalence_class &a, const basic_modulus_equivalence_class &b) noexcept
        {
            if constexpr (N <= 1)
            {
                return basic_modulus_equivalence_class{0};
            }
            else
            {
                return basic_modulus_equivalence_class{(a.get_normalized_value()+b.get_normalized_value())%N};
            }
        }
        /**
         * @returns class [c] that represents difference of classes [a] and [b]
        */
        friend constexpr basic_modulus_equivalence_class operator- (const basic_modulus_equivalence_class &a, const basic_modulus_equivalence_class &b) noexcept
        {
            if constexpr (N <= 1)
            {
                return basic_modulus_equivalence_class{0};
            }
            else
            {
                return basic_modulus_equivalence_class{(a.get_normalized_value()-b.get_normalized_value())%N};
            }
        }
        /**
         * @returns class [c] that represents product of classes [a] and [b]
        */
        friend constexpr basic_modulus_equivalence_class operator* (const basic_modulus_equivalence_class &a, const basic_modulus_equivalence_class &b) noexcept
        {
            if constexpr (N <= 1)
            {
                return basic_modulus_equivalence_class{0};
            }
            else
            {
                return basic_modulus_equivalence_class{(a.get_normalized_value()*b.get_normalized_value())%N};
            }
        }
    };
}