#include "logos.h"
#include "getDataFromClients.h"
#include "file.h"
#include "clients.h"

short arrayAmount[9] = { 0,20,50,100,200,400,600,800,1000 };

vector<string>dataFromFile ;

vector <clients::stClient>v_st_client;


void balance(double balance_c) {
	logo::printBalance();
	cout << "yuor balance is " << balance_c << endl << endl;
	system("pause");
}

void deposit(clients::stClient client,short number) {
	
	logo::printDeposit();
	
	double depositBlance = dataClient::getNumber("enter a deposit amount ");
	
	if (dataClient::get_y_n("\nare you sure you want perform this transaction [y,n]? ")){
		
		client.balance += depositBlance;
	
		cout << "\ndone successfully.new balance is : " << client.balance<<endl;
	}
	v_st_client[number - 1] = client;
	file::reFillDatatToFile("client.text", clients::structClientsTo_string(v_st_client));

	system("pause");
}

void withdrawNormal(clients::stClient client, short number) {
	logo::printNormalWithdraw();

	int withdraw=dataClient::getNumber("enter an amount multiple of 5 's?");

	while(withdraw % 5 != 0) {

		withdraw=dataClient::getNumber("\namount not multiple of 5 enter anther amount?");	
	}
	if (withdraw > client.balance) {
		
		cout << "\nthe amount exceeds your balance ,mack anther choice.\n ";
	}
	else {
		
		if (dataClient::get_y_n("are you sure you want perform this transaction? [y,n] ")) {
		
			client.balance -= withdraw;
			
			v_st_client[number - 1] = client;
			file::reFillDatatToFile("client.text", clients::structClientsTo_string(v_st_client));

			cout << "done successfully .New balance is :  " << client.balance << endl;		
		}
	}
	system("pause");
}

void withdrawQucik(clients::stClient client, short number) {
	logo::printQuickWithdraw();
	
	
	cout << "your balance is " << client.balance << endl;

	short choose = dataClient::getNumberInRange("choose what to withdraw from [1,8] or [9] to exit ", 1, 9);
	if (arrayAmount[choose]> client.balance) {

		cout << "\nthe amount exceeds your balance ,mack anther choice.\n ";
	}
	else {

		if (dataClient::get_y_n("are you sure you want perform this transaction? [y,n] ")) {

			client.balance -= arrayAmount[choose];

			v_st_client[number - 1] = client;
			file::reFillDatatToFile("client.text", clients::structClientsTo_string(v_st_client));

			cout << "done successfully .New balance is :  " << client.balance << endl;
		}
	}
	system("pause");
}

void atm(short numberSt) {
	int choose = 0;
	
	while (choose != 5) {
		logo::atmMenue();
		
		choose=dataClient::getNumberInRange("choose what do want to do [1,5] ", 1, 5);
		
		if (choose != 4) {
			dataFromFile = file::dataFile_v_str("client.text");
			v_st_client = clients::v_St_Clients(dataFromFile);
		}
		
		switch (choose) {
		case 1:
			withdrawQucik(v_st_client[numberSt - 1], numberSt);
			break;
		case 2:
			withdrawNormal(v_st_client[numberSt-1],numberSt);
			break;
		case 3:
			deposit(v_st_client[numberSt-1],numberSt);
			break;
		case 4:
			balance(v_st_client[numberSt-1].balance);
			break;
		}
	}
}

void login() {
	string nameAcount;
	string pin;
	short number;
	bool search = true;
	do{
		logo::printLoginScreen();
		
		if (search == false) {
			cout << "Invalaid Account number/pin ! \n";
		}

		
		dataFromFile = file::dataFile_v_str("client.text");
		v_st_client = clients::v_St_Clients(dataFromFile);
		nameAcount = dataClient::getString("Enter account number ? ");
		pin = dataClient::getString("Enter pin ? ");
		
		
		search = clients::searchClient(v_st_client, nameAcount, pin, number);
	
		if (search) {
			atm(number);
			search = true;
		}
	
	
	} while (true);
}

int main() {
	login();



	return 0;
}





