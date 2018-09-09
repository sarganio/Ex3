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
void Customer::addItem(Item& newItem) {
	iterator it;
	it = this->_items.find(newItem);
	//check if the item is alredy in set
	if (it == this->_items.end())
		this->_items.insert(newItem);
	else
		it->setCount(it->getCount() +1);
}
bool Customer::removeItem(Item& oldItem) {
	this->_items.erase(oldItem);
}
//Dtor
Customer::~Customer() {}
