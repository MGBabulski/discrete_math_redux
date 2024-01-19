//g++ test7.cpp -o a -std=c++23 -Wall -Wextra -pedantic
#include <iostream>
#include "../src/polynomial/sparse_standard_polynomial.hpp"
#include "../src/polynomial/dense_standard_polynomial.hpp"
#include "../src/combinatorics/stirling_numbers.hpp"
#include <chrono>
#include <iomanip>

using namespace std;

//17! = 355687428096000

//sample benchmark
template <typename P, typename S, typename A>
void process (mgb_dsc::crtp_polynomial_interface<P,S,A> &F)
{
    const auto start = std::chrono::steady_clock::now();
    F[0] = mgb_dsc::stirling_first_kind_v<S,17,0>;
    F[1] = mgb_dsc::stirling_first_kind_v<S,17,1>;
    F[2] = mgb_dsc::stirling_first_kind_v<S,17,2>;
    F[3] = mgb_dsc::stirling_first_kind_v<S,17,3>;
    F[4] = mgb_dsc::stirling_first_kind_v<S,17,4>;
    F[5] = mgb_dsc::stirling_first_kind_v<S,17,5>;
    F[6] = mgb_dsc::stirling_first_kind_v<S,17,6>;
    F[7] = mgb_dsc::stirling_first_kind_v<S,17,7>;
    F[8] = mgb_dsc::stirling_first_kind_v<S,17,8>;
    F[9] = mgb_dsc::stirling_first_kind_v<S,17,9>;
    F[10] = mgb_dsc::stirling_first_kind_v<S,17,10>;
    F[11] = mgb_dsc::stirling_first_kind_v<S,17,11>;
    F[12] = mgb_dsc::stirling_first_kind_v<S,17,12>;
    F[13] = mgb_dsc::stirling_first_kind_v<S,17,13>;
    F[14] = mgb_dsc::stirling_first_kind_v<S,17,14>;
    const auto end = std::chrono::steady_clock::now();
    std::cout << "value: " << F(1) << "\n";
    const std::chrono::duration<long double> T = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Time: " << T.count() << "\n";
}

template <typename P, typename S, typename A>
void process_with_std_out (mgb_dsc::crtp_polynomial_interface<P,S,A> &F)
{
    const auto start = std::chrono::steady_clock::now();
    F[0] = mgb_dsc::stirling_first_kind_v<S,17,0>;
    F[1] = mgb_dsc::stirling_first_kind_v<S,17,1>;
    F[2] = mgb_dsc::stirling_first_kind_v<S,17,2>;
    F[3] = mgb_dsc::stirling_first_kind_v<S,17,3>;
    F[4] = mgb_dsc::stirling_first_kind_v<S,17,4>;
    F[5] = mgb_dsc::stirling_first_kind_v<S,17,5>;
    F[6] = mgb_dsc::stirling_first_kind_v<S,17,6>;
    F[7] = mgb_dsc::stirling_first_kind_v<S,17,7>;
    F[8] = mgb_dsc::stirling_first_kind_v<S,17,8>;
    F[9] = mgb_dsc::stirling_first_kind_v<S,17,9>;
    F[10] = mgb_dsc::stirling_first_kind_v<S,17,10>;
    F[11] = mgb_dsc::stirling_first_kind_v<S,17,11>;
    F[12] = mgb_dsc::stirling_first_kind_v<S,17,12>;
    F[13] = mgb_dsc::stirling_first_kind_v<S,17,13>;
    F[14] = mgb_dsc::stirling_first_kind_v<S,17,14>;
    F[15] = mgb_dsc::stirling_first_kind_v<S,17,15>;
    F[16] = mgb_dsc::stirling_first_kind_v<S,17,16>;
    F[17] = mgb_dsc::stirling_first_kind_v<S,17,17>;
    std::cout << "value: " << F(1) << "\n";
    const auto end = std::chrono::steady_clock::now();
    const std::chrono::duration<long double> T = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Time: " << T.count() << "\n";
}

int main ()
{
    //factorial emulation
    auto A = mgb_dsc::dense_standard_polynomial<unsigned long long, unsigned long long, 17>();
    auto B = mgb_dsc::sparse_standard_polynomial<unsigned long long, unsigned long long>();
    std::cout << std::setprecision(17) << std::fixed; 
    process(A);
    process(B);
    process_with_std_out(A);
    process_with_std_out(B);
    return 0;
}