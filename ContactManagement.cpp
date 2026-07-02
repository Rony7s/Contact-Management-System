/*
    Project     : Contact Management System
    Description : A simple command-line contact book that lets you
                   add, view, search, update, and delete contacts.
                   Contacts are stored in a plain text file (data.txt)
                   using comma-separated values.
    Author      : Md. Rony Ahmmed Shah
    GitHub      : github.com/Rony7s

    Note: To keep this beginner-friendly, contact fields (name, phone,
    address) should NOT contain commas, since commas are used to
    separate the fields in the data file.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

const string FILE_NAME = "data.txt";

// Creates data.txt with a header row if it doesn't already exist.
void createFile()
{
    ifstream fin(FILE_NAME);

    if (!fin)
    {
        ofstream fout(FILE_NAME);
        fout << "Name,Phone,Address\n";
        fout.close();
    }

    fin.close();
}

// Splits one "Name,Phone,Address" line into its three parts.
void parseLine(const string &line, string &name, string &phone, string &address)
{
    stringstream ss(line);
    getline(ss, name, ',');
    getline(ss, phone, ',');
    getline(ss, address);
}

void addContact()
{
    string name, phone, address;

    cout << "Name    : ";
    getline(cin, name);

    cout << "Phone   : ";
    getline(cin, phone);

    cout << "Address : ";
    getline(cin, address);

    ofstream fout(FILE_NAME, ios::app);
    fout << name << "," << phone << "," << address << "\n";
    fout.close();

    cout << "\nContact Added Successfully!\n\n";
}

void showContacts()
{
    ifstream fin(FILE_NAME);
    string line;

    getline(fin, line); // skip header row

    cout << "\n========== CONTACT LIST ==========\n\n";

    bool found = false;

    while (getline(fin, line))
    {
        string name, phone, address;
        parseLine(line, name, phone, address);

        cout << "Name    : " << name << endl;
        cout << "Phone   : " << phone << endl;
        cout << "Address : " << address << endl;
        cout << "-----------------------------\n";

        found = true;
    }

    if (!found)
        cout << "No contacts found.\n";

    cout << endl;
    fin.close();
}

void searchContact()
{
    string phoneSearch;
    cout << "Enter Phone Number: ";
    getline(cin, phoneSearch);

    ifstream fin(FILE_NAME);
    string line;
    getline(fin, line); // skip header row

    while (getline(fin, line))
    {
        string name, phone, address;
        parseLine(line, name, phone, address);

        if (phone == phoneSearch)
        {
            cout << "\nContact Found\n";
            cout << "----------------------\n";
            cout << "Name    : " << name << endl;
            cout << "Phone   : " << phone << endl;
            cout << "Address : " << address << endl << endl;

            fin.close();
            return;
        }
    }

    fin.close();
    cout << "\nContact Not Found!\n\n";
}

void updateContact()
{
    string phoneSearch;
    cout << "Enter Phone Number to Update: ";
    getline(cin, phoneSearch);

    ifstream fin(FILE_NAME);
    vector<string> rows;
    string line;
    bool updated = false;

    getline(fin, line);
    rows.push_back(line); // keep header row

    while (getline(fin, line))
    {
        string name, phone, address;
        parseLine(line, name, phone, address);

        if (phone == phoneSearch)
        {
            cout << "\nEnter New Information\n";

            cout << "Name    : ";
            getline(cin, name);

            cout << "Phone   : ";
            getline(cin, phone);

            cout << "Address : ";
            getline(cin, address);

            updated = true;
        }

        rows.push_back(name + "," + phone + "," + address);
    }

    fin.close();

    ofstream fout(FILE_NAME);
    for (const string &row : rows)
        fout << row << "\n";
    fout.close();

    if (updated)
        cout << "\nContact Updated Successfully!\n\n";
    else
        cout << "\nContact Not Found!\n\n";
}

void deleteContact()
{
    string phoneSearch;
    cout << "Enter Phone Number to Delete: ";
    getline(cin, phoneSearch);

    ifstream fin(FILE_NAME);
    vector<string> rows;
    string line;
    bool deleted = false;

    getline(fin, line);
    rows.push_back(line); // keep header row

    while (getline(fin, line))
    {
        string name, phone, address;
        parseLine(line, name, phone, address);

        if (phone == phoneSearch)
        {
            deleted = true; // skip adding this row = delete it
            continue;
        }

        rows.push_back(line);
    }

    fin.close();

    ofstream fout(FILE_NAME);
    for (const string &row : rows)
        fout << row << "\n";
    fout.close();

    if (deleted)
        cout << "\nContact Deleted Successfully!\n\n";
    else
        cout << "\nContact Not Found!\n\n";
}

void showMenu()
{
    cout << "========== CONTACT MANAGEMENT ==========\n";
    cout << "1. Add Contact\n";
    cout << "2. Show All Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Update Contact\n";
    cout << "5. Delete Contact\n";
    cout << "6. Exit\n";
    cout << "\nEnter Choice: ";
}

int main()
{
    createFile();

    while (true)
    {
        showMenu();

        int choice;
        cin >> choice;
        cin.ignore(); // clear the leftover newline left behind by cin >>

        switch (choice)
        {
        case 1: addContact(); break;
        case 2: showContacts(); break;
        case 3: searchContact(); break;
        case 4: updateContact(); break;
        case 5: deleteContact(); break;
        case 6:
            cout << "\nThank You!\n";
            return 0;
        default:
            cout << "\nInvalid Choice!\n\n";
        }
    }

    return 0;
}
