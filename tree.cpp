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
Tree::Tree(const char* input_file) : root(nullptr), size(0)
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
        Site* ptr;
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
            
            Site* ptr = new Site(topic, addy, sum, review, rating);
            add(ptr);
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
	{   //adding leaf
		currRoot = new Node(s);
        currRoot->balance = 0;
	}
	else if (*s < *(currRoot->data))
	{
		add(currRoot->left, s);
        currRoot->balance--;
	}
	else
	{
		add(currRoot->right, s);
        currRoot->balance++;
	}

    //Keeping tree balanced
    if(currRoot->balance > 1)
    {
        format(currRoot, currRoot->right);
    }
            
    else if (currRoot->balance < -1)
    {
        format(currRoot, currRoot->left);
    }
}

void Tree::format(Node* mom, Node* kid)
{
    char kmom[MAX_CHAR],
         kkid[MAX_CHAR],
         kbabyL[MAX_CHAR];

    kmom = mom->data->getKey();
    kkid = kid->data->getKet();
    kbaby= kid
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
	{   //deleting leaf
		delete aNode->data;
		delete aNode;
		aNode = nullptr;
	}
	else if (!aNode->right)
	{   //deleting parent of left child
		Node * temp = aNode;
		aNode = aNode->left;
		delete temp->data;
		delete temp;
		temp = nullptr;
	}
	else if (!aNode->left)
	{   //deleting parent of right child
		Node * temp = aNode;
		aNode = aNode->right;
		delete temp->data;
		delete temp;
		temp = nullptr;
	}
	else
	{   //deleting parent 
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

/*
void format()
{
    int format = heightComp(root);
    if ( format == 0)
        return;

    if (format == 1)
    {
        //format right side
    }

    if (format == -1)
    {
        //format left side 
    }
}
*/



//checks if tree is balanced
    // 1) rHeight > 1 + lHeight
    // 0) tree is balanced  
    //-1) lHeight > 1 + rHeight
int heightComp(Node* root)
{
    int rHeight = height(root->right),
        lHeight = height(root->left);
    
    if (rHeight > 1 + lHeight)
        return 1;
    
    if (lHeight > 1 + rHeight)
        return -1;
    
    else 
        return 0;
}
//Returns total height from root
int Tree::height(Node* root) const
{
	if(!root)
		return 0;

	int countL = height(root->left), countR = height(root->right);
	return (countL > countR)? 1 + countL: 1 + countR;
}
