#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace dataClient {

	string getString(string text) {
		cout << text ;
		string data;
		getline(cin>>ws, data);
		return data;
	}

	double getNumber(string text) {
		cout << text;
		double number;
		cin >> number;
		while (cin.fail()) {
			cout << "please enter a numebr ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> number;
		}
		return double(number);
	}

	int getNumberInRange(string text ,int from ,int to) {
		double number=getNumber(text);

		while (number<from || number>to) {
			number=getNumber("please enter a number ["+to_string(from) +","+ to_string(to)+"] ");
		}
		return number;
	}

	bool get_y_n(string text) {
		string data;
		data = getString(text);
		while (data != "y" && data != "Y" && data != "n" && data != "N") {
			data = getString(text);
		}
		return(data == "y" || data == "Y") ? 1 : 0;
	}


}






