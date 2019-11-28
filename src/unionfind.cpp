#include "unionfind.hpp"

#include <cstdlib>

UnionFind::UnionFind(int items) : count(items)
{
	this->items = (int *)malloc(sizeof(int) * items);
	for (int i = 0; i < count; ++i)
		this->items[i] = i;
}

UnionFind::~UnionFind()
{
	free(items);
	items = nullptr;
	count = 0;
}

int UnionFind::find(int a) const
{
	return items[a];
}

void UnionFind::connect(int a, int b)
{
	items[b] = items[a];
}
