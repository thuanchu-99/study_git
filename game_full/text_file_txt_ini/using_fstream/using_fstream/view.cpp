#include".\view.h"
#include".\common.h"

View::View(){}
View::~View(){}

void View::viewmenu()
{
	Common::Nocursortype();
	system("cls");
	Common::TextColor(default_ColorCode);

	Common::gotoXY(55, 13);
	cout << "New Game";
	Common::gotoXY(55, 15);
	cout << "Thanh tich";
	Common::gotoXY(55, 17);
	cout << "History";
	Common::gotoXY(55, 19);
	cout << "Exit";
}

pair<string, string> View::viewSetPlayer()
{
	string user1;
	string user2;
	system("cls");
	Common::gotoXY(50, 7);
	cout << "<< NEW GAME >>";
	Common::gotoXY(40, 10);
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
	while (true)
	{
		Common::gotoXY(40, 14);
		cout << "Nhap kich thuoc ban co(4 - 15): ";
		cin >> a;
		cin.ignore();
		if (a >= 4 && a <= 15)
			break;
	}
	return a;
}


void View::viewtable(int size)
{
	Common::Nocursortype();
	system("cls");
	Common::TextColor(ColorCode_DarkGreen);
	Common::gotoXY(1, 1);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= size-1; j++)
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
	Common::TextColor(ColorCode_DarkYellow);
	Common::gotoXY(70, 8);
	cout << "New Game";
	Common::gotoXY(70, 10);
	cout << "Save Game";
	Common::gotoXY(70, 12);
	cout << "Return Menu!";
}

void View::viewtablehis(int size)
{
	Common::Nocursortype();
	system("cls");
	Common::TextColor(ColorCode_DarkGreen);
	Common::gotoXY(1, 1);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= size - 1; j++)
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
}

void View::viewinfo(Player user1, Player user2, int step1, int step2)
{
	Common::TextColor(ColorCode_DarkRed);
	Common::gotoXY(LEFT + 4 * 16 + 18, 18);
	cout << "<< INFORMATION >>";
	Common::gotoXY(LEFT + 4 * 16, 20);
	cout << "Player 1<X>: " << user1.GetName() << "  Step: " << step1 << "  W/L/D: " << user1.GetWin() << "/" << user1.GetLose() << "/" << user1.GetDraw();
	Common::gotoXY(LEFT + 4 * 16, 24);
	cout << "Player 2<O>: " << user2.GetName() << "  Step: " << step2 << "  W/L/D: " << user2.GetWin() << "/" << user2.GetLose() << "/" << user2.GetDraw();

}

void View::viewinfohis(Player user1, Player user2)
{
	Common::TextColor(ColorCode_DarkRed);
	Common::gotoXY(LEFT + 4 * 16 + 28, 18);
	cout << "<< INFORMATION >>";
	Common::gotoXY(LEFT + 4 * 16 + 10, 20);
	cout << "Player 1: " << user1.GetName()  << "\t W/L/D: " << user1.GetWin() << "/" << user1.GetLose() << "/" << user1.GetDraw();
	Common::gotoXY(LEFT + 4 * 16 + 10, 24);
	cout << "Player 2: " << user2.GetName()  << "\t W/L/D: " << user2.GetWin() << "/" << user2.GetLose() << "/" << user2.GetDraw();
	Common::gotoXY(70, 12);
	cout << "Return Menu!";

}

void View::viewresult(Player user)
{
	Common::TextColor(ColorCode_DarkRed);
	Common::Nocursortype();
	Common::gotoXY(70, 16);
	cout << "\tCHUC MUNG " << user.GetName() << " CHIEN THANG !\t";
}

void View::viewdraw()
{
	Common::TextColor(ColorCode_DarkRed);
	Common::Nocursortype();
	Common::gotoXY(70, 16);
	cout << "\t" <<"HAI BEN HOA NHAU !\t";

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

vCoord View::MtoV(int x, int y)
{
	vCoord va;
	int x1 = (x * WEIGHT) + LEFT;
	int y1 = (y * HEIGHT) + TOP;
	va.c.X = x1 + 1;
	va.c.Y = y1;
	va.p = false;
	return va;
}

int View::viewHistogy()
{
	int a;
	Common::gotoXY(40, 14);
	cout << "nhap ID tran dau can tim: ";
	cin >> a;
	Common::gotoXY(40, 18);
	cout << "back to MENU";
	Common::gotoXY(40, 16);
	cout << "hien thi tran dau.";
	return a;
}

void View::dismatchhistory(Player one, Player two, Game game)
{
	//viewinfohis(one, two);//view info user
	viewtablehis(game.getsize());//viewtable
	vCoord vpoint;
	vCoord mmouse;
	for (int i = 0; i < game.getsize(); i++)
	{
		for (int j = 0; j < game.getsize(); j++)
		{
			vpoint = MtoV(i, j);
			if (game.getPointint(i,j) == -1)
			{
				pushX(vpoint);
			}
			else if(game.getPointint(i, j) == 1)
				pushO(vpoint);
		}
	}
	Common::TextColor(ColorCode_DarkRed);
	Common::gotoXY(LEFT + 4 * 16 + 28, 18);
	cout << "<< INFORMATION >>";
	Common::gotoXY(LEFT + 4 * 16 + 10, 20);
	cout << "Player 1: " << one.GetName() << "\t W/L/D: " << one.GetWin() << "/" << one.GetLose() << "/" << one.GetDraw();
	Common::gotoXY(LEFT + 4 * 16 + 10, 24);
	cout << "Player 2: " << two.GetName() << "\t W/L/D: " << two.GetWin() << "/" << two.GetLose() << "/" << two.GetDraw();
	Common::gotoXY(70, 12);
	cout << "Return Menu!";
}

void View::viewfile(ifstream& fileout)//show file tin thong tin nguoi choi
{
	system("cls");
	Common::gotoXY(10, 2);
	cout << "<< THONG KE THANH TICH NGUOI CHOI >>" << "=> Back to MENU." << endl;

	string line;//luu gia tri tung dong
	int y = 4;
	while (fileout)
	{
		y++;
		Common::gotoXY(10, y);
		getline(fileout, line);
		cout << line << endl;
	}
}


