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
	cout << "������� ���������� X ����� �: ";
	cin >> tmp;
	A.set_x(tmp);
	cout << "������� ���������� Y ����� �: ";
	cin >> tmp;
	A.set_y(tmp);
	cout << "������� ���������� X ����� B: ";
	cin >> tmp;
	B.set_x(tmp);
	cout << "������� ���������� Y ����� B: ";
	cin >> tmp;
	B.set_y(tmp);
	cout << "���������� ����� �������: " << distance(A, B) << endl;
	cout << "���������� ����� A � B: " << A.distance(B) << endl;
	cout << "���������� ����� B � A: " << B.distance(A) << endl;

	
}