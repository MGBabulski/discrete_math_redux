#pragma once

#include <concepts>

namespace mgb_dsc
{
    /**
     * Concept for checking if the two typenames behave well enough to form 
     * an abstract polynomial type (algebraically denoted by S[A]) using them
     * @param scalar_type type used for scaling arguments (in notation S[A] it is S)
     * @param arg_type type used as an polynomial argument (in notation S[A] it is A)
    */
    template <typename scalar_type, typename arg_type>
    concept polynomial_bundle = 
        std::is_default_constructible_v<arg_type>
        && std::is_default_constructible_v<scalar_type>
        && requires (scalar_type s, arg_type a, arg_type b)
        {
            {a + s} -> std::same_as<arg_type>;
            {a * s} -> std::same_as<arg_type>;
            {a + b} -> std::same_as<arg_type>; 
            {a * b} -> std::same_as<arg_type>;
        };

    /**
     * Concept for checking if polynomial_type is additive, subtractive, multiplicative, and multiplicative by scalar_type
     * @note the concept doesn't require multiplication of polynomials to produce the same type, as it may be inefficient to implement it that way
     * @param polynomial_type type used to represent the whole polynomial (in notation S[A] it's the entire structure)
     * @param scalar_type type used for scaling arguments (in notation S[A] it is S)
    */
    template <typename polynomial_type, typename scalar_type>
    concept polynomial_ring =
        requires (polynomial_type A, polynomial_type B, scalar_type s)
        {
            {A + B} -> std::same_as<polynomial_type>;
            {A - B} -> std::same_as<polynomial_type>;
            {A * B};
            {A == B} -> std::same_as<bool>;
            {s * A} -> std::same_as<polynomial_type>;
        };

    /**
     * Interface (as crtp) used to describe a polynomial structure in an abstract way
     * @param polynomial_type type used to represent the whole polynomial (in notation S[A] it's the entire structure)
     * @param scalar_type type used for scaling arguments (in notation S[A] it is S)
     * @param arg_type type used as an polynomial argument (in notation S[A] it is A)
    */
    template <typename polynomial_type, typename scalar_type, typename arg_type> requires polynomial_bundle<scalar_type,arg_type>
    class crtp_polynomial_interface
    {
    private:
        //this will yield error during compilation if you give wrong (non crtp-like) polynomial_type
        crtp_polynomial_interface () = default;
        friend polynomial_type;
        /**
         * The methods cast "this" object to a polynomial_type reference for crtp purposes
         * @returns polynomial_type&, which basically is the derived class 
        */
        constexpr polynomial_type& cast_reference () noexcept
        {
            return static_cast<polynomial_type&>(*this);
        }
        constexpr const polynomial_type& cast_reference () const noexcept
        {
            return static_cast<const polynomial_type&>(*this);
        }
    public:
        /**
         * The method returns a number corresponding to the greatest i for which coefficient a_i is non zero
         * @note we assume that a degree of a zero polynomial is zero
         * @returns degree of the polynomial
        */
        constexpr std::size_t degree () const noexcept
        {
            return this->cast_reference().degree();
        }
        /**
         * The method returns maximal degree of the polynomial (in other worlds: the max i for which this->at(i) will not throw)
         * @note we assume that a degree of a zero polynomial is zero; furthermore if the implementation is dynamic, then the returned value should be std::numeric_limits<std::size_t>::max-1
         * @returns maximal possible degree the polynomial can achieve
        */
        constexpr std::size_t max_degree () const noexcept
        {
            return this->cast_reference().max_degree();
        }
        /**
         * The method evaluates the polynomial using x as the argument
         * @param x argument of the polynomial
         * @returns evaluation of the polynomial
        */
        constexpr arg_type operator() (const arg_type &x) const noexcept
        {
            return this->cast_reference().operator()(x);
        }
        /**
         * The method gives back the reference to the coefficient at position i (without bound checking)
         * @param i index of coefficient a_i (abstractly coresponding to x^i)
         * @returns reference to the coefficient a_i
        */
        constexpr scalar_type& operator[] (const std::size_t i) noexcept
        {
            return this->cast_reference().operator[](i);
        }
        /**
         * The method gives back the coefficient at position i (without bound checking)
         * @param i index of coefficient a_i (abstractly coresponding to x^i)
         * @returns coefficient a_i
        */
        constexpr scalar_type operator[] (const std::size_t i) const noexcept
        {
            return this->cast_reference().operator[](i);
        }
        /**
         * The method gives back the reference to the coefficient at position i (with bound checking)
         * @param i index of coefficient a_i (abstractly coresponding to x^i)
         * @returns reference to the coefficient a_i
         * @throws out of bounds exception when outside of range
        */
        constexpr scalar_type& at (const std::size_t i)
        {
            return this->cast_reference().at(i);
        }
        /**
         * The method gives back the coefficient at position i (with bound checking)
         * @param i index of coefficient a_i (abstractly coresponding to x^i)
         * @returns coefficient a_i
         * @throws out of bounds exception when outside of range
        */
        constexpr scalar_type at (const std::size_t i) const
        {
            return this->cast_reference().at(i);
        }
    };
}