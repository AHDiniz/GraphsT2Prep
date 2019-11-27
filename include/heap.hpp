#pragma once

#include <cstdlib>
#include <functional>

template<typename T>
static inline void exch(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
class Heap
{
public:
	/**
	 * 1  -> first is more important
	 * 0  -> both are equaly importante
	 * -1 -> second is more important
	*/
	using CompareFnc = std::function<int(const T&, const T&)>&; 
	Heap(int num, CompareFnc compare) : count(0), max(num), compare(compare)
	{
		items = malloc(sizeof(T) * (num + 1));
	}

	~Heap()
	{
		free(items);
		items = nullptr;
		count = max = 0;
	}

	bool add(T item)
	{
		if (count + 1 > max) return false;
		int top = ++count;
		items[top] = item;
		FixUp(top);
	}

	T pop(void)
	{
		if (count - 1 < 0) return nullptr;
		--count;
		exch(items[1], items[count + 1]);
		FixDown(1);
		return result;
	}

	inline T &peek(void) { return items[1]; }

	inline int Count() const { return count; }
	inline bool Empty() const { return count == 0; }
	inline bool Full() const { return count == max; }

private:
	void FixUp(int pos)
	{
		while (pos > 1 && compare(items[pos / 2], items[pos]) == 1)
		{
			exch(items[pos / 2], items[pos]);
			pos /= 2;
		}
	}

	void FixDown(int pos)
	{
		while (2 * pos < count)
		{
			int j = 2 * pos;
			if (j < count && compare(items[j], items[j + 1]) == 1) ++j;
			if (compare(items[pos], items[j]) == 1 || compare(items[pos], items[j]) == 0) break;
			exch(items[pos], items[j]);
			pos = j;
		}
	}

	T *items;
	int count;
	int max;

	CompareFnc compare;
};
