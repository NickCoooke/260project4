#include "myutil.h"
#include "student.h"
#include "table.h"



int main(int argc, char ** argv)
{
	Table cs260;
	Student match;
	Student matchList[10];
	int size = 0;
	cs260.add(new Student("joyce", 3.9));
	cs260.add(new Student("aaron", 3.7));
	cs260.add(new Student("wendy", 2.9));
	cs260.add(new Student("anna", 3.0));
	cs260.add(new Student("eric", 3.8));
	cs260.add(new Student("zack", 3.3));
	cs260.add(new Student("larry", 3.3));
	cs260.add(new Student("karan", 3.3));
	cs260.add(new Student("kim", 3.3));
	cs260.display();
	cout << "Tree size: " << cs260.getSize() << endl;
	if (cs260.search("anna", match))
	{
		cout << "Finding match for anna: " << match << endl;
	}
	cs260.searchByGpa(3.5, matchList, size);
	cout << "Matching students for gpa > 3.5: " << endl;
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
	return 0;
}

