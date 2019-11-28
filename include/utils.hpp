#pragma once

template<typename T>
inline bool compareSetArrays(const T *a, const int ac, const int idA, const T *b, const int bc, const int idB)
{
	if (ac != bc) return false;
	bool isIn = false;
	for (int i = 0; i < ac; ++i)
	{
		for (int j = 0; j < bc; ++j)
		{
			if (a[i] == b[j])
			{
				isIn = true;
				break;
			}
		}
		if (!isIn) return false;
	}
	for (int i = 0; i < bc; ++i)
	{
		if (b[i] == idA)
		{
			isIn = true;
			break;
		}
		if (!isIn) return false;
	}
	for (int i = 0; i < ac; ++i)
	{
		if (a[i] == idB)
		{
			isIn = true;
			break;
		}
		if (!isIn) return false;
	}
	return true;
}

template<typename T>
inline void mergeSetArrays(T *a, int &ac, const T *b, const int &bc, const int idB)
{
	for (int i = 0; i < bc; ++i)
	{
		bool isIn = false;
		for (int j = 0; j < ac; ++j)
		{
			if (b[i] == a[j])
			{
				isIn = true;
				break;
			}
		}
		if (!isIn)
		{
			a[ac++] = b[i];
		}
	}
	a[ac++] = idB;
}
