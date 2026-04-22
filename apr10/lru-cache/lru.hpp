// lru.hpp

#pragma once

class LRUCache
{
private:
	int capacity;
	struct Node
	{
		int key;
		int value;
		Node* prev;
		Node* next;
		Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
	};
	Node* head;
public:
	LRUCache(int capacity);
	~LRUCache();
	int get(int key);
	void put(int key, int value);
};
