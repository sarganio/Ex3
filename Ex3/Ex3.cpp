// Ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "Item.h"
#include "Customer.h"
#include <map>

#define MANY_ATTEMPTS 3
using std::cout;
using std::cin;
using std::endl;
using std::map;
int main()
{
	map<string, Customer> abcCustomers;
	Item itemList[10] = {
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
	string menu = "Welcome to MagshiMart!\n1. to sign as customer and buy items\n2. to update existing customer's items\n3. to print the customer who pays the most\n4. to exit";
	char input;
	do {
		cout << menu<<endl;
		cin >> input;
		switch (input) {
		case 1://to sign as customer and buy items
			break;
		case 2://to update existing customer's items
			break;
		case 3://to print the customer who pays the most
			break;
		case 4://to exit
			running = false;
			break;
		default:
			cout << "Invalid input.\nThe input must be an integer in range [1,4]." << endl;
			
		}


	} while (running);
	return 0;



}

