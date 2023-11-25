#pragma once

#include "Libraries.h"
#include "Administator.h"
#include "File_stream.h"
#include "Product.h"
//#include "Client+Credit_card.h"
//#include "Products.h"
//#include "File_stream.h"

//int Client::Credit_card::number_of_operations;

namespace global
{
	extern File_stream* console_output;
}

namespace class_template
{
	extern Product TEMPLATE_Product;
}

void main_script(Client&, Client::Debit_card&, Client::Credit_card&, Products&, Administator&, File_stream&);

void return_to_start(Client&, Client::Debit_card& dc, Client::Credit_card&, Products&, Administator&, File_stream&);
void restart_cin();

int check_way(int way, int number);
int check_int_corectness(int limits);
string check_card_number_corectness();

void save_data(Products& products);
void read_data(Products& products);

void save_data(Client::Debit_card& cc);
void read_data(Client::Debit_card& cc);

void save_data(Client::Credit_card& cd);
void read_data(Client::Credit_card& cd);

void MoveWindow(int posx, int posy);
void MoveCenter();

void Print_in_center(const string& s);

void return_back(int type);
void return_back(string type);
void return_back();

void try_again();

void check_folder_existence(string folder_name);

template <typename T> shared_ptr<T> try_create_object(T);

//shared_ptr<Product> try_create_object(Product pr);