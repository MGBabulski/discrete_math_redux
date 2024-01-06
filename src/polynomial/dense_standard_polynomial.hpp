#pragma once

#include "polynomial_utilities.hpp"
#include <array>
#include <stdexcept>

namespace mgb_dsc
{
    /**
     * represents polynomial which has densly packed coefficients
     * @param scalar_type type of scalar used to represent coefficients
     * @param arg_type type of polynomial argument
     * @param maximal_degree names maximal degree of the polynomial (in this case it means the limit of maximal_degree+1 coefficients)
    */
    template <typename scalar_type, typename arg_type, std::size_t maximal_degree>
    class dense_standard_polynomial : public crtp_polynomial_interface<dense_standard_polynomial<scalar_type,arg_type,maximal_degree>,scalar_type,arg_type>
    {
    private:
        std::array<scalar_type,maximal_degree+1> coeffs = std::array<scalar_type,maximal_degree+1>();
    public:
        friend constexpr dense_standard_polynomial operator+<> (const dense_standard_polynomial &a, const dense_standard_polynomial &b) noexcept;
        friend constexpr dense_standard_polynomial operator-<> (const dense_standard_polynomial &a, const dense_standard_polynomial &b) noexcept;
        template <std::size_t seckond_maximal>
        friend constexpr dense_standard_polynomial<scalar_type,arg_type,maximal_degree+seckond_maximal> operator* (const dense_standard_polynomial<scalar_type,arg_type,maximal_degree> &a, const dense_standard_polynomial<scalar_type,arg_type,seckond_maximal> &b) noexcept;
        template <std::size_t seckond_maximal>
        friend constexpr dense_standard_polynomial<scalar_type,arg_type,maximal_degree+seckond_maximal> operator* (const dense_standard_polynomial<scalar_type,arg_type,seckond_maximal> &a, const dense_standard_polynomial<scalar_type,arg_type,maximal_degree> &b) noexcept;
        friend constexpr dense_standard_polynomial operator*<> (const scalar_type &scalar, const dense_standard_polynomial &a) noexcept;
        /// friend function used to compare two given polynomials
        friend constexpr bool operator== (const dense_standard_polynomial &a, const dense_standard_polynomial &b) noexcept
        {
            return (a.coeffs == b.coeffs);
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
            return maximal_degree;
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
            return coeffs[i];
        }
        /**
         * @returns coefficient a_i that abstractly corresponds to x^i (with bound checking)
        */
        constexpr scalar_type& at (const std::size_t i)
        {
            return coeffs.at(i);
        }
        /**
         * @returns coefficient a_i that abstractly corresponds to x^i (with bound checking)
        */
        constexpr scalar_type at (const std::size_t i) const
        {
            return coeffs.at(i);
        }
    };
    
    /**
     * function used to add two given polynomials
     * @returns sum of the polynomials
    */
    template <typename scalar_type, typename arg_type, std::size_t max_degree>
    constexpr dense_standard_polynomial<scalar_type,arg_type,max_degree> operator+ (const dense_standard_polynomial<scalar_type,arg_type,max_degree> &a, const dense_standard_polynomial<scalar_type,arg_type,max_degree> &b) noexcept
    {
        auto c = dense_standard_polynomial<scalar_type,arg_type,max_degree>();
        for (std::size_t i = 0; i <= max_degree; i++)
        {
            c.coeffs[i] = a.coeffs[i]+b.coeffs[i];
        }
        return c;
    }

    /**
     * function used to subtract one polynomial from another
     * @returns difference of the polynomials
    */
    template <typename scalar_type, typename arg_type, std::size_t max_degree>
    constexpr dense_standard_polynomial<scalar_type,arg_type,max_degree> operator- (const dense_standard_polynomial<scalar_type,arg_type,max_degree> &a, const dense_standard_polynomial<scalar_type,arg_type,max_degree> &b) noexcept
    {
        auto c = dense_standard_polynomial<scalar_type,arg_type,max_degree>();
        for (std::size_t i = 0; i <= max_degree; i++)
        {
            c.coeffs[i] = a.coeffs[i]-b.coeffs[i];
        }
        return c;
    }

    /**
     * function used to multiply two polynomials
     * @note due to overflow, the sizes should be small enough that max_degree_of_first+max_degree_of_second is a valid std::size_t number
     * @returns product of the polynomials
    */
    template <typename scalar_type, typename arg_type, std::size_t max_degree_of_first, std::size_t max_degree_of_second>
    constexpr dense_standard_polynomial<scalar_type,arg_type,max_degree_of_first+max_degree_of_second> operator* (const dense_standard_polynomial<scalar_type,arg_type,max_degree_of_first> &a, const dense_standard_polynomial<scalar_type,arg_type,max_degree_of_second> &b) noexcept
    {
        auto c = dense_standard_polynomial<scalar_type,arg_type,max_degree_of_first+max_degree_of_second>();
        for (std::size_t i = 0; i <= max_degree_of_first; i++)
        {
            for (std::size_t j = 0; j <= max_degree_of_second; j++)
            {
                c.coeffs[i+j] = c.coeffs[i+j]+a.coeffs[i]*b.coeffs[j];
            }
        }
        return c;
    }

    /**
     * function used to multiply polynomial by a scalar
     * @returns product of polynomial and scalar
    */
    template <typename scalar_type, typename arg_type, std::size_t max_degree>
    constexpr dense_standard_polynomial<scalar_type,arg_type,max_degree> operator* (const scalar_type &scalar, const dense_standard_polynomial<scalar_type,arg_type,max_degree> &a) noexcept
    {
        auto c = dense_standard_polynomial<scalar_type,arg_type,max_degree>();
        for (std::size_t i = 0; i <= max_degree; i++)
        {
            c.coeffs[i] = scalar*a.coeffs[i];
        }
        return c;
    }

    template <typename scalar_type, typename arg_type, std::size_t maximal_degree>
    constexpr std::size_t dense_standard_polynomial<scalar_type,arg_type,maximal_degree>::degree () const noexcept
    {
        for (std::size_t i = maximal_degree; i > 0; i--)
        {
            if (this->coeffs[i] != scalar_type{})
            {
                return i;
            }
        }
        return 0;
    }

    template <typename scalar_type, typename arg_type, std::size_t maximal_degree>
    constexpr arg_type dense_standard_polynomial<scalar_type,arg_type,maximal_degree>::operator() (const arg_type &x) const noexcept
    {
        auto val = arg_type();
        for (std::size_t i = maximal_degree; i > 0; i--)
        {
            val = val*x+coeffs[i];
        }
        val = val*x;
        val = val+this->coeffs[0];
        return val;
    }
}