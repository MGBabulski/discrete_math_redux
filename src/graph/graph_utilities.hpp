#pragma once

#include <concepts>
#include <list>

namespace mgb_dsc
{
    /**
     * Concept used to check if a given type behives well enough for my algorithms to be considered a container
     * @note the checks roughly follow https://en.cppreference.com/w/cpp/named_req/Container and the type should be implemented as such, although it obviously doesn't check everything
     * @param type type to be checked
    */
    template <typename type>
    concept container_type = 
        //typedefs
        requires
        {
            typename type::iterator;
            typename type::const_iterator;
            typename type::value_type;
            typename type::reference;
            typename type::difference_type;
            typename type::size_type;
        }
        //construction
        && std::is_default_constructible_v<type> 
        && std::is_copy_constructible_v<type>
        && std::is_copy_assignable_v<type>
        && std::is_move_constructible_v<type>
        && std::is_move_assignable_v<type>
        && std::is_destructible_v<type>
        //operators
        && requires (type a, type b)
        {
            {a == b} -> std::convertible_to<bool>;
            {a != b} -> std::convertible_to<bool>;
        }
        //iterators
        && requires (type t)
        {
            {t.begin()} -> std::same_as<typename type::iterator>;
            {t.end()} -> std::same_as<typename type::iterator>;
            {t.cbegin()} -> std::same_as<typename type::const_iterator>;
            {t.cend()} -> std::same_as<typename type::const_iterator>;
        }
        //member functions
        && requires (type t)
        {
            {t.size()} -> std::same_as<typename type::size_type>;
            {t.max_size()} -> std::same_as<typename type::size_type>;
            {t.empty()} -> std::convertible_to<bool>;
        };

    /**
     * Interface (as crtp) used to describe a directed mathematical graph (V,E)
     * @param graph_type type used to describe an undirected mathematical graph (V,E)
     * @param vertex_type fully ordered type used to represent vericies and differentiate between them
     * @param container type used as a vertex container that satisfies container_type concept
    */
    template <typename graph_type, typename vertex_type, container_type container = std::list<vertex_type>> requires std::totally_ordered<vertex_type>
    class crtp_graph_interface
    {
    private:
        //this will yield error during compilation if you give wrong (non crtp-like) polynomial_type
        crtp_graph_interface () = default;
        friend graph_type;
        /**
         * The methods cast "this" object to a graph_type reference for crtp purposes
         * @returns graph_type&, which basically is the derived class 
        */
        constexpr graph_type& cast_reference () noexcept
        {
            return static_cast<graph_type&>(*this);
        }
        constexpr const graph_type& cast_reference () const noexcept
        {
            return static_cast<const graph_type&>(*this);
        }
    public:
        /**
         * The method gives the list of used verticies
         * @returns container_type container with all of the used verticies
        */
        constexpr container get_verticies () const noexcept
        {
            return this->cast_reference().get_verticies();
        }
        /**
         * The method gives the list of adjacent verticies of a given vertex
         * @note returns an empty container if vertex is invalid
         * @param v vertex
         * @returns container_type container with all verticies adjacent to vertex v
        */
        constexpr container get_adjacent (const vertex_type &v) const noexcept
        {
            return this->cast_reference().get_adjacent(v);
        }
        /**
         * The method checks if the second vertex is adjacent to the first
         * @param v vertex, that represents v in edge (v,u)
         * @param u vertex, that represents u in edge (v,u)
         * @returns true if (v,u) is an existing edge in the graph, false otherwise
        */
        constexpr bool is_edge (const vertex_type &v, const vertex_type &u) const noexcept
        {
            return this->cast_reference().is_edge(v,u);
        }
        /**
         * The method adds vertex v to used verticies
         * @note the method does not add edge (v,v) to the graph
         * @param v vertex to be added
         * @returns true if the vertex was added, false otherwise
        */
        constexpr bool awaken (const vertex_type &v) noexcept
        {
            return this->cast_reference().awaken(v);
        }
        /**
         * The method inserts edge (v,u) to the graph
         * @param v vertex, that represents v in edge (v,u)
         * @param u vertex, that represents u in edge (v,u)
         * @returns true if edge (v,u) was inserted, false otherwise
        */
        constexpr bool insert_edge (const vertex_type &v, const vertex_type &u) noexcept
        {
            return this->cast_reference().insert_edge(v,u);
        }
        /**
         * The method removes edge (v,u) from the graph
         * @param v vertex, that represents v in edge (v,u)
         * @param u vertex, that represents u in edge (v,u)
         * @returns true if edge (v,u) was removed, false otherwise
        */
        constexpr bool remove_edge (const vertex_type &v, const vertex_type &u) noexcept
        {
            return this->cast_reference().remove_edge(v,u);
        }
        /**
         * The method clears the entire graph (that is all used verticies and edges)
        */
        constexpr void clear () noexcept
        {
            this->cast_reference().clear();
        }
        /**
         * The method prunes all adjacent edges of vertex v form the graph
         * @note the vertex v and all edges pointing to it remain after operation
         * @returns true if vertex was successfully removed from the graph, false otherwise
        */
        constexpr bool prune (const vertex_type &v) noexcept
        {
            return this->cast_reference().prune(v);
        }
    };
}