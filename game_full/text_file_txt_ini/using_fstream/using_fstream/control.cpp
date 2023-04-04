﻿#include".\control.h"

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
	if (MOUSE.c.Y == 15 && (MOUSE.c.X >= 55 && MOUSE.c.X <= 61))
		return 2;
	if (MOUSE.c.Y == 17 && (MOUSE.c.X >= 55 && MOUSE.c.X <= 62))
		return 3;
	if (MOUSE.c.Y == 19 && (MOUSE.c.X >= 55 && MOUSE.c.X <= 59))
		return 4;
}

int Control::cmd_table(vCoord MOUSE, int SIZE)
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

int Control::checkwin(int pX, int pY, int SIZE)
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

string Control::inttostring(int a)
{
	string c;
	if (a < 10)
	{
		c = "0" + to_string(a);
	}
	else
	{
		c = to_string(a);
	}
	return c;
}

int Control::stringtointwld(string s)
{
	int l1 = s.length();
	int num1 = 0;
	for (int i = l1 - 1; i >= 0; i--)
	{
		num1 = num1 + (int)(s[i]-'0') * pow(10, l1 - i - 1);
	}
	return num1;
}

void Control::updatefile(Player one)
{
	ifstream fileout1;
	fileout1.open("data.txt",ios::out);//read data ra
	//trien khai code
	//B1: tim kien xem player da ton tai hay chua
	int check1 = -1;//bien tim kiem
	int linefind1 = 0;//bien xac dinh dong

	string lineone;//luu gia tri dong trong file
	while (getline(fileout1, lineone))
	{
		check1 = lineone.find(one.GetName());//fim kiem ten 
		if (check1 != -1)
			break;
		linefind1++;
	}
	fileout1.close();
	string b = "(WIN/LOSE/DRAW)";
	string a = " ";
	string addone1 = one.GetName()+ b + a + inttostring(one.GetWin()) + a + inttostring(one.GetLose()) + a + inttostring(one.GetDraw())+"\n";
	/*cout << addone1 << endl;
	system("pause");*/
	ofstream filein1("data.txt", ios::app);
	if (check1 == -1)//chua tung choi
	{
		//add truc tiep player vao file
		filein1 << addone1 << endl;
	}
	filein1.close();

	if (check1 != -1)//co trung ten: trung tai dong linefind1
	{
		//B1: lay du lieu : win, Lose, Draw past (trong string lineone)
		//B2: cong voi data moi
		//B3: them du lieu vao dong linfind1 trong file
		string win1 = lineone.substr(lineone.length() - 8, 2);
		string lose1 = lineone.substr(lineone.length() - 5, 2);
		string draw1 = lineone.substr(lineone.length() - 2, 2);

		int win2, lose2, draw2;
		win2 = stringtointwld(win1) + one.GetWin();
		lose2 = stringtointwld(lose1) + one.GetLose();
		draw2 = stringtointwld(draw1) + one.GetDraw();

		string addone2 = one.GetName()+ b + a + inttostring(win2) + a + inttostring(lose2) + a + inttostring(draw2)+"\n";

		vector<string> lines;//luu toan bo data past trong file
		string linecheck;
		ifstream fileout2("data.txt", ios::out);
		while (getline(fileout2, linecheck))
		{
			lines.push_back(linecheck);
		}
		fileout2.close();


		ofstream filein2("data.txt");
		for (int i = 0; i < lines.size(); i++)
		{
			if (i != linefind1)
			{
				filein2 << lines[i] << "\n";
			}
			else if(i == linefind1)
			{
				filein2 << addone2;
			}
		}
		filein2.close();
	}
}

void Control::runProgram()
{
	vCoord MOUSE;//luu toa do click mouse
	int check_win;
	int x_win, y_win;
	int number_game = 0;//so tran
	int number_sec;//so sec trong tran
	int IDgame;//ID save player and game
	int save_game;
	int check_his = 0;
	int check_game = 0;
	int check_menu = 0;
	mCoord mMOUSE;
	vCoord vMOUSE;
	int size;
	int tableMOUSE;
	int check_history = 0;

	//run program
	while (true)
	{
		
		check_game = 0;
		mView.viewmenu();//show menu
		MOUSE = mView.mouse();//click mouse
		int menuMOUSE = cmd_menu(MOUSE);//setup choose

		//nhan exit
		if (menuMOUSE == 4)
			break;//thoat chuong trinh

		switch (menuMOUSE)
		{
		case 1://new game in menu
		{
			number_sec = 0;
			number_game++;
			pair<string, string> user;
			user = mView.viewSetPlayer();
			size = mView.inputSIZE();
			mModel.modelcrematch(size);

			//hai ng choi trong 1 game
			Player one(user.first);
			Player two(user.second);

			int step = 0;
			int step1 = 0;//turn
			int step2 = 0;
			mView.viewtable(size);//tao bang
			while (true)
			{

				mView.viewinfo(one, two, step1, step2);//view info user
				//setup mouse table
				MOUSE = mView.mouse();//click mouse
				tableMOUSE = cmd_table(MOUSE, size);//setup mouse

				//setup in table console
				switch (tableMOUSE)
				{
				case 1://thuoc bang
				{
					//check point : true: addpoint, false: break
					mMOUSE = VtoM(MOUSE);//chuyen mouse sang table coor
					if (mModel.checkpointgame(mMOUSE) == false)
						break;

					step++;//tang luot danh
					vMOUSE = MtoV(mMOUSE);

					if (step % 2 != 0)//dien X
					{
						mModel.addXtogame(mMOUSE);
						mView.pushX(vMOUSE);
						step1++;
					}

					if (step % 2 == 0)
					{
						mModel.addOtogame(mMOUSE);
						mView.pushO(vMOUSE);
						step2++;
					}

					//check win
					x_win = mMOUSE.P.X;
					y_win = mMOUSE.P.Y;
					check_win = checkwin(x_win, y_win, size);

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
						/*Common::gotoXY(1, 1);
						cout << IDgame;*/
						break;
					}
					else if (check_win == 1)
					{
						mView.viewresult(two);
						two.IncreWin();
						one.IncreLose();
						IDgame = number_game * 10 + number_sec;
						one.setID(IDgame);
						two.setID(IDgame);
						mModel.addPlayer(one);
						mModel.addPlayer(two);
						mModel.addgame(IDgame);
						break;
					}
					else if (check_win == 0)
					{
						mView.viewdraw();
						one.IncreDraw();
						two.IncreDraw();
						IDgame = number_game * 10 + number_sec;
						one.setID(IDgame);
						two.setID(IDgame);
						mModel.addPlayer(one);
						mModel.addPlayer(two);
						mModel.addgame(IDgame);
						break;
					}
					break;//break case 1
				}
				case 2://newgame
				{
					//cap nhat thong tin w l d
					IDgame = number_game * 10 + number_sec;
					one.setID(IDgame);//them ID cho ng choi
					two.setID(IDgame);

					mModel.addPlayer(one);
					mModel.addPlayer(two);
					mModel.addgame(IDgame);
					number_sec++;

					mModel.newGame();
					system("cls");
					mView.viewtable(size);
					step = 0;
					step1 = 0;//turn
					step2 = 0;
					break;
				}
				case 3://save game
				{
					IDgame = number_game * 10 + number_sec;
					one.setID(IDgame);
					two.setID(IDgame);
					mModel.addPlayer(one);
					mModel.addPlayer(two);
					mModel.addgame(IDgame);

					check_game = 1;
					int step = 0;
					int step1 = 0;//turn
					int step2 = 0;

					//add file
					updatefile(one);
					updatefile(two);
					mModel.newGame();
					break;
				}
				case 4://return menu
				{
					IDgame = number_game * 10 + number_sec;
					one.setID(IDgame);
					two.setID(IDgame);

					mModel.addPlayer(one);
					mModel.addPlayer(two);
					mModel.addgame(IDgame);

					// add file
					updatefile(one);
					updatefile(two);
					mModel.newGame();
					check_menu = 1;
					break;
				}
				}
				if (check_game == 1||check_menu == 1)
				{
					check_menu = 0;
					check_game = 0;
					break;
				}
					
			}
		break;//break menu one//finish
		}
		case 2:
		{
			//thanh tich
			while (true)
			{
				ifstream filein("data.txt");
				mView.viewfile(filein);
				vCoord m = mView.mouse();
				if (m.c.Y == 2 && (m.c.X >= 48 && m.c.X <= 58))
				{
					break;
				}
				filein.close();
			}
			break;
		}
		case 3://history//finish
		{
			while (true)
			{
				int IDsearch;
				system("cls");
				IDsearch = mView.viewHistogy();
				vCoord his_MOUSE = mView.mouse();

				if (his_MOUSE.c.Y == 18 && (his_MOUSE.c.X >= 40 && his_MOUSE.c.Y <= 52))
				{
					break;
				}
				else if(his_MOUSE.c.Y == 16 && (his_MOUSE.c.X >= 40 && his_MOUSE.c.Y <= 58))
				{
					system("cls");
					pair<Player, Player> u;
					u = mModel.getPlayer(IDsearch);
					Game u1;
					u1 = mModel.search(IDsearch);
					mView.dismatchhistory(u.first, u.second, u1);
					vCoord his_MOUSE1 = mView.mouse();

					if (his_MOUSE1.c.Y == 12 && (his_MOUSE1.c.X >= 70 && his_MOUSE1.c.Y <= 82))
					{
						break;
					}
				}
			}
		break;
		}
		
		}
	}
}
