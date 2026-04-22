// lru.hpp

#pragma once
#include <unordered_map>
#include <cstddef>

class LRUCache
{
private:
	size_t capacity;
	struct Node
	{
		int key;
		int value;
		Node* prev;
		Node* next;
		Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
	};
	Node* head;
	Node* tail;
	std::unordered_map<int, Node*> cache; // 哈希表

	void moveToHead(Node* node); // 将节点移动到头部
public:
	LRUCache(int capacity);
	~LRUCache();
	int get(int key);
	void put(int key, int value);
};
