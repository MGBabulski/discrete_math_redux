#include "catalan_number.hpp"

template struct mgb_dsc::catalan<unsigned long long>;

template struct mgb_dsc::catalan<unsigned long long>::number<0,true>;
template struct mgb_dsc::catalan<unsigned long long>::number<1,true>;
template struct mgb_dsc::catalan<unsigned long long>::number<7,true>;
template struct mgb_dsc::catalan<unsigned long long>::number<10,true>;
template struct mgb_dsc::catalan<unsigned long long>::number<20,true>;

static_assert(mgb_dsc::catalan<unsigned long long>::number<0,true>::value == 1);
static_assert(mgb_dsc::catalan<unsigned long long>::number<1,true>::value == 1);
static_assert(mgb_dsc::catalan<unsigned long long>::number<7,true>::value == 429);
static_assert(mgb_dsc::catalan<unsigned long long>::number<10,true>::value == 16796);
static_assert(mgb_dsc::catalan<unsigned long long>::number<20,true>::value == 6564120420);

static_assert(mgb_dsc::catalan_number<unsigned int,7>::value == 429);

static_assert(mgb_dsc::catalan_number_v<unsigned int,10> == 16796);