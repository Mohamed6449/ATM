#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace file {
	
	vector<string>dataFile_v_str(string nameFile) {
		vector<string>data;
		fstream file;
		file.open(nameFile, ios::in);
		string line;
		if (file.is_open()) {
			while (getline(file, line)) {
				data.push_back(line);
			}
			file.close();
		}
		return data;
	}
	
	void reFillDatatToFile(string nameFile,vector<string>data) {
		fstream file;
		file.open(nameFile, ios::out);
		if (file.is_open()) {
			for (string i : data) {
				file << i << endl;
			}
			file.close();
		}
	}


}