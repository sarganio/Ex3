// Ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Item.h"
#include "Customer.h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
	Item item,item2;
	Customer customer;
	string name = "Pencil";
	string serialNumber = "A3";
	item.setCount(3);
	item.setName(name);
	item.setSerialNumber(serialNumber);
	item.setUnitPrice(12);

	item2.setCount(4);
	item2.setName("Pencil");
	item2.setSerialNumber("A3");
	item2.setUnitPrice(12);

	string Cname = "Osher";
	customer.addItem(item);
	customer.addItem(item2);
	cout << "Name of product: " << customer.getItems().begin()->getName() << endl;
	cout << "Quantity of product: " << customer.getItems().begin()->getCount() << endl;
	cout << "Price of a unit: " << customer.getItems().begin()->getUnitPrice() << endl;
	cout << "Serial number of product: " << customer.getItems().begin()->getSerialNumber() << endl;
	cout << "Total price: " << customer.getItems().begin()->totalPrice() << endl;
	

}

