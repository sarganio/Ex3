#include "pch.h"
#include "Customer.h"
#include <iostream>
typedef set<Item>::iterator iterator;
//Ctors
Customer::Customer() :_name("") {
	_items.clear();
}
Customer::Customer(string name, set<Item> items) : _name(name), _items(items) {}
Customer::Customer(const Customer& other) : _name(other._name), _items(other._items) {}
//getters
string Customer::getName()const {
	return this->_name;
}
set<Item> const& Customer::getItems()const {
	return this->_items;
}
//setters
void Customer::setName(const string& newName) {
	this->_name = newName;
}
void Customer::setItems(const set<Item>& newItems) {
	this->_items = newItems;
}

double Customer::totalSum()const {
	double ans = 0;
	for (iterator it = _items.begin(); it != _items.end(); it++)
		ans += it->totalPrice();
	return ans;
}
void Customer::addItem(const Item& newItem) {
	iterator it;
	it = this->_items.find(newItem);
	//check if the item is already in set
	if (it == this->_items.end())
		this->_items.insert(newItem);
	else {//update the quantity of the item
		Item modified = *it;
		modified.setCount(it->getCount() + newItem.getCount());
		this->_items.erase(it);
		this->_items.insert(modified);
	}
}
bool Customer::removeItem(const Item& oldItem) {
	iterator it;
	it = this->_items.find(oldItem);
	if (it == this->_items.end()) {
		std::cout << "The item requasted to be removed isn't found in " << this->_name << "'s list of items." << std::endl;
		return false;
	}
	Item modified = *it;
	int newCount = modified.getCount() - 1;//change to:	"int newCount = modified.getCount() - oldItem.getCount()" to generalize for removing any amount 

	if (newCount < 0) {
		std::cout << "The quantity which asked to be removed is too high." << std::endl;
		return false;
	}
	if(newCount > 0)
		modified.setCount(newCount);
	this->_items.erase(oldItem);
	//if newCount is 0 then there's no need to insert back the item
	if (newCount == 0) 
		return true;
	this->_items.insert(modified);
	return true;

}
//Dtor
Customer::~Customer() {}
