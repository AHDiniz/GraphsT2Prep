#include <iostream>
#include <fstream>
#include <cstdlib>
#include "kruskal.hpp"

int main(int argc, char *argv[])
{
	std::ifstream f(argv[1]);

	int n, m;
	f >> n >> m;

	KruskalGraph graph(n, m);

	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		f >> u >> v >> w;
		graph.set(u, v, w);
	}

	const Graph::edge *edges = graph.mst();

	std::cout << "Minimal spanning tree:" << std::endl;
	for (KruskalGraph::edge j = 0; j < n - 1; ++j)
	{
		KruskalGraph::edge e = edges[j];
		std::cout << "#" << e << " (" << graph.start(e) << ", " << graph.end(e) << ") -> " << graph.weight(e) << ";" << std::endl;
	}

	return EXIT_SUCCESS;
}