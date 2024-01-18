//g++ test4.cpp -o a -std=c++23 -Wall -Wextra -pedantic
#include <iostream>
#include "../src/polynomial/dense_standard_polynomial.hpp"

using namespace std;

int main ()
{
    auto A = mgb_dsc::dense_standard_polynomial<long long,long double,40>();
    auto B = mgb_dsc::dense_standard_polynomial<long long,long double,40>();

    cout << A.degree() << " " << A.max_degree() << "\n";
    cout << B.degree() << " " << B.max_degree() << "\n";
    
    A[0] = 34; 
    B[0] = 34;
    
    cout << A(3.12) << " | " << B(3.12) << "\n";

    A[1] = 2;
    B[4] = 6;

    cout << A(3.12) << " | " << B(3.12) << "\n";

    A[10] = 32;
    B[30] = 32;

    cout << A(3.12) << " | " << B(3.12) << "\n";

    for (const auto &i : A)
    {
        cout << i << " ";
    }
    cout << "\n";

    for (const auto &i : B)
    {
        cout << i << " ";
    }
    cout << "\n";

    cout << A.degree() << " " << A.max_degree() << "\n";
    cout << B.degree() << " " << B.max_degree() << "\n";

    return 0;
}