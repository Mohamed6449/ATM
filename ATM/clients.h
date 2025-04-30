#pragma once
#include "stringFun.h"



namespace clients {

	struct stClient {
		string accountNumber;
		string PinCode;
		string name;
		string phone;
		double balance;
	};

	vector<stClient>v_St_Clients(vector<string>clientFile) {
		
		vector<stClient>v_St_Client;
		
		vector < string>line;
		
		stClient client;
		
		
		for (string i : clientFile) {

			line = stringFun::splitString(i,"#//#");

			client.accountNumber = line[0];
			client.PinCode       = line[1];
			client.name          = line[2];
			client.phone         = line[3];
			client.balance        =stod( line[4]);

			v_St_Client.push_back(client);
		}
		return v_St_Client;
	}

	vector<string> structClientsTo_string(vector<stClient>v_St_Clients) {
		vector<string>dataToFile;
		string line="";

		for (stClient i : v_St_Clients) {
			line += i.accountNumber + "#//#";
			line += i.PinCode       + "#//#";
			line += i.name          + "#//#";
			line += i.phone         + "#//#";
			line += to_string(i.balance)  + "#//#";
			dataToFile.push_back(line);
			line = "";
		}
		return dataToFile;
	}

	bool searchClient(vector<stClient>v_St_Clients, string nameAcc, string pin, short& number) {
		number = 0;
		for (stClient i : v_St_Clients) {
			number++;
			if (nameAcc == i.accountNumber && pin == i.PinCode) {
				return 1;
			}
		}
		return 0;
	}






}




