#pragma once

#include "Libraries.h"

class Product
{
public:
	//shared_ptr<Product> try_create_object();

	void set_product(string name, double price);

	void set_name(string name);
	void set_price(double price);

	double get_price();
	string get_name();

	Product(string name, double price);
	Product();
	~Product();
private:
	string name;
	double price;
};
