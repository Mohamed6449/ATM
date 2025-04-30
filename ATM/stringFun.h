#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace stringFun {

	vector<string>splitString(string line,string calim) {
		short pos;
		vector<string>text;
		string part;
		while ((pos = line.find(calim)) != line.npos) {
			part = line.substr(0, pos);
			if (part != "") {
				text.push_back(part);
			}
			line.erase(0, pos + calim.length());
		}
		if (line != "") {
			text.push_back(line);
		}
		return text;
	}













}


