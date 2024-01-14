#pragma once

#include <concepts>
#include <limits>

namespace mgb_dsc
{
    /**
     * concept, that checks if a given type behaves like a equivalence class of some Z-module
     * @note only the existence of basic operators is checked
     * @param equivalence_class type to be checked
    */
    template <typename equivalence_class>
    concept modulus = 
    std::is_default_constructible_v<equivalence_class>
    && std::is_copy_constructible_v<equivalence_class>
    && requires (equivalence_class a, equivalence_class b)
    {
        {a + b} -> std::same_as<equivalence_class>;
        {a - b} -> std::same_as<equivalence_class>;
        {a * b} -> std::same_as<equivalence_class>;
        {a == b} -> std::same_as<bool>;
    };
    
    /**
     * Interface (as crtp) used to describe an equivalence class of a Z-module
     * @note existence of no arithmetic operators is checked
     * @param eq_class_type type used to describe an equivalence class of a Z-module
     * @param integer_type type used to narrow the range of calculations (and usually to implement the class itself)
    */
    template <typename eq_class_type, typename integer_type> requires std::numeric_limits<integer_type>::is_integer
    class crtp_modulus_equivalence_class_interface
    {
    private:
        //this will yield error during compilation if you give wrong (non crtp-like) polynomial_type
        crtp_modulus_equivalence_class_interface () = default;
        friend eq_class_type;
        /**
         * The method casts "this" object to a eq_class_typr reference for crtp purposes
         * @returns eq_class_type, which basically is the derived class 
        */
        constexpr eq_class_type& cast_reference () noexcept
        {
            return static_cast<eq_class_type&>(*this);
        }
        constexpr const eq_class_type& cast_reference () const noexcept
        {
            return static_cast<const eq_class_type&>(*this);
        }
    public:
        /**
         * The method returns a representant of the class
         * @note the representant does not need to be normalized
         * @returns integer_type which is a representant of the class
        */
        constexpr integer_type get_representant () const noexcept
        {
            return this->cast_reference().get_representant();
        }
        /**
         * The method returns a normalized representant of the class
         * @returns integer_type that is a value between 0 and N-1, where N is a modulus and a representant of the class
        */
        constexpr integer_type get_normalized_value () const noexcept
        {
            return this->cast_reference().get_normalized_value();
        }
        /**
         * The method returns a modulus, which this equivalence class based on
         * @returns modulus of the structure
        */
        constexpr integer_type get_modulus () const noexcept
        {
            return this->cast_reference().get_modulus();
        }
        /**
         * The method checks, if a given nuber is a representant of the class
         * @param i value to be checked
         * @returns true if i is a representant of the class or false otherwise
        */
        constexpr bool is_representant (const integer_type &i) const noexcept
        {
            return this->cast_reference().is_representant(i);
        }
    };
}