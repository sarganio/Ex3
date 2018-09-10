#include "pch.h"
#include "Item.h"
#include <iostream>
#include <exception>
#define DEFAULTCOUNT -1
#define DEFAULTUNITPRICE -1

//Ctors
Item::Item() :_name(""), _serialNumber(""), _count(DEFAULTCOUNT), _unitPrice(DEFAULTUNITPRICE) {}
Item::Item(string name, string serialNumber, double unitPrice, int count = 1) : _name(name), _serialNumber(serialNumber) {
		this->setCount(count);
		this->setUnitPrice(unitPrice);
}
Item::Item(const Item& other) : _name(other._name), _serialNumber(other._serialNumber), _count(other._count), _unitPrice(other._unitPrice) {}
//getters
string Item::getName()const {
	return this->_name;
}
string Item::getSerialNumber()const {
	return this->_serialNumber;
}
int Item::getCount() const {
	return this->_count;
}
double Item::getUnitPrice()const {
	return this->_unitPrice;
}
//setters
void Item::setName(const string& newName) {
	this->_name = newName;
}
void Item::setSerialNumber(const string& newSerialNumbere) {
	this->_serialNumber = newSerialNumbere;
}
bool Item::setCount(const int newCount) {
	if (newCount > 0) {
		this->_count = newCount;
		return true;
	}else
		std::cout << "The quantity must be an integer bigger than 0." << std::endl;
	return false;
}
bool Item::setUnitPrice(const double newUnitPrice) {
	if (newUnitPrice > 0) {
		this->_unitPrice = newUnitPrice;
		return true;
	}
	else
		std::cout << "The price must be bigger than 0." << std::endl;
	return false;
}

double Item::totalPrice()const {
	return this->_count * this->_unitPrice;
}
bool Item::operator<(const Item& other)const {
	return this->_serialNumber < other._serialNumber;
}
bool Item::operator>(const Item& other)const{
	return this->_serialNumber > other._serialNumber;
}
bool Item::operator==(const Item& other)const {
	return this->_serialNumber == other._serialNumber;
}
//Dtor
Item::~Item() {}
