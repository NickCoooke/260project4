//main.cpp. This file is currently the testing base for project4.

#include "myutil.h"
#include "site.h"
#include "tree.h"

int main()
{
    /*Leave off notes.
     * 4. intigrate key into remove and search functions
     *         -pass Site pointer to tree. tree will pull key and search
     *          via that:)
     *          1) search by topic
     *          --return array of elements
     *                  so print tree equivelent filler
     *          --choose index to edit
     * 5. Build tree reformatting function
     * 6. build sheild class
     * 7. build ui
     *
     *
     */
	Tree* t = new Tree("init.txt");
    t->display();


    cout << endl << endl << endl;
    Site removed;
    char input[] = "reddit.com";
    t->remove(input, removed);
    
    char input1[] = "nasa.gov";
    t->remove(input1, removed);
    
    char input2[] = "nasa.gov";
    t->remove(input3, removed);
    
    char input3[] = "nasa.gov";
    t->remove(input3, removed);
    
    char input4[] = "nasa.gov";
    t->remove(input4, removed);
    
    char input5[] = "nasa.gov";
    t->remove(input5, removed);
    
    char input6[] = "nasa.gov";
    t->remove(input6, removed);
    
    char input7[] = "nasa.gov";
    t->remove(input7, removed);
    
    char input8[] = "nasa.gov";
    t->remove(input8, removed);
    
    char input9[] = "nasa.gov";
    t->remove(input9, removed);
    
    
    
    
    
    delete t; 
    
    /*
    //SEARCH FUNCTION!!!
    cout << "Please enter address that you want to delete: ";
    cin.getline(input, MAX_CHAR);
    int size = 0;
    Site* removed;
*/
//    if (t.remove(input, *removed))
  //      cout << removed;


    /*  
    Site* matches = new Site[t.getSize()];
    t.searchByTopic(input, matches, size);
   for(auto i = 0; i < size; i++) 
   { 
       //why don't you work? 
        //cout << matches[i] << endl;
   }
    delete[] matches;
*/
/*
    t.add(new Site("fun", "https://www.youtube.com/watch?v=9zO_mlzufPk",
                   "Study music", "upbeat chill jazzy", 4));
    t.add(new Site("education", "https://www.youtube.com/watch?v=9zO_mlzufPk",
                   "Study music", "upbeat chill jazzy", 4));
    t.add(new Site("relax", "https://www.youtube.com/watch?v=9zO_mlzufPk",
                   "Study music", "upbeat chill jazzy", 4));
*/   
    
//    t.display();
        
}

 
