#pragma once
#include <memory>

template<typename T>
struct ItemMenu
{
	std::string textSelection{};
	T object;

};