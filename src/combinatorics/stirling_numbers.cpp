#include "stirling_numbers.hpp"

template struct mgb_dsc::stirling<unsigned long long>;

template struct mgb_dsc::stirling<unsigned long long>::first_kind<0,0>;
template struct mgb_dsc::stirling<unsigned long long>::first_kind<7,7>;
template struct mgb_dsc::stirling<unsigned long long>::first_kind<1,1>;
template struct mgb_dsc::stirling<unsigned long long>::first_kind<7,0>;
template struct mgb_dsc::stirling<unsigned long long>::first_kind<9,5>;
template struct mgb_dsc::stirling<unsigned long long>::first_kind<9,7>;

static_assert(mgb_dsc::stirling<unsigned long long>::first_kind<0,0>::value == 1);
static_assert(mgb_dsc::stirling<unsigned long long>::first_kind<7,7>::value == 1);
static_assert(mgb_dsc::stirling<unsigned long long>::first_kind<1,1>::value == 1);
static_assert(mgb_dsc::stirling<unsigned long long>::first_kind<7,0>::value == 0);
static_assert(mgb_dsc::stirling<unsigned long long>::first_kind<9,5>::value == 22449);
static_assert(mgb_dsc::stirling<unsigned long long>::first_kind<9,7>::value == 546);

static_assert(mgb_dsc::stirling_first_kind<unsigned int,9,7>::value == 546);

static_assert(mgb_dsc::stirling_first_kind_v<unsigned int,9,5> == 22449);

template struct mgb_dsc::stirling<unsigned long long>::second_kind<0,0>;
template struct mgb_dsc::stirling<unsigned long long>::second_kind<7,7>;
template struct mgb_dsc::stirling<unsigned long long>::second_kind<1,1>;
template struct mgb_dsc::stirling<unsigned long long>::second_kind<7,0>;
template struct mgb_dsc::stirling<unsigned long long>::second_kind<9,5>;
template struct mgb_dsc::stirling<unsigned long long>::second_kind<9,7>;

static_assert(mgb_dsc::stirling<unsigned long long>::second_kind<0,0>::value == 1);
static_assert(mgb_dsc::stirling<unsigned long long>::second_kind<7,7>::value == 1);
static_assert(mgb_dsc::stirling<unsigned long long>::second_kind<1,1>::value == 1);
static_assert(mgb_dsc::stirling<unsigned long long>::second_kind<7,0>::value == 0);
static_assert(mgb_dsc::stirling<unsigned long long>::second_kind<9,5>::value == 6951);
static_assert(mgb_dsc::stirling<unsigned long long>::second_kind<9,7>::value == 462);

static_assert(mgb_dsc::stirling_second_kind<unsigned int,9,7>::value == 462);

static_assert(mgb_dsc::stirling_second_kind_v<unsigned int,9,5> == 6951);