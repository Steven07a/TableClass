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
	static int serial_num;
public:
	Table(string n, Vector<string> fl);
	void insert_into(Vector<string> field_list);
	void select_all();
	void select_cond(string field, string eq, string value);
	Table select(Vector<string>fields, Vector<string>conditions);
};

int Table::serial_num = 1000;

Table::Table(string n, Vector<string> fl) : _fileName(n+to_string(serial_num)+".bin") , indices(fl.size()) {
	_name = n;
	data_count = 0;
	MMap<string, long>temp;
	for (int i = 0; i < fl.size(); i++) {
		_field_list.push_back(fl[i]);
		field_map.insert(fl[i],i);
		indices.push_back(temp);
	}
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
	cout << _name << ": " << endl;
	cout << _field_list << endl;
	open_fileRW(f, _fileName.c_str());
	int index = 0; 

	for (int i = 0; i < data_count; i++) {
		r.read(f,i);
		cout << left << setfill(' ') << setw(5) << r.get_record() << endl;
	}
	f.close();
}

void Table::select_cond(string field, string eq, string value) {
	if (eq == "=") {
		Vector<long> pos;
		pos = indices[field_map[field]][value];
		open_fileRW(f, _fileName.c_str());
		cout << left;
		cout << setw(6);
		cout << _field_list << endl;
		for (int i = 0; i < pos.size(); i++) {
			r.read(f, pos[i]);
			cout << setfill(' ') << setw(5) << r.get_record() << endl;
		}
		f.close();
	} 
}

Table Table::select(Vector<string>fields, Vector<string>conditions) {
	if (conditions[1] == "=") {
		Vector<long> pos;
		pos = indices[field_map[conditions[0]]][conditions[2]];
		open_fileRW(f, _fileName.c_str());
		Vector<Vector<string> >output;
		
		for (int i = 0; i < pos.size(); i++) {
			r.read(f, pos[i]);
			output.push_back(r.get_record());
		}

		Vector<Vector<string> > output1(output.size());
		for (int i = 0; i < output.size(); i++) {
			for (int j = 0; j < fields.size(); j++) {
				output1[i].push_back((output[i][field_map[fields[j]]]));
			}
		}

		serial_num++;
		Table temp(_name, fields);
		for (int i = 0; i < output.size(); i++) {
			temp.insert_into(output1[i]);
		}
		return temp;
	} else if (conditions[1] == "<") {
		MMap<string,long>::Iterator up = indices[field_map[conditions[0]]].lower_bound(conditions[2]);
		Vector<long> pos;
		for (MMap<string, long>::Iterator it = indices[field_map[conditions[0]]].begin(); *it < *up; it++) {
			auto temp = *it;
			pos.push_back(temp.value_list);
		}
	
		open_fileRW(f, _fileName.c_str());
		Vector<Vector<string> > output;
		for (int i = 0; i < pos.size(); i++) {
			r.read(f, pos[i]);
			output.push_back(r.get_record());
		}

		Vector<Vector<string> > output1(output.size());
		for (int i = 0; i < output.size(); i++) {
			for (int j = 0; j < fields.size(); j++) {
				output1[i].push_back((output[i][field_map[fields[j]]]));
			}
		}
		serial_num++;
		Table temp(_name, fields);
		for (int i = 0; i < output.size(); i++) {
			temp.insert_into(output1[i]);
		}
		return temp;
	}

	/*
	
	next we need to add <= and > and >=

	*/
}

#endif // !TABLE_H_
