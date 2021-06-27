#pragma once
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------------------------\n"

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////		CLASS DECLARATION (���������� ������)		/////////////////////

class String;
String operator+(const String& left, const String& right);

class String	//�������� ������
{
	unsigned int size;	//������ ������ � ������.
	char* str;			//��������� �� ������ � ������������ ������.
public:
	unsigned int get_size()const;
	const char* get_str()const;
	char* get_str();
	//			Constructors:
	explicit String(unsigned int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//			Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	const char& operator[](unsigned int i)const;
	char& operator[](unsigned int i);

	//			Methods:
	void print()const;
};

////////////		CLASS DECLARATION END (����� ���������� ������)		/////////////////
/////////////////////////////////////////////////////////////////////////////////////////
