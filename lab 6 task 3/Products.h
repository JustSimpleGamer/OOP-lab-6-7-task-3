#pragma once

#include "Libraries.h"
#include "Product.h"

class Products
{
public:
	void set_size(size_t size);
	size_t get_size();

	vector <Product> get_array();
	void set_array(vector <Product>& array);

	Product& operator [](const int index);

	int check_element_existence();
	void display_products();

	void push(shared_ptr<Product> product);

	void del_elem();
	void del_elem_by_index(int num);
	void del_elems_by_feature(int feature, int mode);
	void del_elems_by_feature(string feature);

	Products(int size);
	Products();
	~Products();

	vector <Product> array_of_products;
private:
	vector <Product>* pointer_array_of_products = &array_of_products;

};