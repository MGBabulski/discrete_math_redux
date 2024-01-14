# Discrete mathematics reduced library

This is a project that aims to encapsulate basic objects of discrete mathematics and deliver a general framework for further problem solving. The main idea was to find a compromise between optimization and benefits of the modern programming practicies and that's why the solution relies on static polymorphism and high abstraction.

## Possibilities

For basic computations and as an extension of basic c++ it should ***just work***. The library encourages user to make their own extensions and provides basic interfaces, that should help with designing usable structures. There are already some example structures inside. The structures are based on crtp static interfaces, which should help maintain high efficiency and since there is exactly one interface to inherit from for each module, any ambiguities should simply not exist. The library (and it's basic structures) is ready to be used with multiple-precision arithmetic libraries (that override std traits).

## Limitations

This library is more of a proof of concept, than an actual framework. There already exists plenty of much better frameworks and heavily optimized ready-to-use software. This library **does not** provide safety against programmers' stupidity (including, but **not** limited to mine). The library is obviosly reduced, and lacks more sophisticated structures and algorithms.

# Overviev

The project consists of 4 modules:

- combinatorics
- graph
- modular
- polynomial

each of them implements intefaces, concepts and sample classes that should help with discrete calculations. 

Each module is documented insource files. You may also check some use cases and examples in **"tests"** catalogue.

Full dependency chart:

//TODO

## combinatorics

## graph

## modular

This module consists of two parts, that implement basic modular arithmetic structures and concepts:

1. modulus_utilities

    > crtp interface and compile-time checks

    ```c++
    template <typename equivalence_class>
    concept modulus

    template <typename eq_class_type, typename integer_type> requires std::numeric_limits<integer_type>::is_integer
    class crtp_modulus_equivalence_class_interface
    ```

7. basic_modulus_equivalence_class

    > template class that encapsulates the idea of Z-module equivalence class

    ```c++
    template <typename integer_type, integer_type N>
    class basic_modulus_equivalence_class : public crtp_modulus_equivalence_class_interface<basic_modulus_equivalence_class<integer_type,N>,integer_type>
    ```

## polynomial

This module consists of three parts, that implement basic polynomial structures and concepts:

1. polynomial_utilities 
    
    > crtp interface and compile-time checks
 
    ```c++
    template <typename scalar_type, typename arg_type>
    concept polynomial_bundle

    template <typename polynomial_type, typename scalar_type>
    concept polynomial_ring

    template <typename polynomial_type, typename scalar_type, typename arg_type> requires polynomial_bundle<scalar_type,arg_type>
    class crtp_polynomial_interface
    ```

7. dense_standard_polynomial
    
    > template class that excels in dealing with densly packed polynomials (where non-zero coefficients are in majority)

    ```c++
    template <typename scalar_type, typename arg_type, std::size_t maximal_degree>
    class dense_standard_polynomial : public crtp_polynomial_interface<dense_standard_polynomial<scalar_type,arg_type,maximal_degree>,scalar_type,arg_type>
    ```

7. sparse_standard_polynomial

    > template class that excels in dealing with sparesly packed polynomials (where non-zero coefficients are in minority)

    ```c++
    template <typename scalar_type, typename arg_type>
    class sparse_standard_polynomial : public crtp_polynomial_interface<sparse_standard_polynomial<scalar_type,arg_type>,scalar_type,arg_type>
    ```