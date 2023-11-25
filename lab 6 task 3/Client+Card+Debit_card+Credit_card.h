#pragma once

#include "Libraries.h"
#include "Products.h"

class Client
{
public:
	class Card
	{
	public:
		bool get_access();
		void change_access(bool state);

		string get_card_number();
		string get_good_card_number();
		void set_card_number(string card_number);

		int get_number_of_operations();
		void change_number_of_operations(int size);

		//virtual void set_card_attributes() = 0;

		string get_card_type();

		Card();
		Card(bool access, string card_number);

		~Card();
	protected:
		bool access;
		string card_number;
		int number_of_operations = 0;

		double commission;
		string type;
	};

	class Debit_card : public Card
	{
	public:
		double get_money_on_card();
		void set_money_on_card(double money);
		void change_money_on_card(double money);

		void set_card_attributes(bool access, string card_number, int number_of_operations, double money_on_card);

		Debit_card();
		Debit_card(bool access, string card_number, double money_on_card);

		Debit_card(const Debit_card& cd);

		~Debit_card();
	private:
		double money_on_card;
	};

	class Credit_card : public Card
	{
	public:
		unsigned int get_credit_limit();
		void set_credit_limit(int credit_limit);

		double get_credit();
		void set_credit(double credit);
		void change_credit(double money);

		void set_card_attributes(bool access, string card_number, int number_of_operations, int credit_limit, double credit);

		Credit_card();
		Credit_card(bool access, string card_number, double credit, int credit_limit);

		Credit_card(const Credit_card& cd);

		~Credit_card();

		//static int number_of_operations; //знайти рішення для того, щоб воно працювало
	private:
		double credit;
		unsigned int credit_limit;
		
		//початкове констатне значення
		//посилання
	};

	void pay_for_the_order(Debit_card& dc, Credit_card& cc, Products& pr);
	void make_payment_on_other_card(Debit_card& dc);
	void block_card(Credit_card& cc);
	void block_card(Debit_card& dc);
	void annul_money(Debit_card& cc);

	void show_results_of_operation(Debit_card& dc, double price);
	void show_results_of_operation(Credit_card& cc, double price);

	Client();
	~Client();
public:

};

class Credit_card_Universal : public Client::Credit_card
{
public:

private:
	unsigned int credit_limit = 10000;
	double commission = 0.5;
	string type = "Universal";
};

class Credit_card_Gold : public Client::Credit_card
{
public:

private:
	unsigned int credit_limit = 100000;
	double commission = 0.2;
	string type = "Gold";
};

class Credit_card_Premium : public Client::Credit_card
{
public:

private:
	unsigned int credit_limit = 500000;
	double commission = 0.0;
	string type = "Premium";
};

class Debit_card_Universal : public Client::Debit_card
{
public:

private:
	double maximum_purchase_price = 1000.0;
	double commission = 0.5;
	string type = "Universal";
};

class Debit_card_Gold : public Client::Debit_card
{
public:

private:
	double maximum_purchase_price = 100000.0;
	double commission = 0.2;
	string type = "Gold";
};

class Debit_card_Premium : public Client::Debit_card
{
public:

private:
	double maximum_purchase_price = 500000.0;
	double commission = 0.0;
	string type = "Premium";
};
