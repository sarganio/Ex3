#include "pch.h"
#include "Customer.h"

typedef set<Item>::iterator iterator;

Customer::Customer() :_name("") {
	_items.clear();
}
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
void Customer::addItem(Item newItem) {
	this->_items.insert(newItem);
}
void Customer::removeItem(Item oldItem) {
	this->_items.erase(oldItem);
}
Customer::~Customer() {}
