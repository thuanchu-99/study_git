#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
#include<map>
#include <iterator>
#include <utility>

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7
#define default_Background		0
#define White_Background		240




using namespace std;

// parameter table chesh

#define SIZE 13
#define TOP 1
#define LEFT 1
#define WEIGHT 4
#define HEIGHT 2

struct vCoord
{
	COORD c;
	bool p;
};

struct mCoord
{
	COORD P;
};

class Common {

public:
	void fixConsoleWindow();
	void gotoXY(int, int);
	void TextColor(int);
	void Nocursortype();
	void UnNocursortype();
};


void Common::gotoXY(int pX, int pY)
{
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Common::fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Common::TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Common::Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void Common::UnNocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}


class Point
{
private:
	int check;//-1, 0, 1

public:
	Point();
	~Point();

	void setcheck(int);//dien gia tri vao khi nhan chuot
	int getcheck();
};

class Player
{
public:
private:
	int ID;
	string name;
	int win;
	int lose;
	int draw;

public:

	Player();
	~Player();

	Player(string);

	string GetName();
	void SetName(string);

	void setID(int);
	int getID();

	void SetWin(int);
	void SetLose(int);
	void SetDraw(int);

	int GetWin();
	int GetLose();
	int GetDraw();

	void IncreWin();
	void IncreLose();
	void IncreDraw();
};

class Game
{
private:
	vector<vector<Point>> match;//luu tran dau

public:
	Game();
	~Game();

	void resetmatch();
	void crematch(int);

	int getPoint(mCoord);//lay point tu vector match ra 
	int getPointint(int, int);

	void pushXtotable(mCoord);
	void pushOtotable(mCoord);
};

class Model :public Common
{
private:
	Game current;
	vector<Player> csdl;
	map<int, Game> ListMatch;//so tran dau
public:
	Model();
	~Model();

	void newGame();//xóa 

	//interaction Game current
	bool checkpointgame(mCoord);//enable point: da duoc dien hay chua
	int getpointgame(mCoord);//lay gia tri
	int getpointgameint(int, int);
	void resetgame();//tao new sec
	//int getpointgame(int, int);

	void addXtogame(mCoord);//
	void addOtogame(mCoord);//

	/*void deletepoint(int, int);*///ho tro undo

	//model interaction ListMatch
	void addgame(int);//sau khi control kiem tra sec+=1
	Game search(int);//search theo sec

	//vector csdl interaction
	void addPlayer(Player);
	pair<Player, Player> getPlayer(int);
};

class View : public Common
{
private:
	vector<vCoord> vNode;//luu cac toa do da duoc dien
public:
	View();
	~View();
	//mCoord convert(int, int);
	//vCoord MtoV(int, int);

	//view thuan
	void viewmenu();
	pair<string, string> viewSetPlayer();
	int inputSIZE();
	void viewtable(int);
	void viewinfo(Player, Player, int);
	void viewresult(Player);//hien thi sau khi ket thuc
	void viewdraw();
	vCoord mouse();
	bool checkmouseXO(vCoord);
	void pushX(vCoord);
	void pushO(vCoord);
	void viewinfohis(Player, Player);
	//history
	//int viewHistogy(Player, Player, vector<vector<Point>>);
	//void dishistogy();
};

class Control :public Common
{
private:
	Model mModel;
	View mView;
public:
	mCoord VtoM(vCoord);//console -> table
	vCoord MtoV(mCoord);//table -> console

	/*int checkwin(mCoord);*/// kiem tra 0 hoa, -1 user 1 thang, 1 user2 thang
	int checkwin(int, int);
	//int checkwin(mCoord);

	//void newGame();

	//void showhistory();

	void runProgram();

	// cac ham con xay dung cac trang khac nhau
	int cmd_menu(vCoord);//luu lua chon tai menu
	//int cmd_inPlayer();//luu hoat dong nhap
	int cmd_table(vCoord);//luu danh co
	//int cmd_sec(vCoord);//luu lua chon tai danh co
	//int cmd_finish(vCoord);//luu lua chon sau khi finish sec

};

Point::Point()
{
	check = 0;
}

Point::~Point() {}

void Point::setcheck(int icheck)
{
	check = icheck;
}

int Point::getcheck()
{
	return check;
}

Player::Player()
{
	name = "";
	win = lose = draw = 0;
	ID = 0;
}

Player::Player(string iname)
{
	name = iname;
	win = lose = draw = 0;
	ID = 0;
}

Player::~Player() {}

string Player::GetName()
{
	return name;
}

void Player::SetName(string value)
{
	name = value;
}

void Player::SetWin(int value) { win = value; }
void Player::SetLose(int value) { lose = value; }
void Player::SetDraw(int value) { draw = value; }

int Player::GetWin() { return win; }
int Player::GetLose() { return lose; }
int Player::GetDraw() { return draw; }

void Player::IncreWin() { win++; }
void Player::IncreLose() { lose++; }
void Player::IncreDraw() { draw++; }

void Player::setID(int id)
{
	ID = id;
}

int Player::getID()
{
	return ID;
}

Game::Game() {}

Game::~Game() {}

void Game::resetmatch()
{
	for (int i = 0; i < match.size(); i++)
	{
		for (int j = 0; j < match[i].size(); j++)
		{
			match[i][j].setcheck(0);
		}
	}
}

void Game::crematch(int size)
{
	Point p;
	for (int i = 0; i < size; i++)
	{
		match[i].push_back(p);
	}
}

int Game::getPoint(mCoord v)
{
	return match[v.P.X][v.P.Y].getcheck();
}

int Game::getPointint(int x, int y)
{
	return match[x][y].getcheck();
}

void Game::pushOtotable(mCoord v)
{
	match[v.P.X][v.P.Y].setcheck(1);
}

void Game::pushXtotable(mCoord v)
{
	match[v.P.X][v.P.Y].setcheck(-1);
}

Model::Model() {}

Model::~Model() {}

//interaction Game current
bool Model::checkpointgame(mCoord v)
{
	if (current.getPoint(v) == 0)
		return true;
	else
		return false;
}

int Model::getpointgame(mCoord v)
{
	return current.getPoint(v);
}

int Model::getpointgameint(int x, int y)
{
	return current.getPointint(x, y);
}

void Model::addXtogame(mCoord v)
{
	current.pushXtotable(v);
}

void Model::addOtogame(mCoord v)
{
	current.pushOtotable(v);
}

//model interaction ListMatch
void Model::addgame(int sec)
{
	ListMatch.insert(pair<int, Game>(sec, current));
}

Game Model::search(int s)
{
	map<int, Game>::iterator itr;
	for (itr = ListMatch.begin(); itr != ListMatch.end(); ++itr)
	{
		if (itr->first == s)
			return itr->second;
	}
}

//vector csdl interaction
void Model::addPlayer(Player one)
{
	csdl.push_back(one);
}

//tim ng choi theo sec
pair<Player, Player> Model::getPlayer(int sec)
{
	pair<Player, Player> p;
	int i, j;
	for (i = 0; i < csdl.size(); i++)
	{
		if (csdl[i].getID() == sec)
		{
			p.first = csdl[i];
			break;
		}
	}

	for (j = i + 1; j < csdl.size(); j++)
	{
		if (csdl[j].getID() == sec)
		{
			p.second = csdl[j];
			break;
		}
	}

	return p;
}

void Model::newGame()
{
	current.resetmatch();
}

mCoord Control::VtoM(vCoord a)
{
	mCoord ma;
	SHORT x = (a.c.X - LEFT) / WEIGHT;
	SHORT y = (a.c.Y - TOP) / HEIGHT;
	ma.P.X = x;
	ma.P.Y = y;
	return ma;
}

vCoord Control::MtoV(mCoord ma)
{
	vCoord va;
	SHORT x = (ma.P.X * WEIGHT) + LEFT;
	SHORT y = (ma.P.Y * HEIGHT) + TOP;
	va.c.X = x + 1;
	va.c.Y = y;
	va.p = false;
	return va;
}


int Control::cmd_menu(vCoord MOUSE)
{
	if (MOUSE.c.Y == 13 && (MOUSE.c.X >= 55 && MOUSE.c.X <= 63))
		return 1;
	/*if (MOUSE.c.Y == 15 && (MOUSE.c.X >= 55 && MOUSE.c.X <= 61))
		return 2;*/
	if (MOUSE.c.Y == 17 && (MOUSE.c.X >= 55 && MOUSE.c.X <= 62))
		return 3;
	if (MOUSE.c.Y == 19 && (MOUSE.c.X >= 55 && MOUSE.c.X <= 59))
		return 4;
}

int Control::cmd_table(vCoord MOUSE)
{
	if ((MOUSE.c.Y >= LEFT && MOUSE.c.Y <= (LEFT + (SIZE * 4))) && (MOUSE.c.X >= TOP && MOUSE.c.X < (TOP + (SIZE * 4))))
		return 1;
	if (MOUSE.c.Y == 8 && (MOUSE.c.X >= 70 && MOUSE.c.X <= 78))
		return 2;
	if (MOUSE.c.Y == 10 && (MOUSE.c.X >= 70 && MOUSE.c.X <= 79))
		return 3;
	if (MOUSE.c.Y == 12 && (MOUSE.c.X >= 70 && MOUSE.c.X <= 91))
		return 4;
}

int Control::checkwin(int pX, int pY)
{
	//return 1;
	//return 1: win, 0: draw, 2: tiep tuc
	/**/
	// thao tac tren Game curent thuoc model

	//check draw
	bool check = true;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (mModel.getpointgameint(i, j) == 0) {
				check = false;
				break;
			}
		}
		if (check == false)
			break;
	}
	if (check)
		return 0;//draw

	//check win
	int x = pX;//toa do diem nhan chuot
	int y = pY;

	//check diem bat dau va diem ket thuc
	int res = 0;
	int xStart = (x - 3 > 0) ? x - 3 : 0;
	int yStart = (y - 3 > 0) ? y - 3 : 0;

	int xEnd = (x + 3 >= SIZE) ? SIZE - 1 : x + 3;
	int yEnd = (y + 3 >= SIZE) ? SIZE - 1 : y + 3;

	int x1, x2, y1, y2;

	//check chieu ngang
	for (int i = xStart; i <= x; i++)
	{
		if (i + 3 < SIZE)
		{
			res = mModel.getpointgameint(i, y) + mModel.getpointgameint(i + 1, y) + mModel.getpointgameint(i + 2, y)
				+ mModel.getpointgameint(i + 3, y);

			x1 = i - 1 >= 0 ? i - 1 : xStart;
			y1 = y;

			x2 = i + 4 >= SIZE ? x + 3 : i + 4;
			y2 = y;
		}


		//check check 2 dau
		if (res == 4 && (mModel.getpointgameint(x1, y1) != -1 || mModel.getpointgameint(x2, y2) != -1))
		{
			pX = i;
			pY = y;
			return 1;
		}
		//x thang
		if (res == -4 && (mModel.getpointgameint(x1, y1) != 1 || mModel.getpointgameint(x2, y2) != 1))
		{
			pX = i;
			pY = y;
			return -1;
		}
	}
	//check theo chieu doc
	for (int i = yStart; i <= y; i++)
	{
		if (i + 4 < SIZE)
		{
			res = mModel.getpointgameint(x, i) + mModel.getpointgameint(x, i + 1) + mModel.getpointgameint(x, i + 2)
				+ mModel.getpointgameint(x, i + 3);

			x1 = x;
			y1 = i - 1 >= 0 ? i - 1 : yStart;

			x2 = x;
			y2 = i + 4 >= SIZE ? y + 3 : i + 4;
		}
		//check 2 dau
		if (res == 4 && (mModel.getpointgameint(x1, y1) != -1 || mModel.getpointgameint(x2, y2) != -1))
		{
			pX = x;
			pY = i;
			return 1;
		}
		//x thang
		if (res == -4 && (mModel.getpointgameint(x1, y1) != 1 || mModel.getpointgameint(x2, y2) != 1))
		{
			pX = x;
			pY = i;
			return -1;
		}
	}
	//check treo
	for (int i = xStart; i <= x; i++)
	{
		for (int j = yStart; j <= y; j++)
		{
			if (i - j == x - y && i + 4 < SIZE && j + 4 < SIZE)
			{
				res = mModel.getpointgameint(i, j) + mModel.getpointgameint(i + 1, j + 1) + mModel.getpointgameint(i + 2, j + 2)
					+ mModel.getpointgameint(i + 3, j + 3);
				x1 = i - 1;
				y1 = j - 1;

				if (x1 < 0 || y1 < 0)
				{
					x1 = i;
					y1 = j;
				}
				x2 = i + 4;
				y2 = j + 4;
				if (x2 >= SIZE || y2 >= SIZE)
				{
					y2 = j;
					x2 = i;
				}
			}
			//check 2 dau
			if (res == 4 && (mModel.getpointgameint(x1, y1) != -1 || mModel.getpointgameint(x2, y2) != -1))
			{
				pX = i;
				pY = j;
				return 1;
			}
			//x thang
			if (res == -4 && (mModel.getpointgameint(x1, y1) != 1 || mModel.getpointgameint(x2, y2) != 1))
			{
				pX = i;
				pY = j;
				return -1;
			}
		}
	}

	for (int i = xEnd; i >= x; i--)
	{
		for (int j = yStart; j <= y; j++)
		{
			if (i + j == x + y && j + 4 < SIZE && i - 4 >= 0)
			{
				res = mModel.getpointgameint(i, j) + mModel.getpointgameint(i - 1, j + 1) + mModel.getpointgameint(i - 2, j + 2)
					+ mModel.getpointgameint(i - 3, j + 3);
				x1 = i + 1;
				y1 = j - 1;
				if (x1 >= SIZE || y1 < 0)
				{
					x1 = i;
					y1 = i;
				}
				x2 = i - 4;
				y2 = j + 4;
				if (x2<0 || y2>SIZE)
				{
					x2 = i;
					y2 = j;
				}
			}
			//check 2 dau
			if (res == 4 && (mModel.getpointgameint(x1, y1) != -1 || mModel.getpointgameint(x2, y2) != -1))
			{
				pX = i;
				pY = j;
				return 1;
			}
			//x thang
			if (res == -4 && (mModel.getpointgameint(x1, y1) != 1 || mModel.getpointgameint(x2, y2) != 1))
			{
				pX = i;
				pY = j;
				return -1;
			}
		}
	}
	return 2;//chua win
}

void Control::runProgram()
{
	vCoord MOUSE;//luu toa do click mouse
	int check_win;
	int x_win, y_win;
	int number_game = 0;//so tran
	int number_sec;
	int IDgame;
	int save_game;
	int check_game;

	//run program
	while (true)
	{
		mView.viewmenu();
		MOUSE = mView.mouse();
		int menuMOUSE = cmd_menu(MOUSE);
		mCoord mMOUSE;
		vCoord vMOUSE;
		//nhan exit
		if (menuMOUSE == 4)
			break;//thoat chuong trinh

		switch (menuMOUSE)
		{
		case 1://new game in menu
		{
			number_sec = 0;
			number_game++;
			mModel.resetgame();
			pair<string, string> user;
			int size;
			int tableMOUSE;
			user = mView.viewSetPlayer();
			size = mView.inputSIZE();

			//hai ng choi trong 1 game
			Player one(user.first);
			Player two(user.second);
			int step = 0;

			mView.viewtable(size);
			while (true)
			{
				//mView.viewtable(size);
				mView.viewinfo(one, two, step);
				//setup mouse table
				MOUSE = mView.mouse();
				tableMOUSE = cmd_table(MOUSE);

				if (tableMOUSE == 4)
					break;

				//setup in table console
				switch (tableMOUSE)
				{
				case 1://thuoc bang
				{

					//check point : true: addpoint, false: break
					mMOUSE = VtoM(MOUSE);
					if (mModel.checkpointgame(mMOUSE) == false)
						break;
					step++;//tang luot danh
					vMOUSE = MtoV(mMOUSE);
					if (step % 2 != 0)//dien X
					{
						mModel.addXtogame(mMOUSE);
						mView.pushX(vMOUSE);
					}
					if (step % 2 == 0)
					{
						mModel.addOtogame(mMOUSE);
						mView.pushO(vMOUSE);
					}

					x_win = mMOUSE.P.X;
					y_win = mMOUSE.P.Y;
					check_win = checkwin(x_win, y_win);

					if (check_win == -1)
					{
						mView.viewresult(one);
						one.IncreWin();
						two.IncreLose();
						IDgame = number_game * 10 + number_sec;
						one.setID(IDgame);
						two.setID(IDgame);
						mModel.addPlayer(one);
						mModel.addPlayer(two);
						mModel.addgame(IDgame);
						break;
					}
					else if (check_win == 1)
					{
						mView.viewresult(two);
						two.IncreWin();
						one.IncreLose();
						break;
					}
					else if (check_win == 0)
					{
						mView.viewdraw();
						one.IncreDraw();
						two.IncreDraw();
						break;
					}
					break;//break case 1
				}
				case 2://newgame
				{
					IDgame = number_game * 10 + number_sec;
					one.setID(IDgame);
					two.setID(IDgame);
					mModel.addPlayer(one);
					mModel.addPlayer(two);
					mModel.addgame(IDgame);
					number_sec++;
					mModel.resetgame();
					system("cls");
					mView.viewtable(size);
					break;
				}
				case 3:
				{
					IDgame = number_game * 10 + number_sec;
					one.setID(IDgame);
					two.setID(IDgame);
					mModel.addPlayer(one);
					mModel.addPlayer(two);
					mModel.addgame(IDgame);
					break;
				}

				}
			}
			break;//break menu one
		}

		case 3://history
		{
			break;
		}

		}

	}

}

View::View() {}
View::~View() {}

void View::viewmenu()
{
	Nocursortype();
	system("cls");
	TextColor(default_ColorCode);

	gotoXY(55, 13);
	cout << "New Game";
	gotoXY(55, 15);
	cout << "Option";
	gotoXY(55, 17);
	cout << "History";
	gotoXY(55, 19);
	cout << "Exit";
}

pair<string, string> View::viewSetPlayer()
{
	string user1;
	string user2;

	Common::UnNocursortype();
	system("cls");
	Common::gotoXY(50, 7);
	cout << "<< NEW GAME >>";
	Common::gotoXY(40, 10);
	cin.ignore();
	cout << "Name Player 1 : ";
	getline(cin, user1);

	Common::gotoXY(40, 12);
	cout << "Name Player 2 : ";
	getline(cin, user2);

	pair<string, string> a;
	a.first = user1;
	a.second = user2;

	return a;
}

int View::inputSIZE()
{
	int a;
	Common::gotoXY(40, 14);
	cout << "Nhap kich thuoc ban co(4 - 15): ";
	cin >> a;
	return a;
}


void View::viewtable(int size)
{
	Common::Nocursortype();
	system("cls");
	Common::gotoXY(1, 1);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= size; j++)
		{
			Common::TextColor(ColorCode_DarkGreen);
			Common::gotoXY(LEFT + i * 4 - 1, TOP + j * 2);
			if (i != 0)
			{
				printf("|");
			}

		}
	}

	for (int i = 0; i < size * 4; i++)
	{
		for (int j = 0; j <= size; j++)
		{
			Common::TextColor(ColorCode_DarkGreen);
			Common::gotoXY(LEFT + i, TOP + j * 2 - 1);
			if (j != 0)
				printf("-");

		}
	}

	Common::gotoXY(70, 8);
	cout << "New Game";
	Common::gotoXY(70, 10);
	cout << "Save Game";
	Common::gotoXY(70, 12);
	cout << "Return Menu!";
}

void View::viewinfo(Player user1, Player user2, int step)
{
	Common::gotoXY(LEFT + 4 * SIZE + 28, 18);
	cout << "<< INFORMATION >>";
	Common::gotoXY(LEFT + 4 * SIZE + 10, 20);
	cout << "Player 1: " << user1.GetName() << "\t Step: " << step << "\t W/L/D: " << user1.GetWin() << "/" << user1.GetLose() << "/" << user1.GetDraw();
	Common::gotoXY(LEFT + 4 * SIZE + 10, 24);
	cout << "Player 2: " << user2.GetName() << "\t Step: " << step << "\t W/L/D: " << user2.GetWin() << "/" << user2.GetLose() << "/" << user2.GetDraw();

}

void View::viewinfohis(Player user1, Player user2)
{
	Common::gotoXY(LEFT + 4 * SIZE + 28, 18);
	cout << "<< INFORMATION >>";
	Common::gotoXY(LEFT + 4 * SIZE + 10, 20);
	cout << "Player 1: " << user1.GetName() << "\t W/L/D: " << user1.GetWin() << "/" << user1.GetLose() << "/" << user1.GetDraw();
	Common::gotoXY(LEFT + 4 * SIZE + 10, 24);
	cout << "Player 2: " << user2.GetName() << "\t W/L/D: " << user2.GetWin() << "/" << user2.GetLose() << "/" << user2.GetDraw();
	Common::gotoXY(70, 12);
	cout << "Return Menu!";

}

void View::viewresult(Player user)
{
	Common::Nocursortype();
	Common::gotoXY(70, 16);
	cout << "\tCHUC MUNG " << user.GetName() << " CHIEN THANG !\t";
	//Common::gotoXY(70, 18);
	//cout << "New Game";
	//Common::gotoXY(70, 20);
	//cout << "Back to Menu";
}

void View::viewdraw()
{
	Common::Nocursortype();
	Common::gotoXY(70, 16);
	cout << "\t" << "HAI BEN HOA NHAU !\t";
	//Common::gotoXY(70, 7);
	//cout << "New Game";
	//Common::gotoXY(70, 9);
	//cout << "Back to Menu";

}

bool View::checkmouseXO(vCoord vmt)
{
	return true;
}

vCoord View::mouse()
{
	INPUT_RECORD ir[128];
	DWORD        nRead;
	COORD        xy;
	HANDLE       hStdInput = NULL;
	HANDLE       hStdOutput = NULL;
	HANDLE       hEvent = NULL;

	vCoord m;
	hStdInput = GetStdHandle(STD_INPUT_HANDLE);
	hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hStdInput);
	SetConsoleMode(hStdInput, ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	HANDLE handles[2] = { hEvent, hStdInput };
	while (WaitForMultipleObjects(2, handles, FALSE, INFINITE)) {
		ReadConsoleInput(hStdInput, ir, 128, &nRead);
		for (unsigned int i = 0; i < nRead; i++) {
			if (ir[i].EventType == MOUSE_EVENT) {
				xy.X = ir[i].Event.MouseEvent.dwMousePosition.X, xy.Y = ir[i].Event.MouseEvent.dwMousePosition.Y;
				if (((int)ir[i].Event.MouseEvent.dwButtonState & 0x07) == 1) {

					m.c.X = xy.X;
					m.c.Y = xy.Y;

					return m;
				}
			}
		}
	}
}

void View::pushX(vCoord x)
{
	Common::gotoXY(x.c.X, x.c.Y);
	Common::TextColor(ColorCode_DarkGreen);
	printf("X");
}
void View::pushO(vCoord x)
{
	Common::gotoXY(x.c.X, x.c.Y);
	Common::TextColor(ColorCode_DarkYellow);
	printf("O");
}

//mCoord View::convert(int x, int y)
//{
//	mCoord a;
//	a.P.X = x;
//	a.P.Y = y;
//	return a;
//}
//
//vCoord View::MtoV(int x, int y)
//{
//	vCoord va;
//	int x = (x * WEIGHT) + LEFT;
//	int y = (y * HEIGHT) + TOP;
//	va.c.X = x + 1;
//	va.c.Y = y;
//	va.p = false;
//	return va;
//}
//
//int View::viewHistogy(Player one, Player two, vector<vector<Point>> game)
//{
//	viewtable(game.size());
//	vCoord vpoint;
//	vCoord mmouse;
//	for (int i = 0; i < game.size(); i++)
//	{
//		for (int j = 0; j < game[i].size(); j++)
//		{
//			vpoint = MtoV(i, j);
//			if (game[i][j].getcheck() == -1)
//			{
//				pushX(vpoint);
//			}
//			else if(game[i][j].getcheck() == 1)
//				pushO(vpoint);
//		}
//	}
//	viewinfohis(one, two);
//	mmouse = mouse();
//	if (mmouse.c.Y == 12 && (mmouse.c.X >= 70 && mmouse.c.X <= 82))
//		return 5;
//	return 6;
//}

int main()
{
	Control c;
	c.runProgram();

	return 0;
}