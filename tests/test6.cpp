//g++ test6.cpp -o a -std=c++23 -Wall -Wextra -pedantic
#include <iostream>
#include "../src/polynomial/sparse_standard_polynomial.hpp"
#include "../src/modular/basic_modulus_equivalence_class.hpp"

using namespace std;

int main ()
{
    //sussy polynomials
    auto A = mgb_dsc::sparse_standard_polynomial<long long,mgb_dsc::basic_modulus_equivalence_class<long long,17>>();
    for (int i = 0; i < 17; i++)
    {
        A[7*i] = (i+4)*i+7;
    }
    auto B = 7ll*A;
    std::cout << A(7).get_representant() << " " << A(7).get_normalized_value() << "\n";
    std::cout << B(7).get_representant() << " " << B(7).get_normalized_value() << "\n";
    std::cout << A(17).get_representant() << " " << A(17).get_normalized_value() << "\n";
    std::cout << B(17).get_representant() << " " << B(17).get_normalized_value() << "\n";
    std::cout << A(14).get_representant() << " " << A(14).get_normalized_value() << "\n";
    std::cout << B(14).get_representant() << " " << B(14).get_normalized_value() << "\n";
    return 0;
}