#include "Administator.h"
#include "Sub_main.h"

Administator::~Administator()
{
	cout << "��'��� ����� \"Administator\" ��� ���������" << endl;
}

//void Administator::change_access_of_card(Client::Debit_card& cd)
//{
//	//read_data(cd);
//
//	int type;
//
//	cout << "���� ������: ";
//
//	if (cd.get_access() == true)
//	{
//		//cout << "��� ������ �볺���: " << cd.get_card_type() << endl;
//
//		cout << "��������";
//
//		cout << "������ ����������� ������? " << "��� (1) ͳ (2)" << endl;
//		cout << "������ �����: ";
//
//		type = check_way(2, 0);
//
//		if (type == 1)
//		{
//			cd.change_access(false);
//
//			cout << "������ ���� ������ �����������!" << endl << endl;
//
//			return;
//		}
//
//		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
//		return;
//	}
//	if (cd.get_access() == false)
//	{
//		cout << "���� ������: �����������" << endl << endl << "������ �������� ������? " << "��� (1) ͳ (2)" << endl;
//		cout << "������ �����: ";
//
//		type = check_way(2, 0);
//
//		if (type == 1)
//		{
//			cd.change_access(true);
//
//			cout << "������ ���� ������ ���������!" << endl << endl;
//
//			return;
//		}
//
//		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
//	}
//}

//void Administator::change_access_of_card(Client::Credit_card& cc)
//{
//	//read_data(cd);
//	int type;
//
//	cout << "���� �������� ������: ";
//
//	if (cc.get_access() == true)
//	{
//		//cout << "��� ������ �볺���: " << cd.get_card_type() << endl;
//
//		cout << "��������";
//
//		cout << "������������ �������: ";
//
//		if (cc.get_credit() > cc.get_credit_limit())
//		{
//			cout << "������ " << (cc.get_credit() - cc.get_credit_limit()) << " �������" << endl << endl;
//		}
//		else
//		{
//			cout << "������" << endl << endl;
//		}
//
//		cout << "������ ����������� ������? " << "��� (1) ͳ (2)" << endl;
//		cout << "������ �����: ";
//
//		type = check_way(2, 0);
//
//		if (type == 1)
//		{
//			cc.change_access(false);
//
//			cout << "������ ���� ������ �����������!" << endl << endl;
//
//			return;
//		}
//
//		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
//		return;
//	}
//	if (cc.get_access() == false)
//	{
//		cout << "�����������" << endl << endl << "������ �������� ������? " << "��� (1) ͳ (2)" << endl;
//		cout << "������ �����: ";
//
//		type = check_way(2, 0);
//
//		if (type == 1)
//		{
//			cc.change_access(true);
//
//			cout << "������ ���� ������ ���������!" << endl << endl;
//
//			return;
//		}
//
//		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
//	}
//}

void Administator::change_product(Products& pr) //����� ������ � ��c���� ��'����
{
	pr.display_products();

	cout << "������ ����� ������, ���� �� ������ ������: " << endl;
	cout << "������ �����: ";

	//int number = check_way(5, 1);
	int number = pr.check_element_existence();

	string name;
	int price;

	restart_cin();

	cout << endl << "������ ���� ����� " << number << "-�� ������: ";
	getline(cin, name);
	global::console_output->write(name, ADD);

	cout << "������ ���� ���� " << number << "-�� ������: ";
	price = check_int_corectness(1);

	pr[number-1].set_product(name, price);

	cout << endl << number << "-�� ����� ��� ������ �������!" << endl << endl;
}

void Administator::initialize_card(Client::Debit_card& dc)
{
	string card_number;
	double money_on_card;

	cout << "������ ����� ������ (16 ����): ";
	card_number = check_card_number_corectness();

	cout << "������ ������� ������ �� ������ �볺���: ";
	money_on_card = check_int_corectness(1);

	dc.set_card_attributes(true, card_number, 0, money_on_card);
}

void Administator::initialize_card(Client::Credit_card& cc)
{
	string card_number;
	unsigned int credit_limit;
	double credit;

	cout << "������ ����� ������ (16 ����): ";
	card_number = check_card_number_corectness();

	cout << "������ ��������� ��� �� ������ �볺���: ";
	credit_limit = check_int_corectness(1);

	cout << "������ ��������� ������� ������� �볺���: ";
	credit = check_int_corectness(1);

	cc.set_card_attributes(true, card_number, 0, credit_limit, credit);
}

void Administator::initiliaze_products(Products& pr) //����� ������ � ������� ��'����
{
	string name;
	int price, number;

	cout << "������ ������� �������� � ������� ��������: ";
	return_back();
	number = check_int_corectness(1);

	//global::console_output->close();
	vector <Product> array(number);

	for (int i = 0; i < number; i++)
	{
		restart_cin();
		//console_output->clear_log();
		cout << "������ ����� " << i + 1 << "-�� ������: ";
		getline(cin, name);

		//console_output->close();
		global::console_output->write(name, ADD);
		//console_output->open(ADD);

		cout << "������ ���� " << i + 1 << "-�� ������: ";
		price = check_int_corectness(1);

		array[i].set_product(name, price);
		//cout << endl;
	}

	pr.set_array(array);
	return;
}

void low_level_Administrator::change_access_of_card(Client::Debit_card& dc)
{
	//read_data(cd);

	int type;

	cout << "���� ������� ������: ";

	if (dc.get_access() == true)
	{
		//cout << "��� ������ �볺���: " << cd.get_card_type() << endl;

		cout << "��������" << endl << endl;

		cout << "������ ����������� ������? " << "��� (1) ͳ (2)" << endl;
		cout << "������ �����: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			dc.change_access(false);

			cout << "������ ���� ������ �����������!" << endl << endl;

			return;
		}

		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
		return;
	}
	if (dc.get_access() == false)
	{
		cout << "�����������" << endl << endl << "���������� ����� ������� ��� ������������� ������" << endl << endl;
		//cout << "������ �����: ";

		/*type = check_way(2, 0);

		if (type == 1)
		{
			dc.change_access(true);

			cout << "������ ���� ������ ���������!" << endl << endl;

			return;
		}

		cout << "���� ������ �볺��� ��������� ��� ���" << endl;*/
	}
}

void low_level_Administrator::change_access_of_card(Client::Credit_card& cc)
{
	//read_data(cc);
	int type;

	cout << "���� �������� ������: ";

	if (cc.get_access() == true)
	{
		//cout << "��� ������ �볺���: " << cd.get_card_type() << endl;

		cout << "��������" << endl << endl;

		cout << "������������ �������: ";

		if (cc.get_credit() > cc.get_credit_limit())
		{
			cout << "������ " << (cc.get_credit() - cc.get_credit_limit()) << " �������" << endl << endl;
		}
		else
		{
			cout << "������" << endl << endl;
		}

		cout << "������ ����������� ������? " << "��� (1) ͳ (2)" << endl;
		cout << "������ �����: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			cc.change_access(false);

			cout << "������ ���� ������ �����������!" << endl << endl;

			return;
		}

		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
		return;
	}
	if (cc.get_access() == false)
	{
		cout << "�����������" << endl << endl << "���������� ����� ������� ��� ������������� ������" << endl << endl;

		/*cout << "�����������" << endl << endl << "������ �������� ������? " << "��� (1) ͳ (2)" << endl;
		cout << "������ �����: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			cc.change_access(true);

			cout << "������ ���� ������ ���������!" << endl << endl;

			return;
		}

		cout << "���� ������ �볺��� ��������� ��� ���" << endl;*/
	}
}

void low_level_Administrator::delete_product_s(Products& pr)
{
	cout << "���������� ����� ������� ��� ��������� ��������" << endl << endl;
}

string low_level_Administrator::get_access_level()
{
	return "������� ����� �������";
}


void medium_level_Administrator::change_access_of_card(Client::Debit_card& dc)
{
	//read_data(cd);

	int type;

	cout << "���� ������� ������: ";

	if (dc.get_access() == true)
	{
		//cout << "��� ������ �볺���: " << cd.get_card_type() << endl;

		cout << "��������" << endl << endl;

		cout << "������ ����������� ������? " << "��� (1) ͳ (2)" << endl;
		cout << "������ �����: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			dc.change_access(false);

			cout << "������ ���� ������ �����������!" << endl << endl;

			return;
		}

		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
		return;
	}
	if (dc.get_access() == false)
	{
		cout << "�����������" << endl << endl << "������ �������� ������? " << "��� (1) ͳ (2)" << endl;
		cout << "������ �����: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			dc.change_access(true);

			cout << "������ ���� ������ ���������!" << endl << endl;

			return;
		}

		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
	}
}

void medium_level_Administrator::change_access_of_card(Client::Credit_card& cc)
{
	//read_data(cc);
	int type;

	cout << "���� �������� ������: ";

	if (cc.get_access() == true)
	{
		//cout << "��� ������ �볺���: " << cd.get_card_type() << endl;

		cout << "��������" << endl << endl;

		cout << "������������ �������: ";

		if (cc.get_credit() > cc.get_credit_limit())
		{
			cout << "������ " << (cc.get_credit() - cc.get_credit_limit()) << " �������" << endl << endl;
		}
		else
		{
			cout << "������" << endl << endl;
		}

		cout << "������ ����������� ������? " << "��� (1) ͳ (2)" << endl;
		cout << "������ �����: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			cc.change_access(false);

			cout << "������ ���� ������ �����������!" << endl << endl;

			return;
		}

		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
		return;
	}
	if (cc.get_access() == false)
	{
		cout << "�����������" << endl << endl << "������ �������� ������? " << "��� (1) ͳ (2)" << endl;
		cout << "������ �����: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			cc.change_access(true);

			cout << "������ ���� ������ ���������!" << endl << endl;

			return;
		}

		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
	}
}

void medium_level_Administrator::delete_product_s(Products& pr)
{
	pr.del_elem();
}

string medium_level_Administrator::get_access_level()
{
	return "������� ����� �������";
}