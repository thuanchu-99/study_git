#include".\control.h"

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
	va.c.X = x+1;
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
			res = mModel.getpointgameint(x, i) + mModel.getpointgameint(x, i+1) + mModel.getpointgameint(x, i+2)
				+ mModel.getpointgameint(x, i+3);

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
				res = mModel.getpointgameint(i, j) + mModel.getpointgameint(i+1, j + 1) + mModel.getpointgameint(i+2, j + 2)
					+ mModel.getpointgameint(i+3, j + 3);
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
