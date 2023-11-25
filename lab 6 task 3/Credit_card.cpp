#include "Client+Card+Debit_card+Credit_card.h"

unsigned int Client::Credit_card::get_credit_limit()
{
	return this->credit_limit;
}

void Client::Credit_card::set_credit_limit(int credit_limit)
{
	this->credit_limit = credit_limit;
}

double Client::Credit_card::get_credit()
{
	return this->credit;
}

void Client::Credit_card::set_credit(double credit)
{
	this->credit = credit;
}

void Client::Credit_card::change_credit(double price)
{
	this->credit += price;
}

void Client::Credit_card::set_card_attributes(bool access, string card_number, int number_of_operations, int credit_limit, double credit)
{
	this->access = access;
	this->card_number = card_number;
	this->number_of_operations = number_of_operations;
	this->credit_limit = credit_limit;
	this->credit = credit;
}

Client::Credit_card::Credit_card(bool access, string card_number, double credit, int credit_limit) : Card(access, card_number)
{
	this->credit = credit;
	this->credit_limit = credit_limit;
}

Client::Credit_card::Credit_card()
{
	this->access = false;
	this->card_number = "";
	this->credit = 0;
	this->credit_limit = 0;
}

Client::Credit_card::Credit_card(const Credit_card& cd)
{
	this->access = cd.access;
	this->card_number = cd.card_number;
	this->number_of_operations = cd.number_of_operations;
	this->credit = cd.credit;
	this->credit_limit = cd.credit_limit;
}

Client::Credit_card::~Credit_card()
{
	cout << "Об'єкт класу \"Credit_card\" був видалений" << endl;
}