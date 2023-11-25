#pragma once

#include "Libraries.h"
#include "Client+Card+Debit_card+Credit_card.h"

enum Open_mode
{
	WRITE, ADD, READ
};

enum Read_mode
{
	NOT_OPEN_NOT_CLOSE
};

class File_stream
{
public:
	File_stream(string name);

	void open(Open_mode mode);
	void close();
	void clear();
	void clear_log();

	void write(string data, Open_mode mode);
	void write(int data, Open_mode mode);
	void write(double data, Open_mode mode);

	void write(Client::Debit_card& dc);
	void read(Client::Debit_card& dc);

	void write(Client::Credit_card& dc);
	void read(Client::Credit_card& dc);

	string read();
	string read(Read_mode mode);

	void display_content();

	void copy_to(File_stream& file);
	void copy_from(File_stream& file, Open_mode mode);

	string get_file_name();

	void check_file_existence();

	bool eof();
	void seekg(streampos _Pos);

	fstream stream; //вимушений крок
private:
	string file_name;
};