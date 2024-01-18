#pragma once

#include "graph_utilities.hpp"
#include <array>

namespace mgb_dsc
{
    /**
     * The class represents basic directed mathematical graph (V,E), where connections are dense
     * @param vertex_number number of verticies
     * @note if vertex_number is 0, the behavior is undefined
    */
    template <std::size_t vertex_number>
    class dense_standarg_graph : public crtp_graph_interface<dense_standarg_graph<vertex_number>,std::size_t>
    {
    private:
        std::array<std::array<bool,vertex_number>,vertex_number> adj_list = std::array<std::array<bool,vertex_number>,vertex_number>();
        std::array<bool,vertex_number> check_list = std::array<bool,vertex_number>();
    public:
        /**
         * @returns list of verticies
        */
        constexpr std::list<std::size_t> get_verticies () const noexcept
        {
            auto l = std::list<std::size_t>();
            for (std::size_t i = 0; i < vertex_number; i++)
            {
                if (check_list[i])
                {
                    l.push_back(i);
                }
            }
            return l;
        }
        /**
         * @param v vertex
         * @returns list with all verticies adjacent to vertex v if v is a valid vertex, empty list otherwise
        */
        constexpr std::list<std::size_t> get_adjacent (const std::size_t &v) const noexcept
        {
            if (v >= vertex_number)
            {
                return std::list<std::size_t>{};
            }
            auto l = std::list<std::size_t>();
            for (std::size_t i = 0; i < vertex_number; i++)
            {
                if (adj_list[v][i] == true)
                {
                    l.push_back(i);
                }
            }
            return l;
        }
        /**
         * @param v vertex, that represents v in edge (v,u)
         * @param u vertex, that represents u in edge (v,u)
         * @returns true if (v,u) is an existing edge in the graph, false otherwise
        */
        constexpr bool is_edge (const std::size_t &v, const std::size_t &u) const noexcept
        {
            if (v >= vertex_number || u >= vertex_number)
            {
                return false;
            }
            return adj_list[v][u];
        }
        /**
         * The method adds vertex v to used verticies
         * @note the method does not add edge (v,v) to the graph
         * @param v vertex to be added
         * @returns true if the vertex was added, false otherwise
        */
        constexpr bool awaken (const std::size_t &v) noexcept
        {
            if (v >= vertex_number)
            {
                return false;
            }
            check_list[v] = true;
            return true;
        }
        /**
         * The method inserts edge (v,u) to the graph
         * @param v vertex, that represents v in edge (v,u)
         * @param u vertex, that represents u in edge (v,u)
         * @returns true if edge (v,u) was inserted, false otherwise
        */
        constexpr bool insert_edge (const std::size_t &v, const std::size_t &u) noexcept
        {
            if (v >= vertex_number || u >= vertex_number)
            {
                return false;
            }
            adj_list[v][u] = true;
            check_list[v] = true;
            check_list[u] = true;
            return true;
        }
        /**
         * The method removes edge (v,u) from the graph
         * @param v vertex, that represents v in edge (v,u)
         * @param u vertex, that represents u in edge (v,u)
         * @returns true if edge (v,u) was removed, false otherwise
        */
        constexpr bool remove_edge (const std::size_t &v, const std::size_t &u) noexcept
        {
            if (v >= vertex_number || u >= vertex_number)
            {
                return false;
            }
            adj_list[v][u] = false;
            return true;
        }
        /**
         * clears the graph
        */
        constexpr void clear () noexcept
        {
            adj_list = std::array<std::array<bool,vertex_number>,vertex_number>();
            check_list.fill(false);
        }
        /**
         * The method prunes all adjacent edges of vertex v form the graph
         * @note the vertex v and all edges pointing to it remain after operation
         * @returns true if vertex was successfully removed from the graph, false otherwise
        */
        constexpr bool prune (const std::size_t &v) noexcept
        {
            if (v >= vertex_number)
            {
                return false;
            }
            adj_list[v].fill(false);
            return true;
        }
    };
}