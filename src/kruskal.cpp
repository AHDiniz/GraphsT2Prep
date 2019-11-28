#include "set.hpp"
#include "heap.hpp"
#include "kruskal.hpp"

#include <iostream>

KruskalGraph::KruskalGraph(int n, int m) : Graph(n, m), count(0)
{
	edges.starts = (int *)malloc(sizeof(int) * m);
	edges.ends = (int *)malloc(sizeof(int) * m);
	edges.weights = (int *)malloc(sizeof(int) * m);
}

KruskalGraph::~KruskalGraph()
{
	free(edges.starts);
	free(edges.ends);
	free(edges.weights);
	n = m = 0;
}

int KruskalGraph::compareEdges(edge &a, edge &b)
{
	if (weight(a) == weight(b)) return 0;
	else return (weight(a) > weight(b)) ? 1 : -1;
}

const int *KruskalGraph::get(edge e)
{
	int *result = (int *)malloc(sizeof(int) * 3);
	result[0] = start(e);
	result[1] = end(e);
	result[2] = weight(e);
	return const_cast<const int *>(result);
}

Graph::edge KruskalGraph::set(int n, int m, int c)
{
	edges.starts[count] = n;
	edges.ends[count] = m;
	edges.weights[count] = c;
	return count++;
}

const Graph::edge *KruskalGraph::mst(void)
{
	edge *result = (edge *)malloc(sizeof(edge) * (n - 1));

	Set<edge> *sets = (Set<edge> *)alloca(sizeof(Set<edge>) * n);
	for (int i = 0; i < n; ++i)
	{
		sets[i].init(n);
		sets[i].add(i);
	}

	Heap<edge> heap(m, [this](const edge &u) {
		return weight(u);
	});
	for (int i = 0; i < m; ++i) heap.add(i);

	int count = 0;
	for (int i = 0; i < m && count < (n - 1); ++i)
	{
		edge e = heap.pop();
		int u = start(e), v = end(e);
		if (!(sets[u] == sets[v]))
		{
			result[count++] = e;
			sets[u] += sets[v];
		}
	}

	for (int i = 0; i < n; ++i) sets[i].~Set();

	return result;
}
