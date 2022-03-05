#pragma once

#include <vector>
#include <iostream>

template<typename T>
void PrintVector(const std::vector<T>& items)
{
	for (auto item : items)
		std::cout << item << " ";
	std::cout << std::endl;
}
