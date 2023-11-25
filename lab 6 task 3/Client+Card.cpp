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
	cout << "Об'єкт класу \"Card\" був видалений" << endl;
}

void Client::pay_for_the_order(Debit_card& dc, Credit_card& cc, Products& pr) //Метод оплати замовлення (купівля товара) клієнтом за допомогою картки
{
	int number, payment_option;

	pr.display_products();

	cout << "Введіть номер товару, який ви бажаєте придбати" << endl << "Введіть число: ";

	//number = check_way(5, 1);
	number = pr.check_element_existence();

	/*global_stream->close();
	cout << endl;
	global_stream->open("ConsoleOutput.txt", ios::app);*/

	if (dc.get_money_on_card() == NULL)
	{
		cout << "Оплата з дебітовою карткою неможлива. Доступний варіант: в кредит (2)" << endl << "Оберіть тип оплати: ";
		payment_option = check_way(1, 0);
	}
	else
	{
		cout << "Оплата діботовою карткою (1) чи в кредит (2)?" << endl << "Оберіть тип оплати: ";
		payment_option = check_way(2, 0);
	}

	if (payment_option == 1)
	{
		if (dc.get_money_on_card() < pr[number].get_price())
		{
			cout << "Помилка! На вашому рахунку не достатньо грошей для оплати. Операція не була проведена" << endl;
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
				cout << "Попередження! При оформленні даного замовлення в кредит приведе до перевищення кредитного ліміту." << endl << endl;
				cout << "Все-одно продовжити? Так (1) Ні (2)" << endl << "Введіть цифру: ";

				payment_option = check_way(2, 0);
				if (payment_option == 1)
				{
					cc.change_credit(pr[number].get_price());
					cc.change_number_of_operations(1);

					show_results_of_operation(cc, pr[number].get_price());
				}
				if (payment_option == 2)
				{
					cout << "Операція не була проведена";
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
			cout << "Попередження! Перевищення кредиту!" << endl << endl;
			cout << "Все-одно продовжити? Так (1) Ні (2)" << endl << "Введіть цифру: ";

			payment_option = check_way(2, 0);

			if (payment_option == 1)
			{
				cc.change_credit(pr[number].get_price());
				cc.change_number_of_operations(1);

				show_results_of_operation(cc, pr[number].get_price());
			}
			if (payment_option == 2)
			{
				cout << "Операція не була проведена";
			}
		}

		return;
	}
}

void Client::make_payment_on_other_card(Debit_card& dc)
{
	string card_number;

	cout << "Введіть номер картки на яку ви хочете перевести гроші (16 цифр): ";
	card_number = check_card_number_corectness();
	//console_output->close();

	//ConsoleOutput_open();
	//console_output->write(card_number, ADD);
	//ConsoleOutput_write(card_number);
	cout << endl;

	int type = 0;

	if (dc.get_money_on_card() == NULL)
	{
		cout << "Оплата з рахунку неможлива";
	}

	int price;

	cout << "Введіть кількість грошей, яку ви хочете перевести на картку: " << endl;
	cout << "Введіть суму: ";
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
		cout << "Помилка! На вашому рахунку не достатньо грошей для оплати" << endl << endl << "Операція не була проведена" << endl;
	}
}

void Client::block_card(Debit_card& dc)
{
	int way;

	cout << "Бажаєте заблокувати дибітову картку? " << "Так (1) Ні (2)" << endl;
	cout << "Введіть цифру: ";

	way = check_way(2, 0);

	if (way == 1)
	{
		dc.change_access(false);

		cout << "Картка була успішно заблокована!" << endl << endl;

		return;
	}

	cout << "Стан картки клієнта залишився без змін" << endl << endl;
}

void Client::block_card(Credit_card& cc)
{
	int way;

	cout << "Бажаєте заблокувати кредутну картку? " << "Так (1) Ні (2)" << endl;
	cout << "Введіть цифру: ";

	way = check_way(2, 0);

	if (way == 1)
	{
		cc.change_access(false);

		cout << "Картка була успішно заблокована!" << endl << endl;

		return;
	}

	cout << "Стан картки клієнта залишився без змін" << endl << endl;
}

void Client::annul_money(Debit_card& dc)
{
	cout << "Бажаєте анулювати рахунок? " << "Так (1) Ні (2)" << endl << endl;
	cout << "Введіть цифру: ";

	int way = check_way(2, 0);

	if (way == 1)
	{
		dc.set_money_on_card(NULL);

		cout << "Ваш рахунок було успішно онульовано!" << endl;
	}

	if (way == 2)
	{
		cout << "Стан рахунку залишився без змін" << endl << endl;
	}

	return;
}

void Client::show_results_of_operation(Debit_card& dc, double price)
{
	cout << "Операція пройшла успішно!" << endl << endl << "З вашого рахунку дебітової картки було знято " << price << " гривень" << endl;
	cout << "Кількість грошей на рахунку дебітової кратки складає: " << dc.get_money_on_card() << " гривень" << endl << endl;
}

void Client::show_results_of_operation(Credit_card& cc, double price)
{
	cout << "Операція пройшла успішно!" << endl << endl << "На рахунок кредитної картки було нарахвано " << price << " гривень" << endl;
	cout << "Величина кредиту складає: " << cc.get_credit() << " гривень" << endl << endl;
}


Client::Client()
{

}

Client::~Client()
{
	cout << "Об'єкт класу \"Client\" був видалений" << endl;
}