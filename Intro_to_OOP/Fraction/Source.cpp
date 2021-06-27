#include <iostream>
using namespace std;
class fraction;
fraction operator/(fraction left, fraction right);
fraction operator*(fraction left, fraction right);
class fraction
{
	int integer; // Целая часть
	int numerator; // Числитель
	int denominator; // Знаменатель
public :
	int get_int() const {
		return integer;
	}
	int get_numenator() const {
		return numerator;
	}
	int get_denominator() const {
		return denominator;
	}
	void set_int(int integer) {
		this->integer = integer;
	}
	void set_numenator(int numenator) {
		this->numerator = numenator;
	}
	void set_denominator(int denominator) {
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	fraction& to_improper() {
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	fraction& to_proper() {
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	fraction invert() {
		to_improper();
		fraction inverted(denominator, numerator);
		return inverted;
	}
	//Constructors
	fraction() {
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "DefaultConstructor: \t" << this <<  endl;
	}
	fraction(int integer) {
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 0;
		//cout << "SingleArgumentConstructor: \t" << this << endl;
	}
	fraction(int numerator, int denominator) {
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
		//cout << "Constructor: \t\t" << this << endl;
	}
	fraction(int integer, int numerator, int denominator) {
		this->set_int(integer);
		this->set_numenator(numerator);
		this->set_denominator(denominator);
		//cout << "Constructor:\t" << this << endl;
	}
	~fraction()
	{
		//cout << "Destructor:\t" << this << endl;
	}
	fraction(const fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "CopyConstructor: \t" << this << endl;
	}
	//Operators
	fraction& operator++() {
		integer++;
		return *this;
	}
	fraction operator++(int) {
		fraction old = *this;
		integer++;
		return old;
	}
	fraction& operator=(const fraction other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "CopyAssignment: \t" << this << endl;
		return *this;
	}
	fraction& operator*=(const fraction other) {
		return *this = *this*other;
	}
	fraction& operator/=(const fraction other) {
		return *this = *this / other;
	}
	operator double() {
		return (double)integer + (double)numerator / denominator;
	}

	//Methods
	void print() {
		if (integer) cout << integer;
		if (integer&&numerator) cout << "(";
		if (numerator) cout << numerator << "/" << denominator;
		if (integer&&numerator) cout << ")";
		if (integer == 0 && numerator == 0) cout << "0";
		cout << endl;
	}
	friend istream& operator>>(istream& is, fraction& obj);
};

fraction operator*(fraction left, fraction right) {
	left.to_improper();
	right.to_improper();
	fraction result;
	result.set_numenator(left.get_numenator() * right.get_numenator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	return fraction(left.get_numenator() * right.get_numenator(), left.get_denominator() * right.get_denominator());
}
fraction operator/(fraction left, fraction right) {
	left.to_improper();
	right.to_improper();
	/*fraction result(
		left.get_numenator() * right.get_denominator(),
		right.get_numenator() * left.get_denominator()
	);*/
	return left * right.invert();
}
istream& operator>>(istream& is, fraction& obj) {
	char str[256]{};
	int integer, numerator, denominator;
	is.getline(str, 256);
	const char* delimiters = " (/)";
	int i = 0;
	for (char* pch = strtok(str, delimiters); pch; pch = strtok(NULL, delimiters), i++) {
		cout << pch << "\t";
	}
	is >> integer >> numerator >> denominator;
	obj.set_int(integer);
	obj.set_numenator(numerator);
	obj.set_denominator(denominator);
	return is;
}
//#define CONSTRUCTORS_CHECK
void main() {
	setlocale(LC_ALL, "ru");
#ifdef CONSTRUCTORS_CHECK
	double A = 5; cout << A << endl;
	fraction a = 5;
	a.print();
	fraction b(2, 3, 4);
	b.print();
	fraction c(0, 1, 2);
	c.print();
	fraction d;
#endif // CONSTRUCTORS_CHECK
#ifdef AR_OP_CHECK
	/*fraction a(1, 2, 3);
a.to_improper();
a.print();
fraction b(19, 5);
b.to_proper();
b.print();
*/
	fraction A(1, 2, 3);
	fraction B(19, 5);
	fraction C = A * B;
#endif // AR_OP_CHECK
#ifdef COMPARSION_OPERATORS_CHECK
	for (double i = .25; i < 10; i++) {
		cout << i << "\t";
	}
	for (fraction i(1, 4); i.get_int() < 10; i++) {
		i.print();
	}
#endif // COMPARSION_OPERATORS_CHECK
	fraction a(2, 3, 4);
	cout << a << endl;
	int A = (int)a;
	cout << "a = " << A << endl;
	double b = A;
	cout << "b = " << b << endl;
}