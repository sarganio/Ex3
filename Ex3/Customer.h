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
	Customer();
//getters
	string getName()const;
	set<Item> getItems()const;
//setters
	void setName(const string& newName);
	void setItems(const set<Item>& newItems);

double totalSum()const; //returns the total sum for payment
	void addItem(Item newItem); //add item to the set
	void removeItem(Item oldItem); //remove item from the set
	~Customer();
};

