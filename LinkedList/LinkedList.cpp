#include "LinkedList.h"
#include <iostream>
/*****************************************
A linked list is a complex data structure
that contain two parts, data and pointer.
Data contains the data we want to store
and the pointer points to our next linked
list data structure.
*****************************************/
LinkedList::LinkedList() { nodeP = NULL; }

// Add at the end of the list.
void LinkedList::Append(int num) {
	Node *nodeQ, *nodeT;
	if (nodeP == NULL) {
		nodeP = new Node;
		nodeP->data = num;
		nodeP->link = NULL;
	} else {
		nodeQ = nodeP;
		while (nodeQ->link != NULL)	nodeQ = nodeQ->link;

		nodeT = new Node;
		nodeT->data = num;
		nodeT->link = NULL;
		nodeQ->link = nodeT;
	}
}
// Add number to the front of the linked list.
void LinkedList::AddAtFront(int num) {
	Node *nodeQ;
	nodeQ = new Node;
	nodeQ->data = num;
	nodeQ->link = nodeP;
	nodeP = nodeQ;
}

// Add a linked list after the selected one 'c'.
void LinkedList::AddAfter(int c, int num) {
	Node *nodeQ, *nodeT;
	int i; // Decleare this here so 
	// we can do what we do in the for-loops first section
	for (i = 0, nodeQ = nodeP; i < c; i++){
		nodeQ = nodeQ->link;
		if (nodeQ == NULL) {
			std::cout << "There is less than " << c << " elements.";
			return;
		}
	}
	nodeT = new Node;
	nodeT->data = num;
	nodeT->link = nodeQ->link; // nodeT now point to where nodeQ was pointing.
	nodeQ->link = nodeT; // nodeQ now point to nodeT.
}

void LinkedList::Delete(int num){
	Node *nodeQ, *nodeT;
	nodeQ = nodeP;
	if (nodeQ->data == num) {
		nodeP = nodeT->link;
		delete nodeQ;
		return;
	}

	nodeT = nodeQ;
	while (nodeQ != NULL) {
		if (nodeQ->data == num) {
			nodeT->link = nodeQ->link;
			delete nodeQ;
			return;
		}
		nodeT = nodeQ;
		nodeQ = nodeQ->link;
	}
	std::cout << "\n[ERROR] Element " << num << " was not found.\n";
}

// What does the LinkedList contain?
void LinkedList::Display() {
	Node *nodeQ;
	std::cout << "\n";
	for (nodeQ = nodeP; nodeQ != NULL; nodeQ = nodeQ->link)
		std::cout << "\n" << nodeQ->data;
	std::cout << "\n";
}

// How many items is in the linked list?
int LinkedList::Count() const {
	Node *nodeQ;
	int c = 0;
	for (nodeQ = nodeP; nodeQ != NULL; nodeQ = nodeQ->link)
		c++;
	return c;
}

void LinkedList::Empty() {
	Node *nodeQ;
	if (nodeP == NULL)
		return;
	while (nodeP != NULL) {
		nodeQ = nodeP->link;
		delete nodeP;
		nodeP = nodeQ;
	}
}

LinkedList::~LinkedList() {
	Node *nodeQ;
	if (nodeP == NULL)
		return;
	while (nodeP != NULL) {
		nodeQ = nodeP->link;
		delete nodeP;
		nodeP = nodeQ;
	}
}

