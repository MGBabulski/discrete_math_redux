#include "binomial_coefficient.hpp"

template struct mgb_dsc::binomial<unsigned long long>;

template struct mgb_dsc::binomial<unsigned long long>::coefficient<190,7>;
template struct mgb_dsc::binomial<unsigned long long>::coefficient<77,7>;
template struct mgb_dsc::binomial<unsigned long long>::coefficient<23,7>;
template struct mgb_dsc::binomial<unsigned long long>::coefficient<40,17>;
template struct mgb_dsc::binomial<unsigned long long>::coefficient<60,48>;
template struct mgb_dsc::binomial<unsigned long long>::coefficient<7,7>;

static_assert(mgb_dsc::binomial<unsigned long long>::coefficient<190,7>::value == 1585940245560);
static_assert(mgb_dsc::binomial<unsigned long long>::coefficient<77,7>::value == 2404808340);
static_assert(mgb_dsc::binomial<unsigned long long>::coefficient<23,7>::value == 245157);
static_assert(mgb_dsc::binomial<unsigned long long>::coefficient<40,17>::value == 88732378800);
static_assert(mgb_dsc::binomial<unsigned long long>::coefficient<60,48>::value == 1399358844975);
static_assert(mgb_dsc::binomial<unsigned long long>::coefficient<7,7>::value == 1);

static_assert(mgb_dsc::binomial_coefficient<unsigned int,23,7>::value == 245157);

static_assert(mgb_dsc::binomial_coefficient_v<unsigned int,77,7> == 2404808340);