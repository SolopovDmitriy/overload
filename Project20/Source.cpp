a#include <iostream>
using namespace std;

class Fraction
{
	int integer;	 // Целая часть
	int numerator;	 // Числитель
	int denominator; // Знаменатель
public:
	const int get_integer()const
	{
		return integer;
	}
	const int get_numerator()const
	{
		return numerator;
	}
	const int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//Constructor

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:" << this << endl;
		return *this;
	}
	Fraction& operator*=(Fraction other)
	{
		this->reduse().to_improrep();
		other.reduse().to_improrep();
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return this->reduse().to_proper();

	}

	/*Fraction operator*(const Fraction& other)const
	{
		Fraction result;
		Fraction left = this->to_improrep();
		Fraction right = other.to_improrep();*/
		/*left.to_improrep();
		right.to_improrep();*/
		/*result.numerator = left.numerator * right.numerator;
		result.denominator = left.denominator * right.denominator;
		result.reduse();
		result.to_proper();
		return result;
	}*/


	//	Metods
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer) cout << "+";
			//if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			//if (integer) cout << ")";
		}
		else if (integer == 0)
			cout << 0;
		cout << endl;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	/*Fraction*/Fraction& to_improrep()
	{
		//Fraction result = *this;
		/*result.*/numerator += integer * denominator;
		/*result.*/integer = 0;
		/*return result;*/
		return *this;
	}
	Fraction& reduse()
	{
		// В дроби, в любом случае что то больше. Числитель может быть больше знаминателя или наоборот.
		int more; // большее значение
		int less; // меньшее значение
		int reminder = 0; // отстаток от деления
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}
		do
		{
			reminder = more % less;
			more = less;
			less = reminder;
		} while (reminder);
		int GCD = more; // Найбольший Общий Делитель
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improrep();
	right.to_improrep();
	//Fraction result(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());
	/*result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*result.reduse();
	result.to_proper();*/
	return Fraction(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator()).to_proper().reduse();
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define METHODS_CHECK

void main()
{
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	Fraction B = 3;
	B.print();
	Fraction C(4, 5);
	C.print();
	Fraction D(5, 4, 7);
	Fraction E = D; // CopyConstructor
	E.print();
	Fraction F;  // DefaultConstructor
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	Fraction D(1, 2);

	Fraction A, B, C;
	A = B = C = D;
	D.print();

#endif // ASSIGNMENT_CHECK

#ifdef METHODS_CHECK
	/*Fraction A(7, 5);
A.print();
A.to_proper();
A.print();
A.to_improrep();
A.print();*/
	Fraction A(148, 44);
	A.reduse();
	A.print();
	Fraction B(251, 934);
	B.reduse();
	B.print();

	Fraction C;
	C = A * B;
#endif // METHODS_CHECK

	Fraction A(2, 3, 4);
	Fraction B(5, 7, 8);
	Fraction C = A * B;
	C.print();
	(A *= B).print();
}