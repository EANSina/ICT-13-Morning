#include<iostream>
#include<string>
using namespace std;

const int maxrow = 10;
string StudName[maxrow] = {};
string StudID[maxrow] = {};

void InputInfo()
{
    string name, studno;
    cin.ignore();
    cout << "Student ID: ";
    getline(cin, studno);
    cout << "Student name: ";
    getline(cin, name);

    for (int x = 0; x < maxrow; x++)
    {
        if (StudID[x].empty())
        {
            StudID[x] = studno;
            StudName[x] = name;
            break;
        }
    }
}

void DisplayInfo()
{
    cout << "\nDisplay student information:" << endl;
    cout << "---------------------------------------------------" << endl;

    int counter = 0;
    cout << " No. |   ID   |    Name     " << endl;
    cout << "---------------------------------------------------" << endl;

    for (int x = 0; x < maxrow; x++)
    {
        if (!StudID[x].empty())
        {
            counter++;
            cout << "  " << counter << "  | " << StudID[x] << "     |     " << StudName[x] << endl;
        }
    }

    if (counter == 0)
    {
        cout << "No Information found!" << endl;
    }

    cout << "---------------------------------------------------\n" << endl;
}

void DeleteInfo(string search)
{
    int counter = 0;
    for (int x = 0; x < maxrow; x++)
    {
        if (StudID[x] == search)
        {
            counter++;
            StudName[x] = "";
            StudID[x] = "";
            cout << "Successfully Deleted!" << endl;
            break;
        }
    }

    if (counter == 0)
    {
        cout << "No ID was found!" << endl;
    }
}

void SearchInfo(string search)
{
    cout << "\nDisplay Student information:" << endl;
    cout << "---------------------------------------------------" << endl;
    int counter = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if (StudID[x] == search)
        {
            counter++;
            cout << "  " << counter << "  | " << StudID[x] << " |  " << StudName[x] << endl;
            break;
        }
    }

    if (counter == 0)
    {
        cout << "No information was found!" << endl;
    }

    cout << "---------------------------------------------------\n" << endl;
}

void EditInfo(string search)
{
    string name;
    int counter = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if (StudID[x] == search)
        {
            counter++;
            cout << "Enter new name: ";
            getline(cin, name);
            StudName[x] = name;
            cout << "Edited successfully!" << endl;
            break;
        }
    }

    if (counter == 0)
    {
        cout << "ID cannot be found!" << endl;
    }
}

int main()
{
    int choice;
    string studID;
    
    cout<<"\t ---**Welcome**--- \t"<<endl;
    cout<<"\t Please make your selection! \t"<<endl;

    do
    {
        cout << "type-1: To Enter your student information" << endl;
        cout << "type-2: To Display your student information" << endl;
        cout << "type-3: To Delete your student information" << endl;
        cout << "type-4: To Search your student information" << endl;
        cout << "type-5: To Edit your student information" << endl;
        cout << "type-6: To Exit" << endl;
        cout << "________________________________________________" << endl;

        cout << "Type your choice: ";
        cin >> choice;

        cin.ignore();  // Always clear input buffer before getline

        switch (choice)
        {
        case 1:
            InputInfo();
            break;

        case 2:
            DisplayInfo();
            break;

        case 3:
            cout << "Delete by student ID: ";
            getline(cin, studID);
            DeleteInfo(studID);
            break;

        case 4:
            cout << "Search by student ID: ";
            getline(cin, studID);
            SearchInfo(studID);
            break;

        case 5:
            cout << "Edit by student ID: ";
            getline(cin, studID);
            EditInfo(studID);
            break;
        }

    } while (choice != 6);
   

    return 0;
}
