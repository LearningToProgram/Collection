#ifndef LEVELORDERTRAVERSAL_H
#define LEVELORDERTRAVERSAL_H

#include <queue>
#include <iostream>

struct Node
{
public:
	Node() { }
	char data;
	Node* left;
	Node* right;
};

class LOT
{
public:
	LOT() { }
	void LevelOrder(Node* root);
	Node* Insert(Node* root, char data);
};

void LOT::LevelOrder(Node* root)
{
	if (root == NULL) return; // We can't traverse a empty/non-existing tree.
	std::queue<Node*> queue;
	queue.push(root);
	while (!queue.empty())
	{
		Node* current = queue.front();
		std::cout << current->data << ", ";
		if ( current->left != NULL )  queue.push(current->left);
		if ( current->right != NULL ) queue.push(current->right);
		queue.pop();
	}
}

Node* LOT::Insert(Node* root, char data)
{
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data) root->left = Insert(root->left, data);
	else root->right = Insert(root->right, data);
	return root;
}
#endif