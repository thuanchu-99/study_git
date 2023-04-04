#pragma once
#include"common.h"
#include"player.h"
#include"point.h"

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

