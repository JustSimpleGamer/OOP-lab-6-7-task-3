#pragma once

#include "Libraries.h"
#include "Client+Card+Debit_card+Credit_card.h"
#include "Products.h"
//#include "Other.h"
//#include "File_stream.h"

//enum access_level
//{
//	LOW_ACCESS_LEVEL, MEDIUM_ACCESS_LEVEL, HIGH_ACCESS_LEVEL
//};

class Administator
{
public:
	virtual void change_access_of_card(Client::Debit_card& dc) = 0;
	virtual void change_access_of_card(Client::Credit_card& cc) = 0;

	void initialize_card(Client::Credit_card& cc);
	void initialize_card(Client::Debit_card& dc);

	void initiliaze_products(Products& pr);
	void change_product(Products& pr);

	virtual string get_access_level() = 0;
	virtual void delete_product_s(Products& pr) = 0;

	virtual ~Administator();
private:
	string access_level;
};

class low_level_Administrator : public Administator
{
public:
	void change_access_of_card(Client::Debit_card& dc);
	void change_access_of_card(Client::Credit_card& cc);

	void delete_product_s(Products& pr);

	string get_access_level();
private:
};

class medium_level_Administrator : public Administator
{
public:
	void change_access_of_card(Client::Debit_card& dc);
	void change_access_of_card(Client::Credit_card& cc);

	void delete_product_s(Products& pr);

	string get_access_level();
private:
};


