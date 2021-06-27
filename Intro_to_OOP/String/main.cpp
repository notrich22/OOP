#include"String.h"

//#define CONSTRUCTORS_CHECK
//#define INPUT_CHECK
//#define OPERATOR_PLUS_CHECK
//#define HOW_CAN_WE_CALL_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();
	String str1 = "Hello";
	str1 = str1;
	str1.print();
	cout << str1 << endl;
	String str2 = str1;		//CopyConstructor
	str2.print();
	String str3;
	str3 = str2;	//CopyAssignment
	cout << str3 << endl;

	int a = 2;
	int b = 3;
	a = b;
#endif // CONSTRUCTORS_CHECK

#ifdef INPUT_CHECK
	String str;
	cout << "������� ������: "; cin >> str;
	cout << str << endl;
#endif // INPUT_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	//cout << delimiter << endl;
	//String str3;		//Default constructor
	//str3 = str1 + str2;	//Move assignment
	////MoveMethods:MoveConstructor, MoveAssignment
	//cout << delimiter << endl;
	//cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;
#endif // OPERATOR_PLUS_CHECK

#ifdef HOW_CAN_WE_CALL_CONSTRUCTORS
	String str1;	//Default constructor
	String str2 = "Hello";	//Single-argument constructor
	String str3 = str2;	//Copy constructor - ������ ��� �� ������� ������
	String str4;
	str4.print();
	str4 = str3;	//Copy assignment (operator=). Copy constructor ������� ����������,
					//��������� ������ str4 ��� ������
	String str5();	//�� Default constructor, ����� ������ �� ��������� ������.
					//���������� ������� str5, ������� ������ �� ���������, 
					//� ���������� �������� ���� String.
	String str6{};	//����� ����� ������������ �� ���������.	  
#endif // HOW_CAN_WE_CALL_CONSTRUCTORS

}