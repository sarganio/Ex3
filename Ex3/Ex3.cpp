// Ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "Item.h"
#include "Customer.h"
#include <map>
#include <iomanip>

#define MANY_ATTEMPTS 3
#define NUM_OF_ITEMS 10
using std::cout;
using std::cin;
using std::endl;
using std::map;

void sign_up(map<string, Customer>& abcCustomer,Item itemList [NUM_OF_ITEMS]);
void sign_in(map<string, Customer>& abcCustomers);
void best_customer();
int main()
{
	map<string, Customer> abcCustomers;
	Item itemList[NUM_OF_ITEMS] = {
		Item("Milk","00001",5.3),
		Item("Cookies","00002",12.6),
		Item("bread","00003",8.9),
		Item("chocolate","00004",7.0),
		Item("cheese","00005",15.3),
		Item("rice","00006",6.2),
		Item("fish", "00008", 31.65),
		Item("chicken","00007",25.99),
		Item("cucumber","00009",1.21),
		Item("tomato","00010",2.32) };
	bool running = true;
	string menu = "Welcome to MagshiMart!\n"
		"1. to sign as customer and buy items\n"
		"2. to update existing customer's items\n"
		"3. to print the customer who pays the most\n"
		"4. to exit";
	short input;
	do {
		cout << menu<<endl;
		cin >> input;
		switch (input) {
		case 1://to sign as customer and buy items
			sign_up(abcCustomers,itemList);
			break;
		case 2://to update existing customer's items
			sign_in(abcCustomers);
			break;
		case 3://to print the customer who pays the most
			best_customer();
			break;
		case 4://to exit
			running = false;
			break;
		default:
			cout << "Invalid input.\n"
				"The input must be an integer in range [1,4]." << endl;
			
		}


	} while (running);
	return 0;
}
void sign_up(map<string, Customer>& abcCustomer, Item itemList[NUM_OF_ITEMS]) {
	string name = "";
	bool nameInUse = false;
	map<string, Customer>::iterator it;
	Customer* newCustomer;
	set<Item> items;
	short input = -1;
	do {
		cout << "Please enter your name:" << endl;
		cin >> name;
		it = abcCustomer.find(name);
		//check if name is already in the system
		nameInUse = it != abcCustomer.end();
		if (nameInUse)
			cout << "Name is already taken.\nPlease pick another one." << endl;
	} while (nameInUse);
	newCustomer = new Customer(name,items);
	cout << "Hello " << name << ", which items would you like to buy:" << endl;
	do {
		//if not the first iteration: add the selected item to the customer's list
		if(input !=-1 )
			newCustomer->addItem(itemList[input - 1]);
		for (int i = 0; i < NUM_OF_ITEMS; i++)
			cout << std::setw(2) << i+1 << std::setw(5)<< ". Price: " << std::setw(5) << itemList[i].getUnitPrice() << std::setw(5) << " " << itemList[i].getName() << endl;
		cout << "Input:(Insert '0' to return to the main menu)" << endl;
		cin >> input;
	} while (input != 0);
	//add new customer to the database
	abcCustomer.insert(std::pair<string,Customer>(name,*newCustomer));
	


}
void sign_in(map<string, Customer>& abcCustomers) {
	map<string, Customer>::iterator Mit;
	set<Item>::iterator Sit;
	short input = 0;
	string user = "", menu = "Please select one of the following:"
							"1.	Add items\n"
							"2.	Remove items\n"
							"3.	Back to menu";
		cout << "Please enter your name:" << endl;
		cin >> user;
		Mit = abcCustomers.find(user);
		//name was not found - error massage
		if (Mit == abcCustomers.end()) {
			cout << "Name was not found in the system.\nTry again:" << endl;
			return;
		}
		cout << "Hello " << user << ", your current list of items is:" << endl;
		for (Sit = Mit->second.getItems().begin(); Sit != Mit->second.getItems().end(); Sit++) {
			static int i = 0;
			cout << std::setw(2) << i + 1 << ".	" << std::setw(5) << Sit->getName() << endl;
		}
		cout << menu << endl;
		cin >> input;
		bool running;
		do {
			running = false;
			switch (input) {
			case 1://Add items
				break;
			case 2://Remove items
				break;
			case 3://Back to the menu
				break;
			default:
				cout << "Invalid input.\n"
					"The input must be an integer in range [1,3]." << endl;
				running = true;
				break;
			}
		} while (running);

}
void best_customer() {

}
