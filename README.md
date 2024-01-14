# Discrete mathematics reduced library

This is a project that aims to encapsulate basic objects of discrete mathematics and deliver a general framework for further problem solving. The main idea was to find a compromise between optimization and benefits of the modern programming practicies and that's why the solution relies on static polymorphism and high abstraction.

## Possibilities

For basic computations and as an extension of basic c++ it should ***just work***. The library encourages user to make their own extensions and provides basic interfaces, that should help with designing usable structures. There are already some example structures inside. The structures are based on crtp static interfaces, which should help maintain high efficiency and 

## Limitations (at least for now...)

This library is more of a proof of concept, than an actual framework. There already exists plenty of much better frameworks and heavily optimized ready-to-use software. This library **does not** provide safety against programmers' stupidity (including, but **not** limited to mine). The library is obviosly reduced, and lacks more sophisticated structures and algorithms.

# Overviev

The project consists of 4 modules:

- combinatorics
- graph
- modular
- polynomial

each of them implements intefaces, concepts and sample classes that should help with discrete calculations. 

Each module is documented insource files. You may also check some use cases and examples in **"tests"** catalogue.

Full dependancy chart:

//TODO

## combinatorics

## graph

## modular

## polynomial

This module consists of three parts, that implement basic polynomial structures and concepts:

1. polynomial_utilities 
    
    > for crtp interface and compile-time checks
 
    ```c++
    template <typename scalar_type, typename arg_type>
    concept polynomial_bundle

    template <typename polynomial_type, typename scalar_type>
    concept polynomial_ring

    template <typename polynomial_type, typename scalar_type, typename arg_type> requires polynomial_bundle<scalar_type,arg_type>
    class crtp_polynomial_interface
    ```

7. dense_standard_polynomial
    
    > for template class that excels in dealing with densly packed polynomials (where non-zero coefficients are in majority)

    ```c++
    template <typename scalar_type, typename arg_type, std::size_t maximal_degree>
    class dense_standard_polynomial : public crtp_polynomial_interface<dense_standard_polynomial<scalar_type,arg_type,maximal_degree>,scalar_type,arg_type>
    ```

7. sparse_standard_polynomial

    > for template class that excels in dealing with sparesly packed polynomials (where non-zero coefficients are in minority)

    ```c++
    template <typename scalar_type, typename arg_type>
    class sparse_standard_polynomial : public crtp_polynomial_interface<sparse_standard_polynomial<scalar_type,arg_type>,scalar_type,arg_type>
    ```