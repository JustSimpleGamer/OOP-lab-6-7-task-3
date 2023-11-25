#include "Client+Card+Debit_card+Credit_card.h"

double Client::Debit_card::get_money_on_card()
{
	return this->money_on_card;
}

void Client::Debit_card::set_money_on_card(double money)
{
	this->money_on_card = money;
}

void Client::Debit_card::change_money_on_card(double money)
{
	this->money_on_card = this->money_on_card - money;
}

void Client::Debit_card::set_card_attributes(bool access, string card_number, int number_of_operations, double money_on_card)
{
	this->access = access;
	this->card_number = card_number;
	this->number_of_operations = number_of_operations;
	this->money_on_card = money_on_card;
}

Client::Debit_card::Debit_card(bool access, string card_number, double money_on_card) : Card(access, card_number)
{
	this->money_on_card = money_on_card;
}

Client::Debit_card::Debit_card()
{
	this->access = false;
	this->card_number = "";
	this->money_on_card = 0;
}

Client::Debit_card::Debit_card(const Debit_card& cd)
{
	this->access = cd.access;
	this->card_number = cd.card_number;
	this->number_of_operations = cd.number_of_operations;
	this->money_on_card = cd.money_on_card;
}

Client::Debit_card::~Debit_card()
{
	cout << "Об'єкт класу \"Debit_card\" був видалений" << endl;
}



