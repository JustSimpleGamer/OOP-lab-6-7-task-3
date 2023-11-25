#include "Product.h"

//shared_ptr<Product> Product::try_create_object()
//{
//	try
//	{
//		Product* temp = new Product;
//		shared_ptr<Product> ptr1(temp);
//		return ptr1;
//	}
//	catch (bad_alloc& e)
//	{
//		cerr << "Помилка при виділенні пам\'яті під об\'єкт" << endl;
//		exit(-1);
//	}
//}

Product::Product(string name, double price)
{
	this->name = name;
	this->price = price;
}

Product::Product()
{
	
}

Product::~Product()
{
	cout << "Об'єкт класу \"Product\" був видалений" << endl;
}

void Product::set_product(string name, double price)
{
	this->name = name;
	this->price = price;
}

void Product::set_name(string name)
{
	this->name = name;
}

void Product::set_price(double price)
{
	this->price = price;
}

double Product::get_price()
{
	return this->price;
}

string Product::get_name()
{
	return this->name;
}