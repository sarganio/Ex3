#pragma once
#include "Item.h"
#include <set>

using std::set;
using std::set;

class Customer
{
private:
	string _name;
	set<Item> _items;
public:
//Ctors
	Customer();
	Customer(const Customer& other);
//getters
	string getName()const;
	set<Item> getItems()const;
//setters
	void setName(const string& newName);
	void setItems(const set<Item>& newItems);

double totalSum()const; //returns the total sum for payment
	void addItem(Item& newItem); //add item to the set
	bool removeItem(Item& oldItem); //remove item from the set
//Dtor
	~Customer();
};

