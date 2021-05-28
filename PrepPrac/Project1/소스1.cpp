#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllAccInfo();

enum{MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct{
	int accID;
	int balance;
	char cusName[NAME_LEN];
} Account;

Account accArr[100];
int accNum = 0;

int main(){
	int choice;
	while (1){
		ShowMenu();
		cout << "Choose: ";
		cin >> choice;
		cout << endl;

		switch (choice){
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection" << endl;
		}
	}
	return 0;
	system("pause");
}

void ShowMenu(){
	cout << "-----Menu-----" << endl;
	cout << "Create Account" << endl;
	cout << "Deposit" << endl;
	cout << "Withdraw" << endl;
	cout << "Account Info" << endl;
	cout << "End" << endl;
}

void MakeAccount(){
	int id;
	char name[NAME_LEN];
	int balance;
	cout << "[Create Account]" << endl;
	cout << "Account ID:  "; 
	cin >> id;
	cout << "Name:  ";
	cin >> name;
	cout << "Deposit Amount:  ";
	cin >> balance;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy_s(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(){
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID:  ";
	cin >> id;
	cout << "Deposit Amount:  ";
	cin >> money;

	for (int i = 0; i < accNum; i++){
		if (accArr[i].accID == id){
			accArr[i].balance += money;
			cout << "Deposit Completed" << endl << endl;
			return;
		}
	}
	cout << "ID Not Found" << endl << endl;
}

void WithdrawMoney(){
	int money;
	int id;
	cout << "[Withdraw]" << endl;
	cout << "Account ID:  ";
	cin >> id;
	cout << "Withdraw Amount:  ";
	cin >> money;

	for (int i = 0; i < accNum; i++){
		if (accArr[i].accID == id){
			if (accArr[i].balance < money){
				cout << "Not enough balance" << endl << endl;
				return;
			}
			
			accArr[i].balance -= money;
			cout << "Withdraw Completed" << endl << endl;
			return;
		}
	}
	cout << "ID Not Found" << endl << endl;
}

void ShowAllAccInfo(){
	for (int i = 0; i < accNum; i++){
		cout << "Account ID:  " << accArr[i].accID << endl;
		cout << "Name:  " << accArr[i].cusName << endl;
		cout << "Balance" << accArr[i].balance <<endl << endl;

	}
}