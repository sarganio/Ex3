// Ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Item.h"

using std::cout;
using std::cin;
using std::endl;
int main()
{
	Item item;
	string name = "Pencil";
	string serialNumber = "A3";
	item.setCount(3);
	item.setName(name);
	item.setSerialNumber(serialNumber);
	item.setUnitPrice(12);
	cout << "Name of product: " << item.getName() << endl;
	cout << "Quantity of product: " << item.getCount() << endl;
	cout << "Serial number of product: " << item.getSerialNumber() << endl;
	cout << "Total price: " << item.totalPrice() << endl;

}

