#ifndef TREE_H
#define TREE_H
#include "site.h"
#include <vector>
/*
 *What am I doing?
 1) Sorting upon input: read file input into an array, sorted
 2) binary search that array and add elements to list

 *
 *
 */

class Tree
{
    public:
        Tree(); 
        Tree(const char* input_file);
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
                balance = 0;
            }
            Site * data;
            Node * left;
            Node * right;
            int balance;
        };

        //destructor helper functions
        void destroy(Node *& currRoot);
        
        //constructor helper functions 
        bool readfile(const char* input_file);
        void binaryAdd(vector<Site> input);
        void sort(Site** arr, int i);
        int  fileLines(const char* input_file) const; 
        void balanceAdd(Site* arr[], int l, int r); 

        //add helper functions
        void keyGen(const Site* s) const;
        void add(Node *& currRoot, Site * s);
    
        
        bool remove(Node *& currRoot, const char * key, Site& objectRemoved);
        void deleteNode(Node *& aNode);
        
        //Description functions
        void displayInOrder(Node * currRoot) const;
        int getSize(Node * currRoot) const;
        int height(Node* root) const;
        int heightComp(Node* root) const;
     
        //search functions
        bool search(Node * currRoot, const char * key, Site& match) const;
        void searchByTopic(Node * currRoot, const char* topic,
                       Site matches[], int& size) const;

        
        Node *	root;
        int		size;



        //MEMBER GRAVEYARD

};
#endif
