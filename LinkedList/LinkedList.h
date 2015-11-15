#ifndef LINKEDLIST
#define LINKEDLIST

// Linked List storing integers.

class LinkedList
{
private:
	struct Node
	{
		int data;
		Node *link;
	} *nodeP;

public:
	LinkedList();
	~LinkedList();
	void Append(int num);
	void AddAtFront(int num);
	void AddAfter(int c, int num);
	void Delete(int num);
	void Display();
	void Empty();
	int Count() const;
};

#endif
#pragma once
