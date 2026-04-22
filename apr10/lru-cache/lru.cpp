// lru.cpp

#include "lru.hpp"

LRUCache::LRUCache(int capacity) : capacity(capacity), head(nullptr)
{
	head = new Node(-1, -1); // 头节点
}

LRUCache::~LRUCache()
{
	Node *curr = head;
	while (curr)
	{
		Node *temp = curr;
		curr = curr->next;
		delete temp;
	}
}

int LRUCache::get(int key)
{
	Node *curr = head->next;
	while (curr)
	{
		if (curr->key == key)
		{
			// 将节点移动到头部
			if (curr != head->next)
			{
				curr->prev->next = curr->next;
				if (curr->next)
					curr->next->prev = curr->prev;
				curr->next = head->next;
				if (head->next)
					head->next->prev = curr;
				head->next = curr;
				curr->prev = head;
			}
			return curr->value;
		}
		curr = curr->next;
	}
	return -1; // 未找到
}

void LRUCache::put(int key, int value)
{
	Node *curr = head->next;
	while (curr)
	{
		if (curr->key == key)
		{
			curr->value = value;
			// 将节点移动到头部
			if (curr != head->next)
			{
				curr->prev->next = curr->next;
				if (curr->next)
					curr->next->prev = curr->prev;
				curr->next = head->next;
				if (head->next)
					head->next->prev = curr;
				head->next = curr;
				curr->prev = head;
			}
			return;
		}
		curr = curr->next;
	}
	// 插入新节点
	Node *newNode = new Node(key, value);
	newNode->next = head->next;
	if (head->next)
		head->next->prev = newNode;
	head->next = newNode;
	newNode->prev = head;

	// 超过容量
	int count = 0;
	curr = head->next;
	while (curr)
	{
		count++;
		if (count > capacity)
		{
			curr->prev->next = nullptr; // 删除尾节点
			delete curr;
			break;
		}
		curr = curr->next;
	}
}
