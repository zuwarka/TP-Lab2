#include "Price.h"
#include <iostream>
#include <string>

using namespace std;

Price::Price()
{
	cout << "Constructor Price was called." << endl;
}

Price::Price(string item, string shop, int cost)
{
	this->item = item;
	this->shop = shop;
	this->cost = cost;
	cout << "Constructor Price was called." << endl;
}

Price::Price(const Price& Price_copy)
{
	this->item = Price_copy.item;
	this->shop = Price_copy.shop;
	this->cost = Price_copy.cost;
	cout << "Copy constructor Price was called." << endl;
}

Price::~Price()
{
	cout << "Destructor Price was called." << endl;
}

void Price::set_item(string item)
{
	this->item = item;
}

void Price::set_shop(string shop)
{
	this->shop = shop;
}

void Price::set_cost(int cost)
{
	this->cost = cost;
}

string Price::get_item() const
{
	return item;
}

string Price::get_shop() const
{
	return shop;
}

int Price::get_cost() const
{
	return cost;
}

