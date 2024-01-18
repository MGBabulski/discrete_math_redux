#include <iostream>
#include "../src/combinatorics/binomial_coefficient.hpp"
#include "../src/combinatorics/catalan_number.hpp"
#include "../src/combinatorics/stirling_numbers.hpp"

using namespace std;

int main ()
{
    //ready to use at compile time
    cout << "777 choose 27 is : " << mgb_dsc::binomial_coefficient_v<unsigned long long,777,27> << "\n";
    cout << "47th catalan number is : " << mgb_dsc::catalan_number_v<unsigned long long,47> << "\n";
    return 0;
}