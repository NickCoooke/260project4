#include "tree.h"

Tree::Tree() : root(nullptr), size(0)
{
}

Tree::~Tree()
{
	destroy(root);
}

void Tree::destroy(Node *& currRoot)
{
	if (currRoot)
	{
		destroy(currRoot->left);
		destroy(currRoot->right);
		delete currRoot->data;
		delete currRoot;
	}
}

//Public call to insert element into ADT
void Tree::add(site * s)
{
	add(root, s);
	size++;
}
//Insert element into tree ADT
void Tree::add(Node *& currRoot, site * s)
{
	if (!currRoot)
	{
		currRoot = new Node(s);
	}
	else if (*s < *(currRoot->data))
	{
		add(currRoot->left, s);
	}
	else
	{
		add(currRoot->right, s);
	}
}

void Tree::display() const
{

	cout << "In-order: " << endl;
	displayInOrder(root);


}

void Tree::displayInOrder(Node * root) const
{
	if (root)
	{
		displayInOrder(root->left);
		cout << *(root->data) << endl;
		displayInOrder(root->right);
	}
}

void Tree::displayPreOrder(Node * root) const
{
	if (root)
	{
		cout << *(root->data) << endl;
		displayPreOrder(root->left);		
		displayPreOrder(root->right);
	}
}

void Tree::displayPostOrder(Node * root) const
{
	if (root)
	{
		displayPostOrder(root->left);		
		displayPostOrder(root->right);
		cout << *(root->data) << endl;
	}
}

int Tree::getSize() const
{
	return getSize(root);
}

int Tree::getSize(Node * currRoot) const
{

	if (!currRoot)
	{
		return 0;
	}
	return 1 + getSize(currRoot->left) + getSize(currRoot->right);
	
}

bool Tree::search(const char * key, site& match) const
{
	return search(root, key, match);
}

bool Tree::search(Node * currRoot, const char * key, site& match) const
{
	if (!currRoot)
	{
		return false;
	}

	int temp = strcmp(key, currRoot->data->getName());
	if (temp == 0)
	{
		match = *(currRoot->data);
		return true;
	}
	else if (temp < 0)
	{
		return search(currRoot->left, key, match);
	}
	else
	{
		return search(currRoot->right, key, match);
	}
}
void Tree::searchByGpa(float gpa, site matches[], int& size) const
{
	searchByGpa(root, gpa, matches, size);
}

void Tree::searchByGpa(Node * currRoot, float gpa, site matches[], int& size) const
{
	if (currRoot)
	{
		if (gpa <= currRoot->data->getGpa())
		{
			matches[size] = *(currRoot->data);
			size++;
		}

		searchByGpa(currRoot->left, gpa, matches, size);
		searchByGpa(currRoot->right, gpa, matches, size);
	}
}

bool Tree::remove(const char * key, site& objectRemoved)
{
	return remove(root, key, objectRemoved);
}

bool Tree::remove(Node *& currRoot, const char * key, site& objectRemoved)
{
	if (!currRoot)
		return false;
	int temp = strcmp(key, currRoot->data->getName());
	if (temp == 0)
	{
		objectRemoved = *(currRoot->data);
		deleteNode(currRoot);
		size--;
		return true;
	}
	else if (temp < 0)
	{
		return remove(currRoot->left, key, objectRemoved);
	}
	else
	{
		return remove(currRoot->right, key, objectRemoved);
	}
}

void Tree:: deleteNode(Node *& aNode)
{
	if (!aNode->left && !aNode->right)
	{
		delete aNode->data;
		delete aNode;
		aNode = nullptr;
	}
	else if (!aNode->right)
	{
		Node * temp = aNode;
		aNode = aNode->left;
		delete temp->data;
		delete temp;
		temp = nullptr;
	}
	else if (!aNode->left)
	{
		Node * temp = aNode;
		aNode = aNode->right;
		delete temp->data;
		delete temp;
		temp = nullptr;
	}
	else
	{ 
		//find the inorder successor
		Node * prev = nullptr;
		Node * curr = aNode->right;
		while (curr->left)
		{
			prev = curr;
			curr = curr->left;
		}

		delete aNode->data;
		aNode->data = curr->data;
		if (!prev)
		{
			aNode->right = curr->right;
		}
		else
		{
			prev->left = curr->right;
		}
		delete curr;
	}
}
