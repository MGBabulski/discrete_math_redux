#include "sparse_standard_polynomial.hpp"

template class mgb_dsc::sparse_standard_polynomial<int,float>;
template class mgb_dsc::sparse_standard_polynomial<float,float>;
template class mgb_dsc::sparse_standard_polynomial<double,double>;
template class mgb_dsc::sparse_standard_polynomial<long long,long double>;
template class mgb_dsc::sparse_standard_polynomial<long double,long double>;

static_assert(mgb_dsc::polynomial_ring<mgb_dsc::sparse_standard_polynomial<int,float>,int>);
static_assert(mgb_dsc::polynomial_ring<mgb_dsc::sparse_standard_polynomial<float,float>,float>);
static_assert(mgb_dsc::polynomial_ring<mgb_dsc::sparse_standard_polynomial<double,double>,double>);
static_assert(mgb_dsc::polynomial_ring<mgb_dsc::sparse_standard_polynomial<long long,long long>,long long>);
static_assert(mgb_dsc::polynomial_ring<mgb_dsc::sparse_standard_polynomial<long double,long double>,long double>);

template mgb_dsc::sparse_standard_polynomial<int,float> mgb_dsc::operator+<int,float>(const mgb_dsc::sparse_standard_polynomial<int,float>&,const mgb_dsc::sparse_standard_polynomial<int,float>&);
template mgb_dsc::sparse_standard_polynomial<float,float> mgb_dsc::operator+<float,float>(const mgb_dsc::sparse_standard_polynomial<float,float>&,const mgb_dsc::sparse_standard_polynomial<float,float>&);
template mgb_dsc::sparse_standard_polynomial<double,double> mgb_dsc::operator+<double,double>(const mgb_dsc::sparse_standard_polynomial<double,double>&,const mgb_dsc::sparse_standard_polynomial<double,double>&);
template mgb_dsc::sparse_standard_polynomial<long long,long double> mgb_dsc::operator+<long long,long double>(const mgb_dsc::sparse_standard_polynomial<long long,long double>&,const mgb_dsc::sparse_standard_polynomial<long long,long double>&);
template mgb_dsc::sparse_standard_polynomial<long double,long double> mgb_dsc::operator+<long double,long double>(const mgb_dsc::sparse_standard_polynomial<long double,long double>&,const mgb_dsc::sparse_standard_polynomial<long double,long double>&);

template mgb_dsc::sparse_standard_polynomial<int,float> mgb_dsc::operator-<int,float>(const mgb_dsc::sparse_standard_polynomial<int,float>&,const mgb_dsc::sparse_standard_polynomial<int,float>&);
template mgb_dsc::sparse_standard_polynomial<float,float> mgb_dsc::operator-<float,float>(const mgb_dsc::sparse_standard_polynomial<float,float>&,const mgb_dsc::sparse_standard_polynomial<float,float>&);
template mgb_dsc::sparse_standard_polynomial<double,double> mgb_dsc::operator-<double,double>(const mgb_dsc::sparse_standard_polynomial<double,double>&,const mgb_dsc::sparse_standard_polynomial<double,double>&);
template mgb_dsc::sparse_standard_polynomial<long long,long double> mgb_dsc::operator-<long long,long double>(const mgb_dsc::sparse_standard_polynomial<long long,long double>&,const mgb_dsc::sparse_standard_polynomial<long long,long double>&);
template mgb_dsc::sparse_standard_polynomial<long double,long double> mgb_dsc::operator-<long double,long double>(const mgb_dsc::sparse_standard_polynomial<long double,long double>&,const mgb_dsc::sparse_standard_polynomial<long double,long double>&);

template mgb_dsc::sparse_standard_polynomial<int,float> mgb_dsc::operator*<int,float>(const mgb_dsc::sparse_standard_polynomial<int,float>&,const mgb_dsc::sparse_standard_polynomial<int,float>&);
template mgb_dsc::sparse_standard_polynomial<float,float> mgb_dsc::operator*<float,float>(const mgb_dsc::sparse_standard_polynomial<float,float>&,const mgb_dsc::sparse_standard_polynomial<float,float>&);
template mgb_dsc::sparse_standard_polynomial<double,double> mgb_dsc::operator*<double,double>(const mgb_dsc::sparse_standard_polynomial<double,double>&,const mgb_dsc::sparse_standard_polynomial<double,double>&);
template mgb_dsc::sparse_standard_polynomial<long long,long double> mgb_dsc::operator*<long long,long double>(const mgb_dsc::sparse_standard_polynomial<long long,long double>&,const mgb_dsc::sparse_standard_polynomial<long long,long double>&);
template mgb_dsc::sparse_standard_polynomial<long double,long double> mgb_dsc::operator*<long double,long double>(const mgb_dsc::sparse_standard_polynomial<long double,long double>&,const mgb_dsc::sparse_standard_polynomial<long double,long double>&);

template mgb_dsc::sparse_standard_polynomial<int,float> mgb_dsc::operator*<int,float>(const int&,const mgb_dsc::sparse_standard_polynomial<int,float>&);
template mgb_dsc::sparse_standard_polynomial<float,float> mgb_dsc::operator*<float,float>(const float&,const mgb_dsc::sparse_standard_polynomial<float,float>&);
template mgb_dsc::sparse_standard_polynomial<double,double> mgb_dsc::operator*<double,double>(const double&,const mgb_dsc::sparse_standard_polynomial<double,double>&);
template mgb_dsc::sparse_standard_polynomial<long long,long double> mgb_dsc::operator*<long long,long double>(const long long&,const mgb_dsc::sparse_standard_polynomial<long long,long double>&);
template mgb_dsc::sparse_standard_polynomial<long double,long double> mgb_dsc::operator*<long double,long double>(const long double&,const mgb_dsc::sparse_standard_polynomial<long double,long double>&);
