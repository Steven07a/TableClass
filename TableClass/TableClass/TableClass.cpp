// TableClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\vector\vector\vector\Vector.h"
#include <fstream>
#include "Record.h"
#include "Table.h"

using namespace std;


int main(int argc, char* argv[])
{
    //cout << endl << endl << endl << "================================" << endl;
    //string list[10] = { "zero",
    //                   "one",
    //                   "two",
    //                   "three",
    //                   "four",
    //                   "five",
    //                   "six",
    //                   "seven",
    //                   "eight",
    //                   "nine" };

    //for (int i = 0; i < 10; i++) {
    //    cout << list[i] << endl;
    //}

    //fstream f;
    ////reset the file:
    //open_fileW(f, "record_list.bin");
    //for (int i = 0; i < 10; i++) {
    //    Record r(list[i]);
    //    int recno = r.write(f);
    //    cout << "[" << list[i] << "]" << " was written into file as record: " << recno << endl;
    //}
    //f.close();



    //Record r;
    ////open the file for reading and writing.
    //open_fileRW(f, "record_list.bin");
    //r.read(f, 3);
    //cout << "record 3: " << r << endl;
    //r.read(f, 6);
    //cout << "record 6: " << r << endl;

    //cout << endl << endl << endl << "================================" << endl;

    string employee = "employee";
    Vector<string> v1;
    v1.push_back("first");
    v1.push_back("last");
    v1.push_back("age");
    
    Vector<string> v;
    v.push_back("joe");
    v.push_back("Baker");
    v.push_back("23");

    Table t(employee, v1);
    t.insert_into(v);
    t.select_all();

    return 0;
}
