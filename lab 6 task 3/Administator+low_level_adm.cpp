#include "Administator.h"
#include "Sub_main.h"

Administator::~Administator()
{
	cout << "Об'єкт класу \"Administator\" був видалений" << endl;
}

//void Administator::change_access_of_card(Client::Debit_card& cd)
//{
//	//read_data(cd);
//
//	int type;
//
//	cout << "Стан картки: ";
//
//	if (cd.get_access() == true)
//	{
//		//cout << "Тип картки клієнта: " << cd.get_card_type() << endl;
//
//		cout << "доступна";
//
//		cout << "Бажаєте заблокувати картку? " << "Так (1) Ні (2)" << endl;
//		cout << "Введіть цифру: ";
//
//		type = check_way(2, 0);
//
//		if (type == 1)
//		{
//			cd.change_access(false);
//
//			cout << "Картка була успішно заблокована!" << endl << endl;
//
//			return;
//		}
//
//		cout << "Стан картки клієнта залишився без змін" << endl;
//		return;
//	}
//	if (cd.get_access() == false)
//	{
//		cout << "Стан картки: заблокована" << endl << endl << "Бажаєте відновити картку? " << "Так (1) Ні (2)" << endl;
//		cout << "Введіть число: ";
//
//		type = check_way(2, 0);
//
//		if (type == 1)
//		{
//			cd.change_access(true);
//
//			cout << "Картка була успішно відновлена!" << endl << endl;
//
//			return;
//		}
//
//		cout << "Стан картки клієнта залишився без змін" << endl;
//	}
//}

//void Administator::change_access_of_card(Client::Credit_card& cc)
//{
//	//read_data(cd);
//	int type;
//
//	cout << "Стан кредитної картки: ";
//
//	if (cc.get_access() == true)
//	{
//		//cout << "Тип картки клієнта: " << cd.get_card_type() << endl;
//
//		cout << "доступна";
//
//		cout << "Перевтищення кридету: ";
//
//		if (cc.get_credit() > cc.get_credit_limit())
//		{
//			cout << "складає " << (cc.get_credit() - cc.get_credit_limit()) << " гривень" << endl << endl;
//		}
//		else
//		{
//			cout << "відсутнє" << endl << endl;
//		}
//
//		cout << "Бажаєте заблокувати картку? " << "Так (1) Ні (2)" << endl;
//		cout << "Введіть цифру: ";
//
//		type = check_way(2, 0);
//
//		if (type == 1)
//		{
//			cc.change_access(false);
//
//			cout << "Картка була успішно заблокована!" << endl << endl;
//
//			return;
//		}
//
//		cout << "Стан картки клієнта залишився без змін" << endl;
//		return;
//	}
//	if (cc.get_access() == false)
//	{
//		cout << "заблокована" << endl << endl << "Бажаєте відновити картку? " << "Так (1) Ні (2)" << endl;
//		cout << "Введіть число: ";
//
//		type = check_way(2, 0);
//
//		if (type == 1)
//		{
//			cc.change_access(true);
//
//			cout << "Картка була успішно відновлена!" << endl << endl;
//
//			return;
//		}
//
//		cout << "Стан картки клієнта залишився без змін" << endl;
//	}
//}

void Administator::change_product(Products& pr) //Метод роботи з маcивом об'єктів
{
	pr.display_products();

	cout << "Введіть номер товару, який ви бажаєте змінити: " << endl;
	cout << "Введіть цифру: ";

	//int number = check_way(5, 1);
	int number = pr.check_element_existence();

	string name;
	int price;

	restart_cin();

	cout << endl << "Введіть нову назву " << number << "-го товару: ";
	getline(cin, name);
	global::console_output->write(name, ADD);

	cout << "Введіть нову ціну " << number << "-го товару: ";
	price = check_int_corectness(1);

	pr[number-1].set_product(name, price);

	cout << endl << number << "-ий товар був успішно змінений!" << endl << endl;
}

void Administator::initialize_card(Client::Debit_card& dc)
{
	string card_number;
	double money_on_card;

	cout << "Введіть номер картки (16 цифр): ";
	card_number = check_card_number_corectness();

	cout << "Введіть кількість грошей на картці клієнта: ";
	money_on_card = check_int_corectness(1);

	dc.set_card_attributes(true, card_number, 0, money_on_card);
}

void Administator::initialize_card(Client::Credit_card& cc)
{
	string card_number;
	unsigned int credit_limit;
	double credit;

	cout << "Введіть номер картки (16 цифр): ";
	card_number = check_card_number_corectness();

	cout << "Введіть кредитний ліміт на картці клієнта: ";
	credit_limit = check_int_corectness(1);

	cout << "Введіть початкову кількість кредиту клієнта: ";
	credit = check_int_corectness(1);

	cc.set_card_attributes(true, card_number, 0, credit_limit, credit);
}

void Administator::initiliaze_products(Products& pr) //Метод роботи з масивом об'єктів
{
	string name;
	int price, number;

	cout << "Введіть кількість елементів у спискці продуктів: ";
	return_back();
	number = check_int_corectness(1);

	//global::console_output->close();
	vector <Product> array(number);

	for (int i = 0; i < number; i++)
	{
		restart_cin();
		//console_output->clear_log();
		cout << "Введіть назву " << i + 1 << "-го товару: ";
		getline(cin, name);

		//console_output->close();
		global::console_output->write(name, ADD);
		//console_output->open(ADD);

		cout << "Введіть ціну " << i + 1 << "-го товару: ";
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

	cout << "Стан дебітової картки: ";

	if (dc.get_access() == true)
	{
		//cout << "Тип картки клієнта: " << cd.get_card_type() << endl;

		cout << "доступна" << endl << endl;

		cout << "Бажаєте заблокувати картку? " << "Так (1) Ні (2)" << endl;
		cout << "Введіть цифру: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			dc.change_access(false);

			cout << "Картка була успішно заблокована!" << endl << endl;

			return;
		}

		cout << "Стан картки клієнта залишився без змін" << endl;
		return;
	}
	if (dc.get_access() == false)
	{
		cout << "заблокована" << endl << endl << "Недостатній рівень доступу для розблокування картки" << endl << endl;
		//cout << "Введіть число: ";

		/*type = check_way(2, 0);

		if (type == 1)
		{
			dc.change_access(true);

			cout << "Картка була успішно відновлена!" << endl << endl;

			return;
		}

		cout << "Стан картки клієнта залишився без змін" << endl;*/
	}
}

void low_level_Administrator::change_access_of_card(Client::Credit_card& cc)
{
	//read_data(cc);
	int type;

	cout << "Стан кредитної картки: ";

	if (cc.get_access() == true)
	{
		//cout << "Тип картки клієнта: " << cd.get_card_type() << endl;

		cout << "доступна" << endl << endl;

		cout << "Перевтищення кридету: ";

		if (cc.get_credit() > cc.get_credit_limit())
		{
			cout << "складає " << (cc.get_credit() - cc.get_credit_limit()) << " гривень" << endl << endl;
		}
		else
		{
			cout << "відсутнє" << endl << endl;
		}

		cout << "Бажаєте заблокувати картку? " << "Так (1) Ні (2)" << endl;
		cout << "Введіть цифру: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			cc.change_access(false);

			cout << "Картка була успішно заблокована!" << endl << endl;

			return;
		}

		cout << "Стан картки клієнта залишився без змін" << endl;
		return;
	}
	if (cc.get_access() == false)
	{
		cout << "заблокована" << endl << endl << "Недостатній рівень доступу для розблокування картки" << endl << endl;

		/*cout << "заблокована" << endl << endl << "Бажаєте відновити картку? " << "Так (1) Ні (2)" << endl;
		cout << "Введіть число: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			cc.change_access(true);

			cout << "Картка була успішно відновлена!" << endl << endl;

			return;
		}

		cout << "Стан картки клієнта залишився без змін" << endl;*/
	}
}

void low_level_Administrator::delete_product_s(Products& pr)
{
	cout << "Недостатній рівень доступу для виконання операції" << endl << endl;
}

string low_level_Administrator::get_access_level()
{
	return "Низький рівень доступу";
}


void medium_level_Administrator::change_access_of_card(Client::Debit_card& dc)
{
	//read_data(cd);

	int type;

	cout << "Стан дебітової картки: ";

	if (dc.get_access() == true)
	{
		//cout << "Тип картки клієнта: " << cd.get_card_type() << endl;

		cout << "доступна" << endl << endl;

		cout << "Бажаєте заблокувати картку? " << "Так (1) Ні (2)" << endl;
		cout << "Введіть цифру: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			dc.change_access(false);

			cout << "Картка була успішно заблокована!" << endl << endl;

			return;
		}

		cout << "Стан картки клієнта залишився без змін" << endl;
		return;
	}
	if (dc.get_access() == false)
	{
		cout << "заблокована" << endl << endl << "Бажаєте відновити картку? " << "Так (1) Ні (2)" << endl;
		cout << "Введіть число: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			dc.change_access(true);

			cout << "Картка була успішно відновлена!" << endl << endl;

			return;
		}

		cout << "Стан картки клієнта залишився без змін" << endl;
	}
}

void medium_level_Administrator::change_access_of_card(Client::Credit_card& cc)
{
	//read_data(cc);
	int type;

	cout << "Стан кредитної картки: ";

	if (cc.get_access() == true)
	{
		//cout << "Тип картки клієнта: " << cd.get_card_type() << endl;

		cout << "доступна" << endl << endl;

		cout << "Перевтищення кридету: ";

		if (cc.get_credit() > cc.get_credit_limit())
		{
			cout << "складає " << (cc.get_credit() - cc.get_credit_limit()) << " гривень" << endl << endl;
		}
		else
		{
			cout << "відсутнє" << endl << endl;
		}

		cout << "Бажаєте заблокувати картку? " << "Так (1) Ні (2)" << endl;
		cout << "Введіть цифру: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			cc.change_access(false);

			cout << "Картка була успішно заблокована!" << endl << endl;

			return;
		}

		cout << "Стан картки клієнта залишився без змін" << endl;
		return;
	}
	if (cc.get_access() == false)
	{
		cout << "заблокована" << endl << endl << "Бажаєте відновити картку? " << "Так (1) Ні (2)" << endl;
		cout << "Введіть число: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			cc.change_access(true);

			cout << "Картка була успішно відновлена!" << endl << endl;

			return;
		}

		cout << "Стан картки клієнта залишився без змін" << endl;
	}
}

void medium_level_Administrator::delete_product_s(Products& pr)
{
	pr.del_elem();
}

string medium_level_Administrator::get_access_level()
{
	return "Середній рівень доступу";
}