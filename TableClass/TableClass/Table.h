#ifndef TABLE_H_
#define TABLE_H_

#include <iostream>
#include <string>
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\vector\vector\vector\Vector.h"
#include "Record.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\Map-Class\MapClass\MapClass\Map.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\Map-Class\MapClass\MapClass\MultiMap.h"

using namespace std;

class Table {
private:
	string _name;
	const string _fileName;
	Vector<string> _field_list;
	Map<string,int> field_map;
	Vector<MMap<string, long> > indices;
	Record r;
	fstream f;
	int data_count;
public:
	Table(string n, Vector<string> fl);
	void insert_into(Vector<string> field_list);
	void select_all();
	void select_cond(string field, string eq, string value);
};

Table::Table(string n, Vector<string> fl) : _fileName(n+".bin") , indices(fl.size()) {
	_name = n;
	data_count = 0;
	MMap<string, long>temp;
	for (int i = 0; i < fl.size(); i++) {
		_field_list.push_back(fl[i]);
		field_map.insert(fl[i],i);
		indices.push_back(temp);
	}
	
	/*for (int i = 0; i < indices.size(); i++) {
		
	}*/
	open_fileW(f, _fileName.c_str());
	f.close();
}

void Table::insert_into(Vector<string> field_list) {
	long pos = 0;
	open_fileRW(f, _fileName.c_str());
	Record t(field_list);
	pos = t.write(f);
	f.close();
	data_count++;
	MMap<string, long>temp;
	temp.insert(field_list[0], pos);
	for (int i = 0; i < field_list.size(); i++) {
		indices[field_map[_field_list[i]]].insert(field_list[i], pos);
	}
}

void Table::select_all() {
	cout << _fileName << ": " << endl;
	cout << _field_list << endl;
	open_fileRW(f, _fileName.c_str());
	for (int i = 0; i < data_count; i++) {
		r.read(f,i);
		cout << r.get_record() << endl;
	}
	f.close();
}

void Table::select_cond(string field, string eq, string value) {
	Vector<long> pos;
	pos = indices[field_map[field]][value];
	open_fileRW(f, _fileName.c_str());
	cout << _field_list << endl << endl;
	for (int i = 0; i < pos.size(); i++) {
		r.read(f, pos[i]);
		cout << r.get_record() << endl;
	}
	f.close();
}
#endif // !TABLE_H_
