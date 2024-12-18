#pragma once
#include <string>
#include <vector>
class Stock; // forward declaration of Stock class so include isn't needed (include had breaking problems before)
using namespace std;
// the Trader class represents a corporation, market, or person who buys/sells stocks from the Stock class with a balance of how much money they have on top of that
class Trader
{
public:
	// getters
	string get_name(); // gets Trader's name
	double get_balance(); // gets Trader's balance
	vector<Stock> get_portfolio(); // gets Trader's portfolio
	Stock get_from_portfolio(int position); // get a Stock from portfolio vector
// setters
	void set_name(string given_name); // sets Trader's name
	void set_balance(double given_balance); // sets balance of Trader
	void set_portfolio(vector<Stock> given_portfolio); // sets portfolio of Trader
// constructors
	Trader(); // constructs Trader with no parameters, default setting name to an empty string, balance to null, and portfolio to an empty vector
	Trader(string given_name); // constructs Trader with a passed in name, null balance, and empty vector portfolio
	Trader(double given_balance); // constructs Trader with a passed in balance
	Trader(string given_name, double given_balance, vector<Stock> given_portfolio); // constructs Trader with everything passed in: a name, a balance, and a portfolio vector
// validators
	bool validate_position(int position); // validate position
// finders
	int find_position_from_portfolio_stock(string given_symbol); // find position of a stock in a portfolio
// adders and removers
	bool add_to_portfolio(Stock given_stock); // add Stock to portfolio vector
	void remove_from_portfolio(int position); // remove Stock from portfolio vector
	void change_quantity_from_portfolio_stock(int position, int given_quantity); // change quantity of a portfolio stock
	bool sell_from_portfolio(int position, int given_quantity); // sell Stock from portfolio vector given quantity and position
	bool sell_from_stock_market(int position, int given_quantity); // sell Stock from stock market portfolio vector given quantity and position (does not alter balance)
	bool withdraw(double amount); // withdraw certain amount of money removing from balance, return true if possible and successful, return false if not possible
	void deposit(double amount); // deposit certain amount of money adding to balance

private:
	// main variables
	string name; // Trader's name
	double balance; // how much money Trader has
	vector<Stock> portfolio; // how many Stocks Trader has in portfolio
};