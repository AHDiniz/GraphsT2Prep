#include "utils.hpp"
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
	else (weight(a) > weight(b)) ? 1 : -1;
}

const int *KruskalGraph::get(edge e)
{
	const int result[3] = { start(e), end(e), weight(e) };
	return result;
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
	int *sets = (int *)malloc(sizeof(int) * n * n);
	for (int i = 0; i < n * n; ++i) sets[i] = 0;

	std::function<int(const edge&, const edge&)> func =
	[this](const edge &u, const edge &v) {
		if (weight(u) == weight(v)) return 0;
		else (weight(u) > weight(v)) ? 1 : -1;
	};

	Heap<edge> heap(m, func);
	for (int i = 0; i < m; ++i) heap.add(i);

	int count = 0;
	for (int i = 0; i < m && count < (n - 1); ++i)
	{
		edge e = heap.pop();
		int u = start(e), v = end(e);
		if (!compareSetArrays(&sets[u * n + 1], sets[u * n], &sets[v * n + 1], sets[v * n]))
		{
			std::cout << e << std::endl;
			result[count] = e;
			++count;
			mergeSetArrays(&sets[u * n + 1], sets[u * n], &sets[v * n + 1], sets[v * n]);
		}
	}

	return result;
}
