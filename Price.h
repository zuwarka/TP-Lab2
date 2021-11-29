#pragma once
#include <string>

class Price
{
private:

	string item; //название товара
	string shop; //название магазина
	int cost; //цена товара в рублях

public:

	Price();
	Price(string item, string shop, int cost);
	Price(const Price& Price_copy);
	~Price();

	void set_item(string item);
	void set_shop(string shop);
	void set_cost(int cost);
	string get_item() const;
	string get_shop() const;
	int get_cost() const;



};