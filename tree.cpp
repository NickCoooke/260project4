//tree.cpp : holds member implementation for class Tree
//by Nicholas Cooke
//Project 4, Fall 2019 lling cs260



#include "tree.h"
#include "myutil.h"
#include <fstream>


//defualt constructor
Tree::Tree() : root(nullptr), size(0)
{}



//constructs tree with data from input file
Tree::Tree(const char* input_file) 
{
    if(!readfile(input_file))
    {
        cout << "File initilization failed...\n";
    }
}


//deallocate tree data
Tree::~Tree()
{
	destroy(root);
}



//private member function that loads data from a file into tree
bool Tree::readfile(const char* input_file)
{
    {
        ifstream in;
        in.open(input_file);
        if (!in)
            return false; // checks if file is open.

        //now we read into our class....
        char topic[MAX_CHAR];
        char addy[MAX_CHAR];
        char sum[MAX_CHAR];
        char review[MAX_CHAR];
        int rating;
        in.get(topic, MAX_CHAR, ';');
        while (!in.eof()) {
            in.get();

            in.get(addy, MAX_CHAR, ';');
            in.get();
            in.get(sum, MAX_CHAR, ';');
            in.get();
            in.get(review, MAX_CHAR, ';');
            in.get();
            in >> rating;

            in.ignore(MAX_CHAR, '\n'); //moves to new line
            
            add(new Site(topic, addy, sum, review, rating));
            in.get(topic, MAX_CHAR, ';');
        }
        in.close();
        return true;
    }


}


//helper function for destrucor. Recursively go through tree dealocating membory
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
void Tree::add(Site * s)
{
	add(root, s);
	size++;
}



//Insert element into tree ADT
void Tree::add(Node *& currRoot, Site * s)
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




//display entire tree contents
void Tree::display() const
{
	cout << "In-order: " << endl;
	displayInOrder(root);
}



//recursive helper to display tree contents
void Tree::displayInOrder(Node * root) const
{
	if (root)
	{
		displayInOrder(root->left);
		cout << root->data << endl;
		displayInOrder(root->right);
	}
}



//display unordered tree
//DELETE?
void Tree::displayPreOrder(Node * root) const
{
	if (root)
	{
		cout << root->data << endl;
		displayPreOrder(root->left);		
		displayPreOrder(root->right);
	}
}



//DELETE?
void Tree::displayPostOrder(Node * root) const
{
	if (root)
	{
		displayPostOrder(root->left);		
		displayPostOrder(root->right);
		cout << root->data << endl;
	}
}




//return total number of elements in tree
int Tree::getSize() const
{
	return getSize(root);
}



//helper function to calculate nodes in tree
int Tree::getSize(Node * currRoot) const
{
	if (!currRoot)
	{
		return 0;
	}
	return 1 + getSize(currRoot->left) + getSize(currRoot->right);
}



//public function which searches tree with a key and sets Site& to match
bool Tree::search(const char * key, Site& match) const
{
	return search(root, key, match);
}



//private helper function for search
bool Tree::search(Node * currRoot, const char * key, Site& match) const
{
	if (!currRoot)
	{
		return false;
	}

	int temp = strcmp(key, currRoot->data->getTopic());
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



//Public call to search tree for topic matches, popopulate array matches, set size
void Tree::searchByTopic(const char* topic, Site matches[], int& size) const
{
	searchByTopic(root, topic, matches, size);
}



//Private call. Recursive helper function that searches through tree and populates
//array "matches" with sites that match topic 
void Tree::searchByTopic(Node * currRoot, const char* topic,
                       Site matches[], int& size) const
{
	if (currRoot)
	{
		if (topic <= currRoot->data->getTopic())
		{
			matches[size] = *(currRoot->data);
			size++;
		}

		searchByTopic(currRoot->left,  topic, matches, size);
		searchByTopic(currRoot->right, topic, matches, size);
	}
}



//Public: remove object matching the keyword
bool Tree::remove(const char * key, Site& objectRemoved)
{
	return remove(root, key, objectRemoved);
}



//Private helper. recursively searches bst for key matches
bool Tree::remove(Node *& currRoot, const char * key, Site& objectRemoved)
{
	if (!currRoot)
		return false;
	int temp = strcmp(key, currRoot->data->getTopic());
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



//Private helper function for remove. accepts node and deletes if from list
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
