// lru.cpp

#include "lru.hpp"
#include <unordered_map>
#include <cstddef>

LRUCache::LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr)
{
	head = new Node(-1, -1);
	tail = new Node(-1, -1);
	head->next = tail;
	tail->prev = head;
}

LRUCache::~LRUCache()
{
	Node* current = head;
	while (current)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
}

void LRUCache::moveToHead(Node* node)
{
	if (node == head->next)
		return; // 已经在头部

	// 从链表中移除节点
	node->prev->next = node->next;
	node->next->prev = node->prev;

	// 将节点移动到头部
	node->next = head->next;
	node->prev = head;
	head->next->prev = node;
	head->next = node;
}
int LRUCache::get(int key)
{
	auto it = cache.find(key);
	if (it == cache.end())
		return -1;

	Node* node = it->second;
	moveToHead(node);
	return node->value;
}

void LRUCache::put(int key, int value)
{
	if (capacity == 0)
		return;

	auto it = cache.find(key);
	if (it != cache.end())
	{
		Node* node = it->second;
		node->value = value;
		moveToHead(node);
		return;
	}

	if (cache.size() == capacity)
	{
		Node* lru = tail->prev; // 最久未使用的节点
		cache.erase(lru->key);
		lru->prev->next = tail;
		tail->prev = lru->prev;
		delete lru;
	}

	Node* newNode = new Node(key, value);
	newNode->next = head->next;
	newNode->prev = head;
	head->next->prev = newNode;
	head->next = newNode;
	cache[key] = newNode;
}
