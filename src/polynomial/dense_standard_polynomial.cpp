#include "dense_standard_polynomial.hpp"

template class mgb_dsc::dense_standard_polynomial<int,float,100>;
template class mgb_dsc::dense_standard_polynomial<float,float,100>;
template class mgb_dsc::dense_standard_polynomial<double,double,100>;
template class mgb_dsc::dense_standard_polynomial<long long,long double,100>;
template class mgb_dsc::dense_standard_polynomial<long double,long double,100>;

static_assert(mgb_dsc::polynomial_ring<mgb_dsc::dense_standard_polynomial<int,float,100>,int>);
static_assert(mgb_dsc::polynomial_ring<mgb_dsc::dense_standard_polynomial<float,float,100>,float>);
static_assert(mgb_dsc::polynomial_ring<mgb_dsc::dense_standard_polynomial<double,double,100>,double>);
static_assert(mgb_dsc::polynomial_ring<mgb_dsc::dense_standard_polynomial<long long,long double,100>,long long>);
static_assert(mgb_dsc::polynomial_ring<mgb_dsc::dense_standard_polynomial<long double,long double,100>,long double>);

template mgb_dsc::dense_standard_polynomial<int,float,200> mgb_dsc::operator*<int,float,100,100>(const mgb_dsc::dense_standard_polynomial<int,float,100>&,const mgb_dsc::dense_standard_polynomial<int,float,100>&);
template mgb_dsc::dense_standard_polynomial<float,float,200> mgb_dsc::operator*<float,float,100,100>(const mgb_dsc::dense_standard_polynomial<float,float,100>&,const mgb_dsc::dense_standard_polynomial<float,float,100>&);
template mgb_dsc::dense_standard_polynomial<double,double,200> mgb_dsc::operator*<double,double,100,100>(const mgb_dsc::dense_standard_polynomial<double,double,100>&,const mgb_dsc::dense_standard_polynomial<double,double,100>&);
template mgb_dsc::dense_standard_polynomial<long long,long double,200> mgb_dsc::operator*<long long,long double,100,100>(const mgb_dsc::dense_standard_polynomial<long long,long double,100>&,const mgb_dsc::dense_standard_polynomial<long long,long double,100>&);
template mgb_dsc::dense_standard_polynomial<long double,long double,200> mgb_dsc::operator*<long double,long double,100,100>(const mgb_dsc::dense_standard_polynomial<long double,long double,100>&,const mgb_dsc::dense_standard_polynomial<long double,long double,100>&);

template mgb_dsc::dense_standard_polynomial<int,float,100> mgb_dsc::operator+<int,float,100>(const mgb_dsc::dense_standard_polynomial<int,float,100>&,const mgb_dsc::dense_standard_polynomial<int,float,100>&);
template mgb_dsc::dense_standard_polynomial<float,float,100> mgb_dsc::operator+<float,float,100>(const mgb_dsc::dense_standard_polynomial<float,float,100>&,const mgb_dsc::dense_standard_polynomial<float,float,100>&);
template mgb_dsc::dense_standard_polynomial<double,double,100> mgb_dsc::operator+<double,double,100>(const mgb_dsc::dense_standard_polynomial<double,double,100>&,const mgb_dsc::dense_standard_polynomial<double,double,100>&);
template mgb_dsc::dense_standard_polynomial<long long,long double,100> mgb_dsc::operator+<long long,long double,100>(const mgb_dsc::dense_standard_polynomial<long long,long double,100>&,const mgb_dsc::dense_standard_polynomial<long long,long double,100>&);
template mgb_dsc::dense_standard_polynomial<long double,long double,100> mgb_dsc::operator+<long double,long double,100>(const mgb_dsc::dense_standard_polynomial<long double,long double,100>&,const mgb_dsc::dense_standard_polynomial<long double,long double,100>&);

template mgb_dsc::dense_standard_polynomial<int,float,100> mgb_dsc::operator-<int,float,100>(const mgb_dsc::dense_standard_polynomial<int,float,100>&,const mgb_dsc::dense_standard_polynomial<int,float,100>&);
template mgb_dsc::dense_standard_polynomial<float,float,100> mgb_dsc::operator-<float,float,100>(const mgb_dsc::dense_standard_polynomial<float,float,100>&,const mgb_dsc::dense_standard_polynomial<float,float,100>&);
template mgb_dsc::dense_standard_polynomial<double,double,100> mgb_dsc::operator-<double,double,100>(const mgb_dsc::dense_standard_polynomial<double,double,100>&,const mgb_dsc::dense_standard_polynomial<double,double,100>&);
template mgb_dsc::dense_standard_polynomial<long long,long double,100> mgb_dsc::operator-<long long,long double,100>(const mgb_dsc::dense_standard_polynomial<long long,long double,100>&,const mgb_dsc::dense_standard_polynomial<long long,long double,100>&);
template mgb_dsc::dense_standard_polynomial<long double,long double,100> mgb_dsc::operator-<long double,long double,100>(const mgb_dsc::dense_standard_polynomial<long double,long double,100>&,const mgb_dsc::dense_standard_polynomial<long double,long double,100>&);

template mgb_dsc::dense_standard_polynomial<int,float,100> mgb_dsc::operator*<int,float,100>(const int&,const mgb_dsc::dense_standard_polynomial<int,float,100>&);
template mgb_dsc::dense_standard_polynomial<float,float,100> mgb_dsc::operator*<float,float,100>(const float&,const mgb_dsc::dense_standard_polynomial<float,float,100>&);
template mgb_dsc::dense_standard_polynomial<double,double,100> mgb_dsc::operator*<double,double,100>(const double&,const mgb_dsc::dense_standard_polynomial<double,double,100>&);
template mgb_dsc::dense_standard_polynomial<long long,long double,100> mgb_dsc::operator*<long long,long double,100>(const long long&,const mgb_dsc::dense_standard_polynomial<long long,long double,100>&);
template mgb_dsc::dense_standard_polynomial<long double,long double,100> mgb_dsc::operator*<long double,long double,100>(const long double&,const mgb_dsc::dense_standard_polynomial<long double,long double,100>&);