// Ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "Item.h"
#include "Customer.h"
#include <map>
#include <iomanip>
#include <vector>

#define MANY_ATTEMPTS 3
#define NUM_OF_ITEMS 11
#define NUM_OF_OPTIONS_MAIN 4
#define NUM_OF_OPTIONS_OPTEION1 3
using std::cout;
using std::cin;
using std::endl;
using std::map;

Customer* sign_up(map<string, Customer>& abcCustomer,const Item itemList [NUM_OF_ITEMS]);
void sign_in(map<string, Customer>& abcCustomers,const Item itemList[NUM_OF_ITEMS]);
void best_customer(const map<string, Customer>& abcCustomers);
void add_items(Customer& customer,const Item itemList[NUM_OF_ITEMS]);
int main()
{
	map<string, Customer> abcCustomers;
	map<string, Customer>::iterator Mit;
	set<Customer*>::iterator Sit;
	set<Customer*> deletePtrs;
	const Item itemList[NUM_OF_ITEMS] = {
		Item("Milk","00001",5.3),
		Item("Cookies","00002",12.6),
		Item("Bread","00003",8.9),
		Item("Chocolate","00004",7.0),
		Item("Cheese","00005",15.3),
		Item("Rice","00006",6.2),
		Item("Fish", "00008", 31.65),
		Item("Chicken","00007",25.99),
		Item("Cucumber","00009",1.21),
		Item("Tomato","00010",2.32),
		Item("Ice cream", "00011", 16.90) };
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
			deletePtrs.insert(sign_up(abcCustomers,itemList));
			break;
		case 2://to update existing customer's items
			sign_in(abcCustomers,itemList);
			break;
		case 3://to print the customer who pays the most
			best_customer(abcCustomers);
			break;
		case 4://to exit
			running = false;
			for (Sit = deletePtrs.begin(); Sit != deletePtrs.end(); Sit++)
				delete *Sit;
			abcCustomers.clear();
			deletePtrs.clear();
			break;
		default:
			cout << "Invalid input.\n"
				"The input must be an integer in range [1," << NUM_OF_OPTIONS_MAIN << "]." << endl;
			
		}


	} while (running);
 	return 0;
}
Customer* sign_up(map<string, Customer>& abcCustomer, const Item itemList[NUM_OF_ITEMS]) {
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
	add_items(*newCustomer,itemList);
	//add new customer to the database
	abcCustomer.insert(std::pair<string,Customer>(name,*newCustomer));

	items.clear();
	return newCustomer;
	


}
void sign_in(map<string, Customer>& abcCustomers,const Item itemList [NUM_OF_ITEMS]) {
	map<string, Customer>::iterator Mit;
	set<Item>::iterator Sit;
	Customer* customerPtr;
	short input = 0, selectedItem = 0;
	int i = 0;
	string user = "", menu = "Please select one of the following:\n"
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
		//name was found - print list of items
		cout << "Hello " << user << ", your current list of items is:" << endl;
		customerPtr = &Mit->second; 
		Sit = customerPtr->getItems().begin();
		for (Sit = customerPtr->getItems().begin(); Sit != customerPtr->getItems().end(); Sit++) {
			cout << std::setw(2) << i + 1 << ".	" << std::setw(5) << Sit->getName() << endl;
			i++;
		}
		//Add or Remove items
		bool running;
		do {
			cout << menu << endl;
			cin >> input;
			running = false;
			switch (input) {
			case 1://Add items
				add_items(Mit->second, itemList);
				break;
			case 2://Remove items
				if (Mit->second.getItems().size() == 0) {
					cout << "There are no items in your list to remove.\nAdd some items before you choose this option." << endl;
					break;
				}
				do {
					i = 0;
					for (Sit = Mit->second.getItems().begin(); Sit != Mit->second.getItems().end(); Sit++) {
						cout << std::setw(2) << i + 1 << ".	" << std::setw(5) << Sit->getName() << endl;
						i++;
					}
					cout << "please enter the number of the item you wish to remove:" << endl;
					cin >> selectedItem;
					if (selectedItem <= 0 || selectedItem > i)
						cout << "Invalid input.\n"
						"The input must be an integer in range [1," << i << "]." << endl;
				} while (selectedItem <= 0 || selectedItem > i);
				Sit = Mit->second.getItems().begin();
				//move the iterator to the item the user wish to remove
				std::advance(Sit, selectedItem - 1);
				Mit->second.removeItem(*Sit);
				break;
			case 3://Back to the menu
				return;
			default:
				cout << "Invalid input.\n"
					"The input must be an integer in range [1," << NUM_OF_OPTIONS_OPTEION1 << "]." << endl;
				running = true;
				break;
			}
		} while (running);

}
void best_customer(const map<string, Customer>& abcCustomers) {
	map<string, Customer>::const_iterator it;
	const Customer* bestCustomer = nullptr;
	double maxTotal = -1;
	if (abcCustomers.size() == 0) {
		cout << "There are no customers yet.\nSign up customers first." << endl;
		return;
	}
	//search for max total sum of prices of all customers
	for (it = abcCustomers.begin(); it != abcCustomers.end(); it++) {
		if (maxTotal < it->second.totalSum()) {
			maxTotal = it->second.totalSum();
			bestCustomer = &it->second;
		}
	}
	cout << "Our best customer for now is " << bestCustomer->getName() << " who paid a total of " << maxTotal<<".\nCongratulations!" << endl;
}
void add_items(Customer& customer, const Item itemList[NUM_OF_ITEMS]) {
	short input = -1;
	do {
		//if not the first iteration: add the selected item to the customer's list
		if (input != -1)
			customer.addItem(itemList[input - 1]);
		do {
			for (int i = 0; i < NUM_OF_ITEMS; i++)
				cout << std::setw(2) << i + 1 << std::setw(5) << ". Price: " << std::setw(5) << itemList[i].getUnitPrice() << std::setw(5) << " " << itemList[i].getName() << endl;
			cout << "Input:(Insert '0' to return to the main menu)" << endl;
			cin >> input;
			if(input < 0 || input>NUM_OF_ITEMS)
				cout << "Invalid input.\n"
				"The input must be an integer in range [1,"<<NUM_OF_ITEMS<<"].(Or '0' to exit)" << endl;
		} while (input<0 || input>NUM_OF_ITEMS);
	} while (input != 0);

}