//g++ test2.cpp -o a -std=c++23 -Wall -Wextra -pedantic
#include <iostream>
#include "../src/graph/dense_standard_graph.hpp"
#include "../src/graph/sparse_standard_graph.hpp"
#include "../src/graph/graph_algorithms.hpp"

using namespace std;

template <typename graph_type, typename vertex_type, typename container>
void process (mgb_dsc::crtp_graph_interface<graph_type,vertex_type,container> &g)
{
    cout << "======================\n";
    g.awaken(14);
    for (std::size_t i = 0; i < 10; i++)
    {
        g.insert_edge(i,i+1);
    }
    auto x = [i = 0](std::size_t v) mutable {cout << "vertex " << i++ << " : " << v << "\n";};
    cout << g.is_edge(7,8) << " " << g.is_edge(8,7) << "\n";
    mgb_dsc::apply_bfs(x,g,(std::size_t)1);
    g.prune(3);
    cout << "\n";
    mgb_dsc::apply_dfs(x,g,(std::size_t)1);
    cout << "\n";
    mgb_dsc::apply_dfs(x,g,(std::size_t)5);
    g.clear();
    cout << "\n" << g.get_vertices().empty() << "\n";
    cout << "======================\n";
}

int main ()
{
    //for both dense and sparse
    auto g1 = mgb_dsc::dense_standard_graph<17>();
    auto g2 = mgb_dsc::dense_standard_graph<17>();
    //crtp makes interfacing easy
    process(g1);
    process(g2);
    return 0;
}