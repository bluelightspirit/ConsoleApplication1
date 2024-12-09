#include "Stock.h"
#include "Trader.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// getters

// gets symbol of Stock
string Stock::get_symbol()
{
	return symbol;
}

// gets price of Stock
double Stock::get_price()
{
	return price;
}

// gets attributes of Stock
map<Trader*, int> Stock::get_attributes()
{
	return attributes;
}

// gets max quantity of Stock
int Stock::get_max_quantity()
{
	return 0;
}

// gets quantity of Stock for a trader (simplified)
int Stock::get_attributes_simplified(Trader* given_trader)
{
	return attributes.find(given_trader)->second;
}

// setters

// sets symbol of Stock
void Stock::set_symbol(string given_symbol)
{
	symbol = given_symbol;
}

// sets price of Stock
void Stock::set_price(double given_price)
{
	price = given_price;
}

// sets attributes of Stock (literal)
void Stock::set_attributes(map<Trader*, int> given_attributes)
{
	attributes = given_attributes;
}

// sets random price of Stock
void Stock::set_random_price()
{
	set_price(rand());
}

// sets max quantity of Stock
void Stock::set_max_quantity(int given_max_quantity)
{
	given_max_quantity = max_quantity;
}

// sets attributes of Stock (simplified)
void Stock::set_attributes_simplified(Trader* given_trader, int given_quantity)
{
	// if attributes trying to find given trader results in the end of the map only (meaning not found)
	if (attributes.find(given_trader) == attributes.end()) {
		// insert attributes showing given trader and quantity
		attributes.insert({ given_trader, given_quantity });
	}
	// else if trader is found
	else {
		// set attributes of given trader to that quantity
		attributes[given_trader] = given_quantity;
	}
}

// constructors

// constructs an empty Stock with a null price, empty string, and empty attributes vector
Stock::Stock()
{
	symbol = "";
	price = NULL;
	attributes = map<Trader*, int>();
	max_quantity = rand() % 100 + 1;
}

// constructs a mostly empty Stock with the passed in symbol, null price, and empty attributes vector
Stock::Stock(string given_symbol)
{
	symbol = given_symbol;
	price = NULL;
	attributes = map<Trader*, int>();
	int random_number = rand() % 100 + 1;
	cout << random_number << endl;
	max_quantity = random_number;
	//cout << rand() % 100 + 1;
}

// constructs a Stock with an empty string, the passed in price, and empty attributes map
Stock::Stock(double given_price)
{
	symbol = "";
	price = given_price;
	attributes = map<Trader*, int>();
	max_quantity = rand() % 100 + 1;
}

// constructs a Stock with an empty String, the passed in price, and passed in attributes map
Stock::Stock(double given_price, map<Trader*, int> given_attributes)
{
	symbol = "";
	price = given_price;
	attributes = given_attributes;
	max_quantity = rand() % 100 + 1;
}

Stock::Stock(string given_symbol, double given_price, map<Trader*, int> given_attributes, int given_max_quantity)
{
	symbol = given_symbol;
	price = given_price;
	attributes = given_attributes;
	max_quantity = given_max_quantity;
}
