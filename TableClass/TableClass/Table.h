#ifndef TABLE_H_
#define TABLE_H_

#include <iostream>
#include <string>
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\vector\vector\vector\Vector.h"
#include "Record.h"

using namespace std;

class Table {
private:
	string _name;
	const string _fileName;
	string _field_list;
	Record r;
	fstream f;
	int data_count;
public:
	Table(string n, Vector<string> fl);
	void insert_into(Vector<string> field_list);
	void select_all();

};

Table::Table(string n, Vector<string> fl) : _fileName(n+".bin") {
	_name = n;
	data_count = 0;
	for (int i = 0; i < fl.size(); i++) {
		_field_list += fl[i];
		if (i < fl.size() - 1) {
			_field_list += " ";
		}
	}
	
	open_fileW(f, _fileName.c_str());
	f.close();
}

void Table::insert_into(Vector<string> field_list) {
	open_fileRW(f, _fileName.c_str());
	string temp;
	for (int i = 0; i < field_list.size(); i++) {
		temp += field_list[i];
		if (i < field_list.size() - 1) {
			temp += " ";
		}
	}
	Record t(temp);
	t.write(f);
	f.close();
	data_count++;
}

void Table::select_all() {
	cout << _fileName << ": " << endl;
	cout << _field_list << endl;
	open_fileRW(f, _fileName.c_str());
	for (int i = 0; i < data_count; i++) {
		r.read(f,i);
		cout << r << endl;
	}
	f.close();
}
#endif // !TABLE_H_
