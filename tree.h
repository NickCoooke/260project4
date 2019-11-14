#ifndef TREE_H
#define TREE_H
#include "site.h"
class Tree
{
public:
	Tree();
	~Tree();
	void add(Site * s);
	
	void display() const;
	//int search(const char * key, Site matches[]) const;
	bool remove(const char * key, Site& objectRemoved);
	bool search(const char * key, Site& match) const;
	void searchByTopic(const char* topic, Site matches[], int& size) const;
	int getSize() const;
private:	
	struct Node
	{
		Node(Site * aSite)
		{
			data = aSite;
			left = right = nullptr;
		}
		Site * data;
		Node * left;
		Node * right;
	};

	void add(Node *& currRoot, Site * s);

	void displayInOrder(Node * currRoot) const;
	void displayPreOrder(Node * currRoot) const;
	void displayPostOrder(Node * currRoot) const;
	void destroy(Node *& currRoot);
	int getSize(Node * currRoot) const;
	bool search(Node * currRoot, const char * key, Site& match) const;
	void searchByTopic(Node * currRoot, const char* topic, Site matches[], int& size) const;
	bool remove(Node *& currRoot, const char * key, Site& objectRemoved);
	void deleteNode(Node *& aNode);

	Node *	root;
	int		size;

};
#endif
