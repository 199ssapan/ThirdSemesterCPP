#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

int main() {
    using namespace boost;

    typedef adjacency_list<vecS, vecS, directedS, no_property, property<edge_weight_t, int>> Graph;
    typedef graph_traits<Graph>::vertex_descriptor Vertex;

    Graph g(10);

    add_edge(0, 1, 3, g);
    add_edge(0, 2, 4, g);
    add_edge(0, 3, 2, g);
    add_edge(1, 4, 3, g);
    add_edge(2, 4, 6, g);
    add_edge(3, 4, 3, g);
    add_edge(3, 5, 1, g);
    add_edge(4, 5, 1, g);
    add_edge(4, 6, 8, g);
    add_edge(4, 8, 7, g);
    add_edge(5, 7, 12, g);
    add_edge(5, 6, 6, g);
    add_edge(7, 8, 6, g);
    add_edge(6, 9, 14, g);
    add_edge(8, 9, 3, g);
    add_edge(7, 9, 11, g);

    std::vector<int> distances(num_vertices(g));
    std::vector<Vertex> parents(num_vertices(g));

    dijkstra_shortest_paths(g, vertex(0, g), distance_map(make_iterator_property_map(distances.begin(), get(vertex_index, g)))
        .predecessor_map(make_iterator_property_map(parents.begin(), get(vertex_index, g))));

    for (int i = 0; i < distances.size(); ++i) {
        std::cout << "Shortest distance from vertex 0 to vertex " << i << ": " << distances[i] << std::endl;
    }

    return 0;
}
