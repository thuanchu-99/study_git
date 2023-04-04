#pragma once
#include".\lib.h"
#include".\common.h"
#include".\player.h"
#include".\point.h"
#include".\game.h"
class View
{
private:
	vector<vCoord> vNode;//luu cac toa do da duoc dien
public:
	View();
	~View();
	vCoord MtoV(int, int);

	//view thuan
	void viewmenu();
	pair<string, string> viewSetPlayer();
	int inputSIZE();
	void viewtable(int);
	void viewinfo(Player, Player, int, int);
	void viewresult(Player);//hien thi sau khi ket thuc
	void viewdraw();
	vCoord mouse();
	bool checkmouseXO(vCoord);
	void pushX(vCoord);
	void pushO(vCoord);
	void viewinfohis(Player, Player);
	//history
	int viewHistogy();
	void dismatchhistory(Player, Player, Game);
	void viewtablehis(int);

	void viewfile(ifstream&);//doc toan bo noi dung file
	
};

