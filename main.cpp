//main.cpp. This file is currently the testing base for project4.

#include "myutil.h"
#include "site.h"
#include "tree.h"



int main()
{
    /*Leave off notes.
     * 0. add key to site and all site related things.
     *      -need to finish Site::keyGen. 
     *          -if key exists delete and replace 
     *          -else create and replace 
     * 2. update init file to contian realistic websites
     * 3. ask about the key and plan out what she wants
     * 4. build ui
     *
     *
     */ 
	Tree t("init.txt");
	int size = 0;
    t.add(new Site("fun", "https://www.youtube.com/watch?v=9zO_mlzufPk",
                   "Study music", "upbeat chill jazzy", 4));
    t.add(new Site("education", "https://www.youtube.com/watch?v=9zO_mlzufPk",
                   "Study music", "upbeat chill jazzy", 4));
    t.add(new Site("relax", "https://www.youtube.com/watch?v=9zO_mlzufPk",
                   "Study music", "upbeat chill jazzy", 4));
    t.display();
    
	cout << "Tree size: " << t.getSize() << endl;

    /*Old code. Inputs no longer valid
    
	if (cs260.search("anna", match))
	{
		cout << "Finding match for anna: " << match << endl;
	}
	cs260.searchByGpa(3.5, matchList, size);
	cout << "Matching sites for gpa > 3.5: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << matchList[i] << endl;
	}

	cout << "Test remove leaf ..." << endl;
	if (cs260.remove("eric", match))
	{
		cout << "Removed: " << match << endl;
	}
	cout << "After removing eric ..." << endl;
	cs260.display();

	cout << "Test remove one child ..." << endl;
	if (cs260.remove("aaron", match))
	{
		cout << "Removed: " << match << endl;
	}
	cout << "After removing aaron ..." << endl;
	cs260.display();

	cout << "Test remove two children ..." << endl;
	if (cs260.remove("joyce", match))
	{
		cout << "Removed: " << match << endl;
	}
	cout << "After removing joyce ..." << endl;
	cs260.display();
	system("pause");
*/}

