#include "Console_output_copier.h"
#include "File_stream.h"
#include "Sub_main.h"

MyStreambuf::~MyStreambuf()
{
	cout << "Об'єкт класу \"MyStreambuf\" був видалений";

	restart_cin();

	//temp2w.close();

	cin.get();
}