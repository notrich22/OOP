#include<iostream>
using namespace std;

#define tab "\t"

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
	
	double distance(Point other)const {
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		return sqrt(x_distance * x_distance + y_distance * y_distance);
	}

	void print()
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
};
double distance(Point A, Point B) {
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(),2));
}
void main()
{
	setlocale(LC_ALL, "Russian");
	Point A;
	Point B;
	double tmp;
	cout << "Введите координату X точки А: ";
	cin >> tmp;
	A.set_x(tmp);
	cout << "Введите координату Y точки А: ";
	cin >> tmp;
	A.set_y(tmp);
	cout << "Введите координату X точки B: ";
	cin >> tmp;
	B.set_x(tmp);
	cout << "Введите координату Y точки B: ";
	cin >> tmp;
	B.set_y(tmp);
	cout << "Расстояние между точками: " << distance(A, B) << endl;
	cout << "Расстояние между A и B: " << A.distance(B) << endl;
	cout << "Расстояние между B и A: " << B.distance(A) << endl;

	
}