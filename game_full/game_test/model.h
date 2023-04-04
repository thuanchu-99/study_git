#pragma once
#include".\lib.h"
#include"game.h"
#include"player.h"

//chuong trinh chi thuc hien luu 1 lan choi
//luu du lieu cac sec trong moot tran dau
//ten nguoi choi, 
//vector XO moi sec

class Model:public Common
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