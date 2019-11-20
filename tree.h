#ifndef TREE_H
#define TREE_H
#include "site.h"



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
            }
            Site * data;
            Node * left;
            Node * right;
        };

        //constructor/ destructor helper functions
        void destroy(Node *& currRoot);
        bool readfile(const char* input_file);
        
        //add helper functions
        void keyGen(const Site* s) const;
        void add(Node *& currRoot, Site * s);
    
        //Display functions. Need soring 
        void displayInOrder(Node * currRoot) const;
        void displayPreOrder(Node * currRoot) const;
        void displayPostOrder(Node * currRoot) const;
        
        
        void deleteNode(Node *& aNode);
        //
        int getSize(Node * currRoot) const;
        bool search(Node * currRoot, const char * key, Site& match) const;
        void searchByTopic(Node * currRoot, const char* topic, Site matches[], int& size) const;
        bool remove(Node *& currRoot, const char * key, Site& objectRemoved);

        Node *	root;
        int		size;

};
#endif
