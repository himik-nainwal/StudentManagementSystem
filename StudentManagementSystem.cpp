#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
using namespace std;
class StudentManagementSystem
{
public:
    void MainMeat()
    {
        system("cls");
        ShowHeading();
        cout << endl << endl;
        while (true) {
            system("cls");
            ShowOptionsHomeScreen();
            cout << "\t\t\t\t\t\t\t\t\t";
            char action = getch();
            if (action == '1')
            {
                //writing in file
                addingDetails();
                // cout << "Adding file..." << endl;
            }
            else if (action == '2')
            {
                //reading from file
                viewStudentDetails();
                // cout << "Reading file..." << endl;
            }
            else if (action == '3')
            {
                //deleting student from roll no.
                cout << "Deleting file..." << endl;
            }
            else if (action == '4')
            {
                exit(0);
            } else
            {
                cout << "Invalid input...";
            }
        }
    }
    void addingDetails()
    {
        system("cls");
        ShowHeading();
        ofstream studentList;
        studentList.open("list.txt", ios_base::app);
        string name, address;
        string rollno, space = "             ";
        cout << "\t\t\t\t\t\t\t\t\tRoll no: ";
        cin >> rollno;
        fflush(stdin);
        cout << "\t\t\t\t\t\t\t\t\tName: ";
        getline(cin, name);
        fflush(stdin);
        cout << "\t\t\t\t\t\t\t\t\tAddress: ";
        getline(cin, address);
        fflush(stdin);
        //writing data to file
        string final = rollno + space + name + space + address + "\n";
        studentList << final;
        studentList.close();

        //recurtion call
        cout << "\t\t\t\t\t\t\t\t\tDo you want to add anothor data?(Y/N)" << endl;
        while (true) {
            cout << "\t\t\t\t\t\t\t\t\t";
            char flag = getch();
            if (flag == 'Y' or flag == 'y')
                addingDetails();
            else if (flag == 'n' or flag == 'N')
                return;
        }

    }
    void viewStudentDetails()
    {
        system("cls");
        ShowHeading();
        ifstream in("list.txt");
        stringstream sstr;
        while (in >> sstr.rdbuf());
        cout << sstr.str() << endl;
        in.close();

        cout << "Press Q to exit";
        while (true) {
            char quit = getch();
            if (quit == 'Q' or quit == 'q')
                return;
        }
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
        }
        else {
            cout << "Deleting process cancelled !";
        }
    }
    void ShowHeading()
    {
        cout << "\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~ Student MANAGEMENT SYSTEM ~~~~~~~~~~~~~~~~~~~~\n\t\t\t\t\t\t\t\t\t\t\t\t\tBy: Harshit Bhatt\n";
    }
    void ShowOptionsHomeScreen()
    {
        system("cls");
        cout << "\t\t\t\t\t\t\t\t\tSelect one option" << endl;
        cout << "\t\t\t\t\t\t\t\t\t1.Add Student Record\n" << "\t\t\t\t\t\t\t\t\t2.View Student Record\n" << "\t\t\t\t\t\t\t\t\t3.Delete Student Record\n" << "\t\t\t\t\t\t\t\t\t4.Quit" << endl;
    }
    void pass() {
        system("cls");
        int i = 0;
        char s[21], str[21] = "Admin123", ch;
        cout << "\n\t\t\t\t\t\t\t\t\tEnter Password: ";
        while (true) {
            ch = getch();
            if (ch == 13) {
                s[i] = '\0';
                break;
            }
            else if (ch == 8 && i > 0) {
                i--;
                cout << "\b \b";
            }
            else {
                cout << "*";
                s[i] = ch;
                i++;
            }
        }
        ifstream inf("password.txt");
        inf >> str;
        inf.close();

        for (i = 0; s[i] == str[i] && s[i] != '\0' && str[i] != '\0'; i++);
        if (s[i] == '\0' && str[i] == '\0') {
            system("cls");
            MainMeat();
        }
        else {
            cout << "\n\n\t\t\t\t\t\t\t\t\tWRONG PASSWORD!!\n\t\t\t\t\t\t\t\t\t";
            system("PAUSE");
            system("cls");
            start();
        }
    }
    void start() {
        system("cls");
        ShowHeading();
        cout << "\n\t\t\t\t\t\t\t\t\t>>> LOGIN MENU <<<\n";;
        cout << "\n\t\t\t\t\t\t\t\t\t1. Admin User\n\t\t\t\t\t\t\t\t\t2. Exit\n";
        cout << "\t\t\t\t\t\t\t\t\t";

        while (true) {
            char quit = getch();
            if (quit == '1')
                pass();
            else if (quit == '2')
                exit(0);
        }
    }
};
int main()
{
    StudentManagementSystem st;
    st.start();
    return 0;
}