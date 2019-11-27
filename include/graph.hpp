#pragma once

class Graph
{
public:
	using edge = int;

	inline Graph(int n, int m) : n(n), m(m){}

	/**
	 * Returns length 3 const array with edge data:
	 * 0 - first vertex
	 * 1 - second vertex
	 * 2 - weight
	*/
	virtual const int *get(edge e) = 0;
	virtual edge set(int n, int m, int c) = 0;
	virtual const edge *mst(void) = 0;

protected:
	virtual int compareEdges(edge &a, edge &b) = 0;
	int n, m;
};