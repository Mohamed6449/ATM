#pragma once
#include <iostream>
using namespace std;


namespace logo {

	void printLoginScreen() {
		system("cls");
		cout << "------------------------------------------\n";
		cout << "             Login Screen \n";
		cout << "------------------------------------------\n\n";
	}
	void atmMenue() {
		system("cls");
		cout << "========================================================\n";
		cout << "                 ATM main menue screen                  \n";
		cout << "========================================================\n";
		cout << "            [1] Quick Withdraw.                         \n";
		cout << "            [2] Normal Withdraw.                        \n";
		cout << "            [3] Deposit.                                \n";
		cout << "            [4] Check Balance.                          \n";
		cout << "            [5] Logout.                                 \n";
		cout << "========================================================\n";


	}
	void printBalance() {
		system("cls");
		cout << "========================================================\n";
		cout << "                 check Balance screen                   \n";
		cout << "========================================================\n";
	}
	void printDeposit() {
		
		system("cls");
		cout << "========================================================\n";
		cout << "                 Deposit screen                     \n";
		cout << "========================================================\n";
		
	}

	void printNormalWithdraw() {

		system("cls");
		cout << "========================================================\n";
		cout << "               Normal withdraw screen                   \n";
		cout << "========================================================\n";

	}

	void printQuickWithdraw() {

		system("cls");
		cout << "========================================================\n";
		cout << "               Quick withdraw screen                   \n";
		cout << "========================================================\n";
		cout << "             [1] 20           [2] 50          \n";
		cout << "             [3] 100          [4] 200         \n";
		cout << "             [5] 400          [6] 600         \n";
		cout << "             [7] 800          [8] 1000        \n";
		cout << "             [9] Exit                         \n";
		cout << "========================================================\n";

	}
}

