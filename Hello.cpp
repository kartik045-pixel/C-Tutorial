
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Directory
{
    int srno;
    string name;
    string phonenumber;
    string email;

public:

    Directory(int srno, string name, string phonenumber, string email)
    {
        this->srno = srno;
        this->name = name;
        this->phonenumber = phonenumber;
        this->email = email;
    }

    int getSrno()
    {
        return srno;
    }

    void writeToFile(ofstream &fout)
    {
        fout << srno << " " << name << " "
             << phonenumber << " " << email << endl;
    }

    void displaydetails()
    {
        cout << srno << "    " << name << "    "
             << phonenumber << "    " << email << endl;
    }

    // Searching Function

    void searchContact(vector<Directory> &d)
    {
        int search;
        cout << "Enter Serial Number to search: ";
        cin >> search;

        bool found = false;

        for(int i = 0; i < d.size(); i++)
        {
            if(d[i].getSrno() == search)
            {
                cout << "Contact Found!" << endl;
                d[i].displaydetails();
                found = true;
                break;
            }
        }

        if(!found)
        {
            cout << "Contact not found!"<<endl;
        }
    }
};

int main()
{
    vector<Directory> d;
    int n;

    cout << "Enter number of records: ";
    cin >> n;

    ofstream fout("Directory.txt");

    int x;
    string y, z, e;

    for(int i = 1; i <= n; i++)
    {
        cout << "Record number: " << i << endl;

        cin >> x;
        cin >> y;
        cin >> z;
        cin >> e;

        cout << "---------------------" << endl;

        d.push_back(Directory(x, y, z, e));
    }

    fout << "Srno Name Phonenumber Email" << endl;

    for(int i = 0; i < d.size(); i++)
    {
        d[i].writeToFile(fout);
    }

    fout.close();

    cout << "Srno    Name    Phone number    Email" << endl;

    for(int i = 0; i < d.size(); i++)
    {
        d[i].displaydetails();
    }

    // Reading data from file

    ifstream fin("Directory.txt");

    if(!fin)
    {
        cout << "File not found";
        return 1;
    }

    cout << "Reading data from file: "<<endl;

    string line;
    getline(fin, line);

    int a;
    string b, c, f;

    while(fin >> a >> b >> c >> f)
    {
        cout << a << " " << b << " "
             << c << " " << f << endl;
    }

    fin.close();

    // Searching

    d[0].searchContact(d);

    // Deletion

    int del;
    cout << "Enter Serial Number to delete: ";
    cin >> del;

    bool found = false;

    for(int i = 0; i < d.size(); i++)
    {
        if(d[i].getSrno() == del)
        {
            d.erase(d.begin() + i);
            cout << "Contact deleted successfully!"<<endl;
            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "Contact not found!";
    }

    // Updation

    ofstream out("Directory.txt");

    out << "Srno Name Phonenumber Email" << endl;

    for(int i = 0; i < d.size(); i++)
    {
        d[i].writeToFile(out);
    }

    out.close();

    cout << "Updated Contact Directory:"<<endl;

    for(int i = 0; i < d.size(); i++)
    {
        d[i].displaydetails();
    }

    return 0;
}

