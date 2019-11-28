#ifndef SET_H_

#define SET_H_

#include <cstdlib>

template<typename T>
class Set
{
public:
	inline Set() : count(0){}

	inline void init(size_t numItems)
	{
		max = numItems;
		items = (T *)malloc(sizeof(T) * numItems);
	}

	inline ~Set()
	{
		free(items);
		items = nullptr;
		max = count = 0;
	}

	bool add(T item)
	{
		if (count >= max) return false;
		items[count++] = item;
		return true;
	}

	bool remove(T item)
	{
		if (count <= 0) return false;
		--count;
		return true;
	}

	bool contains(T item)
	{
		for (int i = 0; i < count; ++i)
			if (items[i] == item) return true;
		return false;
	}

	void operator += (const Set &other)
	{
		for (int i = 0; add(other.items[i]); ++i);
	}

	bool operator == (const Set &other)
	{
		if (count != other.count) return false;
		int i;
		for (i = 0; contains(other.items[i]); ++i);
		return i == count;
	}

private:
	T *items;
	int count;
	int max;
};

#endif
