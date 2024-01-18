#include "dense_standard_graph.hpp"

template class mgb_dsc::dense_standarg_graph<10>;
template class mgb_dsc::dense_standarg_graph<20>;
template class mgb_dsc::dense_standarg_graph<30>;
template class mgb_dsc::dense_standarg_graph<40>;
template class mgb_dsc::dense_standarg_graph<50>;
template class mgb_dsc::dense_standarg_graph<60>;
template class mgb_dsc::dense_standarg_graph<70>;
template class mgb_dsc::dense_standarg_graph<80>;
template class mgb_dsc::dense_standarg_graph<90>;
template class mgb_dsc::dense_standarg_graph<100>;

template class mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standarg_graph<10>,std::size_t>;
template class mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standarg_graph<20>,std::size_t>;
template class mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standarg_graph<30>,std::size_t>;
template class mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standarg_graph<40>,std::size_t>;
template class mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standarg_graph<50>,std::size_t>;
template class mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standarg_graph<60>,std::size_t>;
template class mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standarg_graph<70>,std::size_t>;
template class mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standarg_graph<80>,std::size_t>;
template class mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standarg_graph<90>,std::size_t>;
template class mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standarg_graph<100>,std::size_t>;

static_assert(mgb_dsc::container_type<std::list<std::size_t>>);