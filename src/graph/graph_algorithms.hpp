#pragma once

#include "graph_utilities.hpp"
#include <stack>
#include <queue>

namespace mgb_dsc
{
    /**
     * Forwards vertices to the functor in dfs order
     * @note may not travel the entire graph
     * @param f functor for vertices to be forwarded to
     * @param g graph to be checked
     * @param first vertex that serves as a starting point
    */
    template <typename functor_type, typename graph_type, typename vertex_type, container_type container = std::list<vertex_type>>
    constexpr void apply_dfs (functor_type f, const crtp_graph_interface<graph_type,vertex_type,container> &g, const vertex_type &first) noexcept
    {
        auto st = std::stack<vertex_type>();
        st.push(first);
        while (!st.empty())
        {
            vertex_type v = st.top();
            st.pop();
            for (const auto &i : g.get_adjacent(v))
            {
                st.push(i);
            }
            f(v);
        }
    }
    
    /**
     * Forwards vertices to the functor in bfs order
     * @note may not travel the entire graph
     * @param f functor for vertices to be forwarded to
     * @param g graph to be checked
     * @param first vertex that serves as a starting point
    */
    template <typename functor_type, typename graph_type, typename vertex_type, container_type container = std::list<vertex_type>>
    constexpr void apply_bfs (functor_type f, const crtp_graph_interface<graph_type,vertex_type,container> &g, const vertex_type &first) noexcept
    {
        auto q = std::queue<vertex_type>();
        q.push(first);
        while (!q.empty())
        {
            vertex_type v = q.front();
            q.pop();
            for (const auto &i : g.get_adjacent(v))
            {
                q.push(i);
            }
            f(v);
        }
    }
}