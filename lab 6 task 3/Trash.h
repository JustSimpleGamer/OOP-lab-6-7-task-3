#pragma once

#include "Libraries.h"
#include "Product.h"
#include "Client+Card+Debit_card+Credit_card.h"
#include "Sub_main.h"

#include <list>
#include <deque>
#include <set>
#include <stack>
#include <queue>

void addtional_method();
void addtional_method(Client::Debit_card& dc, Client::Credit_card& cc);
Client::Credit_card addtional_method_class(Client::Credit_card& cc);


class Additional_Class_With_Private_Imitation : private Product
{
public:
	Additional_Class_With_Private_Imitation(string name, double price, int add1, float add2, double add3) : Product(name, price)
	{
		this->add1 = add1;
		this->add2 = add2;
		this->add3 = add3;
	}
private:
	int add1;
	float add2;
	double add3;
};

class Additional_Class_1
{
public:
	Additional_Class_1(int add)
	{
		this->add = add;
		cout << "Був створений об\'єкт класу \"Additional_Class_1\"" << endl;
	}	

	~Additional_Class_1()
	{
		cout << "Об\'єкт класу \"Additional_Class_1\" був видалений" << endl << endl;
	}

	int get_add()
	{
		return this->add;
	}
private:
	int add;
};

class Additional_Class_2
{
public:
	Additional_Class_2(int add)
	{
		this->add = add;
		cout << "Був створений об\'єкт класу \"Additional_Class_2\"" << endl;
	}	

	~Additional_Class_2()
	{
		cout << "Об\'єкт класу \"Additional_Class_2\" був видалений" << endl;
	}

	int get_add()
	{
		return this->add;
	}
private:
	int add;
};

class Additional_Class_3
{
public:
	Additional_Class_3(int add)
	{
		this->add = add;
		cout << "Був створений об\'єкт класу \"Additional_Class_3\"" << endl;
	}	
	
	~Additional_Class_3()
	{
		cout << "Об\'єкт класу \"Additional_Class_3\" був видалений" << endl;
	}

	int get_add()
	{
		return this->add;
	}
private:
	int add;
};

class Additional_Class_123 : public Additional_Class_1, public Additional_Class_2, public Additional_Class_3
{
public:
	Additional_Class_123(int add, int add1, int add2, int add3) : Additional_Class_1(add1), Additional_Class_2(add2), Additional_Class_3(add3)
	{
		this->add = add;
		this->add1 = add1;
		this->add2 = add2;
		this->add3 = add3;
		cout << "Був створений об\'єкт класу \"Additional_Class_123\"" << endl << endl;
	}

	~Additional_Class_123()
	{
		cout << "Об\'єкт класу \"Additional_Class_123\" був видалений" << endl;
	}

	using Add1 = Additional_Class_1;
	using Additional_Class_3::get_add;

	void print()
	{
		cout << Add1::get_add() << Additional_Class_2::get_add() << get_add();
	}
private:
	int add, add1, add2, add3;
};

//

class Abstract_class
{
public:
	void virtual abstract_method() = 0;

	Abstract_class()
	{
		cout << "Виклик конструктору класу \"Abstract_class\"" << endl;
	}

	virtual ~Abstract_class()
	{
		cout << "Об\'єкт класу \"Abstract_class\" був видалений" << endl << endl;
	}
};

class Derivative_from_abstract_1 : public Abstract_class
{
public:
	Derivative_from_abstract_1* try_create_object()
	{
		try
		{
			Derivative_from_abstract_1* temp = nullptr;
			temp = new Derivative_from_abstract_1;
			return temp;
		}
		catch (bad_alloc& e)
		{
			cerr << "Помилка" << endl;
			exit(-1);
		}
	}

	Derivative_from_abstract_1()
	{
		cout << "Виклик конструктору класу \"Abstract_class 1\"" << endl;
	}

	void abstract_method()
	{
		cout << "Виклик методу об\'єкту #1 похідного від абстрактного" << endl;
	}
	virtual ~Derivative_from_abstract_1()
	{
		cout << "Об\'єкт класу \"Derivative_from_abstract_1\" був видалений" << endl;
	}
};

class Derivative_from_abstract_2 : public Abstract_class
{
public:
	Derivative_from_abstract_2* try_create_object()
	{
		try
		{
			Derivative_from_abstract_2* temp = nullptr;
			temp = new Derivative_from_abstract_2;
			return temp;
		}
		catch (bad_alloc& e)
		{
			cerr << "Помилка" << endl;
			exit(-1);
		}
	}

	Derivative_from_abstract_2()
	{
		cout << "Виклик конструктору класу \"Abstract_class 2\"" << endl;
	}

	void abstract_method()
	{
		cout << "Виклик методу об\'єкту #2 похідного від абстрактного" << endl;
	}
	virtual ~Derivative_from_abstract_2()
	{
		cout << "Об\'єкт класу \"Derivative_from_abstract_2\" був видалений" << endl;
	}
};

class Derivative_from_abstract_3 : public Abstract_class
{
public:
	Derivative_from_abstract_3* try_create_object()
	{
		try
		{
			Derivative_from_abstract_3* temp = nullptr;
			temp = new Derivative_from_abstract_3;
			return temp;
		}
		catch (bad_alloc& e)
		{
			cerr << "Помилка" << endl;
			exit(-1);
		}
	}

	Derivative_from_abstract_3()
	{
		cout << "Виклик конструктору класу \"Abstract_class 3\"" << endl << endl;
	}

	void abstract_method()
	{
		cout << "Виклик методу об\'єкту #3 похідного від абстрактного" << endl << endl;
	}
	virtual ~Derivative_from_abstract_3()
	{
		cout << "Об\'єкт класу \"Derivative_from_abstract_3\" був видалений" << endl;
	}
};

class Additional_class_21
{
public:
	int a;
};

//

class Derivative_from_Additional_class_21_1 : virtual public Additional_class_21
{

};

class Derivative_from_Additional_class_21_2 : virtual public Additional_class_21
{

};

class Additional_class_22 : public Derivative_from_Additional_class_21_1, public Derivative_from_Additional_class_21_2
{
public:
	void print()
	{
		cout << a;
	}
};

//

class Unary_overload
{
public:
	Unary_overload(int var)
	{
		this->var = var;
	}
	int get_var()
	{
		return var;
	}
	void print()
	{
		cout << var << endl;
	}

	// пре
	Unary_overload& operator++ ()
	{
		var += 1;
		return *this;
	}
	Unary_overload& operator-- ()
	{
		var -= 1;
		return *this;
	}

	// пост
	Unary_overload operator++ (int)
	{
		Unary_overload copy{ *this };
		++(*this);
		return copy;
	}
	Unary_overload operator-- (int)
	{
		Unary_overload copy = *this;
		--(*this);
		return copy;
	}

private:
	int var;
};

class Binary_overload
{
public:
	Binary_overload()
	{}

	Binary_overload(int var)
	{
		this->var = var;
	}

	int get_var()
	{
		return var;
	}

	Binary_overload operator + ()
	{
		return Binary_overload(fabs(var));
	}

	Binary_overload operator - ()
	{
		return Binary_overload(-var);
	}
private:
	int var;
};

Binary_overload operator + (Binary_overload obj1, Binary_overload obj2);

Binary_overload operator - (Binary_overload obj1, Binary_overload obj2);

Binary_overload operator * (Binary_overload obj1, Binary_overload obj2);

Binary_overload operator / (Binary_overload obj1, Binary_overload obj2);

class Comparison_overload
{
public:
	Comparison_overload(int var)
	{
		this->var = var;
	}

	int get_var()
	{
		return var;
	}

	bool operator == (Comparison_overload & obj)
	{
		return this->var == obj.var;
	}

	bool operator != (Comparison_overload& obj)
	{
		return this->var != obj.var;
	}

	bool operator > (Comparison_overload& obj)
	{
		return this->var > obj.var;
	}

	bool operator < (Comparison_overload& obj)
	{
		return this->var < obj.var;
	}
private:
	int var;
};

class Assignment
{
public:
	Assignment()
	{}

	Assignment(int var)
	{
		this->var = var;
	}

	int get_var()
	{
		return this->var;
	}

	Assignment operator += (Assignment& counter)
	{
		this->var += counter.var;
		return *this;
	}

	Assignment operator -= (Assignment& counter)
	{
		this->var -= counter.var;
		return *this;
	}

	Assignment operator *= (Assignment& counter)
	{
		this->var *= counter.var;
		return *this;
	}

	Assignment operator /= (Assignment& counter)
	{
		this->var /= counter.var;
		return *this;
	}
private:
	int var;
};

template <typename A, typename B, typename C, typename D, typename E>
class Template_class
{
public:
	Template_class(A Int, B Bool, C Char, D Double, E Float)
	{
		this->Int = Int;
		this->Bool = Bool;
		//strcpy(this->Char, Char);
		this->Char = Char;
		this->Double = Double;
		this->Float = Float;
	}

private:
	A Int;
	B Bool;
	C Char;
	D Double;
	E Float;
};

//class Class_as_parameter
//{
//public:
//	Class_as_parameter(int var)
//	{
//		this->var = var;
//	}
//
//	int get_var()
//	{
//		return var;
//	}
//private:
//	int var;
//};

//typedef Class_as_parameter (ClassType);
//template<ClassType CL>

//class Template_class_with_class_as_Parameter
//{
//public:
//	Template_class_with_class_as_Parameter(int var)
//	{
//		this->var = var;
//	}
//private:
//	int var;
//};


class Functor
{
public:
	template <typename T>
	class Plus
	{
	public:
		T operator()(T a, T b)
		{
			return a + b;
		}
	};

	template <typename T>
	class Addition
	{
	public:
		T operator()(T a, T b)
		{
			return a - b;
		}
	};

	template <typename T>
	class Times
	{
	public:
		T operator()(T a, T b)
		{
			return a * b;
		}
	};

	template <typename T>
	class Divides
	{
	public:
		T operator()(T a, T b)
		{
			return a / b;
		}
	};

	template <typename T>
	class Modulus
	{
	public:
		double operator()(T a, T b)
		{
			return a % b;
		}
	};

	template <typename T>
	class Negate
	{
	public:
		T operator()(T a)
		{
			return -a;
		}
	};

	template <typename T>
	class Equal_to
	{
	public:
		bool operator()(T a, T b)
		{
			return a = b;
		}
	};

	template <typename T>
	class Not_equal_to
	{
	public:
		bool operator()(T a, T b)
		{
			return a != b;
		}
	};

	template <typename T>
	class Greater
	{
	public:
		bool operator()(T a, T b)
		{
			return a > b;
		}
	};

	template <typename T>
	class Less
	{
	public:
		bool operator()(T a, T b)
		{
			return a < b;
		}
	};

	template <typename T>
	class Greater_equal
	{
	public:
		bool operator()(T a, T b)
		{
			return a >= b;
		}
	};

	template <typename T>
	class Less_equal
	{
	public:
		bool operator()(T a, T b)
		{
			return a <= b;
		}
	};

	template <typename T>
	class Logical_and
	{
	public:
		bool operator()(T a, T b)
		{
			return (a && b);
		}
	};

	template <typename T>
	class Logical_or
	{
	public:
		bool operator()(T a, T b)
		{
			return (a || b);
		}
	};

	template <typename T>
	class Logical_not
	{
	public:
		bool operator()(T a)
		{
			return !a;
		}
	};
};
