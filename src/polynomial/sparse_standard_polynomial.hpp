#pragma once

#include "polynomial_utilities.hpp"
#include <map>
#include <limits>

namespace mgb_dsc
{
    /**
     * represents polynomial which has sparsely packed coefficients
     * @param scalar_type type of scalar used to represent coefficients
     * @param arg_type type of polynomial argument
    */
    template <typename scalar_type, typename arg_type>
    class sparse_standard_polynomial : public crtp_polynomial_interface<sparse_standard_polynomial<scalar_type,arg_type>,scalar_type,arg_type>
    {
    private:
        std::map<std::size_t,scalar_type> coeffs = std::map<std::size_t,scalar_type>();
    public:
        friend constexpr sparse_standard_polynomial operator+<> (const sparse_standard_polynomial &a, const sparse_standard_polynomial &b) noexcept;
        friend constexpr sparse_standard_polynomial operator-<> (const sparse_standard_polynomial &a, const sparse_standard_polynomial &b) noexcept;
        friend constexpr sparse_standard_polynomial operator*<> (const sparse_standard_polynomial &a, const sparse_standard_polynomial &b) noexcept;
        friend constexpr sparse_standard_polynomial operator*<> (const scalar_type &scalar, const sparse_standard_polynomial &a) noexcept;
        /**
         * function, that trivially checks if this polynomial contains other
         * @param other polynomial that may be contained in this
         * @returns true if other is contained in this or false otherwise
        */
        constexpr bool contains (const sparse_standard_polynomial &other) const noexcept;
        /// friend function used to compare two given polynomials
        friend constexpr bool operator== (const sparse_standard_polynomial &a, const sparse_standard_polynomial &b) noexcept
        {
            return (a.contains(b) && b.contains(a));
        }
        /**
         * @returns iterator to the first coefficient of the polynomial
        */
        constexpr decltype(auto) begin () noexcept
        {
            return coeffs.begin();
        }
        /**
         * @returns iterator to the first coefficient of the polynomial
        */
        constexpr decltype(auto) begin () const noexcept
        {
            return coeffs.begin();
        }
        /**
         * @returns iterator to the element after the last coefficient
        */
        constexpr decltype(auto) end () noexcept
        {
            return coeffs.end();
        }
        /**
         * @returns iterator to the element after the last coefficient
        */
        constexpr decltype(auto) end () const noexcept
        {
            return coeffs.end();
        }
        /**
         * @returns degree of the polynomial
         * @note degree of the zero polynomial will be returned as zero
        */
        constexpr std::size_t degree () const noexcept;
        /**
         * @returns maximal possible degree of this polynomial class
        */
        constexpr std::size_t max_degree () const noexcept
        {
            return std::numeric_limits<std::size_t>::max()-1;
        }
        /**
         * evaluates the polynomial over argument x
         * @note this implementation is based on Horner's rule and thus any weird behavior or interaction of scalar_type and arg_type may influence the result
         * @param x argument of the polynomial
         * @returns evaluation of the polynomial over argument x
        */
        constexpr arg_type operator() (const arg_type &x) const noexcept;
        /**
         * @returns coefficient a_i that abstractly corresponds to x^i (without bound checking)
        */
        constexpr scalar_type& operator[] (const std::size_t i) noexcept
        {
            return coeffs[i];
        }
        /**
         * @returns coefficient a_i that abstractly corresponds to x^i (without bound checking)
        */
        constexpr scalar_type operator[] (const std::size_t i) const noexcept
        {
            try
            {
                return coeffs.at(i);
            }
            catch (...)
            {
                return scalar_type{};
            }
        }
        /**
         * @returns coefficient a_i that abstractly corresponds to x^i (with bound checking)
        */
        constexpr scalar_type& at (const std::size_t i)
        {
            return coeffs[i];
        }
        /**
         * @returns coefficient a_i that abstractly corresponds to x^i (with bound checking)
        */
        constexpr scalar_type at (const std::size_t i) const
        {
            try
            {
                return coeffs.at(i);
            }
            catch (...)
            {
                return scalar_type{};
            }
        }
    };

    /**
     * function used to add two given polynomials
     * @returns sum of the polynomials
    */
    template <typename scalar_type, typename arg_type>
    constexpr sparse_standard_polynomial<scalar_type,arg_type> operator+ (const sparse_standard_polynomial<scalar_type,arg_type> &a, const sparse_standard_polynomial<scalar_type,arg_type> &b) noexcept
    {
        auto c = sparse_standard_polynomial<scalar_type,arg_type>();
        for (const auto &[key,val] : a.coeffs)
        {
            c.coeffs[key] = val;
        }
        for (const auto &[key,val] : b.coeffs)
        {
            c.coeffs[key] = c.coeffs[key]+val;
        }
        return c;
    }

    /**
     * function used to subtract one polynomial from another
     * @returns difference of the polynomials
    */
    template <typename scalar_type, typename arg_type>
    constexpr sparse_standard_polynomial<scalar_type,arg_type> operator- (const sparse_standard_polynomial<scalar_type,arg_type> &a, const sparse_standard_polynomial<scalar_type,arg_type> &b) noexcept
    {
        auto c = sparse_standard_polynomial<scalar_type,arg_type>();
        for (const auto &[key,val] : a.coeffs)
        {
            c.coeffs[key] = val;
        }
        for (const auto &[key,val] : b.coeffs)
        {
            c.coeffs[key] = c.coeffs[key]-val;
        }
        return c;
    }

    /**
     * function used to multiply two polynomials
     * @returns product of the polynomials
    */
    template <typename scalar_type, typename arg_type>
    constexpr sparse_standard_polynomial<scalar_type,arg_type> operator* (const sparse_standard_polynomial<scalar_type,arg_type> &a, const sparse_standard_polynomial<scalar_type,arg_type> &b) noexcept
    {
        auto c = sparse_standard_polynomial<scalar_type,arg_type>();
        for (const auto &[a_key,a_val] : a.coeffs)
        {
            for (const auto &[b_key,b_val] : b.coeffs)
            {
                c.coeffs[a_key+b_key] = c.coeffs[a_key+b_key]+a_val*b_val;
            }
        }
        return c;
    }

    /**
     * function used to multiply polynomial by a scalar
     * @returns product of polynomial and scalar
    */
    template <typename scalar_type, typename arg_type>
    constexpr sparse_standard_polynomial<scalar_type,arg_type> operator* (const scalar_type &scalar, const sparse_standard_polynomial<scalar_type,arg_type> &b) noexcept
    {
        auto c = sparse_standard_polynomial<scalar_type,arg_type>();
        for (const auto &[key,val] : b.coeffs)
        {
            c.coeffs[key] = scalar*val;
        }
        return c;
    }

    template <typename scalar_type, typename arg_type>
    constexpr arg_type sparse_standard_polynomial<scalar_type,arg_type>::operator() (const arg_type &x) const noexcept
    {
        arg_type eval = arg_type{};
        arg_type variable = x;
        std::size_t i = 1;
        for (const auto &[key,val] : this->coeffs)
        {
            if (key == 0)
            {
                eval = eval+val;
                continue;
            }
            while (i < key)
            {
                variable = variable*x;
                i++;
            }
            eval = eval+val*variable;
        }
        return eval;
    }

    template <typename scalar_type, typename arg_type>
    constexpr bool sparse_standard_polynomial<scalar_type,arg_type>::contains (const sparse_standard_polynomial<scalar_type,arg_type> &other) const noexcept
    {
        for (const auto &[key,val] : other.coeffs)
        {
            if (val == scalar_type{})
            {
                continue;
            }
            auto i = this->coeffs.find(key);
            if (i == this->coeffs.end() || i->second != val)
            {
                return false;
            }
        }
        return true;
    }

    template <typename scalar_type, typename arg_type>
    constexpr std::size_t sparse_standard_polynomial<scalar_type,arg_type>::degree () const noexcept
    {
        for (auto i = this->coeffs.rbegin(); i != this->coeffs.rend(); ++i)
        {
            if (i->second != scalar_type{})
            {
                return i->first;
            }
        }
        return 0;
    }
}