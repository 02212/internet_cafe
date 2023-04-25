#pragma once
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;


class Internet_Cafe {
	string name ="", _name[20];
	char access_vouch_gen[26] = "abcdefghijklmnopqsturwxv";
	string access_vouch_unique[20], voucher_user;
	string account_type,_at[20];
	float init_money = 0, deposite_money;  
	int _index = 0, _rand = 0;
public:
	void login();
	void menu();
	void create();
	void check();
	void deposite();
	void details();
	void admin_page();
};

void Internet_Cafe::admin_page() {
	fstream stream;

	stream.open("stream.csv");

	if (!stream.fail())
	{

		for (int i = 0; i < 20; i++)
		{

			stream << i << _name[i] << access_vouch_unique[i] << _at[i] << endl;
		}
		exit(1);
	}
}
 
void Internet_Cafe::check() {
	cout << "Here's your balance: R" <<init_money <<setprecision(2)<< endl;
	menu();
}



void Internet_Cafe::login() {
	cout << "Welcome to Bafy Cafe" <<endl;
	cout << "Please enter name"<<endl;
	cin >> name;
	cout <<"Please enter your unique voucher"<<endl;
	cin >> voucher_user;
	int choice = 0;
	for (int j = 0; j < 20; j++)
		if (name == _name[j] && voucher_user == access_vouch_unique[j]) {
			menu();
		}
	if (name == "Admin" && voucher_user == "Admin_5*")
	{
		admin_page();
	}
	cout << "forgot your account?\n";
	cout << "visit: www.bobwilly.org.za" << endl;
	cout << "1. for Yes\n2. for No\n";
	cin >> choice;
			
	switch (choice) {
	case 1: {
		cout << "Welcome to Register screen" << endl;
		create();
		break;
	}
	default:
		login();
		break;
	}

}

void Internet_Cafe::menu() {
	cout << "\nWelcome to Bafy Cafe" << endl;
	cout << endl;
	cout << "1. Create an account and get a car" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Check balance" << endl;
	cout << "4. Accountholder Details" << endl;
	cout << "5. Exit" << endl;
	cout << endl;
	int choise = 0;
	cin >> choise;
	switch (choise)
	{
		case 1: {
			create();
		}
		case 2: {
			deposite();
		}
		case 3: {
			check();
		}
		case 4: {
			details();
		}
		case 5: {
			cout << "Thanks you for using our systems goodbye" << endl;
			login();
		}
	}
}

void Internet_Cafe::deposite() {
	cout << endl;
	cout << "Goodmorning "<<name<<"Deposite Menu"<<endl;
	cout << "Insert money into machine: ";
	cin >> deposite_money;
	cout << "did you insert R"<<deposite_money <<  setprecision(2)<< "\n1. for Yes \n2. for No \t->: ";
	cout << endl;
	int choice = 0; 
	cin >> choice;
	switch (choice)
	{
	case 1: {
		init_money = init_money + deposite_money;
		cout << "Want to see balance? \n1. for Yes \n2. for No" << endl;
		int pick;
		cin >> pick;
			if ( pick == 1)
			{
				cout << init_money<<setprecision(2)<<endl;
			}
			else 
			{
				cout << "Thank you."<<endl;
				cout << endl;
				menu();
			}
		}
	default:
		cout << endl;
		menu();

	}
}

void Internet_Cafe::create() {
	cout << endl;
	_index++;
	cout << "Enter name: ";
	cin >> name;
	/*cout << "Enter Deposite ";
	cin >> name;*/ 
	cout << "Enter account type: ";
	cin >> account_type;
	/*cout << "Enter exit: ";
	cin >> name;*/
	_at[_index] = account_type;
	cout << "Here is your unique: ";
	//store info
	_name[_index] = name;
	srand(time(NULL));
	string temp = "";
	for (int i = 0; i <5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			_rand = 1 + (rand() % 20);
		}
		temp = temp + access_vouch_gen[_rand];
	}
	cout << endl;
	access_vouch_unique[_index] = temp;
	cout << temp<<endl;
	login();
}

void Internet_Cafe::details() {
	cout << endl;
	cout << "Name: " << name << endl;
	cout << "Unique Voucher: " << access_vouch_unique[_index] << endl;
	cout << "Account Type: " << account_type << endl;
	cout << "Total Balance: R" << init_money<<setprecision(2) << endl;
	cout << endl;
}
