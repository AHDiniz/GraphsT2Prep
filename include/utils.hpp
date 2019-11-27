#pragma once

template<typename T>
inline bool compareSetArrays(const T *a, const int ac, const T *b, const int bc)
{
	if (ac != bc) return false;
	for (int i = 0; i < ac; ++i)
	{
		bool isIn = false;
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
	return true;
}

template<typename T>
inline void mergeSetArrays(T *a, int &ac, const T *b, const int &bc)
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
}
