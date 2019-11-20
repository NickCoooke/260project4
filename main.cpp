//main.cpp. This file is currently the testing base for project4.

#include "myutil.h"
#include "site.h"
#include "tree.h"



int main()
{
    /*Leave off notes.
     * DONE 0. add key to site and all site related things.
     * DONE 2. update init file to contian realistic websites
     * DONE 3. ask about the key and plan out what she wants
     * 4. intigrate key into remove and search functions
     *         -how will higher up functions know what the key is?
     *              -just use address as the key?
     *
     * 5. Build tree reformatting function
     * 5. build ui
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
    
    Site s;
    t.remove(
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

