#include "Main_header.h"

using namespace std;

//c++ singleton
	//SOLID
	//Design pattern Strategy
	//Design pattern Factory
	//Design pattern Singleton
	//Design patterr adapter
	//Design pattern decorator
	//Design pattern bridge

	//Smart pointer
	//Move semantics

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//check_folder_existence("test");

	File_stream console_output("output_content/ConsoleOutput.txt");
	MyStreambuf streambuf(console_output.stream.rdbuf(), cout.rdbuf());
	cout.rdbuf(&streambuf);
	console_output.close();

	//system("mode con width=125 higth=100");
	MoveCenter();

	Client client;
	Client::Debit_card debit_card;
	Client::Credit_card credit_card;

	Administator* temp_adm = new low_level_Administrator;
	shared_ptr<Administator>admin(temp_adm);

	Products products;

	//Client::Credit_card* index_of_credit_card = &credit_card; //покажчик на екземпляр класу
	//credit_card = new Credit_card_Universal;

	read_data(debit_card);
	read_data(credit_card);
	read_data(products);

	main_script(client, debit_card, credit_card, products, *admin, console_output);

	save_data(debit_card);
	save_data(credit_card);
	save_data(products);

	//return 0;
}

