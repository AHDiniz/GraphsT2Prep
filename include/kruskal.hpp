#pragma once

#include "graph.hpp"

class KruskalGraph : public Graph
{
public:
    using edge = int;

    KruskalGraph(int n, int m);
    ~KruskalGraph();

    const int *get(edge e) override;
    edge set(int n, int m, int c) override;
    const edge *mst(void) override;

    inline int weight(edge a) const { return edges.weights[a]; }
    inline int start(edge a) const { return edges.starts[a]; }
    inline int end(edge a) const { return edges.ends[a]; }

private:
    int compareEdges(edge &u, edge &v) override;

    struct EdgeData
    {
        int *starts;
        int *ends;
        int *weights;
    };
    EdgeData edges;
    int count;
};
