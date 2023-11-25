#include "Products.h"
#include "File_stream.h"
#include "Sub_main.h"

Products::Products(int size)
{
	this->array_of_products.resize(size);
	for (int i = 0; i < this->array_of_products.size(); i++)
	{
		this->array_of_products[i].set_price(0);
	}
}

Products::Products()
{}

Products::~Products()
{
	cout << "��'��� ����� \"Products\" ��� ���������" << endl;
}

void Products::display_products()
{
	size_t length = 0;

	for (int i = 0; i < array_of_products.size(); i++)
	{
		if ((array_of_products[i].get_name()).length() > length)
		{
			length = (array_of_products[i].get_name()).length();
		}
	}

	cout << "������ ������:" << endl;

	cout << setw(3) << left << "N" << setw(length + 3) << "�����" << "ֳ��" << endl << endl;

	for (int i = 0; i < array_of_products.size(); i++)
	{
		cout << setw(3) << i + 1 << setw(length + 3) << array_of_products[i].get_name() << array_of_products[i].get_price() << endl << endl;
	}
}

void Products::set_size(size_t size)
{
	this->array_of_products.resize(size);
}

size_t Products::get_size()
{
	return this->array_of_products.size();
}

Product& Products::operator [](const int index) {
	return this->array_of_products[index];
}

int Products::check_element_existence()
{
	return_back();
	//console_output->close();

	//return_back();

	int variable;

	if (!(cin >> variable))
	{
		do
		{
			try_again();

			cout << "����-�����, ������ �������� ��������" << endl << "������ �����: ";

			restart_cin();
		} while (!(cin >> variable));
	}


	if (variable < 0 || variable > array_of_products.size())
	{
		do
		{
			try_again();

			cout << "����-�����, ������ �������� �����" << endl << "������ �����: ";

			restart_cin();

			if (!(cin >> variable))
			{
				do
				{
					try_again();

					cout << "����-�����, ������ �������� ��������" << endl << "������ �����: ";

					restart_cin();
				} while (!(cin >> variable));
			}
		} while (variable < 0 || variable > array_of_products.size());
	}

	return_back(variable);
	cout << endl;
	return (variable-1);
	/*if (num > array_of_products.size())
	{
		return false;
	}

	return true;*/
}

vector <Product> Products::get_array()
{
	return *pointer_array_of_products;
}

void Products::set_array(vector <Product>& array)
{
	this->array_of_products = array;
}

void Products::push(shared_ptr<Product> product)
{
	//this->products.push_back(*product);
	for (int i = 0; i < this->array_of_products.size(); i++)
	{
		if (this->array_of_products[i].get_name() == "")
		{
			array_of_products[i] = *product;
			return;
		}
	}
}

void Products::del_elem()
{
	int way, price, num = -1;
	string name;

	this->display_products();

	cout << "������ �������� ������(�) ������ �������� �� ������ (1) �� �� ����� ��� (2): ";
	//way = check_int_corectness(1);
	way = check_way(2, 0);

	switch (way)
	{
	case 1:
		cout << "������ ����� ��������, ���� �� ������ ��������: ";
		num = this->check_element_existence();

		this->del_elem_by_index(num - 1);
		break;
	case 2:
		cout << "������ �������� �������(�) �� ������ ����� (1) �� ������ (2): ";
		way = check_way(2, 0);

		switch (way)
		{
		case 1:
			cout << "�������� ������ �������� ����� ���������� �� ��� ������ (-1), ���� (0) �� ������ (1) �������: ";
			//way = this->check_element_existence();
			way = check_int_corectness(0);

			if (way == -1 || way == 0 || way == 1)
			{
				cout << "������ ����: ";
				//cin >> price;
				price = check_int_corectness(1);

				this->del_elems_by_feature(price, way);
			}
			else
			{
				cout << endl << "������������ ��������" << endl;
				exit(1);
			}
			break;

		case 2:
			cout << "������ �����, �� ��� ������ ������� ������(�) ������ ��������: ";
			restart_cin();
			getline(cin, name);

			global::console_output->write(name, ADD);
			cout << endl;

			this->del_elems_by_feature(name);
			break;

		default:
			cout << endl << "������������ ��������" << endl;
			exit(1);
		}

		break;
	default:
		cout << endl << "������������ ��������" << endl;
		exit(1);
	}
	//return_back();
	this->display_products();
}

void Products::del_elem_by_index(int num)
{
	/*if (check_element_existence())
	{
		array_of_products.erase(array_of_products.begin() + (num));
		cout << "������� �� ������� " << num+1 << " ��� ������ ���������!" << endl << endl;
	}*/

	array_of_products.erase(array_of_products.begin() + (num));
	//cout << endl << "������� �� ������� " << num + 1 << " ��� ������ ���������!" << endl << endl;
}

void Products::del_elems_by_feature(string feature)
{
	bool deleted = false;
	int i = 0;
	while (i < this->array_of_products.size())
	{
		if (this->array_of_products[i].get_name() == feature)
		{
			this->del_elem_by_index(i);
			deleted = true;
		}
		else
		{
			i++;
		}
	}

	if (deleted == false)
	{
		cout << "�������� �� ����� ������ �� ���� ��������" << endl << endl;
	}
}

void Products::del_elems_by_feature(int feature, int mode)
{
	int i = 0;

	switch (mode)
	{
	case -1:
		while (i < this->array_of_products.size())
		{
			if (this->array_of_products[i].get_price() > feature)
			{
				this->del_elem_by_index(i);
			}
			else
			{
				i++;
			}
		}

		break;

	case 0:
		while (i < this->array_of_products.size())
		{
			if (this->array_of_products[i].get_price() == feature)
			{
				this->del_elem_by_index(i);
			}
			else
			{
				i++;
			}
		}
		break;

	case 1:
		while (i < this->array_of_products.size())
		{
			if (this->array_of_products[i].get_price() < feature)
			{
				this->del_elem_by_index(i);
			}
			else
			{
				i++;
			}
		}
		break;
	}
}