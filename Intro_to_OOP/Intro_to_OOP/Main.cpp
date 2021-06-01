#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n---------------------------------------------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	/*Point operator+(const Point& other)const
	{
		Point result;
		//this->x = 123;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "Operator+:\t" << this << endl;
		return result;
	}*/

	Point& operator++()		
	{
		this->x++;
		this->y++;
		cout << "Prefix Increment:\t" << this << endl;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		this->x++;
		this->y++;
		cout << "Suffix Increment" << endl;
		return old;
	}

	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global Plus" << endl;
	return result;
}

//#define STRUCT
//#define DISTANCE_AND_CONSTRUCTORS
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT
	int a;		
	Point A;

	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT

#ifdef DISTANCE_AND_CONSTRUCTORS
	Point A(2.3, 4.5);
	cout << sizeof(A) << endl;
	cout << A.get_x() << tab << A.get_y() << endl;

	Point B;
	B.print();

	Point D(6.7, 8.3);
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки D: " << A.distance(D) << endl;
	cout << "Расстояние от точки D до точки A: " << D.distance(A) << endl;
	cout << "Расстояние между точками A и D:   " << distance(A, D) << endl;
	cout << "Расстояние между точками D и A:   " << distance(D, A) << endl;
	cout << delimiter << endl;

	B = D;

	cout << delimiter << endl;
	Point E = A;
	Point F;	
	F = D;		
	cout << delimiter << endl;
#endif // DISTANCE_AND_CONSTRUCTORS

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;
	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2.3, 4.5);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK


	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2.3, 4.5);
	Point B(2.7, 3.14);
	cout << delimiter << endl;
	Point C = A + B;
	cout << delimiter << endl;
	C.print();
	++C;
	C.print();
	C++;
	C.print();
}