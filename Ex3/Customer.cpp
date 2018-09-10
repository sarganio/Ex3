#include "pch.h"
#include "Customer.h"

typedef set<Item>::iterator iterator;
//Ctors
Customer::Customer() :_name("") {
	_items.clear();
}
Customer::Customer(const Customer& other) : _name(other._name), _items(other._items) {}
//getters
string Customer::getName()const {
	return this->_name;
}
set<Item> Customer::getItems()const {
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
	it = this->_items.find(newItem);//////////////////////
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
	this->_items.erase(oldItem);
	return false;
}
//Dtor
Customer::~Customer() {}
