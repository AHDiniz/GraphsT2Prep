#ifndef HEAP_H_

#define HEAP_H_

#include <cmath>
#include <cstdlib>
#include <iostream>
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
	using PriorityFnc = std::function<int(const T&)>; 
	Heap(int num, PriorityFnc priority) : count(0), max(num), priority(priority)
	{
		items = (T *)malloc(sizeof(T) * (num + 1));
	}

	~Heap()
	{
		free(items);
		items = nullptr;
		count = max = 0;
	}

	bool add(T item)
	{
		int top = ++count;
		if (top > max)
		{
			count--;
			return false;
		}
		items[top] = item;
		FixUp(top);
		return true;
	}

	T pop(void)
	{
		print();

		if (count - 1 < 0) return items[0];
		--count;
		T result = items[1];
		exch(items[1], items[count + 1]);
		FixDown(1);

		print();

		return result;
	}

	void print(void)
	{
		std::cout << "Heap: (count = " << count << ")" << std::endl;
		int level = 0;
		for (int i = 1; i <= count; ++i)
		{
			if (i == pow(2, level + 1))
			{
				++level;
				std::cout << std::endl;
			}
			std::cout << "(" << items[i] << ", " << priority(items[i]) << ") ";
		}
		std::cout << std::endl;
	}

	inline T &peek(void) { return items[1]; }

	inline int Count() const { return count; }
	inline bool Empty() const { return count == 0; }
	inline bool Full() const { return count == max; }

private:
	void FixUp(int pos)
	{
		while (pos > 1 && priority(items[pos / 2]) > priority(items[pos]))
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
			if (j < count && priority(items[j]) > priority(items[j + 1])) ++j;
			if (priority(items[pos]) <= priority(items[j])) break;
			exch(items[pos], items[j]);
			pos = j;
		}
	}

	T *items;
	int count;
	int max;

	PriorityFnc priority;
};

#endif
