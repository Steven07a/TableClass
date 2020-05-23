// TableClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\vector\vector\vector\Vector.h"
#include <fstream>
#include "Record.h"
#include "Table.h"
//#include <vector>

using namespace std;


int main(int argc, char* argv[])
{
    Vector<string>v{
        "First", "Last", "Major"
    };

    Vector<Vector<string> > records{
        {"Bob" , "Jones", "CS"},
        {"Jane", "Doe", "Math"},
        {"Steve", "Booker", "CS"},
        {"Jack", "Thompson", "Phys"},
        {"Bob", "Jackson", "CS"}
    };

    string employee = "employee";
    Table t(employee, v);
    for (int i = 0; i < records.size(); i++) {
        t.insert_into(records[i]);
    }
    
    t.select_cond("first", "=", "Bob");
    cout << "\n\n";
    t.select_cond("Major", "=", "CS");
    cout << "\n\n";
    //t.select_all();

    return 0;
}
