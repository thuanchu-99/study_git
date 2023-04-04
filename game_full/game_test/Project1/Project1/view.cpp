#include"view.h"


View::View(){}
View::~View(){}

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
	cout << "Player 1: " << user1.GetName()  << "\t W/L/D: " << user1.GetWin() << "/" << user1.GetLose() << "/" << user1.GetDraw();
	Common::gotoXY(LEFT + 4 * SIZE + 10, 24);
	cout << "Player 2: " << user2.GetName()  << "\t W/L/D: " << user2.GetWin() << "/" << user2.GetLose() << "/" << user2.GetDraw();
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
	cout << "\t" <<"HAI BEN HOA NHAU !\t";
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