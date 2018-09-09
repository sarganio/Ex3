#pragma once
#include <string>
using std::string;
class Item
{
private:
	string _name;
	string _serialNumber;
	int _count; //can never be less than 1
	double _unitPrice; //always bigger than 0
public:
//Ctors
	Item();
	Item(const Item& other);
//getters
	string getName()const;
	string getSerialNumber()const;
	int getCount() const;
	double getUnitPrice()const;
//setters
	void setName(const string& newName);
	void setSerialNumber(const string& newSerialNumbere);
	bool setCount(const int newCount);//return true upon successes , false otherwise
	bool setUnitPrice(const double newUnitPrice);//return true upon successes , false otherwise

	double totalPrice()const; //returns _count*_unitPrice
	bool operator<(const Item& other)const; //compares the _serialNumber of those items.
	bool operator>(const Item& other)const; //compares the _serialNumber of those items.
	bool operator==(const Item& other)const; //compares the _serialNumber of those items.
//Dtor
	~Item();

};

