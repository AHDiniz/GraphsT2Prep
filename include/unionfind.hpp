#ifndef UNION_FIND_H_

#define UNION_FIND_H_

class UnionFind
{
public:
	UnionFind(int items);
	~UnionFind();

	int find(int a) const;
	void connect(int a, int b);

private:
	int *items;
	int count;
};

#endif
