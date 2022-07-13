//
// Created by 董子雄 on 2021/8/2.
//

#ifndef CPP_FEATURE_TEST_GRAPH_H
#define CPP_FEATURE_TEST_GRAPH_H

#include <vector>
#include "graph.h"
#include "utils/print.h"

namespace algorithms {

using util::print;

void main() {
    Graph graph;
    print("add_vertex: \n", graph.add_vertex(0));
    print(graph.add_vertex(1));
    print(graph.add_vertex(2));
    print(graph.add_vertex(3));
    print(graph.add_vertex(4));
    print(graph.add_vertex(5));
    print("add_edge: \n", graph.add_edge(3, 5));
    print(graph.add_edge(3, 4));
    print(graph.add_edge(1, 2));
    print(graph.add_edge(1, 3));
    print(graph.add_edge(2, 5));
    print(graph.add_edge(5, 0));
    print("num_vertex: ", graph.num_vertex());
    auto source_vetexes = graph.source_vetexes();
    print("source_vetexes");
    for (const auto& item : source_vetexes) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    print("_vetexes");
    auto sink_vetexes = graph.sink_vetexes();
    for (const auto& item : sink_vetexes) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

}

#endif //CPP_FEATURE_TEST_GRAPH_H
