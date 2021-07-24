#include<bits/stdc++.h>
using namespace std;
class StudentManagementSystem
{
public:
	void MainMeat()
	{
		ShowHeading();
		cout << endl << endl;
		int action;
		do {
			ShowOptionsHomeScreen();
			cin >> action;
			if (action == 1)
			{
				//writing in file
				cout << "Adding file" << endl;
			} else if (action == 2)
			{
				//reading from file
				cout << "Reading file" << endl;
			} else if (action == 3)
			{
				//deleting student from roll no.
				cout << "Deleting file" << endl;
			} else if (action > 4)
			{
				cout << "Invalid option" << endl;
			}
		} while (action != 4);

	}
	void ShowHeading()
	{
		cout << "\t\t" << "****Student Management System****" << endl;
	}
	void ShowOptionsHomeScreen()
	{
		cout << "Select one option" << endl;
		cout << "1.Add Student Record\n" << "2.View Student Record\n" << "3.Delete Student Record\n" << "4.Quit" << endl;
	}
};
int main()
{
	StudentManagementSystem st;
	st.MainMeat();
	return 0;
}
