//g++ test3.cpp -o a -std=c++23 -Wall -Wextra -pedantic
#include <iostream>
#include "../src/modular/basic_modulus_equivalence_class.hpp"

using namespace std;

int main ()
{
    //standard classes
    auto a = mgb_dsc::basic_modulus_equivalence_class<int,17>(7);
    auto b = mgb_dsc::basic_modulus_equivalence_class<int,17>(8);
    //trivial class
    auto c = mgb_dsc::basic_modulus_equivalence_class<int,-23>(8);
    //almost trivial class
    auto d = mgb_dsc::basic_modulus_equivalence_class<int,1>(34);

    cout << a.get_modulus() << " " << a.get_representant() << " " << a.get_normalized_value() << " " << a.is_representant(109) << " " << a.is_representant(234) << "\n";
    cout << b.get_modulus() << " " << b.get_representant() << " " << b.get_normalized_value() << " " << b.is_representant(110) << " " << b.is_representant(234) << "\n";
    cout << c.get_modulus() << " " << c.get_representant() << " " << c.get_normalized_value() << " " << c.is_representant(109) << " " << c.is_representant(234) << "\n";
    cout << d.get_modulus() << " " << d.get_representant() << " " << d.get_normalized_value() << " " << d.is_representant(107) << " " << d.is_representant(234) << "\n";

    cout << (a+b).get_normalized_value() << " " << (a+b).get_representant() << "\n";
    cout << (a-b).get_normalized_value() << " " << (a-b).get_representant() << "\n"; 
    cout << (a*b).get_normalized_value() << " " << (a*b).get_representant() << "\n";
    cout << ((a-5*b)*(b+76)).get_normalized_value() << " " << ((a-5*b)*(b+76)).get_representant() << "\n";
}