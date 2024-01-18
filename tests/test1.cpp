//g++ test1.cpp -o a -std=c++23 -Wall -Wextra -pedantic
#include <iostream>
#include "../src/combinatorics/binomial_coefficient.hpp"
#include "../src/combinatorics/catalan_number.hpp"
#include "../src/combinatorics/stirling_numbers.hpp"

using namespace std;

int main ()
{
    //ready to use at compile time
    cout << "177 choose 12 is : " << mgb_dsc::binomial_coefficient_v<unsigned long long,177,12> << "\n";            //1348268519586590420
    cout << "35th catalan number is : " << mgb_dsc::catalan_number_v<unsigned long long,35> << "\n";                //3116285494907301262
    cout << "1st stirling numer (37,29) : " << mgb_dsc::stirling_first_kind_v<unsigned long long, 37,29> << "\n";      //317479586853582846
    cout << "2nd stirling numer (37,29) : " << mgb_dsc::stirling_second_kind_v<unsigned long long, 37,29> << "\n";     //101834671464485146
    return 0;
}

