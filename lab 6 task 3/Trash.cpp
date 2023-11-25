#include "Trash.h"
#include "Sub_main.h"

void addtional_method()
{
	cout << "Введіть кількість елементів у масиві: ";
	int size = check_int_corectness(1);

	int* array = new int[size];

	cout << "[ ";
	for (int i = 0; i < size; i++)
	{
		cout << (array[i] = rand() % 100);
		cout << " ";
	}
	cout << "]" << endl << endl;

	bool swapped;
	for (int i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}

	cout << "Відсортований масив" << endl << endl;

	cout << "[ ";
	for (int i = 0; i < size; i++)
	{
		cout << array[i];
		cout << " ";
	}
	cout << "]" << endl << endl;

	delete[] array;

	return;
}

void addtional_method(Client::Debit_card& dc, Client::Credit_card& cc)
{
	//Провести певні обчислення
	cout << "Результат \"певних обчислень\": " << dc.get_money_on_card() + cc.get_credit_limit() + cc.get_credit() + cc.get_number_of_operations() << endl << endl;
}

Client::Credit_card addtional_method_class(Client::Credit_card& cc)
{
	cout << "Результат \"певних обчислень\": " << cc.get_credit_limit() + cc.get_credit() + cc.get_number_of_operations() << endl << endl;
	return cc;
}

Binary_overload operator + (Binary_overload obj1, Binary_overload obj2)
{
	return (Binary_overload(obj1.get_var() + obj2.get_var()));
}

Binary_overload operator - (Binary_overload obj1, Binary_overload obj2)
{
	return (Binary_overload(obj1.get_var() - obj2.get_var()));
}

Binary_overload operator * (Binary_overload obj1, Binary_overload obj2)
{
	return (Binary_overload(obj1.get_var() * obj2.get_var()));
}

Binary_overload operator / (Binary_overload obj1, Binary_overload obj2)
{
	return (Binary_overload(obj1.get_var() / obj2.get_var()));
}

