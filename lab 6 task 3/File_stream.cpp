#include "File_stream.h"
#include "Client+Card+Debit_card+Credit_card.h"

File_stream::File_stream(string file_name)
{
	this->file_name = file_name;
}

void File_stream::open(Open_mode mode)
{
	switch (mode)
	{
	case WRITE:
		this->stream.open(file_name, ios::out);
		break;

	case ADD:
		this->stream.open(file_name, ios::app);
		break;

	case READ:
		this->stream.open(file_name, ios::in);
		break;
	}
}

void File_stream::close()
{
	this->stream.close();
}

void File_stream::clear()
{
	this->open(WRITE);
	this->close();
}

void File_stream::clear_log()
{
	this->stream.clear();
}

void File_stream::write(string data, Open_mode mode)
{
	if (this->stream.is_open())
	{
		this->close();
		this->open(mode);
		stream << data << endl;
		this->close();
		this->open(ADD);
	}
	else
	{
		this->open(mode);
		stream << data << endl;
		this->close();
	}
}

void File_stream::write(int data, Open_mode mode)
{
	if (this->stream.is_open())
	{
		this->close();
		this->open(mode);
		stream << data << endl;
		this->close();
		this->open(ADD);
	}
	else
	{
		this->open(mode);
		stream << data << endl;
		this->close();
	}
}

void File_stream::write(double data, Open_mode mode)
{
	if (this->stream.is_open())
	{
		this->close();
		this->open(mode);
		stream << data << endl;
		this->close();
		this->open(ADD);
	}
	else
	{
		this->open(mode);
		stream << data << endl;
		this->close();
	}
}

void File_stream::write(Client::Debit_card& dc)
{
	this->check_file_existence();

	this->open(WRITE);

	this->stream << dc.get_access() << endl << dc.get_card_number() << endl << dc.get_number_of_operations() << endl << dc.get_money_on_card();

	this->close();
}

void File_stream::read(Client::Debit_card& dc)
{
	this->check_file_existence();

	bool access;
	string card_number;
	int number_of_operations;
	double money_on_card;

	this->open(READ);

	this->stream >> access >> card_number >> number_of_operations >> money_on_card;

	dc.set_card_attributes(access, card_number, number_of_operations, money_on_card);

	this->close();
}

void File_stream::write(Client::Credit_card& cc)
{
	this->check_file_existence();

	this->open(WRITE);

	this->stream << cc.get_access() << endl << cc.get_card_number() << endl << cc.get_number_of_operations() << endl << cc.get_credit_limit() << endl << cc.get_credit();

	this->close();
}

void File_stream::read(Client::Credit_card& cc)
{
	this->check_file_existence();

	bool access;
	string card_number;
	int number_of_operations;
	unsigned int credit_limit;
	double credit;

	this->open(READ);

	this->stream >> access >> card_number >> number_of_operations >> credit_limit >> credit;

	cc.set_card_attributes(access, card_number, number_of_operations, credit_limit, credit);

	this->close();
}

void File_stream::copy_to(File_stream& file)
{
	this->open(READ);
	file.open(WRITE);

	file.stream << this->stream.rdbuf();;

	file.close();
	this->close();
}

void File_stream::copy_from(File_stream& file, Open_mode mode)
{
	file.open(READ);
	this->open(mode);

	this->stream << file.stream.rdbuf();

	file.close();
	this->close();
}

string File_stream::read()
{
	string data;
	this->open(READ);
	//this->stream >> data;
	getline(this->stream, data);
	this->close();

	return data;
}

string File_stream::read(Read_mode mode)
{
	string data = "NULL";

	switch (mode)
	{
	case NOT_OPEN_NOT_CLOSE:
		if (this->stream.is_open())
		{
			getline(this->stream, data);
			return data;
		}
		break;
	default:
		return data;
		break;
	}
}

void File_stream::display_content()
{
	bool end = false, first_endl = false;
	string line;

	this->open(READ);

	while (end == false)
	{
		if (!getline(this->stream, line))
		{
			this->close();
			return;
		}
		else
		{
			if (first_endl == false)
			{
				first_endl = true;
				cout << line;
			}
			else
			{
				cout << endl << line;
			}
		}
	}

	/*while (getline(this->stream, line))
	{
		cout << line << endl;
	}*/
}

string File_stream::get_file_name()
{
	return this->file_name;
}

void File_stream::check_file_existence()
{
	try
	{
		this->open(READ);
		if (this->stream)
		{
			this->close();
			return;
		}
		else
		{
			throw ERROR;
		}
	}
	catch (int)
	{
		cout << "Помилка при відкритті файлу \"" << this->file_name << "\"";
		exit(-1);
	}
}

bool File_stream::eof()
{
	if (this->stream.eof())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void File_stream::seekg(streampos _Pos)
{
	this->stream.seekg(_Pos);
}