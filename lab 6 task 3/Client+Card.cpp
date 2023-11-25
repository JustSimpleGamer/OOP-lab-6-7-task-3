#include "Client+Card+Debit_card+Credit_card.h"
#include "Sub_main.h"
#include "File_stream.h"

bool Client::Card::get_access()
{
	return this->access;
}

void Client::Card::change_access(bool state)
{
	this->access = state;
}

string Client::Card::get_card_number()
{
	return this->card_number;
}

string Client::Card::get_good_card_number()
{
	string card_n, n;

	for (int i = 0; i < 16; i++)
	{
		card_n += card_number[i];
		if ((i+1) % 4 == 0 && i != 15)
		{
			card_n += '-';
		}
	}

	return card_n;
}

void Client::Card::set_card_number(string card_number)
{
	this->card_number = card_number;
}

int Client::Card::get_number_of_operations()
{
	return number_of_operations;
}

void Client::Card::change_number_of_operations(int size)
{
	this->number_of_operations += size;
}

string Client::Card::get_card_type()
{
	return this->type;
}

Client::Card::Card()
{
	this->access = false;
	this->card_number = "";
}

Client::Card::Card(bool access, string card_number)
{
	this->access = access;
	this->card_number = card_number;
}

Client::Card::~Card()
{
	cout << "��'��� ����� \"Card\" ��� ���������" << endl;
}

void Client::pay_for_the_order(Debit_card& dc, Credit_card& cc, Products& pr) //����� ������ ���������� (������ ������) �볺���� �� ��������� ������
{
	int number, payment_option;

	pr.display_products();

	cout << "������ ����� ������, ���� �� ������ ��������" << endl << "������ �����: ";

	//number = check_way(5, 1);
	number = pr.check_element_existence();

	/*global_stream->close();
	cout << endl;
	global_stream->open("ConsoleOutput.txt", ios::app);*/

	if (dc.get_money_on_card() == NULL)
	{
		cout << "������ � �������� ������� ���������. ��������� ������: � ������ (2)" << endl << "������ ��� ������: ";
		payment_option = check_way(1, 0);
	}
	else
	{
		cout << "������ �������� ������� (1) �� � ������ (2)?" << endl << "������ ��� ������: ";
		payment_option = check_way(2, 0);
	}

	if (payment_option == 1)
	{
		if (dc.get_money_on_card() < pr[number].get_price())
		{
			cout << "�������! �� ������ ������� �� ��������� ������ ��� ������. �������� �� ���� ���������" << endl;
		}
		else
		{
			dc.change_money_on_card(pr[number].get_price());
			dc.change_number_of_operations(1);

			show_results_of_operation(dc, pr[number].get_price());
		}
		return;
	}

	if (payment_option == 2)
	{
		if (!(cc.get_credit() > cc.get_credit_limit()))
		{
			if (cc.get_credit() + pr[number].get_price() > cc.get_credit_limit())
			{
				cout << "������������! ��� ��������� ������ ���������� � ������ ������� �� ����������� ���������� ����." << endl << endl;
				cout << "���-���� ����������? ��� (1) ͳ (2)" << endl << "������ �����: ";

				payment_option = check_way(2, 0);
				if (payment_option == 1)
				{
					cc.change_credit(pr[number].get_price());
					cc.change_number_of_operations(1);

					show_results_of_operation(cc, pr[number].get_price());
				}
				if (payment_option == 2)
				{
					cout << "�������� �� ���� ���������";
				}
			}
			else
			{
				cc.change_credit(pr[number].get_price());
				cc.change_number_of_operations(1);

				show_results_of_operation(cc, pr[number].get_price());
			}
		}
		else
		{
			cout << "������������! ����������� �������!" << endl << endl;
			cout << "���-���� ����������? ��� (1) ͳ (2)" << endl << "������ �����: ";

			payment_option = check_way(2, 0);

			if (payment_option == 1)
			{
				cc.change_credit(pr[number].get_price());
				cc.change_number_of_operations(1);

				show_results_of_operation(cc, pr[number].get_price());
			}
			if (payment_option == 2)
			{
				cout << "�������� �� ���� ���������";
			}
		}

		return;
	}
}

void Client::make_payment_on_other_card(Debit_card& dc)
{
	string card_number;

	cout << "������ ����� ������ �� ��� �� ������ ��������� ����� (16 ����): ";
	card_number = check_card_number_corectness();
	//console_output->close();

	//ConsoleOutput_open();
	//console_output->write(card_number, ADD);
	//ConsoleOutput_write(card_number);
	cout << endl;

	int type = 0;

	if (dc.get_money_on_card() == NULL)
	{
		cout << "������ � ������� ���������";
	}

	int price;

	cout << "������ ������� ������, ��� �� ������ ��������� �� ������: " << endl;
	cout << "������ ����: ";
	price = check_int_corectness(1);
	cout << endl;

	
	
	if (dc.get_money_on_card() > price)
	{
		dc.change_money_on_card(price);
		dc.change_number_of_operations(1);

		show_results_of_operation(dc, price);
	}
	else
	{
		cout << "�������! �� ������ ������� �� ��������� ������ ��� ������" << endl << endl << "�������� �� ���� ���������" << endl;
	}
}

void Client::block_card(Debit_card& dc)
{
	int way;

	cout << "������ ����������� ������� ������? " << "��� (1) ͳ (2)" << endl;
	cout << "������ �����: ";

	way = check_way(2, 0);

	if (way == 1)
	{
		dc.change_access(false);

		cout << "������ ���� ������ �����������!" << endl << endl;

		return;
	}

	cout << "���� ������ �볺��� ��������� ��� ���" << endl << endl;
}

void Client::block_card(Credit_card& cc)
{
	int way;

	cout << "������ ����������� �������� ������? " << "��� (1) ͳ (2)" << endl;
	cout << "������ �����: ";

	way = check_way(2, 0);

	if (way == 1)
	{
		cc.change_access(false);

		cout << "������ ���� ������ �����������!" << endl << endl;

		return;
	}

	cout << "���� ������ �볺��� ��������� ��� ���" << endl << endl;
}

void Client::annul_money(Debit_card& dc)
{
	cout << "������ ��������� �������? " << "��� (1) ͳ (2)" << endl << endl;
	cout << "������ �����: ";

	int way = check_way(2, 0);

	if (way == 1)
	{
		dc.set_money_on_card(NULL);

		cout << "��� ������� ���� ������ ����������!" << endl;
	}

	if (way == 2)
	{
		cout << "���� ������� ��������� ��� ���" << endl << endl;
	}

	return;
}

void Client::show_results_of_operation(Debit_card& dc, double price)
{
	cout << "�������� ������� ������!" << endl << endl << "� ������ ������� ������� ������ ���� ����� " << price << " �������" << endl;
	cout << "ʳ������ ������ �� ������� ������� ������ ������: " << dc.get_money_on_card() << " �������" << endl << endl;
}

void Client::show_results_of_operation(Credit_card& cc, double price)
{
	cout << "�������� ������� ������!" << endl << endl << "�� ������� �������� ������ ���� ��������� " << price << " �������" << endl;
	cout << "�������� ������� ������: " << cc.get_credit() << " �������" << endl << endl;
}


Client::Client()
{

}

Client::~Client()
{
	cout << "��'��� ����� \"Client\" ��� ���������" << endl;
}