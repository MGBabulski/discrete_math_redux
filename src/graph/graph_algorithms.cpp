#include "graph_algorithms.hpp"
#include "sparse_standard_graph.hpp"
#include "dense_standard_graph.hpp"
#include <functional>

template void mgb_dsc::apply_bfs<std::function<void(std::size_t)>,mgb_dsc::dense_standard_graph<77>,std::size_t> (std::function<void(std::size_t)>,const mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standard_graph<77>,std::size_t>&,const std::size_t&);


template void mgb_dsc::apply_dfs<std::function<void(std::size_t)>,mgb_dsc::dense_standard_graph<77>,std::size_t> (std::function<void(std::size_t)>,const mgb_dsc::crtp_graph_interface<mgb_dsc::dense_standard_graph<77>,std::size_t>&,const std::size_t&);