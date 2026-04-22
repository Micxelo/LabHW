// main.cpp

#include <iostream>
#include <string>
#include <unordered_map>
#include "lru.hpp"

int main(int argc, char const *argv[])
{
	size_t capacity, n;
	std::cin >> capacity >> n;

	LRUCache cache(capacity);
	for (size_t i = 0; i < n; ++i)
	{
		std::string op;
		std::cin >> op;
		if (op == "get")
		{
			int key;
			std::cin >> key;
			std::cout << cache.get(key) << ' ';
		}
		else if (op == "put")
		{
			int key, value;
			std::cin >> key >> value;
			cache.put(key, value);
		}
	}

	return 0;
}

