/*
 * Author: Steven Herrera
 * Project: TableClass
 * Purpose: Its meant to open a file and insert items into that file while also keeping track of certain items
 *              
 *
 * Notes: 
 */

#include <iostream>
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\vector\vector\vector\Vector.h"
#include <fstream>
#include "Record.h"
#include "Table.h"

using namespace std;


int main(int argc, char* argv[])
{
    Vector<string>v{
        "First", "Last", "major", "age"
    };

    Vector<Vector<string> > records{
        {"Bob" , "Jones", "CS" , "21"},
        {"Jane", "Doe", "Math", "25"},
        {"Steve", "Booker", "CS", "50"},
        {"Jack", "Thompson", "Phys", "60"},
        {"Bob", "Jackson", "CS", "30"}
    };

    string employee = "employee";
    Table t(employee, v);
    for (int i = 0; i < records.size(); i++) {
        t.insert_into(records[i]);
    }
    /*cout << "Select Conditions: first, =, Bob\n";
    t.select_cond("first", "=", "Bob");
    cout << "\n\nSelect Conditions: first, =, CS\n";
    t.select_cond("Major", "=", "CS");
    cout << "\n\nSelect all\n";
    t.select_all();*/
    Vector<string> fields = { "First", "Last", "age"};
    Vector<string> conditions = { "age" , "<" , "30" };
    t.select(fields, conditions).select_all();
    return 0;
}