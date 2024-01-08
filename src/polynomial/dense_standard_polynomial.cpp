#include "dense_standard_polynomial.hpp"

template class mgb_dsc::dense_standard_polynomial<int,float,100>;
template class mgb_dsc::dense_standard_polynomial<float,float,100>;
template class mgb_dsc::dense_standard_polynomial<double,double,100>;
template class mgb_dsc::dense_standard_polynomial<long long,long double, 100>;
template class mgb_dsc::dense_standard_polynomial<long double,long double,100>;

static_assert(mgb_dsc::polynomial_ring<mgb_dsc::dense_standard_polynomial<int,float,100>,int>);

template mgb_dsc::dense_standard_polynomial<int,float,200> mgb_dsc::operator*<int,float,100,100>(const mgb_dsc::dense_standard_polynomial<int,float,100>&,const mgb_dsc::dense_standard_polynomial<int,float,100>&) noexcept;