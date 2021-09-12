#pragma once

#include <vector>
#include <algorithm>

template<typename T>
bool IsSameVector(const std::vector<T> &vector1, const std::vector<T> &vector2, bool orderMatters)
{
	if (orderMatters) {
		return (vector1 == vector2);
	}

	auto newVector1(vector1), newVector2(vector2);
	std::sort(newVector1.begin(), newVector1.end());
	std::sort(newVector2.begin(), newVector2.end());

	return (newVector1 == newVector2);
}
