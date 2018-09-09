#include "pch.h"
#include "Item.h"


Item::Item()
{
}
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
double Item::getUnitPrice() {
	return this->_unitPrice;
}
//setters
void Item::setName(const string& newName) {
	this->_name = newName;
}
void Item::setSerialNumber(const string& newSerialNumbere) {
	this->_serialNumber = newSerialNumbere;
}void Item::setCount(const int newCount) {
	this->_count;
}
void Item::setUnitPrice(const double newUnitPrice) {
	this->_unitPrice = newUnitPrice;
}

double Item::totalPrice() {
	return this->_count * this->_unitPrice;
}
bool Item::operator<(Item& other) {
	return this->_serialNumber < other._serialNumber;
}
bool Item::operator>(Item& other){
	return this->_serialNumber > other._serialNumber;
}
bool Item::operator==(Item& other) {
	return this->_serialNumber == other._serialNumber;
}
Item::~Item()
{
}
