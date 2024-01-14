#include "basic_modulus_equivalence_class.hpp"

template class mgb_dsc::basic_modulus_equivalence_class<int,2>;
template class mgb_dsc::basic_modulus_equivalence_class<int,10>;
template class mgb_dsc::basic_modulus_equivalence_class<int,20>;
template class mgb_dsc::basic_modulus_equivalence_class<int,40>;
template class mgb_dsc::basic_modulus_equivalence_class<int,60>;
template class mgb_dsc::basic_modulus_equivalence_class<int,80>;
template class mgb_dsc::basic_modulus_equivalence_class<int,100>;

static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<int,2>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<int,10>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<int,20>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<int,40>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<int,60>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<int,80>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<int,100>>);

template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<int,2>,int>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<int,10>,int>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<int,20>,int>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<int,40>,int>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<int,60>,int>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<int,80>,int>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<int,100>,int>;

template class mgb_dsc::basic_modulus_equivalence_class<long long,2>;
template class mgb_dsc::basic_modulus_equivalence_class<long long,10>;
template class mgb_dsc::basic_modulus_equivalence_class<long long,20>;
template class mgb_dsc::basic_modulus_equivalence_class<long long,40>;
template class mgb_dsc::basic_modulus_equivalence_class<long long,60>;
template class mgb_dsc::basic_modulus_equivalence_class<long long,80>;
template class mgb_dsc::basic_modulus_equivalence_class<long long,100>;

static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<long long,2>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<long long,10>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<long long,20>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<long long,40>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<long long,60>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<long long,80>>);
static_assert(mgb_dsc::modulus<mgb_dsc::basic_modulus_equivalence_class<long long,100>>);

template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<long long,2>,long long>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<long long,10>,long long>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<long long,20>,long long>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<long long,40>,long long>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<long long,60>,long long>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<long long,80>,long long>;
template class mgb_dsc::crtp_modulus_equivalence_class_interface<mgb_dsc::basic_modulus_equivalence_class<long long,100>,long long>;