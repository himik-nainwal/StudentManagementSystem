#include<bits/stdc++.h>
#include<fstream>
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
            system("cls");
            ShowOptionsHomeScreen();
            cin >> action;
            if (action == 1)
            {
                //writing in file
                addingDetails();
                cout << "Adding file..." << endl;
            } else if (action == 2)
            {
                //reading from file
                viewStudentDetails();
                cout << "Reading file..." << endl;
            } else if (action == 3)
            {
                //deleting student from roll no.
                cout << "Deleting file..." << endl;
            } else if (action > 4)
            {
                cout << "Invalid option..." << endl;
            }
        } while (action != 4);

    }
    void addingDetails()
    {
        system("cls");
        ShowHeading();
        ofstream studentList;
        studentList.open("list.txt", ios_base::app);
        string name, address;
        string rollno, space = "    ";
        cout << "Roll no: ";
        cin >> rollno;
        fflush(stdin);
        cout << "Name: ";
        getline(cin, name);
        fflush(stdin);
        cout << "Address: ";
        getline(cin, address);
        fflush(stdin);
        //writing data to file
        string final = rollno + space + name + space + address + "\n";
        studentList << final;
        studentList.close();

        //recurtion call
        char flag;
        cout << "Do you want to add anothor data?(Y/N)" << endl;
        cin >> flag;
        if (flag == 'Y' or flag == 'y')
            addingDetails();
    }
    void viewStudentDetails()
    {
        system("cls");
        ShowHeading();
        ifstream in("file.txt");
        stringstream sstr;
        while (in >> sstr.rdbuf());
        cout << sstr.str() << endl;
        in.close();
        char quit;
        cout << "Press Q to exit";
        cin >> quit;
        if (quit == 'Q' or quit == 'q');
    }
    void deleteStudentDetails()
    {
        system("cls");
        ShowHeading();
        int roll;

        cout << "Input Student's Roll number: ";
        cin >> roll;
        char sure;
        cout << "Are you sure you want to delete?(Y?N)";
        cin >> sure;
        if (sure == 'Y' or sure == 'y')
        {
            //delete record
        } else {
            cout << "Deleting process cancelled !";
        }
    }
    void ShowHeading()
    {
        cout << "\t\t\t\t" << "****Student Management System****\n\t\t\t\tBy Harshit Bhatt" << endl;
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
