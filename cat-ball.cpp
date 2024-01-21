#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void Setup1();
void Draw1();
void Input1();
void logic(int s, int t, int q);
void Setup2();
void Draw2();
void Input2();
void logic2();
void Setup3();
void Draw3();
void logic3();
void platform(int &f, int u, int v, int &c);
void vertical(int &f, int u, int v, int &c);
bool gameOver;
const int width = 25;
const int height = 25;
char a[height][width];
static int c1 = 0, c2 = 1, c3 = 0, c4, c5;
int x, y, x2, y2, x3, y3, g, h, o, p, k, l, m, n, q, r;
enum eDirecton
{
	STOP = 0,
	UP,
	LEFT,
	RIGHT,
	DOWN
};
eDirecton dir;
char lvl2[17][39] = {{' '},
					 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'I', ' ', ' ', ' ', ' ', ' ', ' ', 'I', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 {'|', ' ', 'I', 'I', ' ', '|', ' ', 'I', 'I', 'I', 'I', 'I', ' ', 'I', 'I', 'I', ' ', ' ', 'I', 'I', 'I', 'I', 'I', ' ', ' ', '|', 'I', 'I', 'I', ' ', 'I', 'I', ' ', 'I', 'I', 'I', 'I', 'I', '|'},
					 {'|', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
					 {'|', ' ', '|', ' ', ' ', 'I', 'I', 'I', 'I', 'I', 'I', 'I', ' ', 'I', 'I', 'I', 'I', ' ', ' ', 'I', 'I', 'I', 'I', 'I', 'I', 'I', ' ', ' ', 'I', 'I', 'I', 'I', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
					 {'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', 'I', 'I', 'I', '|'},
					 {'|', ' ', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', ' ', 'I', 'I', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', ' ', ' ', ' ', '|'},
					 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|'},
					 {'|', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', ' ', 'I', 'I', ' ', ' ', ' ', ' ', '|', ' ', ' ', 'I', 'I', 'I', ' ', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', '|', ' ', ' ', ' ', '|'},
					 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', 'I', 'I', 'I', 'I', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', '|'},
					 {'|', ' ', 'I', 'I', 'I', 'I', 'I', ' ', ' ', ' ', ' ', 'I', 'I', 'I', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'I', 'I', 'I', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|'},
					 {'|', ' ', ' ', ' ', ' ', ' ', 'I', 'I', 'I', 'I', 'I', 'I', ' ', ' ', ' ', ' ', ' ', ' ', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'I', 'I', 'I', ' ', ' ', '|'},
					 {'|', ' ', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', ' ', ' ', ' ', '|'},
					 {'|', ' ', ' ', ' ', '|', ' ', ' ', ' ', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|'},
					 {'|', 'I', ' ', 'I', 'I', 'I', 'I', 'I', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|'},
					 {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', 'I', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|'}};

void ClearScreen()
{
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void LVL1()
{
	Setup1();
	while (!gameOver)
	{
		Draw1();
		Input1();
		if (y == 3)
			break;
		else if (y == l - 2)
			logic(k, l, c3);
		else if (y == p - 2)
			logic(o, p, c2);
		else if (y == h - 2)
			logic(g, h, c1);
		Sleep(60);
	}
}
void Setup1()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height - 2;
	h = height - 5;
	g = rand() % width;
	p = height - 10;
	o = rand() % width;
	l = height - 15;
	k = rand() % width;
}
void Draw1()
{
	platform(g, 3, 3, c1);
	platform(o, 3, 3, c2);
	platform(k, 3, 3, c3);
	ClearScreen();
	cout << "                     GRUMPY TOWER" << endl;
	cout << "                       LEVEL 1" << endl
		 << endl;
	cout << "press spacebar to make the ball jump and help the cat obtain the ball" << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			a[i][j] = ' ';
			a[0][j] = '_';
			a[height - 1][j] = '_';
			a[i][0] = '|';
			a[i][width - 1] = '|';
			a[l - 1][k - 2] = '=';
			a[l - 1][k - 1] = '=';
			a[l - 1][k] = '=';
			a[p - 1][o - 2] = '=';
			a[p - 1][o - 1] = '=';
			a[p - 1][o] = '=';
			a[h - 1][g - 2] = '=';
			a[h - 1][g - 1] = '=';
			a[h - 1][g] = '=';
			if (j != 0 && j != width - 1)
				a[4][j] = '_';
			a[2][4] = '=';
			a[2][5] = '^';
			a[2][6] = '.';
			a[2][7] = '^';
			a[2][8] = '=';
			a[y][x] = 'o';
			cout << a[i][j];
		}
		cout << endl;
	}
}
void Input1()
{
	if (_kbhit())
		switch (_getch())
		{
		case ' ':
			y = y - 5;
			Draw1();
			dir = UP;
			break;
		default:
			Input1();
			break;
		}
}
void logic(int s, int t, int q)
{
	switch (dir)
	{
	case UP:
		if (x == s)
			platform(x, 3, 3, q);
		else if (x == s - 1)
			platform(x, 4, 2, q);
		else if (x == s - 2)
			platform(x, 5, 1, q);
		else
		{
			dir = STOP;
			gameOver = true;
		}
		break;
	case STOP:
		break;
	}
}

void LVL2()
{
	Setup2();
	while (y2 != 1 || x2 != 38)
	{
		Draw2();
		Input2();
		logic2();
		Sleep(30);
	}
}
void Setup2()
{
	dir = STOP;
	x2 = 7;
	y2 = 7;
}
void Draw2()
{
	ClearScreen();
	cout << "                       LEVEL 2" << endl
		 << endl;
	cout << "Cat lost her ball again. Travel it through the maze to her!!! (use a,w,s,d keys)" << endl;
	lvl2[y2][x2] = 'o';
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 39; j++)
		{

			lvl2[0][j] = '_';
			lvl2[16][j] = '_';
			cout << lvl2[i][j];
			if (i == 1 && j == 38)
				cout << " =^.^=";
		}
		cout << endl;
	}
	lvl2[y2][x2] = ' ';
}
void Input2()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		default:
			break;
		}
	}
}
void logic2()
{
	switch (dir)
	{
	case UP:
		if (lvl2[y2 - 1][x2] == ' ')
			y2--;
		else
			dir = STOP;
		break;
	case DOWN:
		if (lvl2[y2 + 1][x2] == ' ')
			y2++;
		else
			dir = STOP;
		break;
	case LEFT:
		if (lvl2[y2][x2 - 1] == ' ')
			x2--;
		else
			dir = STOP;
		break;
	case RIGHT:
		if (lvl2[y2][x2 + 1] == ' ')
			x2++;
		else
			dir = STOP;
		break;
	case STOP:
		break;
	}
}

void LVL3()
{
	Setup3();
	while (!gameOver)
	{
		Draw3();
		if (y3 == 4 && x3 == (width - 2))
			break;
		if (gameOver == true)
			break;
		Input2();
		logic3();
		Sleep(80);
	}
}
void Setup3()
{
	gameOver = false;
	dir = STOP;
	y3 = height - 2;
	x3 = 1;
	h = rand() % height;
	g = 5;
	p = 9;
	o = rand() % width;
	l = 20;
	k = rand() % width;
	n = rand() % height;
	m = 13;
	r = rand() % height;
	q = 18;
	c1 = c2 = c3 = c4 = c5 = 0;
}
void Draw3()
{
	platform(o, 3, 2, c1);
	vertical(h, 2, 1, c2);
	vertical(n, 2, 1, c3);
	platform(k, 3, 2, c4);
	vertical(r, 2, 1, c5);
	ClearScreen();
	cout << "                       LEVEL 3" << endl
		 << endl;
	cout << "Avoid the hurdles and the walls and get to the cat (use a,w,s,d keys)" << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			a[i][j] = ' ';
			a[0][j] = '_';
			a[height - 1][j] = '_';
			a[i][0] = '|';
			a[i][width - 1] = '|';
			a[l][k] = '+';
			a[p][o] = '+';
			a[h][g] = '+';
			a[n][m] = '+';
			a[r][q] = '+';
			a[l][k - 1] = '+';
			a[p][o - 1] = '+';
			a[h][g - 1] = '+';
			a[n][m - 1] = '+';
			a[r][q - 1] = '+';
			a[4][width - 1] = ' ';
			if (a[y3][x3] == '+')
				gameOver = true;
			a[y3][x3] = 'o';
			cout << a[i][j];
			if (i == 4 && j == width - 1)
				cout << " =^.^=";
		}
		cout << endl;
	}
	a[y3][x3] = ' ';
}
void logic3()
{
	switch (dir)
	{
	case UP:
		if (a[y3 - 1][x3] == ' ')
			y3--;
		else
			gameOver = true;
		break;
	case DOWN:
		if (a[y3 + 1][x3] == ' ')
			y3++;
		else
			gameOver = true;
		break;
	case LEFT:
		if (a[y3][x3 - 1] == ' ')
			x3--;
		else
			gameOver = true;
		break;
	case RIGHT:
		if (a[y3][x3 + 1] == ' ')
			x3++;
		else
			gameOver = true;
		break;
	case STOP:
		break;
	}
}
void platform(int &f, int u, int v, int &c)
{
	if (f >= (width - u))
		c = 0;
	if (f <= v)
		c = 1;
	switch (c)
	{
	case 1:
		f++;
		break;
	case 0:
		f--;
		break;
	}
}
void vertical(int &f, int u, int v, int &c)
{
	if (f >= (height - u))
		c = 0;
	if (f <= v)
		c = 1;
	switch (c)
	{
	case 1:
		f++;
		break;
	case 0:
		f--;
		break;
	}
}

void main()
{
	char end_game = false, c = 'y';

	LVL1();
	while (gameOver && !end_game)
	{
		cout << "\nDo you want to try again (y/n)? ";
		cin >> c;
		if (c == 'y')
		{
			system("cls");
			LVL1();
		}
		else if (c == 'n')
		{
			end_game = true;
		}
	}
    if (!end_game){
		cout << "\nYOU WON LEVEL 1!!!\n\n";
		system("pause");

		system("cls");

		LVL2();
		cout << "\nYOU WON LEVEL 2!!!\n\n" << endl;
		system("pause"); 

		system("cls");

		LVL3();
		while (gameOver && !end_game)
		{
			cout << "\nDo you want to try again (y/n)? ";
			cin >> c;
			if (c == 'y')
			{
				system("cls");
				LVL3();
			}
			else if (c == 'n')
			{
				end_game = true;
			}
		}
		if (!end_game){
			cout << "\nYOU WON THE GAME!!!\n\n" << endl;
			system("pause");
		}
		else{
			cout << "\nGameOver!!!\n\n";
			system("pause");
		}
	}
	else{
		cout << "\nGameOver!!!\n\n";
		system("pause");  
	}
}
