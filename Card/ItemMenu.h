#pragma once
#include <memory>

template<typename T>
struct ItemMenu
{
	std::string textSelection{};
	std::shared_ptr<T> object;

};