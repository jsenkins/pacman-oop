#include <iostream>;
#include <string >;
#include <windows.h>;
#include<conio.h>
#include<stdlib.h>
using namespace std;
char arr[30][50];
char gho[25][100] = {};


class Map {
	char block;


public:
	Map() {
		block = '#';
	}
	char getblock() {
		return block;
	}
	virtual void pacmoves() {};
	virtual void ghost_shifted(int gx, int gy) {};
	virtual bool checkdeath(int ppx, int py, int gx, int gy, int rx, int ry) { return false; };


	char map[21][40] = {
							 "######################################",
							 "##................##................##",
							 "##..####..######..##..######..####..##",
							 "##................##................##",
							 "##..####..######..##..######..####..##",
							 "##........##......##......##........##",
							 "########..######..##..######..########",
							 "      ##..##..............##..##      ",
							 "####..##......##......##......##..####",
							 "                                      ",
							 "########..##..##########..##..########",
							 "      ##..##..............##..##      ",
							 "########..##..##########..##..########",
							 "##................##................##",
							 "##..####..######..##..######..####..##",
							 "##....##......................##....##",
							 "####..##..##..##########..##..##..####",
							 "##........##......##......##........##",
							 "##..############..##..############..##",
							 "##..................................##",
							 "######################################"

	};
	void pacshifted(int x, int y) {
		map[x][y] = 'P';
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}
	}

	void mapp()
	{

		map[1][4] = 'P';
		//map[9][17] = 'R';
		//map[9][20] = 'W';
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}
	}
	/*void showmap() {
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}
	}*/
	~Map() {
		cout << "\n map class destructed\n";

	}
};
//21,40


class pacman : public Map {
	char avatar;
	int xa, ya, total, lives, rx, ry; //xa and ya are cordinated for ghost W and rx and ry are cordinated for ghost red
	int dots = 346;
public:
	pacman() {
		avatar = 'P';

		total = 0;
		lives = 3;
		xa = 9;
		rx = 9;
		ya = 19;
		ry = 20;



	}


	void pacmoves() {
		if (lives <= 0) return;
		char move = 'j';
		bool play = true;
		int x = 1, y = 4;
		int gx = 10, gy = 17;
		// left done


		while (play == true) {
			//cout << "\nMOVE\n";
			//move = _getch();
			//short GetAsynKeyState(int key);



			//==================W random ghost 

			int a = rand() % 50;
			int b = rand() % 50;
			//cout << b;

			if (xa > a) {
				if (map[xa + 1][ya] != '#') {
					if (map[xa + 1][ya] == ' ') {
						map[xa][ya] = ' ';
					}
					else if (map[xa + 1][ya] == '.') {
						map[xa][ya] = '.';

					}
					else if (map[xa + 1][ya] == 'R') {
						map[xa][ya] = 'R';
					}
					else if (map[xa + 1][ya] == 'P') {
						map[xa][ya] = ' ';
						x = 1;
						y = 4;
					}

					xa++;


				}

			}
			else {
				if (map[xa - 1][ya] != '#') {

					if (map[xa - 1][ya] == ' ') {
						map[xa][ya] = ' ';
					}
					else if (map[xa - 1][ya] == '.') {
						map[xa][ya] = '.';

					}
					else if (map[xa - 1][ya] == 'R') {
						map[xa][ya] = 'R';
					}
					else if (map[xa - 1][ya] == 'P') {
						map[xa][ya] = ' ';
						x = 1;
						y = 4;
					}


					xa--;

				}

			}
			if (ya > b) {
				if (map[xa][ya + 1] != '#') {
					if (map[xa][ya + 1] == ' ') {
						map[xa][ya] = ' ';
					}
					else if (map[xa][ya + 1] == '.') {
						map[xa][ya] = '.';

					}
					else if (map[xa][ya + 1] == 'R') {
						map[xa][ya] = 'R';
					}
					else if (map[xa][ya + 1] == 'P') {
						map[xa][ya] = ' ';
						x = 1;
						y = 4;
					}


					ya++;

				}

			}
			else {
				if (map[xa][ya - 1] != '#') {
					if (map[xa][ya - 1] == ' ') {
						map[xa][ya] = ' ';
					}
					else if (map[xa][ya - 1] == '.') {
						map[xa][ya] = '.';

					}
					else if (map[xa][ya - 1] == 'P') {
						map[xa][ya] = ' ';
						x = 1;
						y = 4;
					}



					ya--;
				}
			}
			map[xa][ya] = 'W';
			map[9][20] = ' ';
			ghost_shifted(xa, ya);
			ghost_shifted_R(x, y - 2);

			if (GetAsyncKeyState(VK_LEFT) != 0) {


				//(move == 'j' || move == 'J') && 
				// && map[x][y - 1] != 'R' && map[x][y - 1] != 'W'
				if (map[x][y - 1] != '#') {

					if (map[x][y - 1] == '.') {
						total++;
					}
					map[x][y] = ' ';

					if ((y == 0) && (x == 9 || x == 11 || x == 7))
					{
						y = 40;

					}


					y--;
					if (map[x][y-1] == 'R' || map[x][y-1] == 'W') {
						lives--;
						if (map[x][y - 1] == 'R') {
							map[x][y -1] = ' ';
						}
						x = 1;
						y = 4;
					}
				}

				system("cls");

				pacshifted(x, y);
				system("cls");
				if (map[xa][ya] != '#') {
					map[xa][ya] = 'W';
					ghost_shifted(xa, ya);
				}

				ghost_shifted(rx, ry);
			}

			if (total == 346) {
				system("cls");
				cout << "\n \t YOU HAVE WON THE GAME\t\n";
				cout << total;
				play = false;

			}

			Sleep(200);
			if (GetAsyncKeyState(VK_RIGHT) != 0) {
				//(move == 'l' || move == 'L') && 
				if (map[x][y + 1] != '#' && map[x][y + 1] != 'R' && map[x][y + 1] != 'W') {

					if (map[x][y + 1] == '.') {
						total++;
					}
					if (total == 346) {
						system("cls");
						cout << "\n \t YOU HAVE WON THE GAME\t\n";
						cout << total;
						play = false;
						break;


					}
					map[x][y] = ' ';

					if ((y >= 38) && (x == 9 || x == 11 || x == 7))
					{
						y = 0;
					}
					y++;
					if (map[x][y + 1] == 'R' || map[x][y + 1] == 'W') {
						lives--;
						if (map[x][y + 1] == 'R') {
							map[x][y + 1] = ' ';
						}
						
						x = 1;
						y = 4;
					}

				}
				system("cls");
				pacshifted(x, y);
				system("cls");
				//ghost_shifted_R(x, y - 2);
			}


			if (GetAsyncKeyState(VK_UP) != 0) {
				//(move == 'i' || move == 'I') &&
				if (map[x - 1][y] != '#') {
					if (map[x - 1][y] == '.') {
						total++;
					}
					if (total == 346) {
						system("cls");
						cout << "\n \t YOU HAVE WON THE GAME\t\n";
						cout << total;
						play = false;
						break;


					}
					map[x][y] = ' ';

					x--;
					if (map[x][y] == 'R' || map[x][y] == 'W') {
						if (map[x][y ] == 'R') {
							map[x][y ] = ' ';
						}
						lives--;
						x = 1;
						y = 4;
					}
				}
				system("cls");
				pacshifted(x, y);
				system("cls");
			//	ghost_shifted_R(x, y - 2);
			}
			//move = _getch();
			if (GetAsyncKeyState(VK_DOWN) != 0) {
				//(move == 'k' || move == 'K') &&
				if (map[x + 1][y] != '#' && map[x + 1][y] != 'R' && map[x + 1][y] != 'W') {
					if (map[x + 1][y] == '.') {
						total++;
					}
					if (total == 346) {
						system("cls");
						cout << "\n \t YOU HAVE WON THE GAME\t\n";
						cout << total;
						play = false;
						break;


					}
					map[x][y] = ' ';
					x++;
					if (map[x][y] == 'R' || map[x][y] == 'W') {
						if (map[x][y ] == 'R') {
							map[x][y ] = ' ';
						}
						lives--;
						x = 1;
						y = 4;
					}
				}
				system("cls");
				pacshifted(x, y);
				system("cls");
				//ghost_shifted_R(x, y - 2);
			}


			//lives--;
			if (total == 346) {
				system("cls");
				cout << "\n \t YOU HAVE WON THE GAME\t\n";
				cout << total;
				play = false;
				break;


			}

			if (lives == 0) { //terminates the loop and ends the game
				play = false;
				system("cls");
				cout << "\n\t GAME OVER\t\n";
				cout << '\n';
				cout << "score: " << total << endl;

			}

		}


	}
	void ghost_shifted_R(int gxr, int gyr) {
		system("cls");
		if (map[gxr][gyr] != '#')
		{
			map[gxr][gyr] = 'R';
			if (map[gxr][gyr] == 'R')
			{
				if (map[gxr][gyr-1] != '#')
				{
					map[gxr][gyr - 1] = ' ';
				}
				 
				else
					map[gxr][gyr - 1] = '#';
			}
			if (map[gxr][gyr] == 'R')
			{
				 if (map[gxr][gyr] != '#')
				{
					map[gxr][gyr + 1] = ' ';
				}
				else
					map[gxr][gyr + 1] = '#';
			}
			if (map[gxr][gyr] == 'R')
			{
				 if (map[gxr+2][gyr] != '#')
				{
					map[gxr + 2][gyr] = '.';
				}
				else
					map[gxr + 2][gyr] = '#';
			}
			if (map[gxr][gyr] == 'R')
			{
				 if (map[gxr-2][gyr] != '#')
				{
					map[gxr - 2][gyr] = '.';
				}
				else
					map[gxr - 2][gyr] = '#';
			}
		}
		system("cls");

		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}
	}
	void ghost_shifted(int gx, int gy) {

		system("cls");

		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}

	}
	~pacman() {
		cout << "\npacman class destructed\n";
	}
};

void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

class ghost : public Map {
	int ghostx, ghosty;
	char g1, g2;

public:
	ghost() {
		ghostx = 0;
		ghosty = 0;
		g1 = 'R';
		g2 = 'W';

	}
	/*
	void ghost_shifted(int gx, int gy) {
		if (map[gx][gy] != '#')
		{
			map[gx][gy] = 'R';
		}
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}
	}*/
	bool checkdeath(int px, int py, int gx, int gy, int rx, int ry) {
		if ((px == gx && py == gy) || (px == rx && px == ry)) {

			return true;

		}
		return false;
	}

	int getghostx() {
		return ghostx;
	}
	int getghosty() {
		return ghosty;

	}
};

int main()
{
	//mapp();

	//Map m1;
	gotoxy(0, 0);
	pacman p1;

	p1.mapp();
	//system("cls");
	//p1.showmap();
	p1.pacmoves();
	//p1.ghost_move();
	gotoxy(0, 1);
	//m1.showmap();


	return 0;
}