#include "Console_output_copier.h"
#include "File_stream.h"
#include "Sub_main.h"

MyStreambuf::~MyStreambuf()
{
	cout << "��'��� ����� \"MyStreambuf\" ��� ���������";

	restart_cin();

	//temp2w.close();

	cin.get();
}