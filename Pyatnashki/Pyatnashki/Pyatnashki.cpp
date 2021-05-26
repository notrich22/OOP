#include<iostream>
#include<conio.h>
#include<ctime>
#include<Windows.h>
using namespace std;

#define tab "\t"
#define HORIZONTAL_OFFSET "\t\t\t\t\t\t"
#define VERTICAL_OFFSET "\n\n\n\n\n\n\n\n"

#define VERT_LINE	(char)179
#define HORIZ_LINE	(char)196 << (char)196 << (char)196 << (char)196
#define UPPER_LEFT_CONNER	(char)218
#define UPPER_RIGHT_CONNER	(char)191
#define LOWER_LEFT_CONNER	(char)192
#define LOWER_RIGHT_CONNER	(char)217

#define HORIZ_START	(char)195
#define HORIZ_END	(char)180
#define CROSS		(char)197
#define VERT_START	(char)194
#define VERT_END	(char)193

enum Key
{
	escape = 27,
	up_arrow = 72,
	down_arrow = 80,
	left_arrow = 75,
	right_arrow = 77
};

void ASCII();
void InitField(int** field, const int n, int x = 3, int y = 3, int number_of_moves = 0, int mix_iterations = 100);
void PrintField(int** field, const int n, int x, int y, int number_of_moves);
void Move(int** field, const int n, int x, int y, int number_of_moves);
void Check(int** field, const int n, int x, int y, int number_of_moves);
void Mix(int** field, const int n, int& x, int& y, int mix_iterations);

void main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 4;
	int** field = new int* [n];
	for (int i = 0; i < n; i++)
	{
		field[i] = new int[n] {};
	}
	do
	{
		InitField(field, n);
		cout << "Еще разочек?" << endl;
		cout << "Для выхода нажмите Escape, для продолжения нажмите любую клавишу." << endl;
	} while (_getch() != Key::escape);
	for (int i = 0; i < n; i++)
	{
		delete[] field[i];
	}
	delete[] field;
}

void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << tab << (char)i << endl;
	}
}

void InitField(int** field, const int n, int x, int y, int number_of_moves, int mix_iterations)
{
	int value = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			field[i][j] = value++;
		}
	}
	field[3][3] = 0;
	Mix(field, n, x, y, mix_iterations);
	PrintField(field, n, x, y, number_of_moves);
}
void PrintField(int** field, const int n, int x, int y, int number_of_moves)
{
	system("CLS");
	setlocale(LC_ALL, "C");
	cout << VERTICAL_OFFSET << HORIZONTAL_OFFSET << UPPER_LEFT_CONNER;
	for (int i = 0; i < 3; i++)	cout << HORIZ_LINE << VERT_START;
	cout << HORIZ_LINE << UPPER_RIGHT_CONNER;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << HORIZONTAL_OFFSET << VERT_LINE;
		for (int j = 0; j < n; j++)
		{
			cout << " ";
			if (field[i][j] < 10)cout << " ";
			if (field[i][j] == 0)cout << " ";
			else cout << field[i][j];
			cout << " ";
			cout << VERT_LINE;
		}
		cout << endl;
		if (i != n - 1)
		{
			cout << HORIZONTAL_OFFSET << HORIZ_START;
			for (int i = 0; i < 3; i++)cout << HORIZ_LINE << CROSS;
			cout << HORIZ_LINE << HORIZ_END;
			cout << endl;
		}
	}
	cout << HORIZONTAL_OFFSET << LOWER_LEFT_CONNER;
	for (int i = 0; i < 3; i++)cout << HORIZ_LINE << VERT_END;
	cout << HORIZ_LINE << LOWER_RIGHT_CONNER;
	setlocale(LC_ALL, "Russian");
	cout << "\nКоличество ходов: " << number_of_moves << endl;
	Check(field, n, x, y, number_of_moves);
}

void Move(int** field, const int n, int x, int y, int number_of_moves)
{
	char key;
	bool wrong_key = false;
	do
	{
		wrong_key = false;
		key = _getch();
		if (key == Key::escape)return;
		switch (key)
		{
		case 'w':case 'W':case up_arrow:	if (x == 0)break; swap(field[x][y], field[x - 1][y]); x--; number_of_moves++; break;
		case 's':case 'S':case down_arrow:	if (x == 3)break; swap(field[x][y], field[x + 1][y]); x++; number_of_moves++; break;
		case 'a':
		case 'A':
		case left_arrow:	if (y == 0)break; swap(field[x][y], field[x][y - 1]); y--; number_of_moves++; break;
		case 'd':
		case 'D':
		case right_arrow:	if (y == 3)break; swap(field[x][y], field[x][y + 1]); y++; number_of_moves++; break;
		default: wrong_key = true; if (key != -32)cout << "Допустимые клавиши: Стрелки и WASD" << endl;
		}
	} while (wrong_key);

	PrintField(field, n, x, y, number_of_moves);

}

void Check(int** field, const int n, int x, int y, int number_of_moves)
{

	bool game_over = true;	
	int value = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (i != n - 1 ? n : n - 1); j++)
		{
			if (field[i][j] != value++)
				game_over = false;
		}
	}
	if (game_over)
	{
		cout << "\n\aВы выиграли!" << endl;
		return;
	}
	Move(field, n, x, y, number_of_moves);
}

void Mix(int** field, const int n, int& x, int& y, int mix_iterations)
{
	srand(time(NULL));
	for (int i = 0; i < mix_iterations; i++)
	{
		switch (rand() % 4)
		{
		case 0:if (x == 0)break; swap(field[x][y], field[x - 1][y]); x--; break;
		case 1:if (x == 3)break; swap(field[x][y], field[x + 1][y]); x++; break;
		case 2:if (y == 0)break; swap(field[x][y], field[x][y - 1]); y--; break;
		case 3:if (y == 3)break; swap(field[x][y], field[x][y + 1]); y++; break;
		}
	}
}