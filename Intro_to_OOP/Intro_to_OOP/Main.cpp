#include <iostream>
using namespace std;

//#define struc


class Point
{
	double x;
	double y;
public:
	double get_x() const{
		return x;
	}
	double get_y() const {
		return y;
	}
	void set_x(double x) {
		this->x = x;
	}
	void set_y(double y) {
		this->y = y;
	}
};



void main() {
	setlocale(LC_ALL, "Russian");
#ifdef STRUC
	Point A;
	A.y = 3;
	A.x = 2;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;

#endif // STRUC
	Point A;
	double temp;
	cin >> temp;
	A.set_x(temp);
	cout << A.get_x() << "\t" << A.get_y() << endl;

}