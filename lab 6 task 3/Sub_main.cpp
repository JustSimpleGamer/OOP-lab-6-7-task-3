#include "File_stream.h"
#include "Sub_main.h"
#include "Trash.h"
#include "Product.h"

File_stream temp1("output_content/temp1.txt");
File_stream temp2("output_content/temp2.txt");

namespace global 
{
	File_stream *console_output;
}

namespace class_template
{
	Product TEMPLATE_Product;
}

void main_script(Client& cl, Client::Debit_card& dc, Client::Credit_card& cc, Products& pr, Administator& adm, File_stream& stream)
{
	int acess_way, way_of_operation, card_var = 0;

	global::console_output = &stream;

	temp1.clear();
	global::console_output->clear();

	global::console_output->open(ADD);

	Print_in_center("<<Вас вітає система обробки платежів \"Платежі\">>");

	cout << endl << "Бажаєте ввійти як клієнт? (1)" << endl << "Бажаєте ввійти як адміністратор? (2)" << endl << "Бажаєте ввійти у режим тестування (3)" << endl << "Оберіть тип входу: ";

	return_back();

	acess_way = check_way(3, 0);

	if (acess_way == 1)
	{
		cout << "Номер дебітової картки: " << dc.get_good_card_number() << endl;
		cout << "Дійсність дебітової картки: " ;

		if (dc.get_access() == true)
		{
			cout << "Дісна" << endl;
			
			cout << "Кількість грошей на дебітовій картці: " << dc.get_money_on_card() << endl;
			cout << "Кількість проведений операцій: " << dc.get_number_of_operations() << endl << endl;
		}
		else
		{
			cout << "Рахунок онульований" << endl << endl;
		}

		cout << "Номер кредитної картки: " << cc.get_good_card_number() << endl;
		cout << "Дійсність дебітової картки: ";

		if (cc.get_access() == true)
		{
			cout << "Дісна" << endl;
			
			cout << "Кредитний ліміт: " << cc.get_credit_limit() << endl;
			cout << "Кредит: " << cc.get_credit() << endl;
			cout << "Кількість проведений операцій: " << cc.get_number_of_operations() << endl << endl;
		}
		else
		{
			cout << "Заблокована" << endl << endl;
		}

		if (dc.get_access() != false || cc.get_access() != false)
		{
			cout << "Бажаєте здійснити покупку (1), перевести гроші на іншу картку (2), заблокувати одну з карток (3) чи анулювати рахунок (4)?" << endl;
			cout << "Введіть цифру: ";

			way_of_operation = check_way(4, 0);

			switch (way_of_operation)
			{
			case 1:
				cl.pay_for_the_order(dc, cc, pr);
				break;
			case 2:
				cl.make_payment_on_other_card(dc);
				break;
			case 3:
				switch (card_var)
				{
				case 1:
					cl.block_card(dc);
					break;
				case 2:
					cl.block_card(cc);
					break;
				}
				break;
			case 4:
				cl.annul_money(dc);
				break;
			}
		}
	}

	if (acess_way == 2)
	{
		cout << "Рівень доступу адмінстратора: " << adm.get_access_level() << endl << endl;
		cout << "Бажаєте проініціалізувати одну з карткок клієнта (1), змінити стан доступу до однієї з карток (2), змінити список товарів (3), змінити один з товарів (4) чи видалити товар (5)?" << endl << endl;
		cout << "Ввеідть число: ";

		//return_back();

		way_of_operation = check_way(5, 0);

		switch (way_of_operation)
		{
		case 1:
			cout << "Бажаєте проініціалізувати дебітову (1) чи кредтину (2) картку?" << endl;
			cout << "Введть число: ";
			card_var = check_way(2, 0);
			switch (card_var)
			{
			case 1:
				adm.initialize_card(dc);
				break;
			case 2:
				adm.initialize_card(cc);
				break;
			}
			break;

		case 2:
			cout << "Бажаєте заблокувати дебітову (1) чи кредтину (2) картку?" << endl;
			cout << "Введть число: ";
			card_var = check_way(2, 0);

			switch (card_var)
			{
			case 1:
				adm.change_access_of_card(dc);
				break;
			case 2:
				adm.change_access_of_card(cc);
				break;
			}
			break;

		case 3:
			adm.initiliaze_products(pr);
			break;

		case 4:
			adm.change_product(pr);
			break;

		case 5:
			adm.delete_product_s(pr);
			break;
		}
	}

	if (acess_way == 3)
	{
		/*cout << "Відтестити додатковий метод в класі, який виділяє випадкову величину динамічної пам’яті, в якій буде розміщена множина значень на N елементів, після чого вони будуть відсортовані (1)?" << endl << endl;
		cout << "Відтестити один з перевантажених методів (2) або (3)" << endl << endl;
		cout << "Відтестити метод, що повертає об'єкт класу Credit_card (4)" << endl << endl;
		cout << "Відтетсти стоворення трьох об\'єктів різних класів, після чого створити похдіний об\'єкт, наслідуваний від трьох попередніх (5)?" << endl << endl;
		cout << "Ввеідть число: ";*/


		//way_of_operation = check_way(7, 0);


		addtional_method();
		

		addtional_method(dc, cc);
		

		//addtional_method(&cd, 1.0);
		

		Client::Credit_card temp = *new Client::Credit_card;
		temp = addtional_method_class(cc);
		//delete temp;
		
		
		Additional_Class_123 add(0, 1, 2, 3);
		Derivative_from_abstract_1 dfa1;
		Derivative_from_abstract_2 dfa2;
		Derivative_from_abstract_3 dfa3;
		dfa1.abstract_method();
		dfa2.abstract_method();
		dfa3.abstract_method();
		Abstract_class* ac = nullptr;
		ac = new Derivative_from_abstract_1;
		delete ac;
		ac = new Derivative_from_abstract_2;
		delete ac;
		ac = new Derivative_from_abstract_3;
		delete ac;
		Derivative_from_abstract_1* ac1 = nullptr;
		Derivative_from_abstract_2* ac2 = nullptr;
		Derivative_from_abstract_3* ac3 = nullptr;
		ac1 = ac1->try_create_object();
		ac2 = ac2->try_create_object();
		ac3 = ac3->try_create_object();
		delete ac1;
		delete ac2;
		delete ac3;


		Unary_overload unary_overloaded(10);
		--unary_overloaded;
		cout << unary_overloaded.get_var() << endl;
		unary_overloaded--;
		cout << unary_overloaded.get_var() << endl;
		++unary_overloaded;
		cout << unary_overloaded.get_var() << endl;
		unary_overloaded++;
		cout << unary_overloaded.get_var() << endl << endl;


		Binary_overload binary_overloaded1(10);
		Binary_overload binary_overloaded2(-20);
		binary_overloaded1 = -binary_overloaded2;
		cout << binary_overloaded1.get_var()<< endl;
		binary_overloaded1 = +binary_overloaded2;
		cout << binary_overloaded1.get_var() << endl << endl;
		Binary_overload binary_overloaded3;
		binary_overloaded3 = binary_overloaded1 + binary_overloaded2;
		cout << binary_overloaded3.get_var() << endl;
		binary_overloaded3 = binary_overloaded1 - binary_overloaded2;
		cout << binary_overloaded3.get_var() << endl;
		binary_overloaded3 = binary_overloaded1 * binary_overloaded2;
		cout << binary_overloaded3.get_var() << endl;
		binary_overloaded3 = binary_overloaded1 / binary_overloaded2;
		cout << binary_overloaded3.get_var() << endl << endl;


		Comparison_overload comparison_overload1(10);
		Comparison_overload comparison_overload2(20);
		cout << (comparison_overload1 < comparison_overload2) << endl << (comparison_overload1 > comparison_overload2) << endl << (comparison_overload1 == comparison_overload2) << endl << (comparison_overload1 != comparison_overload2) << endl << endl;
		

		Assignment assigment1(20);
		Assignment assigment2(20);
		assigment1 += assigment2;
		cout << assigment1.get_var() << endl;
		assigment1 -= assigment2;
		cout << assigment1.get_var() << endl;
		assigment1 *= assigment2;
		cout << assigment1.get_var() << endl;
		assigment1 /= assigment2;
		cout << assigment1.get_var() << endl << endl;


		Template_class<int, bool, char, double, float> temp_class(10, true, *"word", 1.2, 5.0);




		list<int> list_(10, 0);
		int i = 0;
		for (list<int>::iterator iter = list_.begin(); iter != list_.end(); iter++)
		{
			*iter = i;
			cout << *iter << " ";
			i++;
		}
		list<int>::iterator iter;
		list_.push_back(10);
		iter = list_.end();
		cout << *--iter << " ";
		list_.push_front(-1);
		iter = list_.begin();
		cout << *iter << " ";
		list_.emplace(iter, -2);
		cout << *list_.begin() << endl << endl;

		
		deque<int> deque_(10, 0);
		for (deque<int>::iterator iter = deque_.begin(); iter != deque_.end(); iter++)
		{
			//*iter = i;
			cout << *iter << " ";
			//i++;
		}
		cout << endl;
		deque_.insert(deque_.begin(), 3, 5);
		for (deque<int>::iterator iter = deque_.begin(); iter != deque_.end(); iter++)
		{
			//*iter = i;
			cout << *iter << " ";
			//i++;
		}
		cout << endl;
		deque_.insert(deque_.begin()+5, 2, 7);
		for (deque<int>::iterator iter = deque_.begin(); iter != deque_.end(); iter++)
		{
			//*iter = i;
			cout << *iter << " ";
			//i++;
		}
		deque_.emplace(deque_.begin(), 9);
		cout << endl;
		for (deque<int>::iterator iter = deque_.begin(); iter != deque_.end(); iter++)
		{
			//*iter = i;
			cout << *iter << " ";
			//i++;
		}
		cout << endl << endl;


		set<int> set_;
		set_.insert(1);
		set_.insert(2);
		set_.insert(2);
		set_.insert(3);
		for (int n : set_)
		{
			//*iter = i;
			cout << n << " ";
			//i++;
		}
		cout << endl;
		set_.erase(2);
		for (int n : set_)
		{
			//*iter = i;
			cout << n << " ";
			//i++;
		}
		cout << endl << set_.count(1) << " " << set_.count(2) << endl << endl;


		multiset<int> multiset_;
		multiset_.insert(1);
		multiset_.insert(2);
		multiset_.insert(2);
		multiset_.insert(3);
		for (int n : multiset_)
		{
			//*iter = i;
			cout << n << " ";
			//i++;
		}
		cout << endl;
		multiset_.erase(2);
		for (int n : multiset_)
		{
			//*iter = i;
			cout << n << " ";
			//i++;
		}
		cout << endl << multiset_.count(1) << " " << multiset_.count(2) << endl << endl;


		stack<int> stack_;
		stack_.push(1);
		stack_.push(2);
		stack_.push(3);
		cout << stack_.top() << endl;
		stack_.pop();
		cout << stack_.top() << endl;
		cout << stack_.size() << " " << stack_.empty() << endl << endl;


		queue<int> queue_;
		queue_.push(1);
		queue_.push(2);
		queue_.push(3);
		queue_.push(4);
		queue_.push(5);
		cout << queue_.back() << " " << queue_.front() << endl;
		queue_.pop();
		cout << queue_.back() << " " << queue_.front() << endl << endl;


		priority_queue<int> priority_queue_;
		priority_queue_.push(1);
		priority_queue_.push(2);
		priority_queue_.push(3);
		priority_queue_.push(4);
		priority_queue_.push(5);
		while(!priority_queue_.empty())
		{
			cout << priority_queue_.top() << " ";
			priority_queue_.pop();
		}
		cout << endl << endl;

		
		Functor::Plus<int> plus;
		int a = 4;
		int b = 2;
		cout << plus(a, b) << endl;


		//Class_as_parameter class_as_parameter(10);
		//Template_class_with_class_as_Parameter<class_as_parameter.get_var()>;
	}
	//delete streambuf;f
	return_to_start(cl, dc, cc, pr, adm, *global::console_output);
}

int check_int_corectness(int type)
{
	return_back();
	global::console_output->close();

	//return_back();

	int variable;

	if (!(cin >> variable))
	{
		do
		{
			try_again();

			cout << "Будь-ласка, введіть коректне значення" << endl << "Введіть число: ";

			restart_cin();
		} while (!(cin >> variable));
	}

	if (type == 1)
	{
		if (variable < 0)
		{
			do
			{
				try_again();

				cout << "Будь-ласка, введіть коректне число" << endl << "Введіть число: ";

				restart_cin();
			} while (!(cin >> variable) || variable < 0);
		}
	}

	if (type == 0)
	{
		/*if (!(cin >> variable))
		{
			do
			{
				try_again();

				cout << "Будь-ласка, введіть коректне значення" << endl << "Введіть число: ";

				restart_cin();
			} while (!(cin >> variable));
		}*/

		//global::console_output->write("\n", ADD);
	}
	//global::console_output->write("\n", ADD);

	return_back(variable);
	cout << endl;
	return variable;
}

int check_way(int way, int sub_way)
{
	//temp2w.close();
	return_back();
	global::console_output->close();

	int type = 0;

	if (!(cin >> type))
	{
		//ConsoleOutput_try_again("Будь-ласка, введіть коректне значення");
		do
		{
			try_again();

			cout << "Будь-ласка, введіть коректне значення" << endl << "Введіть число: ";

			restart_cin();

		} while (!(cin >> type));
		//return_back(type);
	}

	if (type == 0)
	{
		return_back(type);
		cout << endl;
		return 0;
	}

	if (way == 1)
	{
		if (type != 2)
		{
			cout << endl;
			do
			{
				try_again();

				cout << "Оплата з рахунку неможлива. Доступний варіант: в кредит (2)" << endl << endl << "Оберіть тип оплати: ";

				restart_cin();
				cin >> type;
			} while (type != 2);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 2)
	{
		if (type != 1 && type != 2)
		{
			cout << endl;
			do
			{
				try_again();

				cout << "Будь-ласка, введіть коректне число" << endl << "Введіть число: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 3)
	{
		if (type != 1 && type != 2 && type != 3)
		{
			cout << endl;
			do
			{
				try_again();

				cout << "Будь-ласка, введіть коректне число" << endl << "Введіть число: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2 && type != 3);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 4)
	{
		if (type != 1 && type != 2 && type != 3 && type != 4)
		{
			cout << endl;
			do
			{
				try_again();

				cout << "Будь-ласка, введіть коректне число" << endl << "Введіть число: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2 && type != 3 && type != 4);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 5 && sub_way == 0)
	{
		if (type != 1 && type != 2 && type != 3 && type != 4 && type != 5)
		{
			cout << endl;
			do
			{
				try_again();

				cout << endl << endl << "Будь-ласка, введіть коректне число" << endl << "Введіть число: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2 && type != 3 && type != 4 && type != 5);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 5 && sub_way == 1)
	{
		if (type != 1 && type != 2 && type != 3 && type != 4 && type != 5)
		{
			cout << endl;
			do
			{
				try_again();

				cout << endl << "Товару під таким номером не існує. Будь-ласка, введіть коректне число" << endl << "Введіть число: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2 && type != 3 && type != 4 && type != 5);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 6 && sub_way == 0)
	{
		if (type != 1 && type != 2 && type != 3 && type != 4 && type != 5 && type != 6)
		{
			cout << endl;
			do
			{
				try_again();

				cout << "Будь-ласка, введіть коректне число" << endl << "Введіть число: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2 && type != 3 && type != 4 && type != 5 && type != 6);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 7 && sub_way == 0)
	{
		if (type != 1 && type != 2 && type != 3 && type != 4 && type != 5 && type != 6 && type != 7)
		{
			cout << endl;
			do
			{
				try_again();

				cout << "Будь-ласка, введіть коректне число" << endl << "Введіть число: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2 && type != 3 && type != 4 && type != 5 && type != 7);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}
	//temp2w_open();

	return type;
}

string check_card_number_corectness()
{
	string card_number;
	card_number.reserve(16);
	bool corrected = true;

	restart_cin();
	//getline(cin, card_number);
	cin >> card_number;

	return_back();
	global::console_output->close();

	for (int i = 0; i < card_number.size(); i++)
	{
		if (!(isdigit(card_number[i])))
		{
			corrected = false;
		}
	}

	if (card_number.size() != 16 || corrected == false)
	{
		do
		{
			try_again();
			cout << "Некоректний запис номеру картки" << endl << "Введіть номер картки: ";
			restart_cin();

			//getline(cin, card_number);
			cin >> card_number;

			corrected = true;
			for (int i = 0; i < card_number.size(); i++)
			{
				if (!(isdigit(card_number[i])))
				{
					corrected = false;
				}
			}
		} while (card_number.size() != 16 && corrected == false);
	}

	//cout << endl;
	return_back(card_number);
	cout << endl;
	return card_number;
}

void MoveWindow(int posx, int posy)
{
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void MoveCenter()
{
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	int posx, posy;
	posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2;
	posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;

	MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void Print_in_center(const string& s)
{
	int width_field = 120;
	string v(width_field, ' ');
	string v1;

	size_t l_word = s.size();
	size_t l_field = v.size();
	size_t step = (l_field - l_word) / 2;

	for (int i = 0; i < l_word; i++) {
		v1.push_back(s[i]);
	}
	copy(v1.begin(), v1.end(), v.begin() + step);
	for (auto x : v) {
		cout << x;
	}
	cout << endl;
}

void save_data(Client::Debit_card& dc)
{
	File_stream file("files/Client/Debit card.txt");
	file.write(dc);
}

void read_data(Client::Debit_card& dc)
{
	File_stream file("files/Client/Debit card.txt");
	file.read(dc);
}

void save_data(Client::Credit_card& cc)
{
	File_stream file("files/Client/Credit card.txt");
	file.write(cc);
}

void read_data(Client::Credit_card& cc)
{
	File_stream file("files/Client/Credit card.txt");
	file.read(cc);
}

void save_data(Products& products)
{
	//vector <Product> array = products.get_array();

	ofstream file("files/Products.txt");

	file << products.get_size() << endl;

	for (int i = 0; i < products.get_size(); i++)
	{
		file << products[i].get_name() << endl << products[i].get_price();

		if (!(i == products.get_size() - 1))
		{
			file << endl;
		}
	}

	file.close();
}

void read_data(Products& products)
{
	//fstream file("files/Products.txt");
	File_stream file("files/Products.txt");

	file.check_file_existence();

	string name, s_price;
	double d_price;
	size_t size;

	/*Product* product = nullptr;
	shared_ptr<Product> ptr(product);*/

	//shared_ptr<Product> product(try_create_object(class_template::TEMPLATE_Product));
	shared_ptr<Product> product(try_create_object(class_template::TEMPLATE_Product));

	file.open(READ);

	size = stoi(file.read(NOT_OPEN_NOT_CLOSE));
	products.set_size(size);

	while (!file.eof())
	{
		//file >> name;
		//getline(file.stream, name);
		//getline(file.stream, s_price);

		name = file.read(NOT_OPEN_NOT_CLOSE);
		s_price = file.read(NOT_OPEN_NOT_CLOSE);

		d_price = stod(s_price);

		product->set_product(name, d_price);
		products.push(product);
		//d_price = stod(s_price);
		//getline(file, price);
	}

	file.close();
}

void check_folder_existence(string folder_name)
{
	size_t length = folder_name.length() + 1;
	char line[255];
	strcpy(line, folder_name.c_str());

	try
	{
		if (_mkdir(line) == -1)
		{
			cout << "Помилка при створенні папки \"" << folder_name << "\". Папка вже існує";
		}
		else
		{
			throw ERROR;
		}
	}
	catch (int)
	{
		//cout << "Папка під назвою \"" << folder_name << "\" була створена";
		_rmdir(line);
		//exit(-1);
	}
}

//void ConsoleOutput_open()
//{
//	global_stream->open("ConsoleOutput.txt", ios::app);
//}

//void ConsoleOutput_clear()
//{
//	global_stream->open("ConsoleOutput.txt", ios::out);
//	global_stream->close();
//}

//void ConsoleOutput_write(string string_line)
//{
//	cout << string_line;
//	global_stream->close();
//	return_back();
//}

//void temp1w_open()
//{
//	temp1w.open("temp1.txt", ios::app);
//}

//void temp1r_open()
//{
//	temp1r.open("temp1.txt");
//}

//void temp1_clear()
//{
//	temp1w.open("temp1.txt", ios::out);
//	temp1w.close();
//}

//void temp2w_open()
//{
//	temp2w.open("temp2.txt", ios::app);
//}

//void temp2r_open()
//{
//	temp2r.open("temp2.txt");
//}

//void temp2_clear()
//{
//	temp2w.open("temp2.txt", ios::out);
//	temp2w.close();
//}

void try_again()
{
	bool end = false, first_endl = false;
	string line1;

	//temp2_clear();
	temp2.clear();

	//temp1w.open("temp1.txt", ios::in);
	//temp1.open(READ);
	//temp2w_open();
	//temp2.open(ADD);
	//temp2w << temp1w.rdbuf() << endl << endl;
	temp2.copy_from(temp1, ADD);
	temp2.write("\n\n", ADD);
	//temp2w.close();
	//temp2.close();
	//temp1w.close();
	//temp1.close();

	system("cls");

	//temp2r_open();

	temp2.display_content();

	//temp2r.close();
}

void restart_cin()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

void return_to_start(Client& cl, Client::Debit_card& dc, Client::Credit_card& cc, Products& pr, Administator& adm, File_stream& stream)
{
	int type;

	//restart_cin();

	cout << "Бажаєте повернутися на початок?" << endl << "Так (1) Ні (2)" << endl << endl;
	cout << "Введіть цифру: ";

	type = check_way(2, 0);
	if (type == 0)
	{
		return;
	}

	if (type == 1)
	{
		global::console_output->close();
		global::console_output->clear();

		temp1.clear();

		system("cls");
		main_script(cl, dc, cc, pr, adm, stream);
	}
	if (type == 2)
	{
		system("cls");
		cout << "Роботу програми було закінчено" << endl << endl;

		global::console_output->close();
	}
}

void return_back(int input)
{
	global::console_output->close();
	//global_stream << input;
	//c++ singleton
	//SOLID
	//Design pattern Strategy
	//Design pattern Factory
	//Design pattern Singleton
	//Design patterr adapter
	//Design pattern decorator
	//Design pattern bridge

	//global_stream->close();

	bool end = false, first_endl = false;

	//global_stream->open("ConsoleOutput.txt", ios::app);
	//cout << endl;
	//global_stream->close();

	//console_output->open(READ);
	//ofstream temp1("temp.txt", ios::app);
	//temp1w_open();
	temp1.copy_from(*global::console_output, ADD);
	//temp1w << global_stream->rdbuf();
	//temp1w.close();

	//temp1w_open();
	temp1.write(input, ADD);
	//temp1w << input << endl;
	//temp1w.close();

	//global_stream->close();

	//global_stream->open("ConsoleOutput.txt", ios::out);
	//global_stream->close();

	system("cls");

	//ifstream temp2("temp.txt");
	string line1, line2;

	temp1.display_content();

	cout << endl;

	global::console_output->clear();
	global::console_output->open(ADD);
}

void return_back(string input)
{
	global::console_output->close();
	//global_stream << input;
	//c++ singleton
	//SOLID
	//Design pattern Strategy
	//Design pattern Factory
	//Design pattern Singleton
	//Design patterr adapter
	//Design pattern decorator
	//Design pattern bridge

	//global_stream->close();

	bool end = false, first_endl = false;

	//global_stream->open("ConsoleOutput.txt", ios::app);
	//cout << endl;
	//global_stream->close();

	//console_output->open(READ);
	//ofstream temp1("temp.txt", ios::app);
	//temp1w_open();
	temp1.copy_from(*global::console_output, ADD);
	//temp1w << global_stream->rdbuf();
	//temp1w.close();

	//temp1w_open();
	temp1.write(input, ADD);
	//temp1w << input << endl;
	//temp1w.close();

	//global_stream->close();

	//global_stream->open("ConsoleOutput.txt", ios::out);
	//global_stream->close();

	system("cls");

	//ifstream temp2("temp.txt");
	string line1, line2;

	temp1.display_content();

	cout << endl;

	global::console_output->clear();
	global::console_output->open(ADD);
}

void return_back()
{
	global::console_output->close();

	bool end = false, first_endl = false;

	//global_stream->open("ConsoleOutput.txt", ios::app);
	//cout << endl;
	//global_stream->close();

	//console_output->open(READ);
	//ofstream temp1("temp.txt", ios::app);
	//temp1w_open();
	temp1.copy_from(*global::console_output, ADD);
	//temp1w << global_stream->rdbuf();
	//temp1w.close();
	//global_stream->close();

	//global_stream->open("ConsoleOutput.txt", ios::out);
	//global_stream->close();

	system("cls");

	//ifstream temp2("temp.txt");
	string line1, line2;

	temp1.display_content();

	//cout << endl;

	global::console_output->clear();
	global::console_output->open(ADD);
}

template <typename T> shared_ptr<T> try_create_object(T)
{
	try
	{
		T* temp = new T;
		if (temp != NULL)
		{
			shared_ptr<T> ptr(temp);
			return ptr;
		}
		else
		{
			throw ERROR;
		}
	}
	catch (int)
	{
		cerr << "Помилка при виділенні пам\'яті під об\'єкт" << endl;
		exit(-1);
	}
}